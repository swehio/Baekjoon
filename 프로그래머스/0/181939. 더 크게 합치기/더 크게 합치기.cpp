#include <string>
#include <iostream>
#include <vector>

using namespace std;

int solution(int a, int b) {
    int answer = 0;
    string ab = to_string(a)+ to_string(b);
    string ba = to_string(b)+ to_string(a);
    
    answer = stoi(ab) > stoi(ba) ? stoi(ab) : stoi(ba);
    return answer;
}