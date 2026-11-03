#include <iostream>
#include <stack>
using namespace std;

class MyQueue
{
private:
    stack<int> input;
    stack<int> output;

public:
    MyQueue()
    {
    }

    void push(int x)
    {
        input.push(x);
    }

    int pop()
    {
        if (output.empty())
        {
            while (!input.empty())
            {
                output.push(input.top());
                input.pop();
            }
        }

        int front = output.top();
        output.pop();

        return front;
    }

    int peek()
    {
        if (output.empty())
        {
            while (!input.empty())
            {
                output.push(input.top());
                input.pop();
            }
        }

        return output.top();
    }

    bool empty()
    {
        return input.empty() && output.empty();
    }
};

int main()
{
    MyQueue queue;

    queue.push(1);
    queue.push(2);
    queue.push(3);

    cout << "Front Element: " << queue.peek() << endl;
    cout << "Popped Element: " << queue.pop() << endl;
    cout << "Front Element After Pop: " << queue.peek() << endl;
    cout << "Popped Element: " << queue.pop() << endl;
    cout << "Queue Empty: " << (queue.empty() ? "true" : "false") << endl;

    return 0;
}
