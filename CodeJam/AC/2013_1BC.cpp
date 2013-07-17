#include<iostream>
#include<fstream>
#include<set>
#include<string>
#include<vector>

using namespace std;

int aux(const vector<string> & dico, const string & s, int pos, int erreur, vector<vector<int> > & mem){
  if(pos==int(s.size()))
    return 0;
  if(mem[pos][erreur]!=-1) return mem[pos][erreur];

  int res=1000;

  for(auto it=begin(dico); it!=end(dico);++it){

    if((*it).size()+pos>s.size())
      continue;
    int nb_erreur=0;
    int erreurcurr=erreur-5;
    bool good=true;
    for(int k=0;k<int((*it).size());++k)
      if((*it)[k]!=s[pos+k]){
	if(k-erreurcurr<5){
	  good=false;
	  break;
	}
	else{
	  erreurcurr=k;
	  nb_erreur++;
	}
      }

    if(!good)
      continue;

    res=min(res, nb_erreur+aux(dico, s, pos+(*it).size(), max(0,5-(int((*it).size())-erreurcurr)), mem));
  }
  mem[pos][erreur]=res;
  return res;
}

int main(){
  
  ifstream dict("dict.txt");
  vector<string> dico;
  string tmp;
  while(getline(dict, tmp))
    dico.push_back(tmp);
  
  int nbcase;
  cin >> nbcase;
  for(int icase=1;icase<=nbcase;++icase){
    cout << "Case #" << icase << ": ";
    string s;
    cin >> s;
    vector<vector<int> > mem(s.size(), vector<int>(6, -1));
    cout << aux(dico, s, 0, 0, mem) << '\n';
  }
}
