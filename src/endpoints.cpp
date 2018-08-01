#include "endpoints.h"


namespace Dropbox {

const QString Endpoint::DROPBOX_V2_ENDPOINT      = "https://api.dropboxapi.com/2/";

const QString AppAuth::DROPBOX_APP_AUTH_ENDPOINT = "https://api.dropbox.com/1";
const QString AppAuth::APP_AUTHENTICATION        = "/metadata/link";

const QString Auth::USER_AUTHENTICATION = "users/get_current_account";
const QString Auth::TEAM_AUTHENTICATION = "team/get_info";
const QString Auth::TOKEN_FROM_OAUTH1 = "auth/token/from_oauth1";
const QString Auth::TOKEN_REVOKE = "auth/token/revoke";


namespace Folders {

const QString Folder::FOLDER_CREATE = "files/create_folder_v2";
const QString Folder::FOLDER_CREATE_BATCH = "files/create_folder_batch";
const QString Folder::FOLDER_CREATE_BATCH_CHECK = "files/create_folder_batch/check";
const QString Folder::LIST_FOLDER = "files/list_folder";
const QString Folder::LIST_FOLDER_CONTINUE = "files/list_folder/continue";
const QString Folder::LIST_FOLDER_LATEST_CURSOR = "files/list_folder/get_latest_cursor";
const QString Folder::LIST_FOLDER_LONGPOLL = "files/list_folder/longpoll";
const QString Folder::SEARCH_FOLDER = "files/search";

}


namespace Files {

const QString Properties::PROPERTY_ADD = "file_properties/properties/add";
const QString Properties::PROPERTY_OVERWRITE = "file_properties/properties/overwrite";
const QString Properties::PROPERTY_REMOVE = "file_properties/properties/remove";
const QString Properties::PROPERTY_SEARCH = "file_properties/properties/search";
const QString Properties::PROPERTY_SEARCH_CONTINUE = "file_properties/properties/search/continue";
const QString Properties::PROPERTY_UPDATE = "file_properties/properties/update";

const QString Templates::ADD_FOR_USER = "file_properties/templates/add_for_user";
const QString Templates::GET_FOR_USER = "file_properties/templates/get_for_user";
const QString Templates::LIST_FOR_USER = "file_properties/templates/list_for_user";
const QString Templates::REMOVE_FOR_USER = "file_properties/templates/remove_for_user";
const QString Templates::UPDATE_FOR_USER = "file_properties/templates/update_for_user";

const QString Requests::CREATE = "file_requests/create";
const QString Requests::GET = "file_requests/get";
const QString Requests::LIST = "file_requests/list";
const QString Requests::UPDATE = "file_requests/update";

const QString File::COPY = "files/copy_v2";
const QString File::COPY_BATCH = "files/copy_batch";
const QString File::COPY_BATCH_CHECK = "files/copy_batch/check";
const QString File::COPY_REFERENCE_GET = "files/copy_reference/get";
const QString File::COPY_REFERENCE_SAVE = "files/copy_reference/save";
const QString File::DELETE = "files/delete_v2";
const QString File::DELETE_BATCH = "files/delete_batch";
const QString File::DELETE_BATCH_CHECK = "files/delete_batch/check";
const QString File::PERMANENTLY_DELETE = "files/permanently_delete";
const QString File::RESTORE_TO_REVISION = "files/restore";
const QString File::LIST_REVISIONS = "files/list_revisions";
const QString File::MOVE = "files/move_v2";
const QString File::MOVE_BATCH = "files/move_batch";
const QString File::MOVE_BATCH_CHECK = "files/move_batch/check";
const QString File::SAVE_URL = "files/save_url";
const QString File::SAVE_URL_CHECK_STATUS = "files/save_url/check_job_status";
const QString File::SEARCH_FILE = "files/search";

const QString Upload::UPLOAD = "files/upload";
const QString Upload::UPLOAD_START = "files/upload_session/start";
const QString Upload::UPLOAD_SESSION_APPEND = "files/upload_session/append_v2";
const QString Upload::UPLOAD_SESSION_FINISH = "files/upload_session/finish";
const QString Upload::UPLOAD_SESSION_FINISH_BATCH = "files/upload_session/finish_batch";
const QString Upload::UPLOAD_SESSION_FINISH_BATCH_CHECK = "files/upload_session/finish_batch/check";

const QString Download::DOWNLOAD = "files/download";
const QString Download::DOWNLOAD_ZIP = "files/download_zip";

const QString MetaInfo::GET_METADATA = "files/get_metadata";
const QString MetaInfo::GET_PREVIEW = "files/get_preview";
const QString MetaInfo::GET_TEMPORARY_LINK = "files/get_temporary_link";
const QString MetaInfo::GET_TEMPORARY_UPLOAD_LINK = "files/get_temporary_upload_link";
const QString MetaInfo::GET_THUMBNAIL = "files/get_thumbnail";
const QString MetaInfo::GET_THUMBNAIL_BATCH = "files/get_thumbnail_batch";

}


QUrl Endpoint::getHttpUrl(const QString url)
{
    return QUrl(DROPBOX_V2_ENDPOINT + url);
}

QString Endpoint::getHttpUrlString(const QString url)
{
    return QString(DROPBOX_V2_ENDPOINT + url);
}

QUrl AppAuth::getAppAuthUrl()
{
    return QUrl(DROPBOX_APP_AUTH_ENDPOINT + APP_AUTHENTICATION);
}

QString AppAuth::getAppAuthUrlString()
{
    return QString(DROPBOX_APP_AUTH_ENDPOINT + APP_AUTHENTICATION);
}


}
