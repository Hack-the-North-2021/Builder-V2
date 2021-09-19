#include "NetworkManager.h"

enum h_NetworkCommands {
    H_PLAYER_UPDATE = 1,
    H_RESOURCE_UPDATE,
    H_BUILDING_UPDATE
};

enum s_NetworkCommands {
    S_PLAYER_UPDATE = 1,
    S_RESOURCE_UPDATE,
    S_BUILDING_UPDATE
};

NetworkManager* NetworkManager::networkSingleton = nullptr;

NetworkManager*
NetworkManager::getInstance()
{
    if (!networkSingleton)
        networkSingleton = new NetworkManager();
    return networkSingleton;
}

NetworkManager::NetworkManager() 
	:server(8080, std::map<int, NetworkCallback>())
{
	server.OpenConnection();
}

NetworkManager::~NetworkManager() { }

void
NetworkManager::addPlayer(int player_id)
{
    Player new_player(player_id);
    players_index.insert(std::pair<int,Player>(player_id, new_player));
}

void
NetworkManager::addResource(ResourceType resource_type, float x, float y)
{
    Resource new_resource(resource_type, 100, x, y);
    resources_index.push_back(new_resource);
}

void
NetworkManager::addBuilding(BuildingType building_type, float x, float y)
{
    Building new_building(building_type, x, y);
    building_index.push_back(new_building);
}

void
NetworkManager::broadcastMessage(const nlohmann::json& j)
{
    for (const auto &[k, v] : players_index) server.SendRawMessage(v.player_id, j);
}

void
NetworkManager::broadcastMessage(int ignore_id, const nlohmann::json& j)
{
    for (const auto &[k, v] : players_index) {
        if (k == ignore_id) continue;
        server.SendRawMessage(v.player_id, j);   
    }
}

void
NetworkManager::handlePlayerUpdate(int client_id, const nlohmann::json& j)
{
}

void
NetworkManager::handleResourceUpdate(int client_id, const nlohmann::json& j)
{
}

void
NetworkManager::handleBuildingUpdate(int client_id, const nlohmann::json& j)
{
}

void
NetworkManager::sendPlayerUpdate(int player_id, std::vector<s_PlayerUpdate> player_updates)
{
    //nlohmann::json j = {
    //    {"cmd", S_PLAYER_UPDATE},
    //    {"updates", player_updates}
    //};
    //broadcastMessage(player_id, j);
}

void
NetworkManager::sendResourceUpdate(std::vector<s_ResourceUpdate> resource_updates)
{
}

void
NetworkManager::sendBuildingUpdate(std::vector<s_BuildingUpdate> building_updates)
{
}

