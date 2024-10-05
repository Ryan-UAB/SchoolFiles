#include "screensaver.h"
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Vector2.hpp>
#include <iostream>
#include <cmath>

//Self-explanatory
ScreenSaver::ScreenSaver() {
  shape = sf::CircleShape(10.f);
  velocity = sf::Vector2f(0.0f, 0.0f);
  shape.setFillColor(sf::Color::White);
}

//Self-explanatory
ScreenSaver::ScreenSaver(float radius, sf::Vector2f cVelocity, sf::Color color) {
  shape = sf::CircleShape(radius);
  velocity = cVelocity;
  shape.setFillColor(color);
}

//We have to return shape as a reference!
sf::CircleShape &ScreenSaver::getShape() { return shape; }

//this will draw the sf::CircleShape member of ScreenSaver to the screen
//this will be inherited by all derived class, and shouldn't have to be overriden
void ScreenSaver::draw(sf::RenderWindow &window) { window.draw(getShape()); }

/*Here's some nifty code to resolve any collsions with a wall, by reversing
the velocity of the object to mimic bouncing, you can call this function
in your update functions to make sure your ScreenSaver doesn't wander off-screen*/
void ScreenSaver::checkWallCollision(int screenWidth, int screenHeight){
  sf::Vector2f position = getShape().getPosition();
  float diameter = getShape().getRadius() * 2;

  // Check if the circle hits the right wall
  if (position.x + diameter > screenWidth)
  {
    getShape().setPosition(screenWidth - diameter, position.y);
    velocity.x *= -1.f;
  }

  // Check if the circle hits the left wall
  if (position.x < 0)
  {
    getShape().setPosition(0, position.y);
    velocity.x *= -1.f;
  }

  // Check if the circle hits the top wall
  if (position.y < 0)
  {
    getShape().setPosition(position.x, 0);
    velocity.y *= -1.f;
  }

  // Check if the circle hits the bottom wall
  if (position.y + diameter > screenHeight)
  {
    getShape().setPosition(position.x, screenHeight - diameter);
    velocity.y *= -1.f;
  }
}


//TODO Define all necessary member functions for ClassicSaver, ColorChangingSaver, and CustomSaver Here
ClassicSaver::ClassicSaver(){}
ClassicSaver::ClassicSaver(float radius, sf::Vector2f cVelocity, sf::Color color){ 
  getShape() = sf::CircleShape(radius);
  velocity = cVelocity;
  getShape().setFillColor(color);
}

void ClassicSaver::update(float deltaTime, int screenWidth, int screenHeight){
  getShape().move(velocity.x * deltaTime, velocity.y * deltaTime);
  checkWallCollision(screenWidth, screenHeight);
}

ColorChangingSaver::ColorChangingSaver(float radius, sf::Vector2f cVelocity, float cColorSpeed){
  getShape() = sf::CircleShape(radius);
  velocity = cVelocity;
  getShape().setFillColor(sf::Color(0, 127, 255, 255));
  colorSpeed = cColorSpeed;
}

void ColorChangingSaver::update(float deltaTime, int screenWidth, int screenHeight){
  sf::Color current = getShape().getFillColor();
  getShape().move(velocity.x * deltaTime, velocity.y * deltaTime);
  checkWallCollision(screenWidth, screenHeight);
  getShape().setFillColor(current + sf::Color(10 * colorSpeed, 5 * colorSpeed, 3 * colorSpeed, 0));
  if(current.r == 255){getShape().setFillColor(current - sf::Color(255, 0, 0, 0));}
  if(current.b == 255){getShape().setFillColor(current - sf::Color(0, 0, 255, 0));}
  if(current.g == 255){getShape().setFillColor(current - sf::Color(0, 255, 0, 0));}
}

CustomSaver::CustomSaver(float someFloat, sf::Vector2f someVector, float someOtherFloat){
  getShape() = sf::CircleShape(someFloat);
  velocity = someVector;
  rotation = someOtherFloat;
  getShape().setFillColor(sf::Color::Cyan);
  getShape().setOrigin(100, 100);
  getShape().setPosition(300 * velocity.x, 400 * velocity.y);
}

void CustomSaver::update(float deltaTime, int screenWidth, int screenHeight){
  getShape().rotate(rotation * deltaTime);
  checkWallCollision(screenWidth, screenHeight);
}

