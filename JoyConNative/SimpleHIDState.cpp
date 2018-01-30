#include "stdafx.h"
#include "SimpleHIDState.h"


using namespace JoyConNative;

SimpleHIDState::SimpleHIDState(JoyConNative::Controler^ controler) : BaseControlerState(controler)
{
}

void SimpleHIDState::OnEnter()
{
	throw gcnew System::NotImplementedException();
}

void SimpleHIDState::OnUpdate(System::TimeSpan & epelapsedTime)
{
	throw gcnew System::NotImplementedException();
}

void SimpleHIDState::OnLeave()
{
	throw gcnew System::NotImplementedException();
}
