#pragma once
#include "Model.h"
#include "Camera.h"

class Colisiones : public EDXFramework::Model 
{
private:
	float rangox, rangoz, ox, oz, oy;

public:
	Colisiones(string modelPath, string texturePath, bool mode, float _rangox, float _rangoz, float _ox, float _oy, float _oz): Model (modelPath, texturePath, mode)
	{
		rangox = _rangox;
		rangoz = _rangoz;
		ox = _ox;
		oz = _oz;
		oy = _oy;
	}
	void setrangox(float _rangox) { rangox = _rangox; };
	void setrangoz(float _rangoz) { rangoz = _rangoz; };
	void setox(float _ox) { ox = _ox; };
	void setoz(float _oz) { oz = _oz; };
	void setoy(float _oy) { oy = _oy; };

	float getrangox() { return rangox; }
	float getrangoz() { return rangoz; }
	float getox() { return ox; }
	float getoz() { return oz; }
	float getoy() { return oy; }

	bool colision(GLfloat px, GLfloat pz, float _ox, float _oz, float _rangox, float _rangoz) 
	{
		if (px > (_ox-_rangox) && px < (_ox+_rangox)) {
			if (pz > (_oz - _rangoz) && pz < (_oz + _rangoz)) 
			{
				return true;
			}
		}
		else {
			return false;
		}
	}
};