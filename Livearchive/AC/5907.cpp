#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<map>

using namespace std;

map<char, int> puis; 

void print(int n, const vector<string>& t){
  bool first=true;
   for(int i=0;i<13;++i){
     if(n%2==1){
       if(!first)
	 cout << ' ';
       first=false;
       cout << t[i];
     }
     n/=2;
   }
}

bool is_same_card(const vector<string>& t){
  for(int i=1;i<int(t.size());++i)
    if(t[i][0]!=t[0][0])
      return false;
  return true;
}

bool is_full(const vector<string>& t){
  return (t[0][0]==t[1][0] && t[2][0]==t[3][0] && t[2][0]==t[4][0]) ||
    (t[0][0]==t[1][0] && t[0][0]==t[2][0] && t[3][0]==t[4][0]);
}

bool mysort(const string& a, const string& b){
  return puis[a[0]]<puis[b[0]];
}

char pred(char c){
  if(c=='2')
    return '1';
 if(c=='3')
    return '2';
 if(c=='4')
    return '3';
 if(c=='5')
    return '4';
 if(c=='6')
    return '5';
 if(c=='7')
    return '6';
 if(c=='8')
    return '7';
 if(c=='9')
    return '8';
 if(c=='T')
    return '9';
 if(c=='J')
    return 'T';
 if(c=='Q')
    return 'J';
 if(c=='K')
    return 'Q';
 else
   return 'K';
}

bool is_straight(const vector<string>& t){
for(int i=1;i<int(t.size());++i)
  if(pred(t[i][0])!=t[i-1][0])
      return false;
 return true;
}


bool aux(const int mask, const vector<string>& t){
  int nb=0;
  int mm=mask;
  vector<string> jeu;
  for(int i=0;i<13;++i){
    if(mm%2==1){
      nb++;
      jeu.push_back(t[i]);
    }
    mm/=2;
  }
  
  if(nb==0)
    return false;
  if(nb==1)
    return true;
  if(nb>1 && nb<5 && is_same_card(jeu))
    return true;
  if(nb==5 && is_full(jeu))
    return true;
  return (nb>=5 && is_straight(jeu));
}

int backtrack(int mask, vector<int>& mem, vector<int>& used, const vector<int> valid){
  if(mask==0)
    return 0;
  if(mem[mask]!=-1) return mem[mask];

  int res=1000;
  for(int i=0;i<int(valid.size());++i){
    if((mask&valid[i])==valid[i]){
      int tmp = backtrack(mask-valid[i], mem, used, valid);
      if(tmp+1<res){
	res=tmp+1;
	used[mask]=valid[i];
      }
    }
  }
  return mem[mask]=res;
}

int main(){
  puis['2']=0;
  puis['3']=1;
  puis['4']=2;
  puis['5']=3;
  puis['6']=4;
  puis['7']=5;
  puis['8']=6;
  puis['9']=7;
  puis['T']=8;
  puis['J']=9;
  puis['Q']=10;
  puis['K']=11;
  puis['A']=12;


  int nbcase;
  cin >> nbcase;
  while(nbcase--){
    vector<string> t(13);
    for(int i=0;i<13;++i)
      cin >> t[i];
    
    sort(t.begin(), t.end(), mysort);
    
    vector<int> valid;

    for(int i=1;i<(1<<13);++i)
      if(aux(i,t))
	valid.push_back(i);

    /*
    for(auto i:valid){
      print(i, t);
      cerr << endl;
    }
    */

    vector<int> mem(1<<13,-1);
    vector<int> used(1<<13);
    int res = backtrack((1<<13)-1, mem, used, valid);

    cout << res << '\n';
    
    int curr=(1<<13)-1;
    while(curr!=0){
      print(used[curr], t);
      cout << endl;
      curr=curr-used[curr];
    }
  }
}
