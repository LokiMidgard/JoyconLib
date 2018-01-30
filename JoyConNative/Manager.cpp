// Dies ist die Haupt-DLL.

#include "stdafx.h"


#include <windows.h>
#include <Setupapi.h>
#include <hidsdi.h>

#include "Controler.h"

#include "Manager.h"

using namespace JoyConNative;

System::Collections::Generic::List<JoyConNative::Controler^>^ Manager::ScanForDevices()
{
	auto result = gcnew System::Collections::Generic::List<Controler^>();

	GUID InterfaceClassGuid = { 0x4d1e55b2, 0xf16f, 0x11cf,{ 0x88, 0xcb, 0x00, 0x11, 0x11, 0x00, 0x00, 0x30 } };
	SP_DEVINFO_DATA deviceInfoData;
	SP_DEVICE_INTERFACE_DATA deviceInterfaceData;
	SP_DEVICE_INTERFACE_DETAIL_DATA *deviceInterfaceDetailData = NULL;
	HDEVINFO deviceInfos = INVALID_HANDLE_VALUE;

	memset(&deviceInfoData, 0x0, sizeof(deviceInfoData));
	deviceInfoData.cbSize = sizeof(SP_DEVINFO_DATA);
	deviceInterfaceData.cbSize = sizeof(SP_DEVICE_INTERFACE_DATA);

	try
	{
		deviceInfos = SetupDiGetClassDevs(&InterfaceClassGuid, NULL, NULL, DIGCF_PRESENT | DIGCF_DEVICEINTERFACE);

		// iterate over all HID devices
		for (int device_index = 0;; ++device_index) {
			try
			{
				DWORD required_size = 0;
				if (!SetupDiEnumDeviceInterfaces(deviceInfos, NULL, &InterfaceClassGuid, device_index, &deviceInterfaceData))
					break; // No more devices

			    // Get the size of the struct
				SetupDiGetDeviceInterfaceDetail(deviceInfos, &deviceInterfaceData, NULL, 0, &required_size, NULL);

				// Alocate the buffer
				deviceInterfaceDetailData = (SP_DEVICE_INTERFACE_DETAIL_DATA*)malloc(required_size);
				deviceInterfaceDetailData->cbSize = sizeof(SP_DEVICE_INTERFACE_DETAIL_DATA);

				// Get the device path
				if (!SetupDiGetDeviceInterfaceDetail(deviceInfos, &deviceInterfaceData, deviceInterfaceDetailData, required_size, NULL, NULL))
					continue; // next here we go.

				if (!deviceInterfaceDetailData->DevicePath)
					continue; // ignore devices without path.

				//Only devices of class "HIDClass" are interresting
				bool found = false;
				for (int i = 0; ; i++) {
					WCHAR driver_name[256];

					if (!SetupDiEnumDeviceInfo(deviceInfos, i, &deviceInfoData))
						break; // no mor interfaces

					if (!SetupDiGetDeviceRegistryProperty(deviceInfos, &deviceInfoData, SPDRP_CLASS, NULL, (PBYTE)driver_name, sizeof(driver_name), NULL))
						break;

					// check for HIDClass
					if (lstrcmpW(driver_name, L"HIDClass") == 0) {
						if (SetupDiGetDeviceRegistryProperty(deviceInfos, &deviceInfoData, SPDRP_DRIVER, NULL, (PBYTE)driver_name, sizeof(driver_name), NULL)) {
							found = true;
							break;
						}
					}
				}
				if (!found)
					continue; // no luck, next time.

				const WCHAR *path;
				path = deviceInterfaceDetailData->DevicePath;
				// check if we alrady have opend the same device
				for each (auto containedString in this->devicePathes)
					if (this->CompareStrings(containedString, path) == 0)
						continue;

				// open the device
				HANDLE handle = INVALID_HANDLE_VALUE;
				handle = OpenDevice(path);

				if (handle == INVALID_HANDLE_VALUE) {
					continue; // can't opeb => next one
				}

				// Check for the Vendor and Product ID's
				HIDD_ATTRIBUTES attributes;
				attributes.Size = sizeof(HIDD_ATTRIBUTES);
				HidD_GetAttributes(handle, &attributes);

				if (attributes.VendorID != VENDOR_ID_NINTENDO
					|| (attributes.ProductID != PRODUCT_ID_JOY_CON_LEFT
						&& attributes.ProductID != PRODUCT_ID_JOY_CON_RIGHT
						&& attributes.ProductID != PRODUCT_ID_PRO_CONTROLER)) {
					CloseHandle(handle);
					continue; // No JoyCon
				}

				// store the device path
				String^ managedPath = gcnew String(path);
				this->devicePathes.Add(managedPath);

				// generate controler and add it to the new found controler.
				auto x = gcnew Controler(handle, managedPath, (ControlerType)attributes.ProductID, this);
				result->Add(x);
			}
			finally
			{
				if (deviceInterfaceDetailData != NULL)
					free(deviceInterfaceDetailData);
				deviceInterfaceDetailData = NULL;
			}
		}
	}
	finally
	{
		if (deviceInfos != INVALID_HANDLE_VALUE)
			SetupDiDestroyDeviceInfoList(deviceInfos);
	}
	return result;
}


void Manager::RemoveControler(Controler^ toRemove)
{
	this->devicePathes.Remove(toRemove->devicePath);
}

bool Manager::CompareStrings(String^ s1, const WCHAR* str) {
	for (int i = 0; i < s1->Length; i++)
	{
		if (s1[i] != str[i]) {
			return false;
		}
		if (s1[i] == '\0') {
			return true;
		}
	}
	if (str[s1->Length] == '\0')
		return true;
	return false;
}

HANDLE Manager::OpenDevice(const WCHAR *path)
{
	HANDLE handle;
	handle = CreateFile(path, GENERIC_WRITE | GENERIC_READ, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0  /*| FILE_FLAG_OVERLAPPED*/, 0);
	return handle;
}
