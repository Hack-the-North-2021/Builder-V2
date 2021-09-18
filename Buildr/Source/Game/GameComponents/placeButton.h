#pragma once
#include "GameEngine/GameEngineMain.h"
#include "GameEngine/EntitySystem/Components/ButtonComponent.h"
#include <iostream>

namespace Game {
	class placeButton : public GameEngine::ButtonComponent {
	public:
		void OnButtonClicked();
	};
}