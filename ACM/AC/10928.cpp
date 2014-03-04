#include<iostream>
#include<cmath>
#include<string>

using namespace std;

const int P=1009;
int t[P];

int main(){
  int cas;
  cin >> cas;
  while(cas--){
    for(int i=0;i<P;++i)
      t[i]=0;
    int mini=P;
    int p;
    cin >> p;
    string line;
    getline(cin, line);
    for(int i=1;i<=p;++i){

      getline(cin,line);
      //     cout << "line= " << line << endl;
      int res=1;
      for(int k=0;k<line.size();++k)
	if(line[k]==' ') res++;
      t[i]=res;
      mini=min(mini, t[i]);
    }
    bool first=true;
    for(int i=1;i<=p;++i){
      if(t[i]==mini){
	if(!first)
	  cout << ' ';
	first=false;
	cout << i;
      }
    }
    cout << endl;
    
  }
}
