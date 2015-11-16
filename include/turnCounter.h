#ifndef TURN_COUNTER_H
#define TURN_COUNTER_H

class TurnCounter 
{
private:
    int m_turnMax;
    int m_turnCount;

public:
    TurnCounter();
    TurnCounter(int turnMax);
    bool update();
};

#endif /* TURN_COUNTER_H */
