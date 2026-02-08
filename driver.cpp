#include <iostream>
#include <string>
#include "LinkedList.hpp"
using namespace std;

template <typename T>
void printBasicInfo(const string& label, const LinkedList<T>& list) {
    cout << "---- " << label << " ----\n";
    cout << "Length: " << list.getLength() << "\n";
    cout << "Empty?  " << (list.isEmpty() ? "true" : "false") << "\n";
    cout << "List:   " << list;
    cout << endl;
}

template <typename T>
void expectThrowsGet(const LinkedList<T>& list, int pos) {
    try {
        cout << "Attempt getElement(" << pos << "): ";
        cout << list.getElement(pos) << "\n";
        cout << "ERROR: expected exception but none thrown.\n";
    } catch (const string& e) {
        cout << "Caught exception: " << e << "\n";
    }
}

template <typename T>
void expectThrowsReplace(LinkedList<T>& list, int pos, const T& value) {
    try {
        cout << "Attempt replace(" << pos << ", value): ";
        list.replace(pos, value);
        cout << "ERROR: expected exception but none thrown.\n";
    } catch (const string& e) {
        cout << "Caught exception: " << e << "\n";
    }
}

int main() {
    cout << "===== LinkedList Lab Driver =====\n\n";

    // -----------------------------
    // Test with int
    // -----------------------------
    LinkedList<int> ints;
    printBasicInfo("INTS initial", ints);

    // invalid operations on empty list
    expectThrowsGet(ints, 0);
    expectThrowsGet(ints, -1);
    expectThrowsReplace(ints, 0, 999);

    // append
    cout << "Appending: 10, 20, 30\n";
    ints.append(10);
    ints.append(20);
    ints.append(30);
    printBasicInfo("INTS after append", ints);

    // getElement valid
    cout << "getElement(0) = " << ints.getElement(0) << "\n";
    cout << "getElement(1) = " << ints.getElement(1) << "\n";
    cout << "getElement(2) = " << ints.getElement(2) << "\n\n";

    // getElement invalid
    expectThrowsGet(ints, 3);
    expectThrowsGet(ints, 999);

    // replace valid
    cout << "\nReplacing position 1 with 777\n";
    ints.replace(1, 777);
    printBasicInfo("INTS after replace", ints);

    // replace invalid
    expectThrowsReplace(ints, -1, 5);
    expectThrowsReplace(ints, 3, 5);

    // clear
    cout << "\nClearing ints list\n";
    ints.clear();
    printBasicInfo("INTS after clear", ints);

    // clear again (should still be safe)
    cout << "Clearing ints list again\n";
    ints.clear();
    printBasicInfo("INTS after clear again", ints);

    // -----------------------------
    // Test with string
    // -----------------------------
    LinkedList<string> words;
    printBasicInfo("STRINGS initial", words);

    cout << "Appending: \"alpha\", \"beta\", \"gamma\"\n";
    words.append("alpha");
    words.append("beta");
    words.append("gamma");
    printBasicInfo("STRINGS after append", words);

    cout << "Replacing position 2 with \"DELTA\"\n";
    words.replace(2, "DELTA");
    printBasicInfo("STRINGS after replace", words);

    // bounds tests
    expectThrowsGet(words, -1);
    expectThrowsGet(words, 3);
    expectThrowsReplace(words, 3, string("oops"));

    cout << "\nClearing words list\n";
    words.clear();
    printBasicInfo("STRINGS after clear", words);

    // -----------------------------
    // Test with double
    // -----------------------------
    LinkedList<double> doubles;
    cout << "Appending doubles: 1.5, 2.25, 3.75, -4.0\n";
    doubles.append(1.5);
    doubles.append(2.25);
    doubles.append(3.75);
    doubles.append(-4.0);
    printBasicInfo("DOUBLES after append", doubles);

    cout << "Replacing position 0 with 99.99\n";
    doubles.replace(0, 99.99);
    printBasicInfo("DOUBLES after replace", doubles);

    cout << "Access all doubles:\n";
    for (int i = 0; i < doubles.getLength(); i++) {
        cout << "  [" << i << "] = " << doubles.getElement(i) << "\n";
    }
    cout << endl;

    // -----------------------------
    // Stress-ish test: many appends
    // -----------------------------
    LinkedList<int> many;
    for (int i = 0; i < 20; i++) {
        many.append(i * 10);
    }
    printBasicInfo("MANY (20 appends)", many);

    cout << "Replacing some positions in MANY\n";
    many.replace(0, 1111);
    many.replace(19, 9999);
    many.replace(10, 5555);
    printBasicInfo("MANY after replaces", many);

    cout << "Verifying edge elements:\n";
    cout << "  first = " << many.getElement(0) << "\n";
    cout << "  middle(10) = " << many.getElement(10) << "\n";
    cout << "  last = " << many.getElement(many.getLength() - 1) << "\n\n";

    cout << "Clearing MANY\n";
    many.clear();
    printBasicInfo("MANY after clear", many);

    cout << "===== End Driver =====\n";
    return 0;
}
