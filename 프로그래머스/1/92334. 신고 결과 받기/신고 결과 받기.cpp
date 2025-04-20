#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <sstream>
#include <iostream>

using namespace std;

vector<int> solution(vector<string> id_list, vector<string> reports, int k) {
    vector<int> answer;
    unordered_map<string, int> listReported;
    unordered_map<string, vector<string>> listReporting;
    
    for(string report : reports)
    {
        stringstream ss(report);
        string reporting, reported;
        ss >> reporting >> reported;
        
        if(find(listReporting[reporting].begin(), listReporting[reporting].end(), reported) == listReporting[reporting].end())
        {
            listReported[reported]++;
            listReporting[reporting].push_back(reported);
        }
    }
    
    for(string id : id_list)
    {
        int mailNum = 0;
        
        for(string reported : listReporting[id])
        {
            //cout << *it << listReported[*it] << endl;
            if(listReported[reported] >= k)
            {
                mailNum++;
            }
        }
        //cout << mailNum << endl;
        answer.push_back(mailNum);
    }
    
    return answer;
}