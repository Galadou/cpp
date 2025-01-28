#ifndef CHARACTER_HPP
# define CHARACTER_HPP

#include "ICharacter.hpp"
#include "AMateria.hpp"

class Character : public ICharacter
{
	public:
		Character();
		Character(const std::string name);
		~Character();
		Character	&operator=(Character const &src);
		Character(Character const &cpy);

		std::string const & getName() const;
		void equip(AMateria* m);
		void unequip(int idx);
		void use(int idx, ICharacter& target);

	private:
		int _idx;
		std::string _name;
		AMateria *_inventory[4];
		AMateria *_ground[100];
};

#endif
