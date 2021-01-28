/**
 * @file State.h
 * @author Jan Wielgus
 * @brief Base class for all concrete states.
 * @date 2021-01-26
 * 
 */

#ifndef STATE_H
#define STATE_H

class Context;


class State
{
protected:
    Context* const context;

    State(Context* _context)
        : context(_context)
    {
    }

    virtual ~State() {}

    /**
     * @brief Update current state and decide if remain in this one
     * or change the state.
     * Have to be overriden in derivative class.
     * @return State* new dynamically allocated object or nullptr
     * if this state should remain.
     */
    virtual void updateState() = 0;

    /**
     * @brief Can be overriden. Called once
     * before the first call of updateState() method.
     */
    virtual void entryEvent() {}

    /**
     * @brief Optional state name getter.
     * Can be overriden in derivative class.
     */
    virtual const char* stateName()
    {
        return "";
    }

    friend class Context;
};


#endif
