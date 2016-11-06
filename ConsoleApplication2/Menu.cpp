#include "Menu.h"


Menu::Menu(float width , float height)
{
	colors[0].setFillColor(sf::Color::Red);
	colors[0].setPosition(10, 920);
	colors[0].setSize(sf::Vector2f(30, 30));

	colors[1].setFillColor(sf::Color::Yellow);
	colors[1].setPosition(50, 920);
	colors[1].setSize(sf::Vector2f(30, 30));
	
	colors[2].setFillColor(sf::Color::Blue);
	colors[2].setPosition(90, 920);
	colors[2].setSize(sf::Vector2f(30, 30));

	colors[3].setFillColor(sf::Color::Black);
	colors[3].setPosition(130, 920);
	colors[3].setSize(sf::Vector2f(30, 30));

	colors[4].setFillColor(sf::Color::Magenta);
	colors[4].setPosition(170, 920);
	colors[4].setSize(sf::Vector2f(30, 30));

	submenu.setFillColor(sf::Color::Black);
	submenu.setPosition(210, 920);
	submenu.setSize(sf::Vector2f(170, 30));

	rect.setFillColor(sf::Color::Yellow);
	rect.setPosition(220, 925);
	rect.setSize(sf::Vector2f(20,20));

	triangle.setFillColor(sf::Color::Yellow);
	triangle.setPosition(250, 925);
	triangle.setPointCount(3);
	triangle.setRadius(14);

	circle.setFillColor(sf::Color::Yellow);
	circle.setPosition(290, 925);
	circle.setPointCount(100);
	circle.setRadius(11);

	line.setFillColor(sf::Color::Yellow);
	line.setPosition(340, 925);
	line.setSize(sf::Vector2f(5, 25));
	line.setRotation(45);
	
	pencil.setFillColor(sf::Color::Yellow);
	pencil.setPosition(360, 925);
	pencil.setSize(sf::Vector2f(5, 20));
	
}
bool Menu::isPressed(sf::Event e)
{
	for (int i = 0; i < 5; i++)
	{
		if (colors[i].getGlobalBounds().contains(e.mouseButton.x, e.mouseButton.y))
		{
			return true;
		}
	}
	if (submenu.getGlobalBounds().contains(e.mouseButton.x, e.mouseButton.y))
	{
		return true;
	}
	if (triangle.getGlobalBounds().contains(e.mouseButton.x, e.mouseButton.y))
	{
		return true;
	}
	if (rect.getGlobalBounds().contains(e.mouseButton.x, e.mouseButton.y))
	{
		return true;
	}
	if (circle.getGlobalBounds().contains(e.mouseButton.x, e.mouseButton.y))
	{
		return true;
	}
}

sf::Color Menu::getColor(sf::Event e)
{
	for (int i = 0; i < 5; i++)
	{
		if (colors[i].getGlobalBounds().contains(e.mouseButton.x, e.mouseButton.y))
		{
			return colors[i].getFillColor();
		}
	}
}

int Menu::getState(sf::Event e)
{
	if (triangle.getGlobalBounds().contains(e.mouseButton.x, e.mouseButton.y))
	{
		return TRIANGLE;
	}
	if (rect.getGlobalBounds().contains(e.mouseButton.x, e.mouseButton.y))
	{
		return RECT;
	}
	if (circle.getGlobalBounds().contains(e.mouseButton.x, e.mouseButton.y))
	{
		return CIRCLE;
	}
	if (line.getGlobalBounds().contains(e.mouseButton.x, e.mouseButton.y))
	{
		return LINE;
	}
	if (pencil.getGlobalBounds().contains(e.mouseButton.x, e.mouseButton.y))
	{
		return PENCIL;
	}

}

void Menu::draw(sf::RenderWindow &window)
{
	for (int i = 0; i < 5; i++)
	{
		window.draw(colors[i]);
	}
	window.draw(submenu);
	window.draw(rect);
	window.draw(triangle);
	window.draw(circle);
	window.draw(line);
	window.draw(pencil);
}

Menu::~Menu()
{
}
