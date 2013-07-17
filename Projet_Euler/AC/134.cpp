//quite slow, use chiness remainder to speed this up

#include<iostream>
#include<vector>

using namespace std;

typedef long long ent;
const int N=1000000;
const int lim=2000000;


void sieve(vector<bool> &crossed, int limit) {
	crossed.assign(limit / 2, false);
	crossed[0] = true;
	for (int i = 1; 4 * i * i < limit; ++i)
		if (not crossed[i])
			for (int j = 2 * i * (i + 1); 2 * j < limit; j += 2 * i + 1)
				crossed[j] = true;
}

bool isPrime(vector<bool> &crossed, int i) {
	if (i == 2) return true;
	if (i % 2 == 0) return false;
	return not crossed[(i - 1) / 2];
}

ent aux(ent p1, ent p2, ent & nb){
  while(p1/nb!=0){
    nb*=10;
    clog << "nb= " << nb << endl;
  }
  ent i=1;
  while((i*p2)%nb!=p1) ++i;
  return i*p2;
}

int main(){
  vector<bool> p;
  ent res=0;
  ent nb=10;
  sieve(p, lim);
  clog << "gen completed\n";
  for(int p1=5;p1<N;)
    if(isPrime(p,p1)){
      int p2=p1+2;
      while(!(isPrime(p,p2)))p2+=2;
      res+=aux(p1, p2, nb);
      p1=p2;
      //cerr << p1 << ' ' << p2 << endl;
    }
  cout << res << endl;
}
