#include <string>
#include <vector>

using namespace std;

void swap(string& a, string& b){
    string temp = a;
    a = b;
    b = temp;
}

vector<string> solution(vector<string> strings, int n) {
    vector<string> answer = strings;
    
     for(int i = 0; i < strings.size(); ++i){
         for(int j = 0; j < strings.size(); ++j)
            if(answer[i][n] < answer[j][n]){
                swap(answer[i], answer[j]);
            }
            else if(answer[i][n] == answer[j][n]){
                if(answer[i] < answer[j]){
                    swap(answer[i], answer[j]);
                }
            }
     }
    
    return answer;
}