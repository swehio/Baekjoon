#include <string>
#include <vector>
#include <iostream>
#include <map>

using namespace std;

string solution(int a, int b) {
    string answer = "";
    map<int, string> weekend;
    int month = 1;
    int day = 1;
    int week = 5;
    
    weekend[0] = "SUN";
    weekend[1] = "MON";
    weekend[2] = "TUE";
    weekend[3] = "WED";
    weekend[4] = "THU";
    weekend[5] = "FRI";
    weekend[6] = "SAT";
    
    while(1)
    {
        if(month == a && day == b)
            break;
        if(month == 2)
        {
            if(day >= 29){
                ++month;
                day = 0;
            } 

        }
        else if (month < 8)
        {
            if(month % 2 != 0)
            {
                if(day >= 31){
                    ++month;
                    day = 0;
                }
            }
            else
            {
                if(day >= 30){
                    ++month;
                    day = 0;
                }
            }
        }
        else
        {
            if(month % 2 != 0)
            {
                if(day >= 30){
                    ++month;
                    day = 0;
                }
            }
            else
            {
                if(day >= 31){
                    ++month;
                    day = 0;
                }
            }
        }
        ++day;
        ++week;        
        week = week%7;

    }
    answer = weekend[week];
    return answer;
    
}