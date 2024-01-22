#pragma once
#include "Prerequisites.h"

class
Window {
public:
	Window();
	~Window();

	HRESULT
	init(HINSTANCE hInstance, int nCmdShow, WNDPROC wndproc);

	void 
	update();

	void
	render();

	void
	destroy();
public:
	HWND  m_hWnd = nullptr;
	unsigned int m_width;
	unsigned int m_height;

private:
	HINSTANCE m_hInst = nullptr;
	RECT m_rect;
	std::string m_windowName = "PLOPLO-Engine"; 
};