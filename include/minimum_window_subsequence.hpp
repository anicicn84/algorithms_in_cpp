#pragma once

// Given strings str1 and str2, find the minimum (contiguous) substring subStr of str1, 
// such that every character of str2 appears in subStr in the same order as it is present in str2.
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

}