#ifndef RENDER_COMMAND_H
#define RENDER_COMMAND_H

#include "RendererAPI.h"

namespace Pandemonium {
	class PANDEMONIUM_API RenderCommand {
	public:
		inline static void SetClearColor(const glm::vec4& color) { s_RendererAPI->SetClearColor(color); }

		inline static void Clear() { s_RendererAPI->Clear(); }

		inline static void DrawIndexed(const std::shared_ptr<VertexArray>& VertexArray) { s_RendererAPI->DrawIndexed(VertexArray); }
	private:
		static RendererAPI* s_RendererAPI;
	};
} // namespace Pandemonium

#endif /* RENDER_COMMAND_H */