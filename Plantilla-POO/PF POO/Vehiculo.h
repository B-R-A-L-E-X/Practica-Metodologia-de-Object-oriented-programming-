#pragma once
#include "Animados.h"

class Vehiculo : public Animados
{
private:
	bool atropello, cambio2, cambio3, cambio4;
	float rx1, rx2, rz1, rz2;
public:
	Vehiculo(string modelPath, string texturePath, bool mode, float _rangox, float _rangoz,
		float _ox, float _oy, float _oz, float _Angulo, bool _cambio, bool _atropello, bool _cambio2,
		bool _cambio3, bool _cambio4, float _rx1, float _rx2, float _rz1, float _rz2) :
		Animados(modelPath, texturePath, mode, _rangox, _rangoz, _ox, _oy, _oz, _Angulo, _cambio)
	{
		atropello = _atropello;
		cambio2 = _cambio2;
		cambio3 = _cambio3;
		cambio4 = _cambio4;
		rx1 = _rx1;//-26
		rx2 = _rx2;//91
		rz1 = _rz1;//-15
		rz2 = _rz2;//168

	}

	void setAtropello(bool _atropello) { atropello = _atropello; }
	void setCambio2(bool _cambio2) { cambio2 = _cambio2; }
	void setCambio3(bool _cambio3) { cambio3 = _cambio3; }
	void setCambio4(bool _cambio4) { cambio4 = _cambio4; }

	bool getAtropello() { return atropello; }
	bool getCambio2() { return cambio2; }
	bool getCambio3() { return cambio3; }
	bool getCambio4() { return cambio4; }


	void Animacion() 
	{
		if (this->getoz() >= rz1 && this->GetCambio() == true)
		{
			this->setoz(this->getoz()+1);
			if (this->getoz() >= rz2)
			{
				this->setCambio(false);
				this->setAngulo(90);
				this->setCambio2(true);
			}
		}
		if (this->getox() >= rx1 && this->getCambio2() == true)
		{
			this->setox(this->getox() + 1);
			if (this->getox() >= rx2)
			{
				this ->setCambio2(false);
				this->setAngulo(180);
				this->setCambio3(true);
			}
		}

		if (this->getoz() >= rz2 && this->getCambio3() == true || this->getoz() <= rz2 && this->getCambio3() == true)
		{
			this->setoz(this->getoz() - 1);
			if (this->getoz() <= rz1)
			{
				this->setCambio3(false);
				this->setAngulo(270);
				this->setCambio4(true);
			}
		}
		if (this->getox() >= rx2 && this->getCambio4() == true || this->getox() <= rx2 && getCambio4() == true)
		{
			this->setox(this->getox() - 1); 
			if (this->getox() <= rx1)
			{
				this->setCambio4(false);
				this->setAngulo(0);
				this->setCambio(true);
			}
		}
	
	}
	
	void GAMEOVER(bool _colision)
	{
		if (_colision == true) 
		{
			this->setAtropello(true);
		}
	}
};