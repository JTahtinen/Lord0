#pragma once
#include "../renderers/renderer3d.h"
#include "../../math/matrix4f.h"
#include "../mesh.h"
#include "../shader.h"
#include <deque>

namespace lord { namespace graphics {

	struct Renderable3D
	{
		const Mesh*		mesh;
		math::Matrix4f	transformation;
	};

	class Layer3D
	{
		std::deque<Renderable3D>		_renderQueue;
		math::Matrix4f					_projection;
		Renderer3D						_renderer;
		Shader*							_shader;
	public:
		Layer3D(Shader* shader);
		void submit(const Mesh* renderable, const math::Matrix4f& transform);
		void render();
	};

}}