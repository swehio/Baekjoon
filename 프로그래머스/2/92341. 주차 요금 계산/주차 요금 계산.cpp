#include <string>
#include <vector>
#include <queue>
#include <map>
#include <sstream>
#include <iostream>
#include <cmath>

using namespace std;

int getSumTime(string in, string out)
{
    int inHour = stoi(in.substr(0, 2));
    int inMin = stoi(in.substr(2, 2));
    int outHour = stoi(out.substr(0, 2));
    int outMin = stoi(out.substr(2, 2));
    cout << inHour << inMin << outHour << outMin << endl;
    if(inMin > outMin)
    {
        --outHour;
        outMin += 60;
    }
    
    return (outMin - inMin) + (outHour - inHour) * 60;
    
}

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    map<string, queue<string>> carLecordList;
    
    for(string record : records)
    {
        stringstream ss(record);
        
        string time;
        string carNum;
        while(ss >> time >> carNum)
        {
            time.replace(2, 1, "");
            carLecordList[carNum].push(time);
        }
    }
    
    for(auto it = carLecordList.begin(); it != carLecordList.end(); ++it)
    {
        queue<string> times = it->second;
        string inTime= "";
        string outTime= "";
        
        if(times.size() % 2 != 0)
        {
            times.push("2359");
        }
        
        int SumTime = 0;
        while(times.size() > 0)
        {
            inTime = times.front();
            times.pop();
            outTime = times.front();
            times.pop();

            SumTime += getSumTime(inTime, outTime);
        }

        if(SumTime > fees[0])
        {
            int fee = fees[1] + ceil((float)(SumTime - fees[0])/fees[2])*fees[3];
            answer.push_back(fee);
        }
        else
            answer.push_back(fees[1]);
    }
    
    return answer;
}