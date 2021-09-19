#include "BuildingEntity.h"
#include "GameEngine/GameEngineMain.h"
#include <iostream>
#include "GameEngine/EntitySystem/Components/CollidableComponent.h"
#include <GameEngine/Util/CameraManager.h>
using namespace Game;
BuildingEntity::BuildingEntity(GameEngine::eTexture::type buildingType, int health)
	: buildingType(buildingType),x(0),y(0),isPlaced(false)
{
	//Render 
	m_renderComponent = AddComponent<GameEngine::SpriteRenderComponent>();
	m_renderComponent->SetTexture(buildingType);
	SetPos(sf::Vector2f(x, y));
	SetSize(sf::Vector2f(80, 70));
	AddComponent<GameEngine::CollidableComponent>();

	m_buildingComponent = AddComponent<Resourcecomponent>();
	m_buildingComponent->setHealth(health);
	m_buildingComponent->setResource(buildingType);
	m_renderComponent->SetZLevel(2);
	

	GameEngine::GameEngineMain::GetInstance()->AddEntity(this);
}

Game::BuildingEntity::~BuildingEntity()
{
}





void BuildingEntity::OnAddToWorld()
{
	Entity::OnAddToWorld();


	SetEntityTag("Building");
}

void Game::BuildingEntity::OnRemoveFromWorld()
{
}


void BuildingEntity::Update() {
	Entity::Update();
	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1)) {
		isPlaced = true;
	}


}

