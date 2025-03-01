#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

int main(void)
{
	Base *ptr = generate();
	if (!ptr)
		std::cout << "Error while generated." << std ::endl;
	identify(ptr);

	std::cout << std::endl;

	Base &ref = *ptr;
	identify(ref);

	delete ptr;
}