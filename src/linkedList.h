#pragma once

// ============================================================================

namespace CIU
{

template<typename T>
class LinkedList
{
public:
    LinkedList();
    LinkedList(const LinkedList<T>& other);
    ~LinkedList();

    LinkedList<T>& operator=(const LinkedList<T>& other);

    /**
     * @brief Get the size of the linked list
     *
     * @return size_t The size of the linked list
     */
    size_t size() const;

    /**
     * @brief Check if the linked list is empty
     *
     * @return true The linked list is empty
     * @return false The linked list is not empty
     */
    bool empty() const;

    /**
     * @brief Get the value at the specified index
     *
     * @param index The index of the value to get
     * @return const T& The value at the specified index
     */
    const T& valueAt(size_t index) const;

    /**
     * @brief Get the value at the specified index
     *
     * @param index The index of the value to get
     * @return T& The value at the specified index
     */
    T& valueAt(size_t index);

    /**
     * @brief Add a value to the front of the linked list
     *
     * @param value The value to add
     */
    void pushFront(const T& value);

    /**
     * @brief Remove the value at the front of the linked list
     *
     * @return T The value at the front of the linked list
     */
    T popFront();

    /**
     * @brief Add a value to the back of the linked list
     *
     * @param value The value to add
     */
    void pushBack(const T& value);

    /**
     * @brief Remove the value at the back of the linked list
     *
     * @return T The value at the back of the linked list
     */
    T popBack();

    /**
     * @brief Get the value at the front of the linked list
     *
     * @return const T& The value at the front of the linked list
     */
    const T& front() const;

    /**
     * @brief Get the value at the front of the linked list
     *
     * @return T& The value at the front of the linked list
     */
    T& front();

    /**
     * @brief Get the value at the back of the linked list
     *
     * @return const T& The value at the back of the linked list
     */
    const T& back() const;

    /**
     * @brief Get the value at the back of the linked list
     *
     * @return T& The value at the back of the linked list
     */
    T& back();

    /**
     * @brief Insert a value at the specified index
     *
     * @param index The index to insert the value
     * @param value The value to insert
     */
    void insert(size_t index, const T& value);

    /**
     * @brief Erase the value at the specified index
     *
     * @param index The index to erase the value
     */
    void erase(size_t index);

    /**
     * @brief Get the value at the specified index from the end of the linked list
     *
     * @param n The index from the end of the linked list
     * @return const T& The value at the specified index from the end of the linked list
     */
    const T& valueNFromEnd(size_t n) const;

    /**
     * @brief Get the value at the specified index from the end of the linked list
     *
     * @param n The index from the end of the linked list
     * @return T& The value at the specified index from the end of the linked list
     */
    T& valueNFromEnd(size_t n);

    /**
     * @brief Reverse the linked list
     */
    void reverse();

    /**
     * @brief Remove the first occurrence of the specified value
     *
     * @param value The value to remove
     */
    void removeValue(const T& value);
private:
    struct Node
    {
        T     data;
        Node* next;
    };

    Node*  m_head;
    Node*  m_tail;
    size_t m_size;
};

}  // namespace CIU

#include "linkedList.hpp"
