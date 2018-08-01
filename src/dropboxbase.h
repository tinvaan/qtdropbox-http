#ifndef _DROPBOX_BASE_H_
#define _DROPBOX_BASE_H_


#include <QUrl>
#include <QString>
#include <QObject>


class QNetworkReply;
class QNetworkRequest;
class QNetworkAccessManager;

class DropboxBase : public QObject
{
    Q_OBJECT

public:
    explicit DropboxBase(QObject *parent=Q_NULLPTR);
    ~DropboxBase();

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


#endif // _DROPBOX_BASE_H_
