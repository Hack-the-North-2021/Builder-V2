
#include "GameBoard.h"

#include "GameEngine/GameEngineMain.h"
#include "GameEngine/EntitySystem/Components/CollidableComponent.h"
#include "GameEngine/EntitySystem/Components/SpriteRenderComponent.h"
#include "GameEngine/EntitySystem/Components/TextRenderComponent.h"
#include "GameEngine/Util/CameraManager.h"
#include "Game/GameEntities/PlayerEntity.h"

using namespace Game;

GameBoard::GameBoard()
	: player(nullptr)
	, map(nullptr)
	, client("127.0.0.1", 8080, std::map<int, NetworkCallback>())
{

	client.OpenConnection();

	player = PlayerEntity::GetInstance();

	GameEngine::GameEngineMain::GetInstance()->AddEntity(player);
	player->SetPos(sf::Vector2f(200.f, 200.f));
    //player->SetSize(sf::Vector2f(200.f, 200.f));

	resourceManager = new ResourceManagerEntity();

	map = new MapEntity();

}


GameBoard::~GameBoard()
{

}


void GameBoard::Update()
{	
	float dt = GameEngine::GameEngineMain::GetInstance()->GetTimeDelta();
	
}

