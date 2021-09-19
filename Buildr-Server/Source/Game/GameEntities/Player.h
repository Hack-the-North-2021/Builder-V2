#pragma once
#include "Game/GameEntities/NetworkEntity.h"
#include "Game/GameEntities/Resource.h"

typedef struct playerData {
	int id;
	int hp;
	float x;
	float y;
} playerData;

enum resourceIndex
{
	Forest = 0,
	Metal = 1,
	Gold = 2,
	Food = 3
};

class Player : public NetworkEntity
{
public:
	Player(int conn_id);
	~Player();
	int *resources = new int[4]{50, 0, 0, 100};
	int health;
	int conn_id;

	void mine(Resource* res);
	playerData getNetworkData();
	void broadcastState();
};