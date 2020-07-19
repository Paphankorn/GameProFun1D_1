#include "globalboundcollision.h"

bool globalboundcollision::checkcollision(sf::Sprite &somthing, sf::Sprite &other)
{
	bool collision;
	if (somthing.getGlobalBounds().intersects(other.getGlobalBounds())) {
		collision = true;
	}
	else {
		collision = false;
	}


	return collision;
}
