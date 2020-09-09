#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define ll long long int

ll prime[100001];

void seive(){

	for(ll i = 0 ; i <= 100000 ; i++) prime[i] = i;
		
	for(ll i = 2 ; i <=  100000 ; i++){
		if(prime[i]){
			for(ll j = i*i ; j <= 100000 ; j += i){
				prime[j] = false;
			}
		}
	}
}

ll power(ll n, ll x){
	ll ans = 1;

	while(x){
		if(x % 2){
			x--;
			ans = ans * n;
		}else{
			x /= 2;
			n *= n;
		}
	}

	return ans;

}

ll phi(ll n){
	ll ans = 1;
	for(ll i = 2 ; i*i <= n ; i++){
		ll cnt = 0;
		if(n % i == 0){
			while(n % i == 0){
				n /= i;
				cnt++;
			}

			ans = ans * (power(i , cnt) - power(i , cnt - 1)); 
		}
	}

	if(n != 1){
		ans = ans * (n - 1);
	}

	return ans;
}

int main() {

	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
#ifndef ONLINE_JUDGE
	freopen("input.txt" , "r" , stdin);
	freopen("output.txt" , "w" , stdout);
#endif

	ll n , k;

	cin >> n >> k;

	while(k--){
		n = phi(n);
		if(n == 1) break;
	}

	cout << n << endl;

	return 0;
}
