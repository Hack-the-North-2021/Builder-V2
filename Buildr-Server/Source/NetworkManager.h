#pragma once

#include "NetworkServer.h"
#include "Resource.h"
#include "Entities.h"
#include "NetworkTypes.h"

#include <map>
#include <vector>

struct s_PlayerUpdate {
    int player_id;
    float x, y, r;
};

typedef Resource s_ResourceUpdate;
typedef Building s_BuildingUpdate;

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

    void broadcastMessage(const nlohmann::json& j);
    void broadcastMessage(int ignore_id, const nlohmann::json& j);

    /* handlers and senders */
    void handlePlayerUpdate(int client_id, const nlohmann::json& j);
    void handleResourceUpdate(int client_id, const nlohmann::json& j);
    void handleBuildingUpdate(int client_id, const nlohmann::json& j);
    
    void sendPlayerUpdate(int player_id, std::vector<s_PlayerUpdate> player_updates);
    void sendResourceUpdate(std::vector<s_ResourceUpdate> resource_updates);
    void sendBuildingUpdate(std::vector<s_BuildingUpdate> building_updates);
};
