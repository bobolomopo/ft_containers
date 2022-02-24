/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   VectorIterators.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jandre <jandre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 12:37:52 by jandre            #+#    #+#             */
/*   Updated: 2022/02/24 14:20:52 by jandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_ITERATOR_HPP
# define VECTOR_ITERATOR_HPP

namespace ft
{
    template <class T>
    class VectorIterator
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
            VectorIterator(void)
            {
                return ;
            };
            VectorIterator(const VectorIterator &other)
            {
                *this = other;
                return ;
            };
            VectorIterator(pointer ptr) : _ptr(ptr)
            {
                return ;
            };
            ~VectorIterator(void)
			{
                return ;
            };

        //Operator overloads
            VectorIterator &operator=(const VectorIterator &other)
            {
                if (*this != other)
                    this->_ptr = other._ptr;
                return (*this);
            };

        //increment & decrement before and after the it
            VectorIterator &operator++(void)
            {
                this->_ptr++;
                return ;
            };
            VectorIterator &operator--(void)
            {
                this->_ptr--;
                return ;
            };
            VectorIterator operator++(int)
			{
				VectorIterator tmp(*this);
				operator++();
				return (tmp);
			};
			VectorIterator operator--(int)
			{
				VectorIterator tmp(*this);
				operator--();
				return (tmp);
			};

        //boolean operators
            bool operator==(const VectorIterator &other) const
			{
				return (_ptr == other._ptr);
			};
			bool operator!=(const VectorIterator &other) const
			{
				return (_ptr != other._ptr);
			};
			bool operator>(const VectorIterator &other) const
			{
				return (_ptr > other._ptr);
			};
			bool operator>=(const VectorIterator &other) const
			{
				return (_ptr >= other._ptr);
			};
			bool operator<(const VectorIterator &other) const
			{
				return (_ptr < other._ptr);
			};
			bool operator<=(const VectorIterator &other) const
			{
				return (_ptr <= other._ptr);
			};
    
        //reference and dereference
            value_type &operator*(void)
			{
				return (*this->_ptr);
			};
			value_type *operator->(void)
			{
				return (this->_ptr);
			};

        //Basic arithmetic operations
            VectorIterator operator+(int n) const
			{
				VectorIterator tmp(*this);
				tmp += n;
				return (tmp);
			};
			VectorIterator operator-(int n) const
			{
				VectorIterator tmp(*this);
				tmp -= n;
				return (tmp);
			};
			VectorIterator &operator+=(int n)
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
			VectorIterator &operator-=(int n)
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
    class ReverseVectorIterator : public VectorIterator<T>
    {
        public:
        //Typedef to simplify the usage of the T class
            typedef T value_type;
            typedef T& reference;
			typedef T* pointer;

        //Constructors && destructors
            ReverseVectorIterator(void)
            {
                return ;
            };
            ReverseVectorIterator(const ReverseVectorIterator &other)
            {
                *this = other;
                return ;
            };
            ReverseVectorIterator(pointer ptr) : _ptr(ptr)
            {
                return ;
            };
            ~ReverseVectorIterator(void)
			{
                return ;
            };

        //Operator overloads
            ReverseVectorIterator &operator=(const ReverseVectorIterator &other)
            {
                if (*this != other)
                    this->_ptr = other._ptr;
                return (*this);
            };

        //increment & decrement before and after the it
            ReverseVectorIterator &operator++(void)
            {
                this->_ptr++;
                return ;
            };
            ReverseVectorIterator &operator--(void)
            {
                this->_ptr--;
                return ;
            };
            ReverseVectorIterator operator++(int)
			{
				ReverseVectorIterator tmp(*this);
				operator++();
				return (tmp);
			};
			ReverseVectorIterator operator--(int)
			{
				ReverseVectorIterator tmp(*this);
				operator--();
				return (tmp);
			};

        //boolean operators
            bool operator==(const ReverseVectorIterator &other) const
			{
				return (_ptr == other._ptr);
			};
			bool operator!=(const ReverseVectorIterator &other) const
			{
				return (_ptr != other._ptr);
			};
			bool operator>(const ReverseVectorIterator &other) const
			{
				return (_ptr > other._ptr);
			};
			bool operator>=(const ReverseVectorIterator &other) const
			{
				return (_ptr >= other._ptr);
			};
			bool operator<(const ReverseVectorIterator &other) const
			{
				return (_ptr < other._ptr);
			};
			bool operator<=(const ReverseVectorIterator &other) const
			{
				return (_ptr <= other._ptr);
			};

        //reference and dereference
            value_type &operator*(void)
			{
				return (*this->_ptr);
			};
			value_type *operator->(void)
			{
				return (this->_ptr);
			};

        //Basic arithmetic operations
            ReverseVectorIterator operator+(int n) const
			{
				ReverseVectorIterator tmp(*this);
				tmp += n;
				return (tmp);
			};
			ReverseVectorIterator operator-(int n) const
			{
				ReverseVectorIterator tmp(*this);
				tmp -= n;
				return (tmp);
			};
			ReverseVectorIterator &operator+=(int n)
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
			ReverseVectorIterator &operator-=(int n)
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
	class ConstVectorIterator : public VectorIterator<T>
	{
		public:
			typedef T value_type;
			typedef T& reference;
			typedef T* pointer;
		
		//Constructor & destructors
			ConstVectorIterator(void)
			{
				return ;
			};
			ConstVectorIterator(pointer ptr)
			{
				this->_ptr = ptr;
			};
			ConstVectorIterator(const ConstVectorIterator &other)
			{
				*this = other;
			};
			~ConstVectorIterator(void)
			{
				return ;
			};

		//Operator overloads
			ConstVectorIterator &operator=(const ConstVectorIterator &other)
			{
				this->_ptr = other._ptr;
				return (*this);
			};
		//reference dereference
			const value_type &operator*(void)
			{
				return (*this->_ptr);
			};
			const value_type *operator->(void)
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
	class ConstReverseVectorIterator : public ReverseVectorIterator<T>
	{
		public:
			typedef T value_type;
			typedef T& reference;
			typedef T* pointer;
					
		//Constructor & destructors
			ConstReverseVectorIterator(void)
			{
				return ;
			};
			ConstReverseVectorIterator(pointer ptr)
			{
				this->_ptr = ptr;
			};
			ConstReverseVectorIterator(const ConstReverseVectorIterator &other)
			{
				*this = other;
			};
			~ConstReverseVectorIterator(void)
			{
				return ;
			};
		//Operator overloads
			ConstReverseVectorIterator &operator=(const ConstReverseVectorIterator &other)
			{
				this->_ptr = other._ptr;
				return (*this);
			};
		//reference dereference
			const value_type &operator*(void)
			{
				return (*this->_ptr);
			};
			const value_type *operator->(void)
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