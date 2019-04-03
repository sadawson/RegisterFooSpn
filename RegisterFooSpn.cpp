#include "pch.h"
#include <iostream>
#include <windows.h>
#include <NtDsAPI.h>

int main()
{
	DWORD status;
	LPCWSTR mySvcClass = L"foo";

	std::wcout << " [+] Attempting to register SPN using DsServerRegisterSpn with ServiceClass set to " << mySvcClass << "..." << std::endl;
	status = DsServerRegisterSpn(DS_SPN_ADD_SPN_OP, mySvcClass, NULL);
	std::wcout << "   [-] DsServerRegisterSpn to add SPN completed with " << status << " return code." << std::endl << std::endl;
	
	if (status)
		return EXIT_FAILURE;

	std::wcout << " [+] Attempting to deregister SPN using DsServerRegisterSpn with ServiceClass set to " << mySvcClass << "..." << std::endl;
	status = DsServerRegisterSpn(DS_SPN_DELETE_SPN_OP, mySvcClass, NULL);
	std::wcout << "   [-] DsServerRegisterSpn to remove SPN completed with " << status << " return code." << std::endl << std::endl;
	
	if (status)
		return EXIT_FAILURE;

	return EXIT_SUCCESS;
}
