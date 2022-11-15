#include "ppch.h"
#include "Texture.h"

#include "OpenGLTexture.h"
#include "Renderer.h"

namespace Pandemonium {

	Ref<Texture2D> Texture2D::Create(const std::string& path) {
		switch(Renderer::GetAPI()) {
			case RendererAPI::API::None: {
				LOG_ERROR("RendererAPI::None is currently not supportetd!");
				DEBUG_BREAK();
				return nullptr;
			}
			case RendererAPI::API::OpenGL: {
				return std::make_shared<OpenGLTexture2D>(path);
			}
		}

		LOG_ERROR("Unknown Renderer API!");
		return nullptr;
	}
} // namespace Pandemonium