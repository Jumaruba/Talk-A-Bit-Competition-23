#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<vector>
#include<unordered_map>
using namespace std;
#define ull unsigned long long
#define ul unsigned long

// CONTROL STRUCTURES
#define FOR(i, a) for (int i=0; i<(a); i++)
#define FIR(i, a) for (int i=1; i<(a); i++)
#define all(vec)  vec.begin(),  vec.end()
#define ANMR cin.tie(0)->sync_with_stdio(0);
// EASY 
// Inspired in https://cses.fi/problemset/task/1637
/*
int solve(int n, unordered_map<int,int>& um){
    if (n < 10) return 1;
    if (um.find(n) != um.end()) return um[n];
    string ns = to_string(n);
    int ans = INT32_MAX, newN; 
    for (char c: ns){
        // Don't process '0', otherwise we gonna have an infinite loop.
        if (c != '0') { 
            newN = n-(c-'0');
            ans = min(solve(newN, um), ans);
        }
    }
    um[n] = ans + 1;

    return ans + 1;
}*/

int solve(int n) {
    vector<int> dp(n+1, INT32_MAX); 
    dp[0] = 0;  
    int aux; 
    for (int i = 1; i <= n; i++) {
        aux = i; 
        while(aux != 0) { 
            dp [i] = aux%10 == 0? dp[i] :min(dp[i], dp[i-aux%10]+1);
            aux /= 10;
        }
    }
    return dp[n];
}

int main(){
    ANMR
    int t;
    cin >> t;
    unordered_map<int,int> um; 
    //cout << solve(t, um) << endl; 
    cout << solve(t) << endl;

}