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
    State* currentState;

public:
    /**
     * @param initialState dynamically allocated initial state.
     */
    Context(State* initialState)
        : currentState(initialState)
    {
    }


    /**
     * @brief Set state. State have to be new, dynamically
     * allocated object.
     */
    void setCurrentState(State* state)
    {
        delete currentState;
        currentState = state;
    }


    /**
     * @brief This method can be used to set current state,
     * if state object constructor receives no parameters.
     * @tparam T 
     */
    template <class T, class ... Types>
    void setCurrentState(Types ... args)
    {
        delete currentState;
        currentState = new T(args...);
    }
    

    /**
     * @brief Execute current gesture state and change it
     * if current gesture requests it.
     */
    void updateState()
    {
        if (currentState == nullptr)
            return;

        State* nextState = currentState->updateState();

        // if nextState == nullptr -> current state remains
        if (nextState != nullptr)
        {
            delete currentState;
            currentState = nextState;
        }
    }
};


#endif
