#include <bits/stdc++.h> 

using namespace std; 

bool checkP(char a, char b)
{
    if(a=='['&&b==']') return true;
    if(a=='('&&b==')') return true;
    if(a=='{'&&b=='}') return true;
    
    return false;
}


bool check(string& s)
{
    stack<char> st;
    
    for(char ch : s)
    {  
        if(!st.empty()&&checkP(st.top(), ch)) st.pop();  
        else st.push(ch);  
    }  
    
    return st.empty();
}

int cnt;

int solution(string s) {   
    int size = s.size();
    
    for(int i=0; i<size; i++)
    {
        rotate(s.begin(), s.begin()+1, s.end());
        if(check(s)) cnt++;
    } 
    return cnt;
}