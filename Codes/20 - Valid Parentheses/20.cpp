#include <bits/stdc++.h>
using namespace std;
#ifdef ONLINE_JUDGE
#define dbg(...)
#else
#include <debug.h>
#endif
#define ll long long

bool isValid(string s)
{
    stack<char> st;
    for (auto &c : s)
    {
        if (c == ')')
        {
            if (st.empty() || st.top() != '(')
                return false;
            st.pop();
        }
        else if (c == '}')
        {
            if (st.empty() || st.top() != '{')
                return false;
            st.pop();
        }
        else if (c == ']')
        {
            if (st.empty() || st.top() != '[')
                return false;
            st.pop();
        }
        else
            st.push(c);
    }
    if (st.empty())
        return true;
    return false;
}

signed main()
{
    string s;
    cin >> s;
    cout << isValid(s) << endl;
}