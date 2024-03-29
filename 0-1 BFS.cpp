#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pb              push_back
#define mp              make_pair
#define pii             pair<int,int>
#define vi              vector<int>
#define mii             map<int,int>
#define pqb             priority_queue<int>
#define pqs             priority_queue<int,vi,greater<int> >
#define setbits(x)      __builtin_popcountll(x)
#define zrobits(x)      __builtin_ctzll(x)
#define mod 			1000000007
#define tc(t) 			int t;cin >> t;while(t--)
#define for0(i , n)		for(int i=0;i<n;i++)
#define loop(i , a, b)	for(int i=a;i<=b;i++)
#define endl 			'\n'
#define inf 			1e18
#define fi 				first
#define se 				second

int XX[8] = { +1, +1, +1, 0, 0, -1, -1, -1};
int YY[8] = { +1, 0, -1, +1, -1, +1, 0, -1};
int dx[4] = { -1, 1, 0, 0};
int dy[4] = {0, 0, 1, -1};

/**
 * 	In 0-1 BFS, 0 is must and in place of 1 any weight can be used
 * 	1st wt -> 0,
 * 	2nd wt -> +x
 **/

void bfszeroone(int src) {
	deque<pii> dq;
	vector<int> dis(n, 0);

	for (int i = 0; i < n; i++) {
		dis[i] = inf;
	}

	dis[src] = 0;
	dq.push_front({src, 0});

	while (!dq.empty()) {
		int node = dq.front().first;
		int dist = dq.front().second;
		dq.pop();

		for (auto it : adj[node]) {
			int adjNode = it.first;
			int wt = it.second;
			if (dist + wt < dis[adjNode]) {
				dis[adjNode] = dist + wt;
				if (wt == 1) {
					dq.push_back({adjNode, dist + wt});
				} else {
					dq.push_front({adjNode, dist + wt});
				}
			}
		}
	}

	for (int i = 0; i < n; i++) {
		cout << dist[i] << " ";
	}
}


signed main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

#ifndef ONLINE_JUDGE
	freopen("input.txt" , "r" , stdin);
	freopen("output.txt" , "w" , stdout);
#endif



	return 0;
}
