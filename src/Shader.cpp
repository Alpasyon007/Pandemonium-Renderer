#include "Shader.h"

#include "OpenGLShader.h"
#include "Renderer.h"

namespace Pandemonium {

	Shader* Shader::Create(const std::string& vertexSrc, const std::string& fragmentSrc) {
		switch(Renderer::GetAPI()) {
			case RendererAPI::API::None: {
				LOG_ERROR("RendererAPI::None is currently not supportetd!");
				DEBUG_BREAK();
				return nullptr;
			}
			case RendererAPI::API::OpenGL: {
				return new OpenGLShader(vertexSrc, fragmentSrc);
			}
		}

		LOG_ERROR("Unknown Renderer API!");
		return nullptr;
	}

} // namespace Pandemonium