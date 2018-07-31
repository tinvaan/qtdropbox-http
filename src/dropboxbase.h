#ifndef _DROPBOX_HTTP_H_
#define _DROPBOX_HTTP_H_


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
    explicit DropboxBase(QString, QObject *parent=Q_NULLPTR);
    ~DropboxBase();

    QString getApiKey() const;
    QString getAuthToken(QString );

    void setApiKey(QString );

public slots:
    void synced(QNetworkReply* );

protected:
    QString m_apiKey;
    QNetworkRequest *m_request;
    QNetworkAccessManager *m_manager;
};


#endif // _DROPBOX_HTTP_H_
