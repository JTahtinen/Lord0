#pragma once
#include <GL/glew.h>
#include <string>
#include "../math/matrix4f.h"
#include <unordered_map>

namespace lord { namespace graphics {

	class Shader
	{
		GLuint		_id;
		std::unordered_map<std::string, GLint> _uniformLocations;
	public:
		~Shader();
		void bind() const;
		void unbind() const;
		void setUniform1f(const std::string& u_name, float v0);
		void setUniform2f(const std::string& u_name, float v0, float v1);
		void setUniform3f(const std::string& u_name, float v0, float v1, float v2);
		void setUniform4f(const std::string& u_name, float v0, float v1, float v2, float v3);
		void setUniformMat4(const std::string& u_name, const math::Matrix4f& mat4f);
		static Shader* loadShader(const std::string& path);
	private:
		GLint getUniformLocation(const std::string& u_name);
		Shader(const std::string& vertex, const std::string& fragment);

	};

}}