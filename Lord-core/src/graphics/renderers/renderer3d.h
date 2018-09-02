#pragma once
#include <deque>
#include <vector>
#include "../mesh.h"
#include "../../math/matrix4f.h"
#include "../shader.h"

namespace lord { namespace graphics {

	class Renderer3D
	{
		std::vector<math::Matrix4f>			_transformationStack;
	public:
		Renderer3D();
		void pushMatrix(const math::Matrix4f& matrix);
		void popMatrix();
		void render(const Mesh* mesh, Shader* shader);
	};
	
}}