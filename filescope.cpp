#include <bits/stdc++.h>
#include "a.h"
using namespace std;

// グローバル変数
int x = 20;

// 名前空間スコープ
namespace NA {
    int count = 2;
}

// inline関数
inline void InlineMan() {
    cout << "I am THE man!" << endl;
}

int main() {
    HelloWorld();

    cout << NA::count << endl;

    int x = 40;
    // ローカルスコープ
    cout << x << endl;
    // ::グローバルスコープ
    cout << ::x << endl;

    InlineMan();
    return 0;
}