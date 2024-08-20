#pragma once

// ============================================================================

namespace CIU
{

/**
 * @brief A dynamic array that can grow and shrink as needed.
 *
 */
template<typename T>
class DynamicArray
{
public:
    DynamicArray();
    DynamicArray(size_t capacity);
    DynamicArray(const DynamicArray<T>& other);
    DynamicArray(DynamicArray<T>&& other);
    ~DynamicArray();

    DynamicArray<T>& operator=(const DynamicArray<T>& other);
    DynamicArray<T>& operator=(DynamicArray<T>&& other);
    T&               operator[](size_t index);
    const T&         operator[](size_t index) const;

    /**
     * @brief Get the size of the array
     *
     * @return size_t The size of the array
     */
    size_t size() const;

    /**
     * @brief Get the capacity of the array
     *
     * @return size_t The capacity of the array
     */
    size_t capacity() const;

    /**
     * @brief Check if the array is empty
     *
     * @return true If the array is empty
     * @return false If the array is not empty
     */
    bool isEmpty() const;

    /**
     * @brief Get the value at the given index
     *
     * @param index The index of the value to get
     * @return T& The value at the given index
     */
    void pushBack(const T& value);

    /**
     * @brief Remove the last element from the array
     *
     * @return T The value that was removed
     */
    T popBack();

    /**
     * @brief Insert a value at the given index
     *
     * @param index The index to insert the value at
     * @param value The value to insert
     */
    void insert(size_t index, const T& value);

    /**
     * @brief Append a value to the end of the array
     *
     * @param value The value to append
     */
    void prepend(const T& value);

    /**
     * @brief Remove the value at the given index
     *
     * @param index The index of the value to remove
     */
    void deleteAt(size_t index);

    /**
     * @brief Remove the all occurrences of the given value
     *
     * @param value The value to remove
     */
    void remove(const T& value);

    /**
     * @brief Find the first occurrence of the given value
     *
     * @param value The value to find
     * @return The index of the value. -1 if the value is not found.
     */
    int find(const T& value);
private:
    T*     m_data;
    size_t m_size;
    size_t m_capacity;

    void   resize();
};

}  // namespace CIU

#include "dynamicArray.hpp"
