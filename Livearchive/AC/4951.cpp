#include<iostream>
#include<queue>

using namespace std;

typedef pair<int, int> pi;

int main(){
  ios::sync_with_stdio(false);
  int nbcase;
  cin >> nbcase;
  while(nbcase--){
    int n;
    cin >> n;
    priority_queue<pi> ask;
    priority_queue<pi> bid;
    int price=-1;

    for(int i=0;i<n;++i){
      string order, trash;
      int nb, val;
      cin >> order >> nb >> trash >> trash >> val;
      if(order=="buy")
	bid.push(pi(val, nb));
      else
	ask.push(pi(-val, nb));
      
      while(!ask.empty() && !bid.empty() && -ask.top().first<=bid.top().first){
	pi pask = ask.top();
	pask.first=-pask.first;
	pi pbid = bid.top();
	ask.pop();
	bid.pop();
	price = pask.first;
	if(pbid.second<pask.second)
	  ask.push(pi(-pask.first, pask.second-pbid.second));
	else
	  bid.push(pi(pbid.first, pbid.second-pask.second));

	while(!ask.empty() && ask.top().second==0)
	  ask.pop();
	while(!bid.empty() && bid.top().second==0)
	  bid.pop();
      }

      if(!ask.empty())
	cout << -ask.top().first;
      else
	cout << '-';
      cout << ' ';
      if(!bid.empty())
	cout << bid.top().first;
      else
	cout << '-';
      cout << ' ';
      if(price!=-1)
	cout << price;
      else
	cout << '-';
      cout << '\n';
    }
  }
}
