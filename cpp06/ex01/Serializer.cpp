#include "Serializer.hpp"

Serializer::Serializer() {}

Serializer::~Serializer()
{
	
}

Serializer::Serializer(Serializer const &src)
{
	*this = src;
}


Serializer& Serializer::operator=(Serializer const &src)
{
	(void)src;
	return (*this);
}

uintptr_t Serializer::serialize(Data* ptr)
{
	if (!ptr)
		throw std::invalid_argument("Error: The pointer to Data can't be NULL");
	uintptr_t addr = reinterpret_cast<uintptr_t>(ptr);
	return (addr);
}
Data* Serializer::deserialize(uintptr_t raw)
{
	Data *func = reinterpret_cast<Data *>(raw);
	if (!func)
		throw std::invalid_argument("Error: The uintptr_t isn't valid.");
	return (func);
}