#ifndef QSS_H
#define QSS_H
#include <string>

using namespace std;

string hslider_qss = R"(
        QSlider
        {
            background-color: #FF0000;
            border-style: outset;
            border-radius: 1px;
        }

        QSlider::groove:horizontal
        {
            height: 12px;
            background: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 #B1B1B1, stop:1 #c4c4c4);
            margin: 2px 0
        }

        QSlider::handle:horizontal
        {
            background: QRadialGradient(cx:0, cy:0, radius: 1, fx:0.5, fy:0.5, stop:0 white, stop:1 green);
            width: 16px;
            height: 16px;
            margin: -5px 6px -5px 6px;
            border-radius:11px;
            border: 3px solid #ffffff;
        }
    )";
#endif // QSS_H
