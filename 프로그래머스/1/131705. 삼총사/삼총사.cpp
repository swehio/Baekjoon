#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(vector<int> number) {
    int answer = 0;
    int sum = 0;
    for(int i = 0; i< number.size(); ++i){
        for(int j = i+1; j<number.size();++j){
            for(int k = j+1; k<number.size(); ++k){
                sum = 0;
                sum += number[i]+number[j]+number[k];
                if(sum == 0)
                    ++answer;
            }
        }
    }
    
    return answer;
}