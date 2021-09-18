#pragma once
#include "GameEngine/EntitySystem/Component.h"
#include "GameEngine/GameEngineMain.h"

namespace Game
{
	class mouseFollowComp : public GameEngine::Component
	{
	public:
		virtual void Update() override;

	private:
		bool debounce = true;
	};
}