#include <bits/stdc++.h>
using namespace std;
 
void naivesearch(char* p, char* t)
{
    int l1,l2,k=0;
    l1= strlen(p);
    l2= strlen(t);
 
   
    for (int i = 0; i <= l2-l1; i++) {
        
       k=0;
        for ( int j = 0; j <l1; j++){
            if (t[i + j] != p[j])
                break;
               
             else
             k++;


        }
 
        if (k == l1) 
            cout << "pattern found at index "
                 << i << endl;
    }
}
 

int main()
{
    char t[] = "PQPPQQQPQPPQPQQQP";
    char p[] = "QPPQ";
    naivesearch(p, t);
    return 0;
}
