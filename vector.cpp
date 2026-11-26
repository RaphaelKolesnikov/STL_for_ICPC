#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void show(vector<int> const &v) {
    cout << "show vector: ";
    for (auto it = v.begin(); it != v.end(); ++it) cout << *it << " ";
    cout << endl;
}

int main() {

    vector<int> v1, v2;

    v1.push_back(1);        // вставить в конец, O(1) амортизированно
    v1.push_back(2);
    v1.pop_back();          // удалить с конца, O(1)

    v2.reserve(5);          // заранее выделить память, O(n), избегаем реаллокаций
    v2.push_back(1); v2.push_back(7); v2.push_back(3);
    v2.push_back(11); v2.push_back(5);

    for (int i = 0; i < 10; i++) v1.push_back(i * 2);

    cout << "v1 & v2: " << endl;
    show(v1); show(v2);

    cout << "size / capacity: " << v1.size() << " " << v1.capacity() << endl; // size O(1), capacity O(1)
    // size - сколько элементов реально, capacity - сколько памяти выделено

    cout << "front / back: " << v1.front() << " " << v1.back() << endl; // O(1)

    cout << "v1[3]: " << v1[3] << endl;   // доступ по индексу, O(1), без проверки границ
    cout << "v1.at(3): " << v1.at(3) << endl; // то же, но с проверкой границ, кидает исключение

    v1[3] = 100;         // менять элементы можно 
    show(v1);

    auto it = v1.begin();
    it++;                // итератор random access: it++, it--, it+5, it-2
    v1.erase(it);        // удаление по итератору, O(n) — сдвиг всех элементов влево
    show(v1);

    v1.erase(v1.begin()); // удаление первого элемента, O(n) 
    show(v1);

    v1.insert(v1.begin() + 1, 42); // вставка в середину, O(n)
    show(v1);

    v1.clear();                    // очистить всё, O(n)
    cout << "v1.empty(): " << v1.empty() << endl; // проверка на пустоту, O(1)
    cout << "v1.size(): " << v1.size() << endl;   // размер, O(1)

    v1 = v2; show(v1);

    // count в векторе нет, считаем вручную или через алгоритм
    cout << "count 3: " << count(v1.begin(), v1.end(), 3) << endl; // O(n), #include <algorithm>

    // find тоже через алгоритм, возвращает итератор или end(), O(n)
    it = find(v1.begin(), v1.end(), 3);
    if (it != v1.end()) cout << "find(3): " << *it << endl;

    cout << endl << "lower/upper bounds (только на отсортированном!)" << endl;
    sort(v1.begin(), v1.end());   // sort, O(n log n), #include <algorithm>
    it = lower_bound(v1.begin(), v1.end(), 7); // первый элемент >= x, O(log n)
    cout << *it << ", ";
    it = upper_bound(v1.begin(), v1.end(), 7); // первый элемент > x, O(log n)
    cout << *it << endl;

    reverse(v1.begin(), v1.end()); // развернуть, O(n)
    show(v1);

    // 2D вектор
    vector<vector<int>> g(3, vector<int>(4, 0)); // 3 строки по 4 нуля
    g[1][2] = 5;

    return 0;
}