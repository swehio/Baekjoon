#include <string>
#include <iostream>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> answer;
    int min = 0;
    
    for(int i = 0; i < arr.size(); i++){
        if(arr.size() == 1){
            answer.push_back(-1);
            break;
        }
        else{
            if(arr[min] > arr[i]){
                min = i;
            }
        }
    }
    
    for(int i = 0; i<arr.size(); i++){
        if(i == min)
            continue;
        answer.push_back(arr[i]);
    }
    
    return answer;
}