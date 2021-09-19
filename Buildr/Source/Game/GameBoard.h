#pragma once
#include "GameEngine/EntitySystem/Entity.h"

#include <SFML/System/Vector2.hpp>
#include <vector>
#include "Game/GameEntities/ResourceManagerEntity.h"
#include "Game/GameEntities/BuildingSpawnerEntity.h"
#include "Game/GameEntities/MapEntity.h"

namespace Game
{
	//Used for storing and controlling all game related entities, as well as providing an entry point for the "game" side of application	
	class PlayerEntity;	

	class GameBoard
	{
	public:
		GameBoard();
		virtual ~GameBoard();

		void Update();		

		

		bool IsGameOver() { return false; }

	protected: 
		void CreateBackGround();
		void UpdateBackGround();

		PlayerEntity* player;
		MapEntity* map;
		ResourceManagerEntity* resourceManager;
		BuildingSpawnerEntity* buildingSpawner;

		
	};
}

