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

vector<int> adj[200005];
int parent[200005][21];
int level[200005];
int n,q;

void dfs(int node,int par,int lev){
	parent[node][0]=par;
	level[node]=lev;

	for(int i=1;i<=20;i++){
		parent[node][i]=parent[parent[node][i-1]][i-1];
	}

	for(auto it: adj[node]){
		if(it!=par){
			dfs(it,node,lev+1);
		}
	}
}

int findlca(int x,int y){
	if(level[y]>level[x]){
		swap(x,y);
	}

	int d=level[x]-level[y];
	int cnt=-1;
	while(d){
		cnt++;
		if(d&1){
			x=parent[x][cnt];
		}
		d>>=1;
	}

	if(x==y)return x;

	for(int i=20;i>=0;i--){
		if(parent[x][i]!=parent[y][i]){
			x=parent[x][i];
			y=parent[y][i];
		}
	}

	return parent[x][0];
}

signed main() {

	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
#ifndef ONLINE_JUDGE
	freopen("input.txt" , "r" , stdin);
	freopen("output.txt" , "w" , stdout);
#endif

	cin>>n>>q;

	memset(parent,0,sizeof(parent));

	for(int i=2;i<=n;i++){
		int p;
		cin>>p;
		adj[i].push_back(p);
		adj[p].push_back(i);
	}

	dfs(1,0,0);

	while(q--){
		int x,y;
		cin>>x>>y;
		cout<<findlca(x,y)<<endl;
	}

	return 0;
}
