#include "tree.h"

Tree::Tree(int hspeed) : AnimatedAssets(0, hspeed)
{

}

void Tree::moveTree(sf::Time &elapsed, sf::RenderWindow &window)
{
    sf::FloatRect bounds = this->getGlobalBounds();
    if(bounds.left <= 0.0) // Dont exit screen on left side
    {
        this->setHspeed(std::abs(this->getHspeed()));
//        this->setPosition(0.0, current_y_);
    }
    else if(bounds.left >= window.getSize().x - bounds.width) // Dont exit screen on right side
    {
        this->setHspeed(-std::abs(this->getHspeed()));
//        this->setPosition(windowSize.x - enemy_bounds.width, current_y_);
    }
    this->move(this->getHspeed() * elapsed.asSeconds(), 0);
}
