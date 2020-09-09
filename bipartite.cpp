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

vector<int> adj[200005];
int color[200005],vis[200005];
int n,m;

bool fl=true;

void checkBipartite(int node,int par,int col){
	vis[node]=1;
	color[node]=col;

	for(auto it: adj[node]){
		if(!vis[it]){
			checkBipartite(it,node,!col);
		}else if(it!=par && color[node]==color[it]){
			fl=false;
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

	cin>>n>>m;
	vector<pair<int,int>> edges;

	for(int i=1;i<=m;i++){
		int u,v;
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
		edges.push_back({u,v});
	}

	memset(vis,0,sizeof(vis));
	memset(color,0,sizeof(color));
	
	checkBipartite(1,0,1);

	if(fl){
		cout<<"YES"<<endl;
		for(auto it: edges){
			if(color[it.first]==0){
				cout<<0;
			}else{
				cout<<1;
			}
		}
		cout<<endl;
	}else{
		cout<<"NO"<<endl;
	}

	return 0;
}
