#include <string>
#include <vector>
#include <algorithm>

bool compare(int a, int b){
    return a>b;
}

using namespace std;

int solution(int k, int m, vector<int> score) {
    int answer = 0;
    int num = 0;
    sort(score.begin(), score.end(), compare);
    int min = 10;
    
    for(int fruit:score){
        if(fruit < min)     
            min = fruit;
        ++num;
        if(num > m-1){
            num = 0;
            answer += min * m;
            min = 10;
        }
    }
    
    return answer;
}