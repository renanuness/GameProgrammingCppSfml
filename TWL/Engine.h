#pragma once
#include <SFML/Graphics.hpp>
#include "TextureHolder.h"
#include "Thomas.h"
#include "Bob.h"

using namespace sf;

class Engine
{
private:
	TextureHolder th;

	Thomas m_Thomas;
	Bob m_Bob;

	const int TILE_SIZE = 50;
	const int VERTS_IN_QUAD = 4;
	const int GRAVITY = 300;

	RenderWindow m_Window;

	View m_MainView;
	View m_LeftView;
	View m_RightView;

	View m_BGMainView;
	View m_BGLeftView;
	View m_BGRightView;

	View m_HudView;

	Sprite m_BackgroundSprite;
	Texture m_BackgroundTexture;

	bool m_Playing = false;
	bool m_Character1 = true;
	bool m_SplitScreen = false;
	float m_TimeRemaining = 10;
	Time m_GameTimeTotal;
	bool m_NewLevelRequired = true;

	void input();
	void update(float dtAsSeconds);
	void draw();

public:
	Engine();
	void run();
};