#pragma once
#include "Animados.h"
#include "stdlib.h"
#include "time.h"

class Objetivo : public Animados
{
private:
	bool capturado;
	bool activo;
	static int recolectados;
	int pz, px, operacion;
public:
	Objetivo(string modelPath, string texturePath, bool mode, float _rangox, float _rangoz,
		float _ox, float _oy, float _oz, float _Angulo, bool _cambio, bool _capturado, bool _activo) : 
		Animados(modelPath, texturePath, mode, _rangox, _rangoz, _ox, _oy, _oz, _Angulo, _cambio) 
	{
		capturado = _capturado;
		activo = _activo; 
		srand(time(NULL));
		if (activo == true) {
			for (int i = 1; i <= 5; i++)
			{
				pz = (1 + rand() % (6 - 1));
				px = (1 + rand() % (6 - 1)) ;
				operacion = (1 + rand() % (3 - 1));
			}
		}
		else {
			for (int i = 1; i <= 5; i++)
			{
				pz = (1 + rand() % (6 - 1)) * 5;
				px = (1 + rand() % (6 - 1)) * 5;
				operacion = (1 + rand() % (3 - 1));
			}
		}
		if (operacion <= 1)
		{
			this->setox(this->getox() + px);
			this->setoz(this->getoz() + pz);
		}
		if (operacion >= 2)
		{
			this->setox(this->getox() - px);
			this->setoz(this->getoz() - pz);
		}

	}

	void setCapturado(bool _capturado) { capturado = _capturado; }
	void setActivo(bool _activo) { activo = _activo; }

	bool getCapturado() { return capturado; }
	bool getActivo() { return activo; }

	void Animacion()
	{
		float _angulo;
		_angulo = this->GetAngulo();
		if (_angulo < 360) 
		{
			_angulo+=0.5F;
		}
		else 
		{
			_angulo = 0;
		}
		this->setAngulo(_angulo);
		if (this->GetCambio() == true)
		{
			this->setoy(this->getoy() + 0.025f);
			if (this->getoy() >= 16)
			{
				this->setCambio(false);
			}
		}

		if (this->GetCambio() == false)
		{
			this->setoy(this->getoy() - 0.025f);
			if (this->getoy() <= 14)
			{
				this->setCambio(true);
			}
		}

		
	}

	void CAPTURADO(bool _colision)
	{
	if (_colision == true)
		{
			this->setCapturado(true);
			recolectados++;
		}
	}

	static int Recolectados() 
	{
		return recolectados;
	}
};

int Objetivo::recolectados = 0;
