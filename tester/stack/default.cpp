#include "base.hpp"

#define T1 int
typedef NAME::stack<T1>::container_type container_type;

int		main(void)
{
	NAME::stack<T1> stck;

	std::cout << "empty: " << stck.empty() << std::endl;
	std::cout << "size: " << stck.size() << std::endl;

	stck.push(41);
	stck.push(29);
	stck.push(10);
	stck.push(42);
	std::cout << "Added some elements" << std::endl;

	std::cout << "empty: " << stck.empty() << std::endl;
	print_stack(stck);

	return (0);
}
