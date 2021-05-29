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
	ASSERT_EQ(original_map.size(), my_map.size());

	o_it = copy_original_map.begin();
	m_it = copy_my_map.begin();
	for (;o_it != copy_original_map.end() || m_it != copy_my_map.end(); ++o_it, ++m_it)
	{
		ASSERT_EQ(o_it->first, m_it->first);
		ASSERT_EQ(o_it->second, m_it->second);
	}
	ASSERT_EQ(copy_original_map.size(), copy_my_map.size());

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
	ASSERT_EQ(original_map.size(), my_map.size());

	std::cout << std::endl;
}

void test_mapgroup_assignoperator()
{
	std::cout << "map::assign_operator" << std::endl;

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

	std::map<char, int> assign_original_map;
	ft::Map<char, int> assign_my_map;

	assign_original_map.insert(std::pair<char, int>('g', 123));
	assign_original_map.insert(std::pair<char, int>('x', 321));

	assign_my_map.insert(ft::Pair<char, int>('g', 123));
	assign_my_map.insert(ft::Pair<char, int>('x', 321));

	assign_original_map = original_map;
	assign_my_map = my_map;

	std::map<char, int>::const_iterator o_it = original_map.begin();
	ft::Map<char, int>::const_iterator m_it = my_map.begin();
	for (;o_it != original_map.end() || m_it != my_map.end(); ++o_it, ++m_it)
	{
		ASSERT_EQ(o_it->first, m_it->first);
		ASSERT_EQ(o_it->second, m_it->second);
	}

	o_it = assign_original_map.begin();
	m_it = assign_my_map.begin();
	for (;o_it != assign_original_map.end() || m_it != assign_my_map.end(); ++o_it, ++m_it)
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

void test_mapgroup_accessoperator()
{
	std::cout << "map::access_opretor" << std::endl;

	std::map<char,std::string> original_map;
	ft::Map<char,std::string> my_map;

	original_map['a'] = "an element";
	original_map['b'] = "another element";
	original_map['c'] = original_map['b'];

	my_map['a'] = "an element";
	my_map['b'] = "another element";
	my_map['c'] = my_map['b'];

	ASSERT_EQ(original_map['a'], my_map['a']);
	ASSERT_EQ(original_map['b'], my_map['b']);
	ASSERT_EQ(original_map['c'], my_map['c']);
	ASSERT_EQ(original_map['d'], my_map['d']);
	ASSERT_EQ(original_map.size(), my_map.size());

	std::cout << std::endl;
}

void test_mapgroup_insert()
{
	std::cout << "map::insert" << std::endl;

	std::map<char, int> original_map;
	ft::Map<char, int> my_map;

	std::pair<std::map<char, int>::iterator, bool> o_ins_it;
	ft::Pair<ft::Map<char, int>::iterator, bool> m_ins_it;

	o_ins_it = original_map.insert(std::pair<char, int>('u', 200));
	m_ins_it = my_map.insert(ft::Pair<char, int>('u', 200));
	ASSERT_EQ((*o_ins_it.first).first, (*m_ins_it.first).first);
	ASSERT_EQ((*o_ins_it.first).second, (*m_ins_it.first).second);
	ASSERT_EQ(o_ins_it.second, m_ins_it.second);
	o_ins_it = original_map.insert(std::pair<char, int>('r', 300));
	m_ins_it = my_map.insert(ft::Pair<char, int>('r', 300));
	ASSERT_EQ((*o_ins_it.first).first, (*m_ins_it.first).first);
	ASSERT_EQ((*o_ins_it.first).second, (*m_ins_it.first).second);
	ASSERT_EQ(o_ins_it.second, m_ins_it.second);
	o_ins_it = original_map.insert(std::pair<char, int>('r', 400));
	m_ins_it = my_map.insert(ft::Pair<char, int>('r', 400));
	ASSERT_EQ((*o_ins_it.first).first, (*m_ins_it.first).first);
	ASSERT_EQ((*o_ins_it.first).second, (*m_ins_it.first).second);
	ASSERT_EQ(o_ins_it.second, m_ins_it.second);
	o_ins_it = original_map.insert(std::pair<char, int>('a', 100));
	m_ins_it = my_map.insert(ft::Pair<char, int>('a', 100));
	ASSERT_EQ((*o_ins_it.first).first, (*m_ins_it.first).first);
	ASSERT_EQ((*o_ins_it.first).second, (*m_ins_it.first).second);
	ASSERT_EQ(o_ins_it.second, m_ins_it.second);
	o_ins_it = original_map.insert(std::pair<char, int>('b', 200));
	m_ins_it = my_map.insert(ft::Pair<char, int>('b', 200));
	ASSERT_EQ((*o_ins_it.first).first, (*m_ins_it.first).first);
	ASSERT_EQ((*o_ins_it.first).second, (*m_ins_it.first).second);
	ASSERT_EQ(o_ins_it.second, m_ins_it.second);
	o_ins_it = original_map.insert(std::pair<char, int>('z', 300));
	m_ins_it = my_map.insert(ft::Pair<char, int>('z', 300));
	ASSERT_EQ((*o_ins_it.first).first, (*m_ins_it.first).first);
	ASSERT_EQ((*o_ins_it.first).second, (*m_ins_it.first).second);
	ASSERT_EQ(o_ins_it.second, m_ins_it.second);
	o_ins_it = original_map.insert(std::pair<char, int>('c', 400));
	m_ins_it = my_map.insert(ft::Pair<char, int>('c', 400));
	ASSERT_EQ((*o_ins_it.first).first, (*m_ins_it.first).first);
	ASSERT_EQ((*o_ins_it.first).second, (*m_ins_it.first).second);
	ASSERT_EQ(o_ins_it.second, m_ins_it.second);
	o_ins_it = original_map.insert(std::pair<char, int>('f', 100));
	m_ins_it = my_map.insert(ft::Pair<char, int>('f', 100));
	ASSERT_EQ((*o_ins_it.first).first, (*m_ins_it.first).first);
	ASSERT_EQ((*o_ins_it.first).second, (*m_ins_it.first).second);
	ASSERT_EQ(o_ins_it.second, m_ins_it.second);

	std::map<char, int>::iterator o_it = original_map.begin();
	ft::Map<char, int>::iterator m_it = my_map.begin();
	for (;o_it != original_map.end() || m_it != my_map.end(); ++o_it, ++m_it)
	{
		ASSERT_EQ(o_it->first, m_it->first);
		ASSERT_EQ(o_it->second, m_it->second);
	}
	ASSERT_EQ(original_map.size(), my_map.size());

	std::cout << std::endl;
}

void test_mapgroup_positioninsert()
{
	std::cout << "map::position_insert" << std::endl;

	std::map<char, int> original_map;
	ft::Map<char, int> my_map;

	original_map['g'] = 1;
	original_map['h'] = 2;
	original_map['e'] = 3;

	my_map['g'] = 1;
	my_map['h'] = 2;
	my_map['e'] = 3;

	original_map.insert(original_map.begin(), std::pair<char, int>('a', 4));
	my_map.insert(my_map.begin(), ft::Pair<char, int>('a', 4));

	original_map.insert(original_map.begin(), std::pair<char, int>('z', 5));
	my_map.insert(my_map.begin(), ft::Pair<char, int>('z', 5));

	std::map<char, int>::iterator o_it = original_map.begin();
	ft::Map<char, int>::iterator m_it = my_map.begin();

	++o_it;
	++m_it;

	original_map.insert(o_it, std::pair<char, int>('b', 6));
	my_map.insert(m_it, ft::Pair<char, int>('b', 6));

	o_it = original_map.end();
	m_it = my_map.end();

	--o_it;
	--m_it;

	original_map.insert(o_it, std::pair<char, int>('k', 6));
	my_map.insert(m_it, ft::Pair<char, int>('k', 6));

	o_it = original_map.begin();
	m_it = my_map.begin();
	for (;o_it != original_map.end() || m_it != my_map.end(); ++o_it, ++m_it)
	{
		ASSERT_EQ(o_it->first, m_it->first);
		ASSERT_EQ(o_it->second, m_it->second);
	}
	ASSERT_EQ(original_map.size(), my_map.size());

	std::cout << std::endl;
}

void test_mapgroup_iteratorinsert()
{
	std::cout << "map::iterator_insert" << std::endl;

	std::pair<char, int> original_array[] = {std::pair<char, int>('a', 1), std::pair<char, int>('b', 2),
		std::pair<char, int>('c', 3), std::pair<char, int>('d', 4), std::pair<char, int>('e', 300)};
	ft::Pair<char, int> my_array[] = {ft::Pair<char, int>('a', 1), ft::Pair<char, int>('b', 2),
		ft::Pair<char, int>('c', 3), ft::Pair<char, int>('d', 4), ft::Pair<char, int>('e', 300)};

	std::map<char, int> original_map;
	ft::Map<char, int> my_map;

	original_map['g'] = 1;
	original_map['h'] = 2;
	original_map['e'] = 3;

	my_map['g'] = 1;
	my_map['h'] = 2;
	my_map['e'] = 3;

	original_map.insert(original_array, original_array + 5);
	my_map.insert(my_array, my_array + 5);

	std::map<char, int>::iterator o_it = original_map.begin();
	ft::Map<char, int>::iterator m_it = my_map.begin();
	for (;o_it != original_map.end() || m_it != my_map.end(); ++o_it, ++m_it)
	{
		ASSERT_EQ(o_it->first, m_it->first);
		ASSERT_EQ(o_it->second, m_it->second);
	}
	ASSERT_EQ(original_map.size(), my_map.size());

	std::cout << std::endl;
}

void test_mapgroup_erase()
{
	std::cout << "map::erase" << std::endl;

	std::map<char,int> original_map;
	ft::Map<char, int> my_map;

	original_map['a']=10;
	original_map['b']=20;
	original_map['c']=30;
	original_map['d']=40;
	original_map['e']=50;
	original_map['f']=60;

	my_map['a']=10;
	my_map['b']=20;
	my_map['c']=30;
	my_map['d']=40;
	my_map['e']=50;
	my_map['f']=60;

	std::map<char,int>::iterator o_it;
	ft::Map<char,int>::iterator m_it;

	for (int i = 0; i < 6; ++i)
	{
		o_it = original_map.begin();
		m_it = my_map.begin();
		// for (size_t j = 0; j < (my_map.size() - 1); ++j)
		// {
		// 	++o_it;
		// 	++m_it;
		// }
		original_map.erase(o_it);
		my_map.erase(m_it);

		o_it = original_map.begin();
		m_it = my_map.begin();
		for (;o_it != original_map.end() || m_it != my_map.end(); ++o_it, ++m_it)
		{
			ASSERT_EQ(o_it->first, m_it->first);
			ASSERT_EQ(o_it->second, m_it->second);
		}
		ASSERT_EQ(original_map.size(), my_map.size());
	}

	std::cout << std::endl;
}

void test_mapgroup_keyerase()
{
	std::cout << "map::key_erase" << std::endl;

	std::map<char,int> original_map;
	ft::Map<char, int> my_map;

	original_map['a']=10;
	original_map['b']=20;
	original_map['c']=30;
	original_map['d']=40;
	original_map['e']=50;
	original_map['f']=60;

	my_map['a']=10;
	my_map['b']=20;
	my_map['c']=30;
	my_map['d']=40;
	my_map['e']=50;
	my_map['f']=60;

	char ch = 'a';
	size_t o = original_map.erase(ch);
	size_t i = my_map.erase(ch);
	ASSERT_EQ(o, i);

	std::map<char,int>::iterator o_it = original_map.begin();
	ft::Map<char, int>::iterator m_it = my_map.begin();
	for (;o_it != original_map.end() || m_it != my_map.end(); ++o_it, ++m_it)
	{
		ASSERT_EQ(o_it->first, m_it->first);
		ASSERT_EQ(o_it->second, m_it->second);
	}
	ASSERT_EQ(original_map.size(), my_map.size());

	std::cout << std::endl;
}

void test_mapgroup_rangeerase()
{
	std::cout << "map::range_erase" << std::endl;

	std::map<char,int> original_map;
	ft::Map<char, int> my_map;

	original_map['a']=10;
	original_map['b']=20;
	original_map['c']=30;
	original_map['d']=40;
	original_map['e']=50;
	original_map['f']=60;

	my_map['a']=10;
	my_map['b']=20;
	my_map['c']=30;
	my_map['d']=40;
	my_map['e']=50;
	my_map['f']=60;

	std::map<char,int>::iterator o_it = original_map.begin();
	ft::Map<char,int>::iterator m_it = my_map.begin();
	std::map<char,int>::iterator o_eit = original_map.end();
	ft::Map<char,int>::iterator m_eit = my_map.end();

	o_it++;
	m_it++;

	o_eit--;
	m_eit--;

	original_map.erase(o_it, o_eit);
	my_map.erase(m_it, m_eit);

	o_it = original_map.begin();
	m_it = my_map.begin();
	for (;o_it != original_map.end() || m_it != my_map.end(); ++o_it, ++m_it)
	{
		ASSERT_EQ(o_it->first, m_it->first);
		ASSERT_EQ(o_it->second, m_it->second);
	}
	ASSERT_EQ(original_map.size(), my_map.size());

	std::cout << std::endl;
}

void test_mapgroup_swap()
{
	std::cout << "map::swap" << std::endl;

	std::map<char,int> original_foo, original_bar;
	ft::Map<char, int> my_foo, my_bar;

	original_foo['x']=100;
	original_foo['y']=200;
	my_foo['x']=100;
	my_foo['y']=200;

	original_bar['a']=11;
	original_bar['b']=22;
	original_bar['c']=33;
	my_bar['a']=11;
	my_bar['b']=22;
	my_bar['c']=33;

	original_foo.swap(original_bar);
	my_foo.swap(my_bar);

	std::map<char,int>::iterator o_it = original_foo.begin();
	ft::Map<char,int>::iterator m_it = my_foo.begin();
	for (;o_it != original_foo.end() || m_it != my_foo.end(); ++o_it, ++m_it)
	{
		ASSERT_EQ(o_it->first, m_it->first);
		ASSERT_EQ(o_it->second, m_it->second);
	}
	ASSERT_EQ(original_foo.size(), my_foo.size());

	o_it = original_bar.begin();
	m_it = my_bar.begin();
	for (;o_it != original_bar.end() || m_it != my_bar.end(); ++o_it, ++m_it)
	{
		ASSERT_EQ(o_it->first, m_it->first);
		ASSERT_EQ(o_it->second, m_it->second);
	}
	ASSERT_EQ(original_bar.size(), my_bar.size());

	std::cout << std::endl;
}

void test_mapgroup_keycomp()
{
	std::cout << "map::key_comp" << std::endl;

	std::map<char,int> original_map;
	ft::Map<char, int> my_map;

	std::map<char,int>::key_compare original_comp = original_map.key_comp();
	ft::Map<char,int>::key_compare my_comp = my_map.key_comp();

	original_map['a']=100;
	original_map['b']=200;
	original_map['c']=300;

	my_map['a']=100;
	my_map['b']=200;
	my_map['c']=300;


	char o_highest = original_map.rbegin()->first;     // key value of last element
	char m_highest = my_map.rbegin()->first;

	std::map<char,int>::iterator o_it = original_map.begin();
	ft::Map<char,int>::iterator m_it = my_map.begin();
	for (;; ++o_it, ++m_it)
	{
		ASSERT_EQ(o_it->first, m_it->first);
		ASSERT_EQ(o_it->second, m_it->second);
		if ( !original_comp((*o_it).first, o_highest) && !my_comp((*m_it).first, m_highest) )
			break ;
	}
	ASSERT_EQ(original_map.size(), my_map.size());

	std::cout << std::endl;
}

void test_mapgroup_valuecomp()
{
	std::cout << "map::value_comp" << std::endl;

	std::map<char,int> original_map;
	ft::Map<char, int> my_map;

	original_map['a']=100;
	original_map['b']=200;
	original_map['c']=300;

	my_map['a']=100;
	my_map['b']=200;
	my_map['c']=300;


	std::pair<char, int> o_highest = *original_map.rbegin();     // key value of last element
	ft::Pair<char, int> m_highest = *my_map.rbegin();

	std::map<char,int>::iterator o_it = original_map.begin();
	ft::Map<char,int>::iterator m_it = my_map.begin();
	for (;; ++o_it, ++m_it)
	{
		ASSERT_EQ(o_it->first, m_it->first);
		ASSERT_EQ(o_it->second, m_it->second);
		if ( !original_map.value_comp()(*o_it, o_highest) && !my_map.value_comp()(*m_it, m_highest) )
			break ;
	}
	ASSERT_EQ(original_map.size(), my_map.size());

	std::cout << std::endl;
}

void test_mapgroup_find()
{
	std::cout << "map::find" << std::endl;

	std::map<char,int> original_map;
	ft::Map<char, int> my_map;
	std::map<char,int>::iterator o_it;
	ft::Map<char, int>::iterator m_it;

	original_map['a']=50;
	original_map['b']=100;
	original_map['c']=150;
	original_map['d']=200;

	my_map['a']=50;
	my_map['b']=100;
	my_map['c']=150;
	my_map['d']=200;

	o_it = original_map.find('a');
	m_it = my_map.find('a');

	ASSERT_EQ(o_it->first, m_it->first);
	ASSERT_EQ(o_it->second, m_it->second);

	o_it = original_map.find('b');
	m_it = my_map.find('b');

	ASSERT_EQ(o_it->first, m_it->first);
	ASSERT_EQ(o_it->second, m_it->second);

	o_it = original_map.find('c');
	m_it = my_map.find('c');

	ASSERT_EQ(o_it->first, m_it->first);
	ASSERT_EQ(o_it->second, m_it->second);

	o_it = original_map.find('d');
	m_it = my_map.find('d');

	ASSERT_EQ(o_it->first, m_it->first);
	ASSERT_EQ(o_it->second, m_it->second);

	o_it = original_map.find('h');
	m_it = my_map.find('h');

	ASSERT_EQ(o_it == original_map.end(), m_it == my_map.end());

	std::cout << std::endl;
}

void test_mapgroup_count()
{
	std::cout << "map::count" << std::endl;

	std::map<char,int> original_map;
	ft::Map<char, int> my_map;
	char c;

	original_map ['a']=101;
	original_map ['c']=202;
	original_map ['f']=303;

	my_map ['a']=101;
	my_map ['c']=202;
	my_map ['f']=303;



	for (c='a'; c<'h'; c++)
	{
		ASSERT_EQ(original_map.count(c), my_map.count(c));
	}

	std::cout << std::endl;
}

void test_mapgroup_lowerboundupperbound()
{
	std::cout << "map::lower_bound, upper_bound" << std::endl;

	std::map<char,int> original_map;
	ft::Map<char, int> my_map;
	std::map<char,int>::iterator o_itlow, o_itup;
	ft::Map<char, int>::iterator m_itlow, m_itup;

	original_map['a']=20;
	original_map['c']=40;
	original_map['e']=60;
	original_map['h']=80;
	original_map['k']=100;

	my_map['a']=20;
	my_map['c']=40;
	my_map['e']=60;
	my_map['h']=80;
	my_map['k']=100;

	for (char c = 'a'; c <= 'z'; ++c)
	{
		o_itlow = original_map.lower_bound (c);
		o_itup = original_map.upper_bound (c);

		m_itlow = my_map.lower_bound (c);
		m_itup = my_map.upper_bound (c);

		if (o_itlow == original_map.end() && m_itlow == my_map.end())
		{
			ASSERT_TRUE(true);
		}
		else
		{
			ASSERT_EQ(o_itlow->first, m_itlow->first);
		}
		if (o_itup == original_map.end() && m_itup == my_map.end())
		{
			ASSERT_TRUE(true);
		}
		else
		{
			ASSERT_EQ(o_itup->first, m_itup->first);
		}
	}

	std::cout << std::endl;
}

int test_mapgroup()
{
	test_pairgroup();
	test_mapgroup_copyconstructor();
	test_mapgroup_rangeconstructor();
	test_mapgroup_assignoperator();
	test_mapgroup_reverseiterator();
	test_mapgroup_accessoperator();

	test_mapgroup_insert();
	test_mapgroup_positioninsert();
	test_mapgroup_iteratorinsert();
	test_mapgroup_erase();
	test_mapgroup_keyerase();
	test_mapgroup_rangeerase();
	test_mapgroup_swap();

	test_mapgroup_keycomp();
	test_mapgroup_valuecomp();

	test_mapgroup_find();
	test_mapgroup_count();
	test_mapgroup_lowerboundupperbound();
	return (0);
}
