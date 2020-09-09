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

int gcd(int a,int b, int& x, int& y){
	if(a == 0){
		x = 0;
		y = 1;
		return b;
	}

	int x1,y1;
	int d = gcd(b%a,a,x1,y1);
	x = y1 - (b/a)*x1;
	y = x1;
	return d;
}

int euclid(int a,int b, int &x, int &y){
	if(b == 0){
		x = 1;
		y = 0;
		return a;
	}

	int x1,y1;
	int d = euclid(b, a%b, x1,y1);
	x = y1;
	y = x1 - (a/b)*y1;
	return d;
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
		int a,b,d;
		cin >> a >> b >> d;
		int x,y;
		int g = gcd(a,b,x,y);

		cout << g << " " << x << " " << y << endl;

		if(d % g != 0){
			cout << 0 << endl;
			continue;
		}

		cout << a << " " << b << endl;

		int k1 = ceil(double(-x) * (double(d)/(double)b));
		int k2 = floor(double(y) * ((double)d/(double)a));
		cout << k1 << " " << k2 << endl;
		if(k1 <= k2){
			cout << k2-k1+1 << endl;
		}else{
			cout << 0 << endl;
		}

	}

	return 0;
}
