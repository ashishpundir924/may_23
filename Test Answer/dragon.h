#pragma once

#include "animatedassets.h"

class Dragon : public AnimatedAssets
{
private:
    int acceleration = 150;
    float fall_velocity = 0;
public:
    Dragon(int vspeed);

    void animate(sf::Time elapsed, sf::RenderWindow &window);

    void jump(sf::Time elapsed);
};
