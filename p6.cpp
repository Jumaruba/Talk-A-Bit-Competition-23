#include <bits/stdc++.h>
using namespace std;

// CONTROL STRUCTURES
#define FOR(i, a) for (int i=0; i<(a); i++)
#define all(vec)  vec.begin(),  vec.end()
#define ANMR cin.tie(0)->sync_with_stdio(0);

int solve(int t){
    int r = 0, a;
    FOR(i, t) {
        cin >> a; 
        r^= a;
    }
    return r; 
}

int main(){
    ANMR
    int t;
    cin >> t;
    cout << solve(t) << endl;
}