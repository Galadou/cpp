#ifndef AANIMAL_HPP
# define AANIMAL_HPP

#include <iostream>

class AAnimal
{
	public:
		AAnimal();
		AAnimal(AAnimal const &cpy);
		AAnimal	&operator=(AAnimal const &src);
		virtual ~AAnimal();

		//with virtual, makeSound can be redefined by inherited class
		virtual void	makeSound() const = 0;
		const std::string	&getType() const;
		
	protected:
		std::string _type;
};

#endif