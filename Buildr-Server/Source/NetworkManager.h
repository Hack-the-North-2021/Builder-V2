#pragma once

#include "NetworkServer.h"
#include "Resource.h"
#include "Entity.h"
#include "NetworkTypes.h"

#include <map>
#include <vector>

class NetworkManager {
private:
	static NetworkManager* networkSingleton;
	NetworkServer server;
	std::map<int,Player> players_index;
	std::vector<Resource> resources_index;
    std::vector<Building> building_index;

public:
	static NetworkManager* getInstance();

	NetworkManager();
    ~NetworkManager();

	void addPlayer(int player_id);
    void addResource(ResourceType resource_type, float x, float y);
    void addBuilding(BuildingType building_type, float x, float y);

    /* handlers and senders */
    void handlePlayerMove(int client_id, const nlohmann::json& j);
    void sendPlayerUpdate(sPlayerMove d);

};
