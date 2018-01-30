// JoyConNative.h

#pragma once

#include "ForwardDeclarations.h"

using namespace System;

namespace JoyConNative {

	public ref class Manager
	{
		// TODO: Die Methoden für diese Klasse hier hinzufügen.
	public:
		System::Collections::Generic::List<JoyConNative::Controler^>^ ScanForDevices();

	internal:
		void RemoveControler(Controler^ toRemove);

	private:
		System::Collections::Generic::List<String^> devicePathes;

		static bool CompareStrings(String ^ s1, const WCHAR * str);
		static HANDLE OpenDevice(const WCHAR *path);


	};
}
