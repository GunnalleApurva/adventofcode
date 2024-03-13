#include <bits/stdc++.h>
using namespace std;

void split ( string s , char delimeter , vector<string>& v){
    s.append(";");
    string temp;
    int i=0;
    while (s[i] != '\0') {
        if (s[i] != delimeter) {
            temp += s[i]; 
        } else {
          temp.erase(remove_if(temp.begin(), temp.end(), ::isspace),temp.end());
          v.push_back(temp);
          temp.clear();
        } i++;
    } 
    return;
}

int main()
{
    string str;
    vector<string> s;
    vector<vector<int> > v;
    int red=12,green=13,blue=14;
    int ans = 0;

    while (getline(cin, str))
    {
        if (str.empty())
        {
            break;
        }
        s.push_back(str.erase(0,8));
    }
    
    for (int i=0;i<s.size();i++)
    {
      string &it = s[i];
      // cout<<endl<<endl<<it<<endl;
      int game[3] = {0,0,0};
      vector<string> games ;
      split(it,';',games);
      for(int g=0;g<games.size();g++){
        // cout<<games[g]<<endl;
        int rp=-1,gp=-1,bp=-1;
        rp = games[g].find("red");
        if(rp>=0 && rp<= games[g].size()){
          int t = 0;
          t += (games[g][rp-1] - '0');
          if(isdigit(games[g][rp-2])){
            t += (games[g][rp-2]-'0')*10;
            game[0]=max(game[0],t);
          }
        }
        gp = games[g].find("green");
        if(gp>=0 && gp<= games[g].size()){
          int t=0;
          t += (games[g][gp-1] - '0');
          if(isdigit(games[g][gp-2])){
            t += (games[g][gp-2]-'0')*10;
            game[1] = max(game[1],t);
          }
        }
        bp = games[g].find("blue");
        if(bp>=0 && bp<= games[g].size()){
          int t=0;
          t += (games[g][bp-1] - '0');
          if(isdigit(games[g][bp-2])){
            t += (games[g][bp-2]-'0')*10;
            game[2] = max(game[2],t);
          }
        }
        // cout<<"red : "<<game[0]<<" green : "<<game[1]<<" blue : "<<game[2]<<endl;
      }
      if( game[0]<=red && game[1]<=green && game[2]<=blue ){
        // cout<<"inside if \n";
        ans += i+1;
      }
    }
    cout<<ans;
}
