#include "turnCounter.h"

TurnCounter::TurnCounter()
{
}

TurnCounter::TurnCounter(int turnMax) :
    m_turnMax(turnMax),
    m_turnCount(0)
{
}

bool TurnCounter::update()
{
    bool res = false;
    if (++m_turnCount == m_turnMax) {
        m_turnCount = 0;
        res = true;
    }
    return res;
}
