#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iostream>

using namespace std;

int solution(int n, int a, int b)
{
    int answer = 0;
    vector<int> matchList;
    int aIndex = 0;
    int bIndex = 0;
    
    for(int i = 0; pow(2, i) <= n; ++i)
    {
        for(int j = 1; j <= pow(2, i); ++j)
        {
            matchList.push_back(j);
            if(pow(2, i) == n)
            {
                if(j==a) aIndex = matchList.size()-1;
                if(j==b) bIndex = matchList.size()-1;
            }
        }
    }
    
    while(aIndex != bIndex)
    {
        ++answer;
        aIndex = aIndex%2 == 0 ? (aIndex-2)/2 : (aIndex-1)/2;
        bIndex = bIndex%2 == 0 ? (bIndex-2)/2 : (bIndex-1)/2;
    }

    return answer;
}