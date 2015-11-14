#ifndef POSITIONER_H
#define POSITIONER_H

#include <random>
#include <SFML/System/Vector2.hpp>

class Positioner
{
private:
    std::default_random_engine m_generator;
    std::discrete_distribution<int> m_neighbour_distribution {1,1,1};
    std::uniform_int_distribution<int> m_screen_x_distribution;
    std::uniform_int_distribution<int> m_screen_y_distribution;
    Positioner();
    int getSign(int num);

public:
    static Positioner& instance();
    sf::Vector2f nextRand(const sf::Vector2f& current);
    sf::Vector2f nextRandGoal(const sf::Vector2f& current, sf::Vector2f& goal);
    sf::Vector2f generateGoal();
    void print(const char* msg, const sf::Vector2f& position);
};

#endif /* POSITIONER_H */
