#include <string>
#include <vector>

using namespace std;

string solution(int n) {
    string answer = "";
    
    for(int i = 0; i<n; i++){
        answer += i%2 == 0 ? "수" : "박";
    }
    
    return answer;
}