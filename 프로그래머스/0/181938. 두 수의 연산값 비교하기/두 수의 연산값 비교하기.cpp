#include <string>
#include <vector>

using namespace std;

int solution(int a, int b) {
    int answer = 0;
    int appendab = stoi(to_string(a)+to_string(b));
    
    if(appendab >= 2*a*b)
        answer = appendab;
    else
        answer = 2*a*b;
        
    return answer;
}