#include "winapiwrapper.h"
#include <Windows.h>

WinAPIWrapper::WinAPIWrapper()
{

}

void WinAPIWrapper::ShowSystemTray()
{
    //HWND hwnd=FindWindow((LPCTSTR)"Shell_TrayWnd", (LPCTSTR)"");
    HWND hwnd = FindWindow(L"Shell_TrayWnd", NULL);
    ShowWindow(hwnd, SW_SHOW);
}

void WinAPIWrapper::HideSystemTray()
{
    //HWND hwnd=FindWindow((LPCTSTR)"Shell_TrayWnd", (LPCTSTR)"");
    HWND hwnd = FindWindow(L"Shell_TrayWnd", NULL);
    ShowWindow(hwnd, SW_HIDE);

}

void WinAPIWrapper::clickControl(HWND hWnd, int x, int y)
{
    POINT p;
    p.x = x; p.y = y;
    ClientToScreen(hWnd, &p);
    SetCursorPos(p.x, p.y);
    PostMessage(hWnd, WM_MOUSEMOVE, 0, MAKELPARAM(x, y));
    PostMessage(hWnd, WM_LBUTTONDOWN, MK_LBUTTON, MAKELPARAM(x, y));
    PostMessage(hWnd, WM_LBUTTONUP, MK_LBUTTON, MAKELPARAM(x, y));
}


void WinAPIWrapper::ToggleSystemTray()
{
    // Find the Start button
    HDC hScreenDC = GetDC(0);
    DWORD height = GetDeviceCaps(hScreenDC, VERTRES);
    ReleaseDC(NULL, hScreenDC);
    HWND hTaskBarWnd = FindWindow(L"Shell_TrayWnd", NULL);
    HWND hStartButtonWnd = GetWindow(hTaskBarWnd, GW_CHILD);
    //ShowWindow(hStartButtonWnd,5);
   //  Now simulate a press on the Start button
    SendMessage(hStartButtonWnd, WM_LBUTTONDOWN,
          MK_LBUTTON, LOWORD(5) + HIWORD(height - 5));

    PostMessage(hStartButtonWnd, WM_LBUTTONUP, MK_LBUTTON, LOWORD(5) + HIWORD(height - 5));

  // clickControl(hStartButtonWnd,10,10);
  //  int HideCmd = 0;
//ShowWindow(FindWindow(L"DV2ControlHost",NULL), "Start Menu");//WIN7 WIN8
//ShowWindow(FindWindow(L"Windows.UI.Core.CoreWindow", L"Search"),ShowCmd);
}
