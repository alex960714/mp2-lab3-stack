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

TEST(TParser, can_check_wrong_placement_of_parenthesis)
{
	TParser p("(4+6");

	EXPECT_EQ(false, p.CheckParentheses());
}

TEST(TParser, post_parsers_calculation)
{
	TParser p("2+7*(5-3)+4*2^2");
	p.inftopost();

	EXPECT_EQ(32, p.CalcPost());
}

TEST(TParser, cant_divide_on_zero_post)
{
	TParser p("2/0");
	p.inftopost();

	ASSERT_ANY_THROW(p.CalcPost());
}

TEST(TParser, inf_parsers_calculation)
{
	TParser p("2+7*(5-3)+4*2^2");

	EXPECT_EQ(32, p.Calc());
}

TEST(TParser, cant_divide_on_zero_inf)
{
	TParser p("2/0");

	ASSERT_ANY_THROW(p.Calc());
}

TEST(TParser, can_calculate_parsers_with_inf_minus_numbers)
{
	TParser p("-2+3");

	EXPECT_EQ(1, p.Calc());
}

TEST(TParser, can_calculate_parsers_with_sin)
{
	TParser p("2+sin(1)");

	EXPECT_EQ(2 + sin(1), p.Calc());
}

TEST(TParser, can_calculate_parsers_with_cos)
{
	TParser p("cos(3)+1");

	EXPECT_EQ(cos(3) + 1, p.Calc());
}

TEST(TParser, can_calculate_parsers_with_ln)
{
	TParser p("ln(3)");

	EXPECT_EQ(log(3), p.Calc());
}

TEST(TParser, cant_calculate_ln_from_negative_number)
{
	TParser p("ln(-3)");

	ASSERT_ANY_THROW(p.Calc());
}