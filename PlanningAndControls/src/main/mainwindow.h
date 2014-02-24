#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "QListView"
#include "QLayout"
#include "QGroupBox"
#include "QPushButton"
#include "QTextEdit"
#include "QStringListModel"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void appLog();

private:
    void creatList();
    void creatButtonGroup();
    void creatTopGroup();
    void creatBotGroup();
    void creatCavan();
    void creatLog();

    enum {numGridRows = 2,numButtons = 3};

    // these are widget place at top group
    QGroupBox *m_buttonGroup;
    QPushButton *buttons[numButtons];
    QListView *m_listView;

    // top and botton group box to contain widgets.
    QGroupBox *m_topGroup;
    QGroupBox *m_botGroup;

    // widgets place at bot group
    // log panel
    QTextEdit *m_log;
    QPushButton *m_testLog;
    int _numTestLog;

};

#endif // MAINWINDOW_H
