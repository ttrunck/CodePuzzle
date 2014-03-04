#include<iostream>
#include<cstdio>

using namespace std;

int const N=200000;

int base;
int n;
int tt[N];
int t[2*N];
int next[N];

void add(int i, int x){
  t[base+i]=x;
  int p=(base+i)/2;
  while(p!=0){
    t[p]=max(t[p*2], t[p*2+1]);
    p/=2;
  }
}

int maxi(int a, int b){
  if(next[a]>b)
    return b-a+1;

  int res=max(next[a]-a, b-(next[b]-tt[b]-1));
  int aa=(base+next[a]);  
  int bb=(base+next[b]-tt[b]-1);  
  
  // cout << aa-base << ' ' << bb-base << ' ' << res << endl;

  if(aa>=bb) return res;
  res=max(res,t[aa]);
  res=max(res,t[bb]);
  while(aa/2!=bb/2){
    if((aa/2)*2+1!=aa)
      res=max(res, t[(aa/2)*2+1]);
    aa/=2;
    if((bb/2)*2!=bb)
      res=max(res, t[(bb/2)*2]);
    bb/=2;
  }
  return res;
}

int print(){
  for(int i=1;i<2*base;++i)
    cout << t[i] << ' ';
  cout << endl;
}

int main(){
  int q;
  cin >> n;
  while(n){
    cin >> q;
    int pred, curr=0, f=1;
     cin >> pred;
     
     for(int i=1;i<n;++i){
       int tmp;
       cin >> tmp;
       if(tmp==pred)
	 f++;
       else{
	 for(int j=curr;j<i;++j){
	   tt[j]=f;
	   next[j]=i;
	 }
	 curr=i;
	 f=1;
	 pred=tmp;
       }
    }
     for(int j=curr;j<n;++j){
       tt[j]=f;
       next[j]=n;
     }

     base=1;
     while(base<n) base*=2;
     for(int i=1;i<2*base+10;++i)
       t[i]=-N;
     for(int i=0;i<n;++i)
       add(i, tt[i]);

     for(int i=0;i<q;++i){
       int a,b;
       scanf("%d %d", &a, &b);
       printf("%d\n", maxi(a-1, b-1));
     }
     cin >> n;
  }
}
