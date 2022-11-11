#ifndef RENDERER_H
#define RENDERER_H

#include "OrthographicCamera.h"
#include "RenderCommand.h"
#include "Shader.h"

namespace Pandemonium {

	class PANDEMONIUM_API Renderer {
	public:
		static void					   BeginScene(OrthographicCamera& camera);
		static void					   EndScene();

		static void					   Submit(const std::shared_ptr<Shader>& shader, const std::shared_ptr<VertexArray>& VertexArray);

		inline static RendererAPI::API GetAPI() { return RendererAPI::GetAPI(); }
	private:
		struct SceneData {
			glm::mat4 ViewProjectionMatrix;
		};

		static SceneData* m_SceneData;
	};
} // namespace Pandemonium

#endif /* RENDERER_H*/