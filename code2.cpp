#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool isPrime(int num) {
    if (num < 2) return false;
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) return false;
    }
    return true;
}

vector<int> formatArray(vector<int> arr) {
    vector<int> primes, nonPrimes;
    for (int num : arr) {
        if (isPrime(num)) {
            primes.push_back(num);
        } else {
            nonPrimes.push_back(num);
        }
    }

    sort(primes.begin(), primes.end());
    sort(nonPrimes.rbegin(), nonPrimes.rend());

    vector<int> result;
    if (!primes.empty()) {
        result.push_back(primes.back());
    }
    result.insert(result.end(), nonPrimes.begin(), nonPrimes.end());
    if (!primes.empty()) {
        result.push_back(primes.front());
    }

    return result;
}

int main() {
    vector<int> arr1 = {1,8, 11, 2};


    vector<int> result1 = formatArray(arr1);
  

    for (int num : result1) cout << num << " ";
}