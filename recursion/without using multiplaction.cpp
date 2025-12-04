/*
 * Multiplication Without Using * Operator
 * Approach: a * b = a + a + ... (b times); use recursion to add 'a' repeatedly
 * Time: O(b)
 * Space: O(b) recursive stack
 * Key: Base case b=0 returns 0; each call adds 'a' once
 */
#include<iostream>

int muil(int a,int b)
{
    
    if (b==0) return 0;
    int k = a + muil(a,b-1);
    return k;
}
int main()
{
    int a,b;
    printf("enter the number that you want to multiplay : ");
    scanf("%d",&a);
    printf("enter the number that you multipiye uith : ");
    scanf("%d",&b);

    printf("%d", muil(a,b));
    return 0;
}