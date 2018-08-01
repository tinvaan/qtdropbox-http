#include "endpoints.h"


namespace Dropbox {
namespace Files {}
namespace Folders {}


QUrl AppAuth::getAppAuthUrl() const
{
    return QUrl(DROPBOX_APP_AUTH_ENDPOINT + APP_AUTHENTICATION);
}

QString AppAuth::getAppAuthUrlString() const
{
    return QString(DROPBOX_APP_AUTH_ENDPOINT + APP_AUTHENTICATION);
}

QUrl Endpoint::getHttpUrl(const QString url) const
{
    return QUrl(DROPBOX_V2_ENDPOINT + url);
}

QString Endpoint::getHttpUrlString(const QString url) const
{
    return QString(DROPBOX_V2_ENDPOINT + url);
}


}
