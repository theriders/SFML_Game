

#include "AnimatedGameObject.h"
#include <cmath>
#include <iostream>

AnimatedGameObject::AnimatedGameObject() {
    xsize = 10;
    ysize = 10;
    howmanyx = 1;
    howmanyy = 1;
    howmany = 1;
    curr = 1;
}

AnimatedGameObject::AnimatedGameObject(double x,double y,int nx,int ny,int n,int angle) {
    m_sprite.setRotation(angle);
    xsize = x;
    ysize = y;
    howmanyx = nx;
    howmanyy = ny;
    howmany = n;
    curr = 1;
}

bool AnimatedGameObject::load(const std::string& filename) {
    if (m_texture.loadFromFile(filename)) {
        m_filename = filename;
        m_sprite.setTexture(m_texture);
        //std::cout << floor(xsize/(double)howmanyx) << "   " << floor(ysize/(double)howmanyy) << std::endl;
        rect = sf::IntRect(0,0,floor(xsize/(double)howmanyx),floor(ysize/(double)howmanyy));
        m_sprite.setTextureRect(rect);
        m_valid = true;
        return true;
    }
    return false;
}

void AnimatedGameObject::update(float Tsec) {

    int temp = ((int)floor(Tsec*1000000))%100;
    //int temp = 0;
    if (temp == 0){
       // std::cout << curr << std::endl;
    if (curr <  howmany) {
        int check = curr % howmanyx;
        if (check == 0) {
            rect = sf::IntRect(0,rect.top + rect.height,floor(xsize/(double)howmanyx),floor(ysize/(double)howmanyy));
            m_sprite.setTextureRect(rect);
        } else {
            rect = sf::IntRect(rect.left + rect.width,rect.height,floor(xsize/(double)howmanyx),floor(ysize/(double)howmanyy));
            m_sprite.setTextureRect(rect);
        }
        curr++;
    } else {
        rect = sf::IntRect(0,0,floor(xsize/(double)howmanyx),floor(ysize/(double)howmanyy));
        m_sprite.setTextureRect(rect);
        curr = 1;
    }
    }
}

void AnimatedGameObject::draw(sf::RenderWindow& window) {
    if (m_valid) {
        window.draw(m_sprite);
        //std::cout << "i am drawn  " << m_filename << std::endl;
    }
}

void AnimatedGameObject::move(sf::Vector2f loc) {
    if (m_valid)
        m_sprite.move(loc);
}

void AnimatedGameObject::setPosition(float x, float y) {
    if (m_valid)
        m_sprite.setPosition(x, y);
}

sf::Vector2f AnimatedGameObject::getPosition() const {
    if (m_valid)
        return m_sprite.getPosition();
    else
        return sf::Vector2f(0, 0);
}

float AnimatedGameObject::getHeight() const {
    return m_sprite.getLocalBounds().height;
}

float AnimatedGameObject::getWidth() const {
    return m_sprite.getLocalBounds().width;
}

void AnimatedGameObject::setScale(float scale) {
    if (m_valid)
        m_sprite.setScale(scale, scale);
}

void AnimatedGameObject::changeValid(bool a) {
    m_valid = a;
}

bool AnimatedGameObject::isValid() {
    return m_valid;
}
