#include <gtest/gtest.h>
#include "myString.h" // Make sure this is the correct path to your myString class header

/*
  This is the prompt I used.
  I need a test file in c++ that uses the google test framework to test the different methods of a class I made called myString. Currently I have a toString() method which should take no arguments but use the private char array variable mystr, which it gets from the constructor myString(std::string input), and convert that into a c++ standard library string. Next, I have a method called length() which should return the length of the mystr variable as an integer. Lastly, I have a method called substrate(int start, int n) which takes the integers start and n to return a substring of the mastering variable where the substring starts at index start and ends at index n.
 */

// Test the toString() method
TEST(MyStringTest, ToString) {
    myString str("Hello, World!");
    EXPECT_EQ(str.toString(), "Hello, World!");
}

// Test the length() method
TEST(MyStringTest, Length) {
    myString str("Hello, World!");
    EXPECT_EQ(str.length(), 13);
    
    myString emptyStr("");
    EXPECT_EQ(emptyStr.length(), 0);
}

// Test the substring() method
TEST(MyStringTest, Substring) {
    myString str("Hello, World!");
    
    // Basic substring extraction
    EXPECT_EQ(str.substring(0, 5), "Hello");
    EXPECT_EQ(str.substring(7, 5), "World");
    
    // Edge cases
    EXPECT_EQ(str.substring(0, 0), "");      // Zero length
    EXPECT_EQ(str.substring(0, 13), "Hello, World!"); // Full length
    
    // Out-of-bound cases (assuming substring handles these by returning empty or partial valid parts)
    EXPECT_EQ(str.substring(20, 5), "");     // Start beyond length
    EXPECT_EQ(str.substring(5, 20), ", World!"); // Exceeds length but within valid start
}

// Main function for running all tests
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
