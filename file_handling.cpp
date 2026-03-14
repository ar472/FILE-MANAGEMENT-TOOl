#include <iostream>
#include <stack>
using namespace std;

int precedence(char op)
{
    if(op == '+' || op == '-') return 1;
    if(op == '*' || op == '/') return 2;
    return 0;
}

int applyOperation(int a, int b, char op)
{
    switch(op)
    {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return a / b;
    }
    return 0;
}

int evaluate(string exp)
{
    stack<int> values;
    stack<char> ops;

    for(int i = 0; i < exp.length(); i++)
    {
        if(isdigit(exp[i]))
        {
            int val = 0;
            while(i < exp.length() && isdigit(exp[i]))
            {
                val = val * 10 + (exp[i] - '0');
                i++;
            }
            values.push(val);
            i--;
        }

        else if(exp[i] == '+' || exp[i] == '-' || exp[i] == '*' || exp[i] == '/')
        {
            while(!ops.empty() && precedence(ops.top()) >= precedence(exp[i]))
            {
                int val2 = values.top(); values.pop();
                int val1 = values.top(); values.pop();
                char op = ops.top(); ops.pop();
                values.push(applyOperation(val1, val2, op));
            }
            ops.push(exp[i]);
        }
    }

    while(!ops.empty())
    {
        int val2 = values.top(); values.pop();
        int val1 = values.top(); values.pop();
        char op = ops.top(); ops.pop();
        values.push(applyOperation(val1, val2, op));
    }

    return values.top();
}

int main()
{
    string expression;
    cout << "Enter arithmetic expression: ";
    cin >> expression;

    cout << "Result = " << evaluate(expression);

    return 0;
}
