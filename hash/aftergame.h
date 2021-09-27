#pragma once

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

int afteregame(int score);


int afteregame(int score) {
	


	ifstream statsread("stats.txt");

	string line;

	getline(statsread, line);

	int num = atoi(line.c_str());

	if (num < score) {
		ofstream stats;
		stats.open("stats.txt");

		stats << to_string(score).c_str();
		stats.close();
	}

	return num;
}
