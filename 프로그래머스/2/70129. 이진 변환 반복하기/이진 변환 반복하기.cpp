#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <iostream>

using namespace std;

int removeZeroNum = 0;

string transeNum(const string& str){
    removeZeroNum += count(str.begin(), str.end(), '0');
    stringstream ss(str);
    string token;
    string newStr = "";
    while(getline(ss, token, '0'))
        newStr += token;
    
    int newStrLength = newStr.size();
    
    string binaryTrans = "";
    while(newStrLength > 0)
    {
        binaryTrans += to_string(newStrLength % 2);
        newStrLength = newStrLength / 2;
    }
    reverse(binaryTrans.begin(), binaryTrans.end());
    return binaryTrans;
    
}

vector<int> solution(string s) {
    vector<int> answer;
    int tryNum = 0;
    string result = s;
    
    while (result.size() > 1)
    {
        result = transeNum(result);
        tryNum++;
    }
    
    answer = {tryNum, removeZeroNum};
    
    return answer;
}