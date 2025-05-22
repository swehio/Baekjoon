#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, long long left, long long right) {
    vector<int> answer;
        
    for(long long i = left; i<=right; ++i)
    {
        int row = i / n;
        int column = i % n;
        int value = 0;
        
        if(row < column)
        {
            value = column+1;
        }
        else
        {
            value = row+1;
        }
        
        answer.push_back(value);
    }
            
    return answer;
}