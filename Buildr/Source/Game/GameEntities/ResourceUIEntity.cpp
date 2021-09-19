#include "ResourceUIEntity.h"
#include "GameEngine/GameEngineMain.h"
#include "PlayerEntity.h"
#include <string>

using namespace Game;

ResourceUIEntity::ResourceUIEntity(GameEngine::eTexture::type resource, float y_offset)
	: resource(resource)
{
	/*
	m_renderComponent = AddComponent<GameEngine::SpriteRenderComponent>();
	m_renderComponent->SetTexture(resource);
	m_renderComponent->SetZLevel(8);
	*/

	m_textrenderComponent = AddComponent<GameEngine::TextRenderComponent>();
	m_textrenderComponent->SetZLevel(10);
	SetLocalPosOffset(sf::Vector2f(300.f, y_offset));
	m_textrenderComponent->SetFont("SEGOEUI.TTF");
	SETTEXT();


	GameEngine::GameEngineMain::GetInstance()->AddEntity(this);


}
void ResourceUIEntity::OnAddToWorld()
{
	Entity::OnAddToWorld();


	SetEntityTag("UI");
}


void ResourceUIEntity::OnRemoveFromWorld()
{
	Entity::OnRemoveFromWorld();
}

void ResourceUIEntity::SETTEXT()
{
	std::string ans = "";
	PlayerEntity* player = PlayerEntity::GetInstance();
	switch (resource) {
		case (GameEngine::eTexture::BRONZE) : 
		{
				//ans = player->bronze;
			ans = "Bronze: " + std::to_string(player->bronze);
				break;
		}
		case (GameEngine::eTexture::FOOD) : 
		{
			ans = "Food: " + std::to_string(player->food);
			break;
		}
		case (GameEngine::eTexture::TREE): 
		{
			ans = "Tree: " + std::to_string(player->tree);
			break;
		}
		case GameEngine::eTexture::ROCK :
		{
			ans = "Rock: " + std::to_string(player->rock);
			break;
		}
	}

	m_textrenderComponent->SetString(ans);
	
}

void ResourceUIEntity::Update(){
	Entity::Update();
	SETTEXT();


}




