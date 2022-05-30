#include <iostream>
using namespace std;
#define n 10

int main()
{
    int arr[n];
    {
        for (int _i = 0; _i < n; _i++)
            cin >> arr[_i];
    }
    int s;
    cin >> s;
    int flag = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == s)
        {
            flag++;
            cout << "Element found at index: " << i + 1;
            break;
        }
    }
    if (!flag)
        cout << "Element not found";
    return 0;
}