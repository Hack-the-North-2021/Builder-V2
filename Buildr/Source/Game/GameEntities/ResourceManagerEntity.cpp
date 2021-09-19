#include "ResourceManagerEntity.h"
#include "GameEngine/Util/randgen.h"
#include "GameEngine/GameEngineMain.h"
#include <iostream>
using namespace Game;

ResourceManagerEntity::ResourceManagerEntity()
{
	// Generate 1000 resources.
	for (int i = 0; i < numResources; ++i) {
		GenerateResource();

		
		//resourceEntities.push_back(currentResource);



	}

}



ResourceManagerEntity::~ResourceManagerEntity()
{

}

void ResourceManagerEntity::GenerateResource() {
	int x = RandGen::randint(0, 12000);
	int y = RandGen::randint(0, 8000);
	int type = RandGen::randint(0, 3);
	ResourceEntity* currentResource = new ResourceEntity(x, y, types[type], 100);

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
void ResourceManagerEntity::Update(){
	Entity::Update();
	std::vector<GameEngine::Entity*> resources = GameEngine::GameEngineMain::GetInstance()->GetEntitiesByTag("Resource");
	if (resources.size() < 1000) {
		GenerateResource();
	}


}



