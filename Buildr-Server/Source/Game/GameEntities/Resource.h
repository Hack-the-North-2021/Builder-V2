#pragma once
#include "Game/GameEntities/NetworkEntity.h"

typedef struct resourceData {
	int id;
	int hp;
	float x;
	float y;
	int type;
} resourceData;

class Resource : public NetworkEntity
{
public:
	int health;
	int id;
	int type;

	void broadcastState();
};