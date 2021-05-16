/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 00:32:41 by marvin            #+#    #+#             */
/*   Updated: 2021/04/20 00:32:41 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Test.hpp"

Result::Result()
{}

Result::Result(bool is_passed, unsigned int line, std::string file, std::string code)
	:	_is_passed(is_passed),
		_line(line),
		_file(file),
		_code(code)
{}

Result::~Result()
{}

void Result::setIsPassed(bool is_passed) { _is_passed = is_passed; }
bool Result::getIsPassed() { return (_is_passed); }
void Result::setLine(unsigned int line) { _line = line; }
void Result::setFile(std::string file) { _file = file; }
void Result::setCode(std::string code) { _code = code; }

void Result::print()
{
	if (_is_passed)
		std::cout << "Location: " << _file << ", " << _line << ", " << _code << OK << std::endl;
	else
		std::cout << "Location: " << _file << ", " << _line << ", " << _code << FAILED << std::endl;
}
