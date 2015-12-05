#include <T_Stack.h>
#include <gtest.h>


TEST(T_Stack, cant_create_stack_with_negative_length)
{
	ASSERT_ANY_THROW(T_Stack <int> s(-2));
}

TEST(T_Stack, can_create_stack_with_positive_length)
{
	ASSERT_NO_THROW(T_Stack <double> s(3));
}

TEST(T_Stack, can_create_stack_with_default_size)
{
	ASSERT_NO_THROW(T_Stack <int> s);
}

TEST(T_Stack, can_copy_stack)
{
	T_Stack <int> s1(10);
	ASSERT_NO_THROW(T_Stack <int> s(s1));
}

TEST(T_Stack, copied_stack_has_its_own_memory)
{
	T_Stack <int> s1(6);
	T_Stack <int> s(s1);
	s1.Push(2);
	s.Push(3);

	EXPECT_NE(s.Top(), s1.Top());
}

TEST(T_Stack, can_assign_stack_of_different_sizes)
{
	T_Stack <int> s1(7), s2(9);
	s1.Push(4);
	s2 = s1;

	EXPECT_EQ(s1.Pop(), s2.Pop());
}

TEST(T_Stack, can_assign_stack_to_itself)
{
	T_Stack <int> s(5);

	ASSERT_NO_THROW(s = s);
}

TEST(T_Stack, can_show_top_value_of_stack)
{
	T_Stack <int> s(5);
	s.Push(3);
	s.Push(5);

	EXPECT_EQ(5, s.Top());
	EXPECT_EQ(5, s.Top());
}

TEST(T_Stack, cant_show_top_value_of_empty_stack)
{
	T_Stack <int> s(5);

	ASSERT_ANY_THROW(s.Top());
}

TEST(T_Stack, can_pull_top_value_from_stack)
{
	T_Stack <int> s(5);
	s.Push(3);

	EXPECT_EQ(3, s.Pop());
	EXPECT_EQ(true, s.IsEmpty());
}

TEST(T_Stack, cant_pull_top_value_from_empty_stack)
{
	T_Stack <int> s(5);

	ASSERT_ANY_THROW(s.Pop());
}

TEST(T_Stack, can_push_number_to_stack)
{
	T_Stack <int> s(5);
	s.Push(5);

	EXPECT_EQ(5, s.Top());
}

TEST(T_Stack, cant_push_number_to_full_stack)
{
	T_Stack <int> s(3);
	s.Push(4);
	s.Push(5);
	s.Push(5);

	ASSERT_ANY_THROW(s.Push(3));
}