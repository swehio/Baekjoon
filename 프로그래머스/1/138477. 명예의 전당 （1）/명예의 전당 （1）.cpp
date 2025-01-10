#include <string>
#include <vector>
#include <algorithm>

using namespace std;
bool compare(int a, int b){
    return a > b;
}

vector<int> solution(int k, vector<int> score) {
    vector<int> answer;
    vector<int> honorList;
    
    for(int i=0; i<score.size();++i){
        honorList.push_back(score[i]);
        sort(honorList.begin(), honorList.end(), compare);
        if(i < k)
        {
            answer.push_back(honorList[i]);
        }
        else
        {
            answer.push_back(honorList[k-1]);
        }
    }
    return answer;
}