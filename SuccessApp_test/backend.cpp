#include "backend.h"

BackEnd::BackEnd(QObject *parent) :
    QObject(parent)
{

    //displaySize = QApplication::desktop()->availableGeometry();

    cont = engine.rootContext();
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    //engine.load(QUrl(QStringLiteral("qrc:/homePage.qml")));
    //engine.load(QUrl(QStringLiteral("qrc:/payments.qml")));


    cont->setContextProperty("BackEnd", this);

    ////////////////////////////////////////////////////////////////////////// GPS_POSITIONING


    if(source){
        source->setPreferredPositioningMethods(QGeoPositionInfoSource::AllPositioningMethods);
        source->startUpdates();
        source->setUpdateInterval(1000);
        source->requestUpdate();
    }else{
        QMessageBox::information(nullptr, "Message", "Не возможно определить местоположение"
                                                     "\n на вашем устройстве.");
    }

    QGeoPositionInfo info = source->lastKnownPosition();
    QGeoCoordinate coordinate = info.coordinate();
    owner.latitude = coordinate.longitude();
    owner.longitude = coordinate.latitude();

    //    owner.longitude = 60.714748;  // TEST
    //    owner.latitude = 28.729657;   // TEST


    cashpoints.push_back(location(60.693720, 28.761991, "ул. Приморская д. 1,<br> Сбербанк", owner.longitude, owner.latitude));
    cashpoints.push_back(location(60.697717, 28.775652, "пр. Победы, 16,<br> Сбербанк ATM", owner.longitude, owner.latitude));
    cashpoints.push_back(location(60.699575, 28.782988, "Ленинградское ш., 57,<br> Сбербанк ATM", owner.longitude, owner.latitude));
    cashpoints.push_back(location(60.694778, 28.787956, "ул. Большая Каменная 7б,<br> Сбербанк ATM", owner.longitude, owner.latitude));
    cashpoints.push_back(location(60.704596, 28.775528, "Ленинградское ш., 47,<br> Сбербанк", owner.longitude, owner.latitude));
    cashpoints.push_back(location(60.705908, 28.768398, "Батарейная ул., 1,<br> Сбербанк ATM", owner.longitude, owner.latitude));
    cashpoints.push_back(location(60.70682, 28.76907, "УСПЕХ, центральный офис,<br> Ленинградское шоссе д. 33", owner.longitude, owner.latitude));
    cashpoints.push_back(location(60.704881, 28.749174, "Садовая ул., 15,<br> Сбербанк", owner.longitude, owner.latitude));
    cashpoints.push_back(location(60.709370, 28.752608, "Московский пр., 24,<br> Сбербанк ATM", owner.longitude, owner.latitude));
    cashpoints.push_back(location(60.710176, 28.747834, "пр. Ленина, 20-а,<br> Сбербанк", owner.longitude, owner.latitude));
    cashpoints.push_back(location(60.711523, 28.744147, "Ленинградский пр., 10/12,<br> Офис Сбербанк", owner.longitude, owner.latitude));
    cashpoints.push_back(location(60.716410, 28.759876, "ул. Кривоносова 9а,<br> Сбербанк", owner.longitude, owner.latitude));
    cashpoints.push_back(location(60.713838, 28.739966, "40 лет ВЛКСМ наб., 1,<br> Сбебанк", owner.longitude, owner.latitude));
    cashpoints.push_back(location(60.719487, 28.715171, "ул. Госпитальная, д. 1,<br> Сбербанк ATM", owner.longitude, owner.latitude));
    cashpoints.push_back(location(60.533401, 28.665485, "Советский, Советская, 47,<br> Сбербанк", owner.longitude, owner.latitude));
    cashpoints.push_back(location(60.365635, 28.607738, "Приморск, Набережная Лебедева 12,<br> Сбербанк", owner.longitude, owner.latitude));
    cashpoints.push_back(location(60.707622, 28.753213, "пр. Ленина 9/Кутузова,<br> Сбербанк", owner.longitude, owner.latitude));
    cashpoints.push_back(location(60.700772, 28.783921, "ул. Транспортная 1<br> Сбербанк ATM", owner.longitude, owner.latitude));

    std::sort(cashpoints.begin(), cashpoints.end());
}

void BackEnd::trustedPay()
{
    QMessageBox::information(nullptr, "Message", "Вам предоставлен временный платеж!");
}

QString BackEnd::showATM()
{
    if (source){
        source->setPreferredPositioningMethods(QGeoPositionInfoSource::AllPositioningMethods);
        source->startUpdates();
        source->setUpdateInterval(1000);
        source->requestUpdate();
    }
    else QMessageBox::information(nullptr, "Message", "Не возможно определить местоположение"
                                                      "\n на вашем устройстве.");
    QGeoPositionInfo info = source->lastKnownPosition();
    QGeoCoordinate coordinate = info.coordinate();
    owner.latitude = coordinate.longitude();
    owner.longitude = coordinate.latitude();

    std::sort(cashpoints.begin(), cashpoints.end());


    return ("<b>1. </b>" + cashpoints[0].address + "<br>"
                                                   "<b>2. </b>" + cashpoints[1].address + "<br>"
            "<b>3. </b>" + cashpoints[2].address);

}

////////////////////////////////////////// BLOCK CONTACTS
void BackEnd::callUs()
{
    QDesktopServices::openUrl(QUrl("tel:+78137898098"));
}

void BackEnd::goUrl()
{
    QUrl myUrl("http://www.comfort-tv.ru/net.php?m=1");
    QDesktopServices::openUrl(myUrl);
}

void BackEnd::goValue()
{
    QUrl myUrl("https://play.google.com/store/apps/details?id=org.success.isp");
    QDesktopServices::openUrl(myUrl);
}

void BackEnd::social()
{
    QUrl myUrl("https://vk.com/arrivanet");
    QDesktopServices::openUrl(myUrl);
}

void BackEnd::go_OSM_url()
{
    QUrl myUrl("https://www.openstreetmap.org/copyright");
    QDesktopServices::openUrl(myUrl);
}

double BackEnd::p_point_long(int i)
{
    return cashpoints[i].longitude;
}

double BackEnd::p_point_lat(int i)
{
    return cashpoints[i].latitude;
}

double BackEnd::p_owner_long()
{
    if (QString::number(owner.longitude) == "nan")
        return 60.70682;
    return owner.longitude;
}

double BackEnd::p_owner_lat()
{
    if (QString::number(owner.latitude) == "nan")
        return 28.76907;
    return owner.latitude;
}

int BackEnd::p_count()
{
    return cashpoints.size();
}



//////////////////////////////////////////////////////////















