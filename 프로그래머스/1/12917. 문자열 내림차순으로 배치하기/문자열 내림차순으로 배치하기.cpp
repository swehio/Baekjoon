#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = s;

    for(int i = 0; i<answer.size(); ++i){
        int temp = 0;
        for(int j = i+1; j<answer.size(); ++j){
            if(answer[i]<answer[j]){
                temp =answer[i];
                answer[i] = answer[j];
                answer[j] = temp;
            }
        }
    }
    return answer;
}