#ifndef TILEMAP_H
#define TILEMAP_H

#include <SFML/Graphics.hpp>
#include <vector>

class tilemap : public sf::Drawable, public sf::Transformable {
    private:
        sf::VertexArray m_vertices;
        sf::Texture m_tileset;


    public:
        tilemap();

        bool load(const std::string& tileset, sf::Vector2u tilesize, 
                  const std::vector<int>& tiles, unsigned int width, unsigned int height);
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};

#endif