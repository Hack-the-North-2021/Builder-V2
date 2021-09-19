#pragma once
#include "GameEngine/EntitySystem/Entity.h"
#include <GameEngine/EntitySystem/Components/SpriteRenderComponent.h>
#include <Game/GameComponents/Resource-Component.h>


namespace Game
{

	class BuildingEntity : public GameEngine::Entity
	{
	public:
		BuildingEntity(GameEngine::eTexture::type buildingType, int health);
		~BuildingEntity();

		virtual void OnAddToWorld() override;
		virtual void OnRemoveFromWorld() override;
		virtual void Update() override;
		int x;
		int y;
		bool isPlaced;
		GameEngine::eTexture::type buildingType;

	protected:
		GameEngine::SpriteRenderComponent* m_renderComponent;
		Resourcecomponent* m_buildingComponent;


	};
}



