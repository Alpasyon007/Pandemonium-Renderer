#include "VertexArray.h"

#include "Renderer.h"

#include "OpenGLVertexArray.h"

namespace Pandemonium {

	Ref<VertexArray> VertexArray::Create() {
		switch(Renderer::GetAPI()) {
			case RendererAPI::API::None: {
				LOG_ERROR("RendererAPI::None is currently not supportetd!");
				DEBUG_BREAK();
				return nullptr;
			}
			case RendererAPI::API::OpenGL: {
				return std::make_shared<OpenGLVertexArray>();
			}
		}

		LOG_ERROR("Unknown Renderer API!");
		return nullptr;
	}
} // namespace Pandemonium