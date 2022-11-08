#ifndef GRAPHICS_CONTEXT_H
#define GRAPHICS_CONTEXT_H

namespace Pandemonium {

	class GraphicsContext {
	public:
		virtual void Init()		   = 0;
		virtual void SwapBuffers() = 0;
	};

} // namespace Pandemonium

#endif /* GRAPHICS_CONTEXT_H */