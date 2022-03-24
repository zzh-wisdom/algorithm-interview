#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// inline bool copy_increase(uintptr_t dst, uintptr_t src, int size) {
//     if((dst&size) == 0) return false;
//     switch (size)
//     {
//     case 1:
//         *((uint8_t*)dst) = *((uint8_t*)src);
//         break;
//     case 2:
//         *((uint16_t*)dst) = *((uint16_t*)src);
//     case 3:
//         *((uint16_t*)dst) = *((uint16_t*)src);
//     default:
//         break;
//     }
// }

// inline void copy_decrease(uintptr_t dst, uintptr_t src, int size) {

// }

void MyMemcpy(void* dst, void* src, unsigned int len) {
    // 先注意区间覆盖的问题
    if(dst == src || len == 0) return;
    if(dst < src) { // 从小到大
        uintptr_t dst_ptr = (uintptr_t)dst;
        uintptr_t src_ptr = (uintptr_t)src;
        // 前面的char
        for(; len > 0 && dst_ptr&(sizeof(uint64_t)-1); --len) {
            *((char*)dst_ptr) = *((char*)src_ptr);
            ++dst_ptr;
            ++src_ptr;
        }
        // 中间的uint64
        for(; len >= sizeof(uint64_t); len -= sizeof(uint64_t)) {
            *((uint64_t*)dst_ptr) = *((uint64_t*)src_ptr);
            dst_ptr += sizeof(uint64_t);
            src_ptr += sizeof(uint64_t);
        }
        // 后面的char
        for(; len > 0; --len) {
            *((char*)dst_ptr) = *((char*)src_ptr);
            ++dst_ptr;
            ++src_ptr;
        }
    } else { // 从大到小
        uintptr_t dst_ptr = (uintptr_t)dst + len;
        uintptr_t src_ptr = (uintptr_t)src + len;
        // 后面的char
        for(; len > 0 && dst_ptr&(sizeof(uint64_t)-1); --len) {
            --dst_ptr;
            --src_ptr;
            *((char*)dst_ptr) = *((char*)src_ptr);
        }
        // 中间的uint64
        for(; len >= sizeof(uint64_t); len -= sizeof(uint64_t)) {
            dst_ptr -= sizeof(uint64_t);
            src_ptr -= sizeof(uint64_t);
            *((uint64_t*)dst_ptr) = *((uint64_t*)src_ptr);
        }
        // 前面的char
        for(; len > 0; --len) {
            ++dst_ptr;
            ++src_ptr;
            *((char*)dst_ptr) = *((char*)src_ptr);
        }
    }
}

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
};

vector<int> MidPrint(TreeNode* root) {
    vector<int> ret;
    stack<TreeNode*> s;
    while(!s.empty() || root) {
        while(root) {
            s.push(root);
            root = root->left;
        }
        root = s.top();
        s.pop();
        ret.push_back(root->val);
        root = root->right;
    }
    return ret;
}

int main() {
    return 0;
}