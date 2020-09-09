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
#define mod 1000000007
#define tc(t) 			int t;cin >> t;while(t--)
#define for0(i , n)		for(int i=0;i<n;i++)
#define loop(i , a, b)	for(int i=a;i<=b;i++)
#define endl '\n'

int XX[8]={+1, +1, +1, 0, 0, -1, -1, -1};
int YY[8]={+1, 0, -1, +1, -1, +1, 0, -1};
int dx[4]={-1,1,0,0};
int dy[4]={0,0,1,-1};

vector<int> adj[100005];
map<pair<int,int>,int> mpp;
int dist[100005];
int n,m;

void dijikstra(int src){
	dist[src]=0;
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;

	pq.push({dist[src],src});

	while(!pq.empty()){
		pair<int,int> p=pq.top();
		int d = p.first;
		int node = p.second;
		pq.pop();

		for(auto it: adj[node]){
			if(d + mpp[{node,it}] < dist[it]){
				dist[it]=d+mpp[{node,it}];
				pq.push({dist[it],it});
			}
		}
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

	cin >> n >> m;

	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		adj[u].push_back(v);
		adj[v].push_back(u);
		mpp[{u,v}]=w;
		mpp[{v,u}]=w;
	}

	memset(dist,0,sizeof(dist));

	for(int i=0;i<=n;i++){
		dist[i]=1e18;
	}

	dijikstra(0);

	for(int i=0;i<=n;i++){
		cout<<dist[i]<<" ";
	}

	return 0;
}
