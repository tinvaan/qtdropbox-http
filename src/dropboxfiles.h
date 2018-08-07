#ifndef _DROPBOX_FILES_H_
#define _DROPBOX_FILES_H_

#include "dropboxauth.h"


namespace Dropbox {

class DropboxFiles : public DropboxAuth
{
    Q_OBJECT

public:
    explicit DropboxFiles(QString, QObject *parent=Q_NULLPTR);
    explicit DropboxFiles(QString, QString, QString, QObject *parent=Q_NULLPTR);

    bool upload(QString );
    bool download(QString );

    bool save(QString );
    bool remove(QString );
    bool move(QString, QString );
    bool copy(QString, QString );
    bool permanentRemove(QString );

    QString getPreview(QString );
    QString getMetadata(QString );
    QUrl getTemporaryLink(QString );
    QUrl getTemporaryUploadLink(QString );
};

}

#endif // _DROPBOX_FILES_H_
