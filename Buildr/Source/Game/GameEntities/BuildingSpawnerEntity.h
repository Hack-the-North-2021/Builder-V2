#pragma once
#include "GameEngine/EntitySystem/Entity.h"

#include "GameEngine/EntitySystem/Components/SpriteRenderComponent.h"
#include "ResourceEntity.h"

#include <vector>

using std::vector;

namespace Game
{

	class BuildingSpawnerEntity : public GameEngine::Entity
	{
	public:
		static BuildingSpawnerEntity* GetInstance() { if (!sm_instance) sm_instance = new BuildingSpawnerEntity(); return sm_instance; }
		
		~BuildingSpawnerEntity();
		virtual void Update() override;

		virtual void OnAddToWorld() override;
		virtual void OnRemoveFromWorld() override;
		void Build(int x);

	protected:
		const vector<GameEngine::eTexture::type> types = { GameEngine::eTexture::WALL };
	private:
		BuildingSpawnerEntity();
		static BuildingSpawnerEntity* sm_instance;

	};
}

