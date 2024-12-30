#include<bits/stdc++.h>
using namespace std;

void PrintArray(const int* arry, size_t num) {
    for (size_t i = 0; i < num; i++) {
        cout << "arry[" << i << "]: " << arry[i] << endl;
    }
}

int main () {
    /*
     * 配列
     */
    int arr1[5] = {0, 1 , 2 , 3, 4};
    cout << "arr1[1]: " << arr1[1] << endl;

    // 中身が決まっていれば要素数はなくてOK
    int arr2[] = {0, 1 , 2 , 3, 4};

    // 要素数のみ指定なら、中はゼロ埋めされる
    int zeroArr[5] = {};

    /*
     * 配列ポインタ
     */
    int* pArr = arr1;
    // ポインタ配列に対し要素指定しなかったら先頭を参照
    cout << "pArr: " << *pArr << endl;
    cout << "pArr+1: " << *(pArr + 1) << endl;

    /*
     * 関数に配列を渡す場合
     * ・引数に配列を渡す時、ポインタ解釈される。
     * ・ポインタ配列だけだと要素数が読み取れないため、別途渡す必要がある。
     * ・Cからの仕様なのでしようがない
     */
    constexpr size_t num = 5;
    int printer[num] = {10, 11, 12, 13, 14};
    PrintArray(printer, num);

    // std::array
    array<int, 5> list = {0, 1, 2, 3, 4};
    cout << "list[3]: " << list[3] << endl;
    // array.size()で要素数が取れる
    cout << "list.size: " << list.size() << endl;

    /*
     * 文字列 std::string
     */
    string s = "Hello";
    cout << "s: " << s << endl;
    // char配列みたいな感じ。
    // sizeはバイト換算なのでマルチバイト入ってると実際の文字列と合わない。
    cout << "s[0]: " << s[0] << endl;
    cout << "s.size: " << s.size() << endl;

    /*
     * タプル std::tuple
     * ・他言語での配列はこっちが近いか
     */
    tuple<string, int> person {"Tarou", 18};
    // tuple<string, int> person("Tarou", 18); // 初期化手段その2
    // tuple<string, int> person = make_tuple("Tarou", 18); // 初期化手段その3
    cout << "get<0>(person): " << get<0>(person) << endl;
    // タプルの内容を変数にまとめて設定できる
    string name;
    int age;
    tie(name, age) = person;
    cout << "name: " << name << endl;
    cout << "age: " << age << endl;

    // ペアなんてのもある
    pair<string, int> pair_p("Jirou", 17);

    /*
     * ベクタ std::vector
     * ・要素追加できるから、こっちが他言語の配列っぽいのかも
     */
    vector<int> vector_i = {0, 1, 2, 3, 4};
    cout << "vector_i[3]: " << vector_i[3] << endl;
    cout << "vector_i.size: " << vector_i.size() << endl;
    // 末尾要素の追加
    vector_i.emplace_back(5);
    cout << "vector_i.size: " << vector_i.size() << endl;
    // 末尾要素の削除
    vector_i.pop_back();
    cout << "vector_i.size: " << vector_i.size() << endl;
    // 先頭要素のポインタ取得
    cout << "vector_i.data: " << *vector_i.data() << endl;

    /*
     * マップ std:map/std:unordered_map
     * 他言語でいう連想配列がこれ。
     * ・違いは、mapがキーによるソート、unordered_mapがキーハッシュ管理。
     * ・unordered_mapのほうが、パフォーマンスが優れている。キー順序は担保されない。
     * ・また、unorderedはイテレータを前にしか進められない。
     * ・通常版は前後に行き来できる。
     */
    unordered_map<string, int> persons = {
        {"Hanako", 17},
        {"Natsuko", 16},
    };
    cout << "Hanako's age: " << persons["Hanako"] << endl;
    // 要素追加
    persons.insert({"Akiko", 15});
    cout << "Akiko's age: " << persons["Akiko"] << endl;
    // 要素削除
    persons.erase("Natsuko");

    /*
     * セット std:set/std:unordered_set
     * ・マップの単一要素版というイメージ
     */
    unordered_set<string> names = {
        "Bob",
        "Clark",
    };

    /*
     * イテレータ
     * ・いわばポインタ版indexみたいなもの。
     * ・コンテナの種類に依存しないで利用することができる。
     */
    auto names_it = names.begin();
    cout << "names_it: " << *names_it << endl;
    // イテレータを進めれば、参照する要素も変化する
    ++names_it;
    cout << "names_it: " << *names_it << endl;
    // for文と組み合わせられる
    for (auto it = vector_i.begin(); it != vector_i.end(); ++it) {
        cout << *it << endl;
    }

    /*
     * std::count_if
     * 関数オブジェクト的なことができる
     */
    auto n = count_if(list.begin(), list.end(), [](const int v) {
        if (v <= 0) {
            return false;
        }
        if (v % 2 != 0) {
            return false;
        }
        return true;
    });
    cout << n << endl;

    // マップのイテレータ
    for (auto it = persons.begin(); it != persons.end(); ++it) {
        const auto person = *it;
        const string name = person.first;
        const int age = person.second;
        cout << name << ": " << age << endl;
    }

    // シンプルに書くこともできる
    for (auto&& e : vector_i) {
        cout << e << endl;
    }
}