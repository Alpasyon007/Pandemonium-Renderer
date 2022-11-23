#ifndef ORTOGRAPHIC_CAMERA_CONTROLLER_H
#define ORTOGRAPHIC_CAMERA_CONTROLLER_H

#include "Core.h"

#include "OrthographicCamera.h"
#include "Timestep.h"

#include "ApplicationEvent.h"
#include "Event.h"
#include "MouseEvent.h"

namespace Pandemonium {

	class PANDEMONIUM_API OrthographicCameraController {
	public:
		OrthographicCameraController(float aspectRatio, bool rotation = false);

		void					  OnUpdate(Timestep ts);
		void					  OnEvent(Event& e);

		OrthographicCamera&		  GetCamera() { return m_Camera; }

		const OrthographicCamera& GetCamera() const { return m_Camera; }

		float					  GetZoomLevel() const { return m_ZoomLevel; }

		void					  SetZoomLevel(float level) { m_ZoomLevel = level; }
	private:
		bool			   OnMouseScrolled(MouseScrolledEvent& e);
		bool			   OnWindowResized(WindowResizeEvent& e);

		float			   m_AspectRation;
		float			   m_ZoomLevel = 1.0f;

		OrthographicCamera m_Camera;

		bool			   m_Rotation;
		glm::vec3		   m_CameraPosition			= {0.0f, 0.0f, 0.0f};
		float			   m_CameraRotation			= 0.0f;
		float			   m_CameraTranslationSpeed = 1.0f;
		float			   m_CameraRotationSpeed	= 1.0f;
	};

} // namespace Pandemonium

#endif /* ORTOGRAPHIC_CAMERA_CONTROLLER_H */