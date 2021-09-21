#include <iostream>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <Windows.h>
#include <ctime>
#include <cstdlib> 
#include <fstream>



using namespace std;
using namespace sf;
struct gameStatistic
{
	int quantity;
	double score;
};

int main();
int menu();
int game(Mouse mouse, Vector2i mousePos, Vector2f targetPos, Event& event, Texture targetTexture, int radius, CircleShape target);
int aboutautors();
int afteregame(int score);

RenderWindow window(VideoMode(1500, 1000), "HESH Welcome you!");

int Start() {

	Mouse mouse;
	Texture t1, t2;
	t1.loadFromFile("gl.png");
	t2.loadFromFile("g2.png");
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
				t2.loadFromFile("g2.png");
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

int aboutautors() {
	setlocale(0, "");
	Font font;
	font.loadFromFile("AlumniSans-Bold.ttf");
	Text text("", font, 55);
	RenderWindow window(sf::VideoMode(1500, 1000), "THE HASH. About autors");
	View view(FloatRect(0, 0, 1500, 1000));
	Vector2i localPosition = Mouse::getPosition(window);
	Image i1;
	i1.loadFromFile("i1.png");
	Texture h1;
	h1.loadFromImage(i1);
	Sprite s1;
	s1.setTexture(h1);
	s1.setPosition(50, 25);
	Image i2;
	i2.loadFromFile("i2.png");
	Texture h2;
	h2.loadFromImage(i2);
	Sprite s2;
	s2.setTexture(h2);
	s2.setPosition(1150, 600);

	Image icon;
	icon.loadFromFile("windowIcon.png");
	window.setIcon(512, 512, icon.getPixelsPtr());

	Image i3;
	i3.loadFromFile("i3.png");
	Texture h3;
	h3.loadFromImage(i3);
	Sprite s3;
	s3.setTexture(h3);
	s3.setPosition(50, 1175);

	Image i4;
	i4.loadFromFile("i4.png");
	Texture h4;
	h4.loadFromImage(i4);
	Sprite s4;
	s4.setTexture(h4);
	s4.setPosition(1150, 1750);

	Image i5;
	i5.loadFromFile("i5.png");
	Texture h5;
	h5.loadFromImage(i5);
	Sprite s5;
	s5.setTexture(h5);
	s5.setPosition(50, 2325);



	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
			else if (event.type == Event::MouseWheelMoved)
			{
				if (event.mouseWheel.delta == 1 && view.getCenter().y < 2400) view.move(0, 50);
				if (event.mouseWheel.delta == -1 && view.getCenter().y > 150) view.move(0, -50);
			}
		}
		window.clear();
		window.setView(view);

		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		window.draw(s1);
		window.draw(s2);
		window.draw(s3);
		window.draw(s4);
		window.draw(s5);
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
			main();
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

int afteregame(int score) {
	gameStatistic Old, New;


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