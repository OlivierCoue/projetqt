#ifndef VISUALIZESTAFFWIDGET_H
#define VISUALIZESTAFFWIDGET_H

#include <QWidget>

#include "daostaff.h"

namespace Ui {
class VisualizeStaffWidget;
}

class VisualizeStaffWidget : public QWidget
{
    Q_OBJECT

public:
    explicit VisualizeStaffWidget(QWidget *parent = 0);
    ~VisualizeStaffWidget();

    void updateTreeView();

private:
    Ui::VisualizeStaffWidget *ui;
};

#endif // VISUALIZESTAFFWIDGET_H
