#include "TList.h"
#include "gtest.h"

TEST(TList, can_create_list)
{
	ASSERT_NO_THROW(TList<int> lst);
}

TEST(TList, can_push_back)
{
	TList<int> lst;
	ASSERT_NO_THROW(lst.Push(5));
}

TEST(TList, can_pop_front)
{
	TList<int> lst;
	lst.Push(5);
	ASSERT_NO_THROW(lst.Pop());
}

TEST(TList, can_create_copied_list)
{
	TList<int> lst1;
	lst1.Push(5);
	ASSERT_NO_THROW(TList<int> lst2 = lst1);
}

TEST(TList, can_assign_list)
{
	TList<int> lst1, lst2;
	lst1.Push(5);
	ASSERT_NO_THROW(lst2 = lst1);
}

TEST(TList, method_pop_front_return_value)
{
	TList<int> lst;
	lst.Push(10);
	EXPECT_EQ(10, lst.Pop());
}

TEST(TList, can_check_for_empty)
{
	TList<int> lst;
	EXPECT_TRUE(lst.Empty());
}

TEST(TList, can_return_size_of_list)
{
	TList<int> lst;
	for (int i = 0; i < 5; i++)
		lst.Push(i);
	EXPECT_EQ(5, lst.GetSize());
}

TEST(TList, method_clear_delete_all_values_of_list)
{
	TList<int> lst;
	for (int i = 0; i < 5; i++)
		lst.Push(i);
	lst.Clear();
	EXPECT_TRUE(lst.Empty());
}

TEST(TList, two_different_lists_have_different_memories)
{
	TList<int> lst1, lst2(lst1);
	EXPECT_NE(&lst1, &lst2);
}

TEST(TList, can_insert_elem_by_iterator)
{
	TList<int> lst;
	TList<int>::iterator it;
	it = lst.Begin();
	lst.Insert(it, 5);
	EXPECT_EQ(5, lst.Pop());
}

TEST(TList, can_erace_elem_by_iterator)
{

	TList<int> lst;
	TList<int>::iterator it;
	lst.Push(10);
	it = lst.Begin();
	ASSERT_NO_THROW(lst.Erase(it));
}

