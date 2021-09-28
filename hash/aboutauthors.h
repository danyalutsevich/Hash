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

int aboutautors();

int aboutautors() {
	setlocale(0, "");
	Font font;
	font.loadFromFile("AlumniSans-Bold.ttf");
	Text text("", font, 55);

	View view(FloatRect(0, 0, 1500, 1000));
	Vector2i localPosition = Mouse::getPosition(window);
	Image i1;
	i1.loadFromFile("aboutauthors\\vladAboutAuthors.png");
	Texture h1;
	h1.loadFromImage(i1);
	Sprite s1;
	s1.setTexture(h1);
	s1.setPosition(50, 25);
	Image i2;
	i2.loadFromFile("aboutauthors\\anyaAboutAuthors.png");
	Texture h2;
	h2.loadFromImage(i2);
	Sprite s2;
	s2.setTexture(h2);
	s2.setPosition(1150, 600);

	Image icon;
	icon.loadFromFile("windowIcon.png");
	window.setIcon(512, 512, icon.getPixelsPtr());

	Image i3;
	i3.loadFromFile("aboutauthors\\katyaAboutAuthors.png");
	Texture h3;
	h3.loadFromImage(i3);
	Sprite s3;
	s3.setTexture(h3);
	s3.setPosition(50, 1175);

	Image i4;
	i4.loadFromFile("aboutauthors\\nazarAboutAuthors.png");
	Texture h4;
	h4.loadFromImage(i4);
	Sprite s4;
	s4.setTexture(h4);
	s4.setPosition(1150, 1750);

	//Image i5;
	//i5.loadFromFile("aboutauthors\\danyaAboutAuthors.png");


	RectangleShape danyasHead;
	danyasHead.setSize(Vector2f(350,350));

	Texture headTexture;
	//h5.loadFromfile(i5);
	danyasHead.setPosition(50, 2325);

	/*Sprite s5;
	s5.setTexture(h5);
	s5.setPosition(50, 2325);*/
	

	int i = 0;


	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed) {

				window.close();
				exit(0);
			}
			else if (event.type == Event::MouseWheelMoved)
			{
				if (event.mouseWheel.delta == 1 && view.getCenter().y < 2400) view.move(0, 50);
				if (event.mouseWheel.delta == -1 && view.getCenter().y > 150) view.move(0, -50);
			}
		}
		window.clear();
		window.setView(view);

		

		window.draw(s1);
		window.draw(s2);
		window.draw(s3);
		window.draw(s4);

		//for (int i = 0; i <= 300; i++) {

			if (i < 10) {

				headTexture.loadFromFile("head\\000"+to_string(i)+".jpg");
				//s5.setTexture(h5);

			}
			else if (i < 100) {
				
				headTexture.loadFromFile("head\\00" + to_string(i) + ".jpg");
			//	s5.setTexture(h5);

			}
			else if (i < 1000) {

				headTexture.loadFromFile("head\\0" + to_string(i) + ".jpg");
				//s5.setTexture(h5);
			}

			danyasHead.setTexture(&headTexture,true);
			window.draw(danyasHead);

		//	window.display();

			i++;
			if (i > 300) {
				i = 0;
			}

		//}

		text.setString(L"Владислав Величко, он же Валериан Дейкун, он же \nМаграм Байков,он же Раиса Трансовая — глава ритуальной \nконторы, автор бренда и немного дизайнер. \nНу а что? Конторка то молодая! Именно благодаря \nопечатке этого человека появилось слово «ХЭЩ». ");
		text.setPosition(400, 25);
		window.draw(text);
		text.setString(L"Анна Червоная, она же Анна Рэд. Работала по \nхозяйственной части. Проверяла подушки на мягкость, \nгробы на целость, оркестр на трезвость. Что-то \nкооперировала, что-то сегрегировала. Сейчас занимается \nархитектурой: то есть все так же кооперирует и \nсегрегирует.");
		text.setPosition(50, 600);
		window.draw(text);
		text.setString(L"Катя Олейник, она же Котейка, она же матриарх\nритуальной конторы — тот самый мазохист, который \nбудет сотни раз запускать нашу программу и выискивать \nв ней баги. ");
		text.setPosition(400, 1175);
		window.draw(text);
		text.setString(L"Назар Стефанов, он же Dufrayn — дирижёр похоронного \nаркестра, отвечает за все звуки которые издаёт \nкомпьютер во время игры(кроме звуков работы системы \nохлаждения, разумеется). ");
		text.setPosition(50, 1750);
		window.draw(text);
		text.setString(L"Данил Луцевич — человек, описывать которого словами \nневозможно, генератор самых странных идей и не менее \nэкзотичных реализаций наших крайне амбициозных \nзадумок. В нашей конторке он в основном программист.");
		text.setPosition(400, 2375);
		window.draw(text);
		text.setString(L"Мы — ХЭЩ-жрицы, ритуальная контора, которая в связи с тяжелыми\nфинансовым и моральным кризисом решила сменить род своей \nдеятельности. И так мы стали IT-компанией. ");
		text.setPosition(50, -275);
		window.draw(text);
		window.display();
	}

	return 0;
}