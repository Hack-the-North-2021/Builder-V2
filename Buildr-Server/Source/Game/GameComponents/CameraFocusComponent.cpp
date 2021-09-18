#include "CameraFocusComponent.h"
#include <iostream>
#include "GameEngine/GameEngineMain.h"
#include "GameEngine/Util/CameraManager.h"
#include <cmath>
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
	float dt = GameEngine::GameEngineMain::GetTimeDelta();
	sf::Vector2f camPos = GameEngine::CameraManager::GetInstance()->GetCameraView().getCenter();
	sf::Vector2f entityPos = GetEntity()->GetPos();
	float fx = camPos.x + 0.1* (entityPos.x - camPos.x);
	float fy = camPos.y + 0.1* (entityPos.y - camPos.y);


	GameEngine::CameraManager::GetInstance()->GetCameraView().setCenter(sf::Vector2f(fx,fy));
}