#include "SpriteRenderComponent.h"

#include "GameEngine/GameEngineMain.h"
#include "GameEngine/Util/CameraManager.h"
#include <iostream>
using namespace GameEngine;
bool rectOverlap(float x1, float y1, float w1, float h1, float x2, float y2, float w2, float h2) {
	return (((x2 + w2 / 2 >= x1 - w1 / 2) && (x2 - w2 / 2 <= x1 + w1 / 2)) &&
		((y2 + h2 / 2 >= y1 - h1 / 2) && (y2 - h2 / 2 <= y1 + h1 / 2)));


}
SpriteRenderComponent::SpriteRenderComponent()	
	: m_texture(eTexture::None)
	, m_tileIndex(sf::Vector2i(0, 0))
	, m_animComponent(nullptr)
{

}


SpriteRenderComponent::~SpriteRenderComponent()
{

}


void SpriteRenderComponent::OnAddToWorld()
{
	Component::OnAddToWorld();
	UpdateSpriteParams();

	m_animComponent = GetEntity()->GetComponent<AnimationComponent>();
}

void SpriteRenderComponent::UpdateSpriteParams()
{
	if (m_texture == eTexture::None)
		return;

	//We set the sprite texture to the one provided in the parameters
	sf::Texture* texture = TextureManager::GetInstance()->GetTexture(m_texture);
	m_sprite.setTexture(*texture);	
	
	//This grabs the size of the tiled texture and IN CASE the texture is set as tiled, gets the size of the tile
	sf::Vector2f textureSize = sf::Vector2f(texture->getSize());
	if (TextureHelper::GetTextureTileSize(m_texture).x > 0.f)
	{
		textureSize = TextureHelper::GetTextureTileSize(m_texture);
	}

	//We then use size of a tile, or size of a texture to figure out which part of the image do we draw as sprite
	//This is done via specifying a rectangle that marks the portion of texture we are interested in
	sf::IntRect textureRect((int)textureSize.x * m_tileIndex.x, (int)textureSize.y * m_tileIndex.y, (int)textureSize.x, (int)textureSize.y);
	m_sprite.setTextureRect(textureRect);

	//Having the origing of the sprite set to the centre helps a lot, especially with rotations
	m_sprite.setOrigin(sf::Vector2f(textureSize.x / 2.f, textureSize.y / 2.f));
	
	//If we have specified size, rescale to fit - meaning - we can grab 32x32 px texture and render it on 128x128 sprite if we want:
	if (GetEntity()->GetSize().x > 0.f && GetEntity()->GetSize().y > 0.f)
	{
		float scaleX = GetEntity()->GetSize().x / textureSize.x;
		float scaleY = GetEntity()->GetSize().y / textureSize.y;

		m_sprite.setScale(sf::Vector2f(scaleX, scaleY));
	}
}


void SpriteRenderComponent::UpdateTileRect()
{
	sf::Texture* texture = TextureManager::GetInstance()->GetTexture(m_texture);
	if (!texture)
		return;

	//This updates the wanted rectangle of the texture and is used when animations are playing
	sf::Vector2f textureSize = sf::Vector2f(texture->getSize());
	if (TextureHelper::GetTextureTileSize(m_texture).x > 0.f)
	{
		textureSize = TextureHelper::GetTextureTileSize(m_texture);
	}

	sf::IntRect textureRect((int)textureSize.x * m_tileIndex.x, (int)textureSize.y * m_tileIndex.y, (int)textureSize.x, (int)textureSize.y);
	m_sprite.setTextureRect(textureRect);
}


void SpriteRenderComponent::Update()
{
	//If we have an animation component and there is an animation playing, use this info to figure out your wanted texture tile
	if (m_animComponent && m_animComponent->IsAnimPlaying())
	{
		SetTileIndex(m_animComponent->GetWantedTileIndex());
	}		

	UpdateTileRect();
}


void SpriteRenderComponent::SetTexture(eTexture::type texture)
{
	m_texture = texture;	
}


void SpriteRenderComponent::Render(sf::RenderTarget* target)
{
	sf::Vector2f camPos = GameEngine::CameraManager::GetInstance()->GetCameraView().getCenter();
	sf::Vector2f spritePos = GetEntity()->GetPos();

	/*if (GetEntity()->GetEntityTag() != "MAP" && GetEntity()->GetEntityTag() != "Player") {
		if (camPos.x - 600 <= spritePos.x && spritePos.x <= camPos.x + 600 && camPos.y - 400 <= spritePos.y && spritePos.y <= camPos.y + 400) {

		}
		else {
			return;
		}
	}*/
	
	sf::Vector2f spriteSize = GetEntity()->GetSize();
	//std::cout << spriteSize.x << " " << spriteSize.y << std::endl;
	if (!rectOverlap(camPos.x,camPos.y,1200,800,spritePos.x,spritePos.y,spriteSize.x,spriteSize.y)&& GetEntity()->GetEntityTag() != "MAP") {
		return;

	}

	
	RenderComponent::Render(target);

	if (!target)
	{
		return;
	}
	
	//After the values are set, render itself is pretty simple
	m_sprite.setPosition(GetEntity()->GetPos());
	m_sprite.setRotation(GetEntity()->GetRot());
	
	


	target->draw(m_sprite);
}