#include "testpch.h"

#include <memory>

namespace nyvux
{
	class IAdaptableA
	{
	public:
		virtual int foo() = 0;
	};

	class IAdaptableB
	{
	public:
		virtual int bar() = 0;
	};

	class IAdaptableAA : public virtual IAdaptableA
	{
	public:
		virtual int baz() = 0;
	};

	class IAdaptableAC : public virtual IAdaptableA
	{
	public:
		virtual int qux() = 0;
	};

	class IAdaptableAAAC : public virtual IAdaptableAA, public virtual IAdaptableAC
	{
	public:
		virtual int quux() = 0;
	};

	class OnlyA : public IAdaptableA
	{
	public:
		int foo() override
		{
			return 0;
		}
	};

	class OnlyB : public IAdaptableB
	{
	public:
		int bar() override
		{
			return 1;
		}
	};

	class BothAB : public IAdaptableA, public IAdaptableB
	{
	public:
		int foo() override
		{
			return 2;
		}
		int bar() override
		{
			return 3;
		}
	};

	class OnlyAA : public IAdaptableAA
	{
	public:
		int foo() override
		{
			return 4;
		}

		int baz() override
		{
			return 5;
		}
	};

	class BothAAB : public IAdaptableAA, public IAdaptableB
	{
		int foo() override
		{
			return 6;
		}
		int bar() override
		{
			return 7;
		}
		int baz() override
		{
			return 8;
		}
	};

	class OnlyAC : public IAdaptableAC
	{
		int foo() override
		{
			return 9;
		}
		int qux() override
		{
			return 10;
		}
	};

	class BothAAAC : public IAdaptableAAAC
	{
		int foo() override
		{
			return 11;
		}
		int baz() override
		{
			return 12;
		}
		int qux() override
		{
			return 13;
		}
		int quux() override
		{
			return 14;
		}
	};
	TEST(AdapterTest, TestAdapt)
	{
		using namespace std;

		shared_ptr<OnlyA> A = make_shared<OnlyA>();
		shared_ptr<OnlyB> B = make_shared<OnlyB>();
		shared_ptr<BothAB> AB = make_shared<BothAB>();
		shared_ptr<OnlyAA> AA = make_shared<OnlyAA>();
		shared_ptr<BothAAB> AAB = make_shared<BothAAB>();

		shared_ptr<IAdaptableB> AtoB = dynamic_pointer_cast<IAdaptableB>(A);
		shared_ptr<IAdaptableA> AtoA = dynamic_pointer_cast<IAdaptableA>(A);
		shared_ptr<IAdaptableAA> AtoAA = dynamic_pointer_cast<IAdaptableAA>(A);

		shared_ptr<IAdaptableA> BtoA = dynamic_pointer_cast<IAdaptableA>(B);
		shared_ptr<IAdaptableB> BtoB = dynamic_pointer_cast<IAdaptableB>(B);
		shared_ptr<IAdaptableAA> BtoAA = dynamic_pointer_cast<IAdaptableAA>(B);

		shared_ptr<IAdaptableA> ABtoA = dynamic_pointer_cast<IAdaptableA>(AB);
		shared_ptr<IAdaptableB> ABtoB = dynamic_pointer_cast<IAdaptableB>(AB);
		shared_ptr<IAdaptableAA> ABtoAA = dynamic_pointer_cast<IAdaptableAA>(AB);

		shared_ptr<IAdaptableA> AAtoA = dynamic_pointer_cast<IAdaptableA>(AA);
		shared_ptr<IAdaptableB> AAtoB = dynamic_pointer_cast<IAdaptableB>(AA);
		shared_ptr<IAdaptableAA> AAtoAA = dynamic_pointer_cast<IAdaptableAA>(AA);

		shared_ptr<IAdaptableA> AABtoA = dynamic_pointer_cast<IAdaptableA>(AAB);
		shared_ptr<IAdaptableB> AABtoB = dynamic_pointer_cast<IAdaptableB>(AAB);
		shared_ptr<IAdaptableAA> AABtoAA = dynamic_pointer_cast<IAdaptableAA>(AAB);


		EXPECT_EQ(0, A->foo());
		EXPECT_EQ(1, B->bar());
		EXPECT_EQ(2, AB->foo());
		EXPECT_EQ(3, AB->bar());
		EXPECT_EQ(4, AA->foo());
		EXPECT_EQ(5, AA->baz());

		EXPECT_EQ(nullptr, AtoB);
		EXPECT_EQ(nullptr, AtoAA);

		EXPECT_EQ(nullptr, BtoA);
		EXPECT_EQ(nullptr, BtoAA);

		EXPECT_EQ(nullptr, ABtoAA);

		EXPECT_EQ(nullptr, AAtoB);

		EXPECT_EQ(0, AtoA->foo());
		EXPECT_EQ(1, BtoB->bar());
		EXPECT_EQ(2, ABtoA->foo());
		EXPECT_EQ(3, ABtoB->bar());
		EXPECT_EQ(4, AAtoA->foo());
		EXPECT_EQ(4, AAtoAA->foo());
		EXPECT_EQ(5, AAtoAA->baz());
		EXPECT_EQ(6, AABtoA->foo());
		EXPECT_EQ(7, AABtoB->bar());
		EXPECT_EQ(6, AABtoAA->foo());
		EXPECT_EQ(8, AABtoAA->baz());

		// check diamond problem
		shared_ptr<OnlyAC> AC = make_shared<OnlyAC>();
		shared_ptr<BothAAAC> AAAC = make_shared<BothAAAC>();

		shared_ptr<IAdaptableAC> AAtoAC = dynamic_pointer_cast<IAdaptableAC>(AA);
		shared_ptr<IAdaptableAAAC> AAtoAAAC = dynamic_pointer_cast<IAdaptableAAAC>(AA);

		shared_ptr<IAdaptableAA> ACtoAA = dynamic_pointer_cast<IAdaptableAA>(AC);
		shared_ptr<IAdaptableAC> ACtoAC = dynamic_pointer_cast<IAdaptableAC>(AC);
		shared_ptr<IAdaptableAAAC> ACtoAAAC = dynamic_pointer_cast<IAdaptableAAAC>(AC);

		shared_ptr<IAdaptableAA> AAACtoAA = dynamic_pointer_cast<IAdaptableAA>(AAAC);
		shared_ptr<IAdaptableAC> AAACtoAC = dynamic_pointer_cast<IAdaptableAC>(AAAC);
		shared_ptr<IAdaptableAAAC> AAACtoAAAC = dynamic_pointer_cast<IAdaptableAAAC>(AAAC);

		EXPECT_EQ(nullptr, AAtoAC);
		EXPECT_EQ(nullptr, AAtoAAAC);
		EXPECT_EQ(nullptr, ACtoAA);
		EXPECT_EQ(nullptr, ACtoAAAC);

		EXPECT_EQ(4, AAtoAA->foo());
		EXPECT_EQ(5, AAtoAA->baz());

		EXPECT_EQ(9, ACtoAC->foo());
		EXPECT_EQ(10, ACtoAC->qux());

		EXPECT_EQ(11, AAACtoAA->foo());
		EXPECT_EQ(12, AAACtoAA->baz());

		EXPECT_EQ(11, AAACtoAC->foo());
		EXPECT_EQ(13, AAACtoAC->qux());

		EXPECT_EQ(11, AAACtoAAAC->foo());
		EXPECT_EQ(12, AAACtoAAAC->baz());
		EXPECT_EQ(13, AAACtoAAAC->qux());
		EXPECT_EQ(14, AAACtoAAAC->quux());
	}
}
