#ifndef VERTEX_ARRAY_H
#define VERTEX_ARRAY_H

#include "ppch.h"

#include "Buffer.h"

namespace Pandemonium {
	class PANDEMONIUM_API VertexArray {
	public:
		virtual ~VertexArray() {}

		virtual void								  Bind() const											 = 0;
		virtual void								  Unbind() const										 = 0;

		virtual void								  AddVertexBuffer(const Ref<VertexBuffer>& vertexBuffer) = 0;
		virtual void								  SetIndexBuffer(const Ref<IndexBuffer>& indexBuffer)	 = 0;

		virtual const std::vector<Ref<VertexBuffer>>& GetVertexBuffers() const								 = 0;
		virtual const Ref<IndexBuffer>&				  GetIndexBuffer() const								 = 0;

		static VertexArray*							  Create();
	};
} // namespace Pandemonium

#endif /* VERTEX_ARRAY_H */