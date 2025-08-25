#include <bits/stdc++.h>

using namespace std;

map<int, int> m;
queue<int> a;
queue<int> b;

int main()
{
   ios::sync_with_stdio(0);
   cin.tie(0);
   
   int N, M;
   cin >> N >> M;
   
   while(N--)
   {
       int num;
       cin >> num;
       
       a.push(num);
   }
   while(M--)
   {
       int num;
       cin >> num;
       
       b.push(num);
   }
   
  while(!a.empty()||!b.empty())
  {
      if(b.empty()) 
      {
          cout << a.front() << ' ';
          a.pop();
          continue;
      }
      if(a.empty()) 
      {
          cout << b.front() << ' ';
          b.pop();
          continue;
      }
      if(a.front() <= b.front())
      {
          cout << a.front() << ' ';
          a.pop();
      }
      else
      {
          cout << b.front() << ' ';
          b.pop();
      }
  }
}