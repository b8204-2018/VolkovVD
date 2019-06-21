#include "gtest/gtest.h"
#include "OPZ.h"

using namespace std;


TEST(InvalidExpression, EmptyString) {
    string test("");
    Polska polska(test);
    ASSERT_THROW(polska(test), EMPTY);
}

TEST(InvalidExpression, ExtraRightBracket) {
    string test("(2+5))");
    Polska polska(test);
    ASSERT_THROW(polska(test), invalid_argument);
}

TEST(InvalidExpression, ExtraLeftBracket) {
    string test("((2+5)");
    Polska polska(test);
    ASSERT_THROW(polska(test), invalid_argument);
}

TEST(Calculation, NoBrackets_EqualPriorities) {
    string test("5+5-2");
    Polska polska(test);
    EXPECT_EQ(polska(test), 8);
}

TEST(Calculation, NoBrackets_NotEqualPriorities) {
    string test("5+5*1");
    Polska polska(test);
    EXPECT_EQ(polska(test), 10);
    test = "1*5+5";
    EXPECT_EQ(polska(test), 10);
}

TEST(Calculation, Brackets_EqualPriorities) {
    string test("(5+5)-5");
    Polska polska(test);
    EXPECT_EQ(s.solution(ex), 5);
    ex = "5+(2-1)";
    EXPECT_EQ(s.solution(ex), 6);
}

TEST(Calculation, Brackets_NotEqualPriorities) {
    string test("(1+1)*2");
    Polska polska(test);
    EXPECT_EQ(polska(test), 4);
    ex = "2*(1+1)";
    EXPECT_EQ(polska(test), 4);
}


TEST(Calculation, DivisionByZero) {
    string test("(22+17)/0");
    Polska polska(test);
    EXPECT_THROW(polska(test), ZERO);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}