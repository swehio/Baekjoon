#include <bits/stdc++.h>
using namespace std;

int cnt; 

bool compare(string& a, string& b)
{
    if(a.size() == b.size())
    {
        return a < b;
    }
    return a.size() < b.size();
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N;
    cin >> N;
    
    vector<string> list;
    
    while(N--)
    {
        string str;
        cin >> str;
        
        int start = -1;
        int len = 0;
        string num = ""; 
        for(int i = 0; i<str.size(); i++)
        {
            if(isdigit(str[i]))
            {
                if(start == -1) start = i;
                len++;
            }
            else
            {
                if(len != 0) 
                {
                    while(1)
                    {
                        if(str[start] != '0' || len == 1) break;
                        start++;
                        len--;
                    }
                    string s = str.substr(start, len);
                    list.push_back(s);
                    start = -1;
                    len = 0;
                }
            }
        }
        if(len != 0)                     
        {
            while(1)
            {
                if(str[start] != '0' || len == 1) break;
                start++;
                len--;
            }
            string s = str.substr(start, len);
            list.push_back(s);
        }
    }
    
    sort(list.begin(), list.end(), compare);
    for(int i = 0; i < list.size(); i++)
    {
        cout << list[i] << '\n';
    }
}