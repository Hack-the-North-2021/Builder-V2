#include "CameraFocusComponent.h"
#include <iostream>
#include "GameEngine/GameEngineMain.h"
#include "GameEngine/Util/CameraManager.h"

using namespace Game;

CameraFocusComponent::CameraFocusComponent()
{

}


CameraFocusComponent::~CameraFocusComponent()
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