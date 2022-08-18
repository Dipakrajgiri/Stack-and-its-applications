#include <iostream>
#include "stack.cpp"
#include <string>
#include <cmath>
using namespace std;
int postfixevaluation(string s)
{
    Stack<int> st(100);
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] >= '0' && s[i] <= '9')
        {
            int num = 0, j = 0;
            Stack<int> it(100);
            while (s[i] >= '0' && s[i] <= '9')
            {
                it.push(s[i]);
                i++;
            }
            i--;
            while (!it.isEmpty())
            {
                num = num + (it.pop() - '0') * pow(10, j);
                j++;
            }
            st.push(num);
        }
        else if (s[i] == ' ')
        {
            continue;
        }

        else
        {
            int op2 = st.pop();
            int op1 = st.pop();
            switch (s[i])
            {
            case '+':
                st.push(op1 + op2);
                break;
            case '-':
                st.push(op1 - op2);
                break;
            case '*':
                st.push(op1 * op2);
                break;
            case '/':
                st.push(op1 / op2);
                break;
            }
        }
    }
    return st.peek();
}
int main()
{

    string exp;
    cout << "demo input is 34 45 +\n Result :" << postfixevaluation("34 45 +") << endl;
    cout << "the postfix expression to be evaluated is:" << endl;
    getline(cin, exp);
    cout << "The result is:" << postfixevaluation(exp) << endl;
    return 0;
}
