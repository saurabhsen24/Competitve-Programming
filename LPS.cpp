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

void computelps(int prehash[], int n, string s){
	int i = 0, j = 1;
	
	prehash[0]=0;

	while(j < n){
		if(s[i] == s[j]){
			prehash[j] = i+1;
			i++; 
			j++;
		}else{
			if(i != 0){
				i = prehash[i-1];
			}else{
				prehash[j] = 0;
				j++;
			} 
		}
	}
}

vector<int> prefix_function (string Z) {

    int n = (int) Z.length();

    vector<int> F (n);

     F[0]=0;

    for (int i=1; i<n; ++i) {

        int j = F[i-1];

        while (j > 0 && Z[i] != Z[j])

            j = F[j-1];

        if (Z[i] == Z[j])  ++j;

        F[i] = j;

    }

    return F;

}

signed main() {

	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
#ifndef ONLINE_JUDGE
	freopen("input.txt" , "r" , stdin);
	freopen("output.txt" , "w" , stdout);
#endif

	string pat,txt;
	cin >> txt >> pat;
	string s = pat + '$' + txt;
	int n = s.size();
	int prehash[n];
	computelps(prehash,n,s);
	vector<int> v = prefix_function(s);
	int x = pat.size();
	int cnt = 0;

	for(int i = 0 ; i < n ; i++){
		if(prehash[i] == x){
			cnt++;
		}
	}

	int cnt1 = 0;

	for(int i = 0 ; i < n ; i++){
		if(v[i] == x){
			cnt1++;
		}
	}

	cout << cnt << " " << cnt1 << endl;

	return 0;
}
