// C++ Program for Palindrome Partitioning Problem
// using Recursion
#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

// Function to Check if a substring is a palindrome
bool isPalindrome(string& s, int i, int j) {
    while (i < j) {
        if (s[i] != s[j])
            return false;
        i++;
        j--;
    }
    return true;
}

// Recursive Function to find the minimum number of 
// cuts needed for palindrome partitioning
int palPartitionRec(string& s, int i, int j) {
  
    // Base case: If the substring is empty or 
      // a palindrome, no cuts needed
    if (i >= j || isPalindrome(s, i, j))
        return 0;

    int res = INT_MAX, cuts;

    // Iterate through all possible partitions and 
      // find the minimum cuts needed
    for (int k = i; k < j; k++) {
        cuts = 1 + palPartitionRec(s, i, k)
                    + palPartitionRec(s, k + 1, j);
        res = min(res, cuts);
    }

    return res;
}

int palPartition(string &s) {
      return palPartitionRec(s, 0, s.size()-1);
}

int main() {
    string s = "a bab bbabb ababa";

    cout << palPartition(s) << endl;
    return 0;
}