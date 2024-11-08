#include <SFML/Graphics.hpp>
#include <iostream>
#include <cstdlib>
#include <ctime>

sf::Vector2f gerarCoordenadasAleatorias(float minX, float maxX, float minY, float maxY) {
    float novoX = std::rand() % static_cast<int>(maxX - minX + 1) + minX;
    float novoY = std::rand() % static_cast<int>(maxY - minY + 1) + minY;
    return sf::Vector2f(novoX, novoY);
    }


int main() {
    // Creating the window
    sf::RenderWindow window(sf::VideoMode(1000, 700), "BUXA NO DRUGS");

    // Creating a WHITE circle shape
    sf::CircleShape circle(25.0f);
    circle.setPosition(sf::Vector2f(100, 500));
    circle.setFillColor(sf::Color::Red);
    circle.setOutlineThickness(3);
    circle.setOutlineColor(sf::Color::White);

    // Creating a RED rectangle shape
    sf::RectangleShape red_rect(sf::Vector2f(20, 19));
    red_rect.setPosition(sf::Vector2f(250, 505));
    red_rect.setFillColor(sf::Color::Red);
    red_rect.setOutlineThickness(3);
    red_rect.setOutlineColor(sf::Color::White);

    // Creating a BLUE rectangle shape
    sf::RectangleShape blue_rect(sf::Vector2f(20, 19));
    blue_rect.setPosition(sf::Vector2f(450, 505));
    blue_rect.setFillColor(sf::Color(0, 0, 128));
    blue_rect.setOutlineThickness(3);
    blue_rect.setOutlineColor(sf::Color::White);

    // Creating a VIBRANT PURPLE rectangle shape
    sf::RectangleShape purple_rect(sf::Vector2f(20, 19));
    purple_rect.setPosition(sf::Vector2f(650, 505));
    purple_rect.setFillColor(sf::Color(128, 0, 128));
    purple_rect.setOutlineThickness(3);
    purple_rect.setOutlineColor(sf::Color::White);

    // Creating the font
    sf::Font fonte;
    if (!fonte.loadFromFile("Blacklisted.ttf")) {
        std::cout << "Font não encontrada" << std::endl;
        return -1;  // Evitar continuar sem a fonte
    }

    // Creating the text "THE HIPNOSE GAME"
    sf::Text texto;
    texto.setFont(fonte);
    texto.setString("THE HIPNOSE GAME");
    texto.setCharacterSize(50);
    texto.setFillColor(sf::Color(0, 255, 255));
    texto.setPosition(sf::Vector2f(340, 105));

    // Creating another text for points
    int pontos = 0;
    sf::Text texto_pontos;
    texto_pontos.setFont(fonte);
    texto_pontos.setString(std::to_string(pontos));
    texto_pontos.setCharacterSize(15);
    texto_pontos.setFillColor(sf::Color(0, 255, 255));
    texto_pontos.setPosition(sf::Vector2f(900, 105));

    bool passouRed = false;
    bool passouBlue = false;
    bool passouPurple = false;


    sf::Clock relogio;


    while (window.isOpen()) {
        sf::Event event;

        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
            circle.move(-2.f, 0.f);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
            circle.move(2.f, 0.f);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)){
            circle.move(0.f, -2.f);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)){
            circle.move(0.f, 2.f);
        }

        if (circle.getGlobalBounds().intersects(red_rect.getGlobalBounds()) && !passouRed) {
            circle.setFillColor(sf::Color::Red);
            pontos += 1;
            passouRed = true;
            red_rect.setPosition(gerarCoordenadasAleatorias(100.f, 900.f, 300.f, 600.f));
        } else if (!circle.getGlobalBounds().intersects(red_rect.getGlobalBounds())) {
            passouRed = false;
        }

        if (circle.getGlobalBounds().intersects(blue_rect.getGlobalBounds()) && !passouBlue) {
            circle.setFillColor(sf::Color(0, 0, 128));
            pontos += 1;
            passouBlue = true;
            blue_rect.setPosition(gerarCoordenadasAleatorias(100.f, 900.f, 300.f, 600.f));
        } else if (!circle.getGlobalBounds().intersects(blue_rect.getGlobalBounds())) {
            passouBlue = false;
        }

        if (circle.getGlobalBounds().intersects(purple_rect.getGlobalBounds()) && !passouPurple) {
            circle.setFillColor(sf::Color(128, 0, 128));
            pontos += 1;
            passouPurple = true;
            purple_rect.setPosition(gerarCoordenadasAleatorias(100.f, 900.f, 300.f, 600.f));
        } else if (!circle.getGlobalBounds().intersects(purple_rect.getGlobalBounds())) {
            passouPurple = false;
        }

        texto_pontos.setString(std::to_string(pontos));

        window.clear();
        window.draw(texto);
        window.draw(texto_pontos);
        window.draw(circle);
        window.draw(red_rect);
        window.draw(blue_rect);
        window.draw(purple_rect);
        window.display();
    }

    return 0;
}
