#include "TextureManager.h"

using namespace GameEngine;

TextureManager* TextureManager::sm_instance = nullptr;

TextureManager::TextureManager()
{
	for (int a = 0; a < (int)eTexture::Count; ++a)
	{
		m_textures[a] = nullptr;
	}
}


TextureManager::~TextureManager()
{
	UnLoadTextures();
}


void TextureManager::LoadTextures()
{
	for (int a = 0; a < (int)eTexture::Count; ++a)
	{
		sf::Texture* texture = new sf::Texture();
		std::string filePath;
		filePath.append("Resources/img/");
		filePath.append(GetPath((eTexture::type)a));
		texture->loadFromFile(filePath);
		

		m_textures[a] = texture;
	}
}


void TextureManager::UnLoadTextures()
{
	for (int a = 0; a < (int)eTexture::Count; ++a)
	{
		delete m_textures[a];
		m_textures[a] = nullptr;
	}
}

namespace TextureHelper
{
    sf::Vector2f GetTextureTileSize(GameEngine::eTexture::type texture)
    {
        switch (texture)
        {
		case  GameEngine::eTexture::Player:  return sf::Vector2f(700.f,800.f);
        case  GameEngine::eTexture::Tileset: return sf::Vector2f(32.f, 32.f);
        case  GameEngine::eTexture::MAP:	     return sf::Vector2f(12000.f, 8000.f);
        case  GameEngine::eTexture::FOOD:	     return sf::Vector2f(256.f, 256.f);
        case  GameEngine::eTexture::ROCK:	     return sf::Vector2f(256.f, 256.f);
        case  GameEngine::eTexture::TREE:	     return sf::Vector2f(256.f, 256.f);
        case  GameEngine::eTexture::BRONZE:	     return sf::Vector2f(256.f, 256.f);
        case  GameEngine::eTexture::Rectangle:	     return sf::Vector2f(200.f, 600.f);
        case  GameEngine::eTexture::GrassWall:	     return sf::Vector2f(100.f, 100.f);
        case  GameEngine::eTexture::WoodWall:	     return sf::Vector2f(100.f, 100.f);
        case  GameEngine::eTexture::RockWall:	     return sf::Vector2f(100.f, 100.f);
        case  GameEngine::eTexture::BrickWall:	     return sf::Vector2f(100.f, 100.f);
        default:							 return sf::Vector2f(-1.f, -1.f);
        }
    }
}
