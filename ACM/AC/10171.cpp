#include<iostream>
#include<vector>
#include<limits>

using namespace std;

const int INF=numeric_limits<int>::max();

int main(){
  int n;
  while(cin >> n && n!=0){
    vector<vector<int> > old(26, vector<int>(26,INF));
    vector<vector<int> > young(26, vector<int>(26,INF));
    for(int i=0;i<26;++i)
      old[i][i]=young[i][i]=0;

    for(int i=0;i<n;++i){
      char a,b,c,d;
      int cost;
      cin >> a >> b >> c >> d >> cost;
      if(a=='Y'){
	young[c-'A'][d-'A']=min(cost, young[c-'A'][d-'A']);
	if(b=='B')
	  young[d-'A'][c-'A']=min(cost, young[d-'A'][c-'A']);
      }
      else{
	old[c-'A'][d-'A']=min(cost, old[c-'A'][d-'A']);
	if(b=='B')
	  old[d-'A'][c-'A']=min(cost, old[d-'A'][c-'A']);
      }
    }

    for(int k=0;k<26;++k)
      for(int i=0;i<26;++i)
	for(int j=0;j<26;++j)
	  if(young[i][k]!=INF && young[k][j]!=INF)
	    young[i][j]=min(young[i][j], young[i][k]+young[k][j]);

 for(int k=0;k<26;++k)
      for(int i=0;i<26;++i)
	for(int j=0;j<26;++j)
	  if(old[i][k]!=INF && old[k][j]!=INF)
	    old[i][j]=min(old[i][j], old[i][k]+old[k][j]);

    char U, M;
    cin >> U >> M;

    int mini=INF;
    vector<int> res;

    for(int i=0;i<26;++i)
      if(young[U-'A'][i]!=INF && old[M-'A'][i]!=INF && young[U-'A'][i]+old[M-'A'][i]<mini){
	mini=young[U-'A'][i]+old[M-'A'][i];
	res=vector<int>(1,i);
      }
      else if(young[U-'A'][i]!=INF && old[M-'A'][i]!=INF && young[U-'A'][i]+old[M-'A'][i]==mini)
	res.push_back(i);

    if(mini!=INF){
      cout << mini;
      for(int i=0;i<int(res.size());++i)
	cout << ' ' << char('A'+res[i]);
      cout << '\n';
    }
    else
      cout << "You will never meet.\n";

  }
}
