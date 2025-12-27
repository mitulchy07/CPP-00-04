#include "Fixed.hpp"
#include <iostream>
#include <cmath>

Fixed::Fixed(void) : _value(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int n) : _value(n << _fractionalBits)
{
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float f) : _value(roundf(f * (1 << _fractionalBits)))
{
	std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &src)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

Fixed	&Fixed::operator=(const Fixed &rhs)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &rhs)
		this->_value = rhs.getRawBits();
	return (*this);
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

int	Fixed::getRawBits(void) const
{
	return (this->_value);
}

void	Fixed::setRawBits(int const raw)
{
	this->_value = raw;
}

float	Fixed::toFloat(void) const
{
	return ((float)this->_value / (float)(1 << _fractionalBits));
}

int	Fixed::toInt(void) const
{
	return (this->_value >> _fractionalBits);
}

bool	Fixed::operator>(const Fixed &rhs) const
{
	return (this->_value > rhs._value);
}

bool	Fixed::operator<(const Fixed &rhs) const
{
	return (this->_value < rhs._value);
}

bool	Fixed::operator>=(const Fixed &rhs) const
{
	return (this->_value >= rhs._value);
}

bool	Fixed::operator<=(const Fixed &rhs) const
{
	return (this->_value <= rhs._value);
}

bool	Fixed::operator==(const Fixed &rhs) const
{
	return (this->_value == rhs._value);
}

bool	Fixed::operator!=(const Fixed &rhs) const
{
	return (this->_value != rhs._value);
}

Fixed	Fixed::operator+(const Fixed &rhs) const
{
	Fixed	result;

	result.setRawBits(this->_value + rhs._value);
	return (result);
}

Fixed	Fixed::operator-(const Fixed &rhs) const
{
	Fixed	result;

	result.setRawBits(this->_value - rhs._value);
	return (result);
}

Fixed	Fixed::operator*(const Fixed &rhs) const
{
	Fixed	result;

	result.setRawBits((this->_value * rhs._value) >> _fractionalBits);
	return (result);
}

Fixed	Fixed::operator/(const Fixed &rhs) const
{
	Fixed	result;

	result.setRawBits((this->_value << _fractionalBits) / rhs._value);
	return (result);
}

Fixed	&Fixed::operator++(void)
{
	this->_value++;
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed	tmp(*this);

	this->_value++;
	return (tmp);
}

Fixed	&Fixed::operator--(void)
{
	this->_value--;
	return (*this);
}

Fixed	Fixed::operator--(int)
{
	Fixed	tmp(*this);

	this->_value--;
	return (tmp);
}

Fixed	&Fixed::min(Fixed &a, Fixed &b)
{
	if (a._value < b._value)
		return (a);
	return (b);
}

const Fixed	&Fixed::min(const Fixed &a, const Fixed &b)
{
	if (a._value < b._value)
		return (a);
	return (b);
}

Fixed	&Fixed::max(Fixed &a, Fixed &b)
{
	if (a._value > b._value)
		return (a);
	return (b);
}

const Fixed	&Fixed::max(const Fixed &a, const Fixed &b)
{
	if (a._value > b._value)
		return (a);
	return (b);
}

std::ostream	&operator<<(std::ostream &o, const Fixed &rhs)
{
	o << rhs.toFloat();
	return (o);
}
