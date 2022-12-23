#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>
# include <string>

template< typename T >
void	iter(T *tab, size_t tabSize, void (*fct)(T const &))
{
	for (size_t i = 0; i < tabSize; i++)
		fct(tab[i]);
}

#endif