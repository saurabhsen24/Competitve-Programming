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

int XX[8]={+1, +1, +1, 0, 0, -1, -1, -1};
int YY[8]={+1, 0, -1, +1, -1, +1, 0, -1};
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};


vector<int> adj[200005],g[200005];
int vis[200005];
vector<int> top(2000005,0),comp(200005,0);
int n,m;

void add(int u,int v){
	adj[u].pb(v);
	g[v].pb(u);
}

void dfs1(int node){
	vis[node]=1;
	for(auto it: adj[node]){
		if(!vis[it]){
			dfs1(it);
		}
	}

	top.push_back(node);
}

void dfs2(int node,int cnt){
	vis[node]=1;
	comp[node]=cnt;
	for(auto it: g[node]){
		if(!vis[it]){
			dfs2(it,cnt);
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

	cin>>m>>n;

	for(int i=0;i<m;i++){
		char ch1,ch2;
		int x,y;
		cin>>ch1>>x>>ch2>>y;
		x--;
		y--;
		x<<=1;
		y<<=1;

		if(ch1=='-'){
			x++;
		}

		if(ch2=='-'){
			y++;
		}

		add(x^1,y);
		add(y^1,x);
	}

	memset(vis,0,sizeof(vis));

	for(int i=0;i<2*n;i++){
		if(!vis[i]){
			dfs1(i);
		}
	}

	reverse(top.begin(),top.end());

	memset(vis,0,sizeof(vis));

	int cnt=0;

	for(int i=0;i<2*n;i++){
		if(!vis[i]){
			dfs2(i,++cnt);
		}
	}

	vector<int> ans(n,0);

	for(int i=0;i<2*n;i+=2){
		if(comp[i]==comp[i+1]){
			cout<<"IMPOSSIBLE";
			return 0;
		}
		ans[i/2]=(comp[i]>comp[i+1]);
	}

	for(int i=0;i<n;i++){
		if(ans[i]) cout<<"+";
		else cout<<"-";
	}

	return 0;
}
