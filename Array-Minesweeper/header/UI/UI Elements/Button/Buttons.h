#pragma once
#include <SFML/Graphics.hpp>
#include "../../header/Event/EventPollingManager.h"
#include "../../header/Sound/SoundManager.h"
#include <functional>

namespace UIElements {
    class Button {
    private:
        sf::Texture buttonTexture;
        sf::Sprite buttonSprite;

    public:
        Button(const std::string& texturePath, const sf::Vector2f& position, float width, float height);
        void Render(sf::RenderWindow& window) const;
        void SetTextureRect(const sf::IntRect& rect);
        void Initialize(const std::string& texturePath, const sf::Vector2f& position, float width, float height);
    };
}
