#include <string>
#include <vector>

using namespace std;

string solution(string my_string, string overwrite_string, int s) {
    string answer = "";
    for(int i=0; i < my_string.size(); i++)
    {
        if(i==s)
        {
            answer += overwrite_string;
            i += overwrite_string.size();
        }
        if(i >= my_string.size())
        {
            break;
        }
        answer += my_string[i];

    }
    return answer;
}