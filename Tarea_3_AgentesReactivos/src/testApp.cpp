/*
Primero se mueve Oveja
Segundo se mueve Lobo
Tercero se mueve Humano


Prioridades (0 - Máxima, 3 - Mínima)

Prioridades de la Oveja:
0 Huir del Lobo
1 Seguir Humano
2 Comer
3 Moverse

Prioridades del lobo:
0 Seguir Oveja
1 Huir del Humano
2 Buscar Oveja
3 Moverse
*/

#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
	lobo1 = new Lobo();
	oveja1 = new Oveja();
	oveja2 = new Oveja();
	persona1 = new Persona();
	ofSetFrameRate(2);
	ofSetWindowTitle("Agentes Reactivos - Óscar Dávila Ramírez 793523");

	ovejas.loadImage("images/Ovejas.png");
	ovejas.resize(40,40);

	srand ( time(NULL) );
	//Ubicación de la persona
	bool salir = false;
	do{
		persona1->posX = rand() % 10;
		persona1->posY = rand() % 10;
		if(tablero.tab[persona1->posX][persona1->posY].ocupada != true){
			tablero.tab[persona1->posX][persona1->posY].contenido = PERSONA;
			tablero.tab[persona1->posX][persona1->posY].ocupada = true;
			salir = true;
		}
	}while(!salir);

	//Ubicación del lobo
	salir = false;
	do{
		lobo1->posX = rand() % 10;
		lobo1->posY = rand() % 10;
		if(tablero.tab[lobo1->posX][lobo1->posY].ocupada != true){
			tablero.tab[lobo1->posX][lobo1->posY].contenido = LOBO;
			tablero.tab[lobo1->posX][lobo1->posY].ocupada = true;
			salir = true;
		}
	}while(!salir);
	

	//Ubicación de la primera oveja
	salir = false;
	do{
		oveja1->posX = rand() % 10;
		oveja1->posY = rand() % 10;
		if(tablero.tab[oveja1->posX][oveja1->posY].ocupada != true){
			tablero.tab[oveja1->posX][oveja1->posY].contenido = OVEJA;
			tablero.tab[oveja1->posX][oveja1->posY].ocupada = true;
			salir = true;
		}
	}while(!salir);

	//Ubicación de la segunda oveja
	salir = false;
	do{
		oveja2->posX = rand() % 10;
		oveja2->posY = rand() % 10;
		if(tablero.tab[oveja2->posX][oveja2->posY].ocupada != true){
			tablero.tab[oveja2->posX][oveja2->posY].contenido = OVEJA;
			tablero.tab[oveja2->posX][oveja2->posY].ocupada = true;
			salir = true;
		}
	}while(!salir);

}

//--------------------------------------------------------------
void testApp::update(){
	ofBackground(255);
	int w = ofGetWidth();             
    int h = ofGetHeight();  
    if(w != 400 || h != 400) ofSetWindowShape(400, 400);  
  
	sensarLobo(lobo1);
	sensarOveja(oveja1);
	sensarOveja(oveja2);
	moverOveja(oveja1);
	moverOveja(oveja2);
	moverLobo(lobo1);
	moverPersona();
}

//--------------------------------------------------------------
void testApp::draw(){	
	(tablero.img).draw(0,0);
	ofEnableAlphaBlending();
	lobo1->img.draw(lobo1->posX * 40, lobo1->posY * 40);
	if(oveja1->posX == oveja2->posX && oveja1->posY == oveja2->posY){
		ovejas.draw(oveja1->posX * 40, oveja1->posY * 40);
	}else{
		oveja1->img.draw(oveja1->posX * 40, oveja1->posY * 40);
		oveja2->img.draw(oveja2->posX * 40, oveja2->posY * 40);
	}
	persona1->img.draw(persona1->posX * 40, persona1->posY * 40);
	ofDisableAlphaBlending();
}

