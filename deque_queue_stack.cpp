#include <iostream>
#include <deque>
#include <queue>
#include <stack>

using namespace std;

void show(deque<int> const &dq) {
    cout << "deque: ";
    for (auto it = dq.begin(); it != dq.end(); ++it) cout << *it << " ";
    cout << endl;
}

int main() {
    // -------------------------- deque ----------------------------
    cout << "----------------------- deque: ------------------------" << endl;
    deque<int> dq = {5, 1}; show(dq);

    dq.push_back(7); // вставка в конец за О(1)
    dq.push_front(3); // вставка в начало О(1)
    show(dq);

    cout << "dq[1]: " << dq[1] << endl; // доступ по индексу O(1) 

    cout << dq.back() << endl; // последний эл-т О(1)
    dq.pop_back(); show(dq); // удаление последнего эл-та O(1)
    dq.pop_front(); show(dq);

    dq.clear(); dq = {3, 1, 7, 2, 8, -1, 11, 0};
    dq.insert(dq.begin() + 3, 100); show(dq); // параметры: итератор и значение, О(n)
    dq.erase(dq.begin() + 2); show(dq); // удаление конкретного эл-та О(n), вернет итератор на след. элем
    dq.erase(dq.begin() + 3, dq.end() - 2); show(dq); // удаление диапазона О(n)
    int s = dq.size(); bool found = dq.empty(); // O(1)

    // --------------------------- stack ------------------------
    cout << "----------------------- stack: ------------------------" << endl;
    stack<int> st; // по умолчанию stack строится поверх deque, LIFO

    st.push(5); st.push(1); st.push(7); // push — добавление на вершину: O(1)

    // size, empty — O(1)
    cout << "st.size(): " << st.size() << endl;
    cout << "st.empty(): " << bool(st.empty()) << endl;

    // top — доступ к вершине БЕЗ удаления: O(1)
    cout << "st.top(): " << st.top() << endl;

    // pop — удаление вершины (значение НЕ возвращает): O(1)
    st.pop(); cout << "после pop, st.top(): " << st.top() << endl;

    cout << "stack: ";
    while (!st.empty()) { 
        cout << st.top() << " "; st.pop(); 
    }
    cout << endl;


    // --------------------------- queue ------------------------
    cout << "----------------------- queue: ------------------------" << endl;
    queue<int> q;                   // по умолчанию queue строится поверх deque, FIFO

    // push — добавление в конец очереди: O(1)
    q.push(5);
    q.push(1);
    q.push(7);

    cout << "q.size(): " << q.size() << endl;
    cout << "q.empty(): " << bool(q.empty()) << endl;

    cout << "q.front(): " << q.front() << endl;   // front — доступ к голове (первый пришедший): O(1)

    cout << "q.back(): " << q.back() << endl;     // back — доступ к хвосту (последний пришедший): O(1)

    q.pop(); // удаление головы 
    cout << "после pop, front: " << q.front() << endl; 

    cout << "queue: "; // вывод всей очереди без удаления
    queue<int> tmp = q;
    while (!tmp.empty()) {
        cout << tmp.front() << " ";
        tmp.pop();
    }
    cout << endl;


    return 0;
}