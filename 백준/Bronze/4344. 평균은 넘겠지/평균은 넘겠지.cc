#include <bits/stdc++.h>
using namespace std;

int score[1002];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int c; 
    cin >> c;

    while(c--)
    {
        int n;
        cin >> n;

        int sum = 0;

        for(int i=0; i<n; i++)
        {
            cin >> score[i];
            sum += score[i]; 
        }

        int avg = sum / n; 
        
        float greateravgcnt = 0;

        cout.precision(5);

        for(int i=0; i<n; i++)
        {
            if(avg < score[i]) greateravgcnt++;
        }  
        cout << (greateravgcnt/n*100) << "%\n"; 
    }
}