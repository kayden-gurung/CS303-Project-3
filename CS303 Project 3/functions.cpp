#include "functions.h"
#include <iostream>

template <typename T>
Queue<T>::Queue() : head(nullptr), tail(nullptr), num_items(0) {}

template <typename T>
Queue<T>::~Queue() {
    while (!empty()) {
        pop();
    }
}

template <typename T>
void Queue<T>::push(const T& value) {
    Node* newNode = new Node(value);
    if (empty()) {
        head = tail = newNode;
    }
    else {
        tail->next = newNode;
        tail = newNode;
    }
    num_items++;
}

template <typename T>
void Queue<T>::pop() {
    if (!empty()) {
        Node* temp = head;
        head = head->next;
        delete temp;
        num_items--;
        if (head == nullptr) {
            tail = nullptr;
        }
    }
}

template <typename T>
T Queue<T>::front() const {
    if (!empty()) {
        return head->data;
    }
    throw std::runtime_error("Queue is empty");
}

template <typename T>
int Queue<T>::size() const {
    return num_items;
}

template <typename T>
bool Queue<T>::empty() const {
    return num_items == 0;
}

template <typename T>
void Queue<T>::move_to_rear() {
    if (num_items > 1) {
        T frontValue = front();
        pop();
        push(frontValue);
    }
}