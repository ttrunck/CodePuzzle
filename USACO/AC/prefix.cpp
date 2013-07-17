/*
ID: blabla41
PROG: prefix
LANG: C++
 */

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

ofstream fout ("prefix.out");
ifstream fin ("prefix.in");

vector<string> prim;
string chaine;
bool res[2000001];

/*
int aux(int pos){
  int res=pos;
  for(int i=0;i<prim.size();++i){
    if (chaine.compare(pos,prim[i].size(),prim[i])==0)
      res= max(res, aux(pos+prim[i].size()));
  } 
  return res;
}
*/

int main(){
  string tmp;
  fin >> tmp;
  while(tmp!="."){
    prim.push_back(tmp);
    fin >>tmp;
    //cout << tmp << ' ';
  }
  fin >> chaine;
  while(fin >> tmp){
    chaine.append(tmp);
  }
  //cout << '\n' << chaine << '\n';

  for(int i=0;i<chaine.size();++i)
    res[i]=false;
  
  int paf=0;
  res[0]=true;
  for(int i=0;i<chaine.size()+1;++i){
    if(res[i]){
      paf= i;
      for(int j=0;j<prim.size();++j){
	if (chaine.compare(i,prim[j].size(),prim[j])==0){
	  res[i+prim[j].size()]=true;
	  //cout << i+prim[j].size() << endl;
	  //cout << i << ' ' << prim[j] << endl;
	}
      }
    }
  }
    fout << paf << endl;
    
  //fout << aux(0) << endl;

}
