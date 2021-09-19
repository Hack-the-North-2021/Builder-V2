#include "BuildingSpawnerEntity.h"
#include "ResourceManagerEntity.h"
#include "GameEngine/Util/randgen.h"
#include "GameEngine/GameEngineMain.h"
#include "GameEngine/EntitySystem/Components/CollidableComponent.h"
#include <iostream>

#include "SFML/Window/Keyboard.hpp"
#include <Game/GameEntities/BuildingEntity.h>
#include <GameEngine/Util/CameraManager.h>
#include <Game/GameEntities/PlayerEntity.h>

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
	PlayerEntity* player = PlayerEntity::GetInstance();
	if (!building) return;
	building = false;
	if (x == 1) {
		player->food -= 5;
	}
	else if (x == 2) {
		player->food -= 5;
		player->tree -= 5;
	}
	else if (x == 3) {
		player->tree -= 5;
		player->rock -= 5;
	}
	else if (x == 4) {
		player->food -= 5;
		player->tree -= 5;
		player->rock -= 5;
		player->bronze -= 5;
	}


	currentBuilding->AddComponent<GameEngine::CollidableComponent>();
	currentBuilding = nullptr;
}



void BuildingSpawnerEntity::Update() {
	Entity::Update();
	PlayerEntity* player = PlayerEntity::GetInstance();
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1)&&!building) {
		if (player->food >= 5) {
			currentBuilding = new ResourceEntity(0, 0, types[0], 100);
			building = true;
		}

	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2)&&!building) {
		if (player->food >= 5 && player->tree >= 5) {
			currentBuilding = new ResourceEntity(0, 0, types[1], 200);
			building = true;
		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num3)&&!building) {
		if (player->tree >= 5 && player->rock >= 5) {
			currentBuilding = new ResourceEntity(0, 0, types[2], 300);
			building = true;

		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num4)&&!building) {
		if (player->food >= 5 && player->tree >= 5 && player->rock >= 5 && player->bronze > 5) {
		if (player->food >= 20 && player->tree >= 30 && player->rock >= 40 && player->bronze > 50) {
			currentBuilding = new ResourceEntity(0, 0, types[3], 400);
			building = true;
		}
	}
	
	else if (building) {
		int mx = sf::Mouse::getPosition(*(GameEngine::GameEngineMain::GetInstance()->m_renderWindow)).x;
		int my = sf::Mouse::getPosition(*(GameEngine::GameEngineMain::GetInstance()->m_renderWindow)).y;
		sf::Vector2f camPos = GameEngine::CameraManager::GetInstance()->GetCameraView().getCenter();

		currentBuilding->SetPos(sf::Vector2f(camPos.x - 600 + mx, camPos.y - 400 + my));

	}
	

}


