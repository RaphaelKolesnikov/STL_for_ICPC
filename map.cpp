#include <iostream>
#include <map>

using namespace std;

void show(map<int, string> const &mp) {
    cout << "key, value:" << endl;
    for (auto it = mp.begin(); it != mp.end(); ++it) {
        cout << it->first << ", " << it->second;
        cout << endl;
    }
}

void show_from_back(map<int, string> const &mp) { // обход по убыванию
    for (auto it = mp.rbegin(); it != mp.rend(); ++it)
        cout << it->first << " " << it->second << endl;
}

int main() {
    map<int, string> mp;

    mp[1] = "telephone"; // создание элемента оператором [], вставка элемента = "...",  O(log n)
    cout << mp[1] << endl;

    mp[1] = "iphone";
    cout << mp[1] << endl; // перезаписывать элемент тоже можно так

    mp.insert({2, "notebook"}); // можно вставить и так O(log n), вернет пару итератор/bool
    cout << mp[2] << endl;

    mp.insert({2, "notebook1"}); // не вставит элемент если ключ из пары уже существует
    cout << mp[2] << endl;

    mp.emplace(2, "notebook1"); // мeнее затратно по памяти чем insert, перезаписать так же не получится O(log n)
    cout << mp[2] << endl;

    mp.erase(2);  // вернет кол-во элементов, удаление по ключу за O(log n)
    // возможно удалять и по итератору О(1) амортизированно, стандарт гарантирует O(log n)
    show(mp);

    // cout << mp.at(2); // бросит out_of_range, если нет — безопасно для чтения
    mp.find(1);   //вернет итератор — лучший вариант для проверки O(log n)

    // все что идет ниже - аналогично set, потому что и set и map это красно-черные деревья, просто тут пары ключ-значение
    int key = 2;
    mp.count(key);                 // 0 или 1, O(log n)
    mp.find(key); // возвращает итератор к элементу с ключом или итератор на конец, если такого ключа нет. O(log n)

    mp.lower_bound(key);           // итератор, первый с ключом >= key O(log n)
    mp.upper_bound(key);           // итератор, первый с ключом >  key O(log n)
    mp.equal_range(key);           // пара {lower, upper} — для map это {it, next(it)} O(log n)

    mp.begin();                    // минимальный ключ O(1)
    mp.rbegin();                   // максимальный ключ (*mp.rbegin()) O(1)

    map<int, string, greater<int>> mp1; // по убыванию

    return 0;
}