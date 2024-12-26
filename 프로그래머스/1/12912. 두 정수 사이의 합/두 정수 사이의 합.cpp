#include <string>
#include <vector>

using namespace std;

long long solution(int a, int b) {
    long long answer = 0;
    int lower = 0;
    int higher = 0;
    if(a<b){
        lower = a;
        higher = b;
    }

    else{
        lower = b;
        higher = a;
    }
    
    for(int i= lower; i<=higher ; i++){
        answer += i;
    }
    return answer;
}