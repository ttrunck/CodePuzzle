#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> p3;
vector<int> p4;
vector<int> p5;
vector<int> p6;
vector<int> p7;
vector<int> p8;

void init_3(){
  for(int i=1;i*(i+1)/2<10000;++i)
    if(i*(i+1)/2>=1000) p3.push_back(i*(i+1)/2);
}

void init_4(){
  for(int i=1;i*i<10000;++i)
    if(i*i>=1000) p4.push_back(i*i);
}

void init_5(){
  for(int i=1;i*(3*i-1)/2<10000;++i)
    if(i*(3*i-1)/2>=1000) p5.push_back(i*(3*i-1)/2);
}

void init_6(){
  for(int i=1;i*(2*i-1)<10000;++i)
    if(i*(2*i-1)>=1000) p6.push_back(i*(2*i-1));
}

void init_7(){
  for(int i=1;i*(5*i-3)/2<10000;++i)
    if(i*(5*i-3)/2>=1000) p7.push_back(i*(5*i-3)/2);
}

void init_8(){
  for(int i=1;i*(3*i-2)<10000;++i)
    if(i*(3*i-2)>=1000) p8.push_back(i*(3*i-2));
}

void aux(vector<int> tab,bool b3, bool b4, bool b5, bool b6, bool b7, int nb){

  /*for(int i=0;i<tab.size();++i)
    cout << tab[i] << ' ';
  cout << '\n';
  */
  if(nb==5)
    if(tab[nb]%100==tab[0]/100){
      int res=0;
      for(int i=0;i<tab.size();++i){
	res+=tab[i];
	cout << tab[i] << ' ';
      }
      cout << '\n' << res << '\n';
    }

  if(!b3)
    for(int i=0;i<p3.size();++i)
      if(tab[nb]%100==p3[i]/100){
	vector<int> tmp;
	tmp.resize(tab.size());
	copy(tab.begin(),tab.end(),tmp.begin());
	tmp.push_back(p3[i]);
	aux(tmp,true,b4,b5,b6,b7,nb+1);
      }

if(!b4)
    for(int i=0;i<p4.size();++i)
      if(tab[nb]%100==p4[i]/100){
	vector<int> tmp;
	tmp.resize(tab.size());
	copy(tab.begin(),tab.end(),tmp.begin());
	tmp.push_back(p4[i]);
	aux(tmp,b3,true,b5,b6,b7,nb+1);
      }

if(!b5)
    for(int i=0;i<p5.size();++i)
      if(tab[nb]%100==p5[i]/100){
	vector<int> tmp;
	tmp.resize(tab.size());
	copy(tab.begin(),tab.end(),tmp.begin());
	tmp.push_back(p5[i]);
	aux(tmp,b3,b4,true,b6,b7,nb+1);
      }

if(!b6)
    for(int i=0;i<p6.size();++i)
      if(tab[nb]%100==p6[i]/100){
	vector<int> tmp;
	tmp.resize(tab.size());
	copy(tab.begin(),tab.end(),tmp.begin());
	tmp.push_back(p6[i]);
	aux(tmp,b3,b4,b5,true,b7,nb+1);
      }

 if(!b7)
    for(int i=0;i<p7.size();++i)
      if(tab[nb]%100==p7[i]/100){
	vector<int> tmp;
	tmp.resize(tab.size());
	copy(tab.begin(),tab.end(),tmp.begin());
	tmp.push_back(p7[i]);
	aux(tmp,b3,b4,b5,b6,true,nb+1);
      }
  
}

int main(){
  init_3();
  init_4();
  init_5();
  init_6();
  init_7();
  init_8();

  for(int i=0;i<p8.size();++i){
    vector<int> tab;
    tab.push_back(p8[i]);
    aux(tab,false,false,false,false,false,0);
  }
}
