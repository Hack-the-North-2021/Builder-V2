#include "PlayerEntity.h"


#include "Game/GameComponents/PlayerCameraComponent.h"


using namespace Game;

PlayerEntity::PlayerEntity()
{


	//Render 
	m_renderComponent = AddComponent<GameEngine::SpriteRenderComponent>();
	m_renderComponent->SetTexture(GameEngine::eTexture::Player);
	m_renderComponent->SetZLevel(2);


	//Camera control
	AddComponent<PlayerCameraComponent>();
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