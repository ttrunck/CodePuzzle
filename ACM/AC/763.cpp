#include<iostream>
#include<string>
#include<vector>
#include<sstream>
#include<cmath>

using namespace std;

vector<int> sum(const string & a, const string & b){
  vector<int> t(max(a.size(), b.size())+5,0);
  for(int i=0;i<int(a.size());++i)
    t[int(a.size())-i]+=a[i]-'0';
 for(int i=0;i<int(b.size());++i)
    t[int(b.size())-i]+=b[i]-'0';

 bool cont=true;
 while(cont){
   cont=false;
   if(t[0]==1){
     t[0]=0;
     t[1]+=1;
     cont=true;
   }
   for(int i=1;i<int(t.size())-1;++i){
     if(t[i]==1 && t[i-1]==1){
       t[i+1]+=1;
       t[i]=t[i-1]=0;
       cont=true;
     }
     if(t[i]==2){
       t[i]=0;
       t[i+1]+=1;
       if(i-2>=0)
	 t[i-2]+=1;
       cont=true;
     }
   }
 }

 for(int i=int(t.size())-1;i>1 && t[i]==0;--i)
   t.pop_back();

  return t;
}

ostream& operator<<(ostream & flux, const vector<int> & t){
  for(int i=int(t.size())-1;i>0;--i)
    flux << t[i];
  return flux;
}

int main(){
  string a,b;
  bool first=true;
  while(cin >> a >> b){
    if(!first) cout << '\n';
    first=false;
    cout << sum(a,b) << '\n';
  }
}
