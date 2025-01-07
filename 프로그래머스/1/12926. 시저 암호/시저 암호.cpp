#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(string s, int n) {
    for(char &ch : s){
        if(ch == ' ')
            ch = ' ';
        else{
            for(int i = 0; i<n; ++i){
                ++ch;
                if(ch > 'z' || (ch < 'a' && ch > 'Z')){
                    ch = ch - ('z'-'a') -1;
                }
            }
        }
    }
    return s;
}