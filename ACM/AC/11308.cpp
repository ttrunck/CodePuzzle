#include<iostream>
#include<string>
#include<map>
#include<vector>
#include<algorithm>

using namespace std;

map<string,int> recipice;

bool mysort(string a, string b){
  return (recipice[a]<recipice[b] || (recipice[a]==recipice[b] && a<b));
}

int main(){
  int cas;
  cin >> cas;
  while(cas--){
    string title;
    getline(cin, title);
    getline(cin, title);
    for(int i=0;i<title.size();++i)
      title[i]=toupper(title[i]);
    int n,m,b;
    cin >> m >> n >> b;
    map<string, int> ingredient;
    for(int i=0;i<m;++i){
      string s;
      int c;
      cin >> s >> c;
      ingredient[s]=c;
    }

    recipice.clear();
    vector<string> tab;
    for(int i=0;i<n;++i){

      string name;
      getline(cin, name);
      getline(cin, name);
      int cost=0;
      int d;
      cin >> d;
      for(int j=0;j<d;++j){
	string ing;
	int nb;
	cin >> ing >> nb;
	cost+=nb*ingredient[ing];
      }
      recipice[name]=cost;
      tab.push_back(name);
    }
    sort(tab.begin(),tab.end(), mysort);
    cout << title << endl;
    for(int i=0;i<tab.size();++i)
      if(recipice[tab[i]]<=b)
	cout << tab[i] << endl;
      else{
	if(i==0)
	  cout << "Too expensive!" << endl;
	i=tab.size();
      }
    cout << endl;


  }
}
