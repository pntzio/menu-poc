#pragma once

#include <string>
#include <vector>
#include <memory>

#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Transformable.hpp>

#include "menuitem.h"

class Menu : public sf::Drawable, public sf::Transformable
{

public:

    Menu() = default;
    ~Menu() = default;

    void add_item(std::string const& text);

protected:

    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

    std::vector<std::unique_ptr<MenuItem>> m_items;

};
