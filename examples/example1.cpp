#include "../State.h"
#include "../Context.h"
#include <iostream>


using std::cout;
using std::endl;


class TestState1 : public State
{
    State* updateState() override;
};

class TestState2 : public State
{
    State* updateState() override;
};


State* TestState1::updateState()
{
    cout << "test state 1 is working" << endl;

    return new TestState2;
}

State* TestState2::updateState()
{
    cout << "test state 2 is working" << endl;

    return new TestState1;
}


class StateWithParams : public State
{
    int v1;
    float v2;

public:
    StateWithParams(int var1, float var2)
    {
        v1 = var1;
        v2 = var2;
    }

    State* updateState() override
    {
        cout << "state with params: " << v1 << " and " << v2 << endl;

        return nullptr;
    }
};


int main()
{
    cout << "Hello world!" << endl;

    
    Context context(new TestState1);

    for (int i = 0; i < 10; i++)
        context.updateState();

    context.setCurrentState<StateWithParams>(5, 8.4f);

    context.updateState();


    return 0;
}
