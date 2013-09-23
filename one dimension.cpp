// first.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include "first.h"
#include "Resource.h"

int APIENTRY _tWinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPTSTR    lpCmdLine,
                     int       nCmdShow)
{
	InitCommonControls();
	DialogBox(hInstance,MAKEINTRESOURCE(IDD_Main),NULL,NULL);
	return 0; 
}
