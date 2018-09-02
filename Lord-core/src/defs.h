#pragma once
#include <GL\glew.h>
#include <iostream>

unsigned inline int getSizeOfType(unsigned int type)
{
	switch (type)
	{
	case GL_FLOAT:			return sizeof(float);
	case GL_UNSIGNED_INT:	return sizeof(unsigned int);
	case GL_INT:			return sizeof(int);
	case GL_UNSIGNED_BYTE:	return sizeof(unsigned char);
	}
	return 0;
}

inline void GLClearError()
{
	while (glGetError() != GL_NO_ERROR);
}

inline bool GLLogCall()
{
	while (GLenum error = glGetError())
	{
		std::cout << "[OpenGL ERROR] (" << error << ")" << std::endl;
		return false;
	}
	return true;
}

#ifdef  _DEBUG
#define ASSERT(x) if (x) {} else { __debugbreak(); }
#define GLCALL(x) GLClearError();\
x;\
ASSERT(GLLogCall())

#else

#define ASSERT(x)
#define GLCALL(x) x

#endif
