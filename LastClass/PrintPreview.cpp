//PrintPreview.cpp

#include "PrintPreview.h"
#include "LastClass.h"
#include "ClassDiagramForm.h"
#include "DrawingVisitor.h"
#include "WritingVisitor.h"
#include "Diagram.h"
#include "PrintPreviewState.h"
#include <afxwin.h>
#include <afxdlgs.h>
#include <afxpriv.h>
using namespace std;

BEGIN_MESSAGE_MAP(PrintPreview,CWnd)
	ON_WM_CREATE()
	ON_WM_PAINT()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_CLOSE()
	ON_BN_CLICKED(1,OnNextButton)
	ON_BN_CLICKED(2, OnPriviousButton)
	ON_BN_CLICKED(3, OnPrintButton)
END_MESSAGE_MAP()
PrintPreview::PrintPreview(LastClass *lastClass) {
	this->lastClass = lastClass;
	this->nextButton = NULL;
	this->priviousButton = NULL;
	this->printButton = NULL;
	this->horizontalPage = 0;
	this->verticalPage = 0;
}
int PrintPreview::OnCreate(LPCREATESTRUCT lpCreateStruct) {
	CWnd::OnCreate(lpCreateStruct);
	this->ModifyStyle(0, WS_OVERLAPPEDWINDOW);
	this->nextButton = new CButton;
	this->nextButton->Create("����", WS_CHILD|WS_VISIBLE|BS_PUSHBUTTON|BS_CENTER|BS_VCENTER,CRect(800,200,880,240), this, 1);
	this->priviousButton = new CButton;
	this->priviousButton->Create("����", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON | BS_CENTER | BS_VCENTER, CRect(800, 250, 880, 290), this, 2);
	this->printButton = new CButton;
	this->printButton->Create("�μ�", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON | BS_CENTER | BS_VCENTER, CRect(800, 300, 880, 340), this, 3);
	
	this->SetWindowPos(&wndTopMost, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE );
	this->SetFocus();
	this->lastClass->classDiagramForm->EnableWindow(false);
	this->OnFilePrintPreview();
	Invalidate();

	//this->OnFilePrintPreview();
	//this->OnFilePrintPreview();
	return 0;
}
void PrintPreview::OnFilePrintPreview() {/*
	CPrintPreviewState *pState = new CPrintPreviewState;

	if (!DoPrintPreview(AFX_IDD_PREVIEW_TOOLBAR, this, RUNTIME_CLASS(PrintPreviewState), pState)) {
		TRACE0("Error: DoPrintPreView failed");
		AfxMessageBox(AFX_IDP_COMMAND_FAILURE); 
		delete pState;
	}
	*/
	
}
BOOL PrintPreview::OnPreparePrinting(CPrintInfo *pInfo) {/*
	BOOL ret = CView::OnPreparePrinting(pInfo);
		return ret;*/
	return true;
}
void PrintPreview::OnPaint() {
	
	CPaintDC dc(this);
	CRect rec;
	this->GetClientRect(&rec);
	CDC memDC;
	CBitmap *pOldBitmap;
	CBitmap bitmap;
	
	memDC.CreateCompatibleDC(&dc);
	bitmap.CreateCompatibleBitmap(&dc, 4000, 2000);
	pOldBitmap = memDC.SelectObject(&bitmap);
	memDC.FillSolidRect(CRect(0, 0, 4000, 2000), RGB(255, 255, 255));
	CFont cFont;//CreateFont�� ��18�� textEdit�� rowHight�� �ٲ����
	cFont.CreateFont(25, 0, 0, 0, FW_BOLD, FALSE, FALSE, 0, DEFAULT_CHARSET,// �۲� ����
		OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_SWISS, "���� ����");
	SetFont(&cFont, TRUE);
	CFont *oldFont = memDC.SelectObject(&cFont);
	DrawingVisitor drawingVisitor;
	this->lastClass->classDiagramForm->diagram->Accept(drawingVisitor, &memDC);
	WritingVisitor writingVisitor;
	this->lastClass->classDiagramForm->diagram->Accept(writingVisitor, &memDC);

	dc.FillSolidRect(rec, RGB(153,153,153));
	dc.StretchBlt(10, 10, 600, 800, &memDC, (this->horizontalPage * 800), (this->verticalPage * 1000), 800,1000, SRCCOPY);

	memDC.SelectObject(oldFont);
	cFont.DeleteObject();
	memDC.SelectObject(pOldBitmap);
	bitmap.DeleteObject();
	memDC.DeleteDC();
	
}
void PrintPreview::OnDraw(CDC *cdc) {

}
void PrintPreview::OnPrint(CDC *cdc, CPrintInfo *pInfo, UINT page) {
	Long i[10] = { 0,2000,800,800,1600,1600,2400,2400,3200,3200 };
	Long j[10] = { 0,0,0,1000,0,1000,0,1000,0,1000 };
	Long k = page - 1;

	Long width = pInfo->m_rectDraw.Width();
	Long hegiht = pInfo->m_rectDraw.Height();
	CDC memDC;
	CRect rect;
	this->lastClass->classDiagramForm->GetClientRect(&rect);
	CBitmap *pOldBitmap;
	CBitmap bitmap;

	CPaintDC dc(this);

	memDC.CreateCompatibleDC(&dc);
	bitmap.CreateCompatibleBitmap(&dc, 4000, 2000);
	pOldBitmap = memDC.SelectObject(&bitmap);
	memDC.FillSolidRect(CRect(0, 0, 4000, 2000), RGB(255, 255, 255));
	CFont cFont;//CreateFont�� ��18�� textEdit�� rowHight�� �ٲ����
	cFont.CreateFont(25, 0, 0, 0, FW_BOLD, FALSE, FALSE, 0, DEFAULT_CHARSET,// �۲� ����
		OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_SWISS, "���� ����");
	SetFont(&cFont, TRUE);
	CFont *oldFont = memDC.SelectObject(&cFont);

	DrawingVisitor drawingVisitor;
	this->lastClass->classDiagramForm->diagram->Accept(drawingVisitor, &memDC);
	WritingVisitor writingVisitor;
	this->lastClass->classDiagramForm->diagram->Accept(writingVisitor, &memDC);


	CBitmap *pOldBitmapOne;
	CBitmap bitmapOne;
	CDC memDCOne;
	memDCOne.CreateCompatibleDC(&dc);
	bitmapOne.CreateCompatibleBitmap(&dc, 2000, 2000);
	pOldBitmapOne = memDCOne.SelectObject(&bitmapOne);
	memDCOne.FillSolidRect(CRect(0, 0, 2000, 2000), RGB(255, 255, 255));
	memDCOne.BitBlt(0, 0, 2000, 2000, &memDC, i[k], j[k], SRCCOPY);

	int mapMode = cdc->GetMapMode();
	memDCOne.SetMapMode(mapMode);
	cdc->SetStretchBltMode(COLORONCOLOR);

	cdc->StretchBlt(100, 100, width - 200, hegiht - 200, &memDCOne, 0, 0, 2000, 2000, SRCCOPY);

}
void PrintPreview::OnClose() {
	this->lastClass->classDiagramForm->EnableWindow(true);
	if (this->nextButton != 0) {
		delete this->nextButton;
	}
	if (this->printButton != 0) {
		delete this->printButton;
	}
	if (this->priviousButton != 0) {
		delete this->priviousButton;
	}
	if (this != 0) {
		delete this;
	}
}

