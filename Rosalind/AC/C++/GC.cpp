#include<iostream>
#include<string>

using namespace std;

int main(){
  string res;
  double maxi=0;
  char tmp;
  string lab;
  cin >> tmp;
  while(cin >> lab){
    int nb=0,size=0;
    while(cin >> tmp && tmp!='>'){
      size++;
      if(tmp=='C' || tmp=='G') nb++;
    }
    double compt=(double)nb/(double)size;
    if(compt>maxi){
      maxi=compt;
      res=lab;
    }
  }
  cout << res << '\n';
  cout << maxi*100 << '%' << endl;
}
