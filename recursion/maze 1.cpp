/*
 * Count Paths in Grid (Top-Left to Bottom-Right)
 * Approach: From (n,m) count paths by going right (n,m-1) + down (n-1,m)
 * Time: O(2^(n+m)) - exponential without memoization
 * Space: O(n+m) recursive stack
 * Key: Only right and down moves allowed; base case when reaching (1,1)
 */
#include<iostream>

int maze(int n,int m)
{
    int rightside =0;
    int dowenside =0;

    if(n==1 && m==1)
    return 1;
    if(n<=1)
    rightside += maze(n,m-1);
    else if(m<=1)
    dowenside +=maze(n-1,m);
    else{
        rightside +=maze(n,m-1);
        dowenside +=maze(n-1,m);
    }

    return rightside + dowenside;


}

int main()
{
    int n,m,ma;
    printf("enter the rows: ");
    scanf("%d",&n);
    printf("enter the coluns: ");
    scanf("%d", &m );

    ma = maze(n,m);
    printf("\nThe value is %d ",ma);
}