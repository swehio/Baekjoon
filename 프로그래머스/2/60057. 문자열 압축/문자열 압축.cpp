#include <bits/stdc++.h>

using namespace std;

int mn = 0xfffffff; 

int solution(string s) { 
    
    int size = (int)s.size();
    for(int i=1; i<=size; i++)
    { 
        int tot=0;
        int cnt=0;
        int j=0;
        string str="";
        while(1)
        {
            if(j>size)
            {
                if(cnt!=1) tot+=to_string(cnt).size();
                tot+=str.size(); 
                break;
            }
            string newstr = s.substr(j, i); 
            if(str!=""&&str!=newstr)
            {
                if(cnt!=1) tot+=to_string(cnt).size();
                tot+=str.size();
                
                cnt=0;
            } 
            cnt++;
            str=newstr;
            j+=i;
        }    
        
        mn = min(mn, tot);
    } 
    return mn;
}