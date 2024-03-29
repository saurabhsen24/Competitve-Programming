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

int dp[101][101];

/**

	a[i] is chosen by me so opponent can choose a[i+1] or a[j] and he will try to give me the choices which will give me less amount
that's why we are using  min(solve(i+2,j),solve(i+1,j-1)). Similarly for the second case also where I am picking up the last coin and now opponent can choose 
a[i] or a[j-1] so he will try to minimize the remaining amount so I am writing min(solve(i + 1, j - 1), solve(i, j - 2))

**/

int solve(int a[], int i, int j) {
	if (i > j) return 0;
	if (dp[i][j] != -1) return dp[i][j];
	return dp[i][j] = max(a[i] + min(solve(a, i + 2, j), solve(a, i + 1, j - 1)), a[j] + min(solve(a, i + 1, j - 1), solve(a, i, j - 2)));
}

signed main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

#ifndef ONLINE_JUDGE
	freopen("input.txt" , "r" , stdin);
	freopen("output.txt" , "w" , stdout);
#endif

	tc(t) {
		int n;
		cin >> n;
		int a[n];
		for0(i, n) cin >> a[i];

		memset(dp, -1, sizeof(dp));

		cout << solve(a, 0, n - 1) << endl;
	}

	return 0;
}
