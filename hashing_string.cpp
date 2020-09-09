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
#define vi vector<int>
#define mod 1000000007
#define tc(t) 			int t;cin >> t;while(t--)
#define for0(i , n)		for(int i=0;i<n;i++)
#define loop(i , a, b)	for(int i=a;i<=b;i++)
#define endl '\n'

int modexp(int n, int x, int m){
	int ans = 1;
	while(x){
		if(x % 2){
			ans = (ans*n) % m;
			x--;
		}else{
			n = (n*n) % m;
			x=x/2;
		}
	}

	return ans;
}



signed main() {

	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
#ifndef ONLINE_JUDGE
	freopen("input.txt" , "r" , stdin);
	freopen("output.txt" , "w" , stdout);
#endif
	
	string s;
	cin >> s;

	int n = s.size();
	int m = (1e9+ 7);
	int prehash[n],power[n], inversePower[n];
	int p = 1, ans = 0;

	for(int i = 0 ; i < n ; i++){
		ans = (ans + (((s[i] - 'a' + 1)*p) % m)) % m;
		prehash[i] = ans;
		power[i] = p;
		inversePower[i] = modexp(p , m-2, m);
		p = (p*31) % m;
	}


	 int i1,j1,i2,j2;
	 cin >> i1 >> j1;
	 int hash1 = prehash[j1];
	
	 if(i1 > 0){
	 	hash1 -= prehash[i1-1];
	 	//hash1 = hash1/power[i1];
	 	hash1 = (hash1 * inversePower[i1]) % m;
	 }

	 cout << hash1 << endl;
	

	return 0;
}
