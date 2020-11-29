#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
#define debg(x)	cerr<<(#x)<<" => "<<x<<'\n';
#define debgg(x,y)	cerr<<(#x)<<" => "<<x<<'\t'<<(#y)<<' '<<y<<'\n';
#define len(a) (int)(a).size()
#define all(x) x.begin(),x.end()
#define mod 10000007
//#define mod 998244353

void printarr(int arr[], int n){
    for(int i = 0; i < n; ++i)
        cerr<<arr[i]<<(i<n-1?' ':'\n');
}
template < typename T> void  printv(T &a){
    for(auto it = a.begin(); it != a.end(); ++it)
        cerr<<*it<<' ';
    cerr<<'\n';
}
    

//int t[510][510];
ll ans;
int arr[300009];

void solve()
{
    bool ok = false;
    int n,m,k;  cin>>n;
    for(int i = 0; i < n;++i){
        cin>>arr[i];
    }
    ans = 0;

    cout<<'\n';
}
void sol()
{
    //test
}
void fastio(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
}

int main()
{
    //fastio();
    fastio();
    int testcases;  cin>>testcases;
    for(int t = 0; t < testcases; ++t)
        solve();
    return 0;
}


/*
Sunday 29 November 2020 12:00:36 PM IST
     author:   __astrainL3gi0N
*/
