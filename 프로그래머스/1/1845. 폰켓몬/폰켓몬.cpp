#include <vector>
#include <unordered_set>
using namespace std;

int solution(vector<int> nums)
{
    int answer = 0;
    unordered_set<int> types;
    
    for(int num : nums)
    {
        types.insert(num);
    }
    
    if(types.size() >= nums.size()/2)
    {
        return nums.size()/2;
    }
    else
    {
        return types.size();
    }
    
    return answer;
}