 /*
 I was tasked with turning a bunch of LG TVs on and off for a digital signage project,
 so I wrote a little C program with some borrowed code from LinuxMCE. 
 Compiled in Windows with dev-c++. 
 I then set up batch files to turn the tvs on and off whenever the client wants. 
 The RS232 codes for any specific model can be found on LG's website. 
 You can change and interact with numerous settings on an LG TV.
*/

#define _CRT_SECURE_NO_WARNINGS
#include "stdafx.h"
#include "windows.h"
#include "iostream"

using namespace std;

DWORD iBytesWritten;
DCB dcb;
int i;
char szBuf[1024];
HANDLE hCom;

int _tmain(int argc, _TCHAR* argv[])
{
 hCom = CreateFile ( "com1", GENERIC_WRITE, 0, NULL, OPEN_EXISTING, 0, NULL);
 for ( i = 1; i <= 3; i++ )
  {
   if ( !argv[i] )
    {
     cout << "syntax error." << endl;
     cout << "syntax is: " << argv[0] << " " << endl;
     return 0;
    }
  }
  dcb.DCBlength = sizeof(DCB);
  GetCommState (hCom, &dcb);
  dcb.BaudRate = 9600;
  dcb.ByteSize = 8;
  dcb.Parity = NOPARITY;
  dcb.StopBits = ONESTOPBIT;
  SetCommState (hCom, &dcb);

  sprintf(szBuf, "%s %s %s\r", argv[1], argv[2], argv[3]);
  WriteFile (hCom, szBuf, strlen(szBuf), &iBytesWritten, NULL);


  CloseHandle (hCom);

  cout << "" << endl;
  cout << "-------------------" << endl;
  cout << "Code Sent." << endl;
  cout << "-------------------" << endl;

return 0;
} 
