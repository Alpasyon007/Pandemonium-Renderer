#include "VertexArray.h"

#include "Renderer.h"

#include "OpenGLVertexArray.h"

namespace Pandemonium {

	VertexArray* VertexArray::Create() {
		switch(Renderer::GetAPI()) {
			case RendererAPI::API::None: {
				LOG_ERROR("RendererAPI::None is currently not supportetd!");
				DEBUG_BREAK();
				return nullptr;
			}
			case RendererAPI::API::OpenGL: {
				return new OpenGLVertexArray();
			}
		}

		LOG_ERROR("Unknown Renderer API!");
		return nullptr;
	}
} // namespace Pandemonium