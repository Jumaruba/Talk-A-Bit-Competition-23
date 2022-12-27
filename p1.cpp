#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
#define ull unsigned long long
#define ul unsigned long

// MEDIUM
// Inspired in: https://leetcode.com/problems/possible-bipartition/description/
// CONTROL STRUCTURES
#define F0R(i, a) for (int i=0; i<(a); i++)
#define FIR(i, a) for (int i=1; i<(a); i++)
#define all(vec)  vec.begin(),  vec.end()
#define ANMR cin.tie(0)->sync_with_stdio(0);

bool dfs(int node, vector<vector<int>>& neigh, vector<short int> &colors){
    for (int i: neigh[node]){
        if (colors[i] == colors[node]) return false;
        if (colors[i] == 0){
            colors[i] = colors[node] == 1? 2: 1; 
            if (!dfs(i, neigh, colors)) return false;
        } 
    }
    return true; 
}
bool solve(int n, vector<vector<int>>& dislikes) {
    vector<vector<int>> neigh(n, vector<int>());
    vector<short int> colors(n);  // 0: no color, 1: color1, 2: color2
    int a1, a2; 
    for (int i = 0 ; i < dislikes.size(); i++){
        a1 = dislikes[i][0] - 1;
        a2 = dislikes[i][1] - 1;
        neigh[a1].push_back(a2);
        neigh[a2].push_back(a1);
    }


    for (int i = 0 ; i < n; i++) {
        if (!colors[i]){
            colors[i] = 1;
            if (!dfs(i, neigh, colors)) return false;
        }
    }
    
    return true; 
}



int main(){
    ANMR
    int n, v_size, a1, a2;
    vector<int> a3; 
    cin >> n;
    cin >> v_size; 
    vector<vector<int>> v(v_size);
    for (int i = 0 ; i < v_size; i++){
        cin >> a1 >> a2; 
        v[i] = {a1,a2};
    }
    string res = solve(n,v) ? "true": "false";
    cout << res << endl;

}