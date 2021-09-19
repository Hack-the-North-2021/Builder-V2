#include "Player.h"
#include "GameEngine/GameEngineMain.h"

Player::Player(int conn_id) {
	GameEngine::GameEngineMain::GetInstance()->AddEntity(this);
	this->health = 100;
	this->conn_id = conn_id;
	this->SetSize(sf::Vector2f(70, 80));
	this->SetPos(sf::Vector2f(0, 0));
	this->SetEntityTag("Player");

	broadcastState();
}

Player::~Player() {

}

void Player::mine(Resource* res) {
	
}

playerData Player::getNetworkData() {
	playerData data;
	data.hp = health;
	data.id = conn_id;
	data.x = this->GetPos().x;
	data.x = this->GetPos().y;

	return data;
}

void Player::broadcastState() {
	playerData data = getNetworkData();

	// Tell all other players: ENUM 0 : data
}