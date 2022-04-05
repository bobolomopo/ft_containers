/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexicographical_compare.hpp                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jandre <ajuln@hotmail.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 21:55:44 by jandre            #+#    #+#             */
/*   Updated: 2022/04/05 20:29:23 by jandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXICOGRAPHICAL_COMPARE_HPP
# define LEXICOGRAPHICAL_COMPARE_HPP

namespace ft {
    //Returns true if the range [first1,last1) compares lexicographically less than the range [first2,last2).
    //A lexicographical comparison is the kind of comparison generally used to sort words alphabetically in 
    //dictionaries; It involves comparing sequentially the elements that have the same position in both ranges 
    //against each other until one element is not equivalent to the other. The result of comparing these first 
    //non-matching elements is the result of the lexicographical comparison.
    //If both sequences compare equal until one of them ends, the shorter sequence is lexicographically 
    //less than the longer one.

    template <class InputIterator1, class InputIterator2>
    bool lexicographical_compare (InputIterator1 first1, InputIterator1 last1, 
        InputIterator2 first2, InputIterator2 last2)
    {
        while (first1!=last1)
        {
            if (first2 == last2 || *first2 < *first1)
                return false;
            else if (*first1 < *first2) 
                return true;
            ++first1;
            ++first2;
        }
        return (first2 != last2);
    };

    //The same but we use a binary(bool) function comp to compare lexographically the first and second range.

    template <class InputIterator1, class InputIterator2, class Compare>
    bool lexicographical_compare (InputIterator1 first1, InputIterator1 last1, 
        InputIterator2 first2, InputIterator2 last2, Compare comp)
    {
        while (first1 != last1)
        {
            if (first2 == last2 || comp(*first2, *first1))
                return false;
            else if (comp(*first1, *first2))
                return true;
            ++first1;
            ++first2;
        }
        return (first2 != last2);
    }

    //Compares the elements in the range [first1,last1) with those in the range beginning at first2,
    //and returns true if all of the elements in both ranges match.

    template <class InputIterator1, class InputIterator2>
    bool equal(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2 )
    {
        while (first1!=last1)
        {
            if (!(*first1 == *first2)) 
                return false;
            ++first1;
            ++first2;
        }
        return true;
    }
}

#endif
