#include "Resource-Component.h"
#include "GameEngine/GameEngineMain.h"
using namespace Game;
#include <iostream>
Resourcecomponent::Resourcecomponent() :health(0)
{
	
}

Resourcecomponent::~Resourcecomponent()
{}

void Resourcecomponent::Hit()
{
	health -= 20;
	if (health <= 0) {
		GameEngine::GameEngineMain::GetInstance()->RemoveEntity(GetEntity());
	}

	
}

GameEngine::eTexture::type Resourcecomponent::getResource() {
	return resource;
}

void Resourcecomponent::setHealth(int h) {
	health = h;
	
}

void Resourcecomponent::setResource(GameEngine::eTexture::type res) {
	resource = res;
}






void Resourcecomponent::OnAddToWorld()
{}

void Resourcecomponent::Update()
{
	
	
}


