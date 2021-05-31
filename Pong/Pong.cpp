#include "Bat.h"
#include "Ball.h"
#include <sstream>
#include <cstdlib>
#include <SFML/Graphics.hpp>

const int SCREEN_HEIGHT = 768;
const int SCREEN_WIDTH = 1366;

int main()
{
	VideoMode videoMode(SCREEN_WIDTH, SCREEN_HEIGHT);

	RenderWindow window(videoMode, "Pong", Style::Fullscreen);

	int score = 0;
	int lives = 3;

	Bat bat(SCREEN_WIDTH / 2, SCREEN_HEIGHT - 20);

	Ball ball(SCREEN_WIDTH / 2, 0);

	Text hud;

	Font font;
	font.loadFromFile("fonts/DS-DIGIT.ttf");

	hud.setFont(font);
	hud.setCharacterSize(75);

	hud.setFillColor(Color::White);
	hud.setPosition(20, 20);
	
	Clock clock;

	while (window.isOpen())
	{
		Event event;

		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}

		if (Keyboard::isKeyPressed(Keyboard::Escape))
			window.close();

		if (Keyboard::isKeyPressed(Keyboard::Left))
			bat.moveLeft();
		else
			bat.stopLeft();

		if (Keyboard::isKeyPressed(Keyboard::Right))
			bat.moveRight();
		else
			bat.stopRight();

		Time dt = clock.restart();

		bat.update(dt);
		ball.update(dt);

		std::stringstream ss;

		ss << "Score: " << score << " Lives: " << lives;
		hud.setString(ss.str());

		if (ball.getPosition().top > window.getSize().y)
		{
			ball.reboundBottom();
			lives--;
			if (lives < 1)
			{
				score = 0;
				lives = 3;
			}
		}

		if (ball.getPosition().top < 0)
		{
			ball.reboundBatOrTop();
			score++;
		}

		if (ball.getPosition().left < 0 ||
			ball.getPosition().left + ball.getPosition().width> window.getSize().x)
		{
			ball.reboundSides();
		}

		if (ball.getPosition().intersects(bat.getPosition()))
		{
			// Hit detected so reverse the ball and score a point
			ball.reboundBatOrTop();
		}

		window.clear();

		window.draw(hud);
		window.draw(bat.getShape());
		window.draw(ball.getShape());

		window.display();
	}

	return 0;
}