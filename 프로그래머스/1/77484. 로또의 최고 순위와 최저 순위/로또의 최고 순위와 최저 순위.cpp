#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int lottoRank(int num)
{
    switch(num)
    {
        case 6:
            return 1;
        case 5: 
            return 2;
        case 4:
            return 3;
        case 3:
            return 4;
        case 2:
            return 5;
        default:
            return 6;
    }            
}

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;
    int rightCount = 0;
    int zeroCount = 0;
    
    for(int win_num : win_nums)
    {
        auto it = find(lottos.begin(), lottos.end(), win_num);
        if(it != lottos.end())
        {
            ++rightCount;
        }
    }
    
    for(int lotto : lottos)
    {
        if(lotto == 0)
        {
            ++zeroCount;
        }
    }
    
    answer.push_back(lottoRank(rightCount+zeroCount));
    answer.push_back(lottoRank(rightCount));
    
    //lottos에 있는 숫자 중 맞은 개수
    //0인 숫자 다 맞은 경우
    //0인 숫자 다 틀린 경우
    //0인 숫자의 경우 더해서 최고 / 최저 개수
    //등수 변환
    return answer;
}