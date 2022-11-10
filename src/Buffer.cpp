#include "ppch.h"
#include "Buffer.h"

#include "OpenGLBuffer.h"
#include "Renderer.h"

namespace Pandemonium {

	VertexBuffer* VertexBuffer::Create(float* vertices, uint32_t size) {
		switch(Renderer::GetAPI()) {
			case RendererAPI::None: {
				LOG_ERROR("RendererAPI::None is currently not supportetd!");
				DEBUG_BREAK();
				return nullptr;
			}
			case RendererAPI::OpenGL: {
				return new OpenGLVertexBuffer(vertices, size);
			}
		}

		LOG_ERROR("Unknown Renderer API!");
		return nullptr;
	}

	IndexBuffer* IndexBuffer::Create(uint32_t* indices, uint32_t size) {
		switch(Renderer::GetAPI()) {
			case RendererAPI::None: {
				LOG_ERROR("RendererAPI::None is currently not supportetd!");
				DEBUG_BREAK();
				return nullptr;
			}
			case RendererAPI::OpenGL: {
				return new OpenGLIndexBuffer(indices, size);
			}
		}

		LOG_ERROR("Unknown Renderer API!");
		return nullptr;
	}

} // namespace Pandemonium