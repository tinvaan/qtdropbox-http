#ifndef _DROPBOX_REQUEST_H_
#define _DROPBOX_REQUEST_H_


#include <QUrl>
#include <QString>
#include <QObject>


class QNetworkReply;
class QNetworkRequest;
class QNetworkAccessManager;

namespace Dropbox {

class DropboxRequest : public QObject
{
    Q_OBJECT

public:
    explicit DropboxRequest(QObject *parent=Q_NULLPTR);
    ~DropboxRequest();

    QNetworkRequest* request() const;
    QNetworkAccessManager* manager() const;

    void setRequest(QNetworkRequest* );
    void setManager(QNetworkAccessManager* );

public slots:
    void synced(QNetworkReply* );

protected:
    QNetworkRequest *m_request;
    QNetworkAccessManager *m_manager;
};

}


#endif // _DROPBOX_REQUEST_H_
