#pragma once

#include "ForwardDeclarations.h"
#include "ControlerType.h"
#include "HCIState.h"

using namespace System;

namespace JoyConNative {

	public ref class Controler
	{
	public:
		virtual ~Controler();
		!Controler();

		property ControlerType Type {
			ControlerType get() {
				return type;
			}
		}

		void SetHCIState(HCIState state);


	internal:
		Controler(HANDLE handle, String^ devicePath, ControlerType type, Manager^ parant);
		initonly String^ devicePath;

		void ExecuteSubCommand(byte command, byte data[], size_t length, byte (&rumble)[8]);
		
		template<size_t N>
		void ExecuteSubCommand(byte command, byte(&data)[N], byte(&rumble)[8]) {
			this->ExecuteSubCommand(command, data, N, rumble);
		}

	private:
		initonly HANDLE deviceHandle;
		initonly Manager^ parant;
		initonly ControlerType type;
		bool isDisposed;
		byte globalPackageCount;
		BaseControlerState^ controlerState;
	};



}