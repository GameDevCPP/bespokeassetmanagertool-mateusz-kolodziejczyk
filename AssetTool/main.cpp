#include <SFML/Graphics.hpp>
#include <TGUI/TGUI.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode(200, 200), "SFML please!");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);
    tgui::GuiSFML gui{window};
    tgui::Button::Ptr button = tgui::Button::create();
    auto editBox = tgui::EditBox::create();
    gui.add(button);
    gui.add(editBox, "MyWidgetName");
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            gui.handleEvent(event);

            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        gui.draw();
        window.display();
    }

    return 0;
}