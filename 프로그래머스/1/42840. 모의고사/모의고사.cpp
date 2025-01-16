#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int correctAnswer(int* pattern, int patternSize, vector<int> answers){
    int correct = 0;

    for(int i = 0; i< answers.size();++i){
        if(pattern[i%patternSize] == answers[i])
            ++correct;
    }
    
    return correct;
}

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    int one[] = {1, 2, 3, 4, 5};
    int two[] = { 2, 1, 2, 3, 2, 4, 2, 5};
    int three[] = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};
    
    vector<int> correct;
    
    correct.push_back(correctAnswer(one, 5, answers));
    correct.push_back(correctAnswer(two, 8, answers));
    correct.push_back(correctAnswer(three, 10, answers));

    
    int maxNum = max_element(correct.begin(), correct.end()) - correct.begin()+1;
    answer.push_back(maxNum);
    
    int maxIndex = maxNum - 1;
    for(int i = 0; i<correct.size();++i){
        if(correct[maxIndex] == correct[i] && i!= maxIndex)
            answer.push_back(i+1);
    }
    
    sort(answer.begin(), answer.end());
    return answer;
}