#include "Test.hpp"
#include "List.hpp"
#include "TestMiscellanea.hpp"
#include <list>
#include <vector>
#include <map>
#include <stack>
#include <queue>
#include <iostream>

// void test_listgroup_iterator()
// {
// 	std::cout << "list::iterator" << std::endl;
// 	std::list<int>	original_list;
// 	ft::List<int>	my_list;
// 	std::list<int>::iterator original_it = original_list.begin();
// 	ft::List<int>::iterator my_it = my_list.begin();

// 	ASSERT_EQ(*original_it, *my_it);
// 	++original_it;
// 	++my_it;
// 	*original_it;
// 	*my_it;

// 	std::list<TestClass>	original_list_class;
// 	ft::List<TestClass>		my_list_class;

// 	std::list<TestClass>::iterator original_class_it = original_list_class.begin();
// 	ft::List<TestClass>::iterator my_class_it = my_list_class.begin();

// 	original_class_it->setA(1);
// 	my_class_it->setA(1);
// 	//std::cout << original_class_it->getA() << std::endl;
// 	//std::cout << my_class_it->getA() << std::endl;
// 	ASSERT_EQ(original_class_it->getA(), my_class_it->getA());

// 	original_class_it->setB("test");
// 	//my_class_it->setB("test");
// 	//std::cout << my_class_it->getB() << std::endl;
// 	//ASSERT_EQ(original_class_it->getB(), my_class_it->getB());

// 	std::cout << std::endl;
// }

void test_listgroup_iterator()
{
	std::cout << "list::iterator" << std::endl;
	std::list<int>	original_list;
	ft::List<int>	my_list;

	my_list.push_back(1);
	my_list.push_back(2);
	my_list.push_back(3);
	original_list.push_back(1);
	original_list.push_back(2);
	original_list.push_back(3);
	std::list<int>::iterator original_it = original_list.begin();
	ft::List<int>::iterator my_it = my_list.begin();
	while (original_it != original_list.end() || my_it != my_list.end())
	{
		ASSERT_EQ(*original_it, *my_it);
		++original_it;
		++my_it;
	}
	ASSERT_EQ(original_it == original_list.end(), my_it == my_list.end());

	--original_it;
	--my_it;
	while (original_it != original_list.begin() || my_it != my_list.begin())
	{
		ASSERT_EQ(*original_it, *my_it);
		--original_it;
		--my_it;
	}
	ASSERT_EQ(original_it == original_list.end(), my_it == my_list.end());

	while (original_it != original_list.end() || my_it != my_list.end())
	{
		ASSERT_EQ(*original_it, *my_it);
		original_it++;
		my_it++;
	}
	ASSERT_EQ(original_it == original_list.end(), my_it == my_list.end());

	original_it--;
	my_it--;
	while (original_it != original_list.begin() || my_it != my_list.begin())
	{
		ASSERT_EQ(*original_it, *my_it);
		original_it--;
		my_it--;
	}
	ASSERT_EQ(original_it == original_list.end(), my_it == my_list.end());

	std::cout << std::endl;
}

void test_listgroup_constiterator()
{
	std::cout << "list::const_iterator" << std::endl;

	std::list<int>	original_list;
	ft::List<int>		my_list;

	my_list.push_back(1);
	my_list.push_back(2);
	my_list.push_back(3);
	original_list.push_back(1);
	original_list.push_back(2);
	original_list.push_back(3);
	std::list<int>::const_iterator original_it = original_list.begin();
	ft::List<int>::const_iterator my_it = my_list.begin();

	while (original_it != original_list.end() || my_it != my_list.end())
	{
		ASSERT_EQ(*original_it, *my_it);
		original_it++;
		my_it++;
	}
	ASSERT_EQ(original_it == original_list.end(), my_it == my_list.end());

	std::cout << std::endl;
}

void test_listgroup_copyconstructor()
{
	std::cout << "list::copy_constructor" << std::endl;
	std::list<int>	original_list;
	ft::List<int>	my_list;

	my_list.push_back(1);
	my_list.push_back(2);
	my_list.push_back(3);
	original_list.push_back(1);
	original_list.push_back(2);
	original_list.push_back(3);

	std::list<int> original_copy = std::list<int>(original_list);
	ft::List<int> my_copy = ft::List<int>(my_list);

	std::list<int>::iterator original_it = original_copy.begin();
	ft::List<int>::iterator my_it = my_copy.begin();
	while (original_it != original_copy.end() || my_it != my_copy.end())
	{
		ASSERT_EQ(*original_it, *my_it);
		++original_it;
		++my_it;
	}
	ASSERT_EQ(original_it == original_list.end(), my_it == my_list.end());

	std::cout << std::endl;
}

void test_listgroup_reverseiterator()
{
	std::cout << "list::reverse_iterator" << std::endl;
	std::list<int>	original_list;
	ft::List<int>	my_list;

	my_list.push_back(1);
	my_list.push_back(2);
	my_list.push_back(3);
	original_list.push_back(1);
	original_list.push_back(2);
	original_list.push_back(3);
	std::list<int>::reverse_iterator original_rev_it = original_list.rbegin();
	ft::List<int>::reverse_iterator my_rev_it = my_list.rbegin();
	while (original_rev_it != original_list.rend() || my_rev_it != my_list.rend())
	{
		int o = *original_rev_it;
		int m = *my_rev_it;
		ASSERT_EQ(o, m);
		++original_rev_it;
		++my_rev_it;
	}
	ASSERT_EQ(original_rev_it == original_list.rend(), my_rev_it == my_list.rend());

	std::cout << std::endl;
}

