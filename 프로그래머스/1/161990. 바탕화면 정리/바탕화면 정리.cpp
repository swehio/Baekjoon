#include <string>
#include <vector>

using namespace std;
vector<int> solution(vector<string> wallpaper) {
    vector<int> answer;
    int minX = 51;
    int maxX = -1;
    int minY = 51;
    int maxY = -1;
    
    for(int i = 0; i<wallpaper.size(); i++)
    {
        for(int j = 0; j<wallpaper[0].size(); j++)
        {
            if(wallpaper[i][j] == '#')
            {
                if(i < minX) minX = i;
                if(j < minY) minY = j;
                if(i+1 > maxX) maxX = i+1;
                if(j+1 > maxY) maxY = j+1;
            }
        }
    }
    
    answer.push_back(minX);
    answer.push_back(minY);
    answer.push_back(maxX);
    answer.push_back(maxY);
    return answer;
}