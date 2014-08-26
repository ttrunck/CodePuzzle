#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <queue>
#include <bitset>
#include <complex>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <limits>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

#define forn(i, n) for (int i = 0; i < (n); ++i)
#define foreach(it, a) for (__typeof((a).begin()) it = (a).begin(); it != (a).end(); ++it)

/********************************************************************************
 ********************      Algorithmes sur les graphes       ********************
 ********************************************************************************/

/********************************************************************************
 * Dijkstra. One-to-all shortest path in positive weighted graph. O(m*log(n))
 ********************************************************************************/

struct edge {
	int x, y, w;
	edge(void): x(),y(),w() {};
	edge(int a, int b, int c): x(a), y(b), w(c) {}
	bool operator< (const edge &e) const {
		return w > e.w; // Extract min-cost edges first
	}
};

void dijkstra(vector<vector<edge> > &graph, vector<int> &prev, vector<int> &dist, int source) {
	priority_queue<edge> file;
	vector<bool> mark(graph.size(), false);
	prev.assign(graph.size(), -1);
	dist.assign(graph.size(), INT_MAX);
	file.push(edge(source, source, 0));
	while (not file.empty()) {
		edge e = file.top(); file.pop();
		if (mark[e.y]) continue;
		prev[e.y] = e.x;
		dist[e.y] = e.w; // Distance form source is now correct
		mark[e.y] = true;
		forn(i, graph[e.y].size()) {
			edge f = graph[e.y][i];
			f.w += e.w;
			if (dist[f.y] > f.w) file.push(f);
		}
	}
}

/********************************************************************************
 * Bellman-Ford. One-to-all shortest path in arbitrarily weighted graph. O(n*m)
 ********************************************************************************/

struct edge {
	int x, y, w;
	edge(void): x(),y(),w() {};
	edge(int a, int b, int c): x(a), y(b), w(c) {}
	bool operator< (const edge &e) const { return w < e.w; }
};

// Return true iff contains negative cycle.
bool bellmanFord(vector<edge> &graph, vector<int> &dist, vector<int> &prev, int source, int maxStep) {
	bool again = true;
	dist[source] = 0;
	for (int k = 0; again && k < maxStep; ++k) {
		again = false;
		forn(i, graph.size()) {
			int x = graph[i].x, y = graph[i].y, w = graph[i].w;
			if (dist[x] != INT_MAX && dist[y] > dist[x] + w) {
				dist[y] = dist[x] + w;
				prev[y] = x;
				again = true;
			}
		}
	}
	return again;
}

/********************************************************************************
 * Roy-Warshall. All-to-all shortest path in arbitrarily weighted graph. O(n^3)
 ********************************************************************************/

typedef vector<vector<int> > matrix;

// Return true iff contains negative cycle.
// r[i][j] = next vertex in shortest path from i to j.
bool royWarshall(matrix &g, matrix &r) {
	int n = g.size();
	forn(i, n)
		forn(j, n)
			r[i][j] = (g[i][j] == INT_MAX ? i : j);
	forn(k, n)
		forn(i, n)
			forn(j, n) {
				if (g[i][k] == INT_MAX || g[k][j] == INT_MAX) continue;
				if (g[i][k] + g[k][j] < g[i][j]) {
					g[i][j] = g[i][k] + g[k][j];
					r[i][j] = r[i][k];
				}
			}
	forn(i, n)
		if (g[i][i] < 0) return true;
	return false;
}

/********************************************************************************
 * Kruskal & Union-Find. Minimum weighted spanning tree.
 ********************************************************************************/

vector<int> parent;

void init(int n) {
	parent.resize(n);
	forn(i, n)
		parent[i] = i;
}

int find(int i) {
	if (parent[i] == i) return i;
	parent[i] = find(parent[i]);
	return parent[i];
}

void merge(int i, int j) {
	parent[find(i)] = find(j);
}

void kruskal(vector<edge> &graph, vector<edge> &tree, int n) {
	init(n);
	sort(graph.begin(), graph.end());
	forn(i, graph.size())
		if (find(graph[i].x) != find(graph[i].y)) {
			tree.push_back(graph[i]);
			merge(graph[i].x, graph[i].y);
		}
}

/********************************************************************************
 * Prim. Maximum weighted spanning tree.
 ********************************************************************************/

