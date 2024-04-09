//
// Created by bswenson3 on 11/9/16.
//

#include "Game.h"
#include "resource_path.h"
#include <iostream>

Game::Game() :
	m_window(sf::VideoMode(640, 480), "Amazing Game")
{
	//load the player
	//m_player.load(resource_path + "Mario.png");
    m_player->load(resource_path + "rocket.png");
	//size him.  trial and error to get correct values
	//m_player.setScale(.1f);
	//m_player.setPosition(0,200);

	GameObject* asteroid = new AnimatedGameObject(360,280,5,4,19,0);
	stuff.push_back(asteroid);
	stuff[0]->load(resource_path + "asteroid.png");
    stuff[0]->setPosition(300,200);

	GameObject* fire = new AnimatedGameObject(216,216,5,3,10,0);
    stuff.push_back(fire);
    stuff[1]->load(resource_path + "fire.png");
    stuff[1]->setPosition(500,200);

    GameObject* astro = new AnimatedGameObject(144,192,3,4,3,0);
    stuff.push_back(astro);
    stuff[2]->load(resource_path + "astro.png");
    stuff[2]->setPosition(150,400);

    GameObject* laser = new RegularGameObject();
    stuff.push_back(laser);
    stuff[3]->load(resource_path + "laser.png");
    stuff[3]->setPosition(100,300);
    stuff[3]->setScale(.1f);
}

void Game::run() {
    //loop clock
	sf::Clock clock;
	//game time
	sf::Clock gTime;

	while (m_window.isOpen()) {
        //std::cout << "time:  " << (gTime.getElapsedTime().asSeconds()) << std::endl;
		sf::Time deltaT = clock.restart();
		processEvents();
		update(deltaT,gTime.getElapsedTime());
        for(int x = 0;x<stuff.size();x++){
            if ((stuff[x]->isValid()) & collision(stuff[x],m_player))
                m_player->setPosition(0,0);
                //std::cout << "Collision" << std::endl;
        }
		render();
	}
}

void Game::processEvents() {
	sf::Event event;
	while (m_window.pollEvent(event)) {
		switch (event.type) {

		    case sf::Event::KeyPressed:
		    	//handle key down here
		    	handlePlayerInput(event.key.code, true);
		    	break;
		    case sf::Event::KeyReleased:
	    		handlePlayerInput(event.key.code, false);
	    		break;
	    	case sf::Event::Closed:
	    		m_window.close();
	    		break;
		    default:
		        break;
		}

	}
}

void Game::handlePlayerInput(sf::Keyboard::Key key, bool isDown) {
	if (key == sf::Keyboard::Left)
		m_left = isDown;
	if (key == sf::Keyboard::Right)
		m_right = isDown;
	if (key == sf::Keyboard::Up)
		m_up = isDown;
	if (key == sf::Keyboard::Down)
		m_down = isDown;
	if (key == sf::Keyboard::W)
	    w = !isDown;
	if (key == sf::Keyboard::Space)
	    space = !isDown;
}

//use time since last update to get smooth movement
void Game::update(sf::Time deltaT,sf::Time gTime) {
	//Look a vector class!
	sf::Vector2f movement(0.0f, 0.0f);
	if (m_up)
		movement.y -= m_speed;
	if (m_down)
		movement.y += m_speed;
	if (m_left)
		movement.x -= m_speed;
	if (m_right)
		movement.x += m_speed;
	if (w) {
        m_player->update(0.0f);
        w = false;
    }
    if (space) {
        sf::Rect<float> rocket = sf::Rect<float>(m_player->getPosition(),sf::Vector2f((m_window.getSize().x)-(m_player->getPosition().x),m_player->getHeight()));
        for(int x = 0;x<stuff.size();x++){
            if (collision(rocket,stuff[x]))
                stuff[x]->changeValid(false);
        }
        space = false;
    }

    m_player->move(movement * deltaT.asSeconds());
	//m_player.update(gTime.asSeconds());
    for(int x = 0;x<stuff.size();x++){
        stuff[x]->update(gTime.asSeconds());
    }
    //std::cout << deltaT.asSeconds() << "  " << movement.y << std::endl;

}

void Game::render() {
	m_window.clear();

	m_player->draw(m_window);
    for(int x = 0;x<stuff.size();x++){
        stuff[x]->draw(m_window);
    }
	m_window.display();
}

bool Game::collision(GameObject* a,GameObject* b) {
    sf::Rect<float> arect = sf::Rect<float>(a->getPosition(),sf::Vector2f(a->getWidth(),a->getHeight()));
    sf::Rect<float> brect = sf::Rect<float>(b->getPosition(),sf::Vector2f(b->getWidth(),b->getHeight()));
    return arect.intersects(brect);
}

bool Game::collision(sf::Rect<float> a,GameObject* b) {
    sf::Rect<float> brect = sf::Rect<float>(b->getPosition(),sf::Vector2f(b->getWidth(),b->getHeight()));
    return a.intersects(brect);
}