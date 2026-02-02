//insert an element
#include <stdio.h>

int main() 
{
    int n, val, pos;
    printf("Enter number of elements: ");
    scanf("%d",&n);
    int arr[n+1];
    printf("Enter elements: ");

    for(int i=0;i<n;i++) 
    {
     scanf("%d",&arr[i]);
    }
    
    printf("Enter position and value to insert: ");
    scanf("%d %d",&pos,&val);

    for(int i=n;i>pos;i--) arr[i]=arr[i-1];
    {
    arr[pos]=val;
    }
    printf("Array after insertion: ");
    for(int i=0;i<=n;i++)
    {
     printf("%d ",arr[i]);
     printf("\n");
    }

    return 0;
}
