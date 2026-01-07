#include "AppWindow.h"

#include <QHBoxLayout>
#include <QImage>
#include <vector>
#include <QLabel>
#include <QPixmap>
#include "QtImage.h"
#include "ImageProcessor.h"
#include "DataCompute.h"


AppWindow::AppWindow(int width, int height, QWidget* parent) : QWidget(parent), _width(width), _height(height)
{
    /*
        LAYOUT
    */
    auto* layout = new QHBoxLayout();
    setLayout(layout);
    setMinimumSize(width, height);

    /*
        IMAGE
    */
    FILE* file = fopen("../frame_24.raw", "rb");

    int d = fseek(file, 0, SEEK_END);
    int len = ftell(file);
    std::cout << "LEN: " << len << std::endl;
    fseek(file, 0, SEEK_SET);
    fclose(file);

    QtImage* img = new QtImage(640, 480, "../frame_24.raw");
    layout->addWidget(img, 0, Qt::AlignCenter);

    QtImage* img2 = new QtImage(640, 480, "../frame_49.raw");
    layout->addWidget(img2, 0, Qt::AlignCenter);

    DataCompute *dc = new DataCompute();
    dc->printC();

    ImageProcessor* proc = new ImageProcessor();





}

AppWindow::~AppWindow()
{

}
  