//--------------------------------------------------------------
void testApp::moverPersona(){

	int salir;
	//Mover Persona
	salir = false;
	do{

		switch(	persona1->act() ){
		case UP:
			if ( persona1->posY - 1 >= 0 ){
				if(tablero.tab[persona1->posX][persona1->posY - 1].ocupada != true){
					tablero.tab[persona1->posX][persona1->posY - 1].contenido = PERSONA;
					tablero.tab[persona1->posX][persona1->posY - 1].ocupada = true;
					tablero.tab[persona1->posX][persona1->posY].contenido = VACIA;
					tablero.tab[persona1->posX][persona1->posY].ocupada = false;
					(persona1->posY)--; 
					salir = true;
				}
			}
			break;
		case DOWN:
			if ( persona1->posY + 1 < 10 ){
				if(tablero.tab[persona1->posX][persona1->posY + 1].ocupada != true){
					tablero.tab[persona1->posX][persona1->posY + 1].contenido = PERSONA;
					tablero.tab[persona1->posX][persona1->posY + 1].ocupada = true;
					tablero.tab[persona1->posX][persona1->posY].contenido = VACIA;
					tablero.tab[persona1->posX][persona1->posY].ocupada = false;
					(persona1->posY)++; 
					salir = true;
				}
			}
			break;
		case LEFT:
			if ( persona1->posX - 1 >= 0 ){
				if(tablero.tab[persona1->posX - 1][persona1->posY].ocupada != true){
					tablero.tab[persona1->posX - 1][persona1->posY].contenido = PERSONA;
					tablero.tab[persona1->posX - 1][persona1->posY].ocupada = true;
					tablero.tab[persona1->posX][persona1->posY].contenido = VACIA;
					tablero.tab[persona1->posX][persona1->posY].ocupada = false;
					(persona1->posX)--; 
					salir = true;
				}
			}
			break;
		case RIGHT:
			if ( persona1->posX + 1 < 10 ){
				if(tablero.tab[persona1->posX + 1][persona1->posY].ocupada != true){
					tablero.tab[persona1->posX + 1][persona1->posY].contenido = PERSONA;
					tablero.tab[persona1->posX + 1][persona1->posY].ocupada = true;
					tablero.tab[persona1->posX][persona1->posY].contenido = VACIA;
					tablero.tab[persona1->posX][persona1->posY].ocupada = false;
					(persona1->posX)++; 
					salir = true;
				}
			}
			break;
		}
	}while(!salir);
}

