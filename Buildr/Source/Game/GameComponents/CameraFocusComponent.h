#pragma once
#include "GameEngine/EntitySystem/Component.h"

namespace Game
{
	class CameraFocusComponent : public GameEngine::Component
	{
	public:
		CameraFocusComponent();
		virtual ~CameraFocusComponent();

		virtual void Update() override;
		virtual void OnAddToWorld() override;

	private:
	};
}