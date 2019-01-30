/*
  ------------------------- Hachiikung ---------------------------------
  ---------------------- Worrachate Bosri ------------------------------
*/
#include <bits/stdc++.h>
using namespace std;

const int MAXN(1000005); // define maximum size of array/string

char dna[MAXN];   // input string
int p[MAXN];      // p[i] is 31^i, use for hash function
int dp[MAXN][15]; // store the maximum number of repetition of the substring
                  // which the last index is j and the length of primitive substring is l

void init_p(int n)
{ // set the value of 31^i from i = 0 to i = n
    p[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        p[i] = p[i - 1] * 31;
    }
}

// The hash value of substring is represented in base-31 number
// and do not care the overflow, still have a low chance for a collision
// The value of A is 1, C = 3, G = 7, T = 20

long long getHashR(long long x, char y)
{ // get the hash value when adding digit to the right
    return x * 31 + (y - 'A' + 1);
}

long long getHashL(long long x, char y, int l)
{ // get the hash value when adding digit to the left
    return (y - 'A' + 1) * 1ll * p[l] + x;
}

void printSubString(int f, int l)
{ // print substring from index f to l
    for (int i = f; i <= l; i++)
        printf("%c", dna[i]);
}

int main()
{
    // Choose input file to run

    freopen("input1.txt", "r", stdin);
    // freopen("input2.txt", "r", stdin);
    // freopen("input3.txt", "r", stdin);

    scanf("%s", dna); // input string

    int length = strlen(dna);  // get the length of string
    int minimumSubLength = 3;  // set the minimum primitive substring length (problem variant)
    int maximumSubLength = 10; // set the maximum primitive substring length (problem variant)

    init_p(length); // set the value of 31^i

    // The main algorithm
    // Iterate of all the substring from left to right
    // ans check the substring of the same length adjacent to left
    // if it is the same string (same hash value)
    // then update the value to the array dp (dynamic programming approach)

    // Complexity
    // Time: O(N^2) N is the length of string
    // Memory: O(N*maximum primitive substring), O(N^2) in general case

    for (int i = 0; i < length; i++)
    {
        long long hashL = 0, hashR = 0;

        for (int j = i, k = j - 1; j < length; j++, k--)
        { // consider substring(i, j) and substring(k, i-1)

            int subLength = j - i + 1;

            if (subLength > maximumSubLength)
                break; // stop loop if substring length is more than 10

            hashR = getHashR(hashR, dna[j]); // get the hash value for substring(i, j)
            if (k >= 0)
                hashL = getHashL(hashL, dna[k], subLength - 1); // get the hash value for substring(k, i-1)
                                                                // do not process if k < 0

            if (subLength < 3)
                continue; // do not process if substring length is less than 3

            dp[j][subLength] = 1; // initial value of repetition is one

            if (k < 0)
                continue; // if k < 0 then there is no adjacent left substring, do not process

            if (hashR == hashL)
            {
                dp[j][subLength] += dp[i - 1][subLength]; // update repetition of the right substring
                dp[i - 1][subLength] = 1;                 // and reset repetition of the left substring
            }
        }
    }

    // print output
    // my output is all repeat substring which the primitive substring is between 3 to 10
    // and number of repeat is more than 1

    printf("{\n");

    for (int i = 0; i < length; i++)
        for (int j = 1; j <= maximumSubLength; j++)
            if (dp[i][j] > 1)
            {
                printf("  \'");

                int startPos = i - dp[i][j] * j + 1;
                printf("%d-", startPos);
                printSubString(startPos, startPos + j - 1);

                printf("\': ");

                printf("%d\n", dp[i][j]);
            }

    printf("}");
}
