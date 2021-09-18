#include "GameBoard.h"

#include "GameEngine/GameEngineMain.h"


using namespace Game;

GameBoard::GameBoard():m_player(nullptr)
{
    m_player = new PlayerEntity();
    GameEngine::GameEngineMain::GetInstance()->AddEntity(m_player);
    m_player->SetPos(sf::Vector2f(50.f, 50.f));
    m_player->SetSize(sf::Vector2f(40.f, 40.f));


}


GameBoard::~GameBoard()
{

}


void GameBoard::Update()
{	
	
}