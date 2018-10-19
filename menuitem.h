#pragma once

#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Transformable.hpp>
#include <SFML/Graphics/RectangleShape.hpp>

class MenuItem : public sf::Drawable, public sf::Transformable
{

public:

    MenuItem(std::string const& text, uint32_t char_size = 64);
    ~MenuItem() = default;

    sf::FloatRect local_bounds() { return m_text.getLocalBounds(); }

protected:

    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

private:

    sf::Text m_text;
    sf::Font m_font;

    sf::RectangleShape m_rect;

};
