#include<iostream>
#include<vector>
#include<cstdio>

using namespace std;

vector<int> t;
vector<int> t1;
vector<int> t2;;

int main(){
  t.push_back(0);
  for(int cas=0;cas<15;++cas){
    t1.clear();
    t2.clear();
    for(int i=0;i<t.size();++i){
      t1.push_back(t[i]*2);
      t2.push_back(t[i]*2+1);
    }
    t.clear();
    for(int i=0;i<t1.size();++i)
      t.push_back(t1[i]);
    for(int i=0;i<t2.size();++i)
      t.push_back(t2[i]);
  }

  int n;
  cin >> n;
  while(n!=0){
    cout << n << ':';
    for(int i=0;i<t.size();++i)
      if(t[i]<n)
	printf(" %d",t[i]);
    cout << endl;
    cin >> n;
  }

}
