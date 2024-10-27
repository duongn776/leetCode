#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1;
        int j = n - 1;
        int k = m + n - 1;
        
        while (i >= 0 && j >= 0) {
            if (nums1[i] > nums2[j]) {
                nums1[k] = nums1[i];
                i--; 
            } else {
                nums1[k] = nums2[j];
                j--; 
            }
            k--;
        }

        while (j >= 0) {
            nums1[k] = nums2[j];
            j--; 
            k--; 
        }
    }
};

void printVector(const vector<int>& vec) {
    for (int num : vec) {
        cout << num << " ";
    }
    cout << endl;
}

int main() {
    Solution solution;

    // Test Case 1
    vector<int> nums1 = {1, 2, 3, 0, 0, 0};
    int m = 3;
    vector<int> nums2 = {2, 5, 6};
    int n = 3;
    solution.merge(nums1, m, nums2, n);
    cout << "Test Case 1: ";
    printVector(nums1);  // Expected output: 1 2 2 3 5 6

    // Test Case 2
    nums1 = {0};
    m = 0;
    nums2 = {1};
    n = 1;
    solution.merge(nums1, m, nums2, n);
    cout << "Test Case 2: ";
    printVector(nums1);  // Expected output: 1

    // Test Case 3
    nums1 = {1, 2, 3};
    m = 3;
    nums2 = {};
    n = 0;
    solution.merge(nums1, m, nums2, n);
    cout << "Test Case 3: ";
    printVector(nums1);  // Expected output: 1 2 3

    // Test Case 4
    nums1 = {0, 0, 0};
    m = 0;
    nums2 = {1, 2, 3};
    n = 3;
    solution.merge(nums1, m, nums2, n);
    cout << "Test Case 4: ";
    printVector(nums1);  // Expected output: 1 2 3

    return 0;
}
