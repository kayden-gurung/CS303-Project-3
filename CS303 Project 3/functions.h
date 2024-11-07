#pragma once
#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <vector>
#include <iostream>
#include <stdexcept>

template <typename T>
class Queue {
public:
    Queue();
    ~Queue();

    void push(const T& value);
    void pop();
    T front() const;
    int size() const;
    bool empty() const;
    void move_to_rear();
    void insertion_sort(); 

private:
    struct Node {
        T data;
        Node* next;
        Node(const T& value) : data(value), next(nullptr) {}
    };

    Node* head;
    Node* tail;
    int num_items;
};

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
template <typename T>
void Queue<T>::insertion_sort() {
    if (num_items <= 1) return;

    Queue<T> sortedQueue;

    while (!empty()) {
        T current = front(); 
        pop(); 

        int sortedSize = sortedQueue.size();
        bool inserted = false;

        for (int i = 0; i < sortedSize; ++i) {
            T sortedFront = sortedQueue.front();
            sortedQueue.pop();

            if (!inserted && current < sortedFront) {
                sortedQueue.push(current); 
                inserted = true;
            }

            sortedQueue.push(sortedFront);
        } if (!inserted) {
            sortedQueue.push(current);
        }
    } while (!sortedQueue.empty()) {
        push(sortedQueue.front());
        sortedQueue.pop();
    }
}
template <typename Item_Type>
int linear_search_last(const std::vector<Item_Type>& items, const Item_Type& target, int pos_last) {
    if (pos_last < 0)
        return -1;

    if (items[pos_last] == target)
        return pos_last;

    return linear_search_last(items, target, pos_last - 1);
}
#endif