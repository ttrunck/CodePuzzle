#include<iostream>
#include<string>
#include<vector>

using namespace std;

int l;

void search(const string & s, const vector<string> t){
  int n=int(s.size());
  for(int i=0;i<l;++i)
    for(int j=0;j<l;++j){
     
      if(i+n<=l){
	bool ok=true;
	for(int k=0;k<n;++k)
	  ok=ok&&(t[i+k][j]==s[k]);
	if(ok){
	  cout << i+1 << ',' << j+1 << ' ' << i+n-1+1 << ',' << j+1 << '\n';
	  return;
	}
      }
      
      if(i+n<=l && j+n<=l){
	bool ok=true;
	for(int k=0;k<n;++k)
	  ok=ok&&(t[i+k][j+k]==s[k]);
	if(ok){
	  cout << i+1 << ',' << j+1 << ' ' << i+n-1+1 << ',' << j+n-1+1 << '\n';
	  return;
	}
      }
      
      if(j+n<=l){
	bool ok=true;
	for(int k=0;k<n;++k)
	  ok=ok&&(t[i][j+k]==s[k]);
	if(ok){
	  cout << i+1 << ',' << j+1 << ' ' << i+1 << ',' << j+n-1+1 << '\n';
	  return;
	}
      }

      if(i-n+1>=0 && j+n<=l){
	bool ok=true;
	for(int k=0;k<n;++k)
	  ok=ok&&(t[i-k][j+k]==s[k]);
	if(ok){
	  cout << i+1 << ',' << j+1 << ' ' << i+1-n+1 << ',' << j+n-1+1 << '\n';
	  return;
	}
      }

      if(i-n+1>=0){
	bool ok=true;
	for(int k=0;k<n;++k)
	  ok=ok&&(t[i-k][j]==s[k]);
	if(ok){
	  cout << i+1 << ',' << j+1 << ' ' << i+1-n+1 << ',' << j+1 << '\n';
	  return;
	}
      }

      if(i-n+1>=0 && j-n+1>=0){
	bool ok=true;
	for(int k=0;k<n;++k)
	  ok=ok&&(t[i-k][j-k]==s[k]);
	if(ok){
	  cout << i+1 << ',' << j+1 << ' ' << i+1-n+1 << ',' << j+1-n+1 << '\n';
	  return;
	}
      }
      
      if(j-n+1>=0){
	bool ok=true;
	for(int k=0;k<n;++k)
	  ok=ok&&(t[i][j-k]==s[k]);
	if(ok){
	  cout << i+1 << ',' << j+1 << ' ' << i+1 << ',' << j+1-n+1 << '\n';
	  return;
	}
      }

      if(i+n<=l && j-n+1>=0){
	bool ok=true;
	for(int k=0;k<n;++k)
	  ok=ok&&(t[i+k][j-k]==s[k]);
	if(ok){
	  cout << i+1 << ',' << j+1 << ' ' << i+1+n-1 << ',' << j+1-n+1 << '\n';
	  return;
	}
      }
      
    }

  cout << "Not found\n";
}

int main(){
  cin >> l;
  for(int icas=0;icas<l;++icas){
    vector<string> t(l);
    for(int i=0;i<l;++i)
      cin >> t[i];
    string s;
    while(cin >> s && s!="0"){
      search(s,t);
    }
  }
}
