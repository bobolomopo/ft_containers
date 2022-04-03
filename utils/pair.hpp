/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pair.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jandre <ajuln@hotmail.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 16:03:02 by jandre            #+#    #+#             */
/*   Updated: 2022/04/01 23:39:19 by jandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PAIR_HPP
# define PAIR_HPP

namespace ft 
{
    template <class T1, class T2> 
    struct pair
    {
        //typedef
        typedef T1 first_type;
        typedef T2 second_type;

        //Member of the pair
        first_type first;
        second_type second;

        //Constructor && Destructor
        pair() : first(), second()
        {
            return ;
        };
        template<class U, class V>
        pair (const pair<U,V>& pr) : first(pr.first), second(pr.second)
        {
            return ;
        };
        pair (const first_type& a, const second_type& b) : first(a), second(b)
        {
            return ;
        };
        //operator overload
        pair& operator=(const pair &pr)
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
    bool operator==(const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
    {
        return (lhs.first == rhs.first && lhs.second == rhs.second);
    }
    template <class T1, class T2>
    bool operator!=(const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
    {
        return (!(lhs == rhs));
    }
    template <class T1, class T2>
    bool operator<(const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
    {
        return (lhs.first < rhs.first || (!(rhs.first < lhs.first) && lhs.second < rhs.second));
    }
    template <class T1, class T2>
    bool operator<=(const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
    {
        return (!(rhs < lhs));
    }
    template <class T1, class T2>
    bool operator>(const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
    {
        return (rhs < lhs);
    }
    template <class T1, class T2>
    bool operator>=(const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
    {
        return (!(lhs < rhs));
    }
    //make pair template
    template <class T1,class T2>
    pair<T1, T2> make_pair (T1 x, T2 y)
    {
        return (pair<T1, T2>(x, y));
    }
}

#endif