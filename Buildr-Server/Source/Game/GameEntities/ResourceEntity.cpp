#include "ResourceEntity.h"
#include "GameEngine/GameEngineMain.h"
#include <iostream>
using namespace Game;

ResourceEntity::ResourceEntity(int x, int y, GameEngine::eTexture::type resourceType)
	: x(x)
	, y(y)
	, resourceType(resourceType)
{
	//Render 
	m_renderComponent = AddComponent<GameEngine::SpriteRenderComponent>();
	m_renderComponent->SetTexture(resourceType);
	SetPos(sf::Vector2f(x, y));
	m_renderComponent->SetZLevel(4);
	GameEngine::GameEngineMain::GetInstance()->AddEntity(this);
}


ResourceEntity::~ResourceEntity()
{

}


void ResourceEntity::OnAddToWorld()
{
	Entity::OnAddToWorld();


	SetEntityTag("Resource");
}


void ResourceEntity::OnRemoveFromWorld()
{

	Entity::OnRemoveFromWorld();
}



