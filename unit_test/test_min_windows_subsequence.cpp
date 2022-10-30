#include <gtest/gtest.h>
#include "minimum_window_subsequence.hpp"

TEST(MinWindowSubsequence, AlgoTests) 
{
    std::vector<std::string> input = {"abcdebdde", 
                                      "fgrqsqsnodwmxzkzxwqegkndaa",
                                      "qwewerrty", 
                                      "aaabbcbq", 
                                      "zxcvnhss", 
                                      "alpha",
                                      "beta", 
                                      "asd", 
                                      "abcd",
                                      "abbbccdde"};

    std::vector<std::string> substr = {"bde", 
                                       "kzed", 
                                       "werty", 
                                       "abc",
                                       "css", 
                                       "la", 
                                       "ab", 
                                       "as", 
                                       "pp",
                                       "cde"};
    
    std::vector<std::string> expected_outputs = {"bcde", 
                                                 "kzxwqegknd", 
                                                 "werrty", 
                                                 "abbc", 
                                                 "cvnhss", 
                                                 "lpha", 
                                                 "", 
                                                 "as", 
                                                 "",
                                                 "cdde"
    };

    for (size_t i = 0; i < input.size(); i++)
    {
        auto result = minimum_window_subsequence::minimum_window_subsequence(input[i], substr[i]);
        EXPECT_EQ(result, expected_outputs[i]);
    }
}