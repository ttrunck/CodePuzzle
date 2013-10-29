#include<iostream>
#include<vector>

using namespace std;

typedef long long ll;

int const N=1000000000;

ll pow(ll a, ll b){
  if(b==0) return 1;
  ll tmp=pow(a,b/2);
  tmp*=tmp;
  return tmp*(b%2==0?1:a);
}

ll som(int a){
  int res=0;
  for(int i=1;i<=a;++i)
    res+=i;
  return res;
}

ll aux(vector<int> & b){
  int last=b.back();
  b.pop_back();
  ll res=0;
  if(b.empty()){
    res=som(last);
  }
  else{
    res=som(last)*pow(28, int(b.size()));
    res+=(last+1)*aux(b);
  }
  return res;
}

int main(){
  int n=N;
  vector<int> b;
  while(n){
    b.push_back(n%7);
    n/=7;
  }
  
  cout << aux(b) << '\n';
}