//--------------------------------------------------------------
void testApp::sensarOveja(Oveja *oveja){
	int Accion = 99;
	bool salir = false;
	int randomAct;
	if ( oveja->posY - 1 >= 0 ){
		if(tablero.tab[oveja->posX][oveja->posY - 1].ocupada == true)
		{
			switch(tablero.tab[oveja->posX][oveja->posY - 1].contenido)
			{
			case PERSONA:
				Accion = 1;
				//Seguir a la persona
				oveja->NposX = oveja->posX;
				oveja->NposY = oveja->posY - 1;
				break;
			case LOBO:
				Accion = 0;
				//Movimiento para escapar del lobo.
			
				salir = false;
				do {
					randomAct = rand() % 3;
					switch( randomAct )
					{
					case 0:
						if ( oveja->posX - 1 >= 0 ){
						if(tablero.tab[oveja->posX - 1][oveja->posY].ocupada != true || tablero.tab[oveja->posX - 1][oveja->posY].contenido == PERSONA){
							oveja->NposX = oveja->posX - 1;
							oveja->NposY = oveja->posY;
							salir = true;
						}
						}
						break;
					case 1:
						if ( oveja->posY + 1 < 10 ){
						if(tablero.tab[oveja->posX][oveja->posY + 1].ocupada != true || tablero.tab[oveja->posX][oveja->posY + 1].contenido == PERSONA){
							oveja->NposX = oveja->posX;
							oveja->NposY = oveja->posY + 1;
							salir = true;
						}
						}
						break;
					case 2:
						if ( oveja->posX + 1 < 10 ){
						if(tablero.tab[oveja->posX + 1][oveja->posY].ocupada != true || tablero.tab[oveja->posX + 1][oveja->posY].contenido == PERSONA){
							oveja->NposX = oveja->posX + 1;
							oveja->NposY = oveja->posY;
							salir = true;
						}
						}
						break;
					}
				}while(!salir);

				break;
			default:
				break;
			}
		}
	}
	if ( oveja->posY + 1 < 10 ){
		if(tablero.tab[oveja->posX][oveja->posY + 1].ocupada == true)
		{
			switch(tablero.tab[oveja->posX][oveja->posY + 1].contenido)
			{
			case PERSONA:
				if(Accion > 1){
					Accion = 1;
					//Seguir a la persona
					oveja->NposX = oveja->posX;
					oveja->NposY = oveja->posY + 1;
				}
				break;
			case LOBO:
				Accion = 0;
				//Movimiento para escapar del lobo.

								salir = false;
				do {
					randomAct = rand() % 3;
					switch( randomAct )
					{
					case 0:
						if ( oveja->posX - 1 >= 0 ){
						if(tablero.tab[oveja->posX - 1][oveja->posY].ocupada != true || tablero.tab[oveja->posX - 1][oveja->posY].contenido == PERSONA){
							oveja->NposX = oveja->posX - 1;
							oveja->NposY = oveja->posY;
							salir = true;
						}
						}
						break;
					case 1:
						if ( oveja->posX + 1 < 10 ){
						if(tablero.tab[oveja->posX + 1][oveja->posY].ocupada != true || tablero.tab[oveja->posX + 1][oveja->posY].contenido == PERSONA){
							oveja->NposX = oveja->posX + 1;
							oveja->NposY = oveja->posY;
							salir = true;
						}
						}
						break;
					case 2:
						if ( oveja->posY - 1 >= 0 ){
						if(tablero.tab[oveja->posX][oveja->posY - 1].ocupada != true || tablero.tab[oveja->posX][oveja->posY - 1].contenido == PERSONA){
							oveja->NposX = oveja->posX;
							oveja->NposY = oveja->posY - 1;
							salir = true;
						}
						}
						break;
					}
				}while(!salir);

				break;
			default:
				break;
			}
		}
	}
	if ( oveja->posX - 1 >= 0 ){
		if(tablero.tab[oveja->posX - 1][oveja->posY].ocupada == true)
		{
			switch(tablero.tab[oveja->posX - 1][oveja->posY].contenido)
			{
			case PERSONA:
				if(Accion > 1){
					Accion = 1;
					//Seguir a la persona
					oveja->NposX = oveja->posX - 1;
					oveja->NposY = oveja->posY;
				}
				break;
			case LOBO:
				Accion = 0;
				//Movimiento para escapar del lobo.
				salir = false;
				do {
					randomAct = rand() % 3;
					switch( randomAct )
					{
					case 0:
						if ( oveja->posX + 1 < 10 ){
						if(tablero.tab[oveja->posX + 1][oveja->posY].ocupada != true || tablero.tab[oveja->posX + 1][oveja->posY].contenido == PERSONA){
							oveja->NposX = oveja->posX + 1;
							oveja->NposY = oveja->posY;
							salir = true;
						}
						}
						break;
					case 1:
						if ( oveja->posY + 1 < 10 ){
						if(tablero.tab[oveja->posX][oveja->posY + 1].ocupada != true || tablero.tab[oveja->posX][oveja->posY + 1].contenido == PERSONA){
							oveja->NposX = oveja->posX;
							oveja->NposY = oveja->posY + 1;
							salir = true;
						}
						}
						break;
					case 2:
						if ( oveja->posY - 1 >= 0 ){
						if(tablero.tab[oveja->posX][oveja->posY - 1].ocupada != true || tablero.tab[oveja->posX][oveja->posY - 1].contenido == PERSONA){
							oveja->NposX = oveja->posX;
							oveja->NposY = oveja->posY - 1;
							salir = true;
						}
						}
						break;
					}
				}while(!salir);
				break;
			default:
				break;
			}
		}
	}
	if ( oveja->posX + 1 < 10 ){
		if(tablero.tab[oveja->posX + 1][oveja->posY].ocupada == true)
		{
			switch(tablero.tab[oveja->posX + 1][oveja->posY].contenido)
			{
			case PERSONA:
				if(Accion > 1){
					Accion = 1;
					//Seguir a la persona
					oveja->NposX = oveja->posX + 1;
					oveja->NposY = oveja->posY;
				}
				break;
			case LOBO:
				Accion = 0;
				//Movimiento para escapar del lobo.
				salir = false;
				do {
					randomAct = rand() % 3;
					switch( randomAct )
					{
					case 0:
						if ( oveja->posX - 1 >= 0 ){
						if(tablero.tab[oveja->posX - 1][oveja->posY].ocupada != true || tablero.tab[oveja->posX - 1][oveja->posY].contenido == PERSONA){
							oveja->NposX = oveja->posX - 1;
							oveja->NposY = oveja->posY;
							salir = true;
						}
						}
						break;
					case 1:
						if ( oveja->posY + 1 < 10 ){
						if(tablero.tab[oveja->posX][oveja->posY + 1].ocupada != true || tablero.tab[oveja->posX][oveja->posY + 1].contenido == PERSONA){
							oveja->NposX = oveja->posX;
							oveja->NposY = oveja->posY + 1;
							salir = true;
						}
						}
						break;
					case 2:
						if ( oveja->posY - 1 >= 0 ){
						if(tablero.tab[oveja->posX][oveja->posY - 1].ocupada != true || tablero.tab[oveja->posX][oveja->posY - 1].contenido == PERSONA){
							oveja->NposX = oveja->posX;
							oveja->NposY = oveja->posY - 1;
							salir = true;
						}
						}
						break;
					}
				}while(!salir);
				break;
			default:
				break;
			}
		}
	}

	if( Accion > 1 ){
		//Mover aleatorio o quedarse en el lugar.

		salir = false;
		do{
			randomAct = rand() % 5;
			switch(	randomAct ){
			case UP:
				if ( oveja->posY - 1 >= 0 ){
					if(tablero.tab[oveja->posX][oveja->posY - 1].ocupada != true /*|| tablero.tab[oveja->posX][oveja->posY - 1].contenido == PERSONA*/){
						oveja->NposX = oveja->posX;
						oveja->NposY = oveja->posY - 1;
						salir = true;
					}
				}
				break;
			case DOWN:
				if ( oveja->posY + 1 < 10 ){
					if(tablero.tab[oveja->posX][oveja->posY + 1].ocupada != true /*|| tablero.tab[oveja->posX][oveja->posY - 1].contenido == PERSONA*/){
						oveja->NposX = oveja->posX;
						oveja->NposY = oveja->posY + 1;
						salir = true;
					}
				}
				break;
			case LEFT:
				if ( oveja->posX - 1 >= 0 ){
					if(tablero.tab[oveja->posX - 1][oveja->posY].ocupada != true /*|| tablero.tab[oveja->posX][oveja->posY - 1].contenido == PERSONA*/){
						oveja->NposX = oveja->posX - 1;
						oveja->NposY = oveja->posY;
						salir = true;
					}
				}
				break;
			case RIGHT:
				if ( oveja->posX + 1 < 10 ){
					if(tablero.tab[oveja->posX + 1][oveja->posY].ocupada != true /*|| tablero.tab[oveja->posX][oveja->posY - 1].contenido == PERSONA*/){
						oveja->NposX = oveja->posX + 1;
						oveja->NposY = oveja->posY;
						salir = true;
					}
				}
				break;
			default:
				oveja->NposX = oveja->posX;
				oveja->NposY = oveja->posY;
				salir = true;
				break;
			}
		}while(!salir);

	}

}

