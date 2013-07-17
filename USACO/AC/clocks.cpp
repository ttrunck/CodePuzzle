/*
ID: blabla41
PROG: clocks
LANG: C++
 */

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>

using namespace std;

int const N= 270000;
int tab[10];
int etat;
pair<int,int> visite[N];

void to_etat(){
  etat=0;
  for(int i=0;i<9;++i){
    etat*=4;   
    etat+=tab[i]%4;
  }
  //cout << etat << endl;
}

void to_tab(){
  int tmp=etat;
  for(int i=8;i>=0;--i){
    tab[i]=etat % 4;
    etat/=4;
  }
  etat=tmp;
}

void aff_tab(){
  for(int i=0;i<3;++i){
    for(int j=0;j<3;++j)
      cout << tab[3*i+j] << ' ';
	cout << '\n';
  }
}
int main(){
  ofstream fout ("clocks.out");
  ifstream fin ("clocks.in");

  for(int i=0;i<N;++i)
    visite[i]=make_pair(-1,-1);

  int plop;
  for(int i=0;i<9;++i){
    fin >> plop;
    tab[i]= (plop%12)/3;
  }

  to_etat();
  visite[etat]=make_pair(0,0);
  
  int tmp;
  queue<int> q;
  q.push(etat);


  while( visite[0].first==-1){
    tmp=q.front();
    q.pop();

    etat=tmp;
    to_tab();
    tab[0]++;
    tab[1]++;
    tab[3]++;
    tab[4]++;
    to_etat();
    if (visite[etat].first==-1){
      visite[etat]=make_pair(1,tmp);
      q.push(etat);
    }

    etat=tmp;
    to_tab();
    tab[0]++;
    tab[1]++;
    tab[2]++;
    to_etat();
    if (visite[etat].first==-1){
      visite[etat]=make_pair(2,tmp);
      q.push(etat);
    }

 etat=tmp;
    to_tab();
    tab[1]++;
    tab[2]++;
    tab[4]++;
    tab[5]++;
    to_etat();
    if (visite[etat].first==-1){
      visite[etat]=make_pair(3,tmp);
      q.push(etat);
    }

 etat=tmp;
    to_tab();
    tab[0]++;
    tab[3]++;
    tab[6]++;
    to_etat();
    if (visite[etat].first==-1){
      visite[etat]=make_pair(4,tmp);
      q.push(etat);
    }

 etat=tmp;
    to_tab();
    tab[1]++;
    tab[3]++;
    tab[4]++;
    tab[5]++;
    tab[7]++;
    to_etat();
    if (visite[etat].first==-1){
      visite[etat]=make_pair(5,tmp);
      q.push(etat);
    }

 etat=tmp;
    to_tab();
    tab[2]++;
    tab[5]++;
    tab[8]++;
    to_etat();
    if (visite[etat].first==-1){
      visite[etat]=make_pair(6,tmp);
      q.push(etat);
    }

 etat=tmp;
    to_tab();
    tab[3]++;
    tab[4]++;
    tab[6]++;
    tab[7]++;
    to_etat();
    if (visite[etat].first==-1){
      visite[etat]=make_pair(7,tmp);
      q.push(etat);
    }

 etat=tmp;
    to_tab();
    tab[6]++;
    tab[7]++;
    tab[8]++;
    to_etat();
    if (visite[etat].first==-1){
      visite[etat]=make_pair(8,tmp);
      q.push(etat);
    }

 etat=tmp;
    to_tab();
    tab[4]++;
    tab[5]++;
    tab[7]++;
    tab[8]++;
    to_etat();
    if (visite[etat].first==-1){
      visite[etat]=make_pair(9,tmp);
      q.push(etat);
    }

  }

  stack<int> aff;
  int etat_curr=0;
  while(visite[etat_curr].first!=0){
    aff.push(visite[etat_curr].first);
    etat_curr= visite[etat_curr].second;
  }

  fout << aff.top();
  aff.pop();
  while(!aff.empty()){
    fout << ' ' << aff.top();
    aff.pop();
  }
  fout << endl;
}
  
