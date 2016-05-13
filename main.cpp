#include <SFML/Graphics.hpp>
#include <stdio.h>

using namespace sf;
using namespace std;
const int koef = 75;


Sprite add_figure(string str)
{
	Image *checker_image = new Image();
	Texture *checker_texture = new Texture();
	Sprite *checker_sprite = new Sprite();
	checker_image->loadFromFile(str);
	checker_texture->loadFromImage(*checker_image);
	checker_sprite->setTexture(*checker_texture);
	return *checker_sprite;
}

bool proverka_horse(int y1, int x1, int y2, int x2)
{
	if (((abs(x1 - x2) == 1) && ((abs(y1 - y2)) == 2)) || ((abs(x1 - x2) == 2) && ((abs(y1 - y2)) == 1)))
		return true;
	else
		return false;
}

bool proverka_king(int y1, int x1, int y2, int x2)
{
	if (((abs(x1 - x2) == 0) && ((abs(y1 - y2)) == 1)) || ((abs(x1 - x2) == 1) && ((abs(y1 - y2)) == 0)) || ((abs(x1 - x2) == 1) && ((abs(y1 - y2)) == 1)))
		return true;
	else
		return false;
}

bool proverka_slon(int y1, int x1, int y2, int x2)
{
	if ((abs(y1 - y2) == 0) || (abs(x1 - x2) == 0))
		return true;
	else
		return false;
	
}

bool proverka_oficer(int y1, int x1, int y2, int x2)
{
	if (abs(y1 - y2) == abs(x1 - x2))
		return true;
	else
		return false;
}

bool proverka_queen(int y1, int x1, int y2, int x2)
{
	if ((abs(y1 - y2) == abs(x1 - x2)) || ((abs(y1 - y2) == 0) || (abs(x1 - x2) == 0)))
		return true;
	else
		return false;
}


void Draw_Field(void)
{
	
}

#define ESC 27

