/*
 * Pre-order, In-order, Post-order Traversal Simulation
 * Approach: Print before recursive calls (pre), between calls (in), after calls (post)
 * Time: O(2^n) - binary tree structure
 * Space: O(n) recursive stack
 * Key: Demonstrates when code executes relative to recursive calls
 */
#include<iostream>

void PreInPost(int n)
{
    if(n==0) return;
    printf("pre %d\n",n);
    PreInPost(n-1);
    printf("in %d\n",n);
    PreInPost(n-1);
    printf("post %d\n",n);
    
}

int main()
{
    int n;
    printf("enter the number: ");
    scanf("%d",&n);

    PreInPost(n);
}