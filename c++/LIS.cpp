// OM GANESHAYA NAMAH

#include<bits/stdc++.h>
// #include<ext/pb_ds/assoc_container.hpp>
// #include<ext/pb_ds/tree_policy.hpp>

using namespace std;
// using namespace __gnu_pbds;

// template<class T> using ordered_set = tree<T, null_type, less<T>,rb_tree_tag, tree_order_statistics_node_update>;
typedef long long int ll;
#define ff first
#define ss second
#define pb push_back
#define rep(i,a,b)  for(ll i = a; i < b; i++)
#define rev(i,b,a)  for(ll i = b; i >= a; i--)
#define vpii vector<pair<ll,ll>>
#define endl "\n"
#define mod 1000000007
#define pi 3.14159265358979323846
#define SET(n) cout << fixed << setprecision(n)
#define vll vector<ll>
#define all(x) (x).begin(), (x).end()
#define vi    vector<int>



ll binexp(ll a, ll b, ll m)
{
    ll res = 1;
    while (b > 0)
    {
        if (b & 1)
        {
            res = (res * 1LL * a) % m;
        }
        a = (a * 1LL * a) % m;
        b >>= 1;
    }
    return res;
}

ll binpow(ll a, ll b)
{
    if (b == 0)
        return 1;
    ll res = binpow(a, b / 2);
    if (b % 2)
        return res * res * a;
    else
        return res * res;
}
bool isPrime(int n)
{
    if (n <= 1)
        return false;

    for (int i = 2; i <= sqrt(n); i++)
        if (n % i == 0)
            return false;

    return true;
}
string decimalToBinary(ll n)
{

    string s = bitset<64>(n).to_string();

    const auto loc1 = s.find('1');

    if (loc1 != string::npos)
        return s.substr(loc1);

    return "0";
}
ll binaryToDecimal(string n)
{
    string num = n;
    ll dec_value = 0;
    ll base = 1;

    ll len = num.length();
    for (ll i = len - 1; i >= 0; i--)
    {
        if (num[i] == '1')
            dec_value += base;
        base = base * 2;
    }

    return dec_value;
}
int binarySearchCount(int arr[], int n, int key)
{
    int left = 0;
    int right = n - 1;

    int count = 0;

    while (left <= right) {
        int mid = (right + left) / 2;

        // Check if middle element is
        // less than or equal to key
        if (arr[mid] >= key) {

            // At least (mid + 1) elements are there
            // whose values are less than
            // or equal to key

            right = mid - 1;
        }

        else if(arr[mid]<key){
          left=mid+1;
        }
    }

    return left;
}

ll LIS(ll arr[], ll n)
{
    ll a[n];

    a[0] = 1;

    rep(i,1,n) {

        a[i] = 1;

        rep(j,0,i){
          if (arr[i] > arr[j] && a[i] < a[j] + 1){
            a[i] = a[j] + 1;
          }
        }
    }

    return *max_element(a, a + n);
}

void solve(){


}


int main(){
//  std::ios::sync_with_stdio(false);
//  cin.tie(NULL);
//  cout.tie(NULL);

  //INPUT AND OUTPUT FILES
  // freopen("input.txt", "r", stdin);
  // freopen("output.txt", "w", stdout);



    ll n;
    cout<<"Enter the size of the array of elements : "<<endl;
    cin>>n;
    ll a[n];
    cout<<"Enter the elements of the array  : "<<endl;
    rep(i,0,n)cin>>a[i];

    cout<<"The length of the longest increasing subsequence is :"<<LIS(a,n)<<endl;




  return 0;
}
