#pragma once

#include <iostream>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <Windows.h>
#include <ctime>
#include <cstdlib> 
#include <fstream>

#include "renderWindow.h"


using namespace std;
using namespace sf;

int Start();

int Start() {

	Mouse mouse;
	Texture t1, t2;
	t1.loadFromFile("hashLogo\\theHash.png");
	t2.loadFromFile("hashLogo\\hashGameStudio.png");
	Sprite s;
	Sprite s2;
	s.setTexture(t1);
	s.setPosition(470, 150);

	Image icon;
	icon.loadFromFile("windowIcon.png");
	window.setIcon(512, 512, icon.getPixelsPtr());

	window.clear();
	window.draw(s);
	window.display();

	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event)) {
			if (event.type == Event::Closed)
				window.close();

			if (mouse.isButtonPressed(Mouse::Left) || Keyboard::isKeyPressed(Keyboard::Enter) || Keyboard::isKeyPressed(Keyboard::Space)) {
				t2.loadFromFile("hashLogo\\hashGameStudio.png");
				s2.setTexture(t2);
				s2.setPosition(460, 150);
				window.clear();
				window.draw(s2);
				window.display();

				while (window.isOpen())
				{
					while (window.pollEvent(event)) {
						if (event.type == Event::Closed)
							window.close();

						if (mouse.isButtonPressed(Mouse::Left) || Keyboard::isKeyPressed(Keyboard::Enter) || Keyboard::isKeyPressed(Keyboard::Space)) {

							return 0;
						}
					}

				}
			}
		}

	}
}