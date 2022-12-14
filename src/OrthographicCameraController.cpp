#include "ppch.h"

#include "OrthographicCameraController.h"

#include "Input.h"
#include "KeyCodes.h"

namespace Pandemonium {

	OrthographicCameraController::OrthographicCameraController(float aspectRatio, bool rotation /* = false */)
		: m_AspectRation(aspectRatio)
		, m_Camera(-m_AspectRation * m_ZoomLevel, m_AspectRation * m_ZoomLevel, -m_ZoomLevel, m_ZoomLevel)
		, m_Rotation(rotation) {}

	void OrthographicCameraController::OnUpdate(Timestep ts) {
		PANDEMONIUM_PROFILE_FUNCTION();

		if(Input::IsKeyPressed(PANDEMONIUM_KEY_A)) {
			m_CameraPosition.x -= m_CameraTranslationSpeed * ts;
		} else if(Input::IsKeyPressed(PANDEMONIUM_KEY_D)) {
			m_CameraPosition.x += m_CameraTranslationSpeed * ts;
		}
		if(Input::IsKeyPressed(PANDEMONIUM_KEY_W)) {
			m_CameraPosition.y += m_CameraTranslationSpeed * ts;
		} else if(Input::IsKeyPressed(PANDEMONIUM_KEY_S)) {
			m_CameraPosition.y -= m_CameraTranslationSpeed * ts;
		}

		if(m_Rotation) {
			if(Input::IsKeyPressed(PANDEMONIUM_KEY_Q)) {
				m_CameraRotation += m_CameraRotationSpeed * ts;
			} else if(Input::IsKeyPressed(PANDEMONIUM_KEY_E)) {
				m_CameraRotation -= m_CameraRotationSpeed * ts;
			}

			m_Camera.SetRotation(m_CameraRotation);
		}

		m_Camera.SetPosition(m_CameraPosition);

		m_CameraTranslationSpeed = m_ZoomLevel;
	}

	void OrthographicCameraController::OnEvent(Event& e) {
		PANDEMONIUM_PROFILE_FUNCTION();

		EventDispatcher dispatcher(e);
		dispatcher.Dispatch<MouseScrolledEvent>(std::bind(&OrthographicCameraController::OnMouseScrolled, this, std::placeholders::_1));
		dispatcher.Dispatch<WindowResizeEvent>(std::bind(&OrthographicCameraController::OnWindowResized, this, std::placeholders::_1));
	}

	bool OrthographicCameraController::OnMouseScrolled(MouseScrolledEvent& e) {
		PANDEMONIUM_PROFILE_FUNCTION();

		m_ZoomLevel -= e.GetYOffset() * 0.25f;
		m_ZoomLevel = std::max(m_ZoomLevel, 0.25f);
		m_Camera.SetProjection(-m_AspectRation * m_ZoomLevel, m_AspectRation * m_ZoomLevel, -m_ZoomLevel, m_ZoomLevel);
		return false;
	}

	bool OrthographicCameraController::OnWindowResized(WindowResizeEvent& e) {
		PANDEMONIUM_PROFILE_FUNCTION();

		m_AspectRation = static_cast<float>(e.GetWidth()) / static_cast<float>(e.GetHeight());
		m_Camera.SetProjection(-m_AspectRation * m_ZoomLevel, m_AspectRation * m_ZoomLevel, -m_ZoomLevel, m_ZoomLevel);
		return false;
	}

} // namespace Pandemonium
