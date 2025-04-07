#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

void splitRecord(const string& recordToSplit, string& act, string& id, string& name)
{
    string word = "";
    for(char ch : recordToSplit)
    {
        if(ch != ' ')
        {
            word += ch;
        }
        else
        {
            if(act.empty())
                act = word;
            else
            {
                if(id.empty())
                    id = word;
            }
            word = "";
        }
    }
    if(id.empty())
        id = word;
    else
        name = word;
}

vector<string> solution(vector<string> records) {
    vector<string> answer;
    vector<pair<string, string>> printActions;
    unordered_map<string, string> uidInfo;
    
    for(string record : records)
    {
        string action = "";
        string uid = "";
        string nickName = "";
        
        splitRecord(record, action, uid, nickName);
        
        
        if(action == "Enter")
        {
            printActions.push_back(make_pair(action ,uid));
            uidInfo[uid] = nickName;
        }
        else if(action == "Leave")
        {
            printActions.push_back(make_pair(action, uid));
        }
        else if(action == "Change")
        {
            uidInfo[uid] = nickName;
        }
    }
    
    for(pair<string, string> act : printActions)
    {
        if(act.first == "Enter")
        {
            answer.push_back(uidInfo[act.second]+"님이 들어왔습니다.");
        }
        else
        {
            answer.push_back(uidInfo[act.second]+"님이 나갔습니다.");
        }    
    }
    
    return answer;
}