#include "MapEntity.h"
#include "GameEngine/GameEngineMain.h"

using namespace Game;

MapEntity::MapEntity()
{


	//Render 
	m_renderComponent = AddComponent<GameEngine::SpriteRenderComponent>();
	m_renderComponent->SetTexture(GameEngine::eTexture::MAP);
	m_renderComponent->SetZLevel(0);
	GameEngine::GameEngineMain::GetInstance()->AddEntity(this);



	//Camera control
	// AddComponent<CameraFocusComponent>();
}


MapEntity::~MapEntity()
{

}


void MapEntity::OnAddToWorld()
{
	Entity::OnAddToWorld();


	SetEntityTag("MAP");
}


void MapEntity::OnRemoveFromWorld()
{
	MapEntity::OnRemoveFromWorld();
}


