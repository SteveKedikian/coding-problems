#ifndef UNIQUE_PTR_H
#define UNIQUE_PTR_H

#include <iostream>

namespace skt {

template <typename T>
class unique_ptr 
{
public:
    unique_ptr() = delete;

    unique_ptr(const unique_ptr&) = delete;

    unique_ptr(T data) : m_ptr{new T(data)} {};

    unique_ptr(unique_ptr&& other) : m_ptr{other.m_ptr} { other.m_ptr = nullptr;}

    ~unique_ptr() {
        if (m_ptr) {
            delete m_ptr;
            m_ptr = nullptr;
        }
    }

    T& operator*() {
        return *m_ptr;
    }

    T* operator->() {
        return m_ptr;
    }

private:
    T* m_ptr;
};

} // skt

#endif // UNIQUE_PTR_H