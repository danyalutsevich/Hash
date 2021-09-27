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

int menu();

int menu() {
	Texture menuTexture1, menuTexture2, menuTexture3;
	menuTexture1.loadFromFile("12.png");
	menuTexture2.loadFromFile("11.png");
	menuTexture3.loadFromFile("13.png");
	Sprite menu1(menuTexture1), menu2(menuTexture2), menu3(menuTexture3);
	bool isMenu = 1;
	int menuNumKeyboard = 0;
	int menuNum = 0;
	menu1.setPosition(450, 350);
	menu2.setPosition(550, 540);
	menu3.setPosition(620, 650);

	Image icon;
	icon.loadFromFile("windowIcon.png");
	window.setIcon(512, 512, icon.getPixelsPtr());

	Sound button;
	SoundBuffer sound;

	sound.loadFromFile("button.ogg");

	button.setBuffer(sound);

	button.setPitch(405);
	button.setVolume(100);

	bool playSound = false;

	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event)) {

			if (event.type == Event::Closed)
				window.close();

		}
		menu1.setColor(Color::White);
		menu2.setColor(Color::White);
		menu3.setColor(Color::White);
		menuNum = 0;
		window.clear();

		playSound = false;

		if (Keyboard::isKeyPressed(Keyboard::Down) && menuNumKeyboard < 3 && menuNumKeyboard >= 0 || Keyboard::isKeyPressed(Keyboard::Right) && menuNumKeyboard < 3 && menuNumKeyboard >= 0) {
			menuNumKeyboard++;

		}
		else if (Keyboard::isKeyPressed(Keyboard::Down) && menuNumKeyboard == 3 || Keyboard::isKeyPressed(Keyboard::Right) && menuNumKeyboard == 3) {
			menuNumKeyboard = 1;

		}
		else if (Keyboard::isKeyPressed(Keyboard::Up) && menuNumKeyboard > 0 || Keyboard::isKeyPressed(Keyboard::Left) && menuNumKeyboard > 0) {
			menuNumKeyboard--;

		}
		else if (Keyboard::isKeyPressed(Keyboard::Up) && menuNumKeyboard == 1 || Keyboard::isKeyPressed(Keyboard::Left) && menuNumKeyboard == 1) {
			menuNumKeyboard = 3;

		}
		else if (Keyboard::isKeyPressed(Keyboard::Up) && menuNumKeyboard == 0 || Keyboard::isKeyPressed(Keyboard::Left) && menuNumKeyboard == 0) {
			menuNumKeyboard = 3;

		}

		if (IntRect(450, 350, 570, 190).contains(Mouse::getPosition(window))) {
			menu1.setColor(Color::Blue); menuNum = 1;
			playSound = true;

		}
		else if (IntRect(550, 540, 400, 50).contains(Mouse::getPosition(window))) {
			menu2.setColor(Color::Blue); menuNum = 2;
			playSound = true;
		}
		else if (IntRect(620, 650, 250, 50).contains(Mouse::getPosition(window))) {
			menu3.setColor(Color::Blue); menuNum = 3;
			playSound = true;
		}
		else if (menuNumKeyboard == 1) {
			menu1.setColor(Color::Blue); menuNum = 1;
			playSound = true;
		}
		else if (menuNumKeyboard == 2) {
			menu2.setColor(Color::Blue); menuNum = 2;
			playSound = true;
		}
		else if (menuNumKeyboard == 3) {
			menu3.setColor(Color::Blue); menuNum = 3;
			playSound = true;
		}

		if (playSound) {

			button.play();

			playSound = false;

		}

		if (Mouse::isButtonPressed(Mouse::Left) || Keyboard::isKeyPressed(Keyboard::Enter))
		{
			if (menuNum == 1) {

				return 0;
			}
			if (menuNum == 2) { aboutautors(); }
			if (menuNum == 3) {
				window.close();
				system("pause");
			}
		}
		if (Mouse::isButtonPressed(Mouse::Left))
		{
			if (menuNum == 1) {

				return 0;
			}
			if (menuNum == 2) { aboutautors(); }
			if (menuNum == 3) {
				window.close();
				system("pause");
			}
		}
		window.draw(menu1);
		window.draw(menu2);
		window.draw(menu3);
		window.display();
	}
	return 0;
}