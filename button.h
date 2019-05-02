#ifndef GRAPHICS_STARTER_BUTTON_H
#define GRAPHICS_STARTER_BUTTON_H

#include <string>
#include <functional>
#include "quad.h"
#include "graphics.h"

class Button {
private:
    /* Assume Quad includes color, center, width, height */
    Quad box;
    std::string label;
    color originalFill, hoverFill, pressFill;

public:
    int numDisks;
    Button(Quad box, std::string label);
    Button(Quad box, std::string label,int numDisks);
    /* Uses OpenGL to draw the box with the label on top */
    virtual void draw();

    /* Returns true if the coordinate is inside the box */
    bool isOverlapping(int x, int y) const;

    /* Change color of the box when the user is hovering over it */
    void hover();

    /* Change color of the box when the user is clicking on it */
    void pressDown();

    /* Change the color back when the user is not clicking/hovering */
    void release();

    /* Execute whatever the Button is supposed to do */
    virtual void click(std::function<void()> callback);
};


#endif //GRAPHICS_STARTER_BUTTON_H
