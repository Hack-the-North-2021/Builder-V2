#include "PlayerMovementComponent.h"

#include "GameEngine/GameEngineMain.h"
#include "GameEngine/EntitySystem/Components/SoundComponent.h"

#include "GameEngine/Util/TextureManager.h"
#include "GameEngine/Util/AnimationManager.h"

#include "Game/GameComponents/PlayerSoundComponent.h"

#include <SFML/Window/Keyboard.hpp>
#include <cmath>

using namespace Game;
Vector2 normalize(const Vector2& source)
{
    float length = sqrt((source.x * source.x) + (source.y * source.y));
    if (length != 0)
        return Vector2(source.x / length, source.y / length);
    else
        return source;
}

PlayerMovementComponent::PlayerMovementComponent()
    :velocity
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
    float length = normalize(wantedVel);
    wantedVel.x *=velocity;
    wantedVel.y *=velocity;

	GetEntity()->SetPos(GetEntity()->GetPos() + wantedVel);

}
