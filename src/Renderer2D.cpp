#include "ppch.h"
#include "RenderCommand.h"
#include "Renderer2D.h"

#include "Shader.h"
#include "Texture.h"
#include "VertexArray.h"

#include <glm/gtc/matrix_transform.hpp>

namespace Pandemonium {

	struct Renderer2DStorage {
		Ref<VertexArray> QuadVertexArray;
		Ref<Shader>		 FlatColourShader;
		Ref<Shader>		 TextureShader;
	};

	static Renderer2DStorage* s_Data;

	void					  Renderer2D::Init() {
		 s_Data									 = new Renderer2DStorage();

		 s_Data->QuadVertexArray				 = VertexArray::Create();

		 float			   squareVertices[5 * 4] = {-0.5f, -0.5f, 0.0f, 0.0f, 0.0f, 0.5f,  -0.5f, 0.0f, 1.0f, 0.0f,
																		0.5f,  0.5f,  0.0f, 1.0f, 1.0f, -0.5f, 0.5f,  0.0f, 0.0f, 1.0f};

		 Ref<VertexBuffer> squareVB;
		 squareVB.reset(VertexBuffer::Create(squareVertices, sizeof(squareVertices)));
		 squareVB->SetLayout({{ShaderDataType::Float3, "a_Position"}, {ShaderDataType::Float2, "a_TexCoord"}});
		 s_Data->QuadVertexArray->AddVertexBuffer(squareVB);

		 unsigned int	  squareIndices[6] = {0, 1, 2, 2, 3, 0};
		 Ref<IndexBuffer> squareIB;
		 squareIB.reset(IndexBuffer::Create(squareIndices, sizeof(squareIndices) / sizeof(uint32_t)));
		 s_Data->QuadVertexArray->SetIndexBuffer(squareIB);

		 s_Data->FlatColourShader = Shader::Create("C:\\dev\\Pandemonium\\Game\\assets\\shaders\\FlatColor.glsl");
		 s_Data->TextureShader	  = Shader::Create("C:\\dev\\Pandemonium\\Game\\assets\\shaders\\Texture.glsl");
		 s_Data->TextureShader->Bind();
		 s_Data->TextureShader->SetInt("u_Texture", 0);
	}

	void Renderer2D::Shutdown() { delete s_Data; }

	void Renderer2D::BeginScene(const OrthographicCamera& camera) {
		s_Data->FlatColourShader->Bind();
		s_Data->FlatColourShader->SetMat4("u_ViewProjection", camera.GetViewProjectionMatrix());

		s_Data->TextureShader->Bind();
		s_Data->TextureShader->SetMat4("u_ViewProjection", camera.GetViewProjectionMatrix());
	}

	void Renderer2D::EndScene() {}

	void Renderer2D::DrawQuad(const glm::vec2& position, const glm::vec2& size, const glm::vec4& colour) {
		DrawQuad({position.x, position.y, 0.0f}, size, colour);
	}

	void Renderer2D::DrawQuad(const glm::vec3& position, const glm::vec2& size, const glm::vec4& colour) {
		s_Data->FlatColourShader->Bind();
		s_Data->FlatColourShader->SetFloat4("u_Color", colour);

		glm::mat4 transform = glm::translate(glm::mat4(1.0f), position) * glm::scale(glm::mat4(1.0f), {size.x, size.y, 1.0f}); // TODO - ADD ROTATION
		s_Data->FlatColourShader->SetMat4("u_Transform", transform);

		s_Data->QuadVertexArray->Bind();
		RenderCommand::DrawIndexed(s_Data->QuadVertexArray);
	}

	void Renderer2D::DrawQuad(const glm::vec2& position, const glm::vec2& size, const Ref<Texture2D>& texture) {
		DrawQuad({position.x, position.y, 0.0f}, size, texture);
	}

	void Renderer2D::DrawQuad(const glm::vec3& position, const glm::vec2& size, const Ref<Texture2D>& texture) {
		s_Data->TextureShader->Bind();
		// TODO - ADD COLOUR & TEXTURE

		glm::mat4 transform = glm::translate(glm::mat4(1.0f), position) * glm::scale(glm::mat4(1.0f), {size.x, size.y, 1.0f});
		s_Data->TextureShader->SetMat4("u_Transform", transform);

		texture->Bind();

		s_Data->QuadVertexArray->Bind();
		RenderCommand::DrawIndexed(s_Data->QuadVertexArray);
	}

} // namespace Pandemonium