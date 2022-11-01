#include <gtest/gtest.h>
#include "repeated_DNA_sequences.hpp"

TEST(RepeatedDNAsequence, AlgoTests) 
{
    using OutputType = std::vector<std::set<std::string>>;

    std::vector<std::string> test_strings = {
        "CCATATGTATGGATAT",
        "AAAACCCCTAAAACCCC",
        "AGCTGAAAGCTTAGCTG",
        "ATATATATATATATAT", 
        "AAAAACCCCCAAAAACCCCCC"
    };

    std::vector<uint16_t> sizes = {4, 8, 5, 6, 8};

    OutputType expected_results = {
        std::set<std::string> {"ATAT", "TATG"}, 
        std::set<std::string> {"AAAACCCC"}, 
        std::set<std::string> {"AGCTG"}, 
        std::set<std::string> {"TATATA", "ATATAT"}, 
        std::set<std::string> {"AAACCCCC", "AAAACCCC", "AAAAACCC"}
    };

    for (unsigned int i = 0; i < test_strings.size(); i++)
    {
        std::set<std::string> result = find_repeated_dna_sequences::find_repeated_dna_sequences(test_strings[i], sizes[i]);
        EXPECT_EQ(result, expected_results[i]);

        // ================================================================
        // Another solution tested:
        // ================================================================ 
        
        std::set<std::string> result1 = find_repeated_dna_sequences::find_repeated_dna_sequences1(test_strings[i], sizes[i]);
        EXPECT_EQ(result1, expected_results[i]);
    }
}