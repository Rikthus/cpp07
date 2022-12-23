#include "../include/Array.hpp"

#define MAX_VAL 750
int main(int, char**)
{

    std::cout << "STANDARD TESTS---------------------------------" << std::endl;

    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    //SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete [] mirror;

    std::cout << "-----------------------------------------------" << std::endl;
    std::cout << "COMPLEMENTARY TESTS----------------------------" << std::endl;

    Array<>					emptyArray;
    Array< char >			charged(5);
    Array< Array< float > >	inception(2);
	Array< float >			floatability(5);
	Array< float >			floatability2(6);

	floatability[0] = 0;
	floatability[1] = -4.1;
	floatability[2] = 100;
	floatability[3] = 3;
	floatability[4] = 9.992;


	floatability2[0] = 0;
	floatability2[1] = 0;
	floatability2[2] = 0;
	floatability2[3] = 0;
	floatability2[4] = 0;
	floatability2[5] = 0;

    try
    {
        emptyArray[0];
    }
    catch (std::exception & e)
    {
        std::cout << e.what() << std::endl;
    }

	for (unsigned int i = 0; i < charged.size(); i++)
		std::cout << "Elem: " << charged[i] << std::endl;

	std::cout << std::endl;
	std::cout << "Complex Array size:         " << inception.size() << std::endl;
	std::cout << "Complex Array element [0] size: " << inception[0].size() << std::endl;
	std::cout << "Complex Array element [1] size: " << inception[1].size() << std::endl;
	std::cout << std::endl;

	inception[0] = floatability;
	std::cout << "Complex Array element [0] size: " << inception[0].size() << std::endl;
	std::cout << std::endl;
	std::cout << inception[0][1] << std::endl;

	inception[0] = floatability2;
	std::cout << std::endl;
	std::cout << inception[0][1] << std::endl;




    std::cout << "-----------------------------------------------" << std::endl;
    return 0;
}
