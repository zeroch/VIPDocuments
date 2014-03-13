#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "QListView"
#include "QLayout"
#include "QGroupBox"
#include "QPushButton"
#include "QTextEdit"
#include "QStringListModel"
#include "QGraphicsView"
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QImage>
#include <QDebug>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void appLog();
    void selectImage();
private:
    void creatList();
    void creatButtonGroup();
    void creatTopGroup();
    void creatBotGroup();
    void creatDisplay();
    void creatLog();
    void reloadDisplay();
    enum {numGridRows = 2,numButtons = 3};

    // these are widget place at top group
    QGroupBox *m_buttonGroup;
    QPushButton *buttons[numButtons];
    QListView *m_listView;

    // top and botton group box to contain widgets.
    QGroupBox *m_topGroup;
    QGroupBox *m_botGroup;

    // map display
    QGraphicsView *m_view;
    QGraphicsScene *m_scene;
    QImage *m_image;
    QGraphicsPixmapItem *m_pixItem;
    QPushButton *m_browseFile;
    QString fileName;
    // widgets place at bot group
    // log panel
    QTextEdit *m_log;
    QPushButton *m_testLog;
    int _numTestLog;

};

#endif // MAINWINDOW_H
