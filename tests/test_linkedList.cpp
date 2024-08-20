#include <gtest/gtest.h>

#include "linkedList.h"

// ============================================================================

TEST(LinkedList, Default_Constructor)
{
    CIU::LinkedList<int> list;
    EXPECT_EQ(list.size(), 0);
}
