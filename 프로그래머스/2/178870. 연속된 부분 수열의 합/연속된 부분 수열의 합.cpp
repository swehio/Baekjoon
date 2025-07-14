#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> sequence, int k) {
    vector<int> answer(2, 0);
    int sum = 0;
    int cnt = 0;
    vector<vector<int>> indexList;
    
    for(int i = 0; i < sequence.size(); ++i)
    {
        sum += sequence[i];
        ++cnt;

        if(sum > k)
        {
            while(sum > k)
            {
                sum -= sequence[i-cnt+1];
                cnt--;
            }
        }
        if(sum == k)
        {
            vector<int> idxPair(2, 0);
            idxPair[0] = i-cnt+1;
            idxPair[1] = i;
            indexList.push_back(idxPair);
        }
    }
    
    int minDiffIdx = 0;
    int minDiff = indexList[0][1] - indexList[0][0];
    for(int i = 1; i < indexList.size(); ++i)
    {
        int diff = indexList[i][1] - indexList[i][0];
        if(minDiff > diff)
        {
            minDiff = diff;
            minDiffIdx = i;
        }
    }
    answer = {indexList[minDiffIdx][0], indexList[minDiffIdx][1]};
    
    return answer;
}