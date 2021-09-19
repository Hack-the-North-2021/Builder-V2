#pragma once
#include "GameEngine/EntitySystem/Entity.h"

#include "GameEngine/EntitySystem/Components/SpriteRenderComponent.h"
#include "GameEngine/EntitySystem/Components/TextRenderComponent.h"

namespace Game
{

	class ResourceUIEntity : public GameEngine::Entity
	{
	public:

		ResourceUIEntity(GameEngine::eTexture::type resource, float y_offset);

		virtual void OnAddToWorld() override;
		virtual void OnRemoveFromWorld() override;
		virtual void Update() override;

	protected:
		GameEngine::SpriteRenderComponent* m_renderComponent;
		GameEngine::TextRenderComponent* m_textrenderComponent;
		void SETTEXT();
		GameEngine::eTexture::type resource;
	private:
	};
	
}

