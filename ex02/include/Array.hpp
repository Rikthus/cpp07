#ifndef	ARRAY_HPP
# define ARRAY_HPP

# include <iostream>

template< typename T = int > // IS THIS GOOD FOR DEFAULT BEHAVIOR ?
class	Array
{
	public:
		unsigned int	size(void)	const
		{
			return (this->mSize);
		}

		Array(unsigned int n) : mSize(n)
		{
			if (this->mSize > 0)
			{
				this->mArray = new T[this->mSize];
				for (unsigned int i = 0; i < this->mSize; i++)
					this->mArray[i] = 0; // 				NOT VERY SURE OF THIS
			}
			else
				this->mArray = NULL;
		}
		Array(Array const & src) : mSize(src.mSize)
		{
			if (this->mSize > 0)
			{
				this->mArray = new T[this->mSize];
				for (unsigned int i = 0; i < this->mSize; i++)
					this->mArray[i] = src.mArray[i];
			}
			else
				this->mArray = NULL;
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
				if (this->mSize > 0)
				{
					this->mArray = new T[this->mSize];
					for (unsigned int i = 0; i < this->mSize; i++)
						this->mArray[i] = rhs.mArray[i];
				}
				else
					this->mArray = NULL;
			}
			return (*this);
		}

		T &	operator[](unsigned int index)
		{
			if (index >= this->mSize || index < 0)  // DO I NEED TO CHECK NEGATIVE UNSIGNED INT ?
				throw(IndexOutOfArrayRange());
			return (this->mArray[index]);
		}

		T const &	operator[](unsigned int index) const
		{
			if (index >= this->mSize || index < 0)  // DO I NEED TO CHECK NEGATIVE UNSIGNED INT ?
				throw(IndexOutOfArrayRange());
			return (this->mArray[index]);
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