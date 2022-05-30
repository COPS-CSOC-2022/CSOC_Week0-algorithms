/*.................................................____________.....
.........../\......|\     |....../\......|\     |..     |      .....
........../  \.....| \    |...../  \.....| \    |..     |      .....
........./    \....|  \   |..../    \....|  \   |..     |      .....
......../______\...|   \  |.../______\...|   \  |..     |      .....
......./        \..|    \ |../        \..|    \ |..     |      .....
....../          \.|     \|./          \.|     \|..     |      .....
....................................................................
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef long double ld;
#define ff first
#define ss second
#define pb push_back
#define rep(i,a,b) for(int i = a; i < b; i++)
#define rev(i,a,b) for(int i = a; i >= b; i--)
#define vpii vector<pair<int, int>>
#define vi vector<int>
#define mod 1000003
#define endl "\n"
#define pi 3.14159265358979323846
#define SET(n) cout << fixed << setprecision(n)


int bin_exp(int a, int n)
{
    int res=1;
    while (n){
        if (n%2){
            res = (res*a);
            n--;
        }
        else{
            a = (a*a);
            n/=2;
        }
    }
    return res;
}

int power(long long x, unsigned int y, int p)
{
    int res = 1;    
 
    x = x % p; 
  
    if (x == 0) return 0; 
 
    while (y > 0)
    {
        if (y & 1)
            res = (res*x) % p;
 
        y = y>>1; 
        x = (x*x) % p;
    }
    return res;
}

string decimalToBinary(ll n)
{

    string s = bitset<64>(n).to_string();

    const auto loc1 = s.find('1');

    if (loc1 != string::npos)
    return s.substr(loc1);

    return "0";
}

ll lis(ll arr[], ll n)
{
    ll lis[n];
 
    lis[0] = 1;
 
    rep(i, 0, n){
        lis[i] = 1;
        rep(j, 0, i)
            if (arr[i] > arr[j] && lis[i] < lis[j] + 1)
                lis[i] = lis[j] + 1;
    }
 
    return *max_element(lis, lis + n);
}

void anant_jain_01(){
  int n;
  cin>>n;
  ll arr[n];
  rep(i, 0, n){
    cin>>arr[i];
  }
  printf("Length of lis is %d\n", lis(arr, n));
}


int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int t = 1, i=1;
    // cin >> t;
    while (t--){
        anant_jain_01();
    }
    return 0;
}

