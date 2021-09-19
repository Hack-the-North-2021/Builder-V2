#pragma once
#include"GameEngine/GameEngineMain.h"
#include "Game/GameEntities/NetworkEntity.h"
#include "Game/GameEntities/Resource.h"
#include "Game/GameEntities/Player.h"
#include <map>

class NetworkManager {
public:
	static NetworkManager* getInstance() { if (!networkSingleton) networkSingleton = new NetworkManager(); return networkSingleton; }
	void addPlayer(int conn_id) { playerIds.insert( std::pair<int, Player*>(conn_id, new Player(conn_id) )); }
	void handleMove(int conn_id, int temp);
	void handleMine(int conn_id, int temp);

private:
	static NetworkManager* networkSingleton;
	std::map<int, Player*> playerIds;
	std::map<int, Resource*> resourceIds;

	NetworkManager();

};