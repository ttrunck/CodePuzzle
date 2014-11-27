#include <algorithm>
#include <array>
#include <cassert>
#include <cmath>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <utility>
#include <vector>

using namespace std;

typedef pair<int, int> pi;

const int INF = 1000000000;

int playerCount;  // the amount of players (2 to 4)
int myId;  // my player ID (0, 1, 2 or 3)

int platinum;  // my available Platinum

int n;  // the amount of zones on the map
int m;  // the amount of links between all zones

vector<int> platiniumSource;  // the amount of Platinum per zone
vector<int> owner;  // the player who owns this zone (-1 otherwise)
array<vector<int>, 4> pods;  // player PODs on this zone

vector<vector<int>> g;
vector<vector<int>> dist;

vector<bool> conquise;
vector<int> connexe;

double computePotentiel(int);

class engine{
    map<pi, int> buffer;

    int go(int start, int dest) {
        vector<int> next;
        for (int v : g[start])
            if (dist[start][dest] == 1 + dist[v][dest])
                next.push_back(v);

        int res = next[0];
        double potentiel = computePotentiel(res);
        for (int v : next) {
            double tmp = computePotentiel(v);
            if (tmp > potentiel) {
                res = v;
                potentiel = tmp;
            }
        }

        return res;
    }

 public:
    void move(int start, int dest) {
        if (start != dest) {
            int next = go(start, dest);
            ++buffer[{start, next}];
            if (start != n)
                --pods[myId][start];
            ++pods[myId][next];
        }
    }

    void display() {
        bool fwait = true;
        bool swait = true;
        for (const auto& p : buffer)
            if (p.first.first != n) {
                fwait = false;
                cout << p.second << ' ';
                cout << p.first.first << ' ' << p.first.second << ' ';
            }
        if (fwait)
            cout << "WAIT";
        cout << '\n';

        for (const auto& p : buffer)
            if (p.first.first == n) {
                swait = false;
                cout << p.second << ' ' << p.first.second << ' ';
            }
        if (swait)
            cout << "WAIT";
        cout << endl;
        buffer.clear();
    }
};

engine daEngine;

void readState() {
    cin >> platinum;
    for (int i = 0; i < n; ++i) {
        int zId;
        cin >> zId;
        cin >> owner[zId];
        cin >> pods[0][zId] >> pods[1][zId] >> pods[2][zId] >> pods[3][zId];
    }
}

template<typename T>
void BFS(int start, vector<int>& t, T f) {
    t[start] = f(-1);
    queue<int> q;
    q.push(start);
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        for (int v : g[x])
            if (t[v] == INF) {
                t[v] = f(t[x]);
                q.push(v);
            }
    }
}

void updateSpawn() {
    g[n].clear();
    for (int i = 0; i < n; ++i)
        if (owner[i] == -1 || owner[i] == myId)
            g[n].push_back(i);
    dist[n].assign(n+1, INF);
    BFS(n, dist[n], [](int x){return x+1;});
}

// THE FUNCTIONS WITH THE MAGIC TUNING

double computePotentiel(int v) {
    if (conquise[connexe[v]])
            return -INF;

    double potentiel = 0;

    double risk = 0;
    if (owner[v] == -1) {
        risk = playerCount;
    } else {
        set<int> st;
        for (int u : g[v])
            for (int i = 0; i < playerCount; ++i)
                if (pods[i][u] > 0)
                    st.insert(i);
        st.erase(myId);
        risk = st.size();
    }

    if (owner[v] == myId && risk == 0)
        return -INF;

    potentiel -= risk * exp(-(6-platiniumSource[v]));
    potentiel += platiniumSource[v];
    if (owner[v] == myId)
        potentiel *= 0.01;
    else if (playerCount == 2 && owner[v] != -1)
        potentiel *= 2;
    for (int i = 0; i < 4; ++i)
        potentiel -= 5 * pods[i][v];

    return potentiel;
}

void play(int x) {
    int dest;
    double score = -INF;

    for (int v = 0; v < n; ++v) {
        if (dist[x][v] == INF)
            continue;
        double tmp = static_cast<double>(rand()) / RAND_MAX;
        tmp += computePotentiel(v);
        tmp /= max(1, dist[x][v]);

        if (tmp > score) {
            score = tmp;
            dest = v;
        }
    }

    if (score != -INF)
        daEngine.move(x, dest);
}

int main() {
    cin >> playerCount >> myId >> n >> m;
    g.resize(n+1);
    platiniumSource.resize(n);
    owner.resize(n);
    pods[0].resize(n);
    pods[1].resize(n);
    pods[2].resize(n);
    pods[3].resize(n);
    for (int i = 0; i < n; i++) {
        int zoneId;
        cin >> zoneId;
        cin >> platiniumSource[zoneId];
    }
    for (int i = 0; i < n; ++i)
        g[i].push_back(i);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    // COMPUTE ALL DISTANCE
    dist.assign(n+1, vector<int>(n+1, INF));
    for (int i = 0; i < n; ++i)
        BFS(i, dist[i], [](int x){return x+1;});

    // COMPUTE CONNEXE
    int nbConnexe = 1;
    connexe.assign(n+1, INF);
    for (int i = 0; i < n; ++i)
        if (connexe[i] == INF) {
            BFS(i, connexe, [nbConnexe](int){return nbConnexe;});
            ++nbConnexe;
        }
    conquise.assign(nbConnexe, false);

    // GAME
    while (true) {
        readState();
        updateSpawn();

        // update conquise
        for (int i = 0; i < nbConnexe; ++i)
            conquise[i] = true;
        for (int i = 0; i < n; ++i)
            if (owner[i] != myId)
                conquise[connexe[i]] = false;

        vector<int> mypod(platinum/20, n);
        platinum %= 20;

        for (int i = 0; i < n; ++i)
            for (int j = 0; j < pods[myId][i]; ++j)
                mypod.push_back(i);

        for (int x : mypod)
            play(x);

        daEngine.display();
    }
}