struct edge {
	int x, y, w;
	edge(void): x(),y(),w() {};
	edge(int a, int b, int c): x(a), y(b), w(c) {}
	bool operator< (const edge & e) const {
		return w < e.w; // Change with > for minimum spanning tree
	}
};

// Return the weight of a minimum/maximum spanning tree
int prim(vector<vector<edge> > &graph, vector<edge> &tree) {
	priority_queue<edge> file;
	vector<bool> mark(graph.size(), false);
	int total = 0;
	mark[0] = true;
	forn(i, graph[0].size())
		file.push(graph[0][i]);
	while (not file.empty()) {
		edge e = file.top(); file.pop();
		if (mark[e.y]) continue;
		tree.push_back(e);
		total += e.w;
		mark[e.y] = true;
		forn(i, graph[e.y].size())
			file.push(graph[e.y][i]);
	}
	return total;
}

/********************************************************************************
 * Tarjan. Find strongly connected components in directed graph. O(n + m)
 ********************************************************************************/

struct Tarjan {
	vector<vector<int> > adj;
	vector<int> comp, index, lowlink;
	stack<int> accu;
	int counter, ncomp;

	Tarjan(int n) :
		adj(n), comp(n, -1), index(n, -1), lowlink(n, -1), counter(0), ncomp(0) {}

	void dfs(int i) {
		index[i] = lowlink[i] = counter++;
		accu.push(i);
		forn(k, adj[i].size()) {
			int j = adj[i][k];
			if (index[j] == -1) dfs(j);
			if (comp[j] == -1)
				lowlink[i] = min(lowlink[i], lowlink[j]);
		}
		if (lowlink[i] == index[i]) {
			int j; do {
				j = accu.top(); accu.pop();
				comp[j] = ncomp;
			} while (i != j);
			++ncomp;
		}
	}

	void compute() { forn(i, adj.size()) if (index[i] == -1) dfs(i); }
};

/********************************************************************************
 * Vertex-Cut. Find articulation points in undirected graph. O(n + m)
 ********************************************************************************/

vector<vector<int> > graph;
vector<bool> articulation;
vector<int> index, lowlink;
int counter;

void vertexCut(int x, bool root = true) {
	index[x] = lowlink[x] = ++counter;
	forn(i, graph[x].size()) {
		int y = graph[x][i];
		if (root && i > 0 && index[y] < 0)
			articulation[x] = true;
		if (index[y] < 0) {
			vertexCut(y, false);
			lowlink[x] = min(lowlink[x], lowlink[y]);
			if (not root && index[x] <= lowlink[y])
				articulation[x] = true;
		} else
			lowlink[x] = min(lowlink[x], index[y]);
	}
}

/********************************************************************************
 * Edge-Cut. Find bridges in undirected graph. O(n + m)
 ********************************************************************************/

vector<vector<int> > graph;
vector<int> index, lowlink;
vector<edge> bridge;
int counter;

void edgeCut(int x, int z) {
	index[x] = lowlink[x] = ++counter;
	forn(i, graph[x].size()) {
		int y = graph[x][i];
		if (index[y] < 0) edgeCut(y, x);
		if (y != z) lowlink[x] = min(lowlink[x], lowlink[y]);
	}
	if (lowlink[x] == index[x] && z >= 0)
		bridge.push_back(edge(z, x));
}

/********************************************************************************
 * Effeuillage. O(n+m)
 ********************************************************************************/

void effeuille(vector<vector<int> > &adj, vector<int> &order) {
	vector<bool> mark(adj.size(), false);
	vector<int>  deg(adj.size(), 0); // Input degree
	queue<int> file;
	int index = 0;
	forn(x, adj.size())
		forn(i, adj[x].size())
			++deg[adj[x][i]];
	forn(x, adj.size())
		if (deg[x] == 1) { mark[x] = true; file.push(x); }
	while (not file.empty()) {
		int x = file.front(); file.pop();
		order[x] = index++; // Operation on x
		forn(i, adj[x].size()) {
			int y = adj[x][i];
			if (mark[y]) continue;
			--deg[y];
			if (deg[y] == 1) { mark[y] = true; file.push(y); }
		}
	}
}

/********************************************************************************
 * Edmonds-Karp. Maximum flow using augmenting paths. O(n*m^2)
 ********************************************************************************/

