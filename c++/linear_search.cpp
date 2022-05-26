#include <bits/stdc++.h>
using namespace std;

int main()
{
        int n, find;
        cin >> n >> find;
        vector<int> v(n);
        vector<int> index;
        for(int i=0; i<n; ++i)
        {
                cin >> v[i]; 
        }
        for(int i=0; i<n; ++i)
        {
                if(v[i] == find)
                {
                        index.push_back(i+1);
                }
        }

        if(!index.size()){
                cout << "Err 404 - Not Found\n";
                return 0;
        }

        cout << "The element " << find << " is present at position(s): ";
        for(int i=0; i<index.size(); ++i)
        {
                cout << index[i] << ' ';
        }
        cout << "\n";
        return 0;
}