/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_iterator.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jandre <ajuln@hotmail.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 12:37:52 by jandre            #+#    #+#             */
/*   Updated: 2022/03/21 18:31:28 by jandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_ITERATOR
# define VECTOR_ITERATOR

namespace ft
{
    template <class T>
    class vector_iterator
    {
        public:
        //Typedef to simplify the usage of the T class
            typedef T value_type;
            typedef T& reference;
			typedef T* pointer;
        
        protected:
        //pointer towards the wanted value
            pointer _ptr;
        
        public:
        //Constructors && destructors
            vector_iterator(void)
            {
                return ;
            };
            vector_iterator(const vector_iterator &other)
            {
                *this = other;
                return ;
            };
            vector_iterator(pointer ptr) : _ptr(ptr)
            {
                return ;
            };
            ~vector_iterator(void)
			{
                return ;
            };

        //Operator overloads
            vector_iterator &operator=(const vector_iterator &other)
            {
                if (*this != other)
                    this->_ptr = other._ptr;
                return (*this);
            };

        //increment & decrement before and after the it
            vector_iterator &operator++(void)
            {
                this->_ptr++;
                return (*this);
            };
            vector_iterator &operator--(void)
            {
                this->_ptr--;
                return (*this);
            };
            vector_iterator operator++(int)
			{
				vector_iterator tmp(*this);
				operator++();
				return (tmp);
			};
			vector_iterator operator--(int)
			{
				vector_iterator tmp(*this);
				operator--();
				return (tmp);
			};

        //boolean operators
            bool operator==(const vector_iterator &other) const
			{
				return (_ptr == other._ptr);
			};
			bool operator!=(const vector_iterator &other) const
			{
				return (_ptr != other._ptr);
			};
			bool operator>(const vector_iterator &other) const
			{
				return (_ptr > other._ptr);
			};
			bool operator>=(const vector_iterator &other) const
			{
				return (_ptr >= other._ptr);
			};
			bool operator<(const vector_iterator &other) const
			{
				return (_ptr < other._ptr);
			};
			bool operator<=(const vector_iterator &other) const
			{
				return (_ptr <= other._ptr);
			};
    
        //reference and dereference
            reference operator*(void) const
			{
				return (*this->_ptr);
			};
			pointer operator->(void)
			{
				return (this->_ptr);
			};

        //Basic arithmetic operations
            vector_iterator operator+(int n) const
			{
				vector_iterator tmp(*this);
				tmp += n;
				return (tmp);
			};
			vector_iterator operator-(int n) const
			{
				vector_iterator tmp(*this);
				tmp -= n;
				return (tmp);
			};
			vector_iterator &operator+=(int n)
			{
				while (n < 0)
				{
					operator--();
					n++;
				}
				while (n > 0)
				{
					operator++();
					n--;
				}
				return (*this);
			};
			vector_iterator &operator-=(int n)
			{
				while (n > 0)
				{
					operator--();
					n--;
				}
				while (n < 0)
				{
					operator++();
					n++;
				}
				return (*this);
			};

        //brackets operators
            value_type &operator[](int n) const
			{
				return (*(*this + n));
			};
    };

    template <class T>
    class reverse_vector_iterator : public vector_iterator<T>
    {
        public:
        //Typedef to simplify the usage of the T class
            typedef T value_type;
            typedef T& reference;
			typedef T* pointer;

        //Constructors && destructors
            reverse_vector_iterator(void)
            {
                return ;
            };
            reverse_vector_iterator(const reverse_vector_iterator &other)
            {
                *this = other;
                return ;
            };
            reverse_vector_iterator(pointer ptr)
            {
				this->_ptr = ptr;
                return ;
            };
            ~reverse_vector_iterator(void)
			{
                return ;
            };

        //Operator overloads
            reverse_vector_iterator &operator=(const reverse_vector_iterator &other)
            {
                if (*this != other)
                    this->_ptr = other._ptr;
                return (*this);
            };

        //increment & decrement before and after the it
            reverse_vector_iterator &operator++(void)
            {
                this->_ptr++;
                return (*this);
            };
            reverse_vector_iterator &operator--(void)
            {
                this->_ptr--;
                return (*this);
            };
            reverse_vector_iterator operator++(int)
			{
				reverse_vector_iterator tmp(*this);
				operator++();
				return (tmp);
			};
			reverse_vector_iterator operator--(int)
			{
				reverse_vector_iterator tmp(*this);
				operator--();
				return (tmp);
			};

        //boolean operators
            bool operator==(const reverse_vector_iterator &other) const
			{
				return (this->_ptr == other._ptr);
			};
			bool operator!=(const reverse_vector_iterator &other) const
			{
				return (this->_ptr != other._ptr);
			};
			bool operator>(const reverse_vector_iterator &other) const
			{
				return (this->_ptr > other._ptr);
			};
			bool operator>=(const reverse_vector_iterator &other) const
			{
				return (this->_ptr >= other._ptr);
			};
			bool operator<(const reverse_vector_iterator &other) const
			{
				return (this->_ptr < other._ptr);
			};
			bool operator<=(const reverse_vector_iterator &other) const
			{
				return (this->_ptr <= other._ptr);
			};

        //reference and dereference
            reference operator*(void) const
			{
				return (this->_ptr);
			};
			pointer operator->(void)
			{
				return (this->_ptr);
			};

        //Basic arithmetic operations
            reverse_vector_iterator operator+(int n) const
			{
				reverse_vector_iterator tmp(*this);
				tmp += n;
				return (tmp);
			};
			reverse_vector_iterator operator-(int n) const
			{
				reverse_vector_iterator tmp(*this);
				tmp -= n;
				return (tmp);
			};
			reverse_vector_iterator &operator+=(int n)
			{
				while (n < 0)
				{
					operator++();
					n++;
				}
				while (n > 0)
				{
					operator--();
					n--;
				}
				return (*this);
			};
			reverse_vector_iterator &operator-=(int n)
			{
				while (n > 0)
				{
					operator++();
					n--;
				}
				while (n < 0)
				{
					operator--();
					n++;
				}
				return (*this);
			};

        //brackets operators
            value_type &operator[](int n) const
			{
				return (*(*this - n));
			}
    };

	template <class T>
	class const_vector_iterator : public vector_iterator<T>
	{
		public:
			typedef T value_type;
			typedef T& reference;
			typedef T* pointer;
		
		//Constructor & destructors
			const_vector_iterator(void)
			{
				return ;
			};
			const_vector_iterator(pointer ptr)
			{
				this->_ptr = ptr;
			};
			const_vector_iterator(const const_vector_iterator &other)
			{
				*this = other;
			};
			~const_vector_iterator(void)
			{
				return ;
			};

		//Operator overloads
			const_vector_iterator &operator=(const const_vector_iterator &other)
			{
				this->_ptr = other._ptr;
				return (*this);
			};
		//reference dereference
			reference operator*(void) const
			{
				return (*this->_ptr);
			};
			pointer operator->(void)
			{
				return (this->_ptr);
			};
		//brackets
			const value_type &operator[](int n) const
			{
				return (*(*this + n));
			};
	};

	template <class T>
	class const_reverse_vector_iterator : public vector_iterator<T>
	{
		public:
			typedef T value_type;
			typedef T& reference;
			typedef T* pointer;
					
		//Constructor & destructors
			const_reverse_vector_iterator(void)
			{
				return ;
			};
			const_reverse_vector_iterator(pointer ptr)
			{
				this->_ptr = ptr;
			};
			const_reverse_vector_iterator(const const_reverse_vector_iterator &other)
			{
				*this = other;
			};
			~const_reverse_vector_iterator(void)
			{
				return ;
			};
		//Operator overloads
			const_reverse_vector_iterator &operator=(const const_reverse_vector_iterator &other)
			{
				this->_ptr = other._ptr;
				return (*this);
			};
		//reference dereference
			reference operator*(void) const
			{
				return (*this->_ptr);
			};
			pointer operator->(void)
			{
				return (this->_ptr);
			};
		//brackets
			const value_type &operator[](int n) const
			{
				return (*(*this + n));
			};
	};
};

#endif