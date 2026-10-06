#include <iostream>
#include <vector>
#include <fstream>
#include <SFML/Graphics.hpp>

struct Projectile {
    sf::CircleShape shape;
    sf::Vector2f velocity;

    void update(float deltaTime) {
        shape.move(velocity * deltaTime);
    }
};

int main() {
    unsigned int width = 1280;
    unsigned int height = 720;

    sf::ContextSettings settings;
    settings.antiAliasingLevel = 8;

    sf::RenderWindow window(sf::VideoMode({width, height}), "Simulator");
    window.setFramerateLimit(120);
    window.setVerticalSyncEnabled(true);
    
    const float radius = 40.f;

    Projectile projectile;

    projectile.shape = sf::CircleShape(radius, 4);
    projectile.shape.setOrigin({radius, radius});
    projectile.shape.setPosition({400.f, 600.f});
    projectile.shape.setFillColor(sf::Color(255, 255, 255));
    projectile.velocity = {-200.f, -200.f};

    sf::Clock clock;
    
    while (window.isOpen()) {
        while (const std::optional event = window.pollEvent()) {
            if (event -> is <sf::Event::Closed>()) {
                window.close();
            } 
        }

        float deltaTime = clock.restart().asSeconds();
        projectile.update(deltaTime);

        sf::Vector2f position = projectile.shape.getPosition();
        sf::Vector2f vel = projectile.velocity;

        if (position.x - radius < 0.f) {
            position.x = radius;
            vel.x = -vel.x;
        } else if (position.x + radius > width) {
            position.x = width - radius;
            vel.x = -vel.x;
            
        }
        if (position.y - radius < 0.f) {
            position.y = radius;
            vel.y = -vel.y;
        } else if (position.y + radius > height) {
            position.y = height - radius;
            vel.y = -vel.y;
        }

        projectile.shape.setPosition(position);
        projectile.velocity = vel;


        window.clear(sf::Color(10, 10, 30));
        window.draw(projectile.shape);
        window.display();
    }
}