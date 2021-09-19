#include "BuildingSpawnerEntity.h"
#include "ResourceManagerEntity.h"
#include "GameEngine/Util/randgen.h"
#include "GameEngine/GameEngineMain.h"
#include "GameEngine/EntitySystem/Components/CollidableComponent.h"
#include <iostream>

#include "SFML/Window/Keyboard.hpp"
#include <Game/GameEntities/BuildingEntity.h>
#include <GameEngine/Util/CameraManager.h>

using namespace Game;
bool building = false;
ResourceEntity* currentBuilding;
BuildingSpawnerEntity* BuildingSpawnerEntity::sm_instance = nullptr;

BuildingSpawnerEntity::BuildingSpawnerEntity()
{
}



BuildingSpawnerEntity::~BuildingSpawnerEntity()
{

}


void BuildingSpawnerEntity::OnAddToWorld()
{
	Entity::OnAddToWorld();


	SetEntityTag("BuildingSpawner");
}

void Game::BuildingSpawnerEntity::OnRemoveFromWorld()
{
}

void Game::BuildingSpawnerEntity::Build(int x)

{
	std::cout << "build" << std::endl;
	building = false;
	currentBuilding->AddComponent<GameEngine::CollidableComponent>();
	currentBuilding = nullptr;
}



void BuildingSpawnerEntity::Update() {
	Entity::Update();
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1)&&!building) {
		currentBuilding = new ResourceEntity(0, 0, types[0], 100);
		building = true;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2)&&!building) {
		currentBuilding = new ResourceEntity(0, 0, types[1], 100);
		building = true;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num3)&&!building) {
		currentBuilding = new ResourceEntity(0, 0, types[2], 100);
		building = true;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num4)&&!building) {
		currentBuilding = new ResourceEntity(0, 0, types[3], 100);
		building = true;
	}
	
	else if (building) {
		int mx = sf::Mouse::getPosition(*(GameEngine::GameEngineMain::GetInstance()->m_renderWindow)).x;
		int my = sf::Mouse::getPosition(*(GameEngine::GameEngineMain::GetInstance()->m_renderWindow)).y;
		sf::Vector2f camPos = GameEngine::CameraManager::GetInstance()->GetCameraView().getCenter();

		currentBuilding->SetPos(sf::Vector2f(camPos.x - 600 + mx, camPos.y - 400 + my));

	}
	

}


