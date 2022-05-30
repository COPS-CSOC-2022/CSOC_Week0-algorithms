#include <iostream>
#include <vector>
using namespace std;


int main()
{
    vector<int> v {97, 95, 92, 93, 94, 4, 7};

    int n = v.size();
    for (int i = 0; i < n - 1; i++)
        for (int j = i; j < n - 1; j++)
            if (v[j] > v[j + 1])
                swap(v[j], v[j + 1]);

    for (int i = 0; i < n; i++)
        cout << v[i] << ' ';

    cout << '\n';

    return 0;
}