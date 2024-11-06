#pragma once
#include "Animados.h"

class Carteles : public Animados
{
private:
	float auxy, auxs, rangoy, rangos , scale;
	bool cambio2;
public:

	Carteles(string modelPath, string texturePath, bool mode, float _rangox, float _rangoz, float _ox, 
		float _oy, float _oz, float _Angulo, bool _cambio, bool _cambio2, float _rangoy, float _rangos, float _scale):
		Animados(modelPath, texturePath, mode, _rangox, _rangoz, _ox, _oy, _oz, _Angulo, _cambio)
	{
		rangoy = _rangoy;
		rangos = _rangos;
		scale = _scale;
		auxy = this->getoy();
		auxs = _scale;
		cambio2 = _cambio2;
	}

	void setScale(float _scale) { scale = _scale; }
	float getScale() { return scale; }

	void setCambio2(bool _cambio) { cambio2 = _cambio; }
	bool getCambio2() { return cambio2; }

	void Animacion()
	{
		if(this->GetCambio()==true)
		{
			this->setoy(this->getoy() + 0.05f);
			if (this->getoy() >= (auxy + rangoy)) 
			{
				this->setCambio(false);
			}
		}

		if (this->GetCambio() == false)
		{
			this->setoy(this->getoy() - 0.05f);
			if (this->getoy() <= (auxy - rangoy))
			{
				this->setCambio(true);
			}
		}

		if (this->getCambio2() == true)
		{
			this->setScale(this->getScale() + 0.005f);
			if (this->getScale() >= (auxs + rangos))
			{
				this->setCambio2(false);
			}
		}

		if (this->getCambio2() == false)
		{
			this->setScale(this->getScale() - 0.005f);
			if (this->getScale() <= (auxs))
			{
				this->setCambio2(true);
			}
		}
	}

};