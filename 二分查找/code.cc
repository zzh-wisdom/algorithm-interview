#include <iostream>
#include <vector>
#include <assert.h>
using namespace std;

// 寻找第一个大于等于target的下标
int my_lower_bound(vector<int> &nums, int target)
{
    // 左闭右开
    int low = 0;
    int high = nums.size();
    int mid;
    while (low < high) {
        mid = low + ((high - low) >> 1);// 防止溢出 等同于(left + right)/2
        if(nums[mid] < target) {
            low = mid + 1;
        } else {
            high = mid;
        }
    }
    return low;
}

int std_lower_bound(vector<int> &nums, int target) {
    int first = 0;
    int index, step;
    int count = nums.size();
    while(count > 0) {
        step = count >> 1;
        index = first + step;
        if(nums[index] < target) {
            first = ++index;
            count -= step+1;
        } else {
            count = step;
        }
    }
    return first;
}

// 寻找第一个大于target的下标
int my_upper_bound(vector<int> &nums, int target)
{
    // 左闭右开
    int low = 0;
    int high = nums.size();
    int mid;
    while (low < high) {
        mid = low + ((high - low) >> 1);// 防止溢出 等同于(left + right)/2
        if(nums[mid] <= target) {
            low = mid + 1;
        } else {
            high = mid;
        }
    }
    return low;
}

class Solution {
public:
    int mySqrt(int x) {
        int l = 0, r = x, ans = -1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if ((long long)mid * mid <= x) {
                ans = mid;  // 保留结果的方式，就不用在意区间的开闭
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return ans;
    }
};

int std_upper_bound(vector<int> &nums, int target) {
    int first = 0;
    int index, step;
    int count = nums.size();
    while(count > 0) {
        step = count >> 1;
        index = first + step;
        if(!(target < nums[index])) {
            first = ++index;
            count -= step+1;
        } else {
            count = step;
        }
    }
    return first;
}

int main() {
    vector<int> a = {1, 1, 1, 2, 2, 2, 3, 3, 3, 4, 4, 4, 5, 7, 8, 8, 9, 10};
    printf("lower_bound:\n");
    for(auto target: a) {
        int my_index = my_lower_bound(a, target);
        int std_index = std_lower_bound(a, target);
        printf("target: %d, my_index: %d, std_index: %d\n", target, my_index, std_index);
        if(my_index != std_index) {
            return -1;
        }
    }
    printf("upper_bound:\n");
    for(auto target: a) {
        int my_index = my_upper_bound(a, target);
        int std_index = std_upper_bound(a, target);
        printf("target: %d, my_index: %d, std_index: %d\n", target, my_index, std_index);
        if(my_index != std_index) {
            return -1;
        }
    }
    return 0;
}
