
#include "GameBoard.h"

#include "GameEngine/GameEngineMain.h"
#include "GameEngine/EntitySystem/Components/CollidableComponent.h"
#include "GameEngine/EntitySystem/Components/SpriteRenderComponent.h"
#include "GameEngine/EntitySystem/Components/TextRenderComponent.h"
#include "GameEngine/EntitySystem/Components/RenderComponent.h"
#include "GameEngine/Util/CameraManager.h"
#include "Game/GameEntities/PlayerEntity.h"
#include <Game/GameComponents/placeButton.h>


using namespace Game;


GameBoard::GameBoard()
	: player(nullptr)
	, map(nullptr)
{
    player = new PlayerEntity();
	GameEngine::GameEngineMain::GetInstance()->AddEntity(player);
	player->SetPos(sf::Vector2f(200.f, 200.f));
    //player->SetSize(sf::Vector2f(200.f, 200.f));

	resourceManager = new ResourceManagerEntity();

  map = new MapEntity();
	GameEngine::Entity* button_test = new GameEngine::Entity();
	GameEngine::GameEngineMain::GetInstance()->AddEntity(button_test);

	


	button_test->SetPos(sf::Vector2(200.f, 500.f));
	button_test->SetSize(sf::Vector2(100.f, 100.f));

	GameEngine::RenderComponent* render = button_test->AddComponent<GameEngine::RenderComponent>();
	render->SetFillColor(sf::Color(100, 100, 200));
	
	placeButton *buttonComp = button_test->AddComponent<placeButton>();
	
}


GameBoard::~GameBoard()
{

}


void GameBoard::Update()
{	
	float dt = GameEngine::GameEngineMain::GetInstance()->GetTimeDelta();
	
}

