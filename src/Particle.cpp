/*
 * Particle.cpp
 *
 *  Created on: Apr 12, 2020
 *      Author: andre
 */

#include "Particle.h"
#include "Screen.h"
#include <stdlib.h>
#include <math.h>

namespace WPM {

Particle::Particle() {
	// TODO Auto-generated constructor stub
	init();
}

Particle::~Particle() {
	// TODO Auto-generated destructor stub
}

void Particle::init(){
	m_x = rand() % Screen::SCREEN_WIDTH;
	m_y = rand() % Screen::SCREEN_HEIGHT;
	m_direction = (2 * M_PI * rand())/RAND_MAX;
	m_speed = (0.2 * rand())/RAND_MAX;
}

void Particle::update(int interval){

	double xspeed = m_speed * cos(m_direction) + 0.5;
	double yspeed = m_speed * sin(m_direction);

	m_x += (int) (xspeed * interval);
	m_y += (int) (yspeed * interval);
	m_x %= Screen::SCREEN_WIDTH;
	m_y %= Screen::SCREEN_HEIGHT;

	if(m_x < -1 || m_y < -1){
		init();
	}
//
//	if(rand() < RAND_MAX/100){
//		init();
//	}
}

} /* namespace WPM */
