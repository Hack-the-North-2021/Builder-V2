#pragma once
#include "GameEngine/EntitySystem/Entity.h"

#include "GameEngine/EntitySystem/Components/SpriteRenderComponent.h"
#include "Game/GameComponents/PlayerMovementComponent.h"

namespace Game
{

	class PlayerEntity : public GameEngine::Entity
	{
	public:
		static PlayerEntity* GetInstance() { if (!sm_instance) sm_instance = new PlayerEntity(); return sm_instance; }
		~PlayerEntity();

		virtual void OnAddToWorld() override;
		virtual void OnRemoveFromWorld() override;
		void Attack();

	protected:
		GameEngine::SpriteRenderComponent* m_renderComponent;
		PlayerMovementComponent* playerMovementComponent;
	private:
		static PlayerEntity* sm_instance;
		PlayerEntity();
	};
	
}
