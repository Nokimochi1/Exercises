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
    int n,t;
    int sol = 0;
    cin>>n>>t;
    vector <int> a(n);
    for (int i = 1; i<n; i++){
        cin>>a[i];        
    }
    int current = 1;
    int i = 1;
    while (i < n){
        current = a[i] + i;
        if (current > t){
            cout << "NO" << nl;
            break;
        } 
        if (current == t){
            cout << "YES" << nl;
            break;
        }
        i = current;
    }

}