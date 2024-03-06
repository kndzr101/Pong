#include <SFML/Graphics.hpp>
#include <SFML/Window/Keyboard.hpp>

	int posy1 = 1080/2;
	int posy2 = 1080/2;
	int posBx = 1920/2;
	int posBy = 1080/2;

int main()
{
    sf::RenderWindow window(sf::VideoMode(1920u, 1080u), "Pong game");
    sf::RectangleShape shape;
    shape.setSize(sf::Vector2f(25,100));
    shape.setOutlineColor(sf::Color::Red);
    shape.setOutlineThickness(5);
    shape.setPosition(10,20);
	sf::RectangleShape shape2;
    shape2.setSize(sf::Vector2f(25,100));
    shape2.setOutlineColor(sf::Color::Red);
    shape2.setOutlineThickness(5);
    shape2.setPosition(10,20);
    sf::CircleShape ball(25);
    ball.setFillColor(sf::Color(250, 250, 250));
    ball.setPosition(1920/2,1080/2);


    window.setFramerateLimit(144);


	
	int i = 0;
	int j = 0;
	int ballMovex = 2;
	int ballMovey = 2;
	int ballx = 1920/2 + ballMovex;
	int bally = 1080/2 + ballMovey;
	int paddlev = 10;
	bool endGame = false;


    

    while (window.isOpen())
    {
        for (auto event = sf::Event{}; window.pollEvent(event);)
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
            // Handle other events or modify the circle's properties here
        }

        window.clear();
	
        //window.draw(shape); // Draw the circle

		shape.setFillColor(sf::Color(100,250,50));
		shape2.setFillColor(sf::Color(100,250,50));

		
		 posy1 = 1080/2 + j*paddlev;
		 posy2 = 1080/2 + i*paddlev;

		 
		if ( sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
			if ( posy1 > 0){
				j--;
			}
		}
		if ( sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
			if ( posy1 < 1080-151){
				j++;
			}
		}
		if ( sf::Keyboard::isKeyPressed(sf::Keyboard::S)){
			if ( posy2 < 1080-151){
				i++;
			}
		}
		if ( sf::Keyboard::isKeyPressed(sf::Keyboard::W)){
			if ( posy2 > 0){
				i--;
			}
		}
		if ( bally < 50 || bally > 1080-50){
			ballMovey = ballMovey*(-1);
		}
		if ( ballx < 25){
			if ( bally > posy1-50 && bally < posy1+50){
				ballMovex = ballMovex*(-1);
			}
			else{
				endGame = true;
				return 0;
			}
		}
		if ( ballx > 1920-50){
			if ( bally > posy2-50 && bally < posy2+50){
				ballMovex = ballMovex*(-1);
			}
			else{
				endGame = true;
				return 0;
			}
		}

		ballx = ballx + ballMovex;
		bally = bally + ballMovey; 

		shape.setPosition(25, posy1);
		shape2.setPosition(1920-25,posy2);
		ball.setPosition(ballx, bally);
		window.clear();
		window.draw(ball);
		window.draw(shape);
		window.draw(shape2);

			
        window.display();
    }

    return 0;
}

