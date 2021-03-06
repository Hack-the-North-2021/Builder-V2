#pragma once
#include <vector>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/Vector2.hpp>

namespace GameEngine
{
	//TODO - if needed, move out of Engine part to some sort of loader on the game side of things
	namespace eTexture
	{
		enum type
		{
			None = -1,
			Player = 0,
			Tileset,
			MAP,
			Particles,
			FOOD,
			ROCK,
			TREE,
			BRONZE,
			Rectangle,
			GrassWall,
			WoodWall,
			RockWall,
			BrickWall,
			Count,

		};
	}
	

	inline const char* GetPath(eTexture::type texture)
	{
		switch (texture)
		{
		case eTexture::Player:    return "player.png";
		case eTexture::Tileset:   return "player.png";
		case eTexture::Particles:   return "player.png";
		case eTexture::MAP:		  return "/map/MapFinal.png";
		case eTexture::FOOD:	  return "/resource/food.png";
		case eTexture::ROCK:	  return "/resource/rock.png";
		case eTexture::TREE:	  return "/resource/tree.png";
		case eTexture::BRONZE:	  return "/resource/bronze.png";
		case eTexture::Rectangle: return "/shapes/rectangle.png";
		case eTexture::GrassWall: return "/buildings/grasswall.png";
		case eTexture::WoodWall: return "/buildings/woodwall.png";
		case eTexture::RockWall: return "/buildings/rockwall.png";
		case eTexture::BrickWall: return "/buildings/brickwall.png";
		default:       return "UnknownTexType";
		}
	}

	class TextureManager
	{
	public:
		static TextureManager* GetInstance() { if (!sm_instance) sm_instance = new TextureManager(); return sm_instance; }
		~TextureManager();

		void LoadTextures();
		void UnLoadTextures();

		sf::Texture* GetTexture(eTexture::type texture) const { return m_textures[(int)texture]; }

	private:
		TextureManager();
		static TextureManager* sm_instance;

		sf::Texture* m_textures[eTexture::Count];
	};
}

namespace TextureHelper
{
	sf::Vector2f GetTextureTileSize(GameEngine::eTexture::type texture);
}

