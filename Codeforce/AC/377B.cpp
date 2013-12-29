#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>

using namespace std;

typedef pair<int, int> pi;

struct st{
  int b,c,pos;
  st(int x=0,int y=0,int z=0):b(x), c(y), pos(z){};

  bool operator<(const st& x) const{
    return c>x.c;
  }
};

bool msort(const st& s1, const st& s2){
  return s1.b < s2.b;
}

struct bug{
  int a,pos;
  bug(int x=0,int y=0):a(x), pos(y){};

  bool operator<(const bug& b) const{
    return a<b.a;
  }
};

bool canSolve(int day, int s, const vector<st>& stud, const vector<bug>& bugs, vector<st>& res){
  res.clear();
  int currB=int(bugs.size())-1;
  int currS=int(stud.size())-1;
  priority_queue<st> q;
  while(currB>=0){
    while(currS>=0 && stud[currS].b>=bugs[currB].a){
      q.push(stud[currS]);
      --currS;
    }
    if(q.empty()) return false;
    st x=q.top();
    q.pop();
    s-=x.c;
    if(s<0) return false;
    res.push_back(st(x.b, x.c, x.pos));
    currB-=day;
  }
  return true;
}

int main(){
  int n, m, s;
  cin >> n >> m >> s;

  vector<int> a(m), b(n), c(n);
  for(int i=0;i<m;++i)
    cin >> a[i];
  for(int i=0;i<n;++i)
    cin >> b[i];
  for(int i=0;i<n;++i)
    cin >> c[i];

  vector<st> students(n);
  for(int i=0;i<n;++i)
    students[i]=st(b[i],c[i],i);
  sort(begin(students), end(students), msort);

  vector<bug> bugs(m);
  for(int i=0;i<m;++i)
    bugs[i]=bug(a[i], i);
  sort(begin(bugs), end(bugs));

  vector<st> res;

  canSolve(2, s,students, bugs, res);

  if(!canSolve(m+1, s,students, bugs, res)){
    cout << "NO\n";
    return 0;
  }

  int lo=1,hi=m+1;

  while(lo!=hi){
    int mid=(lo+hi)/2;
    if(canSolve(mid, s,students, bugs, res))
      hi=mid;
    else
      lo=mid+1;
  }

  //  if(lo!=1 && canSolve(lo-1, s,students, bugs, res))
  //  --lo;

  cout << "YES\n";
  vector<int> solution(m);

  canSolve(lo, s,students, bugs, res);

  int currB=m-1;
  int currS=0;
  while(currB>=0){
    for(int i=0;i<lo && currB>=0;++i){
      solution[bugs[currB].pos]=res[currS].pos+1;
      --currB;
    }
    ++currS;
  }

  cout << solution[0];
  for(int i=1;i<m;++i)
    cout << ' ' << solution[i];
  cout << '\n';

}
