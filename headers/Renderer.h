#ifndef RENDERER_H
#define RENDERER_H

#include "RenderCommand.h"

namespace Pandemonium {
	class Renderer {
	public:
		static void					   BeginScene();
		static void					   EndScene();

		static void					   Submit(const std::shared_ptr<VertexArray>& VertexArray);

		inline static RendererAPI::API GetAPI() { return RendererAPI::GetAPI(); }
	};
} // namespace Pandemonium

#endif /* RENDERER_H*/