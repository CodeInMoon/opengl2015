#include "Global.h"

QWndApp* g_pWndApp = NULL; // ��ʼ��Ϊnull
extern QWndApp * GlbGetApp()
{
	return g_pWndApp;
}
