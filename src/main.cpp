#include <QDebug>
#include <QCoreApplication>

#include "dropboxhttp.h"


int main(int argc, char *argv[])
{
    if (argc != 3) {
        qWarning() << "Please provide server URL and API access token";
        return EXIT_FAILURE;
    }

    QCoreApplication app(argc, argv);
    QString url(static_cast<char*>(argv[1]));
    QString key(static_cast<char*>(argv[2]));

    DropboxHttp dbox(QUrl(url), key);
    dbox.getMetadata("/Plasma Publictransport/no_ruter.zip");

    return app.exec();
}
