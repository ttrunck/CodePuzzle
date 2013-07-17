#include<iostream>
#include<string>
#include<vector>
#include<sstream>

using namespace std;

void easy(int d, double p, const vector<double> & s){
  if(s[0]>p){
    cout << "The spider is going to fall!\n";
    return;
  }
  if(s[d]<p){
    cout << "The spider may fall!\n";
    return;
  }
  int res=d;
  while(s[res]>p) res--;
  cout << d-res << '\n';
}

int main(){
  string data;
  while(getline(cin,data)){
    stringstream s(data);
    int D, P;
    s >> D >> P;
    vector<double> S;
    int tmp;
    while(s >> tmp)
      S.push_back(tmp);
    
    if(int(S.size())!=D+1){
    //completer s
      S.resize(D+1);
      double a=S[0], b=S[1], c=S[2], d=S[3];
      if(a*c-b*b==0){
	for(int i=4;i<D+1;++i)
	  S[i]=((a!=0)?b/a:0)*S[i-1];
      }
      else{
	double det=a*c-b*b;
	double aa=c, bb=-b, cc=-b, dd=a;
	double alpha=(c*aa+d*bb)/det, beta=(c*cc+d*dd)/det;
	
	//		cerr << det << ' ' << aa << ' ' << bb << ' ' << cc << ' ' << dd << ' ' << alpha << ' ' << beta << endl;
	for(int i=4;i<D+1;++i)
	  S[i]=(min(alpha*S[i-2]+beta*S[i-1], 1009.));
      }
    }

    /*   
    for(int i=0;i<int(S.size());++i)
      cerr << S[i] << ' ';
    cerr << endl;
    */
    
    easy(D,P,S);
}
}
