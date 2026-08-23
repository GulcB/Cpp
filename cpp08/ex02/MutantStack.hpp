/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbodur <gbodur@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/22 09:11:01 by gbodur            #+#    #+#             */
/*   Updated: 2026/08/23 07:49:41 by gbodur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <stack>
# include <deque>

template <typename T, typename Container = std::deque<T> >
class MutantStack : public std::stack<T, Container>
{
	public:
	    MutantStack() : std::stack<T, Container>() {}
	    MutantStack(const MutantStack& other) : std::stack<T, Container>(other) {}
	
	    MutantStack& operator=(const MutantStack& other)
	    {
	        if (this != &other)
	            std::stack<T, Container>::operator=(other);
	        return *this;
	    }
	
	    virtual ~MutantStack() {}
	
	    typedef typename Container::iterator iterator;
	    typedef typename Container::const_iterator const_iterator;
	    typedef typename Container::reverse_iterator reverse_iterator;
	    typedef typename Container::const_reverse_iterator const_reverse_iterator;
	
	    iterator begin() { return this->c.begin(); }
	    iterator end() { return this->c.end(); }
	
	    const_iterator begin() const { return this->c.begin(); }
	    const_iterator end() const { return this->c.end(); }
	
	    reverse_iterator rbegin() { return this->c.rbegin(); }
	    reverse_iterator rend() { return this->c.rend(); }
	
	    const_reverse_iterator rbegin() const { return this->c.rbegin(); }
	    const_reverse_iterator rend() const { return this->c.rend(); }
};

#endif