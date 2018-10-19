#include "menu.h"

#include <SFML/Graphics/RenderTarget.hpp>

void Menu::add_item(const std::string& text)
{
    auto item = std::make_unique<MenuItem>(text, 64);

    // If there are items already, adjust position of new item
    if(not m_items.empty()) {
        auto const& previous_item = m_items.back();
        sf::FloatRect previous_bounds = previous_item->local_bounds();

        item->setPosition(previous_item->getPosition().x,
                          previous_item->getPosition().y + previous_bounds.height);
    }

    m_items.push_back(std::move(item));
}

void Menu::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    states.transform *= getTransform();

    for(auto const& item : m_items) {
        target.draw(*item, states);
    }
}
