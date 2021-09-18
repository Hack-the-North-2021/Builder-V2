
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
{
    player = new PlayerEntity();
	GameEngine::GameEngineMain::GetInstance()->AddEntity(player);
	player->SetPos(sf::Vector2f(50.f, 50.f));
    player->SetSize(sf::Vector2f(40.f, 40.f));
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
}