void test_listgroup_pushback()
{
	std::cout << "list::push_back" << std::endl;
	std::list<int>	original_list;
	ft::List<int>	my_list;

	my_list.push_back(1);
	my_list.push_back(2);
	my_list.push_back(3);
	original_list.push_back(1);
	original_list.push_back(2);
	original_list.push_back(3);
	std::list<int>::iterator original_it = original_list.begin();
	ft::List<int>::iterator my_it = my_list.begin();
	while (original_it != original_list.end() || my_it != my_list.end())
	{
		ASSERT_EQ(*original_it, *my_it);
		++original_it;
		++my_it;
	}
	ASSERT_EQ(original_it == original_list.end(), my_it == my_list.end());

	std::cout << std::endl;
}

void test_listgroup_pushfront()
{
	std::cout << "list::push_front" << std::endl;
	std::list<int>	original_list;
	ft::List<int>	my_list;

	my_list.push_front(1);
	my_list.push_front(2);
	my_list.push_front(3);
	original_list.push_front(1);
	original_list.push_front(2);
	original_list.push_front(3);
	std::list<int>::iterator original_it = original_list.begin();
	ft::List<int>::iterator my_it = my_list.begin();
	while (original_it != original_list.end() || my_it != my_list.end())
	{
		ASSERT_EQ(*original_it, *my_it);
		++original_it;
		++my_it;
	}
	ASSERT_EQ(original_it == original_list.end(), my_it == my_list.end());

	std::cout << std::endl;
}

void test_listgroup_popback()
{
	std::cout << "list::pop_back" << std::endl;
	std::list<int>	original_list;
	ft::List<int>	my_list;

	my_list.push_back(1);
	my_list.push_back(2);
	my_list.push_back(3);
	my_list.pop_back();
	original_list.push_back(1);
	original_list.push_back(2);
	original_list.push_back(3);
	original_list.pop_back();
	std::list<int>::iterator original_it = original_list.begin();
	ft::List<int>::iterator my_it = my_list.begin();
	while (original_it != original_list.end() || my_it != my_list.end())
	{
		ASSERT_EQ(*original_it, *my_it);
		++original_it;
		++my_it;
	}
	ASSERT_EQ(original_it == original_list.end(), my_it == my_list.end());

	std::cout << std::endl;
}

void test_listgroup_popfront()
{
	std::cout << "list::pop_front" << std::endl;
	std::list<int>	original_list;
	ft::List<int>	my_list;

	my_list.push_back(1);
	my_list.push_back(2);
	my_list.push_back(3);
	my_list.pop_front();														//POP
	original_list.push_back(1);
	original_list.push_back(2);
	original_list.push_back(3);
	original_list.pop_front();
	std::list<int>::iterator original_it = original_list.begin();
	ft::List<int>::iterator my_it = my_list.begin();
	while (original_it != original_list.end() || my_it != my_list.end())
	{
		ASSERT_EQ(*original_it, *my_it);
		++original_it;
		++my_it;
	}
	my_list.pop_front();														//POP
	original_list.pop_front();
	original_it = original_list.begin();
	my_it = my_list.begin();
	while (original_it != original_list.end() || my_it != my_list.end())
	{
		ASSERT_EQ(*original_it, *my_it);
		++original_it;
		++my_it;
	}
	my_list.pop_front();														//POP
	original_list.pop_front();
	original_it = original_list.begin();
	my_it = my_list.begin();
	while (original_it != original_list.end() || my_it != my_list.end())
	{
		ASSERT_EQ(*original_it, *my_it);
		++original_it;
		++my_it;
	}
	std::cout << std::endl;
}

void test_listgroup_empty()
{
	std::cout << "list::empty" << std::endl;
	std::list<int>	original_list;
	ft::List<int>	my_list;

	ASSERT_EQ(original_list.empty(), my_list.empty());
	my_list.push_back(1);
	my_list.push_back(2);
	my_list.push_back(3);
	original_list.push_back(1);
	original_list.push_back(2);
	original_list.push_back(3);
	ASSERT_EQ(original_list.empty(), my_list.empty());
	my_list.pop_back();
	my_list.pop_back();
	my_list.pop_back();
	original_list.pop_back();
	original_list.pop_back();
	original_list.pop_back();
	ASSERT_EQ(original_list.empty(), my_list.empty());
	std::cout << std::endl;
}

void test_listgroup_size()
{
	std::cout << "list::size" << std::endl;
	std::list<int>	original_list;
	ft::List<int>	my_list;

	ASSERT_EQ(my_list.size(), original_list.size());
	my_list.push_back(1);
	original_list.push_back(1);
	ASSERT_EQ(my_list.size(), original_list.size());
	my_list.push_back(2);
	original_list.push_back(2);
	ASSERT_EQ(my_list.size(), original_list.size());
	my_list.push_back(3);
	original_list.push_back(3);
	ASSERT_EQ(my_list.size(), original_list.size());

	std::cout << std::endl;
}

int main()
{
	test_listgroup_iterator();
	test_listgroup_constiterator();
	test_listgroup_copyconstructor();
	test_listgroup_reverseiterator();
	test_listgroup_pushback();
	test_listgroup_pushfront();
	test_listgroup_popback();
	test_listgroup_popfront();
	test_listgroup_empty();
	test_listgroup_size();
	return (0);
}
