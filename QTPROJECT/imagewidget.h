#ifndef IMAGEWIDGET_H
#define IMAGEWIDGET_H

#include <QWidget>

class imageWidget : public QWidget
{
    Q_OBJECT
public:
    explicit imageWidget(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent* event);

signals:

};

#endif // IMAGEWIDGET_H
