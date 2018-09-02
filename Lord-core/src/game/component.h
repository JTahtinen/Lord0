#pragma once

#include "../graphics/mesh.h"
#include "../graphics/layers/layer3d.h"
#include "../math/matrix4f.h"
#include "../input/input.h"

namespace lord {
	namespace game {

		struct GraphicsComponent
		{
			const graphics::Mesh*	_mesh;
			graphics::Layer3D*		_layer;
		};

		struct InputComponent
		{
			input::Input& _in = input::Input::instance();
		};

		struct LocationComponent
		{
			math::Vec3	pos = math::Vec3(0, 0, 0);
			math::Vec3	vel = math::Vec3(0, 0, 0);
		};

		struct PhysicsComponent
		{
		};

	}
}