#ifndef SHARED_PTR_H
#define SHARED_PTR_H

#include <iostream>

namespace skt {

template <typename T>
class shared_ptr 
{
public:
    shared_ptr() = delete;
    
    shared_ptr(T data) : m_ptr{new T(data)}, m_count{new int(0)} {};

    shared_ptr(const shared_ptr& other) : m_ptr{other.m_ptr}, m_count{other.m_count} {
        if (m_count) {
            ++(*m_count);
        }
    }

    shared_ptr(shared_ptr&& other) : m_ptr{other.m_ptr}, m_count{other.m_count} {
        other.m_count = nullptr;
        other.m_ptr = nullptr;
    }

    ~shared_ptr() {
        std::cout << "\ncount: " << *m_count << "\n";
        if (*m_count == 0) {
            std::cout << "\n\nptr_deleted\n\n";
            delete m_ptr;
            delete m_count;
            m_ptr = nullptr;
            m_count = nullptr;
        }
        else {
            --(*m_count);
        }
    }

    void show() {
        std::cout << "address: " << m_ptr << " = " << *m_ptr << "   count: " << *m_count << "\n";
    }
    
private:
    T* m_ptr;
    int* m_count;
};

} // skt

#endif // SHARED_PTR_H