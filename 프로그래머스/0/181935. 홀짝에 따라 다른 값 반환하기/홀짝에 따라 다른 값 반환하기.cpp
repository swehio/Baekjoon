#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    if(n % 2 == 0)
    {
        for(int i=0; i<=n ;i+=2)
            answer += i*i;
    }
    else
        for(int i =1; i<=n; i+=2)
            answer += i;
    
    return answer;
}