#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

double compute(const vector<int>& t){
  double res=0;
  double curr=1;
  bool same=true;
  for(int n:t){
    if(n%2!=t[0]%2)
      same=false;
    if(!same)
      curr*=2;    
    res+=((n%2==0)?1.:-1.)/curr;
  }
  return res;
}

int main(){
  int nbcase;
  cin >> nbcase;
  while(nbcase--){
    int p;
    cin >> p;
    vector<vector<int> > t_full(p);
    for(int i=0;i<p;++i){
      int ni;
      cin >> ni;
      if(ni==0){
	--p;
	t_full.pop_back();
      }
      else{
	for(int j=0;j<ni;++j){
	  int tmp;
	  cin >> tmp;
	  t_full[i].push_back(tmp);
	}
	sort(begin(t_full[i]), end(t_full[i]));
	t_full[i].resize(distance(begin(t_full[i]), unique(begin(t_full[i]), end(t_full[i]))));
      }
    }


    double res=0;

    for(auto t:t_full)
      res+=compute(t);

    if(res==0)
      cout << "DON'T PLAY\n";
    else if(res<0)
      cout << "ODD\n";
    else
      cout << "EVEN\n";

  }
}