void PrintPreview::OnNextButton() {
	this->verticalPage++;
	if (this->verticalPage > 1) {
		this->horizontalPage++;
		this->verticalPage = 0;
	}
	if (this->horizontalPage > 4) {
		this->horizontalPage = 4;
		this->verticalPage = 1;
	}
	//RedrawWindow();
	Invalidate(false);
}
void PrintPreview::OnPriviousButton() {
	this->verticalPage--;
	if (this->verticalPage < 0) {
		this->horizontalPage--;
		this->verticalPage = 1;
	}
	if (this->horizontalPage < 0) {
		this->horizontalPage = 0;
		this->verticalPage = 0;
	}
	//RedrawWindow();
	Invalidate(false);
}
void PrintPreview::OnBeginPrinting(CDC *pDc, CPrintInfo *pInfo) {

}

void PrintPreview::OnEndPrinting(CDC *pDc, CPrintInfo *pInfo) {

}
void PrintPreview::OnPrintButton() {
	CPrintDialog printDialog(false);
	if (printDialog.DoModal() != IDCANCEL) {
		CDC dc;
		dc.Attach(printDialog.GetPrinterDC());
		dc.m_bPrinting = TRUE;

		CString strTitle;
		strTitle.LoadString(AFX_IDS_APP_TITLE);
		DOCINFO di;
		ZeroMemory(&di, sizeof(DOCINFO));
		di.cbSize = sizeof(DOCINFO);
		di.lpszDocName = strTitle;

		BOOL bPrintingOK = dc.StartDoc(&di);

		CPrintInfo Info;
		Info.m_rectDraw.SetRect(0, 0, dc.GetDeviceCaps(HORZRES),dc.GetDeviceCaps(VERTRES));
		Info.SetMaxPage(2);
		OnBeginPrinting(&dc, &Info);
		for (UINT page = Info.GetMinPage(); page <= Info.GetMaxPage() && bPrintingOK; page++) {
			dc.StartPage();
			Info.m_nCurPage = page;
			this->OnPrint(&dc,&Info,page);

			bPrintingOK = (dc.EndPage() > 0);

		}
		this->OnEndPrinting(&dc, &Info);
		if (bPrintingOK) dc.EndDoc();
		else dc.AbortDoc();

		dc.Detach();
	}














//		DeleteDC(hDC);
//	}
//}
//	dlg.DoModal();
//	CDC dc;
//	if (dc.Attach(dlg.CreatePrinterDC())) {
//		DOCINFO info;
//
//		memset(&info, 0, sizeof(DOCINFO));
//		info.cbSize = sizeof(DOCINFO);
//		dc.StartDoc(&info);
//		dc.StartPage();
//		
//		CFont cFont;//CreateFont�� ��18�� textEdit�� rowHight�� �ٲ����
//		cFont.CreateFont(25, 0, 0, 0, FW_BOLD, FALSE, FALSE, 0, DEFAULT_CHARSET,// �۲� ����
//			OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_SWISS, "���� ����");
//		SetFont(&cFont, TRUE);
//		CFont *oldFont = dc.SelectObject(&cFont);
//
//		DrawingVisitor drawingVisitor;
//		this->lastClass->classDiagramForm->diagram->Accept(drawingVisitor, &dc);
//		WritingVisitor writingVisitor;
//		this->lastClass->classDiagramForm->diagram->Accept(writingVisitor, &dc);
//		dc.EndPage();
//		dc.EndDoc();
//		dc.DeleteDC();
//	}
//}
//	dlg.DoModal();
//	
//	CDC dc;
//	CPaintDC dcp(this);
//	if (dc.Attach(dlg.CreatePrinterDC())) {
//		DOCINFO info;
//		memset(&info, 0, sizeof(DOCINFO));
//		info.cbSize = sizeof(DOCINFO);
//		dc.StartDoc(&info);
//		//dc.StartPage();
//
//		HDC hDC = dlg.GetPrinterDC();
//		int nPageWidth = GetDeviceCaps(hDC, HORZRES);
//		int nPageHeight = GetDeviceCaps(hDC, VERTRES);
//
//
//		CDC memDC;
//		CRect rect;
//		this->lastClass->classDiagramForm->GetClientRect(&rect);
//		CBitmap *pOldBitmap;
//		CBitmap bitmap;
//		memDC.CreateCompatibleDC(&dcp);
//		bitmap.CreateCompatibleBitmap(&dcp, 4000, 2000);
//		pOldBitmap = memDC.SelectObject(&bitmap);
//		memDC.FillSolidRect(CRect(0, 0, 4000, 2000), RGB(255, 255, 255));
//		CFont cFont;//CreateFont�� ��18�� textEdit�� rowHight�� �ٲ����
//		cFont.CreateFont(25, 0, 0, 0, FW_BOLD, FALSE, FALSE, 0, DEFAULT_CHARSET,// �۲� ����
//			OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_SWISS, "���� ����");
//		SetFont(&cFont, TRUE);
//		CFont *oldFont = memDC.SelectObject(&cFont);
//
//		DrawingVisitor drawingVisitor;
//		this->lastClass->classDiagramForm->diagram->Accept(drawingVisitor, &memDC);
//		WritingVisitor writingVisitor;
//		this->lastClass->classDiagramForm->diagram->Accept(writingVisitor, &memDC);
//		
//		Long i = 0;
//		while (i < 5) {
//			dc.StartPage();
//			int mapMode = dc.GetMapMode();
//			memDC.SetMapMode(mapMode);
//			dc.SetStretchBltMode(HALFTONE);
//			
//			//dc.BitBlt(0, 0, nPageWidth, nPageHeight, &memDC,0, 0, SRCCOPY);
//			//dc.StretchBlt(0, 0, nPageWidth, nPageHeight, &memDC, 0,0, i * 400, i * 200, SRCCOPY);
//			dc.StretchBlt(0, 0,0,0, &memDC,i*400,i*200, (i*400) - nPageWidth, (i*200) - nPageHeight, SRCCOPY);
//			//::RestoreDC(dc,-1);
//			dc.EndPage();
//			i++;
//		}
//		memDC.SelectObject(oldFont);
//		cFont.DeleteObject();
//		memDC.SelectObject(pOldBitmap);
//		bitmap.DeleteObject();
//		memDC.DeleteDC();
//		//dc.EndPage();
//
//		dc.EndDoc();
//
//		dc.DeleteDC();
//
//	}
}