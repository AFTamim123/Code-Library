// بِسْمِ ٱللَّٰهِ ٱلرَّحْمَٰنِ ٱلرَّحِيمِ
// In the Name of Allah, the Beneficent, the Merciful.
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL)
#define int long long

int koro(vector<int> v, int pos) {
    int ans = 0;
    for (int i = 0; i < v.size(); i++)
    {
        ans+=abs(v[i]-pos);
    }
    return ans;
}


void solve(int TC) {
    int n; cin>>n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) cin>>v[i];
    for (int i = 0; i < n; i++) v[i]-=i+1;
    sort(v.begin(), v.end());

    int lo=0,hi=1e12,ans=LONG_LONG_MAX;
    
    while (hi-lo>4)
    {
        int m1 = (hi+lo)>>1LL;
        int m2 = (hi+lo)/2 + 1;

        int a1 = koro(v, m1);
        int a2 = koro(v, m2);
        if(a1>a2) lo = m1;
        else hi = m2;
        
    }
    
    for (int i = lo-4; i <= hi+4; i++)
    {
        ans = min(ans, koro(v,i));
    }
    
    cout<<ans<<endl;

}
int32_t main() {
    fastio;
   
    int tc=1; 
    // cin>>tc;
    for (int TC = 1; TC <= tc; TC++) solve(TC);

    return 0;
}

// https://codeforces.com/blog/entry/60702
// https://atcoder.jp/contests/abc102/tasks/arc100_a
// https://codeforces.com/contest/1520/problem/E
