#include <stdio.h>
#include <vector>
#include <string.h>

using namespace std;

int global_g_in0 = 0;
int global_g_in1 = 1;
int global_g_unin;

static int global_s_in0 = 0;
static int global_s_in1 = 1;
static int global_s_unin;

static char s_c_in[20] = "123456789";
static char s_c_unin[20];



char* my_strstr(char* str1, char* str2) {
    int n = strlen(str1);
    int m = strlen(str2);
    vector<int> next(m);
    next[0] = 0;
    int j = 0;
    // for(int)
    // printf("%d %d\n", n, m);
    for(int i = 0; i <= n-m; ++i) {
        int j = 0;
        for(; j < m; ++j) {
            if(str1[i+j] != str2[j]) break;
        }
        if(j == m) return str1 + i;
    }
    return NULL;
}

void getNext(vector<int>& next, char* str) {
    int j = 0;
    next[0] = 0;
    int m = strlen(str);
    for(int i = 1; i < m; ++i) {
        while(j > 0 && str[j] != str[i]) {
            j = next[j-1];
        }
        if(str[j] == str[i]) ++j;
        next[i] = j;
    }
}

char* StrStr(char* str1, char* str2) {
    int n = strlen(str1);
    int m = strlen(str2);
    vector<int> next(m);
    getNext(next, str2);
    int j = 0;
    for(int i = 0; i < n; ++i) {
        while(j > 0 && str2[j] != str1[i]) {
            j = next[j-1];
        }
        if(str2[j] == str1[i]) ++j;
        if(j == m){
            return str1 + i - m + 1;
        }
    }
    return nullptr;
}

int main() {
    char str1[11] = "1234567890";
    char str2[4] = "901";
    // char* str = my_strstr(str1, str2);
    char* str = StrStr(str1, str2);
    printf("%s\n", str);
    // printf("%s, %d\n", s_c_unin, num);
    return 0;
}
