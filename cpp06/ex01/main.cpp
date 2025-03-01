
#include "Data.hpp"
#include "Serializer.hpp"

int main(void)
{
	try
	{
		Data data;
		Data *ptr = &data;
		Data *newPtr = NULL;
		uintptr_t result;

		ptr->setName("Fée Clochette");
		std::cout << "Name of ptr is " << ptr->getName() << std::endl;
		result = Serializer::serialize(ptr);
		std::cout << "Ptr serialize = " << result << std::endl;

		//We use a newPtr to be shure its not the same ptr.
		newPtr = Serializer::deserialize(result);
		std::cout << "name of newPtr is now " << newPtr->getName() << std::endl;
		std::cout << "Adress held by newPtr is " << newPtr << std::endl;
		std::cout << "And the adress held ptr is " << ptr << std::endl;

	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}