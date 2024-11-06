#pragma once
#include "Animados.h"

class Enemigo : public Animados 
{
private:
	bool gameover, direccion;
	float r1, r2;
	int swich;
public:

	Enemigo(string modelPath, string texturePath, bool mode, float _rangox, float _rangoz, float _ox, 
		float _oy, float _oz, float _Angulo, bool _cambio, bool _gameover, bool _direccion, float _r1, float _r2) : 
		Animados( modelPath,  texturePath,  mode,  _rangox,  _rangoz,  _ox,  _oy, _oz, _Angulo, _cambio)
	{
		gameover = _gameover;
		direccion = _direccion;
		r1 = _r1;
		r2 = _r2;
		swich = 0;

	}

	void setGameover(bool _gameover) { gameover = _gameover;}
	bool getGameover() { return gameover; }

	void Animacion() {
		if(direccion == 1)
		{
			if (this->GetCambio() == true)
			{
				this->setox(this->getox() + 1.0);
				if (this->getox() >= r1)
				{
					this->setCambio(false);
					this->setAngulo(180.0f);
				}
			}

			if (this->GetCambio() == false)
			{
				this->setox(this->getox() - 1.0f);
				if (this->getox() <= r2)
				{
					this->setCambio(true);
					this->setAngulo(0.0f);
				}
			}
		}
		if (direccion == 0)
		{
			if (this->GetCambio() == true)
			{
				this->setoz(this->getoz() + 1.2);
				if (this->getoz() >= r1)
				{
					this->setCambio(false);
					this->setAngulo(180.0f);
				}
			}

			if (this->GetCambio() == false)
			{
				this->setoz(this->getoz() - 1.2f);
				if (this->getoz() <= r2)
				{
					this->setCambio(true);
					this->setAngulo(0.0f);
				}
			}
			if (swich == 0)
			{
				this->setoy(this->getoy() + 0.15f);
				if (this->getoy() >= 14)
				{
					swich = 1;
				}
			}

			if (swich == 1)
			{
				this->setoy(this->getoy() - 0.15f);
				if (this->getoy() <= 12)
				{
					swich = 0;
				}
			}
		}
		
	}

	void GAMEOVER(bool _colision)
	{
		if (_colision == true)
		{
			this->setGameover(true);
		}
	}
};