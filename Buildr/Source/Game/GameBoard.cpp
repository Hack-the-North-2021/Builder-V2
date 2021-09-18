
#include "GameBoard.h"

#include "GameEngine/GameEngineMain.h"
#include "GameEngine/EntitySystem/Components/CollidableComponent.h"
#include "GameEngine/EntitySystem/Components/SpriteRenderComponent.h"
#include "GameEngine/EntitySystem/Components/TextRenderComponent.h"
#include "GameEngine/Util/CameraManager.h"
#include "Game/GameEntities/PlayerEntity.h"
#include "Game/GameEntities/MapEntity.h"



using namespace Game;





GameBoard::GameBoard()
	: player(nullptr)
	, map(nullptr)
{
    player = new PlayerEntity();
	GameEngine::GameEngineMain::GetInstance()->AddEntity(player);
	player->SetPos(sf::Vector2f(200.f, 200.f));
    //player->SetSize(sf::Vector2f(200.f, 200.f));
	CreateBackGround();


}


GameBoard::~GameBoard()
{

}


void GameBoard::Update()
{	
	float dt = GameEngine::GameEngineMain::GetInstance()->GetTimeDelta();
	
}

void GameBoard::CreateBackGround()
{
	GameEngine::Entity* mapEntity = new MapEntity();
	GameEngine::GameEngineMain::GetInstance()->AddEntity(mapEntity);
	map = mapEntity;
}


void GameBoard::UpdateBackGround()
{
	if (!map) // || !m_player)
		return;

	if (!GameEngine::CameraManager::IsFollowCameraEnabled())
		return;
}

