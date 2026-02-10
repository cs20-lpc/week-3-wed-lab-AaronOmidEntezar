#include <iostream>
#include <string>
#include "LinkedList.hpp"
using namespace std;

template <typename T>
void testListBasics(const string& label) {
    cout << "=============================\n";
    cout << "Testing: " << label << "\n";
    cout << "=============================\n";

    LinkedList<T> lst;

    // initial state
    cout << "Initial isEmpty(): " << boolalpha << lst.isEmpty() << "\n";
    cout << "Initial length: " << lst.getLength() << "\n";
    cout << "Print empty list:\n" << lst << "\n";

    // test invalid getElement
    try {
        cout << "Attempt getElement(0) on empty...\n";
        cout << lst.getElement(0) << "\n";
    } catch (const string& e) {
        cout << "Caught exception: " << e << "\n";
    }

    // test invalid replace
    try {
        cout << "Attempt replace(0) on empty...\n";
        lst.replace(0, T());
    } catch (const string& e) {
        cout << "Caught exception: " << e << "\n";
    }

    cout << "\n";
}

int main() {
    // ----- INT TESTS -----
    {
        cout << "===== INT LIST TEST =====\n";
        LinkedList<int> a;

        cout << "Empty? " << boolalpha << a.isEmpty() << ", length=" << a.getLength() << "\n";
        cout << a << "\n";

        cout << "Appending 10, 20, 30...\n";
        a.append(10);
        a.append(20);
        a.append(30);

        cout << "Empty? " << a.isEmpty() << ", length=" << a.getLength() << "\n";
        cout << "List: " << a;

        cout << "getElement(0)=" << a.getElement(0) << "\n";
        cout << "getElement(1)=" << a.getElement(1) << "\n";
        cout << "getElement(2)=" << a.getElement(2) << "\n";

        cout << "Replacing position 1 with 999...\n";
        a.replace(1, 999);
        cout << "List: " << a;

        // invalid indices
        try {
            cout << "Trying getElement(-1)...\n";
            cout << a.getElement(-1) << "\n";
        } catch (const string& e) {
            cout << "Caught exception: " << e << "\n";
        }

        try {
            cout << "Trying getElement(length)...\n";
            cout << a.getElement(a.getLength()) << "\n";
        } catch (const string& e) {
            cout << "Caught exception: " << e << "\n";
        }

        try {
            cout << "Trying replace(999)...\n";
            a.replace(999, 5);
        } catch (const string& e) {
            cout << "Caught exception: " << e << "\n";
        }

        cout << "Clearing...\n";
        a.clear();
        cout << "Empty? " << a.isEmpty() << ", length=" << a.getLength() << "\n";
        cout << a << "\n";
    }

    cout << "\n";

    // ----- STRING TESTS -----
    {
        cout << "===== STRING LIST TEST =====\n";
        LinkedList<string> s;
        s.append("apple");
        s.append("banana");
        s.append("cherry");

        cout << "List: " << s;
        cout << "Length: " << s.getLength() << "\n";
        cout << "getElement(2)=" << s.getElement(2) << "\n";

        cout << "Replacing position 0 with \"avocado\"...\n";
        s.replace(0, "avocado");
        cout << "List: " << s;

        cout << "Clearing...\n";
        s.clear();
        cout << "List after clear:\n" << s << "\n";
    }

    cout << "\n";

    // ----- DOUBLE TESTS -----
    {
        cout << "===== DOUBLE LIST TEST =====\n";
        LinkedList<double> d;
        d.append(3.14);
        d.append(2.71);
        d.append(1.41);

        cout << "List: " << d;
        cout << "Replacing position 2 with 0.57721...\n";
        d.replace(2, 0.57721);
        cout << "List: " << d;
    }

    cout << "\n";

    // quick generic “empty behavior” tests
    testListBasics<int>("Empty behaviors (int)");
    testListBasics<string>("Empty behaviors (string)");

    return 0;
}
