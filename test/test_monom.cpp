#include <gtest.h>
#include "monom.h"

TEST(Monom, can_create) {
	ASSERT_NO_THROW(monom m(1,123));
}

TEST(Monom, can_set_and_get) {
	monom m;
	m.SetCoefficient(10);
	m.SetDegree(101);

	EXPECT_EQ(10, m.GetCoefficient());
	EXPECT_EQ(101, m.GetDegree());
}

TEST(Monom, can_check_equality)
{
	monom a(1,123);
	monom b(1,123);
	EXPECT_TRUE(a==b);
}

TEST(Monom, can_check_not_equality_coefficient) {
	monom a(1, 123);
	monom b(10, 123);
	EXPECT_FALSE(a == b);
}

TEST(Monom, can_check_noy_equality_degree) {
	monom a(1, 100);
	monom b(1, 123);
	EXPECT_FALSE(a == b);
}

TEST(Monom, can_compare_noy_equality_monoms_by_degree) {
	monom a(1, 100);
	monom b(1, 123);
	EXPECT_TRUE(a < b);
	EXPECT_FALSE(a > b);
}
