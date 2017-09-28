//EnterKey.h

#ifndef _ENTERKEY_H
#define _ENTERKEY_H

#include "KeyAction.h"

class TextEdit;
class ClassDIagrmForm;
class EnterKey : public KeyAction {
public:
	EnterKey();
	EnterKey(const EnterKey& source);
	virtual ~EnterKey();

	void KeyPress(TextEdit *textEdit);
	void KeyPress(ClassDiagramForm *classDiagramForm);
};

#endif // _ENTERKEY_H