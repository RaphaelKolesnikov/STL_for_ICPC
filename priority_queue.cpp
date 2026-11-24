#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void show(priority_queue<int> const &pq) { // правильный вывод с копией, иначе элемент удалится
    auto copy = pq;
    cout << "priority_queue: ";
    while (!copy.empty()) {
        cout << copy.top() << " ";
        copy.pop(); // O(log n), т.к. при удалении надо вернуть свойство кучи
    }
    cout << endl;
}

int main() {
    vector<int> v = {5, 1, 3, 2, -7, 0, 4};
    priority_queue<int> pq(v.begin(), v.end());   // создание кучи за O(n), в цикле с push O(n log n)

    priority_queue<int> v1, empty;
    v1.push(3); // кладем значение, O(log n)
    cout << v1.top() << endl; // доступ к вершине, O(1)

    show(pq); cout << pq.size() << ", " << pq.empty();
    pq.swap(empty); // Обмен O(1): pq становится пустым, старый буфер уходит в empty.
    // Память вернётся, когда empty умрёт (в конце main).

    priority_queue<int, vector<int>, greater<int>> minpq(v.begin(), v.end()); // способ задать min-heap

    return 0;
}