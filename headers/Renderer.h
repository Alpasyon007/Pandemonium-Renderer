#ifndef RENDERER_H
#define RENDERER_H

#include "OrthographicCamera.h"
#include "RenderCommand.h"
#include "Shader.h"

namespace Pandemonium {

	class PANDEMONIUM_API Renderer {
	public:
		static void					   Init();
		static void					   OnWindowResize(uint32_t width, uint32_t height);

		static void					   BeginScene(OrthographicCamera& camera);
		static void					   EndScene();

		static void					   Submit(const Ref<Shader>& shader, const Ref<VertexArray>& VertexArray, const glm::mat4& transform = glm::mat4(1.0f));

		inline static RendererAPI::API GetAPI() { return RendererAPI::GetAPI(); }
	private:
		struct SceneData {
			glm::mat4 ViewProjectionMatrix;
		};

		static SceneData* m_SceneData;
	};
} // namespace Pandemonium

#endif /* RENDERER_H*/