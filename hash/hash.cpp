#include <iostream>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <Windows.h>
#include <ctime>
#include <cstdlib> 
#include <fstream>

#include "renderWindow.h"
#include "start.h"
#include "aboutauthors.h"
#include "menu.h"
#include "game.h"



using namespace std;
using namespace sf;




int main() {

	HWND hWnd = GetConsoleWindow();
	ShowWindow(hWnd, SW_HIDE);



	system("title THE HASH GAME");

	char new_window_size[200];
	wsprintfA(new_window_size, "mode con cols=%d lines=%d", 40, 10);
	system(new_window_size);
	int CurrentTime = 0;
	srand(time(0));

	CircleShape target;
	target.setPosition(750, 500);
	int radius = 30;
	target.setOrigin(radius, radius);
	target.setRadius(radius);
	Mouse mouse;
	Vector2i mousePos;
	Vector2f targetPos;
	Event Event;
	Texture targetTexture;


	Start();
	menu();


	while (game(mouse, mousePos, targetPos, Event, targetTexture, radius, target)) {

		menu();

	}



}