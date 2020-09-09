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


void populate(vector<int> &summ, vector<int> &arr) {
    int n = arr.size(); 
    
    for(int num = 0;num<(1<<n);num++) {
        int sum = 0;
        for(int i = 0;i<n;i++) {
            if(num & (1<<i)) {
                sum += arr[i]; 
            }
        }
        summ.push_back(sum); 
    }
    
}

int meet_in_the_middle_algo(int n, int s, vector<int> &arr){
    int cnt = 0;
    vector<int> left,right;

    for(int i = 0 ; i < n/2 ; i++){
        left.push_back(arr[i]);
    }

    for(int i = (n/2) ; i < n ; i++){
        right.push_back(arr[i]);
    }

    vector<int> sum1,sum2;

    populate(sum1,left);
    populate(sum2,right);



    sort(sum2.begin(),sum2.end());

    for(auto it: sum1){
       
        int s1 = s - it;
        int ind = lower_bound(sum2.begin(),sum2.end(),s1) - sum2.begin();

        cnt += ind;           
    }

    return cnt;
}

signed main() {

	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
#ifndef ONLINE_JUDGE
	freopen("input.txt" , "r" , stdin);
	freopen("output.txt" , "w" , stdout);
#endif

    vector<int> a {1,3,5,6,7};

    int s = 7;



    cout << meet_in_the_middle_algo(a.size(),s,a) << endl;
	return 0;
}
