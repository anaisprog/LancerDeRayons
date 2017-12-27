/*
 * Camera.hpp
 *
 *  Created on: 6 déc. 2017
 *      Author: Djenna
 */

#include "Position.hpp"

#ifndef CAMERA_HPP_
#define CAMERA_HPP_

class Camera {

public:
	Position saPosition;
	Camera();
	Camera(Position pos);
	//virtual ~Camera();

	const Position& getSaPosition() const {
		return saPosition;
	}

	void setSaPosition(const Position& saPosition) {
		this->saPosition = saPosition;
	}
};

#endif /* CAMERA_HPP_ */
