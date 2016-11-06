#include <SFML/Graphics.hpp>
#include <vector>
#include "Menu.h"

float window_width = 1280;
float window_height = 960;

enum states {PENCIL=0, RECT=1, TRIANGLE=2, CIRCLE=3, LINE=4};

sf::Color selected_color = sf::Color::White;

bool mouseButtonDown;

int main()
{
	states state = RECT;
	states last_state = RECT;
	sf::RenderWindow window(sf::VideoMode(window_width, window_height), "SFML works!");
	
	sf::RectangleShape menu;
	menu.setFillColor(sf::Color::Green);
	menu.setSize(sf::Vector2f(window_width, window_height - 910));
	menu.setPosition(sf::Vector2f(0, window_height - 50));

	Menu menu1(menu.getSize().x,menu.getSize().y);

	sf::VertexArray lines;
	lines.setPrimitiveType(sf::Lines);

	sf::VertexArray lines11(sf::PrimitiveType::LinesStrip, 2);

	sf::RectangleShape rect;
	sf::CircleShape triangle;
	sf::CircleShape circle;

	std::vector<sf::RectangleShape> rects;
	std::vector<sf::CircleShape> triangles;
	std::vector<sf::CircleShape> circles;
	std::vector<sf::VertexArray> lines1;
	

	sf::Vector2f lastPosition;

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.y > 910)
			{
				if (event.mouseButton.button == sf::Mouse::Left && menu1.isPressed(event))
				{
					if (event.mouseButton.x < 200){
						selected_color = menu1.getColor(event);
					}
					if (event.mouseButton.x > 210){
						state = (states)menu1.getState(event);
					}
				}
			}
			if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.y < 910)
			{
				if (event.mouseButton.button == sf::Mouse::Left && state == PENCIL)
				{
					mouseButtonDown = true;
					lastPosition = sf::Vector2f(event.mouseButton.x, event.mouseButton.y);
				}
				if (event.mouseButton.button == sf::Mouse::Left && state == RECT)
				{
					mouseButtonDown = true;
					lastPosition = sf::Vector2f(event.mouseButton.x, event.mouseButton.y);
				}
				if (event.mouseButton.button == sf::Mouse::Left && state == TRIANGLE)
				{
					mouseButtonDown = true;
					lastPosition = sf::Vector2f(event.mouseButton.x, event.mouseButton.y);
				}
				if (event.mouseButton.button == sf::Mouse::Left && state == CIRCLE)
				{
					mouseButtonDown = true;
					lastPosition = sf::Vector2f(event.mouseButton.x, event.mouseButton.y);
				}
				if (event.mouseButton.button == sf::Mouse::Left && state == LINE)
				{
					mouseButtonDown = true;
					lastPosition = sf::Vector2f(event.mouseButton.x, event.mouseButton.y);
				}
			}
			if (event.type == sf::Event::MouseButtonReleased)
			{
				if (event.mouseButton.button == sf::Mouse::Left && state == PENCIL)
				{
					mouseButtonDown = false;
				}
				if (event.mouseButton.button == sf::Mouse::Left && state == RECT)
				{
					mouseButtonDown = false;
					rects.push_back(rect);
				}
				if (event.mouseButton.button == sf::Mouse::Left && state == TRIANGLE)
				{
					mouseButtonDown = false;
					triangles.push_back(triangle);
				}
				if (event.mouseButton.button == sf::Mouse::Left && state == CIRCLE)
				{
					mouseButtonDown = false;
					circles.push_back(circle);
				}
				if (event.mouseButton.button == sf::Mouse::Left && state == LINE)
				{
					mouseButtonDown = false;
					lines1.push_back(lines11);
				}
			}
			if (event.type == sf::Event::MouseMoved && event.mouseButton.y < 910)
			{
				if (state == PENCIL)
				{
					if (mouseButtonDown)
					{
						lines.append(sf::Vertex(lastPosition, selected_color));
						lastPosition = sf::Vector2f(event.mouseMove.x, event.mouseMove.y);
						lines.append(sf::Vertex(lastPosition, selected_color));
						last_state = PENCIL;
					}
				}
				if (state == RECT)
				{
					if (mouseButtonDown)
					{
						rect.setPosition(lastPosition);
						rect.setFillColor(selected_color);
						rect.setSize(sf::Vector2f(sf::Mouse::getPosition(window))-sf::Vector2f(lastPosition));
						last_state = RECT;
					}
				}
				if (state == TRIANGLE)
				{
					if (mouseButtonDown)
					{
						triangle.setPosition(lastPosition);
						triangle.setPointCount(3);
						triangle.setFillColor(selected_color);
						triangle.setRadius((sf::Vector2f(sf::Mouse::getPosition(window)).x-lastPosition.x)/2);
						last_state = TRIANGLE;
					}
				}
				if (state == CIRCLE)
				{
					if (mouseButtonDown)
					{
						circle.setPosition(lastPosition);
						circle.setPointCount(100);
						circle.setFillColor(selected_color);
						circle.setRadius((sf::Vector2f(sf::Mouse::getPosition(window)).x - lastPosition.x));
						circle.setOrigin(circle.getRadius(),circle.getRadius());
						last_state = CIRCLE;
					}
				}
				if (state == LINE)
				{
					if (mouseButtonDown)
					{
						lines11[0].position = lastPosition;
						lines11[0].color = selected_color;
						lines11[1].position = sf::Vector2f(sf::Mouse::getPosition(window));
						lines11[1].color = selected_color;
						last_state = LINE;
					}
				}
			}
			if (event.type == sf::Event::Closed)
				window.close();
		}
		window.clear();
		switch (last_state)
		{
		case PENCIL:
			for (const auto& r : rects){
				window.draw(r);
			}
			window.draw(rect);
			for (const auto& c : circles){
				window.draw(c);
			}
			window.draw(circle);
			for (const auto& t : triangles){
				window.draw(t);
			}
			window.draw(triangle);
			for (const auto& l : lines1){
				window.draw(l);
			}
			window.draw(lines11);
			window.draw(lines);
			window.draw(menu);
			menu1.draw(window);
			break;
		case RECT:
			for (const auto& c : circles){
				window.draw(c);
			}
			window.draw(circle);
			for (const auto& t : triangles){
				window.draw(t);
			}
			window.draw(triangle);
			for (const auto& l : lines1){
				window.draw(l);
			}
			window.draw(lines11);
			window.draw(lines);
			for (const auto& r : rects){
				window.draw(r);
			}
			window.draw(rect);
			window.draw(menu);
			menu1.draw(window);
			break;
		case TRIANGLE:
			for (const auto& c : circles){
				window.draw(c);
			}
			window.draw(circle);
			for (const auto& l : lines1){
				window.draw(l);
			}
			window.draw(lines11);
			window.draw(lines);
			for (const auto& r : rects){
				window.draw(r);
			}
			window.draw(rect);
			for (const auto& t : triangles){
				window.draw(t);
			}
			window.draw(triangle);
			window.draw(menu);
			menu1.draw(window);
			break;
		case CIRCLE:
			for (const auto& l : lines1){
				window.draw(l);
			}
			window.draw(lines11);
			window.draw(lines);
			for (const auto& r : rects){
				window.draw(r);
			}
			window.draw(rect);
			for (const auto& t : triangles){
				window.draw(t);
			}
			window.draw(triangle);
			for (const auto& c : circles){
				window.draw(c);
			}
			window.draw(circle);
			window.draw(menu);
			menu1.draw(window);
			break;
		case LINE:
			for (const auto& r : rects){
				window.draw(r);
			}
			window.draw(rect);
			for (const auto& t : triangles){
				window.draw(t);
			}
			window.draw(triangle);
			for (const auto& c : circles){
				window.draw(c);
			}
			window.draw(circle);
			for (const auto& l : lines1){
				window.draw(l);
			}
			window.draw(lines11);
			window.draw(lines);
			window.draw(menu);
			menu1.draw(window);
			break;
		default:
			break;
		}
		window.display();
	}

	return 0;
}