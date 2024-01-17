#include "imagewidget.h"
#include <QPainter>

imageWidget::imageWidget(QWidget *parent)
    : QWidget{parent}
{

}

void imageWidget::paintEvent(QPaintEvent* event)
{
    QPainter painter(this);

    painter.fillRect(rect(), Qt::white);

    int circleRadius = 100;
    int centerX = width() / 2;
    int centerY = height() / 2;
    painter.setBrush(Qt::darkGreen);
    painter.setPen(Qt::NoPen);
    painter.drawEllipse(centerX - circleRadius, centerY - circleRadius,
                        2 * circleRadius, 2 * circleRadius);

    // Draw the inscription "Starbucks"
    QFont font("Arial", 20, QFont::Bold);
    painter.setFont(font);
    painter.setPen(Qt::white);
    painter.drawText(rect(), Qt::AlignCenter, "Starbucks Plus");
}
