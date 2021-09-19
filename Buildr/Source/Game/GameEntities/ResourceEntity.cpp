#include "ResourceEntity.h"
#include "GameEngine/GameEngineMain.h"
#include <iostream>
#include "GameEngine/EntitySystem/Components/CollidableComponent.h"
using namespace Game;

ResourceEntity::ResourceEntity(int x, int y, GameEngine::eTexture::type resourceType, int health)
	: x(x)
	, y(y)
	, resourceType(resourceType)
{
	//Render 
	m_renderComponent = AddComponent<GameEngine::SpriteRenderComponent>();
	m_renderComponent->SetTexture(resourceType);
	SetPos(sf::Vector2f(x, y));
	SetSize(sf::Vector2f(50, 50));
	m_renderComponent->SetZLevel(2);
	AddComponent<GameEngine::CollidableComponent>();

	/*
	m_resourceComponent = AddComponent<ResourceComponent>();
	m_resourceComponent->setHealth(health);
	m_resourceComponent->setResource(resourceType);
	*/
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

