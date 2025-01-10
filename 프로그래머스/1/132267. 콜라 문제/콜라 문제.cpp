#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int a, int b, int n) {
    int answer = 0;
    int newBottle = 0;
    int rest = 0;
    
    while(n >= a){
        newBottle = (n / a)*b;
        answer += newBottle;
        rest = n % a;
        n = newBottle + rest;
    }
    return answer;
}