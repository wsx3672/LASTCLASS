//CtrlEnterKey.h

#ifndef _CTRLENTERKEY_H
#define _CTRLENTERKEY_H

#include "KeyAction.h"

class TextEdit;
class ClassDiagramForm;
class CtrlEnterKey : public KeyAction {
public:
	CtrlEnterKey();
	CtrlEnterKey(const CtrlEnterKey& source);
	virtual ~CtrlEnterKey();

	void KeyPress(TextEdit *textEdit);
	void KeyPress(ClassDiagramForm *classDiagramForm);
};


#endif // _CTRLENTERKEY_H