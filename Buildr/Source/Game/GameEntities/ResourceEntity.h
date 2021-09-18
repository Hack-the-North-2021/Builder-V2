#pragma once
#include "GameEngine/EntitySystem/Entity.h"

#include "GameEngine/EntitySystem/Components/SpriteRenderComponent.h"

namespace Game
{

	class ResourceEntity : public GameEngine::Entity
	{
	public:
		ResourceEntity(int x, int y, GameEngine::eTexture::type resourceType);
		~ResourceEntity();

		virtual void OnAddToWorld() override;
		virtual void OnRemoveFromWorld() override;
		int x;
		int y;
		GameEngine::eTexture::type resourceType;

	protected:
		GameEngine::SpriteRenderComponent* m_renderComponent;
	};
}

