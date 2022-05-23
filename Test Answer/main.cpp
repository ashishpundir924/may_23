#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

#include <animatedassets.h>
#include <dragon.h>
#include <tree.h>

int main()
{
    // create the window
    sf::RenderWindow window(sf::VideoMode(800, 600), "My window");

    // Load background
    sf::Texture background_t; // 213 x 160
    if(!background_t.loadFromFile("background.png")) return 1;
    sf::Sprite background;
    background.setTexture(background_t);
    background.setPosition(0, 0);
    background.setScale(3.75, 3.75);

    // Load other objects
    // Dragon
    sf::Texture dragon_t; // 3756 x 678
    if(!dragon_t.loadFromFile("dragon939x678.png")) return 1;
    Dragon dragon(0);
    dragon.setTexture(dragon_t);
    dragon.setTextureRect(sf::IntRect(0, 0, 939, 678));
    dragon.setScale(0.1, 0.1);
    dragon.setPosition(100, window.getSize().y/2);

    // Random Seed
    std::srand(std::time(NULL));

    // Tree
    sf::Texture tree_t; // 672 x 96
    if(!tree_t.loadFromFile("tree96x96.png")) return 1;
    std::vector<Tree> trees;
    int tree_num = 2;
    for(int i = 0; i < tree_num; i++)
    {
        Tree tree(-200 + rand() % 300);
        tree.setTexture(tree_t);
        tree.setTextureRect(sf::IntRect(0, 0, 96, 96));
        tree.setScale(0.8, 0.8);
        tree.setPosition(window.getSize().x - tree.getGlobalBounds().width, window.getSize().y - tree.getGlobalBounds().height);
        trees.emplace_back(tree);
    }

    sf::Clock clock;

    // run the program as long as the window is open
    while (window.isOpen())
    {
        sf::Time elapsed = clock.restart();

        for(auto &tree : trees)
        {
            tree.moveTree(elapsed, window);
        }

        if(sf::Keyboard::isKeyPressed((sf::Keyboard::W)))
        {
            dragon.setVspeed(-250);
            dragon.jump(elapsed);
        }
        else
        {
            dragon.animate(elapsed, window);
        }


        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed) window.close();
        }

        // clear the window with black color
        window.clear(sf::Color::Black);

        // draw everything here...
        window.draw(background);
        window.draw(dragon);
        for(auto &tree : trees)
        {
            window.draw(tree);
        }

        // end the current frame
        window.display();
    }

    return 0;
}