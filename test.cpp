bool validity(string s)
{
    int opd = 0;
    int op= 0;
    bool first = true, last;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] >= '0' && s[i] <= '9')
        {
            while (s[i] >= '0' && s[i] <= '9')
            {
                i++;
            }
            i--;
            opd++;
        }
        else if (s[i] == ' ')
        {
            continue;
        }
        else
        {
            op++;
        }
    }
    if ((s[s.length() - 1] == '+') && (s[s.length() - 1] == '-') && (s[s.length() - 1] == '*') && (s[s.length() - 1] == '/'))
    {
        last = true;
    }
    for (int i = 0; i < s.length(); i++)
    {
        int space = 0, op = 0;
        if (s[i] == ' ')
        {
            space++;
        }
        if (s[i] == '+' && s[i] == '*' && s[i] == '-' && s[i] == '/')
        {
            op++;
        }
        if (space < 2 && op > 0)
        {
            first == false;
        }
    }

    if ((opd == (op+1)) && first && last)
    {
        return true;
    }
    else
    {
        return false;
    }
}