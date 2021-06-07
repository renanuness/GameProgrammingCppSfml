#include "SFML/Graphics.hpp"
#include <iostream>

using namespace sf;

int main()
{
    VideoMode videoMode(1920, 1080);

    RenderWindow window(videoMode, "Teste", Style::Fullscreen);

    RectangleShape rectA(Vector2f(50, 50));
    rectA.setPosition(250, 250);

    RectangleShape rectB(Vector2f(50, 50));
    rectB.setPosition(450, 250);

    Clock clock;

    while (window.isOpen())
    {
        Time dt = clock.restart();

        Event event;

        while (window.pollEvent(event))
        {
            Keyboard::Key keyCode = event.key.code;
            
            if (keyCode == Keyboard::Escape)
                window.close();

            if (keyCode == Keyboard::Left)
                rectA.setPosition(rectA.getPosition().x - 30 * dt.asMilliseconds(), rectA.getPosition().y);

            if (keyCode == Keyboard::Right)
                rectA.setPosition(rectA.getPosition().x + 30 * dt.asMilliseconds(), rectA.getPosition().y );

            if (keyCode == Keyboard::Up)
                rectA.setPosition(rectA.getPosition().x, rectA.getPosition().y - 30 * dt.asMilliseconds());

            if (keyCode == Keyboard::Down)
                rectA.setPosition(rectA.getPosition().x, rectA.getPosition().y + 30 * dt.asMilliseconds());

            //==================================================================
            if (keyCode == Keyboard::A)
                rectB.setPosition(rectB.getPosition().x - 30 * dt.asSeconds(), rectB.getPosition().y);

            if (keyCode == Keyboard::D)
                rectB.setPosition(rectB.getPosition().x + 30 * dt.asSeconds(), rectB.getPosition().y);

            if (keyCode == Keyboard::W)
                rectB.setPosition(rectB.getPosition().x, rectB.getPosition().y - 30 * dt.asSeconds());

            if (keyCode == Keyboard::S)
                rectB.setPosition(rectB.getPosition().x, rectB.getPosition().y + 30 * dt.asSeconds());

        }

        if (rectA.getGlobalBounds().intersects(rectB.getGlobalBounds()))
        {
            rectA.setPosition(50, 250);
            rectB.setPosition(450, 250);
        }
        window.clear();
        
        window.draw(rectA);
        window.draw(rectB);

        window.display();
    }
}
