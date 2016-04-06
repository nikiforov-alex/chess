#include <SFML/Graphics.hpp>
#include <stdio.h>

using namespace sf;
using namespace std;
const int koef = 75;


Sprite add_figure( string str)
{
	Image *checker_image = new Image();
	Texture *checker_texture = new Texture();
	Sprite *checker_sprite = new Sprite();
	checker_image->loadFromFile(str);
	checker_texture->loadFromImage(*checker_image);
	checker_sprite->setTexture(*checker_texture);
	//checker_sprite->setPosition(x*koef + 25, y*koef + 25);
	return *checker_sprite;
}

int main()
{
	Image figureimage;
	Texture figuretexture;
	Sprite figuresprite;
	
	RenderWindow window(VideoMode(650, 650), "chess");
	RectangleShape WhiteSquare(Vector2f(koef, koef));
	RectangleShape BlackSquare(Vector2f(koef, koef));
	WhiteSquare.setFillColor(sf::Color(222,222,222));
	BlackSquare.setFillColor(sf::Color(41,41,41));

	Sprite blackhorse = add_figure("images/blackhorse.png");
	Sprite blackking = add_figure("images/blackking.png");
	Sprite blackoficer = add_figure("images/blackoficer.png");
	Sprite blackpeshka = add_figure("images/blackpeshka.png");
	Sprite blackqueen = add_figure("images/blackqueen.png");
	Sprite blackslon = add_figure("images/blackslon.png");
	Sprite whitehorse = add_figure("images/whitehorse.png");
	Sprite whiteking = add_figure("images/whiteking.png");
	Sprite whiteoficer = add_figure("images/whiteoficer.png");
	Sprite whitepeshka = add_figure("images/whitepeshka.png");
	Sprite whitequeen = add_figure("images/whitequeen.png");
	Sprite whiteslon = add_figure("images/whiteslon.png");
	Sprite Nill = add_figure("images/Null.png");



	Sprite array [8] [8]
	{
		{ whiteslon, whitehorse, whiteoficer, whiteking, whitequeen, whiteoficer, whitehorse, whiteslon },
		{ whitepeshka, whitepeshka, whitepeshka, whitepeshka, whitepeshka, whitepeshka, whitepeshka, whitepeshka },
		{},
		{},
		{},
		{},
		{ blackpeshka, blackpeshka, blackpeshka, blackpeshka, blackpeshka, blackpeshka, blackpeshka, blackpeshka },
		{ blackslon, blackhorse, blackoficer, blackking, blackqueen, blackoficer, blackhorse, blackslon },
	};

	while (window.isOpen())
	{
		window.setFramerateLimit(48);
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}

		window.clear();
		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				if ((i + j) % 2 == 0)
				{
					WhiteSquare.setPosition(i * koef+25, j * koef+25);
					window.draw(WhiteSquare);
				}
				else
				{
					BlackSquare.setPosition(i * koef+25, j * koef+25);
					window.draw(BlackSquare);
				}
			}
		}
		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				array[j][i].setPosition(i*koef + 25, j*koef + 25);
				window.draw(array[j][i]);
			}
		}
		window.display();
	}

	return 0;
}