/*
 * Background.h
 *
 *  Created on: Jul 1, 2020
 *      Author: andre
 */

#ifndef BACKGROUND_H_
#define BACKGROUND_H_

#include <vector>
#include "Particle.h"

namespace WPM {

class Background {

private:
	constexpr static int m_numOfParticles = 50;
	std::vector<Particle*> Particles;
	int m_last_time;

public:
	std::vector<Particle*> getParticles(){return Particles;}
	void update(int elapsed);
	Background();
	virtual ~Background();
};

} /* namespace WPM */

#endif /* BACKGROUND_H_ */
