#include <string>
#include <vector>
#include <numeric>
#include <cmath>
#include <iostream>

using namespace std;

vector<int> numCounts(int number)
{
    vector<int> counts;
    for(int i = 1; i<=number; ++i)
    {
        int count = 0;
        for(int j = 1;j<=floor(sqrt(i));++j)
        {
            if(i%j == 0)
                ++count;
        }
        count *= 2;
        if(pow(floor(sqrt(i)),2) == i)
            --count;
        counts.push_back(count);
    }
    return counts;
}

void replace(vector<int>& counts, int limit, int power)
{
    for(int i = 0; i<counts.size();++i)
    {
        if(counts[i] > limit)
        {
            counts[i] = power;
        }
    }
}

int solution(int number, int limit, int power) 
{
    int answer = 0;
    vector<int> counts;
    
    counts = numCounts(number);
    
    replace(counts, limit, power);
    
    answer = accumulate(counts.begin(), counts.end(), 0);
    
    return answer;
}