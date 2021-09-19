#include "Resource-Component.h"

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

	
}

GameEngine::eTexture::type Resourcecomponent::getResource() {
	return resource;
}

void Resourcecomponent::setHealth(int h) {
	health = h;
	std::cout << health << std::endl;
	
}

void Resourcecomponent::setResource(GameEngine::eTexture::type res) {
	resource = res;
}






void Resourcecomponent::OnAddToWorld()
{}

void Resourcecomponent::Update()
{
	
	
}


