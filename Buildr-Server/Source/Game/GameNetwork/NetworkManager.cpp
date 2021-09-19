#include "NetworkManager.h"

NetworkManager* NetworkManager::networkSingleton = nullptr;

NetworkManager::NetworkManager() 
	:server(8080, std::map<int, NetworkCallback>())
{
	// Create initial resources
	
	// initialize daniel's code here to start listening
	server.OpenConnection();
}

void NetworkManager::handleMove(int conn_id, int temp) {
	if (playerIds.count(conn_id) == 1) {
		Player* plr = playerIds.at(conn_id);

		plr->SetPos(sf::Vector2f()); // set based on json
		plr->broadcastState();
	}
}

void NetworkManager::handleMine(int conn_id, int temp) {
	if (playerIds.count(conn_id) == 1) {
		Player* plr = playerIds.at(conn_id);

		if (resourceIds.count(0) == 1) { // check based on json
			Resource* res = resourceIds.at(0);
			plr->mine(res);
		}
	}

}