#pragma once
#include "system.h"

namespace lord { namespace game { namespace system {

	namespace inputSystem
	{
		void init(InputsMap& inputs, LocationsMap& locations);
		void update();
		void quit();
		void addEntity(GUID entity);
	}

}}}