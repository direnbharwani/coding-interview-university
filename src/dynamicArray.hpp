#include <exception>

#include "dynamicArray.h"

namespace CIU
{

template<typename T>
DynamicArray<T>::DynamicArray()
    : m_data(nullptr)
    , m_size(0)
    , m_capacity(0)
{
}

template<typename T>
DynamicArray<T>::DynamicArray(size_t capacity)
    : m_data(nullptr)
    , m_size(0)
    , m_capacity(0)
{
    // Round up to the nearest capacity that is a power of 2
    m_capacity = 1;
    while (m_capacity < capacity)
    {
        m_capacity <<= 1;
    }

    m_data = new T[m_capacity];
}

template<typename T>
DynamicArray<T>::DynamicArray(const DynamicArray<T>& other)
    : m_data(new T[other.m_capacity])
    , m_size(other.m_size)
    , m_capacity(other.m_capacity)
{
    for (size_t i = 0; i < m_size; ++i)
    {
        m_data[i] = other.m_data[i];
    }
}

template<typename T>
DynamicArray<T>::DynamicArray(DynamicArray<T>&& other)
    : m_data(other.m_data)
    , m_size(other.m_size)
    , m_capacity(other.m_capacity)
{
    other.m_data     = nullptr;
    other.m_size     = 0;
    other.m_capacity = 0;
}

template<typename T>
DynamicArray<T>::~DynamicArray()
{
    delete[] m_data;
}

template<typename T>
DynamicArray<T>& DynamicArray<T>::operator=(const DynamicArray<T>& other)
{
    if (this != &other)
    {
        delete[] m_data;
        m_data     = new T[other.m_capacity];
        m_size     = other.m_size;
        m_capacity = other.m_capacity;

        for (size_t i = 0; i < m_size; ++i)
        {
            m_data[i] = other.m_data[i];
        }
    }

    return *this;
}

template<typename T>
DynamicArray<T>& DynamicArray<T>::operator=(DynamicArray<T>&& other)
{
    if (this != &other)
    {
        delete[] m_data;
        m_data           = other.m_data;
        m_size           = other.m_size;
        m_capacity       = other.m_capacity;

        other.m_data     = nullptr;
        other.m_size     = 0;
        other.m_capacity = 0;
    }

    return *this;
}

template<typename T>
T& DynamicArray<T>::operator[](size_t index)
{
    if (index < 0 || index >= m_size)
    {
        throw std::out_of_range("Index out of range");
    }

    return m_data[index];
}

template<typename T>
const T& DynamicArray<T>::operator[](size_t index) const
{
    if (index < 0 || index >= m_size)
    {
        throw std::out_of_range("Index out of range");
    }

    return m_data[index];
}

template<typename T>
size_t DynamicArray<T>::size() const
{
    return m_size;
}

template<typename T>
size_t DynamicArray<T>::capacity() const
{
    return m_capacity;
}

template<typename T>
bool DynamicArray<T>::isEmpty() const
{
    return m_size == 0;
}

template<typename T>
void DynamicArray<T>::pushBack(const T& value)
{
    if (m_size == m_capacity)
    {
        resize();
    }

    m_data[m_size++] = value;
}

template<typename T>
T DynamicArray<T>::popBack()
{
    if (m_size == 0)
    {
        throw std::out_of_range("Array is empty");
    }

    return m_data[--m_size];
}

template<typename T>
void DynamicArray<T>::insert(size_t index, const T& value)
{
    if (index < 0 || index > m_size)
    {
        throw std::out_of_range("Index out of range");
    }

    if (m_size == m_capacity)
    {
        resize();
    }

    for (size_t i = m_size; i > index; --i)
    {
        m_data[i] = m_data[i - 1];
    }

    m_data[index] = value;
    ++m_size;
}

template<typename T>
void DynamicArray<T>::prepend(const T& value)
{
    insert(0, value);
}

template<typename T>
void DynamicArray<T>::deleteAt(size_t index)
{
    if (index < 0 || index >= m_size)
    {
        throw std::out_of_range("Index out of range");
    }

    for (size_t i = index; i < m_size - 1; ++i)
    {
        m_data[i] = m_data[i + 1];
    }

    --m_size;
}

template<typename T>
void DynamicArray<T>::remove(const T& value)
{
    for (size_t i = 0; i < m_size; ++i)
    {
        if (m_data[i] == value)
        {
            deleteAt(i);
        }
    }
}

template<typename T>
int DynamicArray<T>::find(const T& value)
{
    for (size_t i = 0; i < m_size; ++i)
    {
        if (m_data[i] == value)
        {
            return i;
        }
    }

    return -1;
}

template<typename T>
void DynamicArray<T>::resize()
{
    m_capacity <<= 1;
    T* new_data = new T[m_capacity];

    for (size_t i = 0; i < m_size; ++i)
    {
        new_data[i] = m_data[i];
    }
    delete[] m_data;
    m_data = new_data;
}

}  // namespace CIU
