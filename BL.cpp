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
int dx[4]={-1,1,0,0};
int dy[4]={0,0,1,-1};

const int LG = 20;
int parent[100005][LG];
int a[100005];

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

		memset(parent,0,sizeof(parent));
		memset(a,0,sizeof(a));

		for(int i=1;i<=n;i++){
			int u,v;
			cin>>u>>v;
			a[i]=u;
			if(v!=0){
				parent[u][0]=v;
			}
		}

		for(int i=1;i<=LG-1;i++){
			for(int j=1;j<=n;j++){
				parent[a[j]][i]=parent[parent[a[j]][i-1]][i-1];
			}
		}

		int q;
		cin>>q;

		while(q--){
			int ch;
			cin>>ch;
			if(ch==0){
				int x,y;
				cin>>x>>y;
				parent[y][0]=x;
				for(int i=1;i<=LG-1;i++){
					parent[y][i]=parent[parent[y][i-1]][i-1];
				}

			}else if(ch==1){
				int x;
				cin>>x;
				parent[x][0]=0;
			}else{
				int x,k;
				cin>>x>>k;

				if(parent[x][0]==0){
					cout<<0<<endl;
					continue;
				}

				int cnt=-1;
				while(k){
					cnt++;
					if(k&1){
						x=parent[x][cnt];
					}
					k>>=1;
				}

				cout<<x<<endl;
			}
		}
	}

	return 0;
}
