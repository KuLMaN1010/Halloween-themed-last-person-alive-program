#pragma once
#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
using namespace std;

template <typename T>
class Queue {
protected:
    struct Node {
        T data;
        Node* next;
    };
    Node* front;
    Node* rear;
    int count;

public:
    Queue() : front(nullptr), rear(nullptr), count(0) {}

    void Enqueue(T data) {
        Node* newNode = new Node{ data, nullptr };
        if (rear != nullptr) {
            rear->next = newNode;
        }
        rear = newNode;
        if (front == nullptr) {
            front = rear;
        }
        count++;
    }

    bool Dequeue(T& data) {
        if (front == nullptr) return false;
        Node* temp = front;
        data = front->data;
        front = front->next;
        if (front == nullptr) {
            rear = nullptr;
        }
        delete temp;
        count--;
        return true;
    }

    int GetCount() const {
        return count;
    }

    void Clear() {
        while (front != nullptr) {
            Node* temp = front;
            front = front->next;
            delete temp;
        }
        rear = nullptr;
        count = 0;
    }
};

#endif // QUEUE_H

