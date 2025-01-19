#include <iostream>
#include <vector>
#include <climits>
using namespace std;

long long maxEvenSubsequence(int n, vector<int>& arr) {
    long long max_even = 0; 
    long long min_odd_prefix = LLONG_MAX; 
    long long min_even_prefix = 0; 
    long long prefix_sum = 0;  

    for (int num : arr) {
        prefix_sum += num; 

        if (prefix_sum % 2 == 0) {
            max_even = max(max_even, prefix_sum); 
            max_even = max(max_even, prefix_sum - min_even_prefix); 
            min_even_prefix = min(min_even_prefix, prefix_sum); 
        } else {
            max_even = max(max_even, prefix_sum - min_odd_prefix); 
            min_odd_prefix = min(min_odd_prefix, prefix_sum); 
        }
    }

    return max_even == 0 ? -1 : max_even; 
}

int main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int n;
    cin >> n;
    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    long long result = maxEvenSubsequence(n, arr);

    if (result == -1) {
        cout << "NOT_FOUND" << endl;
    } else {
        cout << result << endl;
    }

    return 0;
}
