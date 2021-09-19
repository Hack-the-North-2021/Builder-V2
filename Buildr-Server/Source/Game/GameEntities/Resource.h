#pragma once
#include "Game/GameEntities/NetworkEntity.h"

class Resource : NetworkEntity
{
public:
	Resource();
	~Resource();

	int id;
	int type;
	int health;
	sf::Vector2f location;

	void broadcastState();

};