#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define dd double
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
#define eps 1e-9

int XX[8]={+1, +1, +1, 0, 0, -1, -1, -1};
int YY[8]={+1, 0, -1, +1, -1, +1, 0, -1};
int dx[4]={-1,1,0,0};
int dy[4]={0,0,1,-1};


vector<int> adj[200005];
int starttime[200005],endtime[200005];
int n,q,timer=0;

void dfs(int node,int par=0){
	starttime[node]=timer++;
	for(auto it: adj[node]){
		if(it!=par){
			dfs(it,node);
		}
	}

	endtime[node]=timer++;
}

int check(int x,int y){
	if(starttime[x]>starttime[y] && endtime[x]<endtime[y]){
		return 1;
	}
	return 0;
}


signed main() {

	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
#ifndef ONLINE_JUDGE
	freopen("input.txt" , "r" , stdin);
	freopen("output.txt" , "w" , stdout);
#endif

	cin>>n;
	
	for(int i=1;i<=n-1;i++){
		int u,v;
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	memset(starttime,0,sizeof(starttime));
	memset(endtime,0,sizeof(endtime));

	dfs(1);

	cin>>q;

	while(q--){
		int type,x,y;
		cin>>type>>x>>y;

		if(!check(x,y) && !check(y,x)){
			cout<<"NO"<<endl;
			continue;
		}

		if(type==0){
			if(check(y,x)){
				cout<<"YES"<<endl;
			}else{
				cout<<"NO"<<endl;
			}
		}else{
			if(check(x,y)){
				cout<<"YES"<<endl;
			}else{
				cout<<"NO"<<endl;
			}
		}
	}

	return 0;
}
