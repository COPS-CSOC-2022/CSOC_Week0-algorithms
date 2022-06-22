#include<stdio.h>
void subsetsum(int i,int set[],int sum,int n)
{
    if(i==n)
    {
        printf("%d ",sum);
        return;
    }

    subsetsum(i+1,set,sum+set[i],n);
    subsetsum(i+1,set,sum,n);

}
void main()
{
    int n;
    printf("Enter the length of set\n");
    scanf("%d",&n);
    int set[n];
    printf("Enter the element of the set\n");
    for(int i=0;i<n;i++)
        scanf("%d",&set[i]);
    printf("\nthe sum of all possible subsets are:\n\n");


    subsetsum(0,set,0,n);
    printf("\n");
}
