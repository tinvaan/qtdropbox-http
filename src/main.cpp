#include <QDebug>
#include <QCoreApplication>

#include "dropboxauth.h"


int main(int argc, char *argv[])
{
    if (argc != 3) {
        qWarning() << "Please provide app key and secret";
        return EXIT_FAILURE;
    }

    QCoreApplication app(argc, argv);
    QString key(static_cast<char*>(argv[1]));
    QString secret(static_cast<char*>(argv[2]));

    Dropbox::DropboxAuth dauth(key, secret);
    dauth.userAuthentication();
//    dbox.getMetadata("/Plasma Publictransport/no_ruter.zip");

    return app.exec();
}
