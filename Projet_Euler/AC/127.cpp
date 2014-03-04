#include<iostream>
#include<vector>

using namespace std;

typedef long long ent;

const int N=120000;

int gcd(int a, int b){
  return b==0?a:gcd(b, a%b);
}

bool rad(int a, int b, int c, const vector<ent> & t_rad){
  ent res=t_rad[a]*t_rad[b];
  if(res>=c) return false;
  res*=t_rad[c];
  return res<c;
}

int main(){
  vector<ent> t_rad(N+1,1);
  vector<bool> p(N+1,true);
  p[0]=false;
  p[1]=false;
  for(int i=2;i<=N;++i)
    if(p[i]){
      t_rad[i]*=i;
      for(int j=i+i;j<=N;j+=i){
	p[j]=false;
	t_rad[j]*=i;
      }
    }


  ent res=0;
  for(int c=1;c<N;++c)
    if(t_rad[c]>=c) continue;
    else{
      for(int a=0;a<=c/2;++a){
	int b=c-a;
	if(a>=b || gcd(a,b)!=1) continue;
	if(rad(a,b,c,t_rad)){
	  cerr << "a,b,c= " << a << ' ' << b << ' ' << c << '\n';
	  cerr << "t_rad a,b,c= " << t_rad[a] << ' ' << t_rad[b] << ' ' << t_rad[c] << '\n';
	  cerr << "t_rad abc= " << t_rad[a]*t_rad[b]*t_rad[c] << '\n';
	  res+=c;
	}
      }
    }

  cout << res << '\n';
}

/*
Résultat à tester: 18407904
 */
