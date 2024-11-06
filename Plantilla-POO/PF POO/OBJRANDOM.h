#pragma once
#include "Colisiones.h"
#include "stdlib.h"
#include "time.h"

class OBJRANDOM :public Colisiones
{
private:
	int pz, px, operacion;
public:
	OBJRANDOM(string modelPath, string texturePath, bool mode, float _rangox, float _rangoz, float _ox, float _oy, float _oz) :
		Colisiones(modelPath, texturePath, mode, _rangox, _rangoz, _ox, _oy, _oz)
	{
		pz = (1 + rand() % (6 - 1))*5;
		px = (1 + rand() % (6 - 1))*5;
		operacion = (1 + rand() % (11 - 1));
		if (operacion <= 5)
		{
			this->setox(this->getox() + px);
			this->setoz(this->getoz() + pz);
		}
		if (operacion >= 6)
		{
			this->setox(this->getox() - px);
			this->setoz(this->getoz() - pz);
		}
	}

};