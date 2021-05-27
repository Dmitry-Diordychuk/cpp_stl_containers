#include "TestMiscellanea.hpp"

void test_pairgroup()
{
	std::cout << "pair" << std::endl;

	std::pair<std::string, double> original_pair1;
	ft::Pair<std::string, double> my_pair1;

	ASSERT_EQ(original_pair1.first, my_pair1.first);
	ASSERT_EQ(original_pair1.second, my_pair1.second);

	std::pair<std::string, double> original_pair2("tomatoes", 2.30);
	ft::Pair<std::string, double> my_pair2("tomatoes", 2.30);

	ASSERT_EQ(original_pair2.first, my_pair2.first);
	ASSERT_EQ(original_pair2.second, my_pair2.second);

	std::pair<std::string, double> original_pair_copy(original_pair2);
	ft::Pair<std::string, double> my_pair_copy(my_pair2);

	ASSERT_EQ(original_pair_copy.first, my_pair_copy.first);
	ASSERT_EQ(original_pair_copy.second, my_pair_copy.second);

	original_pair2.first = "shoes";
	original_pair2.second = 39.90;
	my_pair2.first = "shoes";
	my_pair2.second = 39.90;

	ASSERT_EQ(original_pair2.first, my_pair2.first);
	ASSERT_EQ(original_pair2.second, my_pair2.second);

	original_pair_copy = original_pair2;
	my_pair_copy = my_pair2;

	ASSERT_EQ(original_pair_copy.first, my_pair_copy.first);
	ASSERT_EQ(original_pair_copy.second, my_pair_copy.second);

	std::pair<std::string, double> original_pair3("cake", 4.50);
	ft::Pair<std::string, double> my_pair3("cake", 4.50);

	ASSERT_EQ(original_pair_copy == original_pair3, my_pair_copy == my_pair3);
	ASSERT_EQ(original_pair_copy != original_pair3, my_pair_copy != my_pair3);
	ASSERT_EQ(original_pair_copy > original_pair3, my_pair_copy > my_pair3);
	ASSERT_EQ(original_pair_copy >= original_pair3, my_pair_copy >= my_pair3);
	ASSERT_EQ(original_pair_copy < original_pair3, my_pair_copy < my_pair3);
	ASSERT_EQ(original_pair_copy <= original_pair3, my_pair_copy <= my_pair3);

	ft::Pair<char, int> original('c', 400);
	std::pair<char, int> my('c', 400);
	const ft::Pair<char, int> const_original('c', 400);
	const std::pair<char, int> const_my('c', 400);

	ASSERT_EQ(original == const_original, my == const_my);
	ASSERT_EQ(original != const_original, my != const_my);
	ASSERT_EQ(original > const_original, my > const_my);
	ASSERT_EQ(original < const_original, my < const_my);

	std::cout << std::endl;
}

void test_mapgroup_copyconstructor()
{
	std::cout << "map::copy_constructor" << std::endl;

	std::map<char, int> original_map;
	ft::Map<char, int> my_map;

	original_map.insert(std::pair<char, int>('u', 200));
	original_map.insert(std::pair<char, int>('r', 300));
	original_map.insert(std::pair<char, int>('r', 400));
	original_map.insert(std::pair<char, int>('a', 100));
	original_map.insert(std::pair<char, int>('b', 200));
	original_map.insert(std::pair<char, int>('z', 300));
	original_map.insert(std::pair<char, int>('c', 400));
	original_map.insert(std::pair<char, int>('f', 100));

	my_map.insert(ft::Pair<char, int>('u', 200));
	my_map.insert(ft::Pair<char, int>('r', 300));
	my_map.insert(ft::Pair<char, int>('r', 400));
	my_map.insert(ft::Pair<char, int>('a', 100));
	my_map.insert(ft::Pair<char, int>('b', 200));
	my_map.insert(ft::Pair<char, int>('z', 300));
	my_map.insert(ft::Pair<char, int>('c', 400));
	my_map.insert(ft::Pair<char, int>('f', 100));

	std::map<char, int> copy_original_map(original_map);
	ft::Map<char, int> copy_my_map(my_map);

	std::map<char, int>::const_iterator o_it = original_map.begin();
	ft::Map<char, int>::const_iterator m_it = my_map.begin();
	for (;o_it != original_map.end() || m_it != my_map.end(); ++o_it, ++m_it)
	{
		ASSERT_EQ(o_it->first, m_it->first);
		ASSERT_EQ(o_it->second, m_it->second);
	}

	o_it = copy_original_map.begin();
	m_it = copy_my_map.begin();
	for (;o_it != copy_original_map.end() || m_it != copy_my_map.end(); ++o_it, ++m_it)
	{
		ASSERT_EQ(o_it->first, m_it->first);
		ASSERT_EQ(o_it->second, m_it->second);
	}

	std::cout << std::endl;
}

