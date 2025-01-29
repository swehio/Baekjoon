#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = 0;
    char x = s[0];
    int xCount = 0;
    int notXCount = 0;
    for(int i = 0; i<s.size();++i)
    {
        (s[i] == x) ? ++xCount : ++notXCount;
        if(xCount == notXCount)
        {
            x = s[i+1];
            xCount = 0;
            notXCount = 0;
            ++answer;
        }
    }
    if(xCount != 0)
        ++answer;
    return answer;
}