struct EdmondsKarp {
	vector<vector<int> > adj, capa, flow;
	vector<int> prev;
	int flowSize;

	EdmondsKarp(int n = 0) :
		adj(n), capa(n, vector<int> (n, 0)), flow(n, vector<int> (n, 0)), flowSize(0) {}

	void findAgumentingPath(int source, int target) {
		queue<int> file;
		prev.assign(adj.size(), -1);
		prev[source] = -2;
		file.push(source);
		while (not file.empty()) {
			int x = file.front(); file.pop();
			forn(i, adj[x].size()) {
				int y = adj[x][i];
				if (prev[y] == -1 && capa[x][y] - flow[x][y] > 0) {
					prev[y] = x;
					file.push(y);
					if (y == target) return;
				}
			}
		}
	}

	int augmentFlow(int target) {
		int delta = INT_MAX;
		for (int y = target, x = prev[target]; x >= 0; y = x, x = prev[x])
			delta = min(delta, capa[x][y] - flow[x][y]);
		for (int y = target, x = prev[target]; x >= 0; y = x, x = prev[x]) {
			flow[x][y] += delta;
			flow[y][x] -= delta;
		}
		flowSize += delta;
	}

	int maxFlow(int source, int target) {
		int n = adj.size(); flowSize = 0;
		flow.assign(n, vector<int> (n, 0));
		while (true) {
			findAgumentingPath(source, target);
			if (prev[target] == -1) break;
			augmentFlow(target);
		}
		return flowSize;
	}
};

/********************************************************************************
 * Maximum Bipartite Matching. Uses augmenting paths. O(n*m)
 ********************************************************************************/

struct Bipartite {
	vector<vector<int> > adjLeft;
	vector<int> matchLeft, matchRight;
	vector<bool> visited;
	int matchingSize;

	Bipartite(int p = 0, int q = 0) :
		adjLeft(p), matchLeft(p, -1), matchRight(q, -1), matchingSize(0) {}

	bool depthFirstSearch(int x) {
		if (visited[x]) return false;
		visited[x] = true;
		forn(i, adjLeft[x].size()) {
			int y = adjLeft[x][i];
			int z = matchRight[y];
			if (z < 0 || depthFirstSearch(z)) {
				matchRight[y] = x;
				matchLeft[x] = y;
				return true;
			}
		}
		return false;
	}

	bool findAgumentingPath(void) {
		visited.assign(adjLeft.size(), false);
		forn(i, adjLeft.size())
			if (matchLeft[i] == -1 && depthFirstSearch(i))
				return true;
		return false;
	}

	void greedyMatching(void) {
		forn(x, adjLeft.size())
			forn(i, (int) adjLeft[x].size()) {
				int y = adjLeft[x][i];
				if (matchLeft[x] == -1 && matchRight[y] == -1) {
					matchLeft[x] = y;
					matchRight[y] = x;
					++matchingSize;
				}
			}
	}

	int maximumMatching(void) {
		while(findAgumentingPath()) ++matchingSize;
		return matchingSize;
	}
};

/*****************************************************************************
 * Hungarian method (Kuhn-Munkres). Assignment problem. O(n^3)
 * slack[y] = min(cost[x][y] - label[x] - label[y]) for x ∈ S
 *****************************************************************************/

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

/********************************************************************************
 *************************         Arithmétique         *************************
 ********************************************************************************/

// Quick Modular Power y = (x ^ n) % m
int powMod(int x, int n, int m) {
	int y = 1;
	while (n != 0) {
		if ((n & 1) == 1)
			y = (y * x) % m;
		x = (x * x) % m;
		n = n >> 1;
	}
	return y;
}

// For p prime, return y such as x*y = 1 [p]
int invMod(int x, int p) { return powMod(x, p - 2, p); }

int gcd(int x, int y) { while (y) { x %= y; swap(x, y); } return x; }

// Compute (u,v) such as a*u + b*v = r, and return r = gcd(a,b).
int bezout(int &a, int &b, int &u, int &v) {
	int r = a, r1 = b;
	int q, rs, us, vs;
	int u1, v1;
	u  = 1, v  = 0;
	u1 = 0, v1 = 1;
	while (r1) {
		q = r / r1;
		rs = r; us = u; vs = v;
		r = r1; u = u1; v = v1;
		r1 = rs - q * r1;
		u1 = us - q * u1;
		v1 = vs - q * v1;
	}
	return r;
}

