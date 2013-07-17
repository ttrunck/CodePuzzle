#include<iostream>
#include<vector>

using namespace std;

void power(const vector<int> & t, vector<int> & res){
  int s=t.size();
  int maj=0;
  for(int i=0;i<s;++i)
    maj+=t[i];
  maj=(maj+1)/2;

  for(int i=0;i<(1<<s);++i){
    int tmp=i;
    int values=0;
    for(int j=0;j<s;++j){
      if(tmp%2==1)
	values+=t[j];
      tmp/=2;
    }
    for(int j=0;j<s;++j){
      if((i>>j)%2==0)
	if(values<maj && values+t[j]>=maj)
	res[j]++;
    }
  }

}

int main(){
  int T;
  cin >> T;
  for(int icase=1;icase<=T;++icase){
    int P;
    cin >> P;
    vector<int> t(P);
    for(int i=0;i<P;++i)
      cin >> t[i];
    vector<int> res(P,0);
    power(t, res);
    for(int i=0;i<P;++i)
      cout << "party " << i+1 << " has power index " << res[i] << '\n'; 
    cout << '\n';
  }
}
