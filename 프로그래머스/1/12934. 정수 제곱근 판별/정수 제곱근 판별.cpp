#include <string>
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

long long solution(long long n) {
    long long answer = 0;
    int m = 0;
    m=sqrt(n);
    answer = (sqrt(n) - m) == 0?pow(m+1, 2):-1;
    return answer;
}