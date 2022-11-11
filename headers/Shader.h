#ifndef SHADER_H
#define SHADER_H

#include "ppch.h"

#include "Core.h"

#include <glm/glm.hpp>

namespace Pandemonium {

	class PANDEMONIUM_API Shader {
	public:
		Shader(const std::string& vertexSrc, const std::string& fragmentSrc);
		~Shader();

		void Bind() const;
		void Unbind() const;

		void UploadUniformMat4(const std::string& name, const glm::mat4& matrix);
	private:
		uint32_t m_RendererID;
	};

} // namespace Pandemonium
#endif /* SHADER_H */