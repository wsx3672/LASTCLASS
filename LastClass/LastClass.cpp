//LastClass.cpp

#include "LastClass.h"
#include "ClassDiagramForm.h"
#include "Menu.h"
#include "menuAction.h"
#include "Scroll.h"
#include "HistoryGraphic.h"

#include <afxdlgs.h>

using namespace std;

BEGIN_MESSAGE_MAP(LastClass, CFrameWnd)
	ON_WM_CREATE()
	ON_WM_KEYDOWN()
	ON_WM_SETFOCUS()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONDBLCLK()
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONUP()
	ON_WM_KILLFOCUS()
	ON_WM_CLOSE()
	ON_COMMAND_RANGE(100, 124, OnMyMenu)
	ON_WM_SIZE()
	ON_WM_VSCROLL()
	ON_WM_HSCROLL()
	ON_WM_MOUSEWHEEL()
END_MESSAGE_MAP()

LastClass::LastClass() {
	this->classDiagramForm = NULL;
	this->menu = NULL;
}

int LastClass::OnCreate(LPCREATESTRUCT lpCreateStruct) {
	CFrameWnd::OnCreate(lpCreateStruct); //�ڵ����� �������̵� //��ӿ���

	CRect rect;
	this->GetClientRect(&rect);
	this->classDiagramForm = new ClassDiagramForm;
	this->classDiagramForm->Create(NULL, "classDiagramForm", WS_CHILD | WS_BORDER | WS_VISIBLE | WS_VSCROLL | WS_HSCROLL, rect, this, 100000);

	this->menu = new Menu(this);

	return 0;
}

void LastClass::OnMyMenu(UINT parm_control_id) {

	MenuAction* menuAction = this->menu->MenuSelected(parm_control_id);
	if (menuAction != 0) {
		menuAction->MenuPress(this);
	}
}
void LastClass::OnKillFocus(CWnd *pNewWnd) {

}
void LastClass::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags) {
}

void LastClass::OnSetFocus(CWnd* pOldWnd) {
	CFrameWnd::OnSetFocus(pOldWnd);
	CWnd::SetFocus();
	Invalidate(false);
}

void LastClass::OnSize(UINT nType, int cx, int cy) {
	//this->SetWindowPos(this, 0, 0, cx, cy, SWP_NOMOVE | SWP_NOZORDER | SWP_NOREDRAW | SWP_NOCOPYBITS);
	CRect rect;
	this->GetClientRect(&rect);
	this->classDiagramForm->SetWindowPos(this, rect.left,rect.top,rect.right,rect.bottom, SWP_NOMOVE | SWP_NOZORDER );
	
	//this->classDiagramForm->Invalidate(false);
	//this->Invalidate(false);
}

BOOL LastClass::OnMouseWheel(UINT nFlags, short zDelta, CPoint pt) {
	return false;
}

void LastClass::OnLButtonDown(UINT nFlags, CPoint point) {
}

void LastClass::OnLButtonDblClk(UINT nFlags, CPoint point) {
}

void LastClass::OnLButtonUp(UINT nFlags, CPoint point) {
}

void LastClass::OnMouseMove(UINT nFlags, CPoint point) {
}

void LastClass::OnClose() {
	//6.2. ���̾�׷��� �����.
	int messageBox = IDNO;
	INT_PTR int_ptr = IDOK;
	if (this->classDiagramForm->historyGraphic->undoGraphicArray->GetLength() != 0) {
		if (this->classDiagramForm->fileName == "") {
			messageBox = MessageBox(_T("���� ������ ���� ������ �����Ͻðڽ��ϱ�?"), "ClassDiagram", MB_YESNOCANCEL);

			if (messageBox == IDYES) {
				CFileDialog  dlgFile(false, "txt", "*", OFN_CREATEPROMPT | OFN_OVERWRITEPROMPT, "�ؽ�Ʈ ����(*.txt)");
				int_ptr = dlgFile.DoModal();
				if (int_ptr == IDOK) {
					this->classDiagramForm->fileName = dlgFile.GetPathName();
					this->classDiagramForm->Save();
				}
				//else {
				//return;  //����
				//}
			}
		}
		else {
			CString object;
			object = "���泻���� ";
			object.Append(this->classDiagramForm->fileName);
			object.Append("�� �����Ͻðڽ��ϱ�?");
			messageBox = MessageBox(object, "ClassDiagram", MB_YESNOCANCEL);
			if (messageBox == IDYES) {
				this->classDiagramForm->Save();
			}
		}
	}
	//6.2. ���̾�׷��� �����.
	if (messageBox != IDCANCEL && int_ptr == IDOK) {//== IDYES || messageBox == IDNO ) {
		if (this->classDiagramForm != NULL) {
			this->classDiagramForm->OnClose();
		}
		if (this->menu != NULL) {
			delete this->menu;
		}
		CFrameWnd::OnClose(); // �������̵� �ڵ�����
	}
}