#include <string>
#include <vector>
#include <stack>
#include <iostream>
#include <cmath>
using namespace std;

int solution(int n, int k) {
    int answer = 0;
    stack<int> convertedNumber;
    vector<long> splitNum;
    
    while(n > 0)
    {
        convertedNumber.push(n%k);
        n = n/k;
    }
    
    string str = "";
    while(!convertedNumber.empty())
    {
        int num = convertedNumber.top();
        convertedNumber.pop();
        if(num == 0 && str != "")
        {
            if(str != "1")
                splitNum.push_back(stol(str));
            str = "";
        }
        else
        {
            str += to_string(num);
        }
    }
    if(str != "")
        splitNum.push_back(stol(str));
    
    for(long num : splitNum)
    {
        bool isPrime = true;
        if(num <= 1)
            isPrime = false;
        int limit = sqrt(num);
        for(long i = 2; i <= limit; ++i)
        {
            if(num % i == 0)
            {
                isPrime = false;
                break;
            }
        }
        if(isPrime)
        {
            ++answer;
        }
    }
    
    return answer;
}