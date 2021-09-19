#pragma once
#include "GameEngine/EntitySystem/Component.h"
#include "GameEngine/EntitySystem/Components/AnimationComponent.h"
#include "GameEngine/Util/SoundManager.h"

namespace Game
{
	class PlayerSoundComponent;

	class PlayerMovementComponent : public GameEngine::Component
	{
	public:
		PlayerMovementComponent();
		~PlayerMovementComponent();
        void SetVelocity(float vel);
		

		virtual void Update() override;
		virtual void OnAddToWorld() override;

	private:
		float velocity;
	};
}


