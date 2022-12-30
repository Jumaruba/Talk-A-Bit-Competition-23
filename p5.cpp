
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


bool traverse_dfs(vector<int> &A, int size, int sum, int start) {
    if (size == 0)
        return sum == 0;
    for (int i = start; i < A.size() && sum >= A[i] * size; i++)
        if (traverse_dfs(A, size - 1, sum - A[i], i + 1))
            return true;
    return false;
}

string solve(vector<int>& A) {
    int size = A.size(), sum = 0;
    for (auto num : A)
        sum += num;
    sort(A.begin(), A.end());
    for (int i = 1; i <= size / 2; i++)
        if (i * sum % size == 0 && traverse_dfs(A, i, i * sum / size, 0))
            return "true";
    return "false";
}

int main(){
    ANMR
    int t, aux;
    vector<int> v; 
    cin >> t;
    while (t--) {
        cin >> aux; 
        v.push_back(aux);
    }
    cout << solve(v) << endl;

}