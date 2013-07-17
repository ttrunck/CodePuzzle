#include<iostream>
#include<vector>


using namespace std;

vector<int> dou;
vector<int> nor;

vector<int> check;

int main(){
  for(int i=1;i<=20;++i){
    nor.push_back(i);
    nor.push_back(i*2);
    nor.push_back(i*3);
    dou.push_back(i*2);
  }
  dou.push_back(50);
  nor.push_back(25);
  nor.push_back(50);
  nor.push_back(0);

  for(int i=0;i<dou.size();++i)
    for(int j=0;j<nor.size();++j)
      for(int k=j;k<nor.size();++k)
	check.push_back(dou[i]+nor[j]+nor[k]);

  int res=0;
  for(int i=0;i<check.size();++i)
    if(check[i]<100)++res;

    cout << res << '\n';
}
