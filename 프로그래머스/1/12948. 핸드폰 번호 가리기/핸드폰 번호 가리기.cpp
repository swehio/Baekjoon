#include <string>
#include <vector>

using namespace std;

string solution(string phone_number) {
    string answer = "";
    for(int i = 0; i<phone_number.size()-4;i++){
        answer += "*";
    }
        for(int i = phone_number.size()-4; i<phone_number.size();i++){
        answer += phone_number[i];
    }
    
    
    return answer;
}