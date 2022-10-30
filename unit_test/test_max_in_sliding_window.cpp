#include <gtest/gtest.h>
#include "max_in_sliding_window.hpp"

TEST(MaxInSlidingWindow, AlgoTests) {
    // Window sizes for below's test array (matching on the indices)
    std::vector<int> targetList = {3, 2, 1, 2, 4, 3, 2};

    std::vector<std::vector<int>> numsList = {
        {1, 2, 3, 4, 5, 6, 7, 8, 9, 10},
        {10, 6, 9, -3, 23, -1, 34, 56, 67, -1, -4, -8, -2, 9, 10, 34, 67},
        {4, 5, 6, 1, 2, 3},
        {9, 5, 3, 1, 6, 3},
        {2, 4, 6, 8, 10, 12, 14, 16},
        {-1, -1, -2, -4, -6, -7},
        {4, 4, 4, 4, 4, 4}
    };

    std::vector<std::vector<int>> expected_results = {
        {3, 4, 5, 6, 7, 8, 9, 10}, 
        {10, 9, 9, 23, 23, 34, 56, 67, 67, -1, -4, -2, 9, 10, 34, 67},
        {4, 5, 6, 1, 2, 3},
        {9, 5, 3, 6, 6},
        {8, 10, 12, 14, 16},
        {-1, -1, -2, -4},
        {4, 4, 4, 4, 4}
    };

    for (int i = 0; i < targetList.size(); i++)
    {
        std::vector<int> result = sliding_window_max_elements::FindMaxSlidingWindow(numsList[i], targetList[i]);
        EXPECT_EQ(result, expected_results[i]);
    }
}