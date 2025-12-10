#include <bits/stdc++.h>
using namespace std;

int firstNum[3];
int secondNum[3];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int first, second, ftmp, stmp;
    cin >> first >> second;

    ftmp = first;
    stmp = second;

    for(int i=0; i<3; i++)
    {
        firstNum[i] = ftmp%10;
        ftmp/=10;
        secondNum[i] = stmp%10;
        stmp/=10;
    }

    for(int i=0; i<3; i++)
    {   
        stack<int> st;
        int up = 0;
        for(int j=0; j<3; j++)
        {
            int multi = secondNum[i] * firstNum[j];
            st.push((multi+up) % 10);
            up = (multi+up)/10;
        }
        if(up!=0) st.push(up);
        bool isfrontzero = true;
 
        while(!st.empty())
        { 
            if(st.top() != 0) isfrontzero = false;
            
            if(!isfrontzero)
                cout << st.top(); 
                
            st.pop();
        }  
        if(isfrontzero) cout << 0;
        cout << '\n';
    }
     
    cout << first * second;
}