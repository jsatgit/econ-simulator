#include "positioner.h"
#include "gameWindow.h"
#include <iostream>
#include <chrono>

using namespace sf;
using namespace std;

Positioner::Positioner() : 
    m_generator(chrono::system_clock::now().time_since_epoch().count()),
    m_screen_x_distribution(uniform_int_distribution<int>(0, GameWindow::instance().getWidth() - 1)),
    m_screen_y_distribution(uniform_int_distribution<int>(0, GameWindow::instance().getHeight() - 1))
{
}

Positioner& Positioner::instance()
{
    static Positioner instance;
    return instance;
}

Vector2f Positioner::nextRand(const Vector2f& current)
{
    return current + Vector2f(m_neighbour_distribution(m_generator) - 1, 
                              m_neighbour_distribution(m_generator) - 1);
}

Vector2f Positioner::generateGoal()
{
    return Vector2f(m_screen_x_distribution(m_generator), m_screen_y_distribution(m_generator));
}

int Positioner::getSign(int num)
{
    if (num < 0) {
        return -1;
    } else if (num == 0) {
        return 0;
    } else {
        return 1;
    }
}

Vector2f Positioner::nextRandGoal(const Vector2f& current, Vector2f& goal)
{
    if (current == goal) {
        goal = generateGoal();
    }
    int signX = getSign(goal.x - current.x);
    int signY = getSign(goal.y - current.y);
    return current + Vector2f(signX, signY);
}

void Positioner::print(const char* msg, const sf::Vector2f& position)
{
    cout << msg << ": " << position.x << "," << position.y << endl;
}
