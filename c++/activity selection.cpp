#include<iostream> 
#include<algorithm>
using namespace std; 

struct activity
{ 
    int start, finish; 
}; 

bool comp(activity a1, activity a2) 
{ 
    return (a1.finish < a2.finish); 
}

void print(activity a[], int n) 
{ 
    int i = 0, j;
    sort(a, a+n, comp); 
    cout<< "Selected activities: ";  
    cout<< "(" << a[i].start << ", " << a[i].finish << "); "; 
    for(j = 1; j < n; j++){ 
      if (a[j].start >= a[i].finish){ 
          cout << "(" << a[j].start << ", "<< a[j].finish << "); "; 
          i = j; 
      } 
    } 
} 

int main() 
{ 
    activity a[] = {{6, 10}, {4, 8}, {3, 9}, {1, 5}, {3, 7}, {8, 10}}; 
    int n = sizeof(a)/sizeof(a[0]); 
    print(a, n); 
    return 0; 
}