// Chinese remainder theorem : find x such as x = a (mod p) et x = b (mod q).
// Return true iff a solution exists
bool chinese(int a, int b, int p, int q, int &x) {
	int u, v;
	int ppq = bezout(p, q, u, v);
	if (a % ppq != b % ppq) return false;
	x = (a / ppq) * v * q + (b / ppq) * u * p + (a % ppq);
	return true;
}

int binomial(int k, int n) {
	int res = 1;
	for (int i = 1; i <= k; ++i)
		res = (n - k + i) * res / i;
	return res;
}

bool isPrime(int n) {
	if (n == 0 || n == 1) return false;
	else if (n == 2 || n == 3 || n == 5 || n == 7) return true;
	else if (n % 2 == 0 || n % 3 == 0) return false;
	else {
		for (int i = 5; i * i <= n; i += 6)
			if (n % i == 0 || n % (i + 2) == 0)
				return false;
		return true;
	}
}

/********************************************************************************
 * Eratosthenes Sieve.
 ********************************************************************************/

void sieve(vector<bool> &crossed, int limit) {
	crossed.assign(limit / 2, false);
	crossed[0] = true;
	for (int i = 1; 4 * i * i < limit; ++i)
		if (not crossed[i])
			for (int j = 2 * i * (i + 1); 2 * j < limit; j += 2 * i + 1)
				crossed[j] = true;
}

bool isPrime(vector<bool> &crossed, int i) {
	if (i == 2) return true;
	if (i % 2 == 0) return false;
	return not crossed[(i - 1) / 2];
}

/********************************************************************************
 * Gaussian Elimination. Determinant & Invert of Square Matrices. O(n^3)
 ********************************************************************************/

typedef long double elem;
typedef vector<vector<elem> > matrix;

elem inline eabs(elem x) { return fabs(x); }
bool inline zero(elem x) { return (eabs(x) < 1e-20); }

void swapLine(matrix &m, int i, int j) { swap(m[i], m[j]); }
void subLine(matrix &m, int i, int j, elem x, elem y) {
	forn(k, m.size())
		m[i][k] = m[i][k] - m[j][k] * y / x;
}
void multLine(matrix &m, int i, elem x) {
	forn(k, m.size())
		m[i][k] = m[i][k] * x;
}

// Invert m if invertible and return its determinant
elem invMatrix(matrix &m, matrix &inv) {
	int n = m.size();
	elem ans = 1;
	inv.assign(n, vector<elem> (n, 0));
	forn(i, n) inv[i][i] = 1.; // Identity matrix
	forn(i, n) {
		// Find greater non-zero element
		for (int j = i + 1; j < n; ++j) {
			if (zero(m[j][i])) continue;
			if (eabs(m[j][i]) > eabs(m[i][i])) {
				swapLine(inv, i, j);
				swapLine(m, i, j);
			}
		}
		if (zero(m[i][i])) return 0; // m not invertible
		ans *= m[i][i];
		for (int j = 0; j < n; ++j) {
			if (i != j) {
				subLine(inv, j, i, m[i][i], m[j][i]);
				subLine(m, j, i, m[i][i], m[j][i]);
			}
		}
		// Normalization
		multLine(inv, i, 1. / m[i][i]);
		multLine(m, i, 1. / m[i][i]);
	}
	return ans;
}


/********************************************************************************
 *************************          Géométrie           *************************
 ********************************************************************************/

typedef complex<double> point;
typedef vector<point> poly;
const double eps = 1e-10;

double inline det(const point &u, const point &v) { return imag(conj(u) * v); }

// Return true iff [a,b] intersects [c,d], and store the intersection in ans
bool intersectSegment(const point &a, const point &b, const point &c, const point &d, point &ans) {
	double x = det(c - a, d - c);
	double y = det(b - a, a - c);
	double z = det(b - a, d - c);
	if (abs(z) < eps || x*z < 0 || x*z > z*z || y*z < 0 || y*z > z*z) return false;
	ans = c + (d - c) * y / z;
	return true;
}

point outside(1000, 1000); // A point outside the workspace
bool isInside(const point &a, const poly &p) {
	int n = p.size();
	bool tmp, ans = false;
	forn(i, p.size()) {
		tmp = intersectSegment(a, outside, p[i], p[(i + 1) % n] /*, dummy */);
		ans = (ans != tmp);
	}
	return ans;
}

