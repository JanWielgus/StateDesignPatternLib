/**
 * @file Context.h
 * @author Jan Wielgus
 * @brief Class that organizes the work of states.
 * @date 2021-01-26
 * 
 */

#ifndef CONTEXT_H
#define CONTEXT_H

#include "State.h"


class Context
{
    State* currentState = nullptr;
    State* nextState = nullptr;

public:
    /**
     * @brief Does nothing. To set state use setState method.
     */
    Context()
    {
    }


    /**
     * @brief Set current state (specify concrete state class
     * as first template argument. Pass parameters in parenthesis,
     * like in constructor).
     * @tparam T Concrete State class to set.
     */
    template <class T, class... Types>
    void setState(Types... args)
    {
        delete nextState;
        nextState = new T(args...);
    }
    

    /**
     * @brief Execute current gesture state and change it
     * if current gesture requests it.
     */
    void updateState()
    {
        if (nextState != nullptr)
        {
            delete currentState;
            currentState = nextState;
            nextState = nullptr;
        }

        if (currentState != nullptr)
            currentState->updateState();
    }
};


#endif