//--------------------------------------------------------------
void testApp::sensarLobo(Lobo *lobo){
	int Accion = 99;
	bool salir = false;
	int randomAct;
	if ( lobo->posY - 1 >= 0 ){
		if(tablero.tab[lobo->posX][lobo->posY - 1].ocupada == true)
		{
			switch(tablero.tab[lobo->posX][lobo->posY - 1].contenido)
			{
			case OVEJA:
				Accion = 1;
				//Seguir a la oveja
				lobo->NposX = lobo->posX;
				lobo->NposY = lobo->posY - 1;
				break;
			case PERSONA:
				Accion = 0;
				//Movimiento para escapar del humano.
			
				salir = false;
				do {
					randomAct = rand() % 3;
					switch( randomAct )
					{
					case 0:
						if ( lobo->posX - 1 >= 0 ){
						if(tablero.tab[lobo->posX - 1][lobo->posY].ocupada != true){
							lobo->NposX = lobo->posX - 1;
							lobo->NposY = lobo->posY;
							salir = true;
						}
						}
						break;
					case 1:
						if ( lobo->posY + 1 < 10 ){
						if(tablero.tab[lobo->posX][lobo->posY + 1].ocupada != true){
							lobo->NposX = lobo->posX;
							lobo->NposY = lobo->posY + 1;
							salir = true;
						}
						}
						break;
					case 2:
						if ( lobo->posX + 1 < 10 ){
						if(tablero.tab[lobo->posX + 1][lobo->posY].ocupada != true){
							lobo->NposX = lobo->posX + 1;
							lobo->NposY = lobo->posY;
							salir = true;
						}
						}
						break;
					}
				}while(!salir);

				break;
			default:
				break;
			}
		}
	}
	if ( lobo->posY + 1 < 10 ){
		if(tablero.tab[lobo->posX][lobo->posY + 1].ocupada == true)
		{
			switch(tablero.tab[lobo->posX][lobo->posY + 1].contenido)
			{
			case OVEJA:
				if(Accion > 1){
					Accion = 1;
					//Seguir a la oveja
					lobo->NposX = lobo->posX;
					lobo->NposY = lobo->posY + 1;
				}
				break;
			case PERSONA:
				Accion = 0;
				//Movimiento para escapar del humano.

								salir = false;
				do {
					randomAct = rand() % 3;
					switch( randomAct )
					{
					case 0:
						if ( lobo->posX - 1 >= 0 ){
						if(tablero.tab[lobo->posX - 1][lobo->posY].ocupada != true){
							lobo->NposX = lobo->posX - 1;
							lobo->NposY = lobo->posY;
							salir = true;
						}
						}
						break;
					case 1:
						if ( lobo->posX + 1 < 10 ){
						if(tablero.tab[lobo->posX + 1][lobo->posY].ocupada != true){
							lobo->NposX = lobo->posX + 1;
							lobo->NposY = lobo->posY;
							salir = true;
						}
						}
						break;
					case 2:
						if ( lobo->posY - 1 >= 0 ){
						if(tablero.tab[lobo->posX][lobo->posY - 1].ocupada != true){
							lobo->NposX = lobo->posX;
							lobo->NposY = lobo->posY - 1;
							salir = true;
						}
						}
						break;
					}
				}while(!salir);

				break;
			default:
				break;
			}
		}
	}
	if ( lobo->posX - 1 >= 0 ){
		if(tablero.tab[lobo->posX - 1][lobo->posY].ocupada == true)
		{
			switch(tablero.tab[lobo->posX - 1][lobo->posY].contenido)
			{
			case OVEJA:
				if(Accion > 1){
					Accion = 1;
					//Seguir a la oveja
					lobo->NposX = lobo->posX - 1;
					lobo->NposY = lobo->posY;
				}
				break;
			case PERSONA:
				Accion = 0;
				//Movimiento para escapar del humano.
				salir = false;
				do {
					randomAct = rand() % 3;
					switch( randomAct )
					{
					case 0:
						if ( lobo->posX + 1 < 10 ){
						if(tablero.tab[lobo->posX + 1][lobo->posY].ocupada != true){
							lobo->NposX = lobo->posX + 1;
							lobo->NposY = lobo->posY;
							salir = true;
						}
						}
						break;
					case 1:
						if ( lobo->posY + 1 < 10 ){
						if(tablero.tab[lobo->posX][lobo->posY + 1].ocupada != true){
							lobo->NposX = lobo->posX;
							lobo->NposY = lobo->posY + 1;
							salir = true;
						}
						}
						break;
					case 2:
						if ( lobo->posY - 1 >= 0 ){
						if(tablero.tab[lobo->posX][lobo->posY - 1].ocupada != true){
							lobo->NposX = lobo->posX;
							lobo->NposY = lobo->posY - 1;
							salir = true;
						}
						}
						break;
					}
				}while(!salir);
				break;
			default:
				break;
			}
		}
	}
	if ( lobo->posX + 1 < 10 ){
		if(tablero.tab[lobo->posX + 1][lobo->posY].ocupada == true)
		{
			switch(tablero.tab[lobo->posX + 1][lobo->posY].contenido)
			{
			case OVEJA:
				if(Accion > 1){
					Accion = 1;
					//Seguir a la oveja
					lobo->NposX = lobo->posX + 1;
					lobo->NposY = lobo->posY;
				}
				break;
			case PERSONA:
				Accion = 0;
				//Movimiento para escapar del humano.
				salir = false;
				do {
					randomAct = rand() % 3;
					switch( randomAct )
					{
					case 0:
						if ( lobo->posX - 1 >= 0 ){
						if(tablero.tab[lobo->posX - 1][lobo->posY].ocupada != true){
							lobo->NposX = lobo->posX - 1;
							lobo->NposY = lobo->posY;
							salir = true;
						}
						}
						break;
					case 1:
						if ( lobo->posY + 1 < 10 ){
						if(tablero.tab[lobo->posX][lobo->posY + 1].ocupada != true){
							lobo->NposX = lobo->posX;
							lobo->NposY = lobo->posY + 1;
							salir = true;
						}
						}
						break;
					case 2:
						if ( lobo->posY - 1 >= 0 ){
						if(tablero.tab[lobo->posX][lobo->posY - 1].ocupada != true){
							lobo->NposX = lobo->posX;
							lobo->NposY = lobo->posY - 1;
							salir = true;
						}
						}
						break;
					}
				}while(!salir);
				break;
			default:
				break;
			}
		}
	}

	if( Accion > 1 ){
		//Mover aleatorio o quedarse en el lugar.
		salir = false;
		do{
			randomAct = rand() % 4;
			switch(	randomAct ){
			case UP:
				if ( lobo->posY - 1 >= 0 ){
					if(tablero.tab[lobo->posX][lobo->posY - 1].ocupada != true){
						lobo->NposX = lobo->posX;
						lobo->NposY = lobo->posY - 1;
						salir = true;
					}
				}
				break;
			case DOWN:
				if ( lobo->posY + 1 < 10 ){
					if(tablero.tab[lobo->posX][lobo->posY + 1].ocupada != true){
						lobo->NposX = lobo->posX;
						lobo->NposY = lobo->posY + 1;
						salir = true;
					}
				}
				break;
			case LEFT:
				if ( lobo->posX - 1 >= 0 ){
					if(tablero.tab[lobo->posX - 1][lobo->posY].ocupada != true){
						lobo->NposX = lobo->posX - 1;
						lobo->NposY = lobo->posY;
						salir = true;
					}
				}
				break;
			case RIGHT:
				if ( lobo->posX + 1 < 10 ){
					if(tablero.tab[lobo->posX + 1][lobo->posY].ocupada != true){
						lobo->NposX = lobo->posX + 1;
						lobo->NposY = lobo->posY;
						salir = true;
					}
				}
				break;
			default:
				lobo->NposX = lobo->posX;
				lobo->NposY = lobo->posY;
				salir = true;
				break;
			}
		}while(!salir);

	}

}

//--------------------------------------------------------------
void testApp::moverOveja(Oveja *oveja){
	tablero.tab[oveja->NposX][oveja->NposY].contenido = OVEJA;
	tablero.tab[oveja->NposX][oveja->NposY].ocupada = true;
	tablero.tab[oveja->posX][oveja->posY].contenido = VACIA;
	tablero.tab[oveja->posX][oveja->posY].ocupada = false;
	oveja->posX = oveja->NposX;
	oveja->posY = oveja->NposY;
}

//--------------------------------------------------------------
void testApp::moverLobo(Lobo* lobo){
	tablero.tab[lobo->NposX][lobo->NposY].contenido = LOBO;
	tablero.tab[lobo->NposX][lobo->NposY].ocupada = true;
	tablero.tab[lobo->posX][lobo->posY].contenido = VACIA;
	tablero.tab[lobo->posX][lobo->posY].ocupada = false;
	lobo->posX = lobo->NposX;
	lobo->posY = lobo->NposY;
}

//--------------------------------------------------------------
int testApp::random_action(){
	return rand() % 4;
}

int testApp::random_move(){
	return (rand() % 4);
}

//--------------------------------------------------------------
int testApp::Persona::act(){
	return random_move();
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){ 

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){ 

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}
