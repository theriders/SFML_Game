//
// Created by bswenson3 on 11/9/16.
//

#include "RegularGameObject.h"

RegularGameObject::RegularGameObject() {

}

bool RegularGameObject::load(const std::string& filename) {
	if (m_texture.loadFromFile(filename)) {
		m_filename = filename;
		m_sprite.setTexture(m_texture);
		m_valid = true;
		return true;
	}
	return false;
}

void RegularGameObject::update(float deltaT) {

}

void RegularGameObject::draw(sf::RenderWindow& window) {
	if (m_valid)
		window.draw(m_sprite);
}

void RegularGameObject::move(sf::Vector2f loc) {
	if (m_valid)
		m_sprite.move(loc);
}

void RegularGameObject::setPosition(float x, float y) {
	if (m_valid)
		m_sprite.setPosition(x, y);
}

sf::Vector2f RegularGameObject::getPosition() const {
	if (m_valid)
		return m_sprite.getPosition();
	else
		return sf::Vector2f(0, 0);
}

float RegularGameObject::getHeight() const {
	return m_sprite.getLocalBounds().height;
}

float RegularGameObject::getWidth() const {
	return m_sprite.getLocalBounds().width;
}

void RegularGameObject::setScale(float scale) {
	if (m_valid)
		m_sprite.setScale(scale, scale);
}

void RegularGameObject::changeValid(bool a) {
    m_valid = a;
}

bool RegularGameObject::isValid() {
    return m_valid;
}