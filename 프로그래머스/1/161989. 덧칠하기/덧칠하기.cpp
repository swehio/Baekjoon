#include <string>
#include <vector>

using namespace std;

int solution(int n, int m, vector<int> section) 
{
    int answer = 0;
    int num = 0;
    bool check = false;
    int length = 0;
    for(int i = section[0]; i<=section[section.size()-1]; ++i)
    {
        if(section[num] == i)
        {
            if(!check)
            {
                ++answer;
                check = true;
            }
            ++num;    
            
        }
        if(check)
            ++length;
        if(length>=m)
        {
            length = 0;
            check=false;
        }


    }
    return answer;
}