#include "mouseFollowComp.h"

namespace Game {
	
	void mouseFollowComp::Update() {
		if (debounce) {
			if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
				int x = sf::Mouse::getPosition(*(GameEngine::GameEngineMain::GetInstance()->m_renderWindow)).x;
				int y = sf::Mouse::getPosition(*(GameEngine::GameEngineMain::GetInstance()->m_renderWindow)).y;
				GetEntity()->SetPos(sf::Vector2f(x, y));
			}
			else {
				debounce = false;
			}
		}
		
	}
}