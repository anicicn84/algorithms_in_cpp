#pragma once

#include <string>
// Given strings str1 and str2, find the minimum (contiguous) substring subStr of str1, 
// such that every character of str2 appears in subStr in the SAME ORDER as it is present in str2.
// If there is no window in str1 that covers all characters in str2, return an empty string.
// If there are multiple minimum-length windows, return the one with the leftmost starting index.

// ================================================================
// Example (1):
// ================================================================
// str1 = "abcdebdde"
// str2 = "bde"
// Then the Output String = "bcde"
// ================================================================

// Explanation (1)
// ================================================================
// The strings "bcde" and "bdde" are both minimum subsequences, 
// but "bcde" occurs before "bdde".The substring “deb” is the 
// shortest to contain all there quired characters, but they do 
// not appear in the required order.
// ================================================================

// ================================================================
// Example (2):
// ================================================================
// str1 = "abcdebdde"
// str2 = "bdf"
// Then the Output String = ""
// ================================================================

// Explanation (2)
// ================================================================
// str1 does not contain character "f" that's 
// why an empty string is returned.
// ================================================================


namespace minimum_window_subsequence
{
    std::string minimum_window_subsequence(const std::string& str1, const std::string str2) 
    {
        size_t sizeStr1 = str1.length();
        size_t sizeStr2 = str2.length();

        uint32_t length = UINT32_MAX;
        int traverseStr1Index = 0;
        int traverseStr2Index = 0;
        std::string min_subsequence{};

        // process every character of str1
        // avoid signed-unsigned conversion, if the int is negative
        // then it will be propagated to singed integer, usually a big one.
        while (traverseStr1Index < static_cast<int>(sizeStr1)) 
        {
            // check if the index pointed at str1 by traverseStr1Index
            // is the same as index pointed at str2 by traverseStr2Index
            if (str1[traverseStr1Index] == str2[traverseStr2Index])
            {
                // then we increment traverseStr2Index to see the next one
                traverseStr2Index++;
                // now do the check if traverseStr2Index has reached the end of str2
                if (traverseStr2Index == sizeStr2)
                {
                    // we are reached the full length, one index beyond the current str2
                    // At this point str1 contains all of the characters of str2
                    int start = traverseStr1Index; 
                    int end = traverseStr1Index + 1;

                    // Now initialize the start to the index where all of the characters
                    // of str2 were present in str1.
                    // We now go backwards.
                    // Decrease index by one, since at this point it is one ptr beyond str2.
                    traverseStr2Index--;
                    // Start the reverse loop (explained below the code at the end of the file)
                    while (traverseStr2Index >= 0)
                    {
                        // Decrement index of str2 until all characters 
                        // of str2 are present in str1
                        if (str1[start] == str2[traverseStr2Index])
                        { 
                            traverseStr2Index--;
                        }

                        // Decrement start index everytime to find the starting point
                        // of the required subsequence
                        start --;
                    }
                    // This increment is done because at the end of the loop the start pointer is pointing at an 
                    // index one less than the one we actually require.
                    // Compensating for 1 decrement too much.
                    start++;
                    if (end - start < length)
                    {
                        // Update the length if the current subsequence is shorter
                        length = end - start;
                        // Update min subsequence string to the shorter stirng
                        min_subsequence = str1.substr(start, length);
                    }

                    // Set index of str1 to start to continue checking in str1
                    // after this discovered subsequence
                    traverseStr1Index = start;
                    // Set index of str2 to 0 to try to find another subsequence that is shorter.
                    traverseStr2Index = 0;
                }
            }
            // Increment the index of str1 since we are still looking for the elements
            traverseStr1Index++;
        }
        return min_subsequence;
    }
}

// ================================================================
// More explanation about right to left traverse
// ================================================================
// You might notice we are finding the sequence from left to right
// and then again from right to the left. This is to avoid some of
// the edge cases, for example, imagine we have:
// str1 = "abbcccdde" and str2 = "cde".
// The obvious solution is "cdde". But in the forward left to right
// approach we would take into account only the first 'c' we have
// found and then the solution we would get will be "cccdde". 
// Like this, right to left, we can capture the right most border, 
// meaning the smallest possible length on two-way approach/check.