#include<iostream>
#include<utility>
#include<vector>

using namespace std;

void pv(vector<pair<int,int> > t){
    for(int i=0;i<int(t.size());++i)
      cout << t[i].first << ',' << t[i].second << ' ';
    cout << endl;
  }

int main(){
  int R;
  cin >> R;
  for(int r=1;r<=R;++r){
    int b;
    cin >> b;
    vector<int> t(b);
    for(int i=0;i<b-1;++i)
      cin >> t[i];

    vector<pair<int,int> > m(b);
    m[0]=make_pair(0,0);
    for(int i=1;i<b;++i){
      if(m[i-1].first>=0)
	m[i]=make_pair(t[i-1]+m[i-1].first, m[i-1].second);
      else
	m[i]=make_pair(t[i-1], i-1);
    }
    //   pv(m);
    int val=0, ires=0, jres=0;
    for(int i=0;i<b;++i)
      if(m[i].first>val || (m[i].first==val && i-m[i].second>jres-ires)){
	val=m[i].first;
	ires=m[i].second;
	jres=i;
      }

    if(ires!=jres)
      cout << "The nicest part of route " << r << " is between stops " << ires+1 << " and " << jres+1 << endl;
    else
      cout << "Route " << r << " has no nice parts" << endl;




  }
}
