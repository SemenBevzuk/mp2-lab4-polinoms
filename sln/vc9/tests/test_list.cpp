#include <gtest.h>
#include "list.h"

TEST(List, can_add_to_head) {
	List<int> list;
	list.AddToHead(2);
	EXPECT_EQ(1, list.GetLength());
	EXPECT_EQ(2,list.GetHead()->GetVar());
}
TEST(List, can_add_to_tail) {
	List<int> list;
	list.AddToHead(1);
	list.AddToTail(4);
	EXPECT_EQ(2, list.GetLength());
	EXPECT_EQ(1, list.GetHead()->GetVar());
	EXPECT_EQ(4, list.GetHead()->GetNext()->GetVar());
}

TEST(List, can_delete_single_element)
{
	List<int> list;
	list.AddToHead(1);
	list.DeleteFirst();

	EXPECT_EQ(0, list.GetLength());
	EXPECT_EQ(NULL, list.GetHead());

}
TEST(List, can_delete_first_element) {
	List<int> list;
	list.AddToHead(1);
	list.AddToTail(4);
	list.DeleteFirst();

	EXPECT_EQ(1, list.GetLength());
	EXPECT_EQ(4, list.GetHead()->GetVar());

}