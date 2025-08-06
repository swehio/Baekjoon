#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    stack<char> st;
    
    string str = "";
    
    while(1)
    {
        getline(cin, str);
        if(str == ".") break;
        if(str[str.size()-1] != '.') continue;
        for(char ch : str)
        {
            if(ch == '(' || ch == '[')
                st.push(ch);
            else if(ch == ')')
            {
                if(!st.empty() && st.top() == '(')
                    st.pop();
                else
                    st.push(ch);
            }
            else if(ch == ']')
            {
                if(!st.empty() && st.top() == '[')
                    st.pop();
                else
                    st.push(ch);
            }
        }
        
        cout << (st.empty() ? "yes" : "no") << '\n';
        while(!st.empty()) st.pop();
        str = "";
    }
    
}