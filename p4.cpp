#include <bits/stdc++.h>
using namespace std;
#define ull unsigned long long
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

void solve(int route){
    int stops, val, maxVal = -1, currVal = -1, currBegin = 0, maxBegin = 0, maxEnd = 0; 
    cin >> stops; 
    
    for (int i = 0; i < stops; i++){
        cin >> val; 
        if (currVal < 0){
            currVal = val; 
            currBegin = i; 
        } else currVal += val; 
        if (currVal == maxVal){
            if (i - currBegin > maxEnd - maxBegin) {
                maxBegin = currBegin; 
                maxEnd = i; 
            } else if (currBegin -i == maxEnd - maxBegin && maxBegin > currBegin){
                maxBegin = currBegin;
                maxEnd = i; 
            }
        } else if (currVal > maxVal){
            maxBegin = currBegin;
            maxEnd = i; 
            maxVal = currVal; 
        } 
    }
    
    if (maxVal >= 0) {
        cout <<  route <<  " " << maxBegin << " " << maxEnd  << endl;  
    } else {
        cout << route <<" None" << endl; 
    }
}
int main(){
    ANMR
    int t;
    cin >> t;
    FOR(i, t) {
        solve(i+1);
    }

}