#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int m, d, w;
    m = 1;
    d = 1;
    w = 1;

    int x, y;
    cin >> x >> y;

    while(m != x || d != y)
    {
        d++;
        w++;
        if(m==12&&d==31) break;
        if(w > 6) w = 0; 
        bool day31 = d>31&&(m==1||m==3||m==5||m==7||m==8||m==10||m==12);
        bool day30 = d>30&&(m==4||m==6||m==9||m==11);
        bool day28 = d>28&&(m==2);
        if(day31||day30||day28)
        {
            d = 1;
            m++;
        }  
    }

    if(w == 0) cout << "SUN";
    else if(w == 1) cout << "MON";
    else if(w == 2) cout << "TUE";
    else if(w == 3) cout << "WED";
    else if(w == 4) cout << "THU";
    else if(w == 5) cout << "FRI";
    else if(w == 6) cout << "SAT";
 
}