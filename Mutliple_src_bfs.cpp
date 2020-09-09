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



signed main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

#ifndef ONLINE_JUDGE
	freopen("input.txt" , "r" , stdin);
	freopen("output.txt" , "w" , stdout);
#endif

	tc(t){
		int n,m;
		cin>>n>>m;
		int a[n+1][m+1];
		int maxi=0;
		vector<pii> adj[n+1][m+1];
		vector<pii> spcl;
		loop(i,1,n){
			loop(j,1,m){
				cin>>a[i][j];
				maxi=max(maxi,a[i][j]);
			}
		}

		loop(i,1,n){
			loop(j,1,m){
				if(a[i][j]==maxi){
					spcl.pb({i,j});
				}
			}
		}

		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				for(int k=0;k<8;k++){
					int x=i+XX[k];
					int y=j+YY[k];
					if(x>=1 && x<=n && y>=1 && y<=m){
						adj[i][j].pb({x,y});
					}
				}
			}
		}

		vector<vector<int>> vis(n+1,vector<int>(m+1,0));
		vector<vector<int>> dis(n+1,vector<int>(m+1,0));
		queue<pii> q;

		for(pii p: spcl){
			vis[p.fi][p.se]=1;
			dis[p.fi][p.se]=0;
			q.push({p.fi,p.se});
		}

		int ans=0;

		while(!q.empty()){
			pii u=q.front();
			q.pop();
			for(auto v: adj[u.fi][u.se]){
				if(!vis[v.fi][v.se]){
					vis[v.fi][v.se]=1;
					dis[v.fi][v.se]=dis[u.fi][u.se]+1;
					ans=max(ans,dis[v.fi][v.se]);
					q.push(v);
				}
			}
		}

		cout<<ans<<endl;
	}

	return 0;
}
