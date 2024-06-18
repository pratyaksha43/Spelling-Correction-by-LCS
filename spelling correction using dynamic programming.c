/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <string.h>

#define MAX_WORDS 100
#define MAX_WORD_LEN 50

char dictionary[MAX_WORDS][MAX_WORD_LEN];
int wordCount;

// Function to calculate the LCS of two strings using dynamic programming
int longestCommonSubsequence(char str1[], char str2[]) {
    int m = strlen(str1);
    int n = strlen(str2);

    int dp[m + 1][n + 1];

    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
            else if (str1[i - 1] == str2[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = (dp[i - 1][j] > dp[i][j - 1]) ? dp[i - 1][j] : dp[i][j - 1];
        }
    }

    return dp[m][n];
}

// Function to correct a misspelled word using LCS
void correctWord(char misspelled[], char suggestion[]) {
    int maxLCS = -1;
    int lcs;

    for (int i = 0; i < wordCount; i++) {
        lcs = longestCommonSubsequence(misspelled, dictionary[i]);
        if (lcs > maxLCS) {
            maxLCS = lcs;
            strcpy(suggestion, dictionary[i]);
        }
    }
}

int main() {
    char misspelled[MAX_WORD_LEN];
    char suggestion[MAX_WORD_LEN];

    // Initialize the dictionary
    wordCount = 7;
    strcpy(dictionary[0], "apple");
    strcpy(dictionary[1], "banana");
    strcpy(dictionary[2], "cherry");
    strcpy(dictionary[3], "grape");
    strcpy(dictionary[4], "lemon");
    strcpy(dictionary[5], "lime");
    strcpy(dictionary[6], "orange");

    // Input a misspelled word
    printf("Enter a misspelled word: ");
    scanf("%s", misspelled);

    // Correct the misspelled word using LCS
    correctWord(misspelled, suggestion);

    // Print the suggested correction
    printf("Suggested correction: %s\n", suggestion);

    return 0;
}
