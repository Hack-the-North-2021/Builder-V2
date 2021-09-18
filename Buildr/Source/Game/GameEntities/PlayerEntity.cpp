#include "PlayerEntity.h"


#include "Game/GameComponents/CameraFocusComponent.h"
#include "Game/GameComponents/PlayerMovementComponent.h"


using namespace Game;

PlayerEntity::PlayerEntity()
{
	//Render 
	m_renderComponent = AddComponent<GameEngine::SpriteRenderComponent>();
	m_renderComponent->SetTexture(GameEngine::eTexture::Player);
	SetSize(sf::Vector2f(70, 80));
	m_renderComponent->SetZLevel(2);

    playerMovementComponent = AddComponent<PlayerMovementComponent>();
    playerMovementComponent->SetVelocity(69);




	//Camera control
	AddComponent<CameraFocusComponent>();
}


PlayerEntity::~PlayerEntity()
{

}


void PlayerEntity::OnAddToWorld()
{
	Entity::OnAddToWorld();


	SetEntityTag("Player");
}


void PlayerEntity::OnRemoveFromWorld()
{
	Entity::OnRemoveFromWorld();
}

