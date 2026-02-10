#include <iostream>
#include <string>
#include "LinkedList.hpp"
using namespace std;

template <typename T>
void expectThrow_GetElement(LinkedList<T>& list, int pos) {
    try {
        cout << "Attempting getElement(" << pos << ")...\n";
        (void)list.getElement(pos);
        cout << "ERROR: expected exception, but none was thrown.\n";
    } catch (const string& e) {
        cout << "Caught exception: " << e << "\n";
    }
}

template <typename T>
void expectThrow_Replace(LinkedList<T>& list, int pos, const T& val) {
    try {
        cout << "Attempting replace(" << pos << ", <value>)...\n";
        list.replace(pos, val);
        cout << "ERROR: expected exception, but none was thrown.\n";
    } catch (const string& e) {
        cout << "Caught exception: " << e << "\n";
    }
}

int main() {
    cout << "===== LinkedList<int> tests =====\n";
    LinkedList<int> li;

    cout << "Initial list: " << li;
    cout << "isEmpty(): " << boolalpha << li.isEmpty() << "\n";
    cout << "getLength(): " << li.getLength() << "\n\n";

    // Exception tests on empty list
    expectThrow_GetElement(li, 0);
    expectThrow_GetElement(li, -1);
    expectThrow_Replace(li, 0, 999);

    cout << "\nAppending values 10, 20, 30...\n";
    li.append(10);
    li.append(20);
    li.append(30);

    cout << "List now: " << li;
    cout << "isEmpty(): " << li.isEmpty() << "\n";
    cout << "getLength(): " << li.getLength() << "\n";

    cout << "Elements by index:\n";
    for (int i = 0; i < li.getLength(); i++) {
        cout << "  li[" << i << "] = " << li.getElement(i) << "\n";
    }

    cout << "\nReplace index 1 with 777...\n";
    li.replace(1, 777);
    cout << "List now: " << li;
    cout << "Check li[1]: " << li.getElement(1) << "\n";

    // Out-of-bounds replace/getElement
    cout << "\nOut-of-bounds tests:\n";
    expectThrow_GetElement(li, 3);
    expectThrow_GetElement(li, 100);
    expectThrow_Replace(li, -5, 1);
    expectThrow_Replace(li, 3, 1);

    cout << "\nClearing list...\n";
    li.clear();
    cout << "List now: " << li;
    cout << "isEmpty(): " << li.isEmpty() << "\n";
    cout << "getLength(): " << li.getLength() << "\n\n";

    cout << "===== LinkedList<string> tests =====\n";
    LinkedList<string> ls;

    cout << "Initial list: " << ls;
    cout << "Appending \"apple\", \"banana\", \"cherry\"...\n";
    ls.append("apple");
    ls.append("banana");
    ls.append("cherry");
    cout << "List now: " << ls;

    cout << "Replace index 2 with \"dragonfruit\"...\n";
    ls.replace(2, "dragonfruit");
    cout << "List now: " << ls;

    cout << "Get each element:\n";
    for (int i = 0; i < ls.getLength(); i++) {
        cout << "  ls[" << i << "] = " << ls.getElement(i) << "\n";
    }

    cout << "\nException tests (string list):\n";
    expectThrow_GetElement(ls, -1);
    expectThrow_GetElement(ls, ls.getLength()); // exactly out of range
    expectThrow_Replace(ls, 999, string("x"));

    cout << "\nClear string list...\n";
    ls.clear();
    cout << "List now: " << ls;
    cout << "getLength(): " << ls.getLength() << "\n";

    cout << "\n===== Done =====\n";
    return 0;
}
