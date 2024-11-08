#pragma once
#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <vector>
#include <iostream>
#include <stdexcept>

// create queue class to store items
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
    struct Node { // make node to hold data and pointer to next node
        T data; 
        Node* next; 
        Node(const T& value) : data(value), next(nullptr) {} // make node with item, point to nothing
    };
    Node* head; // point to first item in queue
    Node* tail;
    int num_items;
};
// make empty queue, set head and tail to nothing, num_items to 0
template <typename T>
Queue<T>::Queue() : head(nullptr), tail(nullptr), num_items(0) {}
// free all nodes in queue when done
template <typename T>
Queue<T>::~Queue() {
    while (!empty()) { // keep removing items until empty
        pop();
    }
}
// add item to end of queue
template <typename T>
void Queue<T>::push(const T& value) {
    Node* newNode = new Node(value); // make new node with item
    if (empty()) { // if queue empty, new node is both head and tail
        head = tail = newNode;
    }
    else { // link new node to end and update tail
        tail->next = newNode;
        tail = newNode;
    }
    num_items++;
}
// remove item from front of queue
template <typename T>
void Queue<T>::pop() {
    if (!empty()) { // 
        Node* temp = head; 
        head = head->next; 
        delete temp;
        num_items--;
        if (head == nullptr) { // if queue empty after pop, tail is also null
            tail = nullptr;
        }
    }
}
// get item at front of queue
template <typename T>
T Queue<T>::front() const {
    if (!empty()) { // if queue not empty
        return head->data; 
    }
    throw std::runtime_error("Queue is empty"); // if empty, throw error
}
// get number of items in queue
template <typename T>
int Queue<T>::size() const {
    return num_items;
}
// check if queue empty
template <typename T>
bool Queue<T>::empty() const {
    return num_items == 0;
}
// move item at front to end of queue
template <typename T>
void Queue<T>::move_to_rear() {
    if (num_items > 1) { 
        T frontValue = front();
        pop(); 
        push(frontValue);
    }
}
// sort items in queue using insertion sort
template <typename T>
void Queue<T>::insertion_sort() {
    if (num_items <= 1) return; 

    Queue<T> sortedQueue; // make temporary queue to hold sorted items

    while (!empty()) {
        T current = front(); 
        pop();

        int sortedSize = sortedQueue.size(); 
        bool inserted = false; 

        for (int i = 0; i < sortedSize; ++i) { 
            T sortedFront = sortedQueue.front(); 
            sortedQueue.pop(); 

            if (!inserted && current < sortedFront) { // if current is smaller, insert here
                sortedQueue.push(current); 
                inserted = true; // mark as inserted
            }

            sortedQueue.push(sortedFront); 
        } if (!inserted) { // if current is largest, put at end
            sortedQueue.push(current);
        }
    } while (!sortedQueue.empty()) { // transfer sorted items back to original queue
        push(sortedQueue.front());
        sortedQueue.pop();
    }
}
// search for last occurrence of target in vector, use recursion
template <typename Item_Type>
int linear_search_last(const std::vector<Item_Type>& items, const Item_Type& target, int pos_last) {
    if (pos_last < 0) 
        return -1;

    if (items[pos_last] == target) // if item at pos_last matches target
        return pos_last; // return position

    return linear_search_last(items, target, pos_last - 1); // keep searching backward
}
#endif