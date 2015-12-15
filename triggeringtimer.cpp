#include "triggeringtimer.h"

TriggeringTimer::TriggeringTimer() : Timer(), _alreadyExpired(false), _loopRunning(false)
{

}

TriggeringTimer::TriggeringTimer(sf::Time timeLimit, bool initRunning, bool loopRunning) :
Timer(timeLimit, initRunning),
_alreadyExpired(false),
_loopRunning(loopRunning)
{

}

TriggeringTimer::~TriggeringTimer()
{

}

void    TriggeringTimer::setLoopRunning(bool active)
{
    _loopRunning = active;
}

bool    TriggeringTimer::loopRunning()  const
{
    return _loopRunning;
}

void    TriggeringTimer::restart(sf::Time timeLimit, bool keepRunning)
{
    Timer::restart(timeLimit, keepRunning);

    _alreadyExpired = false;
}

void    TriggeringTimer::restart(bool keepRunning)
{
    Timer::restart(keepRunning);

    _alreadyExpired = false;
}

void    TriggeringTimer::bind(std::function< void(void) > function)
{
    _listener = function;
}

void    TriggeringTimer::update()
{
    if(isExpired() && !_alreadyExpired)
    {
        // Expiration
        _alreadyExpired = true;
        _listener(); // On lance la fonction associée

        // If loop running, then we have to reset the timer and to re-run it
        if(_loopRunning)
            restart(true);
    }
}
