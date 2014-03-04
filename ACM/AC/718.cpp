#include<iostream>
#include<vector>
#include<utility>
#include<stack>
#include<cmath>

typedef long long ent;

using namespace std;

ent ceil(ent x,ent y){
  if(x>0)
    return (x+y-1)/y;
  else
    return x/y;
}

ent floor(ent x, ent y){
   if(x>0)
     return x/y;
  else
    return (x-y+1)/y;
}

void gcd(ent a, ent b, ent & x, ent & y, ent & d){
  if(b==0){
    x=1;
    y=0;
    d=a;
  }
  else{
    ent xx;
    gcd(b, a%b, xx, x, d);
    y=xx-x*(a/b);
  }
}

bool match(ent a, ent y1, ent b, ent y2, ent f){
  if(y2<y1) return match(b,y2,a,y1,f);
  // cerr << "Init: " << a << ' ' << y1 << ' ' << b << ' ' << y2 << ' ' << f << endl;
  ent c=y2-y1;
  ent x,y,d;
  gcd(a,b,x,y,d);
  // cerr << "GCD1: " << a << '*' << x << '+' << b << '*' << y << '=' << d << '\n';  
if(c%d!=0) return false;
  //ax+by=d
  x*=(c/d);
  y*=(c/d);
  //ax+by=c;
  // cerr << "GCD2: " << a << '*' << x << '+' << b << '*' << y << '=' << c << '\n';  
  ent inf=max(ceil(-x*d,b),ceil(y*d,a));
  ent sup=floor((f-y1-a*x)*d,a*b);
  // cerr << "InfSup " << inf << ' ' << sup << endl; 
  return sup>=inf;
}

bool acc(ent start, ent end, const vector<vector<ent> > & t){
  vector<bool> visited(end+1,false);
  stack<ent> q;
  q.push(start);
  visited[start]=true;
  while(!q.empty()){
    ent curr=q.top();
    q.pop();
    if(curr==end) return true;
    for(ent i=0;i<ent(t[curr].size());++i)
      if(!visited[t[curr][i]]){
	q.push(t[curr][i]);
	visited[t[curr][i]]=true;
      }
  }
  return false;
}

int main(){
  /*
  ent x,y,d;
  ent a=14,b=18;
  gcd(a,b,x,y,d);
  cout << a << '*' << x << '+' << b << '*' << y << '=' << d << '\n';
  */
  ent n;
  cin >> n;
  while(n--){
    ent f,e,a,b;
    cin >> f >> e >> a >> b;
    f--;
    vector<pair<ent, ent> > t(e);
    for(ent i=0;i<e;++i)
      cin >> t[i].first >> t[i].second;

    vector<vector<ent> > g(e+2);
    for(ent i=0;i<e;++i){
      if(a>=t[i].second && ((a-t[i].second)%t[i].first)==0){
	g[e].push_back(i);
	g[i].push_back(e);
      }
      if(b>=t[i].second && ((b-t[i].second)%t[i].first)==0){
	g[e+1].push_back(i);
	g[i].push_back(e+1);
      }
    }
    
    for(ent i=0;i<e;++i)
      for(ent j=i+1;j<e;++j)
	if(match(t[i].first, t[i].second, t[j].first, t[j].second ,f)){
	  //	  cerr << "matching entre " << i+1 << ' ' << j+1 << endl;
	  g[i].push_back(j);
	  g[j].push_back(i);
	}

    if(acc(e,e+1,g))
      cout << "It is possible to move the furniture.\n";
    else
      cout << "The furniture cannot be moved.\n";
  }
}
