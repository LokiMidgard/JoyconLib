#pragma once
#include "stdafx.h"

namespace JoyConNative {

	public	enum class HCIState : System::Byte
	{
		Disconnect = 0x00,
		RebootAndReconnect = 0x01,
		RebootAndEnterPairMode = 0x02,
		RebotAndReconnectHomeMode = 0x04
	};
}