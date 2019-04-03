#include <iostream>
#include <windows.h>
#include <filesystem>
#include "locale.h"
using namespace std;



int main() {
	setlocale(0, "rus");
	cout << "Lab1" << endl;

	int n;
	char dd[4];
	DWORD dr = GetLogicalDrives();
	int d;
	bool Flag;

	for (int i = 0; i < 26; i++)
	{
		n = ((dr >> i) & 0x00000001);
		if (n == 1)
		{
			dd[0] = char(65 + i); dd[1] = ':'; dd[2] = '\\'; dd[3] = 0;
			cout << "Available disk drives : " << dd << endl;


			d = GetDriveType(dd);
			if (d == DRIVE_UNKNOWN) cout << " UNKNOWN" << endl;
			if (d == DRIVE_NO_ROOT_DIR) cout << " DRIVE NO ROOT DIR" << endl;
			if (d == DRIVE_REMOVABLE) cout << " REMOVABLE" << endl;
			if (d == DRIVE_FIXED) cout << " Fixed disk" << endl;
			if (d == DRIVE_REMOTE) cout << " REMOTE" << endl;
			if (d == DRIVE_CDROM) cout << " CDROM" << endl;
			if (d == DRIVE_RAMDISK) cout << " RAMDISK" << endl;

			if (d == DRIVE_FIXED) {
				unsigned __int64 FreeBytesAvailable;
				unsigned __int64 TotalNumberOfBytes;
				unsigned __int64 TotalNumberOfFreeBytes;
				char drive_label[30];
				char drive_fat[30];
				DWORD drive_sn;
				DWORD drive_name_size = sizeof(drive_label);

				Flag = GetVolumeInformation(dd,
					drive_label,
					sizeof(drive_label),
					&drive_sn,
					&drive_name_size,
					NULL,
					drive_fat,
					sizeof(drive_fat)
				);

				cout << drive_sn << endl;
		
			}
		}
	}
	
	return 0;
}