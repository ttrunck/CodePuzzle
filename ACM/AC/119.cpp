#include<iostream>
#include<vector>
#include<string>
#include<map>

using namespace std;

int main(){
  bool first=true;
  int n;
    
    while(cin >> n){
    vector<string> name;
    name.resize(n);
    map<string, int> money;
    for(int i=0;i<n;++i){
      cin >> name[i];
      money[name[i]]=0;
    }

    for(int i=0;i<n;++i){
      string giver;
      cin >> giver;
      int val, nb;
      cin >> val >> nb;
      for(int j=0;j<nb;++j){
	string tmp;
	cin >> tmp;
	money[tmp]+=val/nb;
	money[giver]-=val/nb;
      }
    }

    if(first)
      first=false;
    else
      cout << endl;

    for(int i=0;i<n;++i)
      cout << name[i] << ' ' << money[name[i]] << endl;
    
  }
}
