#include "mainwindow.h"


#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{

       QWidget *widget = new QWidget();

       
      QVBoxLayout *m_mainLayout = new QVBoxLayout;

      setWindowTitle(tr("GTRI"));
      creatList();
      creatDisplay();
      creatButtonGroup();
      creatLog();
      // for layout purpose need top and bot place in diff widget
      creatTopGroup();
      m_mainLayout->addWidget(m_topGroup);
      creatBotGroup();
      m_mainLayout->addWidget(m_botGroup);

      // work around to place our layout instead of default.
      widget->setLayout(m_mainLayout);
      setCentralWidget(widget);


}

MainWindow::~MainWindow()
{

}


void MainWindow::creatList(){


    m_listView =  new QListView(this);
    setCentralWidget(m_listView);

    QStringListModel *m_model = new QStringListModel();
    QStringList m_list;

    m_list << "RRT* search" << "A*" << "D*";
    m_model ->setStringList(m_list);
    m_listView->setModel(m_model);
    m_listView->show();

}

void MainWindow::creatButtonGroup(){
    m_buttonGroup = new QGroupBox(tr("Button Group"));
    QHBoxLayout *layout =new QHBoxLayout;

    buttons[0] = new QPushButton(tr("Run"));
    layout->addWidget(buttons[0]);

    buttons[1] = new QPushButton(tr("Pause"));
    layout->addWidget(buttons[1]);

    buttons[2] = new QPushButton(tr("Stop"));
    layout->addWidget(buttons[2]);

    m_buttonGroup->setLayout(layout);

}


void MainWindow::creatTopGroup(){

      m_topGroup = new QGroupBox(tr("Top Group"));
      QHBoxLayout *topLayout =new QHBoxLayout;
      topLayout->addWidget(m_listView);
      topLayout->addWidget(m_buttonGroup);
      m_topGroup->setLayout(topLayout);
}

void MainWindow::creatBotGroup(){

      m_botGroup = new QGroupBox(tr("Botton Group"));
      QHBoxLayout *botLayout =new QHBoxLayout;
      botLayout->addWidget(m_log);
      botLayout->addWidget(m_testLog);
      botLayout->addWidget(m_browseFile);
      botLayout->addWidget(m_view);
      m_botGroup->setLayout(botLayout);
}

void MainWindow::creatDisplay(){

      m_image = new QImage();
      bool insp = m_image->load("");
      if(!insp){
          qDebug() << "[DEBUG] image loading error";
      }
      m_scene = new QGraphicsScene();
      m_pixItem = new QGraphicsPixmapItem(QPixmap::fromImage(*m_image));
      m_scene->addItem(m_pixItem);
      m_view = new QGraphicsView(m_scene);
      m_view->show();
      m_browseFile = new QPushButton();
      m_browseFile->setText("Browse");
      connect(m_browseFile,SIGNAL(clicked()),this,SLOT(selectImage()));
}

void MainWindow::reloadDisplay(){

    m_scene->clear();
    bool insp = m_image->load(fileName);
    if(!insp){
        qDebug() << "[DEBUG] image loading error";
    }
    m_pixItem = new QGraphicsPixmapItem(QPixmap::fromImage(*m_image));
    m_scene->addItem(m_pixItem);
    m_log->append(QString("loading map: %1").arg(fileName));
}

void MainWindow::creatLog(){

    m_log = new QTextEdit();
    m_log->setText("Hello World!\n");
    m_log->append("appending some text..");
    m_log->setReadOnly(true);
    m_log->show();
    m_testLog = new QPushButton();
    m_testLog->setText("Test");
    _numTestLog = 0;
    connect(m_testLog,SIGNAL(released()),this,SLOT(appLog()));
}

void MainWindow::appLog(){
    ++_numTestLog;
    m_log->append(QString("Updating string by pushbutton: %1 ").arg(_numTestLog));
}

void MainWindow::selectImage(){
     fileName = QFileDialog::getOpenFileName(this,
        tr("Open Image"), "/home/ze", tr("Image Files (*.png *.jpg *.bmp *.pgm)"));
    qDebug()<< fileName;
    reloadDisplay();
}