void test_mapgroup_rangeconstructor()
{
	std::cout << "map::range_constructor" << std::endl;

	std::pair<int, int> original_array[] = {std::pair<int, int>(3, 100), std::pair<int, int>(6, 200), std::pair<int, int>(8, 300),
		std::pair<int, int>(7, 300), std::pair<int, int>(1, 600), std::pair<int, int>(12, 300), std::pair<int, int>(10, 300)};

	ft::Pair<int, int> my_array[] = {ft::Pair<int, int>(3, 100), ft::Pair<int, int>(6, 200), ft::Pair<int, int>(8, 300),
		ft::Pair<int, int>(7, 300), ft::Pair<int, int>(1, 600), ft::Pair<int, int>(12, 300), ft::Pair<int, int>(10, 300)};

	std::map<int, int> original_map(original_array + 1, original_array + 6);
	ft::Map<int, int> my_map(my_array + 1, my_array + 6);

	std::map<int, int>::const_iterator o_it = original_map.begin();
	ft::Map<int, int>::const_iterator m_it = my_map.begin();
	for (;o_it != original_map.end() || m_it != my_map.end(); ++o_it, ++m_it)
	{
		ASSERT_EQ(o_it->first, m_it->first);
		ASSERT_EQ(o_it->second, m_it->second);
	}

	std::cout << std::endl;
}

void test_mapgroup_constiterator()
{
	std::cout << "map::const_iterator" << std::endl;

	std::map<char, int> original_map;
	ft::Map<char, int> my_map;

	original_map.insert(std::pair<char, int>('u', 200));
	original_map.insert(std::pair<char, int>('r', 300));
	original_map.insert(std::pair<char, int>('r', 400));
	original_map.insert(std::pair<char, int>('a', 100));
	original_map.insert(std::pair<char, int>('b', 200));
	original_map.insert(std::pair<char, int>('z', 300));
	original_map.insert(std::pair<char, int>('c', 400));
	original_map.insert(std::pair<char, int>('f', 100));

	my_map.insert(ft::Pair<char, int>('u', 200));
	my_map.insert(ft::Pair<char, int>('r', 300));
	my_map.insert(ft::Pair<char, int>('r', 400));
	my_map.insert(ft::Pair<char, int>('a', 100));
	my_map.insert(ft::Pair<char, int>('b', 200));
	my_map.insert(ft::Pair<char, int>('z', 300));
	my_map.insert(ft::Pair<char, int>('c', 400));
	my_map.insert(ft::Pair<char, int>('f', 100));

	std::map<char, int>::const_iterator o_it = original_map.begin();
	ft::Map<char, int>::const_iterator m_it = my_map.begin();
	for (;o_it != original_map.end() || m_it != my_map.end(); ++o_it, ++m_it)
	{
		ASSERT_EQ(o_it->first, m_it->first);
		ASSERT_EQ(o_it->second, m_it->second);
	}

	std::cout << std::endl;
}

