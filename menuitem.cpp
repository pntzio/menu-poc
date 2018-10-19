#include "menuitem.h"

#include <SFML/Graphics/RenderTarget.hpp>

MenuItem::MenuItem(const std::string& text, uint32_t char_size)
{
    m_font.loadFromFile("/path/to/font.ttf");

    m_text.setFont(m_font);
    m_text.setString(text);
    m_text.setFillColor(sf::Color::White);
    m_text.setCharacterSize(char_size);

    m_rect.setSize(sf::Vector2f(local_bounds().width, local_bounds().height));
    m_rect.setFillColor(sf::Color::Red);
}

void MenuItem::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    states.transform *= getTransform();
    target.draw(m_rect, states);
    target.draw(m_text, states);
}
