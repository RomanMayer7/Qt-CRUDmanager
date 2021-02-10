#ifndef WINAPIWRAPPER_H
#define WINAPIWRAPPER_H
#include <Windows.h>


class WinAPIWrapper
{
public:
    WinAPIWrapper();
    void ShowSystemTray();
    void HideSystemTray();
    void clickControl(HWND hWnd, int x, int y);
    void ToggleSystemTray();
};

#endif // WINAPIWRAPPER_H
