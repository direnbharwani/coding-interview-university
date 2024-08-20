#include <exception>

#include "linkedList.h"

// ============================================================================

namespace CIU
{

template<typename T>
LinkedList<T>::LinkedList()
    : m_head(nullptr)
    , m_tail(nullptr)
    , m_size(0)
{
}

template<typename T>
LinkedList<T>::LinkedList(const LinkedList<T>& other)
    : m_head(nullptr)
    , m_tail(nullptr)
    , m_size(0)
{
    Node* current = other.m_head;
    while (current != nullptr)
    {
        pushBack(current->data);
        current = current->next;
    }
}

template<typename T>
LinkedList<T>::~LinkedList()
{
    while (m_head)
    {
        Node* next = m_head->next;
        delete m_head;
        m_head = next;
    }

    m_head = nullptr;
    m_tail = nullptr;
}

template<typename T>
LinkedList<T>& LinkedList<T>::operator=(const LinkedList<T>& other)
{
    if (this == &other)
    {
        return *this;
    }

    while (m_head)
    {
        Node* next = m_head->next;
        delete m_head;
        m_head = next;
    }

    m_head        = nullptr;
    m_tail        = nullptr;
    m_size        = 0;

    Node* current = other.m_head;
    while (current != nullptr)
    {
        pushBack(current->data);
        current = current->next;
    }

    return *this;
}

template<typename T>
size_t LinkedList<T>::size() const
{
    return m_size;
}

template<typename T>
bool LinkedList<T>::empty() const
{
    return m_size == 0;
}

template<typename T>
const T& LinkedList<T>::valueAt(size_t index) const
{
    if (index < 0 || index >= m_size)
    {
        throw std::out_of_range("Index out of range");
    }

    Node* current = m_head;
    while (index)
    {
        current = current->next;
        --index;
    }

    return current->data;
}

template<typename T>
T& LinkedList<T>::valueAt(size_t index)
{
    if (index < 0 || index >= m_size)
    {
        throw std::out_of_range("Index out of range");
    }

    Node* current = m_head;
    while (index)
    {
        current = current->next;
        --index;
    }

    return current->data;
}

template<typename T>
void LinkedList<T>::pushFront(const T& value)
{
    Node* newNode = new Node(value);
    if (m_size == 0)
    {
        m_head = newNode;
        m_tail = newNode;
        ++m_size;
        return;
    }

    newNode->next = m_head;
    m_head        = newNode;
    ++m_size;
}

template<typename T>
T LinkedList<T>::popFront()
{
    if (m_size == 0)
    {
        throw std::out_of_range("Linked List is empty!");
    }

    if (m_size == 1)
    {
        T returnValue = m_head->data;
        delete m_head;
        m_head = nullptr;
        m_tail = nullptr;
        --m_size;
        return returnValue;
    }

    Node* nextNode    = m_head->next;
    T     returnValue = m_head->data;
    delete m_head;
    m_head = nextNode;
    --m_size;
    return returnValue;
}

template<typename T>
void LinkedList<T>::pushBack(const T& value)
{
    Node* newNode = new Node{value, nullptr};
    if (m_size == 0)
    {
        m_head = newNode;
        m_tail = newNode;
        ++m_size;
        return;
    }

    m_tail->next = newNode;
    m_tail       = newNode;
    ++m_size;
}

template<typename T>
T LinkedList<T>::popBack()
{
    if (m_size == 0)
    {
        throw std::out_of_range("Linked List is empty!");
    }

    if (m_size == 1)
    {
        T returnValue = m_head->data;
        delete m_head;
        m_head = nullptr;
        m_tail = nullptr;
        --m_size;
        return returnValue;
    }

    // Find the node before the m_tail
    Node* current = m_head;
    while (current->next != m_tail)
    {
        current = current->next;
    }

    T returnValue = m_tail->data;
    delete m_tail;
    m_tail       = current;
    m_tail->next = nullptr;
    --m_size;
    return returnValue;
}

template<typename T>
const T& LinkedList<T>::front() const
{
    if (m_size == 0)
    {
        throw std::out_of_range("Linked List is empty!");
    }

    return m_head->data;
}

template<typename T>
T& LinkedList<T>::front()
{
    if (m_size == 0)
    {
        throw std::out_of_range("Linked List is empty!");
    }

    return m_head->data;
}

template<typename T>
const T& LinkedList<T>::back() const
{
    if (m_size == 0)
    {
        throw std::out_of_range("Linked List is empty!");
    }

    return m_tail->data;
}

template<typename T>
T& LinkedList<T>::back()
{
    if (m_size == 0)
    {
        throw std::out_of_range("Linked List is empty!");
    }

    return m_tail->data;
}

template<typename T>
void LinkedList<T>::insert(size_t index, const T& value)
{
    if (index < 0 || index >= m_size)
    {
        throw std::out_of_range("Index out of range");
    }

    if (index == 0)
    {
        pushFront(value);
        return;
    }

    if (index == m_size - 1)
    {
        pushBack(value);
        return;
    }

    Node* current = m_head;
    while (index > 1)
    {
        current = current->next;
        --index;
    }

    Node* newNode = new Node{value, current->next};
    current->next = newNode;
    ++m_size;
}

template<typename T>
void LinkedList<T>::erase(size_t index)
{
    if (index < 0 || index >= m_size)
    {
        throw std::out_of_range("Index out of range");
    }

    if (index == 0)
    {
        popFront();
        return;
    }

    if (index == m_size - 1)
    {
        popBack();
        return;
    }

    Node* current = m_head;
    while (index > 1)
    {
        current = current->next;
        --index;
    }

    Node* nextNode = current->next->next;
    delete current->next;
    current->next = nextNode;
    --m_size;
}

template<typename T>
void LinkedList<T>::reverse()
{
    if (m_size == 0)
    {
        return;
    }

    Node* futureTail = m_head;

    Node* previous   = nullptr;
    Node* current    = m_head;

    while (current != nullptr)
    {
        Node* next    = current->next;
        current->next = previous;
        previous      = current;
        current       = next;
    }

    m_tail = futureTail;
}

}  // namespace CIU