void test_mapgroup_reverseiterator()
{
	std::cout << "map::reverse_iterator" << std::endl;

	std::map<char, int> original_map;
	ft::Map<char, int> my_map;

	original_map.insert(std::pair<char, int>('u', 200));
	original_map.insert(std::pair<char, int>('r', 300));
	original_map.insert(std::pair<char, int>('r', 400));
	original_map.insert(std::pair<char, int>('a', 100));
	original_map.insert(std::pair<char, int>('b', 200));
	original_map.insert(std::pair<char, int>('z', 300));
	original_map.insert(std::pair<char, int>('c', 400));
	original_map.insert(std::pair<char, int>('f', 100));

	my_map.insert(ft::Pair<char, int>('u', 200));
	my_map.insert(ft::Pair<char, int>('r', 300));
	my_map.insert(ft::Pair<char, int>('r', 400));
	my_map.insert(ft::Pair<char, int>('a', 100));
	my_map.insert(ft::Pair<char, int>('b', 200));
	my_map.insert(ft::Pair<char, int>('z', 300));
	my_map.insert(ft::Pair<char, int>('c', 400));
	my_map.insert(ft::Pair<char, int>('f', 100));

	std::map<char, int>::reverse_iterator o_it = original_map.rbegin();
	ft::Map<char, int>::reverse_iterator m_it = my_map.rbegin();
	for (;o_it != original_map.rend() || m_it != my_map.rend(); ++o_it, ++m_it)
	{
		ASSERT_EQ(o_it->first, m_it->first);
		ASSERT_EQ(o_it->second, m_it->second);
	}

	std::map<char, int>::const_reverse_iterator co_it = original_map.rbegin();
	ft::Map<char, int>::const_reverse_iterator cm_it = my_map.rbegin();
	for (;co_it != original_map.rend() || cm_it != my_map.rend(); ++co_it, ++cm_it)
	{
		ASSERT_EQ(co_it->first, cm_it->first);
		ASSERT_EQ(co_it->second, cm_it->second);
	}

	std::cout << std::endl;
}

void test_mapgroup_insert()
{
	std::cout << "map::insert" << std::endl;

	std::map<char, int> original_map;
	ft::Map<char, int> my_map;

	original_map.insert(std::pair<char, int>('u', 200));
	original_map.insert(std::pair<char, int>('r', 300));
	original_map.insert(std::pair<char, int>('r', 400));
	original_map.insert(std::pair<char, int>('a', 100));
	original_map.insert(std::pair<char, int>('b', 200));
	original_map.insert(std::pair<char, int>('z', 300));
	original_map.insert(std::pair<char, int>('c', 400));
	original_map.insert(std::pair<char, int>('f', 100));

	my_map.insert(ft::Pair<char, int>('u', 200));
	my_map.insert(ft::Pair<char, int>('r', 300));
	my_map.insert(ft::Pair<char, int>('r', 400));
	my_map.insert(ft::Pair<char, int>('a', 100));
	my_map.insert(ft::Pair<char, int>('b', 200));
	my_map.insert(ft::Pair<char, int>('z', 300));
	my_map.insert(ft::Pair<char, int>('c', 400));
	my_map.insert(ft::Pair<char, int>('f', 100));

	std::map<char, int>::iterator o_it = original_map.begin();
	ft::Map<char, int>::iterator m_it = my_map.begin();
	for (;o_it != original_map.end() || m_it != my_map.end(); ++o_it, ++m_it)
	{
		ASSERT_EQ(o_it->first, m_it->first);
		ASSERT_EQ(o_it->second, m_it->second);
	}

	std::cout << std::endl;
}

int test_mapgroup()
{
	test_pairgroup();
	test_mapgroup_copyconstructor();
	test_mapgroup_rangeconstructor();
	test_mapgroup_reverseiterator();
	test_mapgroup_insert();
	return (0);
}
