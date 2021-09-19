#include "RectangleEntity.h"
#include "GameEngine/GameEngineMain.h"

using namespace Game;

RectangleEntity::RectangleEntity()
{


	//Render 
	m_renderComponent = AddComponent<GameEngine::SpriteRenderComponent>();
	m_renderComponent->SetTexture(GameEngine::eTexture::MAP);
	m_renderComponent->SetZLevel(0);
	GameEngine::GameEngineMain::GetInstance()->AddEntity(this);



	//Camera control
	// AddComponent<CameraFocusComponent>();
}


RectangleEntity::~RectangleEntity()
{

}


void RectangleEntity::OnAddToWorld()
{
	GameEngine::Entity::OnAddToWorld();


	SetEntityTag("MAP");
}


void RectangleEntity::OnRemoveFromWorld()
{
	RectangleEntity::OnRemoveFromWorld();
}


