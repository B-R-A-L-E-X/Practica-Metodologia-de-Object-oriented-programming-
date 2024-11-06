#pragma once
#include "Colisiones.h"
#include "stdlib.h"
#include "time.h"
#include "Objetivo.h"

class Meta:public Colisiones
{
private:
	bool win;
	int posicion;
public:
	Meta(string modelPath, string texturePath, bool mode, float _rangox, float _rangoz, float _ox, float _oy, float _oz, bool _win):
		Colisiones( modelPath, texturePath,  mode, _rangox, _rangoz, _ox, _oy, _oz)
	{
		win = _win;
	}
	void setWin(bool _win) { win = _win; }
	bool getWin() { return win; }

	void WIN(bool _colision) 
	{
	if(_colision == true && Objetivo::Recolectados() == 5)
	{
		this->setWin(true);
	}
	}
};