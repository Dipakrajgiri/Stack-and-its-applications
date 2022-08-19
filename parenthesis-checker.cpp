#include <iostream>
#include "stack.cpp"
using namespace std;
bool isBalanced(string exp)
{
    Stack<char> s(30);
    char ch;
    for (int i = 0; i < exp.length(); i++)
    {
        if((exp[i]>='a'&& exp[i]<='z') || (exp[i]>='A'&& exp[i]<='Z') || exp[i]=='+'|| exp[i]=='-'||exp[i]=='/'||exp[i]=='*')
        {
            continue;
        }
        if (exp[i] == '(' || exp[i] == '[' || exp[i] == '{')
        {
            s.push(exp[i]);
            continue;
        }
        if (s.isEmpty())
            return false;
        switch (exp[i])
        {
        case ')':
            ch = s.pop();
            if (ch!='(')
                return false;
            break;
        case '}':
            ch = s.pop();
            if (ch != '{')
                return false;
            break;
        case ']':
            ch =s.pop();
            if (ch != '[')
                return false;
            break;
        }
    }
    return (s.isEmpty());
}
int main()
{
    string exp;
    cout << "enter an expression";
    cin >> exp;
    if (isBalanced(exp))
        cout << "Balanced";
    else
        cout << "Not Balanced";
    return 0;
}