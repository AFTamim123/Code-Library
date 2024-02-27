#include <bits/stdc++.h>
using namespace std;
 
int32_t main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    int n;
    cin>>n;
    vector<int> v(n);
    for(auto &it: v) cin>>it;

    int ans = LONG_LONG_MIN,sum=0;
    for (int i = 0; i < n; i++) {
        sum= max(v[i], sum+v[i]);
        ans = max(ans, sum);
    }
    ans = max(ans, sum);
 
    cout<<ans<<endl;
    
 
    return 0;
}