#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

string solution(string s, string skip, int index) {
    string answer = s;
    for(char& ch : answer)
    {
        for(int i = 0; i<index; i++)
        {
            ch++;
            if(ch > 'z')
            {
                ch = 'a';
            }
            if(skip.find(ch) != string::npos)
            {
                i--;
            }

        }
    }
    return answer;
}