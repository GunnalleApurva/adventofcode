#include <bits/stdc++.h>
#include <climits>
#define ll long long int
using namespace std;

vector<ll> inp(3);
void takeInput(int size, vector<vector<ll>> & vi){
  for(int s=0;s<size;s++){
  cin >> inp[0] >> inp[1] >> inp[2];
  vi.push_back(inp);
  }
}

ll findValue(vector<vector<vector<ll>>>v,ll seed){
  ll key=seed,value=seed;
  for(int i=0;i<7;i++){
    value=key;
    for(int row=0;row<v[i].size();row++){
      if(key>=v[i][row][1] && key<=(v[i][row][1]+v[i][row][2]-1)){
        value = v[i][row][0] + (key-v[i][row][1]);
      }
    }
    key = value;
  } 
  return value;
}

int main()
{
    vector<ll> seeds(20);
    // vector<ll> seeds(4);
    for (int i = 0; i < seeds.size(); i++)
    {
        cin >> seeds[i];
    }

    int sizes[] = {36,24,34,46,29,30,38};
    // int sizes[] = {2,3,4,2,3,2,2};
    ll nearestLoc = LLONG_MAX;
    
    vector<vector<vector<ll>>>v(7);
    for(int i=0;i<7;i++){
      takeInput(sizes[i],v[i]);
    }
    
    ll key,value;
    
    for(auto & seed : seeds){
      key = seed;
      value = findValue(v,key);
      nearestLoc = min(nearestLoc,value);
    }
    cout << nearestLoc;
}
