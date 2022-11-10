#include "RenderCommand.h"
#include "ppch.h"

#include "OpenGLRendererAPI.h"

namespace Pandemonium {

	RendererAPI* RenderCommand::s_RendererAPI = new OpenGLRendererAPI;

}