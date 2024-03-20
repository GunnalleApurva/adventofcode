#include <bits/stdc++.h>
#include <climits>
#define ll long long int

using namespace std;

void simplifyInput(vector<ll>& inp, map<ll,ll>& m){
  cin >> inp[0] >> inp[1] >> inp[2];
        for (int j = 0; j < inp[2]; j++)
        {
            m.insert({inp[1]++, inp[0]++});
        }
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
    vector<ll> inp(3);
    vector<map<ll, ll>> m(7);
    ll nearestLoc = LLONG_MAX;
    
    for(int i=0;i<6;i++){
      for(int j=0;j<sizes[i];j++){
        simplifyInput(inp,m[i]);
      }
    }
    for (int i = 0; i < sizes[7]; i++)
    {
        cin >> inp[0] >> inp[1] >> inp[2];
        nearestLoc = min(nearestLoc,inp[0]);
        for (int j = 0; j < inp[2]; j++)
        {
            m[6].insert({inp[1]++, inp[0]++});
        }
    }

    ll key,value;

    for (auto &seed : seeds)
    {
      key = seed;
      for(int i=0;i<m.size();i++){
        value = key;
        if(m[i].find(key)!=m[i].end()){
          value = m[i][key];
          key = value;
        }
      }
        nearestLoc = min(nearestLoc, value);
    }
    
    cout << nearestLoc;
}
