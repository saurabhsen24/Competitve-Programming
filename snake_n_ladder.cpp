#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define pb              push_back
#define mp              make_pair
#define fi       		first
#define se 				second
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

int XX[8]={+1, +1, +1, 0, 0, -1, -1, -1};
int YY[8]={+1, 0, -1, +1, -1, +1, 0, -1};
int dx[4]={-1,1,0,0};
int dy[4]={0,0,1,-1};

int board[50]={0};
int dist[100005];

int bfs(vector<int> adj[],int src,int dest){
	queue<int> q;
	q.push(src);

	dist[src]=0;

	while(!q.empty()){
		int node = q.front();
		q.pop();

		for(auto it: adj[node]){
			if(dist[it]==inf){
				q.push(it);
				dist[it]=dist[node]+1;
			}
		}
	}

	return dist[dest];

}

signed main() {

	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
#ifndef ONLINE_JUDGE
	freopen("input.txt" , "r" , stdin);
	freopen("output.txt" , "w" , stdout);
#endif

	tc(t){
		int n;
		cin>>n;

		vector<int> adj[32];
		memset(board,0,sizeof(board));

		for(int i=1;i<=n;i++){
			int u,v;
			cin>>u>>v;
			board[u]=v-u;
		}


		for(int i=0;i<=30;i++){
			for(int dice=1;dice<=6;dice++){
				int j=i+dice;
				j+=board[j];
				if(j<=30){
					adj[i].push_back(j);
				}
			}
		}		

		adj[30].push_back(30);

		for(int i=0;i<=30;i++) dist[i]=inf;	

		cout<<bfs(adj,1,30)<<endl;

	}

	return 0;
}
