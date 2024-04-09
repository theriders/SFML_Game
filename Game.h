//
// Created by bswenson3 on 11/9/16.
//
#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include "RegularGameObject.h"
#include "GameObject.h"
#include "AnimatedGameObject.h"

class Game {
public:
	//use default screen size
	Game();
	//run the game
	void run();

private:
	void processEvents();
	//update the game objects
	void update(sf::Time deltaT,sf::Time gTime);
	//draw the scene
	void render();
	//handle input from the user
	void handlePlayerInput(sf::Keyboard::Key key, bool isDown);
	//check collison with walls or other objects
	bool collision(GameObject* a,GameObject* b);
	bool collision(sf::Rect<float> a,GameObject* b);

	sf::RenderWindow m_window;

	GameObject* m_player = new AnimatedGameObject(404,206,3,3,7,0);
	std::vector<GameObject*> stuff;

	//TODO::these should be moved to game object
	float m_speed = 120.0f;
	bool m_left = false;
	bool m_right = false;
	bool m_up = false;
	bool m_down = false;
	bool w = false;
	bool space = false;
};

