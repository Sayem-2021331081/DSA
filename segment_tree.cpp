///   ***   ---   ||         In the name of ALLAH        |||   ---   ***   ///
 
 
 
#include<bits/stdc++.h>
using namespace std;
 
 
typedef long long ll;

const int mx = 2e5+123;
ll t[mx*4], a[mx];
 
void init ( int id, int b, int e )
{
    if ( b == e ) {
        t[id] = a[b];
        return;
    }
 
    int mid = ( b + e ) >> 1;
    init ( id*2, b, mid );
    init ( id*2+1, mid+1, e );
 
    t[id] = t[id*2] + t[id*2+1];
}
 
void upd ( int id, int b, int e, int i, int val )
{
    if ( b > i || e < i ) return;
    if ( b == e && b == i ) {
        t[id] = val;
        return;
    }
 
    int mid = ( b + e ) >> 1;
    upd ( id*2, b, mid, i, val );
    upd ( id*2+1, mid+1, e, i, val );
 
    t[id] = t[id*2] + t[id*2+1];
}
 
ll ask ( int id, int b, int e, int l, int r )
{
    if ( b > r || e < l ) return 0;
    if ( l <= b && e <= r ) {
        return t[id];
    }
 
    int mid = ( b + e ) >> 1;
    ll sumL = ask ( id*2, b, mid, l, r );
    ll sumR = ask ( id*2+1, mid+1, e, l, r );
 
    return sumL + sumR;
}
 
int main()
{
    
 
    int n, q;
    cin >> n >> q;
 
    for ( int i = 1; i <= n; i++ ) cin >> a[i];
    init ( 1, 1, n ); /// O(nlog2(n))
 
    while ( q-- ) { /// O(qlog2(n))
        int typ;
        cin >> typ;
        if ( typ == 1 ) {
            int k, u;
            cin >> k >> u;
            upd ( 1, 1, n, k, u ); /// O(log2(n))
        }
        else {
            int l, r;
            cin >> l >> r;
            cout << ask ( 1, 1, n, l, r ) << endl; /// O(log2(n))
        }
    }
 
    return 0;
}
 
 
 
 
 
 
 
 
 
 
 