#pragma once
#include "GameEngine/EntitySystem/Entity.h"
#include <map>

class NetworkEntity : public GameEngine::Entity
{
public:
	NetworkEntity();
	~NetworkEntity();

	void broadcastState();

};