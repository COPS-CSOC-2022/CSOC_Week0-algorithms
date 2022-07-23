#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(x) (x).begin(), (x).end()

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n;
    cout<<"Enter the number of elements: "<<endl;
    cin>>n;
    int a[n];
    cout<<"Enter the elements: "<<endl;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int find;
    cout<<"Enter the number to search: "<<endl;
    cin>>find;
    bool flag=0;
    for(int i=0;i<n;i++){
        if(a[i]==find){
            cout<<find<<" is found on index = "<<i<<"\n";
            bool flag = 1;
        }
    }
    if(flag) cout<<"NOT FOUND\n";

    return 0;
}