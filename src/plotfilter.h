#ifndef PLOTFILTER_H
#define PLOTFILTER_H

#include <QWidget>
#include"glospectrum.h"
#include"glsw.h"
#include<QComboBox>
#include<QLabel>
#include<QToolButton>
#include<QHBoxLayout>
class plotFilter : public QWidget
{
    Q_OBJECT
public:
    explicit plotFilter(float *ria,int num,bool discrete,int sr,QWidget *parent = 0);
    GLOSpectrum* widget;
    GLSW* _timeWidget;
    GLOSpectrum* getWidget();
    GLSW* getGLWidget();
    QComboBox *filterSelect;
    QLineEdit* ripple;
    QLabel* rip;
    QComboBox *cutFreqSel;
    float NyqFreq;
    QStringList texts;
    int sr;
    QToolButton* apply;
    QToolButton* reset;
    QToolButton* play;
    QLineEdit* numOfOrder;
signals:
    void closed(bool);
public slots:
    void filterChanged(int index);
    void setComboText(QString string);
    void setCutFreqToNy();
    void setActualFreq();

private:
    QString NqLabel;
    QLabel* OrderIsToHigh;
    QLabel* RippleNotValid;
    QLabel* name;
    QFont font;
    QLabel* Fdes;
    QLabel* order;
    QHBoxLayout* orderL;
    QWidget* ooder;
    QLabel* cutOfF;
    void closeEvent(QCloseEvent *event);
    QLabel *_displayActualFreq;
};

#endif // PLOTFILTER_H
