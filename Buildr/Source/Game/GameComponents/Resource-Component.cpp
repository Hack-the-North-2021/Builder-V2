#include "Resource-Component.h"

using namespace Game;

Resourcecomponent::Resourcecomponent()
{
	
}

Resourcecomponent::~Resourcecomponent()
{}

void Resourcecomponent::Hit()
{
	health -= 20;
	// GetEntity()->~Entity;
}

GameEngine::eTexture::type Resourcecomponent::getResource() {
	return resource;
}

void Resourcecomponent::setHealth(int health) {
	this->health = health;
}

void Resourcecomponent::setResource(GameEngine::eTexture::type resource) {
	this->resource = resource;
}






void Resourcecomponent::OnAddToWorld()
{}

void Resourcecomponent::Update()
{}


