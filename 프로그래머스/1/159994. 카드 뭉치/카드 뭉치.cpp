#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

string solution(vector<string> cards1, vector<string> cards2, vector<string> goal) {
    string answer = "";
    vector<string> goalCopy = goal;
    int i = 0;
    int j = 0;
    int k = 0;
    while(true){
        if(k == goal.size()){
            answer = "Yes";
            break;
        }
        if(goalCopy[k] == cards1[i]){
            ++i;
        }
        else{
            if(goalCopy[k] == cards2[j]){
                ++j;
            }
            else{
                answer = "No";
                break;
            }
        }
        ++k;
        

        
        
    }
    
    return answer;
}