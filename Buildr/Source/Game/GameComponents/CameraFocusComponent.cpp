#include "CameraFocusComponent.h"

#include "GameEngine/GameEngineMain.h"
#include "GameEngine/Util/CameraManager.h"

using namespace Game;

PlayerCameraComponent::CameraFocusComponent()
{

}


PlayerCameraComponent::~CameraFocusComponent()
{

}

void CameraFocusComponent::OnAddToWorld()
{

}


void CameraFocusComponent::Update()
{
	Component::Update();

	if (!GameEngine::CameraManager::IsFollowCameraEnabled())
		return;

	GameEngine::CameraManager::GetInstance()->GetCameraView().setCenter(GetEntity()->GetPos());
}