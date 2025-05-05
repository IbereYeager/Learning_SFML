#include <SFML/Graphics.hpp>
#include <iostream>
int main() {

	sf::RenderWindow window(sf::VideoMode(800, 600), "First game test");

	sf::Texture NinjaTexture;
	sf::Sprite NinjaSprite;
	
	if (NinjaTexture.loadFromFile("Samurai/Run.png")) {
		std::cout << '\n' << "Image Player loaded!!" << std::endl;
		NinjaSprite.setTexture(NinjaTexture);
		NinjaSprite.setTextureRect(sf::IntRect(0, 0, 128, 128));
	
	}
	else {
		std::cout << '\n' << "Image player not loaded!!" << std::endl;
	}

	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
			}
		}

		if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		{
			sf::Vector2f posicao_atual = NinjaSprite.getPosition();
			NinjaSprite.setPosition(posicao_atual + sf::Vector2f(2, 0));
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
			sf::Vector2f posicao_atual = NinjaSprite.getPosition();
			NinjaSprite.setPosition(posicao_atual + sf::Vector2f(-2, 0));
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
			sf::Vector2f posicao_atual = NinjaSprite.getPosition();
			NinjaSprite.setPosition(posicao_atual + sf::Vector2f(0, -2));
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
			sf::Vector2f posicao_atual = NinjaSprite.getPosition();
			NinjaSprite.setPosition(posicao_atual + sf::Vector2f(0, 2));
		}

		window.clear(sf::Color(255, 255, 255));

		window.draw(NinjaSprite);

		window.display();
	}
}