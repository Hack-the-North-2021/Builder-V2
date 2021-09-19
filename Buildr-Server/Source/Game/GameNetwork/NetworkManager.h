#pragma once
#include "Game/GameEntities/NetworkEntity.h"
#include "Game/GameNetwork/NetworkServer.h"
#include "Game/GameEntities/Resource.h"
#include "Game/GameEntities/Player.h"
#include "Game/GameNetwork/NetworkTypes.h"
#include <map>

class NetworkManager {
public:
	static NetworkManager* getInstance() { if (!networkSingleton) networkSingleton = new NetworkManager(); return networkSingleton; }
	void addPlayer(int conn_id) { playerIds.insert( std::pair<int, Player*>(conn_id, new Player(conn_id) )); }
	NetworkServer server;

    void handlePlayerMove(int client_id, const nlohmann::json& json_cmd);
    void sendPlayerMove(std::vector<PlayerTransform>);

private:
	static NetworkManager* networkSingleton;
	std::map<int, Player*> playerIds;
	std::map<int, Resource*> resourceIds;

	NetworkManager();
};
