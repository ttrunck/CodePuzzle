#include<iostream>
#include<string>
#include<vector>

using namespace std;

typedef long long ll;

int main(){
  string s;
  cin >> s;

  int n=s.size();

  if(n==1){
    cout << "1\n";
    return 0;
  }

  vector<bool> t(n, false);

  for (int i=1;i<n;++i)
    if(s[i]-'0'+s[i-1]-'0'==9)
      t[i-1]=true;

  ll curr= t[0]?1:0;  
  ll res=1;
  for(int i=1;i<n;++i){
    if(t[i])
      ++curr;
    else{
      if (curr>0 && curr%2==0)
	res*=curr/2+1;
      curr=0;
    }
  }
  cout << res << endl;
}

