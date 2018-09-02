#include "shader.h"
#include "../defs.h"
#include "../util/file.h"

namespace lord { namespace graphics {

	Shader::Shader(const std::string& vertex, const std::string& fragment)
	{
		GLCALL(_id = glCreateProgram());
		const char* vsC = vertex.c_str();
		const char* fsC = fragment.c_str();

		GLCALL(GLuint vs = glCreateShader(GL_VERTEX_SHADER));
		GLCALL(GLuint fs = glCreateShader(GL_FRAGMENT_SHADER));

		GLCALL(glShaderSource(vs, 1, &vsC, NULL));
		GLCALL(glShaderSource(fs, 1, &fsC, NULL));
		GLCALL(glCompileShader(vs));
		GLCALL(glCompileShader(fs));
		GLCALL(glAttachShader(_id, vs));
		GLCALL(glAttachShader(_id, fs));
		GLCALL(glLinkProgram(_id));
		GLCALL(glValidateProgram(_id));
		GLCALL(glDeleteShader(vs));
		GLCALL(glDeleteShader(fs));
	}

	Shader::~Shader()
	{
		GLCALL(glDeleteProgram(_id));
	}

	void Shader::bind() const
	{
		GLCALL(glUseProgram(_id));
	}

	void Shader::unbind() const
	{
		GLCALL(glUseProgram(0));
	}

	GLint Shader::getUniformLocation(const std::string& u_name)
	{
		if (_uniformLocations.find(u_name) != _uniformLocations.end())
		{
			return _uniformLocations[u_name];
		}

		GLint location = glGetUniformLocation(_id, u_name.c_str());
		if (location == -1)
		{
			std::cout << "[ERROR] Could not find uniform " << u_name << std::endl;
		}
		_uniformLocations[u_name] = location;
		return location;
	}

	void Shader::setUniform1f(const std::string& u_name, float v0)
	{
		glUniform1f(getUniformLocation(u_name), v0);
	}

	void Shader::setUniform2f(const std::string& u_name, float v0, float v1)
	{
		glUniform2f(getUniformLocation(u_name), v0, v1);
	}

	void Shader::setUniform3f(const std::string& u_name, float v0, float v1, float v2)
	{
		glUniform3f(getUniformLocation(u_name), v0, v1, v2);
	}

	void Shader::setUniform4f(const std::string& u_name, float v0, float v1, float v2, float v3)
	{
		glUniform4f(getUniformLocation(u_name), v0, v1, v2, v3);
	}

	void Shader::setUniformMat4(const std::string& u_name, const math::Matrix4f& mat4f)
	{
		glUniformMatrix4fv(getUniformLocation(u_name), 1, GL_TRUE, &mat4f[0]);
	}

	Shader* Shader::loadShader(const std::string& path)
	{
		std::string vertexShader = load_text_file("res/shaders/basic.vs");
		std::string fragmentShader = load_text_file("res/shaders/basic.fs");

		if (vertexShader != "" && fragmentShader != "")
		{
			return new Shader(vertexShader, fragmentShader);
		}
		
		std::cout << "[ERROR] Could not load shader: " << path << std::endl;
		return nullptr;	
	}

}}