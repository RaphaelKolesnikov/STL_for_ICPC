#include <iostream>
#include <set>

using namespace std;

void show(set<int> const &s) {
    cout << "show set: ";
    for (auto it = s.begin(); it != s.end(); ++it) cout << *it << " ";
    cout << endl;
}

int main() {

    set<int> s1, s2;

    auto i1 = s1.insert(1); // вставить, O(log n). Возвращает pair<iterator,bool>
    cout << "iterator values: " << *i1.first << " " << i1.second << endl; 

    s2.emplace(1); // то же, но конструирует на месте (чуть быстрее, O(log n))
    s2.emplace(7); s2.emplace(3);
    s2.emplace(11); s2.emplace(5);


    for (int i = 0; i < 10; i++) s1.insert(i * 2);

    cout << "s1 & s2: " << endl;
    show(s1); show(s2);

    cout << "after erase: " << endl;
    s2.erase(5); show(s2); // удаление по значению, O(log n)
    cout << "s2.erase(6) : " << s2.erase(6) << endl; // никакой ошибки, никакого исключения 0 (не было)

    auto it = s1.begin(); it++;
    s1.erase(it); // удаление по итератору тоже поддерживается, O(1) амортизированно
    show(s1);

    s1.clear();            // очистить всё, O(n)
    cout << "s1.empty(): " <<  s1.empty() << endl; // проверка на пустоту О(1)
    cout << "s1.size(): " << s1.size() << endl; // размер О(1)

    s1 = s2; show(s1);
    cout << "s2.count(3): " << s2.count(3) << endl; // поиск элемента, О(log n)

    it = s1.find(3); // итератор или s.end(), O(log n)
    cout << "s1.find(3): " << *it;   


    cout << endl << "lower/upper bounds" << endl;
    it = s1.lower_bound(7);     // первый элемент >= x
    cout << *it << ", ";
    it = s1.upper_bound(7);     // первый элемент > x
    cout << *it << endl;
    // оба O(log n), возвращают итератор или end()

    cout << *s1.begin() << ", ";  // минимальный элемент, O(1)
    cout << *s1.rbegin() << endl; // максимальный элемент, O(1)
    // обусловлено тем, что в set предусмотрены указатели на миним. и макс. элементы в структуре


    // Нельзя просто написать *it = 1, можно сделать только так:
    s1.erase(s1.find(1));
    s1.insert(2);

    set<int, greater<int>> desc;          // сделать по убыванию
    set<pair<int,int>> sp;                // сортировка по first, затем second

    // ----------------- multiset ----------------

    multiset<int> ms = {1, 3, 3, 3, 5};
    ms.erase(ms.find(3)); // правильное удаление, через итератор

    auto mit = ms.find(3);
    if (mit != ms.end()) ms.erase(mit);   // правильно удалять именно так, с проверкой, иначе может вылезти ошибка

    mit = ms.insert(3); // в отличие от set вернет итератор, не пару

    for (auto mit = ms.begin(); mit != ms.end(); ) {
        if (*mit < 0) mit = ms.erase(mit); // правильно удаление в цикле! erase указывает уже на следующий итератор
        else ++mit;
    }

    // Все, больше глобальных отличий нет, в multiset несколько одинаковых элементов могут быть

    return 0;
}
