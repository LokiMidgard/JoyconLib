#include "stdafx.h"
#include "BaseControlerState.h"
#include "Controler.h"

using namespace System;
using namespace JoyConNative;

BaseControlerState::BaseControlerState(JoyConNative::Controler^ controler)
{
	this->controler = controler;
}

JoyConNative::BaseControlerState::~BaseControlerState()
{
}

JoyConNative::BaseControlerState::!BaseControlerState()
{
}

void JoyConNative::BaseControlerState::Enter()
{
	if (isActive)
		throw gcnew System::InvalidOperationException("Were already Ented");
	isActive = true;
	OnEnter();
}

void JoyConNative::BaseControlerState::Update(System::TimeSpan & epelapsedTime)
{
	if (!isActive)
		throw gcnew System::InvalidOperationException("Enter was not called");
	OnUpdate(epelapsedTime);
}

void JoyConNative::BaseControlerState::Leave()
{
	if (!isActive)
		throw gcnew System::InvalidOperationException("Enter was not called");
	OnLeave();
	isActive = false;
}

void JoyConNative::BaseControlerState::SetHCIState(HCIState state)
{
	byte data[1];
	data[0] = (byte)state;
	byte rumble[8];
	this->controler->ExecuteSubCommand(0x06, data, rumble);
}

