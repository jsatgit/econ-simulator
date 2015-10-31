#ifndef POSITIONER_H
#define POSITIONER_H

#include <random>
#include <SFML/System/Vector2.hpp>

class Positioner 
{
private:
    std::default_random_engine generator;
    std::discrete_distribution<int> distribution {1,1,1};

public:
    static Positioner& instance();
    sf::Vector2f next(const sf::Vector2f& current);
};

#endif /* POSITIONER_H */
