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
#define endl 			'\n'
#define inf 			1e18
#define fi 				first
#define se 				second

int XX[8]={+1, +1, +1, 0, 0, -1, -1, -1};
int YY[8]={+1, 0, -1, +1, -1, +1, 0, -1};
int dx[4]={-1,1,0,0};
int dy[4]={0,0,1,-1};


int parent[100005],ranks[100005];
int n,m;

void make_set(){
	for(int i=1;i<=n;i++){
		parent[i]=i;
		ranks[i]=0;
	}
}

int findPar(int node){
	if(node==parent[node])return node;
	return parent[node]=findPar(parent[node]);
}

void union_set(int u,int v){
	int p1=findPar(u);
	int p2=findPar(v);
	if(p1!=p2){
		if(ranks[p1]<ranks[p2]){
			parent[p1]=p2;
			ranks[p2]++;
		}else{
			parent[p2]=p1;
			ranks[p1]++;
		}
	}
}

void kruskal(){
	cin>>n>>m;
	make_set();
	vector<pair<int,pii>> edges;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		edges.push_back({w,{u,v}});
	}

	sort(edges.begin(),edges.end());
	int wt=0;

	for(auto it: edges){
		int w=it.fi;
		int u=it.se.fi;
		int v=it.se.se;
		if(findPar(u)!=findPar(v)){
			union_set(u,v);
			wt+=w;
		}
	}

	cout<<wt<<endl;
}

signed main() {

	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
#ifndef ONLINE_JUDGE
	freopen("input.txt" , "r" , stdin);
	freopen("output.txt" , "w" , stdout);
#endif

	kruskal();

	return 0;
}
