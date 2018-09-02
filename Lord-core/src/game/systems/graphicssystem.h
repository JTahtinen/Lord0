#pragma once
#include <unordered_map>
#include "system.h"

namespace lord { namespace game { namespace system {
	
	namespace graphicsSystem 
	{
		void init(GraphicsMap& graphicsComponents, LocationsMap& locationComponents);
		void update();
		void quit();
		void addEntity(GUID entity);
	}
}}}