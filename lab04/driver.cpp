#include <iostream>
#include <string>
#include <cassert>
#include "LinkedList.hpp"

using namespace std;

// A simple custom type to prove templates work beyond primitives
struct Person {
    string name;
    int age;

    Person(string n = "", int a = 0) : name(n), age(a) { }
};

ostream& operator<<(ostream& os, const Person& p) {
    os << "{name: " << p.name << ", age: " << p.age << "}";
    return os;
}

template <typename T>
void expectThrowGetElement(const LinkedList<T>& list, int pos) {
    try {
        (void)list.getElement(pos);
        cout << "ERROR: expected getElement(" << pos << ") to throw, but it did not.\n";
        assert(false);
    } catch (const string& msg) {
        cout << "Caught expected exception: " << msg << "\n";
    }
}

template <typename T>
void expectThrowReplace(LinkedList<T>& list, int pos, const T& value) {
    try {
        list.replace(pos, value);
        cout << "ERROR: expected replace(" << pos << ", ...) to throw, but it did not.\n";
        assert(false);
    } catch (const string& msg) {
        cout << "Caught expected exception: " << msg << "\n";
    }
}

void testIntList() {
    cout << "\n===== TEST: LinkedList<int> =====\n";
    LinkedList<int> a;

    // initial state
    assert(a.isEmpty());
    assert(a.getLength() == 0);
    cout << a; // should print "empty" message

    // invalid operations on empty
    expectThrowGetElement(a, 0);
    expectThrowGetElement(a, -1);
    expectThrowReplace(a, 0, 999);

    // append
    a.append(10);
    a.append(20);
    a.append(30);

    assert(!a.isEmpty());
    assert(a.getLength() == 3);
    cout << "After appends: " << a;

    // getElement
    assert(a.getElement(0) == 10);
    assert(a.getElement(1) == 20);
    assert(a.getElement(2) == 30);

    // out-of-range getElement
    expectThrowGetElement(a, 3);
    expectThrowGetElement(a, 100);

    // replace middle, first, last
    a.replace(1, 200);
    assert(a.getElement(1) == 200);
    cout << "After replace index 1 -> 200: " << a;

    a.replace(0, 111);
    assert(a.getElement(0) == 111);

    a.replace(2, 333);
    assert(a.getElement(2) == 333);
    cout << "After replacing first and last: " << a;

    // out-of-range replace
    expectThrowReplace(a, -1, 5);
    expectThrowReplace(a, 3, 5);

    // clear
    a.clear();
    assert(a.isEmpty());
    assert(a.getLength() == 0);
    cout << "After clear(): " << a;
}

void testStringList() {
    cout << "\n===== TEST: LinkedList<string> =====\n";
    LinkedList<string> s;

    s.append("Bean Burrito");
    s.append("Spicy Pho");
    s.append("Orange chicken with white rice");
    cout << "After appends: " << s;

    assert(s.getLength() == 3);
    assert(s.getElement(0) == "Bean Burrito");
    assert(s.getElement(2) == "Orange chicken with white rice");

    s.replace(1, "Ramen");
    assert(s.getElement(1) == "Ramen");
    cout << "After replace: " << s;

    s.clear();
    assert(s.isEmpty());
    cout << "After clear(): " << s;
}

void testDoubleList() {
    cout << "\n===== TEST: LinkedList<double> =====\n";
    LinkedList<double> d;

    d.append(3.14);
    d.append(2.718);
    d.append(1.414);
    cout << "After appends: " << d;

    assert(d.getLength() == 3);
    assert(d.getElement(0) == 3.14);
    assert(d.getElement(1) == 2.718);
    assert(d.getElement(2) == 1.414);

    d.replace(2, 9.99);
    assert(d.getElement(2) == 9.99);
    cout << "After replace: " << d;
}

void testCustomTypeList() {
    cout << "\n===== TEST: LinkedList<Person> =====\n";
    LinkedList<Person> people;

    people.append(Person("Ava", 19));
    people.append(Person("Noah", 22));
    people.append(Person("Mia", 21));
    cout << "After appends: " << people;

    assert(people.getLength() == 3);
    assert(people.getElement(0).name == "Ava");
    assert(people.getElement(1).age == 22);

    people.replace(1, Person("Noah", 23));
    assert(people.getElement(1).age == 23);
    cout << "After replace: " << people;

    // exceptions
    expectThrowGetElement(people, 3);
    expectThrowReplace(people, -5, Person("X", 0));
}

void testDestructorViaScope() {
    cout << "\n===== TEST: Destructor (scope exit) =====\n";
    {
        LinkedList<int> temp;
        for (int i = 0; i < 5; i++) temp.append(i * 10);
        cout << "Inside scope: " << temp;
        // leaving scope should call ~LinkedList() -> clear() without crashing/leaking
    }
    cout << "Exited scope (destructor ran).\n";
}

int main() {
    cout << "LinkedList Driver Tests\n";

    testIntList();
    testStringList();
    testDoubleList();
    testCustomTypeList();
    testDestructorViaScope();

    cout << "\nAll tests finished.\n";
    return 0;
}


// test change