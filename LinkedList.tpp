template <typename T>
void LinkedList<T>::append(const T& elem) {
    Node* newNode = new Node(elem, nullptr);

    if (head == nullptr) {
        head = newNode;
    } else {
        Node* curr = head;
        while (curr->next != nullptr) {
            curr = curr->next;
        }
        curr->next = newNode;
    }

    this->length++;
}

template <typename T>
void LinkedList<T>::clear() {
    // TODO
}

template <typename T>
T LinkedList<T>::getElement(int position) const {
    // TODO
}

template <typename T>
int LinkedList<T>::getLength() const {
    return this->length;
}

template <typename T>
bool LinkedList<T>::isEmpty() const {
    return this->length == 0;
}

template <typename T>
void LinkedList<T>::replace(int position, const T& elem) {
    // TODO
}

template <typename T>
ostream& operator<<(ostream& outStream, const LinkedList<T>& myObj) {
    if (myObj.isEmpty()) {
        outStream << "List is empty, no elements to display.\n";
    }

    Node* curr = head;
    for (int i = 0; i < position; i++) {
        curr = curr->next;
    }
    curr->value = elem;
}
