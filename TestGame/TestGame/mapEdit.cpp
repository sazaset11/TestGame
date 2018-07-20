#include "stdafx.h"
#include "tge.h"
#include "tge_sprite.h"
#include "maptool_struct.h"
#include "gameObject.h"

enum { MODE_BRUSH_DRAW = 0, MODE_CMD_INPUT = 1, MODE_BRUSH_MOVE = 2, MODE_MOUSE_DRAW = 3 };

int main() {
	HANDLE hdout = GetStdHandle(STD_OUTPUT_HANDLE);
	HANDLE hdin = GetStdHandle(STD_INPUT_HANDLE);
	DWORD fdwOldMode;
	S_TGE_MAPTOOL g_MapToolObject;
	int nW = 8;
	int nH = 4;
	int FSM = MODE_BRUSH_DRAW;
	static char szCmdBuf[32];
	static DWORD cNumRead;
	static INPUT_RECORD irInputBuf[128];
	bool _loop = true;

	CHAR_INFO *pBuf = (CHAR_INFO*)malloc(nW*nH * sizeof(CHAR_INFO));
	initMapTool(&g_MapToolObject);

	GetConsoleMode(hdin, &fdwOldMode);
	SetConsoleMode(hdin, ENABLE_EXTENDED_FLAGS | ENABLE_WINDOW_INPUT | ENABLE_MOUSE_INPUT);
	TGE::clearScreenBuffer(0x2e, 0x0007);

	while (_loop) {
		TGE::updateBuffer(hdout, TGE::g_chiBuffer);
		TGE::setCursor(hdout, 0, 0);
		TGE::setCursor(hdout, 0, 25);
		switch (FSM)
		{
		case MODE_BRUSH_DRAW:
			ReadConsoleInput(hdin, irInputBuf, 128, &cNumRead);
			for (DWORD i = 0; i < cNumRead; i++) {
				if (irInputBuf[i].EventType == KEY_EVENT) {
					if (irInputBuf[i].Event.KeyEvent.bKeyDown) {
						switch (irInputBuf[i].Event.KeyEvent.wVirtualKeyCode)
						{
						case 13:
							SetConsoleMode(hdin, fdwOldMode);
							FSM = MODE_CMD_INPUT;
							break;
						default:
							break;
						}
					}
				}
				else if (irInputBuf[i].EventType == MOUSE_EVENT) {
					if (irInputBuf[i].Event.MouseEvent.dwButtonState == 1) {
						int _posx = irInputBuf->Event.MouseEvent.dwMousePosition.X;
						int _posy = irInputBuf->Event.MouseEvent.dwMousePosition.Y;
						sprintf_s(szCmdBuf, 32, "set %d %d %x %x", _posx, _posy, g_MapToolObject.m_wcCurrentBrushCode, g_MapToolObject.m_wCurrentBrushAttr);
						g_MapToolObject.m_cdCurrentCursorPos.X = _posx;
						g_MapToolObject.m_cdCurrentCursorPos.Y = _posy;
					}
				}
			}
			break;
		case MODE_CMD_INPUT:
			//스크립트 입력처리
			printf("						]");
			TGE::setCursor(hdout, 0, 25);
			printf("[cmd > ");
			gets_s(szCmdBuf, sizeof(szCmdBuf));
			SetConsoleMode(hdin, ENABLE_EXTENDED_FLAGS | ENABLE_WINDOW_INPUT | ENABLE_MOUSE_INPUT);
			FSM = MODE_BRUSH_DRAW;

			break;
		default:
			break;
		}
		if (!parseCmd(&g_MapToolObject, szCmdBuf)) return 0;
	}

	return 0;
}