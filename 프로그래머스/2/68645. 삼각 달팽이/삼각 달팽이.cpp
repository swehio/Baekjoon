#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n) {
    
    
    int sum = 0;
    
    for(int i = 1; i <= n; ++i)
    {
        sum += i;
    }
    
    vector<int> answer(sum, 0);
    
    int k = 0;
    int idx = 0;
    
    int cntNum = n-1;
    int cnt = cntNum;
    int type = 1;
    for(int i = 1; i <= sum; ++i)
    {
        if(i <= n)
        {
            idx += k;
            ++k;
        }
        else
        {
            switch(type)
            {
                case 0:
                    idx += k;
                    ++k;
                    break;
                case 1:
                    ++idx;   
                    break;
                case 2:       
                    idx -= k;
                    --k;
                    break;
                default:
                    break;
            }
            --cnt;
            if(cnt == 0)
            {
                --cntNum;
                cnt=cntNum;
                ++type;
                type %= 3;
            }
        }

        answer[idx] = i;
    }
    
    return answer;
}