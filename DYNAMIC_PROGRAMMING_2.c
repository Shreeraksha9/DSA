//contiguous sub-array with maximum sum//

#include <stdio.h>

int maxSumSubArray(int arr[], int n)
{
    int maxValue = arr[0];
    int dp[n];

    for(int i = 0; i < n; i++) {
        dp[i] = arr[i];
    }

    for(int i = 1; i < n; i++) {
        if((arr[i] + dp[i-1]) > dp[i]) {
            dp[i] = dp[i-1] + arr[i];
        }
    }

    for(int i = 0; i < n; i++) {
        if(dp[i] > maxValue) {
            maxValue = dp[i];
        }
    }

    return maxValue;
}

int main() {
    int n;
    printf("ENTER THE NUMBER OF ARRAY ELEMENTS\n");
    scanf("%d", &n);

    int arr[n];
    printf("ENTER THE ARRAY ELEMENTS\n");
    for(int i = 0; i < n; i++) {

        scanf("%d", &arr[i]);
    }
    printf("THE MAXIMUM CONTAGIOUS SUM IS\n");

    printf("%d\n", maxSumSubArray(arr, n));

    return 0;
}

