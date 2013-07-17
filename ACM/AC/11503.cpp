#include<iostream>
#include<map>
#include<string>

using namespace std;

int const N=200009;
int cmptmap=1;
map<string, int > m;
int t[N];
int nb[N];

int find(int n){
  if(t[n]==n) return n;
  int tmp=find(t[n]);
  t[n]=tmp;
  return tmp;
}

void fusion(int a,int b){
  int aa=find(a), bb=find(b);
  if(aa==bb) return;
  t[aa]=bb;
  nb[bb]+=nb[aa];
}

int main(){
  int cas;
  cin >> cas;
  while(cas--){
    int n;
    cin >> n;
    cmptmap=1;
    m.clear();
    for(int i=0;i<2*n;++i){
      t[i]=i;
      nb[i]=1;
    }
    
    for(int i=0;i<n;++i){
      string s1, s2;
      cin >> s1 >> s2;
      if(m[s1]==0)
	m[s1]=cmptmap++;
      if(m[s2]==0)
	m[s2]=cmptmap++;
      int f1=m[s1], f2=m[s2];
      fusion(f1,f2);
      cout << nb[find(f1)] << endl;
    }
  }
}
