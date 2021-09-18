#include "placeButton.h"
#include<thread>

namespace Game {
	bool debounce = true;

	void placeButton::OnButtonClicked() {
		
		if (debounce) {
			debounce = false;
			std::cout << "Clicked\n";

			GameEngine::Entity* button_test = new GameEngine::Entity();
			GameEngine::GameEngineMain::GetInstance()->AddEntity(button_test);

			button_test->SetPos(sf::Vector2(200.f, 500.f));
			button_test->SetSize(sf::Vector2(100.f, 100.f));

			GameEngine::RenderComponent* render = button_test->AddComponent<GameEngine::RenderComponent>();
			render->SetFillColor(sf::Color(100, 100, 200));

			while (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
				//button_test->SetPos(sf::Vector2f(sf::Mouse::getPosition()));
				//sf::sleep(sf::Time(sf::microseconds(50)));
			}
			
			int x = sf::Mouse::getPosition( *(GameEngine::GameEngineMain::GetInstance()->m_renderWindow) ).x;
			int y = sf::Mouse::getPosition( *(GameEngine::GameEngineMain::GetInstance()->m_renderWindow) ).y;
			button_test->SetPos(sf::Vector2f(x, y));
			std::cout << x << " " << y << "\n";
			debounce = true;
		}
	}
}