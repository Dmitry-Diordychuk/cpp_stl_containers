/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TestMiscellanea.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdustin <kdustin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 14:40:57 by kdustin           #+#    #+#             */
/*   Updated: 2021/05/21 23:00:36 by kdustin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_MISCELLANEA_HPP

#include <string>

class TestClass
{
private:
	int			_a;
	std::string	_b;
public:
	TestClass();
	TestClass(const TestClass& other);
	~TestClass();

	TestClass& operator=(TestClass& rhs);

	int getA();
	void setA(int a);
	std::string getB();
	void setB(std::string b);
};

bool single_digit(const int& value);

struct is_odd{
	bool operator() (const int& value);
};

bool same_integral_part(double first, double second);

struct is_near
{
	bool operator() (double first, double second);
};

bool mycomp(double first, double second);


bool descendingComp(const std::string first, const std::string second);

#endif // !TEST_MISCELLANEA_HPP
