#pragma once
#include <UIlib.h>
#include "Menu.h"

using namespace DuiLib;

class MainWindow : public WindowImplBase
{
public:

	LPCTSTR GetWindowClassName() const;
	CDuiString GetSkinFile();
	CDuiString GetSkinFolder();

	void Notify(TNotifyUI& msg);
	LRESULT HandleMessage(UINT uMsg, WPARAM wParam, LPARAM lParam);
	LRESULT HandleCustomMessage(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
	LRESULT OnCreate(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
	LRESULT OnClose(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
	LRESULT OnTimer(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);

	void FlushData();

private:
	CHorizontalLayoutUI* pMainOptemp;
	CHorizontalLayoutUI* pMainOpcpu;
	CHorizontalLayoutUI* pMainOpbox;
	Menu*	m_pMenu = nullptr;
};

