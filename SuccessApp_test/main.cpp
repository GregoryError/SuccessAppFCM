#include "myclient.h"
#include "backend.h"
#include "permissions.h"
//#include <QtConcurrent>


int main(int argc, char *argv[])
{

    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QCoreApplication::setAttribute(Qt::AA_UseHighDpiPixmaps);

    QApplication app(argc, argv);


    Permissions permission;

    // permission.requestExternalStoragePermission();

    permission.requestLocationPermission();
    permission.requestPreciseLocationPermission();


    //app.setApplicationName("Успех");
    app.setApplicationDisplayName("Успех");
    app.setOrganizationName("Success");
    app.setOrganizationDomain("www.comfort-tv.ru/");
    app.setApplicationName("Success");



    //    QPixmap lg(":/logo.png");



    //    QSplashScreen splash(lg);

    //    splash.show();

    //    app.processEvents();

    //    QTime time;
    //    time.start();
    //    for(int i(0); i < 20;)
    //    {
    //        if(time.elapsed() > 15){
    //            time.start();
    //            ++i;
    //        }
    //    }



    //    QLabel lbl("Loading");
    //    splash.finish(&lbl);


    //BackEnd* obj = new BackEnd;

   //QSharedPointer<MyClient> client(new MyClient);
    MyClient client;

    // MyClient* client = new MyClient;
    BackEnd obj;

    //    obj.setSplash(&splash);

    // qmlRegisterType<*client>("lib.MyClient", 1, 0, "myClient");


    //    obj.cont->setContextProperty("myClient", client.data());
    obj.cont->setContextProperty("myClient", &client);



    if (!permission.getPermissionResult() && !client.isAuth())
    {
        QMessageBox msgBox;
        msgBox.setText("Доступ к местоположению не разрешен Вами. "
                       "Одна из функций приложения не будет работать.");
        msgBox.exec();
        app.quit();
    }



    //delete obj;
    //delete client;

    // client->Sender("(len1-29c#h7rJ2Pn4)getAllData!");


    // Q_UNUSED(obj);
    // Q_UNUSED(client);


    return app.exec();
}




















