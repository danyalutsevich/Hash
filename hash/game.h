#pragma once

#include <iostream>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <Windows.h>
#include <ctime>
#include <cstdlib> 
#include <fstream>

#include "renderWindow.h"
#include "aftergame.h"


using namespace std;
using namespace sf;

int game(Mouse mouse, Vector2i mousePos, Vector2f targetPos, Event& event, Texture targetTexture, int radius, CircleShape target);


int game(Mouse mouse, Vector2i mousePos, Vector2f targetPos, Event& event, Texture targetTexture, int radius, CircleShape target) {

	int score = 0;
	Font font;
	font.loadFromFile("Nasa.ttf");
	Text text("", font, 25);
	Image run;
	run.loadFromFile("B1.png");
	Texture hrun;
	hrun.loadFromImage(run);
	Sprite srun;
	srun.setTexture(hrun);
	Image run2;
	run2.loadFromFile("run.png");
	Texture hrun2;
	hrun2.loadFromImage(run2);
	Sprite srun2;
	srun2.setTexture(hrun2);
	Image run3;
	run3.loadFromFile("B3.png");
	Texture hrun3;
	hrun3.loadFromImage(run3);
	Sprite srun3;
	srun3.setTexture(hrun3);
	Image run4;
	run4.loadFromFile("B2.png");
	Texture hrun4;
	hrun4.loadFromImage(run4);
	Sprite srun4;
	srun4.setTexture(hrun4);
	int pause = 0;


	Image icon;
	icon.loadFromFile("windowIcon.png");
	window.setIcon(512, 512, icon.getPixelsPtr());

	RectangleShape background;
	Vector2f windowSize;
	windowSize.x = window.getSize().x;
	windowSize.y = window.getSize().y;
	background.setSize(windowSize);

	Texture backGroundTexture;
	backGroundTexture.loadFromFile("background.png");
	background.setTexture(&backGroundTexture);

	Texture gameOverT;
	gameOverT.loadFromFile("gameOver.png");
	RectangleShape gameOver;
	gameOver.setTexture(&gameOverT);
	gameOver.setSize(windowSize);

	SoundBuffer soundBuffer;
	Sound sound;
	soundBuffer.loadFromFile("hash.ogg");
	sound.setBuffer(soundBuffer);

	Sound backgroundSound;
	SoundBuffer backgroundBuffer;

	SoundBuffer deathBuffer;
	deathBuffer.loadFromFile("death.oga");
	Sound death;
	death.setBuffer(deathBuffer);


	backgroundBuffer.loadFromFile("background.ogg");
	backgroundSound.setBuffer(backgroundBuffer);




	srun.setPosition(500, 300);
	srun2.setPosition(550, 375);
	srun3.setPosition(800, 375);
	srun4.setPosition(1375, 25);
	srun4.setScale(0.5, 0.5);
	srun2.setColor(Color::White);
	srun3.setColor(Color::White);
	int CurrentTime = 0;
	srand(time(0));
	target.setPosition(750, 500);
	target.setOrigin(radius, radius);
	target.setRadius(0);
	cout << target.getRadius();
	targetTexture.loadFromFile("target_textures\\texture1.png");
	target.setTexture(&targetTexture, true);

	Clock clock;
	Time time;
	if (mouse.isButtonPressed(Mouse::Left)) {
		mousePos = mouse.getPosition(window);
		cout << "X: " << mousePos.x << "\nY: " << mousePos.y;
	}

	window.draw(target);
	window.display();
	Event event1;
	int menuNum = 0;
	int lives = 3;
	bool mouseMoved = true;
	int counter = 0;

	backgroundSound.play();
	while (window.isOpen() && lives) {
		if (Keyboard::isKeyPressed(Keyboard::X)) {
			window.close();
			Start();
		}

		time = clock.getElapsedTime();

		target.setRadius(time.asSeconds() * 30);
		target.setRotation(time.asSeconds() * 30);
		target.setOrigin(target.getRadius(), target.getRadius());

		text.setPosition(25, 25);
		window.draw(background);
		window.draw(srun4);
		srun4.setColor(Color::White);
		int highScore = 0;

		if (IntRect(1375, 25, 1400, 125).contains(Mouse::getPosition(window))) {
			srun4.setColor(Color::Blue);
			menuNum = 3;
		}

		window.draw(target);

		if (mouse.isButtonPressed(Mouse::Left)) {

			if (menuNum == 3) {
				pause = 1;
			}

			mousePos = mouse.getPosition(window);
			targetPos = target.getPosition();

			if (mousePos.x >= targetPos.x - target.getRadius() && mousePos.x <= targetPos.x + target.getRadius() && mousePos.y >= targetPos.y - target.getRadius() && mousePos.y <= targetPos.y + target.getRadius()) {
				score++;
				cout << score << "\n";
				clock.restart();
				target.setPosition((rand() % 1000) + radius, (rand() % 800) + radius);
				target.setRadius(0);

				window.draw(target);
				sound.play();
				window.display();

			}


		}

		if (target.getRadius() > 50) {

			lives--;
			cout << lives;
			clock.restart();
			target.setPosition((rand() % 1000) + radius, (rand() % 800) + radius);
			target.setRadius(0);
			death.play();
			window.draw(target);
			window.display();

		}

		highScore = afteregame(score);

		text.setString(to_string(score) + " " + to_string(highScore));

		window.draw(text);
		window.display();

		if (Keyboard::isKeyPressed(Keyboard::R)) {
			pause = 1;
		}

		while (pause == 1) {

			window.clear();
			window.draw(srun);
			window.draw(srun2);
			window.draw(srun3);
			window.display();
			srun2.setColor(Color::White);
			srun3.setColor(Color::White);
			if (IntRect(320, 315, 330, 330).contains(Mouse::getPosition(window))) {
				srun2.setColor(Color::Blue);
				menuNum = 1;
			}
			else if (IntRect(600, 375, 620, 400).contains(Mouse::getPosition(window))) {
				srun3.setColor(Color::Blue);
				menuNum = 2;
			}

			if (Mouse::isButtonPressed(Mouse::Left) || Keyboard::isKeyPressed(Keyboard::Enter))
			{
				if (menuNum == 1) {
					pause = 0;
					time = clock.restart();
					break;
				}
				if (menuNum == 2) {



					return 0;
					exit(0);


				}
			}
		}

		while (window.pollEvent(event1)) {
			switch (event1.type) {
			case Event::Closed:

				return 0;
				break;
			case Event::KeyPressed:
				if (event1.key.code == sf::Keyboard::P) {
				}
				if (event1.key.code == sf::Mouse::Left) {

					if (!(mousePos.x >= targetPos.x - target.getRadius() && mousePos.x <= targetPos.x + target.getRadius() && mousePos.y >= targetPos.y - target.getRadius() && mousePos.y <= targetPos.y + target.getRadius())) {



					}

				}
			}

		}
	}

	backgroundSound.stop();
	backgroundBuffer.loadFromFile("lose.ogg");
	backgroundSound.setBuffer(backgroundBuffer);
	backgroundSound.play();
	clock.restart();

	while (time.asSeconds() < 3) {

		time = clock.getElapsedTime();

		window.draw(gameOver);
		window.display();

	}

	backgroundSound.stop();

	return 1;
}

