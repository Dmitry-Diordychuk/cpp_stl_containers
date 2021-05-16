/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TestMiscellanea.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdustin <kdustin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 14:40:57 by kdustin           #+#    #+#             */
/*   Updated: 2021/05/16 14:40:58 by kdustin          ###   ########.fr       */
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

#endif // !TEST_MISCELLANEA_HPP
