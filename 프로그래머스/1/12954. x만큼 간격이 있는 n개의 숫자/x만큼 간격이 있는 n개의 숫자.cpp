#include <string>
#include <iostream>
#include <vector>

using namespace std;

vector<long long> solution(int x, int n) {
    vector<long long> answer;
    int initialX = x;
    for(int i=0; i<n; i++){
        answer.push_back(x);
        x += initialX;
        
    }
    return answer;
}