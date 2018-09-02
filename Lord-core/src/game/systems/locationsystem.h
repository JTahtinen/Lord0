#pragma once
#include <unordered_map>
#include "system.h"

namespace lord { namespace game { namespace system {

	namespace locationSystem
	{
		void init(LocationsMap& locations);
		void update();
		void quit();
		void addEntity(GUID entity);
	}

}}}