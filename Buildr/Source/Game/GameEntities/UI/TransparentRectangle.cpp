#include "TransparentRectangle.h"
#include "GameEngine/GameEngineMain.h"

using namespace Game;

TransparentRectangle::TransparentRectangle()
{

	//Render 
	m_renderComponent = AddComponent<GameEngine::SpriteRenderComponent>();
	SetSize(sf::Vector2f(200.f, 600.f));
	m_renderComponent->SetTexture(GameEngine::eTexture::Rectangle);
	m_renderComponent->SetFillColor(sf::Color(0, 0, 0, 50));
	m_renderComponent->SetZLevel(6);
	GameEngine::GameEngineMain::GetInstance()->AddEntity(this);

}


TransparentRectangle::~TransparentRectangle()
{

}


void TransparentRectangle::OnAddToWorld()
{
	Entity::OnAddToWorld();


	SetEntityTag("UI");
}


void TransparentRectangle::OnRemoveFromWorld()
{
	TransparentRectangle::OnRemoveFromWorld();
}


