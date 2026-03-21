// Count Subarrays with Sum Zero
// Problem: Given an array of integers, count the number of subarrays whose sum is equal to zero.
#include <stdio.h>

int main() {

    int n;
    int arr[100];
    int prefix[200] = {0}; 

    scanf("%d",&n);

    for(int i=0;i<n;i++)
        scanf("%d",&arr[i]);

    int sum = 0;
    int count = 0;

    prefix[100] = 1; // sum = 0 initially

    for(int i=0;i<n;i++){

        sum += arr[i];

        if(prefix[sum + 100] > 0)
            count += prefix[sum + 100];

        prefix[sum + 100]++;
    }

    printf("%d\n",count);

    return 0;
}
