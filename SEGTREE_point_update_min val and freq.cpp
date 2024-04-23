#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define vi vector<int>
#define vl vector<long long>
#define ll long long
#define F first
#define S second
#define pii pair<int,int>
#define inv(a) for(auto &it : a) cin >> it;
#define outv(a) for(auto &it : a) cout << it << " ";cout<<"\n"
#define outv1(a) for(auto &it : a) cout << it << " "<<"\n";cout<<"\n"
#define pb push_back
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define yes cout<<"YES\n"
#define no cout<<"NO\n"
#define inf LONG_LONG_MAX
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL)
#define int long long 

const int N = 1e5+5;
int arr[N];

struct node {
    int ele,freq;
};
node tr[4*N];

node merge(node left, node right) {
    node notun;
    int m = min(left.ele, right.ele);
    int f = 0;
    if(m==left.ele) f+=left.freq;
    if(m==right.ele) f+=right.freq;
    notun.ele=m;
    notun.freq=f;
    return notun;
}
void build(int idx, int b, int e) {
    if(b==e) {
        tr[idx].ele=arr[b],
        tr[idx].freq=1;
        return;
    }
    int left = idx*2+1, right = idx*2+2;
    int mid = (b+e)>>1LL;
    build(left, b, mid);
    build(right, mid+1, e);
    tr[idx]=merge(tr[left], tr[right]);
}

node query(int idx, int b, int e, int l, int r) {
    // ! overlap
    if(e<l || r<b) {
        node notun;
        notun.ele=inf;
        notun.freq=0;
        return notun;
    }
    // full overlap
    if(b>=l && e<=r) return tr[idx];
    int mid = (b+e)>>1LL;
    return merge(
        query(2*idx+1, b, mid, l, r),
        query(2*idx+2, mid+1, e, l, r)
    );
}   


void update(int idx, int b, int e, int pos, int val){

    if(b==e) {
        tr[idx].ele=val;
        tr[idx].freq=1;
        return;
    }
    int mid = (b+e)>>1LL;
    if(pos<=mid) update(2*idx+1, b, mid, pos, val);
    else update(2*idx+2, mid+1, e, pos, val);

    tr[idx]=merge(tr[2*idx+1], tr[2*idx+2]);

}
int32_t main() {
    fastio;
    fastio;
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int n,q;
    cin>>n>>q;
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    build(0,0,n-1);
    while (q--)
    {
        int x; cin>>x;
        if(x==1) {
            int pos,val; cin>>pos>>val;
            update(0,0,n-1,pos,val);
        }
        else {
            int l,r;
            cin>>l>>r;
            r--;
            node koto = query(0,0,n-1,l,r);
            cout<<koto.ele<<" "<<koto.freq<<endl;
        }
    }
    
    
    
    

    return 0;
}