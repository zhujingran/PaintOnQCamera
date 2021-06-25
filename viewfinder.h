#ifndef VIEWFINDER_H
#define VIEWFINDER_H

#include <QLabel>

class ViewFinder : public QLabel
{
    Q_OBJECT

public:
    ViewFinder(QWidget *parent = nullptr);
    ~ViewFinder();

private:
    void paintEvent(QPaintEvent *event) override;
};

#endif // VIEWFINDER_H
