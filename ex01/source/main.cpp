#include "../include/iter.hpp"

template<typename T>
void	printElem(T const & elem)
{
	std::cout << elem << std::endl;
}

int	main(void)
{
	int 	intArray[] = {-11, 1, 0, 20000};
	char	charArray[] = "Bonjour";

	iter(intArray, 4, printElem);
	iter(charArray, 7, printElem);

	return (0);
}
