#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int count = 0;

    string word;
    while(cin >> word)
    {
        if(word == "<br>")
        {
            cout << '\n';
            count = 0;
            continue;
        }
        
        if(word == "<hr>")
        {
            if(count != 0) cout << '\n';
            count = 0;
            for(int i=0; i<80; i++) cout<<'-';
            cout << '\n';
            continue;
        }

        if(count+word.size()+1 > 80) 
        {
            cout << '\n'; 
            count = 0;
        }

        if(count != 0) cout << ' '; count++;
        count+=word.size();
        cout << word ;
    } 
}