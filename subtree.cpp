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

int dx[8]={+1, +1, +1, 0, 0, -1, -1, -1};
int dy[8]={+1, 0, -1, +1, -1, +1, 0, -1};

vector<int> adj[300005];
int parent[300005],subtree[300005];
int n;

void dfs(int node,int par=0){
	parent[node]=par;
	subtree[node]=1;
	for(auto it: adj[node]){
		if(it!=par){
			dfs(it,node);
			subtree[node]+=subtree[it];
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

	int u,v;
	cin >> n >> u >> v;
	for(int i=1;i<=n-1;i++){
		int u,v;
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	memset(parent,0,sizeof(parent));
	memset(subtree,0,sizeof(subtree));

	dfs(u);
	int a=subtree[v];
	dfs(v);
	cout<<n*(n-1)-(a*subtree[u]);

	return 0;
}
