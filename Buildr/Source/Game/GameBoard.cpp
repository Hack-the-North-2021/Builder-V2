
#include "GameBoard.h"

#include "GameEngine/GameEngineMain.h"
#include "GameEngine/EntitySystem/Components/CollidableComponent.h"
#include "GameEngine/EntitySystem/Components/SpriteRenderComponent.h"
#include "GameEngine/EntitySystem/Components/TextRenderComponent.h"
#include "GameEngine/Util/CameraManager.h"
// #include "Game/GameEntities/PlayerEntity.h"
// #include "Game/GameEntities/ObstacleEntity.h"

using namespace Game;

GameBoard::GameBoard()
	: player(nullptr)
	, map(nullptr)
	, isGameOver(false)
	, playerX(50.f)
	, playerY(50.f)

{
	// player = new PlayerEntity();
	// GameEngine::GameEngineMain::GetInstance()->AddEntity(player);
	CreateBackGround();

}


GameBoard::~GameBoard()
{

}


void GameBoard::Update()
{	
	float dt = GameEngine::GameEngineMain::GetInstance()->GetTimeDelta();
	if (!isGameOver)
	{
		/*
		m_lastObstacleSpawnTimer -= dt;
		if (m_lastObstacleSpawnTimer <= 0.f)
		{
			SpawnNewRandomObstacles();
			SpawnNewRandomTiledObstacles();
		}
		*/

		// UpdateObstacles(dt);
		UpdateBackGround();
		// UpdatePlayerDying();
	}
}

void GameBoard::CreateBackGround()
{
	GameEngine::Entity* bgEntity = new GameEngine::Entity();
	GameEngine::SpriteRenderComponent* render = bgEntity->AddComponent<GameEngine::SpriteRenderComponent>();
	render->SetTexture(GameEngine::eTexture::BG);
	render->SetZLevel(0);
	bgEntity->SetPos(sf::Vector2f(250.f, 250.f));
	bgEntity->SetSize(sf::Vector2f(12000.f, 8000.f));
	GameEngine::GameEngineMain::GetInstance()->AddEntity(bgEntity);

	map = bgEntity;
}


void GameBoard::UpdateBackGround()
{
	if (!map) // || !m_player)
		return;

	if (!GameEngine::CameraManager::IsFollowCameraEnabled())
		return;

	map->SetPos(sf::Vector2f(playerX, playerY));
}

