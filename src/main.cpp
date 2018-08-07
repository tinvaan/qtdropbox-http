#include <QDebug>
#include <QCoreApplication>

#include "dropboxauth.h"
#include "dropboxfiles.h"


int main(int argc, char *argv[])
{
    if (argc != 2) {
        qWarning() << "Please provide API token";
        return EXIT_FAILURE;
    }

    QCoreApplication app(argc, argv);
    QString token(static_cast<char*>(argv[1]));


    Dropbox::DropboxFiles dbox(token);
//    dbox.userAuthentication();
    dbox.getMetadata("/Plasma Publictransport/no_ruter.zip");

    return app.exec();
}
