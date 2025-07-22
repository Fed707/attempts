#include <SFML/Graphics.hpp>
#include <string>

int main() {
    sf::RenderWindow window(sf::VideoMode(400, 200), "Greetings");
    sf::Font font;
    if (!font.loadFromFile("/usr/share/fonts/truetype/dejavu/DejaVuSans.ttf")) {
        return 1;
    }

    std::string name;
    sf::Text prompt("Enter your name: ", font, 24);
    prompt.setPosition(20, 30);
    prompt.setFillColor(sf::Color::Black);

    sf::Text input("", font, 24);
    input.setPosition(24, 72);
    input.setFillColor(sf::Color::Black);

    sf::Text greeting("", font, 24);
    greeting.setPosition(20, 120);
    greeting.setFillColor(sf::Color::Black);

    sf::RectangleShape inputBox(sf::Vector2f(360, 32));
    inputBox.setPosition(18, 68);
    inputBox.setFillColor(sf::Color(220, 220, 220));
    inputBox.setOutlineColor(sf::Color::Black);
    inputBox.setOutlineThickness(2);

    bool greeted = false;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();

            if (!greeted && event.type == sf::Event::TextEntered) {
                if (event.text.unicode == '\r' || event.text.unicode == '\n') {
                    greeting.setString("Hello, " + name + "!");
                    greeted = true;
                } else if (event.text.unicode == 8) { // Backspace
                    if (!name.empty()) name.pop_back();
                } else if (event.text.unicode < 128 && event.text.unicode != '\t') {
                    name += static_cast<char>(event.text.unicode);
                }
                input.setString(name);
            }
        }

        window.clear(sf::Color::White);
        window.draw(prompt);
        window.draw(inputBox);
        window.draw(input);
        if (greeted) window.draw(greeting);
        window.display();
    }
    return 0;
}