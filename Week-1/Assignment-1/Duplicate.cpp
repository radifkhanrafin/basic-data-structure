#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

string findDuplicate(vector<int>& array) {
    unordered_set<int> seenValues;
    for (int num : array) {
        if (seenValues.count(num) > 0) {
            return "YES";
        }
        seenValues.insert(num);
    }
    return "NO";
}

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    
    string result = findDuplicate(A);
    cout << result << endl;

    return 0;
}
