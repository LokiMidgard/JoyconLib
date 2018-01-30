#include "stdafx.h"

#include <windows.h>
#include <Setupapi.h>
#include <hidsdi.h>
#include <stdio.h>


#include "Controler.h"
#include "Manager.h"
#include "BaseControlerState.h"
#include "SimpleHIDState.h"

using namespace JoyConNative;

void JoyConNative::Controler::SetHCIState(HCIState state)
{
	controlerState->SetHCIState(state);
}

ControlerState Controler::State::get() {
	ControlerState result;
	return result;
}

Controler::Controler(HANDLE handle, String^ devicePath, ControlerType type, Manager^ parant)
{
	this->deviceHandle = handle;
	this->parant = parant;
	this->devicePath = devicePath;
	this->type = type;
	this->isDisposed = false;
	this->globalPackageCount = 0;
	this->controlerState = gcnew SimpleHIDState(this);
}

void JoyConNative::Controler::ExecuteSubCommand(byte command, byte data[], size_t dataLength, byte(&rumble)[8])
{
	if (isDisposed)
		return;
	byte buffer[49];
	memset(buffer, 0, sizeof(buffer));
	buffer[0] = 0x01;
	buffer[1] = globalPackageCount & 0xF;
	++globalPackageCount;

	memcpy(buffer + 2, rumble, sizeof(rumble));
	buffer[10] = command;
	memcpy_s(buffer + 11, sizeof(buffer) - 11, data, dataLength);
	DWORD readedData;
	if (!WriteFile(this->deviceHandle, buffer, sizeof(buffer), &readedData, NULL))
		throw gcnew System::IO::IOException("Some problem in writing to JoyCon", GetLastError());
}

Controler::~Controler()
{
	if (isDisposed)
		return;
	isDisposed = true;
	this->parant->RemoveControler(this);
	this->!Controler();
}

Controler::!Controler()
{
	CancelIo(deviceHandle);
	CloseHandle(deviceHandle);
}


