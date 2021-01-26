#include "../State.h"
#include "../Context.h"
#include <iostream>


using std::cout;
using std::endl;


class TestState1 : public State
{
public:
    TestState1(Context* context)
        : State(context)
    {}

    void updateState() override;
};


class TestState2 : public State
{
public:
    TestState2(Context* context)
        : State(context)
    {}

    void updateState() override;
};



void TestState1::updateState()
{
    cout << "test state 1 is working" << endl;

    context->setState<TestState2>(context);
}


void TestState2::updateState()
{
    cout << "test state 2 is working" << endl;

    context->setState<TestState1>(context);
}



class StateWithParams : public State
{
    int v1;
    float v2;

public:
    StateWithParams(Context* context, int var1, float var2)
        : State(context)
    {
        v1 = var1;
        v2 = var2;
    }

    void updateState() override
    {
        cout << "state with params: " << v1 << " and " << v2 << endl;
    }
};



int main()
{
    cout << "Hello world!" << endl;

    
    Context context;
    context.setState<TestState1>(&context); // remember to pass a pointer to Context class


    for (int i = 0; i < 10; i++)
        context.updateState();

    context.setState<StateWithParams>(&context, 5, 8.4f); // remember to pass a pointer to Context class

    for (int i = 0; i < 4; i++)
        context.updateState();


    return 0;
}
