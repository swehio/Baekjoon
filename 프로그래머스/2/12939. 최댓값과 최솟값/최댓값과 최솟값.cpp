#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(string s) {
    string answer = "";
    vector<int> nums;
    string sNum = "";
    s += " ";
    
    for(int i = 0; i < s.size(); ++i)
    {
        if(s[i] == ' ')
        {
            int inputNum = 0;
            if(sNum[0] == '-')
            {
                inputNum = -1 * stoi(sNum.substr(1));
            }
            else
            {
                inputNum = stoi(sNum);
            }
            nums.push_back(inputNum);
            sNum = "";
            continue;
        }
        sNum += s[i];
    }
    
    
    int min = nums[0];
    int max = nums[0];
    
    for(int num : nums)
    {
        if(min > num)
        {
            min = num;
        }
        if(max < num)
        {
            max = num;
        }
    }
    
    answer += to_string(min) + " ";
    answer += to_string(max);
    return answer;
}