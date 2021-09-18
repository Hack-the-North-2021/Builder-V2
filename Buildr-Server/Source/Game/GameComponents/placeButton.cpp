#include "placeButton.h"
#include "Game/GameComponents/mouseFollowComp.h"

namespace Game {

	void placeButton::OnButtonClicked() {

		GameEngine::Entity* button_test = new GameEngine::Entity();
		GameEngine::GameEngineMain::GetInstance()->AddEntity(button_test);

		button_test->SetPos(sf::Vector2(200.f, 500.f));
		button_test->SetSize(sf::Vector2(100.f, 100.f));

		GameEngine::RenderComponent* render = button_test->AddComponent<GameEngine::RenderComponent>();
		render->SetFillColor(sf::Color(100, 100, 200));
		button_test->AddComponent<mouseFollowComp>();
		
	}
}