/*
 * Particle.h
 *
 *  Created on: Apr 12, 2020
 *      Author: andre
 */

#ifndef PARTICLE_H_
#define PARTICLE_H_

namespace WPM {

struct Particle {

private:

	double m_speed;
	double m_direction;
	void init();

public:

	int m_x;
	int m_y;
	void update(int interval);
	Particle();
	virtual ~Particle();
};

} /* namespace WPM */

#endif /* PARTICLE_H_ */
