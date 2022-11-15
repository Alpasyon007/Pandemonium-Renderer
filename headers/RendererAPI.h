#ifndef RENDERER_API_H
#define RENDERER_API_H

#include <glm/glm.hpp>

#include "VertexArray.h"

namespace Pandemonium {

	class RendererAPI {
	public:
		enum class API {
			None   = 0,
			OpenGL = 1,
		};
	public:
		virtual void	  Init()										   = 0;
		virtual void	  SetClearColor(const glm::vec4& color)			   = 0;
		virtual void	  Clear()										   = 0;

		virtual void	  DrawIndexed(const Ref<VertexArray>& vertexArray) = 0;

		inline static API GetAPI() { return s_API; }
	private:
		inline static API s_API = RendererAPI::API::OpenGL;
	};

} // namespace Pandemonium

#endif /* RENDERER_API_H */