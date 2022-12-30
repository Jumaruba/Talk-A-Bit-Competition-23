#include <bits/stdc++.h>
using namespace std;
#define ull unsigned long long  // [0, 18*10^18]
#define ul unsigned long
#define ll long long int

// CONTROL STRUCTURES
#define FOR(i, a) for (int i=0; i<(a); i++)
#define FIR(i, a) for (int i=1; i<(a); i++)
#define all(vec)  vec.begin(),  vec.end()
#define ANMR cin.tie(0)->sync_with_stdio(0);
// CONSTANTS
const ll INF32 = INT32_MAX;
const int MOD = 1000000007;

ll solve(int t){
    vector<ll> v(t);
    ll res = 1;
    FOR(i, t) cin >> v[i]; 
    sort(v.begin(), v.end()); 
    for(ull i = 0 ; i < t; i++ ){
        if (v[i] > res) return res;
        res = res + v[i];
    }
    return res; 
}
int main(){
    ANMR
    int t;
    cin >> t;
    cout << solve(t) << endl;

}