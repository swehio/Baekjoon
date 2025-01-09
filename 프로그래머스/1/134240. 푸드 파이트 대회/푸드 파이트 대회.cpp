#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<int> food) {
    string answer = "";
    string temp = "";
    for(int i = 1; i<food.size(); ++i){
        int num = food[i]&1 ? (food[i]-1)/2 : food[i]/2;
        for(int j = 0; j < num; ++j){
            temp += to_string(i);
        }
    }
    answer = temp + '0';
    reverse(temp.begin(), temp.end());
    answer += temp;
    return answer;
}