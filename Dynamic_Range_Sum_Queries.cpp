//Author : Sayem Islam
// Generated on 2026-05-31 08:00:31


#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define MOD 1000000007
#define mx 200005
vector<int>v(mx);
int t[mx*4];
void init(int id,int s,int e){
    if(s==e){
        t[id]=v[s];
        return;
    }
    int mid=(s+e)/2;
    init(2*id,s,mid);
    init(2*id+1,mid+1,e);
    t[id]=t[2*id]+t[2*id+1];
    
}

int ask(int id,int s,int e,int i,int j){
    if(s>=i && e<=j) return t[id];
    if(s>j || e<i) return 0;
    int mid=(s+e)/2;
    int left=ask(2*id,s,mid,i,j);
    int right=ask(2*id+1,mid+1,e,i,j);
    return left+right;


}
void upd(int id,int s,int e,int i,int val){
    if(s==i && e==i){
        t[id]=val;
        return;
    }
    if(s>i || e<i ){
        return;
    }
    int mid=(s+e)/2;
    upd(2*id,s,mid,i,val);
    upd(2*id+1,mid+1,e,i,val);
    t[id]=t[2*id]+t[2*id+1];
}

void solve()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,q;
    cin>>n>>q;
    for(int i=1;i<=n;++i){
        cin>>v[i];
    }
    init(1,1,n);
    while(q--){
        int x,y,z;
        cin>>x>>y>>z;
        if(x==1){
            upd(1,1,n,y,z);

        }
        else {
            cout<<ask(1,1,n,y,z)<<endl;

        }

    }
    


    
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc = 1;
    //cin >> tc;

    for (int i = 1; i <= tc; i++)
    {
        solve();
    }

    return 0;
}