#include <iostream>
#include <cstdio>
#include <algorithm>
#include <map>
#include <set>
#include <stack>
#include <unordered_map>
#include <vector>
#define  nl "\n"
#define  ll long long   
using namespace std;



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n; cin>>n;
    int sol = 0;
    vector<ll> a(n);
    for (int i = 0; i < n; i++){
        cin>>a[i];
    }
    for (int i = 0; i < n; i++){
        int j = i;
        while (j + 1 < n && 2 * a[j] >= a[j + 1]){
            j++;
        }
        sol = max(sol, j - i + 1);
        i = j;
    }
    cout << sol << nl;

}