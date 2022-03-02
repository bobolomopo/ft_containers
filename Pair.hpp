/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pair.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jandre <ajuln@hotmail.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 16:03:02 by jandre            #+#    #+#             */
/*   Updated: 2022/03/02 17:09:45 by jandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PAIR_HPP
# define PAIR_HPP

namespace ft 
{
    template <class T1, class T2> 
    struct Pair
    {
        //typedef
        typedef T1 first_type;
        typedef T2 second_type;

        //Member of the Pair
        first_type first;
        second_type second;

        //Constructor && Destructor
        Pair() : first(), second()
        {
            return ;
        };
        template<class U, class V>
        Pair (const Pair<U,V>& pr) : first(pr.first), second(pr.second)
        {
            return ;
        };
        Pair (const first_type& a, const second_type& b) : first(a), second(b)
        {
            return ;
        };
        //operator overload
        Pair& operator= (const Pair& pr)
        {
            if (*this != pr)
            {
                this->first = pr.first;
                this->second = pr.second;
            }
            return (*this);
        };
    };
    //Non-member methods
    //boolean relationnal operators
    template <class T1, class T2>
    bool operator==(const Pair<T1,T2>& lhs, const Pair<T1,T2>& rhs)
    {
        return (lhs.first == rhs.first && lhs.second == rhs.second);
    }
    template <class T1, class T2>
    bool operator!=(const Pair<T1,T2>& lhs, const Pair<T1,T2>& rhs)
    {
        return (!(lhs == rhs));
    }
    template <class T1, class T2>
    bool operator<(const Pair<T1,T2>& lhs, const Pair<T1,T2>& rhs)
    {
        return (lhs.first < rhs.first || (!(rhs.first < lhs.first) && lhs.second < rhs.second));
    }
    template <class T1, class T2>
    bool operator<=(const Pair<T1,T2>& lhs, const Pair<T1,T2>& rhs)
    {
        return (!(rhs < lhs));
    }
    template <class T1, class T2>
    bool operator>(const Pair<T1,T2>& lhs, const Pair<T1,T2>& rhs)
    {
        return (rhs < lhs);
    }
    template <class T1, class T2>
    bool operator>=(const Pair<T1,T2>& lhs, const Pair<T1,T2>& rhs)
    {
        return (!(lhs < rhs));
    }
    template <class T1,class T2>
    //make pair template
    Pair<T1, T2> make_pair (T1 x, T2 y)
    {
        return (Pair<T1, T2>(x, y));
    }
}

#endif