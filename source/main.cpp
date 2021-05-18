#include "Test.hpp"
#include "List.hpp"
#include "TestMiscellanea.hpp"
#include <list>
#include <vector>
#include <map>
#include <stack>
#include <queue>
#include <iostream>

void test_typetrairsgroup_isintegral()
{
	std::cout << "type_traits::is_integral" << std::endl;
	ASSERT_EQ(ft::is_integral<int>::value, true);
	ASSERT_EQ(ft::is_integral<ft::List<int>::iterator>::value, false);
}

void test_listgroup_nconstructor()
{
	std::cout << "list::nconstructor" << std::endl;
	std::list<int>	original_list(10, 42);
	ft::List<int>	my_list(10, 42);

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

void test_listgroup_iterconstructor()
{
	std::cout << "list::iterconstructor" << std::endl;

	int array[] = {1, 2, 3, 4, 5};

	std::list<int>	original_list(array, array + sizeof(array) / sizeof(int));
	ft::List<int>	my_list(array, array + sizeof(array) / sizeof(int));

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
	ASSERT_EQ(original_it == original_copy.end(), my_it == my_copy.end());

	std::cout << std::endl;
}

void test_listgroup_assignmentoperator()
{
	std::cout << "list::assignment_operator" << std::endl;
	std::list<int>	original_list;
	ft::List<int>	my_list;

	my_list.push_back(1);
	my_list.push_back(2);
	my_list.push_back(3);
	original_list.push_back(1);
	original_list.push_back(2);
	original_list.push_back(3);

	std::list<int> second_original_list;
	ft::List<int> second_my_list;

	second_my_list.push_back(4);
	second_my_list.push_back(5);
	second_my_list.push_back(6);
	second_original_list.push_back(4);
	second_original_list.push_back(5);
	second_original_list.push_back(6);

	second_original_list = original_list;
	second_my_list = my_list;

	std::list<int>::iterator original_it = second_original_list.begin();
	ft::List<int>::iterator my_it = second_my_list.begin();
	while (original_it != second_original_list.end() || my_it != second_my_list.end())
	{
		ASSERT_EQ(*original_it, *my_it);
		++original_it;
		++my_it;
	}
	ASSERT_EQ(original_it == second_original_list.end(), my_it == second_my_list.end());

	std::cout << std::endl;
}

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
		//(*original_it)++;					compilation error
		//(*my_it)++;						compilation error
		ASSERT_EQ(*original_it, *my_it);
		original_it++;
		my_it++;
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

void test_listgroup_front()
{
	std::cout << "list::front" << std::endl;
	std::list<int>	original_list;
	ft::List<int>	my_list;

	my_list.push_back(1);
	my_list.push_back(2);
	my_list.push_back(3);
	original_list.push_back(1);
	original_list.push_back(2);
	original_list.push_back(3);

	ASSERT_EQ(my_list.front(), original_list.front());
	my_list.pop_front();
	original_list.pop_front();
	ASSERT_EQ(my_list.front(), original_list.front());
	my_list.pop_front();
	original_list.pop_front();
	ASSERT_EQ(my_list.front(), original_list.front());
	my_list.pop_front();
	original_list.pop_front();

	my_list.push_back(1);
	my_list.push_back(2);
	my_list.push_back(3);
	original_list.push_back(1);
	original_list.push_back(2);
	original_list.push_back(3);

	const std::list<int>	const_original_list(original_list);
	const ft::List<int>		const_my_list(my_list);

	ASSERT_EQ(const_my_list.front(), const_original_list.front());

	std::cout << std::endl;
}

void test_listgroup_back()
{
	std::cout << "list::back" << std::endl;
	std::list<int>	original_list;
	ft::List<int>	my_list;

	my_list.push_back(1);
	my_list.push_back(2);
	my_list.push_back(3);
	original_list.push_back(1);
	original_list.push_back(2);
	original_list.push_back(3);

	ASSERT_EQ(my_list.back(), original_list.back());
	my_list.pop_back();
	original_list.pop_back();
	ASSERT_EQ(my_list.back(), original_list.back());
	my_list.pop_back();
	original_list.pop_back();
	ASSERT_EQ(my_list.back(), original_list.back());
	my_list.pop_back();
	original_list.pop_back();

	my_list.push_back(1);
	my_list.push_back(2);
	my_list.push_back(3);
	original_list.push_back(1);
	original_list.push_back(2);
	original_list.push_back(3);

	const std::list<int>	const_original_list(original_list);
	const ft::List<int>		const_my_list(my_list);

	ASSERT_EQ(const_my_list.back(), const_original_list.back());

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

void test_listgroup_insert()
{
	std::cout << "list::insert" << std::endl;

	std::list<int>				original_list;
	ft::List<int>				my_list;
	std::list<int>::iterator	o_it;
	ft::List<int>::iterator		m_it;

	o_it = original_list.insert(original_list.end(), 1);
	m_it = my_list.insert(my_list.end(), 1);
	ASSERT_EQ(*o_it, *m_it);

	o_it = original_list.insert(original_list.end(), 2);
	m_it = my_list.insert(my_list.end(), 2);
	ASSERT_EQ(*o_it, *m_it);

	o_it = original_list.insert(original_list.end(), 3);
	m_it = my_list.insert(my_list.end(), 3);
	ASSERT_EQ(*o_it, *m_it);

	o_it = original_list.begin();
	m_it = my_list.begin();
	while (o_it != original_list.end() || m_it != my_list.end())
	{
		ASSERT_EQ(*o_it, *m_it);
		++o_it;
		++m_it;
	}

	original_list.clear();
	my_list.clear();

	o_it = original_list.insert(original_list.begin(), 1);
	m_it = my_list.insert(my_list.begin(), 1);
	ASSERT_EQ(*o_it, *m_it);

	o_it = original_list.insert(original_list.begin(), 2);
	m_it = my_list.insert(my_list.begin(), 2);
	ASSERT_EQ(*o_it, *m_it);

	o_it = original_list.insert(original_list.begin(), 3);
	m_it = my_list.insert(my_list.begin(), 3);
	ASSERT_EQ(*o_it, *m_it);

	o_it = original_list.begin();
	m_it = my_list.begin();
	while (o_it != original_list.end() || m_it != my_list.end())
	{
		ASSERT_EQ(*o_it, *m_it);
		++o_it;
		++m_it;
	}

	o_it = original_list.begin();
	m_it = my_list.begin();
	o_it++;
	m_it++;

	original_list.insert(o_it, 4);
	my_list.insert(m_it, 4);

	o_it = original_list.begin();
	m_it = my_list.begin();
	while (o_it != original_list.end() || m_it != my_list.end())
	{
		ASSERT_EQ(*o_it, *m_it);
		++o_it;
		++m_it;
	}

	o_it = original_list.begin();
	m_it = my_list.begin();
	o_it++;
	m_it++;
	o_it++;
	m_it++;

	original_list.insert(o_it, 3, 4);
	my_list.insert(m_it, 3, 4);

	o_it = original_list.begin();
	m_it = my_list.begin();
	while (o_it != original_list.end() || m_it != my_list.end())
	{
		ASSERT_EQ(*o_it, *m_it);
		++o_it;
		++m_it;
	}

	int n[] = {5, 6, 7, 8, 9};

	o_it = original_list.begin();
	m_it = my_list.begin();
	++o_it;
	++m_it;

	original_list.insert(o_it, n, n + 3);
	my_list.insert(m_it, n, n + 3);

	o_it = original_list.begin();
	m_it = my_list.begin();
	while (o_it != original_list.end() || m_it != my_list.end())
	{
		ASSERT_EQ(*o_it, *m_it);
		++o_it;
		++m_it;
	}

	std::cout << std::endl;
}

void test_listgroup_erase()
{
	std::cout << "list::insert" << std::endl;

	std::list<int>				original_list;
	ft::List<int>				my_list;
	std::list<int>::iterator	o_it;
	ft::List<int>::iterator		m_it;

	original_list.push_back(1);
	original_list.push_back(2);
	original_list.push_back(3);
	my_list.push_back(1);
	my_list.push_back(2);
	my_list.push_back(3);

	o_it = original_list.begin();
	++o_it;
	m_it = my_list.begin();
	++m_it;

	original_list.erase(o_it);
	my_list.erase(m_it);

	o_it = original_list.begin();
	m_it = my_list.begin();
	while (o_it != original_list.end() || m_it != my_list.end())
	{
		ASSERT_EQ(*o_it, *m_it);
		++o_it;
		++m_it;
	}

	original_list.erase(original_list.begin());
	my_list.erase(my_list.begin());

	o_it = original_list.begin();
	m_it = my_list.begin();
	while (o_it != original_list.end() || m_it != my_list.end())
	{
		ASSERT_EQ(*o_it, *m_it);
		++o_it;
		++m_it;
	}

	original_list.erase(original_list.begin());
	my_list.erase(my_list.begin());

	ASSERT_EQ(original_list.size(), my_list.size());
	ASSERT_TRUE(original_list.size() == 0);

	original_list.push_back(1);
	original_list.push_back(2);
	original_list.push_back(3);
	original_list.push_back(4);
	my_list.push_back(1);
	my_list.push_back(2);
	my_list.push_back(3);
	my_list.push_back(4);

	original_list.erase(++original_list.begin(), --original_list.end());
	my_list.erase(++my_list.begin(), --my_list.end());

	o_it = original_list.begin();
	m_it = my_list.begin();
	while (o_it != original_list.end() || m_it != my_list.end())
	{
		ASSERT_EQ(*o_it, *m_it);
		++o_it;
		++m_it;
	}

	original_list.erase(original_list.begin(), original_list.end());
	my_list.erase(my_list.begin(), my_list.end());

	ASSERT_EQ(original_list.size(), my_list.size());
	ASSERT_TRUE(original_list.size() == 0);

	std::cout << std::endl;
}

void test_listgroup_swap()
{
	std::cout << "list::swap" << std::endl;

	std::list<int> original_first (3,100);
	std::list<int> original_second (5,200);
	ft::List<int> my_first (3, 100);
	ft::List<int> my_second (5, 200);

	original_first.swap(original_second);
	my_first.swap(my_second);

	std::list<int>::iterator o_it = original_first.begin();
	ft::List<int>::iterator m_it = my_first.begin();
	while (o_it != original_first.end() || m_it != my_first.end())
	{
		ASSERT_EQ(*o_it, *m_it);
		++o_it;
		++m_it;
	}

	o_it = original_second.begin();
	m_it = my_second.begin();
	while (o_it != original_second.end() || m_it != my_second.end())
	{
		ASSERT_EQ(*o_it, *m_it);
		++o_it;
		++m_it;
	}

	std::cout << std::endl;
}

void test_listgroup_resize()
{
	std::cout << "list::resize" << std::endl;

	int n[] = {1, 2, 3};
	std::list<int> original_list(n, n + 3);
	ft::List<int> my_list(n, n + 3);

	original_list.resize(5);
	my_list.resize(5);

	std::list<int>::iterator o_it = original_list.begin();
	ft::List<int>::iterator m_it = my_list.begin();
	while (o_it != original_list.end() || m_it != my_list.end())
	{
		ASSERT_EQ(*o_it, *m_it);
		++o_it;
		++m_it;
	}

	original_list.resize(2);
	my_list.resize(2);

	o_it = original_list.begin();
	m_it = my_list.begin();
	while (o_it != original_list.end() || m_it != my_list.end())
	{
		ASSERT_EQ(*o_it, *m_it);
		++o_it;
		++m_it;
	}

	std::cout << std::endl;
}

int main()
{
	test_typetrairsgroup_isintegral();

	test_listgroup_nconstructor();
	test_listgroup_iterconstructor();
	test_listgroup_copyconstructor();
	test_listgroup_assignmentoperator();

	test_listgroup_iterator();
	test_listgroup_constiterator();
	test_listgroup_reverseiterator();

	test_listgroup_empty();
	test_listgroup_size();

	test_listgroup_front();
	test_listgroup_back();

	test_listgroup_pushback();
	test_listgroup_pushfront();
	test_listgroup_popback();
	test_listgroup_popfront();
	test_listgroup_insert();
	test_listgroup_erase();
	test_listgroup_swap();
	test_listgroup_resize();

	return (0);
}
