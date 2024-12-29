#include<bits/stdc++.h>
#include<cstdint>
#include<functional>
using namespace std;

// 前方宣言
void proccess(int argc, char* argv[]);

int Add(int a, int b) {
    return a + b;
}

int main(int argc, char* argv[]) {
    proccess(argc, argv);
}

void proccess (int argc, char* argv[]) {
    // 変数
    int x = 5;
    cout << x << endl;

    int imu_x;
    cout << imu_x << endl;

    // 定数
    const int const_x = 4;
    // Error
    //const_x = 10;
    cout << const_x << endl;

    // 定数（コンパイル時に値評価、変数を値に指定できない）
    int y = 6;
    const int const_y = y; // これはOK
    cout << y << endl;
    cout << const_y << endl;
    //const int expr_y = y; // これはコンパイルエラーが起こる。
    const int expr_y = 7;
    cout << expr_y << endl;

    // 型推論
    auto auto_z = 8;
    cout << auto_z << endl;

    // bool
    bool ok = true;
    cout << ok << endl;

    // char
    char c = 'c';
    cout << c << endl;

    // 整数型
    short number_s = 16;
    int number_i = 32;
    long number_l = 64;
    cout << number_s << endl;
    cout << number_i << endl;
    cout << number_l << endl;
    // unsignedもいける
    unsigned short nus = 16;
    unsigned int nui = 32;
    unsigned long nul = 64;
    cout << nus << endl;
    cout << nui << endl;
    cout << nul << endl;
    // 上記はコンパイラごとにサイズが異なるらしい。
    // 複数のコンパイラを考慮するなら、サイズ指定付き整数型にする。
    // 使うにはcstdintをincludeする必要がある。
    std::int32_t int32x = 32;
    std::uint32_t uint32x = 64;
    cout << int32x << endl;
    cout << uint32x << endl;

    // 浮動小数展型
    float number_f = 0.32;
    double number_d = 0.64;
    cout << number_f << endl;
    cout << number_d << endl;

    // 列挙型(enum)
    enum Day {
        Sun = 1,
        Mon = 2,
        Tur = 3,
        Wed = 4,
        Thu = 5,
        Fri = 6,
        Sat = 7,
    };
    Day day = Sun;
    cout << day << endl;
    // enumの値を代入することはできる
    int friday = Fri;
    cout << friday << endl;
    // もちろん、enumに直接値を入れることはできない
    //Day day = 5; // エラー

    // 列挙型クラス
    enum class Week {
        Sun = 1,
        Mon = 2,
        Tur = 3,
        Wed = 4,
        Thu = 5,
        Fri = 6,
        Sat = 7,
    };
    Week week = Week::Mon;
    cout << static_cast<int>(week) << endl;

    // リテラル
    // 以下はすべて"26"となる
    cout << 26 << endl;   // 十進数
    cout << 032 << endl;  // 八進数
    cout << 0x1a << endl; // 十六進数

    // ポインタ
    int index = 10;
    int* pointer = &index;
    cout << index << endl;
    cout << pointer << endl;
    // nullは色々あって"nullptr"を使う
    int* nullpointer = nullptr;
    // デリファレンス（逆参照）
    int derindex = *pointer;
    cout << derindex << endl;
    // constにもポインタが使える
    const int* con_int = &index;
    //*con_int = 11; // const後にポインタ指定すると、ポインタ値の更新ができなくなる。
    int* const con_int_2 = &index;
    //con_int_2 = nullpt; // const前にポインタ指定すると、従来のconstっぽくなる。

    // 参照
    int& ref = index;
    cout << ref << endl;
    *pointer = 20;
    cout << ref << endl;

    // if文
    if (x == 5) {
        cout << "x is " << x << endl;
    } else {
        cout << "x is wrong." << endl;
    }

    // switch分
    switch (x) {
        case 0:
            cout << "x was empty." << endl;
            break;
        default:
            cout << "x was " << x << endl;
            break;
    }

    // while文
    int count = 1;
    bool done = false;
    while (!done) {
        cout << "count is " << count << endl;
        if (count >= 5) {
            done = true;
        }
        count++;
    }

    // for文
    for (int i = 0; i < 10; ++i) {
        cout << "for " << i << endl;
    }

    /*
     * 四則演算
     */
    // 加算
    cout << x + y << endl;
    // 減算
    cout << x - y << endl;
    // 乗算
    cout << x * y << endl;
    // ゼロ乗算は不可(実行時エラー)
    //cout << x * 0 << endl;
    // 除算
    cout << x / y << endl;
    // ゼロ除算は不可(実行時エラー)
    //cout << x / 0 << endl;
    // 剰余
    cout << x % y << endl;

    // 引数
    for (int i = 0; i < argc; i++) {
        cout << "argv[" << i << "]: " << argv[i] << endl;
    }

    // ラムダ式
    // int を2つ受け取り、足した結果を返すラムダ式
    auto lambda = [](int a, int b) -> int {
        return a + b;
    };
    int result = lambda(x, y);
    cout << "result is " << result << "." << endl;

    // std::function
    std::function<int(int, int)> func = Add;
    int funcRes = func(3,5);
    cout << "funcRes: " << funcRes <<endl;
}