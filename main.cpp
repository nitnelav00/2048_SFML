#include <SFML/Graphics.hpp>
#include <string>

#include "gamefuncs.hpp"

sf::RenderWindow App;
sf::Font font;
sf::Text txt;

void drawText(const char * text, int x, int y, int size){
	txt.setString(text);
	txt.setCharacterSize(size);
	txt.setPosition(x,y);
	App.draw(txt);
}

int main() {

    App.create(sf::VideoMode(800, 600), "2048 (fait par Nitnelav00)");
	App.setFramerateLimit(60);
	font.loadFromFile("FFFFORWA.TTF");
	txt.setFont(font);
	txt.setFillColor(sf::Color::Black);

	sf::RectangleShape rect;
	reset();

    while (App.isOpen()) {
        sf::Event Event;
        while (App.pollEvent(Event)) {
            if (Event.type == sf::Event::Closed)
            App.close();
			if (Event.type == sf::Event::KeyPressed)
			{
				if (Event.key.code == sf::Keyboard::Up)
					up();
				if (Event.key.code == sf::Keyboard::Down)
					down();
				if (Event.key.code == sf::Keyboard::Left)
					left();
				if (Event.key.code == sf::Keyboard::Right)
					right();
				if (Event.key.code == sf::Keyboard::R)
					reset();
				
			}
			
        }
		App.clear();

		rect.setSize(sf::Vector2f(800/SIZE-2,600/SIZE-2));
		rect.setFillColor(sf::Color::Red);
		
		for (unsigned char x = 0; x < SIZE; x++)
        for(unsigned char y = 0; y < SIZE; y++){
			float rr_ = board[x][y]*(255/MAX);
            float rg_ = 127-(board[x][y]*(255/MAX))/2;
            float rb_ = 255-(board[x][y]*(255/MAX));
			rect.setFillColor((sf::Color){(sf::Uint8)rr_,(sf::Uint8)rg_,(sf::Uint8)rb_,255});
			rect.setPosition(x*800/SIZE,y*600/SIZE);
			App.draw(rect);
			if(board[x][y]!=0)
            drawText(std::to_string(1<<board[x][y]).c_str(),x*800/SIZE+10,y*600/SIZE+int(600/SIZE*0.3),int(600/SIZE*0.4));
		}
		
        App.display();
    }
}
