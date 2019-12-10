#include "TList.h"
#include "gtest.h"

TEST(Iterator, can_create_iterator)
{
	ASSERT_NO_THROW(TList<int>::iterator it);
}

TEST(Iterator, can_create_copied_iterator)
{
	TList<int>::iterator it1;
	ASSERT_NO_THROW(TList<int>::iterator it2(it1));
}

TEST(Iterator, can_assign_iterator)
{
	TList<int>::iterator it1, it2;
	ASSERT_NO_THROW(it2 = it1);
}

TEST(Iterator, can_rename_iterator)
{
	TList<int> lst;
	TList<int>::iterator it;
		lst.Push(5);
	it = lst.Begin();
	EXPECT_EQ(5, *(it));
}

TEST(Iterator, can_increment_iterator)
{
	TList<int> lst;
	lst.Push(1);
	lst.Push(2);
	TList<int>::iterator it;
	it = lst.Begin();
	++it;
	EXPECT_EQ(2, *(it));
}