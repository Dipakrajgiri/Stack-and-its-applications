#include <iostream>
#include "stack.cpp"
using namespace std;
Stack <char> st(50);
int differentiate(char ch)
{
    return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
}
int precedence(char ch)
{
    switch (ch)
    {
    case '+':
    case '-':
        return 1;

    case '*':
    case '/':
        return 2;
    }
    return -1;
}
int converter(char exp[])
{
    int i, j;

    for (i = 0, j = -1; exp[i]; ++i)
    {
        if (differentiate(exp[i]))
            exp[++j] = exp[i];
        else if (exp[i] == '(')
            st.push(exp[i]);
        else if (exp[i] == ')')
        {
            while (!st.isEmpty() && st.peek() != '(')
                exp[++j] = st.pop();
            if (!st.isEmpty() && st.peek() != '(')
                return -1;
            else
                st.pop();
        }
        else
        {
            while (!st.isEmpty() && precedence(exp[i]) <= precedence(st.peek()))
                exp[++j] = st.pop();
            st.push(exp[i]);
        }
    }
    while (!st.isEmpty())
        exp[++j] = st.pop();

    exp[++j] = '\0';
    cout<<exp;
}

int main()
{
    char exp[30];
    cout << "enter an infix operation\n";
    cin >> exp;
    cout << "the postfix operation is ";
    converter(exp);
    return 0;
}
