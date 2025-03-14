#include <iostream>
#include <string>
#include <stack>
using namespace std;

int solution(string s)
{
    stack<char> st;
    for(char ch : s)
    {
        if(!st.empty())
        {
            if(ch == st.top())
            {
                st.pop();
                continue;
            }
        }
        st.push(ch);
    }
    
    return st.empty() ? 1 : 0;
}