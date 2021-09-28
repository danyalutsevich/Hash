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
	s.setPosition(0, 0);

	Image icon;
	icon.loadFromFile("windowIcon.png");
	window.setIcon(512, 512, icon.getPixelsPtr());

	RectangleShape intro;
	intro.setSize(Vector2f(1920/1.5,1080/1.5));
	intro.setPosition(Vector2f(110,140));
	Texture introTexture;


	while (window.isOpen())
	{
		Event event;
		

		for (int i = 0; i < 300; i++) {

			while (window.pollEvent(event)) {
				if (event.type == Event::Closed) {

					window.close();
					exit(0);

				}
				if (mouse.isButtonPressed(Mouse::Left) || Keyboard::isKeyPressed(Keyboard::Enter) || Keyboard::isKeyPressed(Keyboard::Space)) {
					return 0;

				}

			}

			if (i < 10) {
				introTexture.loadFromFile("frames\\photo_2021-09-03_12-25-5000"+to_string(i)+".jpg");

			}
			else if (i < 100) {
				introTexture.loadFromFile("frames\\photo_2021-09-03_12-25-500" + to_string(i) + ".jpg");

			}
			else if (i < 1000) {
				introTexture.loadFromFile("frames\\photo_2021-09-03_12-25-50" + to_string(i) + ".jpg");

			}
			intro.setTexture(&introTexture, true);
			window.draw(intro);
			window.display();

		}

		

		return 0;

	}
}