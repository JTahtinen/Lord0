#include "graphicssystem.h"
#include "system.h"
#include "../../defs.h"
#include <unordered_map>
namespace lord { namespace game { namespace system {

	namespace graphicsSystem
	{
		using namespace graphics;
		using namespace math;

		static std::vector<GUID>									_entities;

		struct GraphicsData {
			GraphicsMap&											graphicsComponents;
			LocationsMap&											locationComponents;
		};

		static GraphicsData*										_data;

		void init(GraphicsMap& graphicsComponents, LocationsMap& locationComponents)
		{
			_data = new GraphicsData
			{
				graphicsComponents,
				locationComponents
			};
		}

		void update()
		{
			for (GUID entity : _entities)
			{
				GraphicsComponent* graphics = _data->graphicsComponents[entity];
				ASSERT(graphics);
				LocationComponent* location = _data->locationComponents[entity];
				ASSERT(location);

				graphics->_layer->submit(graphics->_mesh, Matrix4f::translate(location->pos));
			}
		}

		void quit()
		{
			delete _data;
			_data = nullptr;
		}

		void addEntity(GUID entity)
		{
			for (GUID e : _entities)
			{
				if (e == entity)
				{
					return;
				}
			}
			_entities.push_back(entity);
		}
	}

}}}