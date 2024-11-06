#pragma once
#include "Model.h"
#include "Colisiones.h"

class Animados : public Colisiones{
private:
	float Angulo;
	float AuxX, AuxY, AuxZ;
	bool cambio;



public:
	
	Animados (string modelPath, string texturePath, bool mode, float _rangox, float _rangoz, float _ox, float _oy, float _oz, float _Angulo, bool _cambio) :
				Colisiones(modelPath,texturePath, mode, _rangox,_rangoz, _ox, _oy, _oz)
	{
		Angulo = _Angulo;
		cambio = _cambio;
	
	}
	
	void setAngulo(float _Angulo) { Angulo = _Angulo; }
	void setCambio(bool _cambio) { cambio = _cambio; }

	void setAuxX(float _AuxX) { AuxX = _AuxX; }
	void setAuxY(float _AuxY) { AuxY = _AuxY; }
	void setAuxZ(float _AuxZ) { AuxZ = _AuxZ; }

	float GetAngulo() { return Angulo; }

	bool GetCambio() {return cambio;}

	float GetAuxX() { return AuxX; }
	float GetAuxY() { return AuxY; }
	float GetAuxZ() { return AuxZ; }

	virtual void Animacion() {}
	
};

