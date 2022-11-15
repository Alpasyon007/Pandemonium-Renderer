#ifndef SHADER_H
#define SHADER_H

#include "ppch.h"

#include "Core.h"

namespace Pandemonium {

	class PANDEMONIUM_API Shader {
	public:
		virtual ~Shader()			  = default;

		virtual void   Bind() const	  = 0;
		virtual void   Unbind() const = 0;

		static Shader* Create(const std::string& vertexSrc, const std::string& fragmentSrc);
	};

} // namespace Pandemonium

#endif /* SHADER_H */