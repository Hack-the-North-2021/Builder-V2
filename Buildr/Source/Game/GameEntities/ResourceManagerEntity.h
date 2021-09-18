#pragma once
#include "GameEngine/EntitySystem/Entity.h"

#include "GameEngine/EntitySystem/Components/SpriteRenderComponent.h"
#include "ResourceEntity.h"

#include <vector>

using std::vector;

namespace Game
{

	class ResourceManagerEntity : public GameEngine::Entity
	{
	public:
		ResourceManagerEntity();
		~ResourceManagerEntity();

		virtual void OnAddToWorld() override;
		virtual void OnRemoveFromWorld() override;

	protected:
		vector<ResourceEntity*> resourceEntities;
		const vector<GameEngine::eTexture::type> types = { GameEngine::eTexture::FOOD, GameEngine::eTexture::ROCK, GameEngine::eTexture::TREE, GameEngine::eTexture::BRONZE };
		const int numResources = 100;
	};
}

