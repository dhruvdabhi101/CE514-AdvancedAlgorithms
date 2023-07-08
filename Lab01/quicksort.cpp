#include <iostream>
#include <vector>
using namespace std;


int random(int start, int end) {
    return (rand() % (end - start + 1)) + start;
}


int partition(vector<int> &nums, int start, int end) {
    int x = nums[end];  
    int i = start - 1;
    int j;
    for (j = start; j < end; j++) {
        if (nums[j] <= x) {
            i = i + 1;
            swap(nums[i], nums[j]);
        }
    }
    swap(nums[i + 1], nums[end]);  
    return i + 1;  
}


int randomized_partition(vector<int> &nums, int start, int end) {
    int i = random(start, end);
    swap(nums[i], nums[end]);  
    return partition(nums, start, end);
}


void quickSort(vector<int> &nums, int start, int end) {
    if (start < end) {
        int p = randomized_partition(nums, start, end);  
        quickSort(nums, start, p - 1);  
        quickSort(nums, p + 1, end);  
    }
}

int main() {
    vector<int> nums {7, 94, 163, 53, 196, 121, 72, 218, 5, 207, 152, 130, 61, 83, 229, 174, 94, 112, 185, 103};
    quickSort(nums, 0, nums.size() - 1);  
    for (auto c: nums) {
        cout << c << " ";  
    }
    cout << endl;
    return 0;
}
