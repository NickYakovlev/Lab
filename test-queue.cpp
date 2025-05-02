#include <windows.h>
#include "priority-queue.h"
#include <iostream>
#include <string>
#include <locale>

int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    std::locale::global(std::locale(""));
    std::wcout.imbue(std::locale());
    std::cout << "Тестирование priority_queue<int>...\n";
    priority_queue<int> pq;
    pq.push(5);
    pq.push(1);
    pq.push(10);
    pq.push(3);
    std::cout << "Максимум: " << pq.top() << "\n";
    pq.pop();
    std::cout << "Максимум после удаления: " << pq.top() << "\n";
    std::cout << "Размер очереди: " << pq.size() << "\n";
    std::cout << "Все элементы по убыванию: ";
    while (!pq.empty()) {
        std::cout << pq.top() << ' ';
        pq.pop();
    }
    std::cout << "\n";

    std::cout << "\"Тестирование priority_queue<std::string>...\n";
    priority_queue<std::string> pq_str;
    pq_str.push("яблоко");
    pq_str.push("банан");
    pq_str.push("груша");
    pq_str.push("апельсин");
    std::cout << "Максимум: " << pq_str.top() << "\n";
    pq_str.pop();
    std::cout << "Максимум после удаления: " << pq_str.top() << "\n";
    std::cout << "Размер очереди: " << pq_str.size() << "\n";
    std::cout << "Все элементы по убыванию: ";
    while (!pq_str.empty()) {
        std::cout << pq_str.top() << ' ';
        pq_str.pop();
    }
    std::cout << "\n";

    return 0;
}
