#include <string>
#include <vector>
#include <iostream>

using namespace std;

string toNum(const string &str){
    if(str == "zero")
        return "0";
    else if(str == "one")
        return "1";
    else if(str == "two")
        return "2";
    else if(str == "three")
        return "3";
    else if(str == "four")
        return "4";
    else if(str == "five")
        return "5";
    else if(str == "six")
        return "6";
    else if(str == "seven")
        return "7";
    else if(str == "eight")
        return "8";
    else if(str == "nine")
        return "9";
    else
        return "";
}

using namespace std;

int solution(string s) {
    string answer = "";
    string temp ="";
    for(auto ch : s){
        if(!isdigit(ch)){
            temp += ch;
            if(toNum(temp) != ""){
                answer += toNum(temp);
                temp = "";
            }

        }
        else{
            answer += ch;
        }
    }
    return stoll(answer);
}