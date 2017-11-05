// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com

#include <iostream>
using namespace std;

bool regexMatch(char str[], int i, char pattern[], int j){
    if (str[i] == '\0' && pattern[j] == '\0'){
        return true;
    }

    if (str[i] == '\0' || pattern[j] == '\0'){
        return false;
    }

    if (str[i] == pattern[j] || pattern[j] == '?'){
        return regexMatch(str, i + 1, pattern, j + 1);
    }

    if (pattern[j] == '*'){
        int ans1 = regexMatch(str, i, pattern, j + 1);  //match zero char
        int ans2 = regexMatch(str, i + 1, pattern, j);  //matches more char
        return ans1 || ans2;
    }

    return false;
}

int main() {
    char str[100];
    char pattern[100];
    cin >> str >> pattern;

    cout << regexMatch(str, 0, pattern, 0);

}