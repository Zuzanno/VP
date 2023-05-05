#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <sstream>
#include <cmath>

int main()
{
	sf::RenderWindow window(sf::VideoMode(500, 800), "VP");

	//BG
	sf::Texture bgText;
	sf::Sprite bg;
	sf::Vector2u TextureSize;
	sf::Vector2u WindowSize;
	//VP
	sf::Texture aiText;
	sf::Sprite ai;
	//health
	sf::Texture heText;
	sf::Sprite he;
	//Hunger
	sf::Texture hunText;
	sf::Sprite hun;
	//Energy
	sf::Texture eneText;
	sf::Sprite ene;
	//Mood
	sf::Texture mooText;
	sf::Sprite moo;
	//dolla
	sf::Texture dllText;
	sf::Sprite dll;
	//Fonts
	sf::Font font;
	sf::Text statst;
	sf::Text laugh;
	//Top Banner
	sf::RectangleShape tb;
	tb.setSize(sf::Vector2f(500, 80));
	tb.setFillColor(sf::Color(255,255,255,150));
	tb.setPosition(0, 0);
	//Indicators frame
	sf::RectangleShape ih;
	ih.setSize(sf::Vector2f(250, 50));
	ih.setFillColor(sf::Color::Transparent);
	ih.setPosition(130, 15);
	//Indicators frame
	sf::RectangleShape stats;
	stats.setSize(sf::Vector2f(500, 800));
	stats.setFillColor(sf::Color(255,255,255,150));
	stats.setPosition(0,0);
	//Indicator 1
	sf::RectangleShape i1;
	i1.setSize(sf::Vector2f(40, 40));
	i1.setFillColor(sf::Color(0, 255, 255, 0));
	i1.setOutlineColor(sf::Color::Black);
	i1.setOutlineThickness(5.f);
	i1.setPosition(150, 20);
	//Indicator 2
	sf::RectangleShape i2;
	i2.setSize(sf::Vector2f(40, 40));
	i2.setFillColor(sf::Color(0, 255, 255, 0));
	i2.setOutlineColor(sf::Color::Black);
	i2.setOutlineThickness(5.f);
	i2.setPosition(210, 20);
	//Indicator 3
	sf::RectangleShape i3;
	i3.setSize(sf::Vector2f(40, 40));
	i3.setFillColor(sf::Color(0, 255, 255, 0));
	i3.setOutlineColor(sf::Color::Black);
	i3.setOutlineThickness(5.f);
	i3.setPosition(270, 20);
	//Indicator 4
	sf::RectangleShape i4;
	i4.setSize(sf::Vector2f(40, 40));
	i4.setFillColor(sf::Color(0, 255, 255, 0));
	i4.setOutlineColor(sf::Color::Black);
	i4.setOutlineThickness(5.f);
	i4.setPosition(330, 20);

	if (!aiText.loadFromFile("media/ai.png"))
	{
		return -1;
	}
	else
	{
		ai.setTexture(aiText);
		ai.setTextureRect(sf::IntRect(0, 0, 720, 925));
		ai.setPosition(115, 280);
		ai.setScale(sf::Vector2f(0.4f, 0.4f));
	}

	if (!font.loadFromFile("fonts/Symtext.ttf"))
	{
		return -1;
	}
	else
	{
		statst.setFont(font);
		statst.setCharacterSize(30);
		statst.setFillColor(sf::Color::Black);
		stats.setOutlineThickness(10.f);
		statst.setOutlineColor(sf::Color::Black);
		statst.setPosition(110, 200);
		laugh.setFont(font);
		laugh.setCharacterSize(30);
		laugh.setFillColor(sf::Color::White);
		laugh.setOutlineThickness(5.f);
		laugh.setOutlineColor(sf::Color::Black);
		laugh.setPosition(40, 200);
	}

	if (!bgText.loadFromFile("media/bg1.png"))
	{
		return -1;
	}
	else
	{
		TextureSize = bgText.getSize();
		WindowSize = window.getSize();

		float scaleX = (float)WindowSize.x / TextureSize.x;
		float ScaleY = (float)WindowSize.y / TextureSize.y;

		bg.setTexture(bgText);
		bg.setScale(scaleX, ScaleY);
	}

	if (!heText.loadFromFile("media/health.png"))
	{
		return -1;
	}
	else
	{
		he.setTexture(heText);
		he.setTextureRect(sf::IntRect(0, 0, 40, 40));
		he.setPosition(210.4, 20);
		he.setScale(sf::Vector2f(1.f,1.f));
	}

	if (!hunText.loadFromFile("media/pizza.png"))
	{
		return -1;
	}
	else
	{
		hun.setTexture(hunText);
		hun.setTextureRect(sf::IntRect(0, 0, 40, 40));
		hun.setPosition(150.4, 20);
		hun.setScale(sf::Vector2f(1.f, 1.f));
	}

	if (!eneText.loadFromFile("media/energy.png"))
	{
		return -1;
	}
	else
	{
		ene.setTexture(eneText);
		ene.setTextureRect(sf::IntRect(0, 0, 40, 40));
		ene.setPosition(330.4, 20);
		ene.setScale(sf::Vector2f(1.f, 1.f));
	}

	if (!mooText.loadFromFile("media/mood.png"))
	{
		return -1;
	}
	else
	{
		moo.setTexture(mooText);
		moo.setTextureRect(sf::IntRect(0, 0, 40, 40));
		moo.setPosition(270.4, 20);
		moo.setScale(sf::Vector2f(1.f, 1.f));
	}

	if (!dllText.loadFromFile("media/dolla.png"))
	{
		return -1;
	}
	else
	{
		dll.setTexture(dllText);
		dll.setTextureRect(sf::IntRect(0, 0, 960, 578));
		dll.setPosition(13, 20);
		dll.setScale(sf::Vector2f(0.07f, 0.07f));
	}


	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		statst.setString("Hunger\nHealth\nHappiness\nEnergy");
		laugh.setString("Pffffft JAJAJAJAJAJJ");

		window.clear();
		window.draw(bg);
		window.draw(ai);
		window.draw(tb);
		window.draw(i1);
		window.draw(i2);
		window.draw(i3);
		window.draw(i4);
		window.draw(he);
		window.draw(hun);
		window.draw(ene);
		window.draw(moo);
		window.draw(dll);
		window.draw(ih);
		
		//Button click
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			sf::Vector2i mPos;
			mPos = sf::Mouse::getPosition(window);

			if (ih.getGlobalBounds().contains(mPos.x, mPos.y))
			{
				window.draw(stats);
				window.draw(statst);
			}
			if (ai.getGlobalBounds().contains(mPos.x, mPos.y))
			{
				window.draw(laugh);
			}
		}

		window.display();
	
	}
}


