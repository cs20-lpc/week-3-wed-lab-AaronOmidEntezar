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
    Node* curr = head;
    while (curr != nullptr) {
        Node* toDelete = curr;
        curr = curr->next;
        delete toDelete;
    }

    head = nullptr;
    this->length = 0;
}

template <typename T>
T LinkedList<T>::getElement(int position) const {
    if (position < 0 || position >= this->length) {
        throw string("getElement error: position out of range");
    }

    Node* curr = head;
    for (int i = 0; i < position; i++) {
        curr = curr->next;
    }

    return curr->value;
}

template <typename T>
void LinkedList<T>::replace(int position, const T& elem) {
    if (position < 0 || position >= this->length) {
        throw string("replace error: position out of range");
    }

    Node* curr = head;
    for (int i = 0; i < position; i++) {
        curr = curr->next;
    }

    curr->value = elem;
}
