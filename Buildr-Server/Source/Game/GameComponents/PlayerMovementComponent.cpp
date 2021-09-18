#include "PlayerMovementComponent.h"

#include "GameEngine/GameEngineMain.h"
#include "GameEngine/EntitySystem/Components/SoundComponent.h"

#include "GameEngine/Util/TextureManager.h"
#include "GameEngine/Util/AnimationManager.h"

#include <SFML/Window/Keyboard.hpp>
#include <cmath>
#include <iostream>

using namespace Game;

sf::Vector2f normalize(const sf::Vector2f source)
{
	float length = sqrt((source.x * source.x) + (source.y * source.y));
	if (length != 0)
		return sf::Vector2f(source.x / length, source.y / length);
	else
		return source;
}
PlayerMovementComponent::PlayerMovementComponent()
    :velocity(0)
{


}



PlayerMovementComponent::~PlayerMovementComponent()
{

}
void PlayerMovementComponent::SetVelocity(float vel){
    velocity = vel;
}

void PlayerMovementComponent::OnAddToWorld()
{
}



void PlayerMovementComponent::Update()
{
	Component::Update();

	float dt = GameEngine::GameEngineMain::GetTimeDelta();


	sf::Vector2f wantedVel = sf::Vector2f(0.f, 0.f);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		wantedVel.x -= dt;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		wantedVel.x += dt;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		wantedVel.y -= dt;

	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		wantedVel.y += dt;

	}
    wantedVel= normalize(wantedVel);
    wantedVel.x *=velocity;
    wantedVel.y *=velocity;

	GetEntity()->SetPos(GetEntity()->GetPos() + wantedVel);

	int mx = sf::Mouse::getPosition(*(GameEngine::GameEngineMain::GetInstance()->m_renderWindow)).x;
	int my = sf::Mouse::getPosition(*(GameEngine::GameEngineMain::GetInstance()->m_renderWindow)).y;
	
	sf::Vector2f playerToMouse = sf::Vector2f(mx - 600, my - 400);
	float rot = atan2(playerToMouse.y, playerToMouse.x) * 180/ 3.14159265f;
	GetEntity()->SetRotation(rot-90);


	


}

