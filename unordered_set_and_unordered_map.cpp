#include <iostream>
#include <unordered_set>
#include <unordered_map>

using namespace std;

int main() {
    unordered_set<int> s;

    auto it = s.insert(1);
    cout << *it.first << ", " << it.second << endl; // вставить, амортиз. O(1). Возвращает pair<iterator,bool>

    it = s.insert(1);
    cout << *it.first << ", " << it.second << endl; // выведет false если элемент уже есть

    s.emplace(2); // то же, но конструирует на месте (амортиз. О(1))
    s.clear();

    s = {3, 1, 2, 5};

    for (auto it = s.begin(); it != s.end(); ++it) {
        std::cout << *it << " ";
    }

    cout << endl << (s.find(5) == s.end()); // проверка на пустоту
    // по сути почти весь синтаксис схожий, разве что здесь множество не упорядоченное и сложность операций другая
    // здесь все операции делаются амортизировано за О(1), но в худшем случае за О(n), главные функции возвращают
    // то же самое, что и обычный set. С map/unordered_map всё то же самое
    return 0;
}