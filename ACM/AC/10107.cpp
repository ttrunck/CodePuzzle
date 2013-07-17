#include<iostream>
#include<set>

using namespace std;

int med(const multiset<int> & s ){
  if(s.size()%2==1){
    multiset<int>::iterator it=s.begin();
    for(int i=0;i<(int(s.size())-1)/2;i++)
      it++;
    return *it;
  }
  else{
    multiset<int>::iterator it=s.begin();
    for(int i=0;i<(int(s.size())-1)/2;i++)
      it++;
    int res=*it;
    res+=*(++it);
    return res/2;
  }
}

int main(){
  multiset<int> s;
  int n;
  while(cin >> n){
    s.insert(n);
    cout << med(s) << '\n';
  }
}
