#include "SFML/Graphics.hpp"
#include <iostream>

using namespace std;

void wIsPressed();
void aIsPressed();
void sIsPressed();
void dIsPressed();
void qIsPressed();

void wIsReleased();
void aIsReleased();
void sIsReleased();
void dIsReleased();
void qIsReleased();


sf::RenderWindow window(sf::VideoMode(1280, 720), "First SFML window");	//This creates a window object and sets the resolution using videoMode
sf::RectangleShape background;
sf::Color backgroundColour;

int main()
{

	//Background setup
	background.setSize({1280, 720});

	//Window setup
	window.setPosition(sf::Vector2i(100, 100));		//Sets the position of the window to 100, 100
	window.setFramerateLimit(60);	//Sets fps limit to 60

	while (window.isOpen())		//While the window is open, the code will loop
	{
		//Poll
		sf::Event event;	//Creating an object called event
		while (window.pollEvent(event))		//This keps the window open
		{
			//Handle colour
			background.setFillColor(backgroundColour);

			//Handle close window
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}

			//Handle Input
			//Key Pressed
			if (event.type == sf::Event::KeyPressed)
			{
				switch (event.key.code)
				{
				case sf::Keyboard::W:	wIsPressed();		break;
				case sf::Keyboard::A:	aIsPressed();		break;
				case sf::Keyboard::S:	sIsPressed();		break;
				case sf::Keyboard::D:	dIsPressed();		break;
				case sf::Keyboard::Q:	qIsPressed();		break;
				default:	break;
				}
			}
			//Key Released
			if (event.type == sf::Event::KeyReleased)
			{
				switch (event.key.code)
				{
				case sf::Keyboard::W:	wIsReleased();		break;
				case sf::Keyboard::A:	aIsReleased();		break;
				case sf::Keyboard::S:	sIsReleased();		break;
				case sf::Keyboard::D:	dIsReleased();		break;
				case sf::Keyboard::Q:	qIsReleased();		break;
				default:	break;
				}
			}
		}
		//Draw background
		window.draw(background);

		//Update
		window.display();
	}

	return 0;
}

//Pressed
void wIsPressed()
{
	cout << "W is pressed" << endl;
	backgroundColour.r = 255;
}
void aIsPressed()
{
	cout << "A is pressed" << endl;
	backgroundColour.g = 255;
}
void sIsPressed()
{
	cout << "S is pressed" << endl;
	backgroundColour.b = 255;
}
void dIsPressed()
{
	cout << "D is pressed" << endl;
	backgroundColour.g = 255;
	backgroundColour.b = 255;
}
void qIsPressed()
{
	cout << "Q is pressed" << endl;
}

//Released
void wIsReleased()
{
	cout << "W is released" << endl;
	backgroundColour.r = 0;
}
void aIsReleased()
{
	cout << "A is released" << endl;
	backgroundColour.g = 0;
}
void sIsReleased()
{
	cout << "S is released" << endl;
	backgroundColour.b = 0;
}
void dIsReleased()
{
	cout << "D is released" << endl;
	backgroundColour.g = 0;
	backgroundColour.b = 0;
}
void qIsReleased()
{
	cout << "Q is released" << endl;
	window.close();
}
