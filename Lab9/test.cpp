#include <gtest/gtest.h>
#include "myString.h"  // Include your myString class header file

// Test fixture for myString class
class MyStringTest : public ::testing::Test {
protected:
    // Member variable for our myString instance
    myString myStr;

    // Set up method
    void SetUp() override {
        // Initialize your myString instance if needed
        // Example: myStr = myString("Hello");
    }

    // Tear down method
    void TearDown() override {
        // Clean up if necessary
    }
};

// Test case for toString method
TEST_F(MyStringTest, ToStringReturnsExpectedString) {
    // Set up your myString instance (assume it has a constructor accepting a C-style string)
    myStr = myString("Hello");

    // Call toString and check if it returns the expected std::string
    std::string result = myStr.toString();
    EXPECT_EQ(result, "Hello");
}

// Add more tests as needed for other methods of myString

// Main function for running tests
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}