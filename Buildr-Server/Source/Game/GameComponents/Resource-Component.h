#pragma once
#include "GameEngine/EntitySystem/Entity.h"
#include "GameEngine/EntitySystem/Component.h"
#include "GameEngine/EntitySystem/Components/SpriteRenderComponent.h"
#include "Game/GameComponents/Resource-Component.h"

namespace Game
{
	class Resourcecomponent : public GameEngine::Component
	{
	public:
		Resourcecomponent();
		~Resourcecomponent();
        void Hit();
		void setHealth(int health);
		void setResource(GameEngine::eTexture::type resource);

		virtual void Update() override;
		virtual void OnAddToWorld() override;

		GameEngine::eTexture::type getResource();


	private:
		int health;
		GameEngine::eTexture::type resource;
	};
}


