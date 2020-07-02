/*
 * Background.cpp
 *
 *  Created on: Jul 1, 2020
 *      Author: andre
 */

#include "Background.h"


namespace WPM {

void Background::update(int elapsed)
{
	int interval = elapsed - m_last_time;
	for(auto particle: Particles)
	{
		particle->update(interval);
	}
	m_last_time = elapsed;
}

Background::Background() : m_last_time(0) {
	// TODO Auto-generated constructor stub

	for(auto i=0; i<m_numOfParticles; ++i)
	{
		Particles.push_back(new WPM::Particle());
	}

}

Background::~Background() {
	// TODO Auto-generated destructor stub
}

} /* namespace WPM */
