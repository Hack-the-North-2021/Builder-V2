#include "PlayerEntity.h"


#include "Game/GameComponents/CameraFocusComponent.h"
#include "Game/GameComponents/PlayerMovementComponent.h"
#include "GameEngine/EntitySystem/Components/CollidablePhysicsComponent.h"
#include <GameEngine/GameEngineMain.h>
#include <iostream>


using namespace Game;
PlayerEntity* PlayerEntity::sm_instance = nullptr;
PlayerEntity::PlayerEntity()
{
	//Render 
	m_renderComponent = AddComponent<GameEngine::SpriteRenderComponent>();
	m_renderComponent->SetTexture(GameEngine::eTexture::Player);
	SetSize(sf::Vector2f(70, 80));
	m_renderComponent->SetZLevel(2);

    playerMovementComponent = AddComponent<PlayerMovementComponent>();
    playerMovementComponent->SetVelocity(1.f);

	AddComponent<GameEngine::CollidablePhysicsComponent>();





	//Camera control
	AddComponent<CameraFocusComponent>();
}
void PlayerEntity::Attack() {
	std::vector<GameEngine::Entity*> resources = GameEngine::GameEngineMain::GetInstance()->GetEntitiesByTag("Resource");
	std::cout << resources.size() << std::endl;
	for (GameEngine::Entity* e : resources) {
		if (e->GetEntityTag() == "MAP") {
			continue;
		}


		float dist = sqrt(pow(e->GetPos().x - GetPos().x, 2) +
			pow(e->GetPos().y - GetPos().y, 2));
		if (dist < 100) {
			e->GetComponent<Resourcecomponent>()->Hit();
		}
	}

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

