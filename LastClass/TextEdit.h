//TextEdit.h

#ifndef _TEXTEDIT_H
#define _TEXTEDIT_H

#include <afxwin.h>
#include <imm.h>
#include "ClassDiagramForm.h"

typedef signed long int Long;

class Caret;
class Row;
class TextEdit : public CFrameWnd {
public:
	TextEdit(ClassDiagramForm *classDiagramForm, Long startX, Long startY, Long width, Long height);
public:
	//Long Save();
	//Long Load();
protected:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnPaint();
	afx_msg void OnChar(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnKillFocus(CWnd *pNewWnd);
	afx_msg Long OnComposition(WPARAM wParam, LPARAM lParam);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDoubleClicked(UINT nFlags, CPoint point);
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg LRESULT OnIMENotify(WPARAM wParam,LPARAM lParam);
	afx_msg void OnClose();
	DECLARE_MESSAGE_MAP()
public:
	Long GetWidth() const;
	Long GetHeight() const;
	Long GetRowIndex() const;
	Long GetCharacterIndex() const;
	Long GetStartX() const;
	Long GetStartY() const;
	Long GetRowHeight() const;
	Long GetKoreanEnglish() const;
public:
	ClassDiagramForm *classDiagramForm;
	Caret *caret;
private:
	Long width;
	Long height;
	Long rowIndex;
	Long characterIndex;
	Long startX;
	Long startY;
	Row*(*indexes);
	Long count;
	Long koreanEnglish;
	Long rowHeight;
	Long flagBuffer;
	Long flagInsert;
};

inline Long TextEdit::GetWidth() const {
	return this->width;
}
inline Long TextEdit::GetHeight() const {
	return this->height;
}
inline Long TextEdit::GetRowIndex() const {
	return this->rowIndex;
}
inline Long TextEdit::GetCharacterIndex() const {
	return this->characterIndex;
}
inline Long TextEdit::GetStartX() const {
	return this->startX;
}
inline Long TextEdit::GetStartY() const {
	return this->startY;
}
inline Long TextEdit::GetRowHeight() const {
	return this->rowHeight;
}
inline Long TextEdit::GetKoreanEnglish() const {
	return this->koreanEnglish;
}

#endif // _TEXTEDIT_H