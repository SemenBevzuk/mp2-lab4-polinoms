#include <gtest.h>
#include "polinom.h"
//#include "monom.h"
// тесты мономов и полиномов

TEST(Polinom, can_create) {
	ASSERT_NO_THROW(Polinom p);
}

TEST(Polinom, can_copy) {
	Polinom a;
	a.AddElement(monom(2,1));
	Polinom b(a);
	EXPECT_EQ(a[0].GetCoefficient(),b[0].GetCoefficient());
	EXPECT_EQ(a.GetLength(), b.GetLength());
}

TEST(Polinom, can_add_monom)
{
	Polinom a;
	a.AddElement(monom(2, 1));
	a.AddElement(monom(5, 10));
	EXPECT_EQ(5, a[0].GetCoefficient());
	EXPECT_EQ(2, a[1].GetCoefficient());
}

TEST(Polinom, can_simplify) {
	Polinom a;
	a.AddElement(monom(3, 100));

	a.AddElement(monom(5, 200));

	a.AddElement(monom(1, 200));

	//1|200,5|200,3|100

	a.Simplify();
	EXPECT_EQ(2,a.GetLength());
	EXPECT_EQ(6, a[0].GetCoefficient());
	EXPECT_EQ(3, a[1].GetCoefficient());
}
TEST(Polinom, can_simplify_2) {
	Polinom a;
	a.AddElement(monom(3, 100));

	a.AddElement(monom(5, 200));

	a.AddElement(monom(1, 200));

	a.AddElement(monom(2, 200));
	std::cout << a[0].GetCoefficient() << std::endl;
	std::cout << a[1].GetCoefficient() << std::endl;
	std::cout << a[2].GetCoefficient() << std::endl;
	std::cout << a[3].GetCoefficient() << std::endl;
	//2|200,1|200,5|200,3|100

	a.Simplify();
	EXPECT_EQ(2, a.GetLength());
	EXPECT_EQ(8, a[0].GetCoefficient());
	EXPECT_EQ(3, a[1].GetCoefficient());
}

TEST(Polinom, can_simplify_3) {
	Polinom a;
	a.AddElement(monom(10, 100));

	a.AddElement(monom(5, 200));

	a.AddElement(monom(1, 200));

	a.AddElement(monom(4, 300));

	a.AddElement(monom(1, 300));
	std::cout << a[0].GetCoefficient() << std::endl;
	std::cout << a[1].GetCoefficient() << std::endl;
	std::cout << a[2].GetCoefficient() << std::endl;
	std::cout << a[3].GetCoefficient() << std::endl;
	std::cout << a[4].GetCoefficient() << std::endl;
	//1|300,4|300,1|200,5|200,10|100

	a.Simplify();
	EXPECT_EQ(3, a.GetLength());
	EXPECT_EQ(5, a[0].GetCoefficient());
	EXPECT_EQ(6, a[1].GetCoefficient());
	EXPECT_EQ(10, a[2].GetCoefficient());
}

TEST(Polinom, can_add) {
	Polinom a;
	a.AddElement(monom(1, 100));
	a.AddElement(monom(2, 200));
	Polinom b;
	b.AddElement(monom(1, 100));
	b.AddElement(monom(3, 300));
	Polinom c;
	c = a + b;

	/*std::cout << a[0].GetCoefficient() << " " << a[0].GetDegree() << std::endl;
	std::cout << a[1].GetCoefficient() << std::endl;
	std::cout << b[0].GetCoefficient() << std::endl;
	std::cout << b[1].GetCoefficient() << std::endl;
	std::cout << c[0].GetCoefficient() << std::endl;
	std::cout << c[1].GetCoefficient() << std::endl;
	std::cout << c[2].GetCoefficient() << std::endl;*/
	//1|300,4|300,1|200,5|200,10|100

	//a.Simplify();
	EXPECT_EQ(3, c.GetLength());
	EXPECT_EQ(3, c[0].GetCoefficient());
	EXPECT_EQ(2, c[1].GetCoefficient());
	EXPECT_EQ(2, c[2].GetCoefficient());
}
TEST(Polinom, can_add_2) {
	Polinom a;
	a.AddElement(monom(1, 100));
	a.AddElement(monom(1, 100));
	Polinom b;
	b.AddElement(monom(1, 100));
	b.AddElement(monom(1, 100));
	Polinom c;
	c = a + b;

	/*std::cout << a[0].GetCoefficient() << " " << a[0].GetDegree() << std::endl;
	std::cout << a[1].GetCoefficient() << std::endl;
	std::cout << b[0].GetCoefficient() << std::endl;
	std::cout << b[1].GetCoefficient() << std::endl;
	std::cout << c[0].GetCoefficient() << std::endl;
	std::cout << c[1].GetCoefficient() << std::endl;
	std::cout << c[2].GetCoefficient() << std::endl;*/
	//1|300,4|300,1|200,5|200,10|100

	//a.Simplify();
	EXPECT_EQ(1, c.GetLength());
	EXPECT_EQ(4, c[0].GetCoefficient());
}

TEST(Polinom, can_minus) {
	Polinom a;
	a.AddElement(monom(2, 100));
	a.AddElement(monom(2, 200));
	Polinom b;
	b.AddElement(monom(1, 100));
	b.AddElement(monom(4, 200));
	Polinom c;
	c = a - b;

	/*std::cout << a[0].GetCoefficient() << " " << a[0].GetDegree() << std::endl;
	std::cout << a[1].GetCoefficient() << std::endl;
	std::cout << b[0].GetCoefficient() << std::endl;
	std::cout << b[1].GetCoefficient() << std::endl;
	std::cout << c[0].GetCoefficient() << std::endl;
	std::cout << c[1].GetCoefficient() << std::endl;
	std::cout << c[2].GetCoefficient() << std::endl;*/
	//1|300,4|300,1|200,5|200,10|100

	//a.Simplify();
	EXPECT_EQ(2, c.GetLength());
	EXPECT_EQ(-2, c[0].GetCoefficient());
	EXPECT_EQ(1, c[1].GetCoefficient());
}