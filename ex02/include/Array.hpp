#ifndef	ARRAY_HPP
# define ARRAY_HPP

# include <iostream>

template< typename T >
class	Array
{
	public:
		unsigned int	size(void)	const
		{
			return (this->mSize);
		}

		Array(unsigned int n) : mSize(n)
		{
			this->mArray = new T[this->mSize]
			for (unsigned int i = 0; i < this->mSize; i++)
				this->mArray[i] = 0; // 				NOT VERY SURE OF THIS
		}
		Array(Array const & src) : mSize(src.mSize)
		{
			this->mArray = new T[this->mSize];
			for (unsigned int i = 0; i < this->mSize; i++)
				this->mArray[i] = src.mArray[i];
		}
		Array(void) : mArray(NULL), mSize(0)
		{
			return ;
		}
		~Array(void)
		{
			if (this->mSize > 0)
				delete [] this->mArray;
		}

		Array &	operator=(Array const & rhs)
		{
			if (this != &rhs)
			{
				if (this->mSize > 0)
					delete [] this->mArray;
				this->mSize = rhs.mSize;
				this->mArray = new T[this->mSize];
				for (unsigned int i = 0; i < this->mSize; i++)
					this->mArray[i] = rhs.mArray[i];
			}
			return (*this);
		}

		T &	operator[](unsigned int index)
		{
			if (index >= this->mSize || index < 0)
				throw(IndexOutOfArrayRange());
		}

		class	IndexOutOfArrayRange : public std::exception
		{
			virtual const char	*what(void) const throw()
			{
				return ("Index used is out of array range");
			}
		};

	private:
		T				*mArray;
		unsigned int	mSize;
};

#endif