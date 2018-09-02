#pragma once
#include <vector>
#include "../graphics/mesh.h"
#include "../graphics/layers/layer3d.h"
#include "../math/vec3.h"
#include "systems/system.h"

namespace lord { namespace game {


	class Game
	{
		std::vector<GUID>	_entities;
	public:
		Game();
		~Game();
		void update();
		void addEntity(const math::Vec3& pos, const graphics::Mesh* mesh, graphics::Layer3D* layer);
	};
}}