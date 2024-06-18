/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <string.h>

#define MAX_WORDS 100
#define MAX_WORD_LEN 50

char dictionary[MAX_WORDS][MAX_WORD_LEN];
int wordCount;

// Function to correct a misspelled word
void correctWord(char misspelled[], char suggested[]) {
    // Implement the correction logic, e.g., using LCS or another method
    // For simplicity, we'll just copy the word as a suggestion
    strcpy(suggested, misspelled);
}

// Function to merge suggestions from left and right sub-dictionaries
void mergeCorrections(char leftCorrections[][MAX_WORD_LEN], int leftCount, char rightCorrections[][MAX_WORD_LEN], int rightCount, char mergedCorrections[][MAX_WORD_LEN]) {
    for (int i = 0; i < leftCount; i++) {
        strcpy(mergedCorrections[i], leftCorrections[i]);
    }
    for (int i = 0; i < rightCount; i++) {
        strcpy(mergedCorrections[leftCount + i], rightCorrections[i]);
    }
}

// Function to perform spelling correction using divide and conquer
void spellingCorrectionDivideConquer(char misspelled[], int left, int right, char suggestions[][MAX_WORD_LEN]) {
    if (left > right) {
        return;
    }

    // Base case: If there's only one word in the dictionary, correct the misspelled word
    if (left == right) {
        correctWord(misspelled, suggestions[0]);
        return;
    }

    int mid = (left + right) / 2;
    char leftCorrections[MAX_WORDS][MAX_WORD_LEN];
    char rightCorrections[MAX_WORDS][MAX_WORD_LEN];

    spellingCorrectionDivideConquer(misspelled, left, mid, leftCorrections);
    spellingCorrectionDivideConquer(misspelled, mid + 1, right, rightCorrections);

    mergeCorrections(leftCorrections, mid - left + 1, rightCorrections, right - mid, suggestions);
}

int main() {
    char misspelled[MAX_WORD_LEN];
    char suggestions[MAX_WORDS][MAX_WORD_LEN];

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

    // Perform spelling correction
    spellingCorrectionDivideConquer(misspelled, 0, wordCount - 1, suggestions);

    // Print suggestions
    for (int i = 0; i < wordCount; i++) {
        printf("Suggested correction: %s\n", suggestions[i]);
    }

    return 0;
}
