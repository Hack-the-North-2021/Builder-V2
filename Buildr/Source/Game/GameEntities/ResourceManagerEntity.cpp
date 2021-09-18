#include "ResourceManagerEntity.h"
#include "GameEngine/Util/randgen.h"

using namespace Game;

ResourceManagerEntity::ResourceManagerEntity()
{
	// Generate 1000 resources.
	for (int i = 0; i < numResources; ++i) {
		int x = RandGen::randint(0, 12000);
		int y = RandGen::randint(0, 8000);
		int type = RandGen::randint(0, 3);
		ResourceEntity* currentResource = new ResourceEntity(x, y, types[type]);
		resourceEntities.push_back(currentResource);

	}

}


ResourceManagerEntity::~ResourceManagerEntity()
{

}


void ResourceManagerEntity::OnAddToWorld()
{
	Entity::OnAddToWorld();


	SetEntityTag("ResourceManager");
}


void ResourceManagerEntity::OnRemoveFromWorld()
{
	Entity::OnRemoveFromWorld();
}



