#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(string s) {
    string answer = "";
    bool firstWord = true;
    cout << 'a'-'A' << endl;
    for(char& word : s)
    {
        if(word == ' ')
        {
            firstWord = true;
            continue;
        }        

        if(firstWord)
        {
            if(word >= 'a' && !(word >= '0' && word <='9'))
                word -= 'a'-'A';
            firstWord = false;
            continue;
        }
        if(word < 'a')
            word += 'a'-'A';
    }
    
    return s;
}