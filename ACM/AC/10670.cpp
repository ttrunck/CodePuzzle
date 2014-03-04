#include<iostream>
#include<string>
#include<cstdio>
#include<map>
#include<vector>
#include<algorithm>

using namespace std;

map<string, int> mmap;
vector<string> t;

void parser(string const & ss, string & s, int & a, int & b){
  int curr=0;
  while(ss[curr]!=':'){
    s.push_back(ss[curr]);
    curr++;
  }
  curr++;
  a=0;
  while(ss[curr]!=','){
    a=a*10+ss[curr]-'0';
    curr++;
  }
 curr++;
  b=0;
  while(curr<ss.size()){
    b=b*10+ss[curr]-'0';
    curr++;
  }
}

int cost(int n, int m, int a, int b){
  if(n==m) return 0;
  if(n/2>=m && a*(n-n/2)>b) return cost(n/2,m,a,b)+b;
  return cost(n-1,m,a,b)+a;
}

bool mysort(string a, string b){
  return (mmap[a]<mmap[b] || (mmap[a]==mmap[b] && a<b));
}

int main(){
  int Cas;
  cin >> Cas;
  for(int cas=1;cas<=Cas;++cas){
    int N, M, L;
    cin >> N >> M >>L;

    mmap.clear();
    t.clear();

    for(int l=0;l<L;++l){
      string ss;
      cin >> ss;
      string s;
      int a,b;
      parser(ss,s,a,b);
      int c=cost(N,M,a,b);
      mmap[s]=c;
      t.push_back(s);
    }
    
    sort(t.begin(), t.end(), mysort);
 
    cout << "Case " << cas << endl;
    for(int i=0;i<t.size();++i)
      cout << t[i] << ' ' << mmap[t[i]] << endl;

  }
}
