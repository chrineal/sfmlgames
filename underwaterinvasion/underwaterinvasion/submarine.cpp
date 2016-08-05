#include "stdafx.h"
#include "submarine.h"


Sub::Sub(float x, float y)
{
	subPosition.x = x;
	subPosition.y = y;
	subSprite.setPosition(subPosition);

	fuelBarPosition.x = 0;
	fuelBarPosition.y = 50;
	fuelBar.setSize(sf::Vector2f(400, 20));
	fuelBar.setFillColor(sf::Color::Green);
	fuelBar.setPosition(fuelBarPosition);
}

sf::FloatRect Sub::getSubCoord()
{
	return subSprite.getGlobalBounds();
}

sf::RectangleShape Sub::getFuelBar()
{
	return fuelBar;
}

sf::Sprite Sub::getSprite()
{
	return subSprite;
}

float Sub::getSubRailSpd()
{
	return subRailSpd;
}

float Sub::getSubMoveSpd()
{
	return subMoveSpd;
}

float Sub::getSubFuelCount()
{
	return fuelCount;
}

float Sub::getSubLifeCount()
{
	return subLifeCount;
}


void Sub::changeFuelBarSize(float x, float y)
{
	fuelBar.setSize(sf::Vector2f(x, y));
}

void Sub::changeFuelBarPosition(float x, float y)
{
	fuelBarPosition.x = x;
	fuelBarPosition.y = y;
}

void Sub::resetSubPos()
{
	subPosition.y = 250;
}

void Sub::addFuel()
{
	fuelCount += 50;
}

void Sub::moveUp()
{
	subPosition.y -= subMoveSpd;
}

void Sub::moveDown()
{
	subPosition.y += subMoveSpd;
}

void Sub::moveLeft()
{
	subPosition.x -= subMoveSpd;
}

void Sub::moveRight()
{
	subPosition.x += subMoveSpd;
}

void Sub::decreaseLife()
{
	subLifeCount--;
}

void Sub::resetLife()
{
	subLifeCount = 3.0f;
}

void Sub::increaseFuel()
{
	fuelCount += 100.0f;
}

void Sub::setTexture(string fileloc)
{
	spriteTexture.loadFromFile(fileloc);
	spriteTexture.setSmooth(true);
	subSprite.setTexture(spriteTexture);
}

void Sub::update()
{
	if (subPosition.y < 0) {
		subPosition.y += subMoveSpd;
	}

	if (subPosition.x < 0) {
		subPosition.x += subMoveSpd;
	}

	if (!sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
		subPosition.x += subRailSpd;
	}

	if (fuelBar.getSize().x >= 400) {
		fuelBar.setSize(sf::Vector2f(400, 20));
	}

	fuelCount -= 0.04;
	fuelBar.setSize(sf::Vector2f(fuelCount, 20));

	if (fuelBar.getSize().x > 200) {
		fuelBar.setFillColor(sf::Color::Green);
	}
	else if (fuelBar.getSize().x <= 200) {
		fuelBar.setFillColor(sf::Color::Red);
	}

	subSprite.setPosition(subPosition);
	fuelBar.setPosition(fuelBarPosition);

}
