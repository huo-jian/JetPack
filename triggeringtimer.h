#ifndef TRIGGERINGTIMER_H
#define TRIGGERINGTIMER_H
#include <SFML/System.hpp>

#include <functional>
class TriggeringTimer : public Timer
{
    public:
        /**
        * @brief Default Constructor. To use the Timer you will need to use reset(float timeLimit, bool continueRunning).
        */
        TriggeringTimer();

        /**
        * @brief Recommended constructor.
        * @param timeLimit The starting time of the Timer. It will decrease to zero.
        * @param initRunning Set it true if you want to start the timer at construction
        * @param loopRunning Set it true if you want to restart the time when expired
        */
        TriggeringTimer(sf::Time timeLimit, bool initRunning = false, bool loopRunning = false);

        /**
        * @brief Default destructor.
        */
        virtual ~TriggeringTimer();

        /**
        * @brief To set or unset the auto restarting
        * @param active Set ir true if you want to restart the timer when expired, else set it false
        */
        void    setLoopRunning(bool active = true);

        /**
        * @brief Is the loop running activated ?
        * @return true if the loop running is activated, else return false
        */
        bool    loopRunning() const;

        /**
        * @brief To reset the Timer
        * @param timeLimit The starting time of the Timer. It will decrease to zero.
        * @param keepRunning Set it true if you want to restart the timer
        */
        void    restart(sf::Time timeLimit, bool keepRunning = false);

        /**
        * @brief To reset the Timer, the old time limit will be kept
        * @param keepRunning Set it true if you want to restart the timer
        */
        void    restart(bool keepRunning = false);

        /**
        * @brief Bind the expiration of the time with a slot
        * @param function A slot to call at timer expiration. You can use boost::bind to bind a object member, else use a function.
        */
        void    bind(std::function< void(void) > function);

        /**
        * @brief Update the timer and call the slot binded at expiration. Should be called once a main loop
        */
        void    update();

    private:
        bool        _alreadyExpired;
        bool        _loopRunning;
        std::function< void(void) >    _listener;
};
#endif // TRIGGERINGTIMER_H
