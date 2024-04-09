//
// Created by bswenson3 on 11/9/16.
//
#pragma once

#include <SFML/Graphics.hpp>

class GameObject {
public:

	virtual bool load(const std::string& filename) = 0;

	virtual void draw(sf::RenderWindow& window) = 0;

	virtual void update(float deltaT) = 0;

	virtual void setPosition(float x, float y) = 0;

	virtual void move(sf::Vector2f) = 0;

	virtual sf::Vector2f getPosition() const = 0;

	virtual float getHeight() const = 0;

	virtual float getWidth() const = 0;

	virtual void setScale(float scale) = 0;

	virtual void changeValid(bool valid) = 0;

	virtual bool isValid() = 0;

private:
	sf::Sprite m_sprite;
	sf::Texture m_texture;
	std::string m_filename;
	bool m_valid;

};

