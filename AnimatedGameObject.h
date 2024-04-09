//
// Created by Rohan Malik on 12/4/18.
//

#pragma once
#include "GameObject.h"

class AnimatedGameObject : public GameObject {
public:

    AnimatedGameObject();

    AnimatedGameObject(double x,double y,int nx,int ny,int howmany,int angle);

    bool load(const std::string& filename);

    void draw(sf::RenderWindow& window);

    void update(float deltaT);

    void setPosition(float x, float y);

    void move(sf::Vector2f);

    sf::Vector2f getPosition() const;

    float getHeight() const;

    float getWidth() const;

    void setScale(float scale);

    void changeValid(bool a);

    bool isValid();

private:
    sf::Sprite m_sprite;
    sf::Texture m_texture;
    std::string m_filename;
    bool m_valid = false;
    double xsize;
    double ysize;
    int howmanyx;
    int howmanyy;
    int howmany;
    int curr;
    sf::IntRect rect;
};

