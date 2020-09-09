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
#define tc(t)           int t;cin >> t;while(t--)
#define for0(i , n)     for(int i=0;i<n;i++)
#define loop(i , a, b)  for(int i=a;i<=b;i++)
#define endl '\n'
int X[2000005],Y[2000005];
int fib(int n){
    int mat[2][2],ans[2][2];
    mat[0][0] = 1;
    mat[0][1] = 1;
    mat[1][0] = 1;
    mat[1][1] = 0;

    ans[0][0] = ans[0][1] = ans[1][0] = ans[1][1] = 1;

    int x = n-1;

    while(x){
        if(x%2 == 0){
            int temp[2][2];
            temp[0][0] = temp[0][1] = temp[1][0] = temp[1][1] = 1;
            temp[0][0] = mat[0][0] * mat[0][0] + mat[0][1] * mat[1][0];
            temp[0][1] = mat[0][0] * mat[0][1] + mat[0][1] * mat[1][1];
            temp[1][0] = mat[1][0] * mat[0][0] + mat[1][1] * mat[1][0];
            temp[1][1] = mat[1][0] * mat[0][1] + mat[1][1] * mat[1][1];

            mat[0][0] = temp[0][0];
            mat[0][1] = temp[0][1];
            mat[1][0] = temp[1][0];
            mat[1][1] = temp[1][1];

            x = x/2;
        }else{
            x = x-1;
            int temp[2][2];
            temp[0][0] = temp[0][1] = temp[1][0] = temp[1][1] = 1;
            temp[0][0] = ans[0][0] * mat[0][0] + ans[0][1] * mat[1][0];
            temp[0][1] = ans[0][0] * mat[0][1] + ans[0][1] * mat[1][1];
            temp[1][0] = ans[1][0] * mat[0][0] + ans[1][1] * mat[1][0];
            temp[1][1] = ans[1][0] * mat[0][1] + ans[1][1] * mat[1][1];         

            ans[0][0] = temp[0][0];
            ans[0][1] = temp[0][1];
            ans[1][0] = temp[1][0];
            ans[1][1] = temp[1][1];     
        }
    }

    return ans[0][0];
}

int gcd(int a,int b, int &x , int &y){
    if(a == 0){
        x = 1;
        y = 1;
        return b;
    }

    int x1,y1;
    int d = gcd(b%a, a , x1, y1);
    x = y1 - (b/a)*x1;
    y = x1;

    return d;
}

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
    vector<int> left(n/2),right(n-(n/2));

    for(int i = 0 ; i < n/2 ; i++){
        left.push_back(arr[i]);
    }

    for(int i = (n/2) ; i < n ; i++){
        right.push_back(arr[i]);
    }

    vector<int> sum1,sum2;

    populate(sum1,left);
    populate(sum2,right);

    for(auto i: sum1){
        cout << i << " ";
    }

    cout << endl;

    for(auto i: sum2){
        cout << i << " ";
    }

    cout << endl;
    
    sort(sum2.begin(),sum2.end());

    for(auto it: sum1){
        int s1 = s - it;
        int ind = lower_bound(sum2.begin(),sum2.end(),s1) - sum2.begin();
        cnt += ind;           
    }

    return cnt;
}

void calcsubarray(vector<int> &a, int x[], int n, int c) 
{ 
    for (int i=0; i<(1<<n); i++) 
    { 
        int s = 0; 
        for (int j=0; j<n; j++) 
            if (i & (1<<j)) 
                s += a[j+c]; 
        x[i] = s; 
    } 
}

int solveSubsetSum(vector<int> &a, int n, int S) 
{ 

    calcsubarray(a, X, n/2, 0); 
    calcsubarray(a, Y, n-n/2, n/2); 
  
    int size_X = 1<<(n/2); 
    int size_Y = 1<<(n-n/2); 

    int cnt = 0;
  
    sort(Y, Y+size_Y); 
  
    int max = 0; 
    for (int i=0; i<size_X; i++) 
    { 
        if (X[i] <= S) 
        { 
            int p = lower_bound(Y, Y+size_Y, S-X[i]) - Y; 
            cnt += p; 
        } 
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

    //cout << a.size() << endl;

    cout << meet_in_the_middle_algo(a.size(),s,a) << endl;

    return 0;
}

























 

