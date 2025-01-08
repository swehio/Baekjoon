#include <string>
#include <vector>
#include <algorithm>


using namespace std;

bool compare(int a, int b){
    return a < b;
}

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    vector<int> subArr;
    
    for(int i = 0; i<commands.size(); ++i){
        for(int j = commands[i][0]-1; j <= commands[i][1]-1 ; ++j){
            subArr.push_back(array[j]);
        }
        sort(subArr.begin(), subArr.end(), compare);
        answer.push_back(subArr[commands[i][2]-1]);
        subArr.clear();
    }
    
    return answer;
}