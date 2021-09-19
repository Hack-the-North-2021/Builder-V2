#include "PlayerEntity.h"


#include "Game/GameComponents/CameraFocusComponent.h"
#include "Game/GameComponents/PlayerMovementComponent.h"
#include "GameEngine/EntitySystem/Components/CollidablePhysicsComponent.h"
#include <GameEngine/GameEngineMain.h>
#include <iostream>


using namespace Game;
PlayerEntity* PlayerEntity::sm_instance = nullptr;

PlayerEntity::PlayerEntity():tree(0),rock(0),food(0),bronze(0)
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
	std::vector<GameEngine::Entity*> buildings = GameEngine::GameEngineMain::GetInstance()->GetEntitiesByTag("Building");
	resources.insert(resources.end(), buildings.begin(), buildings.end());
	for (GameEngine::Entity* e : resources) {
		if (e->GetEntityTag() == "MAP") {
			continue;
		}


		float dist = sqrt(pow(e->GetPos().x - GetPos().x, 2) +
			pow(e->GetPos().y - GetPos().y, 2));
		if (dist < 100) {
			Resourcecomponent* resource = e->GetComponent<Resourcecomponent>();
			
			switch (resource->getResource()) {
				case (GameEngine::eTexture::BRONZE) : 
				{
						bronze += 1;
						break;
				}
				case (GameEngine::eTexture::FOOD) : 
				{
					food += 1;
					break;
				}
				case (GameEngine::eTexture::TREE): 
				{
					tree += 1;
					break;
				}
				case GameEngine::eTexture::ROCK :
				{
					rock += 1;
					break;
				}
				case GameEngine::eTexture::WALL:
				{
					std::cout << "break wall" << std::endl;
					break;
				}
			}
			resource->Hit();
			break;
			
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

