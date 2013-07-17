#include<iostream>
#include<utility>
#include<vector>

using namespace std;

bool solved(int start, int n, int end1, vector<pair<int, int> > & t){
    if(n==0)
      return (start==end1);
    for(int i=0;i<int(t.size());++i){
      if(t[i].first==start){
	pair<int, int> tmp=t[i];
	t[i]=t[t.size()-1];
	t.pop_back();
	if(solved(tmp.second, n-1, end1, t))
	  return true;
	t.push_back(t[i]);
	t[i]=tmp;
      }
      else if(t[i].second==start){
	pair<int, int> tmp=t[i];
	t[i]=t[t.size()-1];
	t.pop_back();
	if(solved(tmp.first, n-1, end1, t))
	  return true;
	t.push_back(t[i]);
	t[i]=tmp;
      }
    }
    return false;
}

int main(){
  int n, m;
  while(cin >> n >> m &&(n||m)){
    int start1, start2, end1, end2;
    cin >> start1 >> start2 >> end1 >> end2;
    vector<pair<int, int> > t(m);
    for(int i=0;i<m;++i)
      cin >> t[i].first >> t[i].second;
    if(solved(start2, n, end1, t))
      cout << "YES\n";
    else
      cout << "NO\n";
  }
}
