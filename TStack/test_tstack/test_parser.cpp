#include <TParser.h>
#include <gtest.h>


TEST(TParser, can_create_parser)
{
	ASSERT_NO_THROW(TParser p("2+2"));
}

TEST(TParser, can_create_parser_default)
{
	ASSERT_NO_THROW(TParser p);
}

TEST(TParser, can_check_right_placement_of_parenthesis)
{
	TParser p("4*(5+7)");

	EXPECT_EQ(true, p.CheckParentheses());
}