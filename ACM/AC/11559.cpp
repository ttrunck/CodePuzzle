#include<iostream>

using namespace std;

const int MAXI=100000000;

int main(){
  int n, b, h, w;
  while(cin >> n >> b >> h >> w){
    int mini=MAXI;
    for(int i=0;i<h;++i){
      int cost;
      cin >> cost;
      for(int j=0;j<w;++j){
	int disp;
	cin >> disp;
	if(disp>=n && n*cost<=b)
	  mini=min(mini, n*cost);
      }
    }
    if(mini==MAXI)
      cout << "stay home\n";
    else
      cout << mini << '\n';
  }
}
