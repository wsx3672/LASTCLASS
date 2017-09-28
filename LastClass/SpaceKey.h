//SpaceKey.h

#ifndef _SPACEKEY_H
#define _SPACEKEY_H

#include "KeyAction.h"

class TextEdit;
class ClassDiagremForm;
class SpaceKey : public KeyAction {
public:
	SpaceKey();
	SpaceKey(const SpaceKey& source);
	virtual ~SpaceKey();

	void KeyPress(TextEdit *textEdit);
	void KeyPress(ClassDiagramForm *classDiagramForm);
};

#endif // _SPACEKEY_H