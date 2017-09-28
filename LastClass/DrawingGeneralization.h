#ifndef _DRAWINGGENERALIZATION_H
#define _DRAWINGGENERALIZATION_H
#include "MouseLButtonAction.h"

class DrawingGeneralization :public MouseLButtonAction {
public:
	static MouseLButtonAction* Instance();

	virtual void MouseLButtonUp(MouseLButton *mouseLButton, Diagram *diagram, Selection *selection, Long  startX, Long startY, Long currentX, Long currentY);
	virtual void MouseLButtonDown(MouseLButton *mouseLButton, Diagram *diagram, Selection *selection, Long  startX, Long startY, Long currentX, Long currentY);
	virtual void MouseLButtonDrag(MouseLButton *mouseLButton, Diagram *diagram, Selection *selection, Long  startX, Long startY, Long currentX, Long currentY, CDC *cPatinDC);


protected:
	//DrawingClass();
private:
	static DrawingGeneralization* instance;
};

#endif // !_DRAWINGGENERALIZATION_H

