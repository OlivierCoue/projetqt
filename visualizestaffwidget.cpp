#include "visualizestaffwidget.h"
#include "ui_visualizestaffwidget.h"

VisualizeStaffWidget::VisualizeStaffWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::VisualizeStaffWidget)
{
    ui->setupUi(this);

    updateTreeView();
}

VisualizeStaffWidget::~VisualizeStaffWidget()
{
    delete ui;
}

void VisualizeStaffWidget::updateTreeView()
{
    ui->treeView->setModel(DaoStaff::getAll());
}
