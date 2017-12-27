/*
 * ColorRGB.hpp
 *
 *  Created on: 6 déc. 2017
 *      Author: Djenna
 */

#ifndef COLORRGB_HPP_
#define COLORRGB_HPP_

class ColorRGB {
private:
	int rouge;
	int bleu;
	int vert;

public:
	ColorRGB();

	int getBleu() const {
		return bleu;
	}

	void setBleu(int bleu) {
		this->bleu = bleu;
	}

	int getRouge() const {
		return rouge;
	}

	void setRouge(int rouge) {
		this->rouge = rouge;
	}

	int getVert() const {
		return vert;
	}

	void setVert(int vert) {
		this->vert = vert;
	}
};

#endif /* COLORRGB_HPP_ */
