#include <gtest/gtest.h>

#include "dynamicArray.h"

TEST(DynamicArray, Default_Constructor)
{
    CIU::DynamicArray<int> array;
    EXPECT_EQ(array.size(), 0);
    EXPECT_EQ(array.capacity(), 0);
}

TEST(DynamicArray, Constructor)
{
    CIU::DynamicArray<int> array(10);
    EXPECT_EQ(array.size(), 0);
    EXPECT_EQ(array.capacity(), 16);
}

TEST(DynamicArray, Is_Empty)
{
    CIU::DynamicArray<int> array;
    EXPECT_TRUE(array.isEmpty());
}

TEST(DynamicArray, Push_Back)
{
    CIU::DynamicArray<int> array(3);
    array.pushBack(1);
    array.pushBack(2);
    array.pushBack(3);

    EXPECT_EQ(array.size(), 3);
    EXPECT_EQ(array.capacity(), 4);
}

TEST(DynamicArray, Subscript_Operator)
{
    CIU::DynamicArray<int> array(1);
    array.pushBack(1);

    EXPECT_EQ(array[0], 1);
}

TEST(DynamicArray, Subscript_Operator_Out_Of_Bounds)
{
    CIU::DynamicArray<int> array;

    EXPECT_THROW(array[1], std::out_of_range);
}

TEST(DynamicArray, Copy_Constructor)
{
    CIU::DynamicArray<int> array(10);
    array.pushBack(1);
    array.pushBack(2);
    array.pushBack(3);

    CIU::DynamicArray<int> copy(array);
    EXPECT_EQ(copy.size(), 3);
    EXPECT_EQ(copy.capacity(), 16);

    for (size_t i = 0; i < copy.size(); ++i)
    {
        EXPECT_EQ(copy[i], array[i]);
    }
}

TEST(DynamicArray, Move_Constructor)
{
    CIU::DynamicArray<int> array(10);
    array.pushBack(1);
    array.pushBack(2);
    array.pushBack(3);

    CIU::DynamicArray<int> moved(std::move(array));
    EXPECT_EQ(moved.size(), 3);
    EXPECT_EQ(moved.capacity(), 16);

    for (size_t i = 0; i < moved.size(); ++i)
    {
        EXPECT_EQ(moved[i], i + 1);
    }
}

TEST(DynamicArray, Copy_Assignment)
{
    CIU::DynamicArray<int> array(10);
    array.pushBack(1);
    array.pushBack(2);
    array.pushBack(3);

    CIU::DynamicArray<int> copy;
    copy = array;
    EXPECT_EQ(copy.size(), 3);
    EXPECT_EQ(copy.capacity(), 16);

    for (size_t i = 0; i < copy.size(); ++i)
    {
        EXPECT_EQ(copy[i], array[i]);
    }
}

TEST(DynamicArray, Move_Assignment)
{
    CIU::DynamicArray<int> array(10);
    array.pushBack(1);
    array.pushBack(2);
    array.pushBack(3);

    CIU::DynamicArray<int> moved;
    moved = std::move(array);
    EXPECT_EQ(moved.size(), 3);
    EXPECT_EQ(moved.capacity(), 16);

    for (size_t i = 0; i < moved.size(); ++i)
    {
        EXPECT_EQ(moved[i], i + 1);
    }
}

TEST(DynamicArray, Pop_Back)
{
    CIU::DynamicArray<int> array(3);
    array.pushBack(1);
    array.pushBack(2);
    array.pushBack(3);

    int value = array.popBack();
    EXPECT_EQ(value, 3);
    EXPECT_EQ(array.size(), 2);
    EXPECT_EQ(array.capacity(), 4);
}

TEST(DynamicArray, Pop_Back_Empty)
{
    CIU::DynamicArray<int> array;

    EXPECT_THROW(array.popBack(), std::out_of_range);
}

TEST(DynamicArray, Insert)
{
    CIU::DynamicArray<int> array(3);
    array.pushBack(1);
    array.pushBack(2);
    array.pushBack(3);

    array.insert(1, 4);
    EXPECT_EQ(array.size(), 4);
    EXPECT_EQ(array.capacity(), 4);
    EXPECT_EQ(array[1], 4);
}

TEST(DynamicArray, Prepend)
{
    CIU::DynamicArray<int> array(3);
    array.pushBack(1);
    array.pushBack(2);
    array.pushBack(3);

    array.prepend(4);
    EXPECT_EQ(array.size(), 4);
    EXPECT_EQ(array.capacity(), 4);
    EXPECT_EQ(array[0], 4);
}

TEST(DynamicArray, Delete_At)
{
    CIU::DynamicArray<int> array(3);
    array.pushBack(1);
    array.pushBack(2);
    array.pushBack(3);

    array.deleteAt(1);
    EXPECT_EQ(array.size(), 2);
    EXPECT_EQ(array.capacity(), 4);
    EXPECT_EQ(array[1], 3);
}

TEST(DynamicArray, Remove_SingleInstance)
{
    CIU::DynamicArray<int> array(3);
    array.pushBack(1);
    array.pushBack(2);
    array.pushBack(3);

    array.remove(2);
    EXPECT_EQ(array.size(), 2);
    EXPECT_EQ(array.capacity(), 4);
    EXPECT_EQ(array[1], 3);
}

TEST(DynamicArray, Remove_MultipleInstance)
{
    CIU::DynamicArray<int> array(5);
    array.pushBack(1);
    array.pushBack(2);
    array.pushBack(3);
    array.pushBack(2);
    array.pushBack(4);

    array.remove(2);
    EXPECT_EQ(array.size(), 3);
    EXPECT_EQ(array.capacity(), 8);
    EXPECT_EQ(array[1], 3);
    EXPECT_EQ(array[2], 4);
}
