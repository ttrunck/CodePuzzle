#include<iostream>
#include<utility>
#include<vector>
#include<algorithm>

using namespace std;

typedef pair<char,char> card;

vector<card> hand1;
vector<card> hand2;

int value(card a){
 char aa=a.first;
  int aaa;
  if(aa=='A') aaa=14;
  else if(aa=='K') aaa=13;
  else if(aa=='Q') aaa=12;
  else if(aa=='J') aaa=11;
  else if(aa=='T') aaa=10;
  else aaa=aa-'0';
  return aaa;
}

bool comp(card a, card b){
  return value(a)>value(b);
}

void print_hand(vector<card> hand){
  for(int i=0;i<hand.size();++i)
    cout << hand[i].first << hand[i].second << ' ';
  cout << '\n';
}

bool is_flush(vector<card> hand){
  for(int i=1;i<hand.size();++i)
    if(hand[i].second!=hand[0].second) return false;
  return true;
}

bool is_straight(vector<card> hand){
  for(int i=1;i<hand.size();++i)
    if(value(hand[i])+1!=value(hand[i-1])) return false;
  return true;
}

bool is_four(vector<card> hand){
  int tab[20];
  for(int i=0;i<20;++i)
    tab[i]=0;
  for(int i=0;i<hand.size();++i)
    tab[value(hand[i])]++;

  for(int i=0;i<20;++i)
    if(tab[i]==4) return true;
  return false;
}

bool is_full(vector<card> hand){
  int tab[20];
  for(int i=0;i<20;++i)
    tab[i]=0;
  for(int i=0;i<hand.size();++i)
    tab[value(hand[i])]++;

  bool p=false, b=false;

  for(int i=0;i<20;++i){
    if(tab[i]==3)  b=true;
    if(tab[i]==2) p=true;
  }
  return p&&b;
}

bool is_two_pair(vector<card> hand){
  int tab[20];
  for(int i=0;i<20;++i)
    tab[i]=0;
  for(int i=0;i<hand.size();++i)
    tab[value(hand[i])]++;

  bool p=false;

  for(int i=0;i<20;++i){
    if(tab[i]==2){
      if(!p)  p=true;
      else return true;
    }
  }
  return false;
}

bool is_three(vector<card> hand){
  int tab[20];
  for(int i=0;i<20;++i)
    tab[i]=0;
  for(int i=0;i<hand.size();++i)
    tab[value(hand[i])]++;

  for(int i=0;i<20;++i)
    if(tab[i]==3) return true;
  return false;
}

int is_pair(vector<card> hand){
  int tab[20];
  for(int i=0;i<20;++i)
    tab[i]=0;
  for(int i=0;i<hand.size();++i)
    tab[value(hand[i])]++;

  for(int i=0;i<20;++i)
    if(tab[i]==2) return i;
  return -1;
}


int best(vector<card> hand){
  if(is_flush(hand) && is_straight(hand)){
    //cout << "quinte fleche\n";
    return 10;
  }
  if(is_four(hand)){
    //cout << "carre\n";
    return 9;
  }
  if(is_full(hand)){
    //cout << "full\n";
    return 8;
  }
  if(is_flush(hand)){
    //cout << "couleur\n";
    return 7;
  }
  if(is_straight(hand)){
    //cout << "suite\n";
    return 6;
  }
  if(is_three(hand)){
    //cout << "brelan\n";
    return 5;
  }
  if(is_two_pair(hand)){
    //cout << "deux paires\n";
    return 4;
  }
  if(is_pair(hand)!=-1){
    //cout << "paire\n";
    return 3;
  }
  //cout << "rien\n";
  return 2;
}

int win(vector<card> a, vector<card> b){
  int p1=best(a), p2=best(b);
  
  if(p1>p2) return 1;
  if(p2>p1) return 2;
  
  if(p1==3){
    if(is_pair(a)>is_pair(b)) return 1;
    if(is_pair(b)>is_pair(a)) return 2;
  }
  
  if(p1==2){
    for(int i=0;i<a.size();++i){
      if(value(a[i])>value(b[i])) return 1;
      if(value(b[i])>value(a[i])) return 2;
    }
  }

  print_hand(a);
  print_hand(b);
  cout << "Putain je fais quoi là\n";
  return 0;
}

int main(){
  int res=0;
  card tmp;
  while(cin >> tmp.first >> tmp.second){
    hand1.push_back(tmp);
    for(int i=0;i<4;++i){
      cin >> tmp.first >> tmp.second;
      hand1.push_back(tmp);
    }
    for(int i=0;i<5;++i){
      cin >> tmp.first >> tmp.second;
      hand2.push_back(tmp);
    }
    sort(hand1.begin(),hand1.end(),comp);
    sort(hand2.begin(),hand2.end(),comp);

    if(win(hand1,hand2)==1)
      res++;
    hand1.clear();
    hand2.clear();
  }

  cout << res << '\n';
}
