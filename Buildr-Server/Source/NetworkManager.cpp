#include "NetworkManager.h"

enum NetworkCommands {
    PLAYER_JOIN = 1,
    PLAYER_LEAVE,
    PLAYER_MOVE
};

NetworkManager* NetworkManager::networkSingleton = nullptr;


static NetworkManager*
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
    Player new_player = {
        .player_id = player_id,
        .hp = 100,
        .x = 0, .y = 0, .r = 0,
        .resources = {0, 0, 0, 0}
    };
    players_index.insert(std::pair<int,Player>(player_id, new_player));
}

void
NetworkManager::addResource(ResourceType resource_type, float x, float y)
{
    Resource new_resource = {
        .resource_type = resource_type,
        .hp = 100,
        .x = x, .y = y
    };
    resources_index.push_back(new_resource);
}

void
NetworkManager::addBuilding(BuildingType building_type, float x, float y)
{
    Building new_building = {
        .building_type = building_type,
        .x = x, .y = y
    };
    building_index.push_back(new_building);
}

void
NetworkManager::handlePlayerMove(int client_id, const nlohmann::json& j)
{
    auto parsed = j.get<hPlayerMove>();

}

void
NetworkManager::sendPlayerUpdate(sPlayerMove d)
{
    nlohmann::json encoded = sPlayerMove;

}
