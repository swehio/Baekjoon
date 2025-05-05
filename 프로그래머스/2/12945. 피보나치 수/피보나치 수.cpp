#include <string>
#include <vector>
#include <iostream>

using namespace std;
 
int solution(int n) {
    long long answer = 0;
    vector<long long> fivoList(n+1, 0);
    fivoList[0]=0;
    fivoList[1]=1;
    for(int i = 2; i<=n; ++i)
    {
        fivoList[i] = fivoList[i-2]% 1234567 + fivoList[i-1]% 1234567;
    }
    answer = fivoList[n]% 1234567;
    return answer;
}