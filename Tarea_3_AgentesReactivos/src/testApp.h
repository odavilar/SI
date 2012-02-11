#pragma once

#include "ofMain.h"

#define SIZE_FILAS 10
#define SIZE_COLUMNAS 10
// 0 - Vacía, 1 - Persona, 2 - Oveja, 3 - Lobo, 4 - 2 Ovejas
#define VACIA 0
#define PERSONA 1
#define OVEJA 2
#define LOBO 3
#define OVEJAS 4

#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3
#define UP_DERECHA 4
#define UP_IZQUIERDA 5
#define DOWN_DERECHA 6
#define DOWN_IZQUIERDA 7

class testApp : public ofBaseApp{

public:

	void setup();
	void update();
	void draw();
	void moverPersona();
	void sensarLobo();

	void keyPressed(int key);
	void keyReleased(int key);
	void mouseMoved(int x, int y );
	void mouseDragged(int x, int y, int button);
	void mousePressed(int x, int y, int button);
	void mouseReleased(int x, int y, int button);
	void windowResized(int w, int h);
	void dragEvent(ofDragInfo dragInfo);
	void gotMessage(ofMessage msg);		

	static int random_action();
	static int random_move();

	class Lobo{
	public:
		Lobo()
		{
			img.loadImage("images/Lobo.png");
			img.resize(40,40);
		}
		~Lobo();
		ofImage img;
		int posX;
		int posY;
		int NposX;
		int NposY;
		void act();
	};

	class Oveja{
	public:
		Oveja()
		{
			img.loadImage("images/Oveja.png");
			img.resize(40,40);
		}
		~Oveja();
		ofImage img;
		int posX;
		int posY;
		int NposX;
		int NposY;
		void act();
	};

	class Persona{
	public:
		Persona()
		{
			img.loadImage("images/Persona.png");
			img.resize(40,40);
		}
		~Persona();
		ofImage img;	
		int posX;
		int posY;
		int act();
	};

	class Casilla{
	public:
		Casilla()
		{
			contenido = VACIA;
			ocupada = false;
		}
		int contenido; // 0 - Vacía, 1 - Persona, 2 - Oveja, 3 - Lobo, 4 - 2 Ovejas
		bool ocupada;
	};

	class Tablero{
	public:
		Tablero()
		{
			img.loadImage("images/Grass.jpg");
			img.resize(400,400);
		}
		~Tablero(){}
		ofImage img;
		Casilla tab[SIZE_FILAS][SIZE_COLUMNAS];
	};

	Lobo* lobo1;
	Oveja* oveja1;
	Oveja* oveja2;
	Persona* persona1;
	Tablero tablero;

	ofImage ovejas; 

	void sensarOveja(Oveja* oveja);
	void moverOveja(Oveja* oveja);
	void sensarLobo(Lobo* lobo);
	void moverLobo(Lobo *lobo);

};

