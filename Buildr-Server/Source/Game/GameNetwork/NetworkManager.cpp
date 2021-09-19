#include "NetworkManager.h"

NetworkManager* NetworkManager::networkSingleton = nullptr;

NetworkManager::NetworkManager() 
	:server(8080, std::map<int, NetworkCallback>())
{
	// Create initial resources
	
	// initialize daniel's code here to start listening
	server.OpenConnection();
}

void
NetworkManager::handlePlayerMove(int client_id, const nlohmann::json& json_cmd)
{
    
}

void
NetworkManager::sendPlayerMove(std::vector<PlayerTransform>)
{
}
