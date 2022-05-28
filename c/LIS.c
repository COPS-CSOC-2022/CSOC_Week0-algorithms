# include<stdio.h>
void LIS(int a[],int n)
{
    int count=1;
    for(int i=1,j=0;i<n && j<n;i++)
    {
        if(a[i]>a[j])
        {
            j=i;
            count++;
        }
    }
     printf("%d",count);
}
int main()
{
int n;
printf("Enter size of the array :\n");
scanf("%d",&n);
int a[n];
for(int i=0;i<n;i++)
{
    printf("Enter the %d element :\n",i+1);
    scanf("%d",&a[i]);
}
printf("The length of the LIS is : \n");
LIS(a,n);
return 0;
}