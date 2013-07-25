#include<iostream>
#include<vector>

using namespace std;

void next(vector<int> & t){
  vector<int> tmp;
  int val=t[0];
  int nb=1;
  for(int i:t-{
    if(i==val)
      nb++;
    else{
      tmp.push_back(nb);
      tmp.push_back(val);
      val=i;
      nb=1;
    }
  }
  tmp.push_back(nb);
  tmp.push_back(val);
  t=tmp;
}

int main(){
  int n, l;
  cin >> n >> l;
  vector<int> t{n};
  for(int i=1;i<l;++i)
    next(t);
 
  for(int i:t)
    cout << i << ' ';
}
