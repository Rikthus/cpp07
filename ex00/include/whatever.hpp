#ifndef WHATEVER_HPP
# define WHATEVER_HPP

# include <iostream>
# include <string>

template< typename T >
void	swap(T & x, T & y)
{
	T	tmp;
	tmp = x;
	x = y;
	y = tmp;
}

template< typename T >
T const	&	min(T const & a, T const & b)
{
	if (a < b)
		return (a);
	else
		return (b);
}

template< typename T >
T const &	max(T const & a, T const & b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

#endif