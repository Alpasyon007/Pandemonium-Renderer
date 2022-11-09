#ifndef SHADER_H
#define SHADER_H

#include "ppch.h"

namespace Pandemonium {

	class Shader {
	public:
		Shader(const std::string& vertexSrc, const std::string& fragmentSrc);
		~Shader();

		void Bind() const;
		void Unbind() const;
	private:
		uint32_t m_RendererID;
	};

} // namespace Pandemonium
#endif /* SHADER_H */