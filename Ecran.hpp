/*
 * Ecran.hpp
 *
 *  Created on: 6 déc. 2017
 *      Author: Djenna
 */


#include "Position.hpp"
#include "ColorRGB.hpp"

#ifndef ECRAN_HPP_
#define ECRAN_HPP_

class Ecran {

private:
	Position tlc;//Top Left Corner
	Position trc;//Top Right Corner
	Position blc;//Bottom Left Corner
	Position brc;//Bottom Right Corner
	int horizontaleRes;
	int verticaleRes;
	ColorRGB background;

public:
	Ecran();

	//Getter et Setter

	const Position& getBlc() const {
		return blc;
	}

	void setBlc(const Position& blc) {
		this->blc = blc;
	}

	const Position& getBrc() const {
		return brc;
	}

	void setBrc(const Position& brc) {
		this->brc = brc;
	}

	const Position& getTlc() const {
		return tlc;
	}

	void setTlc(const Position& tlc) {
		this->tlc = tlc;
	}

	const Position& getTrc() const {
		return trc;
	}

	void setTrc(const Position& trc) {
		this->trc = trc;
	}

	void setHorizontaleRes(int horizontaleRes) {
		this->horizontaleRes = horizontaleRes;
	}

	void setVerticaleRes(int verticaleRes) {
		this->verticaleRes = verticaleRes;
	}

	int getHorizontaleRes() const {
		return horizontaleRes;
	}

	int getVerticaleRes() const {
		return verticaleRes;
	}

	const ColorRGB& getBackground() const {
		return background;
	}

	void setBackground(const ColorRGB& background) {
		this->background = background;
	}
};


#endif /* ECRAN_HPP_ */
