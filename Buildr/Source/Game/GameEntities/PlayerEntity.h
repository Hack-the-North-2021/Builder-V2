#pragma once
#include "GameEngine/EntitySystem/Entity.h"

#include "GameEngine/EntitySystem/Components/SpriteRenderComponent.h"

namespace Game
{

	class PlayerEntity : public GameEngine::Entity
	{
	public:
		PlayerEntity();
		~PlayerEntity();

		virtual void OnAddToWorld() override;
		virtual void OnRemoveFromWorld() override;

	protected:
		GameEngine::SpriteRenderComponent* m_renderComponent;
	};
}

