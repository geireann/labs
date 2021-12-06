/**
 * @file Canvas2D.cpp
 *
 * CS123 2-dimensional canvas.
 *
 */

#include <assert.h>
#include <memory>
#include "Canvas2D.h"
#include "Settings.h"
#include <QCoreApplication>
#include "filter/Filter.h"
#include "filter/FilterGray.h"
#include "filter/FilterInvert.h"
#include "filter/FilterIdentity.h"
#include "filter/FilterShift.h"

#include <QPainter>

// For commenting
#include <iostream>
using namespace std;

Canvas2D::Canvas2D() {
    notifySizeChanged(width(), height());
}

Canvas2D::~Canvas2D()
{
}

void Canvas2D::filterImage() {
    // TODO: Task 1
    std::unique_ptr<Filter> filter;

    int filterType = settings.filterType;
    // TODO: Task 2
    switch(filterType){
        case 0:
            filter = std::make_unique<FilterInvert>();
            cout << filterType << ":" << "invert" << endl;
            break;
        case 1:
            filter = std::make_unique<FilterGray>();
            cout << filterType << ":" << "grayscale" << endl;
            break;
        case 2:
            filter = std::make_unique<FilterIdentity>();
            cout << filterType << ":" << "identity" << endl;
            break;
        case 3:
            filter = std::make_unique<FilterShift>(SHIFT_LEFT);
            cout << filterType << ":" << "shift left" << endl;
            break;
        case 4:
            filter = std::make_unique<FilterShift>(SHIFT_RIGHT);
            cout << filterType << ":" << "shift right" << endl;
            break;
        default:
            cout << filterType << endl;
            break;
    }


    // TODO: Task 3
    filter->apply(this);
    this->update();
}

void Canvas2D::paintEvent(QPaintEvent *e) {
    // You probably won't need to fill this in, but you can if you want to override any painting
    // events for the 2D canvas. For now, we simply call the superclass.
    SupportCanvas2D::paintEvent(e);
}
