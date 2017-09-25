#ifndef _MULTIPLESELECTIONSTATE_H
#define _MULTIPLESELECTIONSTATE_H
#include "MouseLButtonAction.h"

class MultipleSelectionState :public MouseLButtonAction {
public:
	static MouseLButtonAction* Instance();

	virtual void MouseLButtonUp(MouseLButton *mouseLButton, Diagram *diagram, Selection *selection, Long  startX, Long startY, Long currentX, Long currentY);
	virtual void MouseLButtonDown(MouseLButton *mouseLButton, Diagram *diagram, Selection *selection, Long  startX, Long startY, Long currentX, Long currentY);
	virtual void MouseLButtonDrag(MouseLButton *mouseLButton, Diagram *diagram, Selection *selection, Long  startX, Long startY, Long currentX, Long currentY, CPaintDC *cPatinDC);


protected:
	//DrawingClass();
private:
	static MultipleSelectionState* instance;
};

#endif // !_MULTIPLESELECTIONSTATE_H
