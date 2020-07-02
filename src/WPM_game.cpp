//============================================================================
// Name        : WPM_game.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

//============================================================================
// Name        : basic.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description :
//============================================================================

#include <iostream>
#include <SDL2/SDL.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include "Screen.h"
#include "Background.h"

int main(){

	srand(time(nullptr));

	WPM::Screen screen;

	if(!screen.init()) std::cout << "Error initializing" << "\n";

	WPM::Background background;

	while(true){
		//update
		//draw
		int elapsed = SDL_GetTicks();

		background.update(elapsed);

		unsigned char red= (unsigned char) ((1 + sin(elapsed*0.0001))*128);
		unsigned char green = (unsigned char) ((1 + sin(elapsed*0.0002))*128);
		unsigned char blue = (unsigned char) ((1 + sin(elapsed*0.0003))*128);

		const std::vector<WPM::Particle*> Particles = background.getParticles();

		for(auto particle: Particles)
		{
			screen.setPixel(particle->m_x, particle->m_y, red, green, blue);
		}

		screen.boxBlur();

		screen.update();

		//check for messages/ events
		if(!screen.processEvents()){
			break;
		}
	}

	screen.close();

	return 0;
}

