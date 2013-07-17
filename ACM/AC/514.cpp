#include<iostream>
#include<stack>
#include<queue>

using namespace std;

int main(){
  int n;
  bool first;
  cin >> n;
  while(n!=0){
    stack<int> p;
    queue<int> q;
    for(int i=1;i<=n;++i){
      int tmp;
      cin >> tmp;
      if(tmp==0)
	goto paf;
      q.push(tmp);
      p.push(i);
      while(!p.empty() && !q.empty() && (p.top()==q.front())){
	p.pop();
	q.pop();
      }
    }
    if(p.empty() && q.empty())
      cout << "Yes" << endl;
    else 
      cout << "No" << endl; 
    continue;
    
  paf:
    cin >> n;
    cout << endl;
  }
}
