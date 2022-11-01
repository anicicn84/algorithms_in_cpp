#pragma once

// Given a string s that represents a DNA sequence, and a number k, 
// return all the contiguous sequences (substrings) of length k 
// that occur more than once in the string. 
// The order of the returned subsequences does not matter. 
// If no repeated subsequence is found, the function should return an empty set.

// The DNA sequence is composed of a series of nucleotides abbreviated as A
// A, C, G, and T. For example, ACGAATTCCG is a DNA sequence. 
// When studying DNA, it is useful to identify repeated sequences in it.

// ================================================================
// Example (1):
// ================================================================
// Input:
// Number = 4
// string = "CCATATGTATGGATAT"
//             ----      ----
// Then the Output String = "ATAT"
// ================================================================

// ================================================================
// Example (2):
// ================================================================
// Input:
// Number = 8
// string = "AAAACCCCTAAAACCCC"
//           -------- --------
// Then the Output String = "AAAACCCC"
// ================================================================

// ================================================================
// Example (3):
// ================================================================
// Input:
// Number = 5
// string = "AGCTGAAAGCTTAGCTG"
//           -----       -----
// Then the Output String = "AGCTG"
// ================================================================

// ================================================================
// Example (4):
// ================================================================
// Input:
// Number = 6
// string = "ATATATATATATATAT"
//           ------------       OR
//            ------------
// Then the Output String = "TATATA" or "ATATAT" (both)
// ================================================================

#include <set>
#include <string>
#include <cstdint>
#include <functional>
#include <unordered_map>

namespace find_repeated_dna_sequences
{
    std::set<std::string> find_repeated_dna_sequences(const std::string& s, uint16_t k)
    {
        std::set<std::string> result{};
        if (s.length() < k) 
            return result;
        if (s.length() == k)
        {
            result.insert(s);
            return result;
        }
        std::unordered_map<std::string, size_t> hash_map;
        // First k characters, add to a hash map
        hash_map.insert({s.substr(0, k), std::hash<std::string>{}(s.substr(0, k))});

        for (unsigned int idx = 1; idx < s.length() - k + 1; idx++) 
        {
            std::string next_window = s.substr(idx, k);
            if (hash_map.find(next_window) == hash_map.end())
            {
                hash_map.insert({next_window, std::hash<std::string>{}(next_window)});
            }
            else 
            {
                // Already present pattern, add it to the set
                result.insert(next_window);
            }
        }
        return result;
    }

    // ================================================================
    // Another solution (with a rolling hash):
    // ================================================================ 

    std::set<std::string> find_repeated_dna_sequences1(const std::string& s, uint16_t k)
    {
        // In this solution we do not have to precompute the hash of the whole subarray
        // but, instead, we remove one letter and add one to the window. 
        // This is more optimal approach since we put less pressure to the hash function.
        // This is how rsync works and Rabin-Karp algorithm.

        int windowSize = k;
        if (s.size() <= windowSize)
        {
            return {};
        }
        // parameters of rolling hash
        int base = 4;                                  // 'a', the hash parameter
        int hiPlaceValue = std::pow(base, windowSize); // a^k, the highest place value

        // mapping of a character into an integer
        std::map<char, int> mapping;

        // Only these 4 values come into consideration for DNA sequence
        // so let's map them to numbers
        mapping['A'] = 1;
        mapping['C'] = 2;
        mapping['G'] = 3;
        mapping['T'] = 4;

        // mapped numbers from the init string
        // Convert string s to mapped numbers, like ABCD = 1234
        std::vector<int> numbers{};
        for (unsigned int i = 0; i < s.size(); i++)
        {
            numbers.push_back(mapping[s[i]]);
        }
        int hashing = 0;
        std::set<int> substringHashes{};
        std::set<std::string> output{};

        // iterate over all window-sized substrings
        for (unsigned int start = 0; start < s.length() - windowSize + 1; start++)
        {
            // hash function of current subsequence
            if (start != 0)
            {
                hashing = hashing * base - numbers[start - 1] * hiPlaceValue + numbers[start + windowSize - 1];
            }
            else
            {
                for (int end = 0; end < windowSize; end++)
                {
                    hashing = hashing * base + numbers[end];
                }
            }
            // subsequence and output sets
            if (substringHashes.find(hashing) != substringHashes.end())
            {
                output.insert(s.substr(start, windowSize));
            }
            substringHashes.insert(hashing);
        }
        return output;
    }
}