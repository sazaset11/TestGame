#pragma once

struct S_TGE_MAPTOOL {
	COORD m_cdCurrentCursorPos;
	WCHAR m_wcCurrentBrushCode;
	WORD m_wCurrentBrushAttr;
	int m_wCurrentCursorSizeX;
	int m_wCurrentCursorSizeY;
};

void initMapTool(S_TGE_MAPTOOL*);
int parseCmd(S_TGE_MAPTOOL*, char*);