#pragma once
#include "stdafx.h"

namespace JoyConNative {

	public	enum class ControlerType : DWORD
	{
		LeftJoyCon = PRODUCT_ID_JOY_CON_LEFT,
		RigthJoyCon = PRODUCT_ID_JOY_CON_RIGHT,
		ProControler = PRODUCT_ID_PRO_CONTROLER
	};
}