int main()
{
	RectangleShape WhiteSquare(Vector2f(koef, koef));
	RectangleShape BlackSquare(Vector2f(koef, koef));
	RenderWindow menu1(VideoMode(650, 650), "menu");
	Sprite menu = add_figure("images/menu.png");
	Sprite newgame = add_figure("images/newgame.png");
	Sprite exitgame = add_figure("images/exit.png");
	int ch = 0;
	while (menu1.isOpen())
	{
		Event event2;
		while (menu1.pollEvent(event2))
		{
			if (event2.type == Event::Closed)
				menu1.close();
		}
		menu1.clear();
		menu1.draw(menu);
		newgame.setPosition(40, 25);
		menu1.draw(newgame);
		exitgame.setPosition(40, 100);
		menu1.draw(exitgame);

			Vector2i mousePos1 = Mouse::getPosition(menu1);
			Event event;
			int x1game = mousePos1.x;
			int y1game = mousePos1.y;
			while (menu1.pollEvent(event))
				if (event.type == Event::MouseButtonPressed)
				{
					if (event.key.code == Mouse::Left)
					{
						if (x1game > 40 && x1game < 240 && y1game >25 && y1game < 80)
						{
							menu1.close();
							ch++;
						}
						if (x1game > 40 && x1game < 160 && y1game >100 && y1game < 150)
						{
							exit;
							menu1.close();
						}
					}
				}
		menu1.display();
	}

	RenderWindow window(VideoMode(650, 650), "chess");
	WhiteSquare.setFillColor(sf::Color(222, 222, 222));
	BlackSquare.setFillColor(sf::Color(41, 41, 41));

	int numbersClick = 1, schyot, xk, yk;
	int x1 = 0, x2 = 0, y1 = 0, y2 = 0, chblack = 0, chwhite = 0;
	int x1q = 0, x2q = 0, y1q = 0, y2q = 0;
	bool prov;
	int posBKX, posWKX, posBKY, posWKY;

	Sprite sblackhorse = add_figure("images/blackhorse.png");
	Sprite sblackking = add_figure("images/blackqueen.png");
	Sprite sblackoficer = add_figure("images/blackoficer.png");
	Sprite sblackpeshka = add_figure("images/blackpeshka.png");
	Sprite sblackqueen = add_figure("images/blackking.png");
	Sprite sblackslon = add_figure("images/blackslon.png");
	Sprite swhitehorse = add_figure("images/whitehorse.png");
	Sprite swhiteking = add_figure("images/whitequeen.png");
	Sprite swhiteoficer = add_figure("images/whiteoficer.png");
	Sprite swhitepeshka = add_figure("images/whitepeshka.png");
	Sprite swhitequeen = add_figure("images/whiteking.png");
	Sprite swhiteslon = add_figure("images/whiteslon.png");
	Sprite sNill = add_figure("images/Null.png");
	Sprite BlackWin = add_figure("images/winblack.png");
	Sprite WhiteWin = add_figure("images/winwhite.png");
	Sprite fon = add_figure("images/fon.png");
	BlackWin.setPosition(0, 0);
	WhiteWin.setPosition(0, 0);
	fon.setPosition(0, 0);


	pair<String, String> pBlackhorse("blackhorse", "Black");
	pair<String, String> pBlackking("blackking", "Black");
	pair<String, String> pBlackoficer("blackoficer", "Black");
	pair<String, String> pBlackpeshka("blackpeshka", "Black");
	pair<String, String> pBlackqueen("blackqueen", "Black");
	pair<String, String> pBlackslon("blackslon", "Black");
	pair<String, String> pWhitehorse("whitehorse", "White");
	pair<String, String> pWhiteking("Whiteking", "White");
	pair<String, String> pWhiteoficer("Whiteoficer", "White");
	pair<String, String> pWhitepeshka("Whitepeshka", "White");
	pair<String, String> pWhitequeen("Whitequeen", "White");
	pair<String, String> pWhiteslon("Whiteslon", "White");
	pair<String, String> pNill("Nilll", "None");


	pair<Sprite, pair<String, String>> blackhorse(sblackhorse, pBlackhorse);
	pair<Sprite, pair<String, String>> blackking(sblackking, pBlackking);
	pair<Sprite, pair<String, String>> blackoficer(sblackoficer, pBlackoficer);
	pair<Sprite, pair<String, String>> blackpeshka(sblackpeshka, pBlackpeshka);
	pair<Sprite, pair<String, String>> blackqueen(sblackqueen, pBlackqueen);
	pair<Sprite, pair<String, String>> blackslon(sblackslon, pBlackslon);
	pair<Sprite, pair<String, String>> whitehorse(swhitehorse, pWhitehorse);
	pair<Sprite, pair<String, String>> whiteking(swhiteking, pWhiteking);
	pair<Sprite, pair<String, String>> whiteoficer(swhiteoficer, pWhiteoficer);
	pair<Sprite, pair<String, String>> whitepeshka(swhitepeshka, pWhitepeshka);
	pair<Sprite, pair<String, String>> whitequeen(swhitequeen, pWhitequeen);
	pair<Sprite, pair<String, String>> whiteslon(swhiteslon, pWhiteslon);
	pair<Sprite, pair<String, String>> Nill(sNill, pNill);
	
	newgame:
	pair<Sprite, pair<String, String>> arrays[8][8]
	{
		{ whiteslon, whitehorse, whiteoficer, whiteking, whitequeen, whiteoficer, whitehorse, whiteslon },
		{ whitepeshka, whitepeshka, whitepeshka, whitepeshka, whitepeshka, whitepeshka, whitepeshka, whitepeshka },
		{ Nill, Nill, Nill, Nill, Nill, Nill, Nill, Nill },
		{ Nill, Nill, Nill, Nill, Nill, Nill, Nill, Nill },
		{ Nill, Nill, Nill, Nill, Nill, Nill, Nill, Nill },
		{ Nill, Nill, Nill, Nill, Nill, Nill, Nill, Nill },
		{ blackpeshka, blackpeshka, blackpeshka, blackpeshka, blackpeshka, blackpeshka, blackpeshka, blackpeshka },
		{ blackslon, blackhorse, blackoficer, blackking, blackqueen, blackoficer, blackhorse, blackslon },
	};

	if (ch > 0 )
		Continue:
	while (window.isOpen())
	{
		Vector2i mousePos1 = Mouse::getPosition(window);
		window.setFramerateLimit(24);

		

		window.clear();
		window.draw(fon);
		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				if ((i + j) % 2 == 0)
				{
					WhiteSquare.setPosition(i * koef + 25, j * koef + 25);
					window.draw(WhiteSquare);
				}
				else
				{
					BlackSquare.setPosition(i * koef + 25, j * koef + 25);
					window.draw(BlackSquare);
				}
			}
		}

		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				arrays[j][i].first.setPosition(i*koef + 25, j*koef + 25);
				window.draw(arrays[j][i].first);
			}
		}
		Event event;

		while (window.pollEvent(event))
			if (event.type == Event::MouseButtonPressed)
			{
				if (mousePos1.x > 25 && mousePos1.x < 625 && mousePos1.y < 625 && mousePos1.y>25)
				{
					if (numbersClick % 2 == 1)
					{
						x1 = mousePos1.x;
						y1 = mousePos1.y;
					}
					else
					{
						x2 = mousePos1.x;
						y2 = mousePos1.y;
					}
					x1q = (x1 - 25) / 75;
					y1q = (y1 - 25) / 75;
					x2q = (x2 - 25) / 75;
					y2q = (y2 - 25) / 75;
				}
				if (((arrays[y1q][x1q].second.first != Nill.second.first) && (arrays[y1q][x1q].second.second == "White") && ((numbersClick % 4 == 1)||(numbersClick % 4 ==2))) || ((arrays[y1q][x1q].second.first != Nill.second.first) && (arrays[y1q][x1q].second.second == "Black") && ((numbersClick % 4 == 3)||(numbersClick % 4 ==0))))
				{
					arrays[y1q][x1q].first.setColor(Color::Yellow);
					
					if (event.key.code == Mouse::Left)
					{
						if (numbersClick % 2 == 0)
						{
							if (arrays[y1q][x1q].second.second == arrays[y2q][x2q].second.second)
							{
								x1 = x2;
								y1 = y2;
								arrays[y1q][x1q].first.setColor(Color::White);
								arrays[y2q][x2q].first.setColor(Color::Yellow);

								numbersClick--;
							}
							else
							{
								posBKX = 0;
								posBKY = 0;
								posWKX = 0; 
								posWKY = 0;
								for (int i = 0; i < 8; i++)
								{
									for (int j = 0; j < 8; j++)
									{
										if (arrays[i][j].second.first == "Whiteking")
										{
											posWKY = i;
											posWKX = j;
										}
										if (arrays[i][j].second.first == "blackking")	
										{
											posBKY = i;
											posBKX = j;
										}
									}
								}

								prov = false;
								if ((proverka_king(y1q, x1q, y2q, x2q) == true) && ((arrays[y1q][x1q].second.first == "Whiteking") || (arrays[y1q][x1q].second.first == "blackking")))
								{
									prov = true;
								}
								if ((proverka_horse(y1q, x1q, y2q, x2q) == true) && ((arrays[y1q][x1q].second.first == "whitehorse")||(arrays[y1q][x1q].second.first == "blackhorse")))
								{			
									prov = true;
								}
								if ((proverka_slon(y1q, x1q, y2q, x2q) == true) && ((arrays[y1q][x1q].second.first == "Whiteslon") || (arrays[y1q][x1q].second.first == "blackslon")))
								{
									prov = true;
									xk = x1q;
									yk = y1q;
									while ((xk != (x2q)) || (yk != (y2q)))
									{
										xk += (xk<x2q) ? 1 : ((xk>x2q) ? -1 : 0);
										yk += (yk<y2q) ? 1 : ((yk>y2q) ? -1 : 0);
										if ((arrays[y2q][x2q].second.first != arrays[yk][xk].second.first) && (arrays[yk][xk].second.first != "Nilll"))
										{
											prov = false;
										}
									}
								}
								if ((proverka_oficer(y1q, x1q, y2q, x2q) == true) && ((arrays[y1q][x1q].second.first == "Whiteoficer") || (arrays[y1q][x1q].second.first == "blackoficer")))
								{
									prov = true;
									xk = x1q;
									yk = y1q;
									while ((xk != (x2q)) || (yk != (y2q)))
									{
										xk += (xk<x2q) ? 1 : ((xk>x2q) ? -1 : 0);
										yk += (yk<y2q) ? 1 : ((yk>y2q) ? -1 : 0);
										if ((arrays[y2q][x2q].second.first != arrays[yk][xk].second.first) && (arrays[yk][xk].second.first != "Nilll"))
										{
											prov = false;
										}
									}
								}
								if ((proverka_queen(y1q, x1q, y2q, x2q) == true) && ((arrays[y1q][x1q].second.first == "Whitequeen") || (arrays[y1q][x1q].second.first == "blackqueen")))
								{
									prov = true;
									xk = x1q;
									yk = y1q;
									while ((xk != (x2q)) || (yk != (y2q)))
									{
										xk += (xk<x2q) ? 1 : ((xk>x2q) ? -1 : 0);
										yk += (yk<y2q) ? 1 : ((yk>y2q) ? -1 : 0);
										if ((arrays[y2q][x2q].second.first != arrays[yk][xk].second.first) && (arrays[yk][xk].second.first != "Nilll"))
										{
											prov = false;
										}
									}
								}
								if (arrays[y1q][x1q].second.first == "Whitepeshka")
								{
									if ((y2q == 1 + y1q) && (x2q == x1q) && (arrays[y2q][x2q].second.first == "Nilll"))
									{
										prov = true;
									}
									if ((y2q == 1 + y1q) && (((x2q + 1) == x1q) || ((x2q - 1) == x1q)) && (arrays[y2q][x2q].second.second == "Black"))
									{
										prov = true;
									}
									if (y1q == 1)
									{
										if ((y2q == 2 + y1q) && (x2q == x1q) && (arrays[y2q][x2q].second.first == "Nilll") && (arrays[y2q - 1][x2q].second.first == "Nilll"))
										{
											prov = true;
										}
									}
									if ((y2q == 7) && (prov == true))
									{
										arrays[y1q][x1q] = whitequeen;
									}
								}
								if (arrays[y1q][x1q].second.first == "blackpeshka")
								{
									if ((1+y2q == y1q) && (x2q == x1q) && (arrays[y2q][x2q].second.first == "Nilll"))
									{
										prov = true;
									}
									if ((1+y2q == y1q) && (((x2q + 1) == x1q) || ((x2q - 1) == x1q)) && (arrays[y2q][x2q].second.second == "White"))
									{
										prov = true;
									}
									if (y1q == 6)
									{
										if ((y2q + 2 == y1q) && (x2q == x1q) && (arrays[y2q][x2q].second.first == "Nilll") && (arrays[y2q+1][x2q].second.first == "Nilll"))
										{
											prov = true;
										}
									}
									if ((y2q == 0) && (prov == true))
									{
										arrays[y1q][x1q] = blackqueen;
									}
								}

								if ((arrays[y2q][x2q].second.first == blackking.second.first) && (prov == true))
								{
									chblack = 1;
								}
								if ((arrays[y2q][x2q].second.first == whiteking.second.first) && (prov == true))
								{
									chwhite = 1;
								}
								
								if (prov == true)
								{
									pair<Sprite, pair<String, String>> loll = arrays[y1q][x1q];
									arrays[y1q][x1q] = Nill;
									arrays[y2q][x2q] = loll;
									arrays[y2q][x2q].first.setColor(Color::White);
								}
								else
								{
									numbersClick--;
								}
							}
							for (int i = 0; i < 8; i++)
							{
								for (int j = 0; j < 8; j++)
								{
									arrays[j][i].first.setPosition(i*koef + 25, j*koef + 25);
									window.draw(arrays[i][j].first);
								}
							}


						}
						if (chblack == 1)
						{
							window.close();
						}
						if (chwhite == 1)
						{
							window.close();
						}
					}
					printf("%d %d %d %d %d\n", mousePos1.x, mousePos1.y, numbersClick, chblack, chwhite);
					numbersClick++;
				}
			}
		
			if (event.type == Event::Closed)
				window.close();
		window.display();
	}
	if ((chblack == 1) || (chwhite == 1))
	{
		RenderWindow window1(VideoMode(650, 650), "Win");
		while (window1.isOpen())
		{
			Event event1;
			while (window1.pollEvent(event1))
			{
				if (event1.type == Event::Closed)
					window1.close();
			}

			window1.clear();
			if (chwhite == 1)
				window1.draw(BlackWin);
			if (chblack == 1)
				window1.draw(WhiteWin);
			window1.display();
		}
	}
	return 0;
}
