#include<iostream>
#include<vector>
#include<queue>

using namespace std;

#define forn(i, n) for (int i = 0; i < int(n); ++i)

class Hungarian {
public:
	vector<vector<int> > cost;
	vector<vector<int> > match;
	Hungarian(int n) : cost(n, vector<int> (n, 0)) {}

private:
	vector<vector<int> > label;
	vector<int> slack, slackx, parent;
	vector<bool> S, T;
	queue<int> file;
	int n, matchingSize;

	void augmentPath(int j) {
		// Invert edges on the path
		while (j >= 0) {
			int tmp = match[0][parent[j]];
			match[0][parent[j]] = j;
			match[1][j] = parent[j];
			j = tmp;
		}
		++matchingSize;
	}

	bool addEdge(int i, int j) {
		int k = match[1][j];
		parent[j] = i;
		// If j is exposed, we found an augmenting path
		if (k < 0) { augmentPath(j); return true; }
		S[k] = T[j] = true;
		file.push(k);
		forn(y, n)
			// Update slacks, because we add new vertex to S
			if (cost[k][y] - label[0][k] - label[1][y] < slack[y]) {
				slack[y] = cost[k][y] - label[0][k] - label[1][y];
				slackx[y] = k;
			}
		return false;
	}

	void findAugmentingPath() {
		int root = -1;
		S.assign(n, false);
		T.assign(n, false);
		parent.assign(n, -1);
		file = queue<int> ();
		// Initial queue, start from uncovered jobs
		forn(i, n)
			if (match[0][i] < 0) {
				file.push(root = i); S[i] = true; break;
			}
		// Initialize slack array
		forn(j, n) {
			slack[j] = cost[root][j] - label[0][root] - label[1][j];
			slackx[j] = root;
		}
		while (true) {
			// Breadth first search
			while (not file.empty()) {
				int i = file.front(); file.pop();
				forn(j, cost.size())
					// Follow tight edges only
					if (not T[j] && label[0][i] + label[1][j] == cost[i][j])
						if (addEdge(i, j)) return;
			}
			// No augmenting path found, update labels
			updateLabels();
			// Try to add new edges to the augmenting tree
			file = queue<int> ();
			forn(j, n)
				if (not T[j] && slack[j] == 0)
					if (addEdge(slackx[j], j)) return;
		}
	}

	void updateLabels() {
		// Compute delta using slack array
		int delta = numeric_limits<int>::max();
		forn(j, n) if (not T[j]) delta = min(delta, slack[j]);
		// Update labels of vertices from S and T
		forn(i, n) if (S[i]) label[0][i] += delta;
		forn(j, n) if (T[j]) label[1][j] -= delta;
		// Update slack array
		forn(j, n) if (not T[j]) slack[j] -= delta;
	}

public:
	int minimize() {
		// Initialization
		n = cost.size();
		slack.resize(n); slackx.resize(n);
		label.assign(2, vector<int> (n, 0));
		match.assign(2, vector<int> (n, -1));
		// Main loop
		for (matchingSize = 0; matchingSize < n;)
			findAugmentingPath();
		// Return the resulting cost
		int sum = 0;
		forn(i, n) sum += cost[i][match[0][i]];
		return sum;
	}
};


int main(){
  Hungarian h(15);
  for(int i=0;i<15;++i)
    for(int j=0;j<15;++j){
      int tmp;
      cin >> tmp;
      h.cost[i][j] = -tmp;

    }
  cout << -h.minimize() << '\n';
}