double computeArea(poly &t) {
	double sum = 0;
	for (int i = 1; i < t.size() - 1; ++i)
		sum += det(t[i] - t[0], t[i + 1] - t[0]);
	return abs(sum / 2);
}

/********************************************************************************
 * Graham. Convex Hull. O(n*log(n))
 ********************************************************************************/

struct Compare {
	point p0; // Leftmost point of the poly
	bool operator ()(const point &p1, const point &p2) {
		if (p1 == p0) return true;
		if (p2 == p0) return false;
		double d = det(p1 - p0, p2 - p0);
		return (d < 0 || (d == 0 && abs(p1 - p0) < abs(p2 - p0)));
	}
};

bool inline salientAngle(point &a, point &b, point &c) {
	return (det(b - a, c - a) >= 0);
}

void convexHull(poly &t, poly &r) {
	Compare order;
	order.p0 = t[0];
	forn(i, t.size())
		if (t[i].real() < order.p0.real())
			order.p0 = t[i];
	sort(t.begin(), t.end(), order);
	forn(i, t.size()) {
		r.push_back(t[i]);
		while (r.size() > 3u && salientAngle(r.end()[-3], r.end()[-2], r.end()[-1])) {
			r.end()[-2] = r.back();
			r.pop_back(); // Pop inner vertices
		}
	}
}

/********************************************************************************
 * KdTree.
 ********************************************************************************/

typedef complex<elem> point;
bool compareX(const point &u, const point &v) { return u.real() < v.real(); }
bool compareY(const point &u, const point &v) { return u.imag() < v.imag(); }

struct KdTree {
	point vertex;
	KdTree *left, *right;

	KdTree(const point &p) : vertex(p), left(0), right(0) {}
	~KdTree() { if (left) delete left; if (right) delete right; }

	// Build a balanced tree, complexity O(n*log(n))
	typedef vector<point>::iterator MyIterator;
	static KdTree * build(MyIterator first, int n, bool odd = false) {
		if (n == 0) return 0;
		if (n == 1) return new KdTree(*first);
		nth_element(first, first + n / 2, first + n, (odd ? compareY : compareX));
		KdTree *node = new KdTree(*(first + (n / 2)));
		node->left = build(first, n / 2, not odd);
		node->right = build(first + n / 2 + 1, n - (n / 2) - 1, not odd);
		return node;
	}

	// Find nearest neighbor, complexity O(n^(1/2))
	// Important: start with a value of radius == numeric_limits<elem>::max();
	void find(const point &target, point &best, elem &radius, bool odd = false) {
		if (target != vertex && norm(target - vertex) < radius)
			best = vertex, radius = norm(target - vertex);
		elem dist = odd ? imag(target - vertex) : real(target - vertex);
		elem distSquared = dist * dist;
		if (dist < 0) {
			if (left) left->find(target, best, radius, not odd);
			if (right && distSquared <= radius)
				right->find(target, best, radius, not odd);
		} else {
			if (right) right->find(target, best, radius, not odd);
			if (left && distSquared <= radius)
				left->find(target, best, radius, not odd);
		}
	}
};

/********************************************************************************
 ***************************          Autre           ***************************
 ********************************************************************************/

// Longest Common Subsequence by dynamic programming
int lcs(string &s1, string &s2) {
	int n = s1.length();
	int m = s2.length();
	matrix v(n + 1, vector<int> (m + 1, 0));
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			if (s1[i - 1] == s2[j - 1]) v[i][j] = 1 + v[i - 1][j - 1];
			else v[i][j] = max(v[i][j - 1], v[i - 1][j]);
		}
	}
	return v[n][m];
}


/********************************************************************************
 * Nombre d'arbres couvrants d'un graphe
 *
 * Soit A la matrice d'adjacence du graphe (avec des A[i][j] = 1 ssi (i,j) est une arête),
 * D la matrice diagonale contenant les degrés des sommets (D[i][i] = deg(i) et 0 ailleurs).
 * On note alors Q = D-A.
 *
 * On peut montrer que le nombre d'arbres couvrants de G est alors la valeur absolue du
 * déterminant d'un des cofacteurs de Q (obtenu en supprimant une ligne et une colonne de Q).
 ********************************************************************************/
