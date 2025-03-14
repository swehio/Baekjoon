#include <string>
#include <vector>
#include <stack>
#include <iostream>

using namespace std;

int IsRight(const string& str)
{
    stack<char> st;
    for(char ch : str)
    {
        if(!st.empty())
        {
            if(ch == ')')
            {
                if(st.top()=='(')
                {
                    st.pop();
                    continue;
                }
            }
            else if(ch == '}')
            {
                if(st.top()=='{')
                {
                    st.pop();
                    continue;
                }
            }
            else if(ch == ']')
            {
                if(st.top()=='[')
                {
                    st.pop();
                    continue;
                }
            }
        }

        st.push(ch);
    }
    
    return st.empty() ? 1 : 0;
}

int solution(string s) {
    int answer = 0;
    
    for(int i = 0; i<s.size(); i++)
    {
        string news ="";
        for(int j =0; j<s.size();j++)
        {
            news+= s[(i+j)%s.size()];
        }
        answer += IsRight(news);
    }
    return answer;
}