
#include "GameBoard.h"

#include "GameEngine/GameEngineMain.h"
#include "GameEngine/EntitySystem/Components/CollidableComponent.h"
#include "GameEngine/EntitySystem/Components/SpriteRenderComponent.h"
#include "GameEngine/EntitySystem/Components/TextRenderComponent.h"
#include "GameEngine/Util/CameraManager.h"
#include "Game/GameEntities/PlayerEntity.h"
#include "Game/GameEntities/ResourceUIEntity.h"
#include "Game/GameEntities/UI/TransparentRectangle.h"

using namespace Game;

GameBoard::GameBoard()
	: player(nullptr)
	, map(nullptr)
	// , client("127.0.0.1", 8080, std::map<int, NetworkCallback>())
{

	// client.OpenConnection();

	player = PlayerEntity::GetInstance();

	GameEngine::GameEngineMain::GetInstance()->AddEntity(player);
	player->SetPos(sf::Vector2f(200.f, 200.f));
	UI = new GameEngine::Entity();
	UI->SetPos(GameEngine::CameraManager::GetInstance()->GetCameraView().getCenter());

	GameEngine::Entity* point = new ResourceUIEntity(GameEngine::eTexture::FOOD, 0);
	point->SetParent(UI);
	point->SetLocalPosOffset(sf::Vector2f(400.f, 0.f));

	point = new ResourceUIEntity(GameEngine::eTexture::TREE, 300.f);
	point->SetParent(UI);
	point->SetLocalPosOffset(sf::Vector2f(400.f, 300.f));

	point = new ResourceUIEntity(GameEngine::eTexture::ROCK, 200.f);
	point->SetParent(UI);
	point->SetLocalPosOffset(sf::Vector2f(400.f, 200.f));

	point = new ResourceUIEntity(GameEngine::eTexture::BRONZE, 100.f);
	point->SetParent(UI);
	point->SetLocalPosOffset(sf::Vector2f(400.f, 100.f));

	point = new TransparentRectangle();
	point->SetParent(UI);
	point->SetLocalPosOffset(sf::Vector2f(450.f, 250.f));

	GameEngine::GameEngineMain::GetInstance()->AddEntity(UI);

	resourceManager = new ResourceManagerEntity();
	buildingSpawner = BuildingSpawnerEntity::GetInstance();
	GameEngine::GameEngineMain::GetInstance()->AddEntity(resourceManager);
	GameEngine::GameEngineMain::GetInstance()->AddEntity(buildingSpawner);

	map = new MapEntity();

}


GameBoard::~GameBoard()
{

}


void GameBoard::Update()
{	
	float dt = GameEngine::GameEngineMain::GetInstance()->GetTimeDelta();
	UI->SetPos(GameEngine::CameraManager::GetInstance()->GetCameraView().getCenter());
}

