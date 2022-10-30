#pragma once
#include <iostream>
#include <vector>
#include <deque>

// Given an integer array nums and a window of size w
// find the current maximum value in the window as it slides through the entire array.
// Note: If the window size is greater than the array size, we consider the entire array as a single window.

// ============================
// Example:
// ============================
// Window size = 3
// Array = [-4, 2, -5, 3, 6]
// Then the Output = [2, 3, 6]
// ============================

namespace sliding_window_max_elements{
    // ================================== helper methods ==================================

    // Remove first index from the window deque if
    // it doesn't fall in the current window anymore
    void pop_if_window_full(std::deque<int>& window, int windowSize, int currIdx) 
    {
        if (!window.empty() and window.front() <= currIdx - windowSize)
        {
            window.pop_front();
        }
    }

    // For every element, remove the previous smaller elements from window
    void remove_previous_smaller_elements_that_at_currIdx(std::deque<int>& window, 
                                                          const std::vector<int>& nums, 
                                                          int currIdx) 
    {
        while (!window.empty() and nums[currIdx] >= nums[window.back()])
        {
            window.pop_back();
        }
    }

    // ================================== main method ==================================
    std::vector<int> FindMaxSlidingWindow(const std::vector<int>& nums, int windowSize)
    {
        std::vector<int> result;
        // Initializing doubly ended queue for storing indices
        std::deque<int> window;
        // Let’s now return an empty list if nums is empty
        if (nums.size() == 0)
        {
            return result;
        }
        // If windowSize is greater than the array size,
        // set the windowSize to nums.size()
        if (windowSize > nums.size())
        {
            windowSize = nums.size();
        }
        // Find out first maximum in the first window
        for (int i = 0; i < windowSize; ++i)
        {
            remove_previous_smaller_elements_that_at_currIdx(window, nums, i);
            // Add current element at the back of the queue
            window.push_back(i);
        }
        // Appending the largest element in the window to the result
        result.push_back(nums[window.front()]);
        for (int i = windowSize; i < nums.size(); ++i)
        {
            // remove all numbers that are smaller than current number
            // from the tail of list
            remove_previous_smaller_elements_that_at_currIdx(window, nums, i);
            pop_if_window_full(window, windowSize, i);
            // Add current element at the back of the queue
            window.push_back(i);
            result.push_back(nums[window.front()]);
        }
        return result;
    }
}