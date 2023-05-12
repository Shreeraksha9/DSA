//LONGEST PALINDROME STRING//

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char* maxpalindrome(char s[])
{
    int start = 0, n, i, j, maxlen = 1;
    n = strlen(s);
    int dp[n][n];
    memset(dp, 0, sizeof(dp));
    for(i = 0; i < n; i++) {
        dp[i][i] = 1;
    }
    for(i = 0; i < n-1; i++) {
        if(s[i] == s[i+1]) {
            dp[i][i+1] = 1;
            if(maxlen == 1) {
                start = i;
                maxlen = 2;
            }
        }
    }

    for(int k = 3; k <= n; k++) {
        for(i = 0; i < n-k+1; i++) {
            j = i+k-1;
            if(dp[i+1][j-1] && s[i] == s[j]) {
                dp[i][j] = 1;
                if(k > maxlen) {
                    maxlen = k;
                    start = i;
                }
            }
        }
    }

    char* res = (char*) malloc((maxlen + 1) * sizeof(char));
    for(i = start; i < start + maxlen; i++) {
        res[i-start] = s[i];
    }
    res[maxlen] = '\0';
    return res;
}

int main()
{
    char s[1000];
    printf("ENTER THE STRING\n");
    scanf("%s", s);
    char* result = maxpalindrome(s);
    printf("THE HIGHEST PALINDROME IS\n");
    printf("%s\n", result);
    free(result);

    return 0;
}
