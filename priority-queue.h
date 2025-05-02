#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H

#include <vector>
#include <stdexcept>
#include <algorithm>
#include <windows.h>


template <typename T, typename Container = std::vector<T>>
class priority_queue {
private:
    Container c; 
    void sift_up(size_t idx) {
        while (idx > 0) {
            size_t parent = (idx - 1) / 2;
            if (c[parent] < c[idx]) {
                std::swap(c[parent], c[idx]);
                idx = parent;
            }
            else {
                break;
            }
        }
    }

    void sift_down(size_t idx) {
        size_t n = c.size();
        while (2 * idx + 1 < n) {
            size_t left = 2 * idx + 1;
            size_t right = 2 * idx + 2;
            size_t largest = idx;
            if (left < n && c[largest] < c[left]) largest = left;
            if (right < n && c[largest] < c[right]) largest = right;
            if (largest != idx) {
                std::swap(c[idx], c[largest]);
                idx = largest;
            }
            else {
                break;
            }
        }
    }

public:
    priority_queue() = default;
    explicit priority_queue(const Container& cont) : c(cont) {
        for (int i = (int)c.size() / 2 - 1; i >= 0; --i) {
            sift_down(i);
        }
    }

    bool empty() const { return c.empty(); }
    size_t size() const { return c.size(); }

       void push(const T& value) {
        c.push_back(value);
        sift_up(c.size() - 1);
    }
    void pop() {
        if (c.empty()) throw std::out_of_range("Очередь пуста");
        std::swap(c.front(), c.back());
        c.pop_back();
        if (!c.empty()) sift_down(0);
    }
    const T& top() const {
        if (c.empty()) throw std::out_of_range("Очередь пуста");
        return c.front();
    }
};

#endif // PRIORITY_QUEUE_H 