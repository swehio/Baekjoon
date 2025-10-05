#include <bits/stdc++.h>
using namespace std;

int days;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    string str;
    cin >> str;

    int sum = 0;
    int multiply = 1;
    for(int i=0; i<str.size(); i++)
    {   
        if(str[i] == '*') 
        {
            if(i%2 != 0) multiply = 3;
            continue;
        }
        if(i%2 == 0) sum += (str[i] - '0');
        else sum += (str[i] - '0') * 3;
    }

    for(int i=0; i<=9; i++)
    {
        if((sum + (i*multiply)) % 10 == 0)
        {
            cout << i;
            return 0;
        }
    }
}