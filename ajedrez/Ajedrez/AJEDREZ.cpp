#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
using namespace sf;

Texture texture_b;
Texture texture_w;
Sprite sprite_b;
Sprite sprite_w;

int main() {

	texture_b.loadFromFile("chessb.png");
	texture_w.loadFromFile("chessw.png");

	sprite_b.setTexture(texture_b);
	sprite_w.setTexture(texture_w);

	sf::RenderWindow window(sf::VideoMode(800, 800), "Ajedrez");

	const int tamaño = 100;

	sf::RectangleShape cuadros[8][8];

	for (int i = 0; i < 8; ++i) {
		for (int j = 0; j < 8; ++j) {
			cuadros[i][j].setSize(sf::Vector2f(tamaño, tamaño));
			cuadros[i][j].setPosition(i * tamaño, j * tamaño);

			if ((i + j) % 2 == 0) {
				cuadros[i][j].setTexture(&texture_w);
			}
			else {
				cuadros[i][j].setTexture(&texture_b);
			}
		}
	}

	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed)
				window.close();
		}
		window.clear();

		for (int i = 0; i < 8; ++i) {
			for (int j = 0; j < 8; ++j) {
				window.draw(cuadros[i][j]);
			}
		}

		window.display();

	}
	return 0;
}
