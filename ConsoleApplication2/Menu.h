#pragma once
#include "SFML/Graphics.hpp"
class Menu
{
public:
	void draw(sf::RenderWindow &window);
	bool isPressed(sf::Event e);
	int getState(sf::Event e);
	sf::Color getColor(sf::Event e);
	Menu(float width, float height);
	~Menu();

private:
	sf::Sprite menu[7];
	sf::RectangleShape colors[5];
	sf::RectangleShape submenu;
	sf::RectangleShape rect, line,pencil;
	sf::CircleShape triangle, circle;
	enum states { PENCIL, RECT, TRIANGLE, CIRCLE, LINE };
};

