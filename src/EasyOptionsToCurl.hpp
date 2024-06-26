#pragma once

#include <array>

#include <curl/curl.h>

#include "EasyOptions.hpp"

namespace CurlWrapper
{
namespace EasyOptionsToCurl
{

static constexpr std::array s_conv_table
{
    std::pair(EasyOption::WRITEDATA, CURLOPT_WRITEDATA),
    std::pair(EasyOption::URL, CURLOPT_URL),
    std::pair(EasyOption::PORT, CURLOPT_PORT),
    std::pair(EasyOption::PROXY, CURLOPT_PROXY),
    std::pair(EasyOption::USERPWD, CURLOPT_USERPWD),
    std::pair(EasyOption::PROXYUSERPWD, CURLOPT_PROXYUSERPWD),
    std::pair(EasyOption::RANGE, CURLOPT_RANGE),
    std::pair(EasyOption::READDATA, CURLOPT_READDATA),
    std::pair(EasyOption::ERRORBUFFER, CURLOPT_ERRORBUFFER),
    std::pair(EasyOption::WRITEFUNCTION, CURLOPT_WRITEFUNCTION),
    std::pair(EasyOption::READFUNCTION, CURLOPT_READFUNCTION),
    std::pair(EasyOption::TIMEOUT, CURLOPT_TIMEOUT),
    std::pair(EasyOption::INFILESIZE, CURLOPT_INFILESIZE),
    std::pair(EasyOption::POSTFIELDS, CURLOPT_POSTFIELDS),
    std::pair(EasyOption::REFERER, CURLOPT_REFERER),
    std::pair(EasyOption::FTPPORT, CURLOPT_FTPPORT),
    std::pair(EasyOption::USERAGENT, CURLOPT_USERAGENT),
    std::pair(EasyOption::LOW_SPEED_LIMIT, CURLOPT_LOW_SPEED_LIMIT),
    std::pair(EasyOption::LOW_SPEED_TIME, CURLOPT_LOW_SPEED_TIME),
    std::pair(EasyOption::RESUME_FROM, CURLOPT_RESUME_FROM),
    std::pair(EasyOption::COOKIE, CURLOPT_COOKIE),
    std::pair(EasyOption::HTTPHEADER, CURLOPT_HTTPHEADER),
    std::pair(EasyOption::SSLCERT, CURLOPT_SSLCERT),
    std::pair(EasyOption::KEYPASSWD, CURLOPT_KEYPASSWD),
    std::pair(EasyOption::CRLF, CURLOPT_CRLF),
    std::pair(EasyOption::QUOTE, CURLOPT_QUOTE),
    std::pair(EasyOption::HEADERDATA, CURLOPT_HEADERDATA),
    std::pair(EasyOption::COOKIEFILE, CURLOPT_COOKIEFILE),
    std::pair(EasyOption::SSLVERSION, CURLOPT_SSLVERSION),
    std::pair(EasyOption::TIMECONDITION, CURLOPT_TIMECONDITION),
    std::pair(EasyOption::TIMEVALUE, CURLOPT_TIMEVALUE),
    std::pair(EasyOption::CUSTOMREQUEST, CURLOPT_CUSTOMREQUEST),
    std::pair(EasyOption::STDERR, CURLOPT_STDERR),
    std::pair(EasyOption::POSTQUOTE, CURLOPT_POSTQUOTE),
    std::pair(EasyOption::OBSOLETE40, CURLOPT_OBSOLETE40),
    std::pair(EasyOption::VERBOSE, CURLOPT_VERBOSE),
    std::pair(EasyOption::HEADER, CURLOPT_HEADER),
    std::pair(EasyOption::NOPROGRESS, CURLOPT_NOPROGRESS),
    std::pair(EasyOption::NOBODY, CURLOPT_NOBODY),
    std::pair(EasyOption::FAILONERROR, CURLOPT_FAILONERROR),
    std::pair(EasyOption::UPLOAD, CURLOPT_UPLOAD),
    std::pair(EasyOption::POST, CURLOPT_POST),
    std::pair(EasyOption::DIRLISTONLY, CURLOPT_DIRLISTONLY),
    std::pair(EasyOption::APPEND, CURLOPT_APPEND),
    std::pair(EasyOption::NETRC, CURLOPT_NETRC),
    std::pair(EasyOption::FOLLOWLOCATION, CURLOPT_FOLLOWLOCATION),
    std::pair(EasyOption::TRANSFERTEXT, CURLOPT_TRANSFERTEXT),
    std::pair(EasyOption::XFERINFODATA, CURLOPT_XFERINFODATA),
    std::pair(EasyOption::PROGRESSDATA, CURLOPT_PROGRESSDATA),
    std::pair(EasyOption::AUTOREFERER, CURLOPT_AUTOREFERER),
    std::pair(EasyOption::PROXYPORT, CURLOPT_PROXYPORT),
    std::pair(EasyOption::POSTFIELDSIZE, CURLOPT_POSTFIELDSIZE),
    std::pair(EasyOption::HTTPPROXYTUNNEL, CURLOPT_HTTPPROXYTUNNEL),
    std::pair(EasyOption::INTERFACE, CURLOPT_INTERFACE),
    std::pair(EasyOption::KRBLEVEL, CURLOPT_KRBLEVEL),
    std::pair(EasyOption::SSL_VERIFYPEER, CURLOPT_SSL_VERIFYPEER),
    std::pair(EasyOption::CAINFO, CURLOPT_CAINFO),
    std::pair(EasyOption::MAXREDIRS, CURLOPT_MAXREDIRS),
    std::pair(EasyOption::FILETIME, CURLOPT_FILETIME),
    std::pair(EasyOption::TELNETOPTIONS, CURLOPT_TELNETOPTIONS),
    std::pair(EasyOption::MAXCONNECTS, CURLOPT_MAXCONNECTS),
    std::pair(EasyOption::OBSOLETE72, CURLOPT_OBSOLETE72),
    std::pair(EasyOption::FRESH_CONNECT, CURLOPT_FRESH_CONNECT),
    std::pair(EasyOption::FORBID_REUSE, CURLOPT_FORBID_REUSE),
    std::pair(EasyOption::CONNECTTIMEOUT, CURLOPT_CONNECTTIMEOUT),
    std::pair(EasyOption::HEADERFUNCTION, CURLOPT_HEADERFUNCTION),
    std::pair(EasyOption::HTTPGET, CURLOPT_HTTPGET),
    std::pair(EasyOption::SSL_VERIFYHOST, CURLOPT_SSL_VERIFYHOST),
    std::pair(EasyOption::COOKIEJAR, CURLOPT_COOKIEJAR),
    std::pair(EasyOption::SSL_CIPHER_LIST, CURLOPT_SSL_CIPHER_LIST),
    std::pair(EasyOption::HTTP_VERSION, CURLOPT_HTTP_VERSION),
    std::pair(EasyOption::FTP_USE_EPSV, CURLOPT_FTP_USE_EPSV),
    std::pair(EasyOption::SSLCERTTYPE, CURLOPT_SSLCERTTYPE),
    std::pair(EasyOption::SSLKEY, CURLOPT_SSLKEY),
    std::pair(EasyOption::SSLKEYTYPE, CURLOPT_SSLKEYTYPE),
    std::pair(EasyOption::SSLENGINE, CURLOPT_SSLENGINE),
    std::pair(EasyOption::SSLENGINE_DEFAULT, CURLOPT_SSLENGINE_DEFAULT),
    std::pair(EasyOption::DNS_CACHE_TIMEOUT, CURLOPT_DNS_CACHE_TIMEOUT),
    std::pair(EasyOption::PREQUOTE, CURLOPT_PREQUOTE),
    std::pair(EasyOption::DEBUGFUNCTION, CURLOPT_DEBUGFUNCTION),
    std::pair(EasyOption::DEBUGDATA, CURLOPT_DEBUGDATA),
    std::pair(EasyOption::COOKIESESSION, CURLOPT_COOKIESESSION),
    std::pair(EasyOption::CAPATH, CURLOPT_CAPATH),
    std::pair(EasyOption::BUFFERSIZE, CURLOPT_BUFFERSIZE),
    std::pair(EasyOption::NOSIGNAL, CURLOPT_NOSIGNAL),
    std::pair(EasyOption::SHARE, CURLOPT_SHARE),
    std::pair(EasyOption::PROXYTYPE, CURLOPT_PROXYTYPE),
    std::pair(EasyOption::ACCEPT_ENCODING, CURLOPT_ACCEPT_ENCODING),
    std::pair(EasyOption::PRIVATE, CURLOPT_PRIVATE),
    std::pair(EasyOption::HTTP200ALIASES, CURLOPT_HTTP200ALIASES),
    std::pair(EasyOption::UNRESTRICTED_AUTH, CURLOPT_UNRESTRICTED_AUTH),
    std::pair(EasyOption::FTP_USE_EPRT, CURLOPT_FTP_USE_EPRT),
    std::pair(EasyOption::HTTPAUTH, CURLOPT_HTTPAUTH),
    std::pair(EasyOption::SSL_CTX_FUNCTION, CURLOPT_SSL_CTX_FUNCTION),
    std::pair(EasyOption::SSL_CTX_DATA, CURLOPT_SSL_CTX_DATA),
    std::pair(EasyOption::FTP_CREATE_MISSING_DIRS, CURLOPT_FTP_CREATE_MISSING_DIRS),
    std::pair(EasyOption::PROXYAUTH, CURLOPT_PROXYAUTH),
    std::pair(EasyOption::SERVER_RESPONSE_TIMEOUT, CURLOPT_SERVER_RESPONSE_TIMEOUT),
    std::pair(EasyOption::IPRESOLVE, CURLOPT_IPRESOLVE),
    std::pair(EasyOption::MAXFILESIZE, CURLOPT_MAXFILESIZE),
    std::pair(EasyOption::INFILESIZE_LARGE, CURLOPT_INFILESIZE_LARGE),
    std::pair(EasyOption::RESUME_FROM_LARGE, CURLOPT_RESUME_FROM_LARGE),
    std::pair(EasyOption::MAXFILESIZE_LARGE, CURLOPT_MAXFILESIZE_LARGE),
    std::pair(EasyOption::NETRC_FILE, CURLOPT_NETRC_FILE),
    std::pair(EasyOption::USE_SSL, CURLOPT_USE_SSL),
    std::pair(EasyOption::POSTFIELDSIZE_LARGE, CURLOPT_POSTFIELDSIZE_LARGE),
    std::pair(EasyOption::TCP_NODELAY, CURLOPT_TCP_NODELAY),
    std::pair(EasyOption::FTPSSLAUTH, CURLOPT_FTPSSLAUTH),
    std::pair(EasyOption::FTP_ACCOUNT, CURLOPT_FTP_ACCOUNT),
    std::pair(EasyOption::COOKIELIST, CURLOPT_COOKIELIST),
    std::pair(EasyOption::IGNORE_CONTENT_LENGTH, CURLOPT_IGNORE_CONTENT_LENGTH),
    std::pair(EasyOption::FTP_SKIP_PASV_IP, CURLOPT_FTP_SKIP_PASV_IP),
    std::pair(EasyOption::FTP_FILEMETHOD, CURLOPT_FTP_FILEMETHOD),
    std::pair(EasyOption::LOCALPORT, CURLOPT_LOCALPORT),
    std::pair(EasyOption::LOCALPORTRANGE, CURLOPT_LOCALPORTRANGE),
    std::pair(EasyOption::CONNECT_ONLY, CURLOPT_CONNECT_ONLY),
    std::pair(EasyOption::MAX_SEND_SPEED_LARGE, CURLOPT_MAX_SEND_SPEED_LARGE),
    std::pair(EasyOption::MAX_RECV_SPEED_LARGE, CURLOPT_MAX_RECV_SPEED_LARGE),
    std::pair(EasyOption::FTP_ALTERNATIVE_TO_USER, CURLOPT_FTP_ALTERNATIVE_TO_USER),
    std::pair(EasyOption::SOCKOPTFUNCTION, CURLOPT_SOCKOPTFUNCTION),
    std::pair(EasyOption::SOCKOPTDATA, CURLOPT_SOCKOPTDATA),
    std::pair(EasyOption::SSL_SESSIONID_CACHE, CURLOPT_SSL_SESSIONID_CACHE),
    std::pair(EasyOption::SSH_AUTH_TYPES, CURLOPT_SSH_AUTH_TYPES),
    std::pair(EasyOption::SSH_PUBLIC_KEYFILE, CURLOPT_SSH_PUBLIC_KEYFILE),
    std::pair(EasyOption::SSH_PRIVATE_KEYFILE, CURLOPT_SSH_PRIVATE_KEYFILE),
    std::pair(EasyOption::FTP_SSL_CCC, CURLOPT_FTP_SSL_CCC),
    std::pair(EasyOption::TIMEOUT_MS, CURLOPT_TIMEOUT_MS),
    std::pair(EasyOption::CONNECTTIMEOUT_MS, CURLOPT_CONNECTTIMEOUT_MS),
    std::pair(EasyOption::HTTP_TRANSFER_DECODING, CURLOPT_HTTP_TRANSFER_DECODING),
    std::pair(EasyOption::HTTP_CONTENT_DECODING, CURLOPT_HTTP_CONTENT_DECODING),
    std::pair(EasyOption::NEW_FILE_PERMS, CURLOPT_NEW_FILE_PERMS),
    std::pair(EasyOption::NEW_DIRECTORY_PERMS, CURLOPT_NEW_DIRECTORY_PERMS),
    std::pair(EasyOption::POSTREDIR, CURLOPT_POSTREDIR),
    std::pair(EasyOption::SSH_HOST_PUBLIC_KEY_MD5, CURLOPT_SSH_HOST_PUBLIC_KEY_MD5),
    std::pair(EasyOption::OPENSOCKETFUNCTION, CURLOPT_OPENSOCKETFUNCTION),
    std::pair(EasyOption::OPENSOCKETDATA, CURLOPT_OPENSOCKETDATA),
    std::pair(EasyOption::COPYPOSTFIELDS, CURLOPT_COPYPOSTFIELDS),
    std::pair(EasyOption::PROXY_TRANSFER_MODE, CURLOPT_PROXY_TRANSFER_MODE),
    std::pair(EasyOption::SEEKFUNCTION, CURLOPT_SEEKFUNCTION),
    std::pair(EasyOption::SEEKDATA, CURLOPT_SEEKDATA),
    std::pair(EasyOption::CRLFILE, CURLOPT_CRLFILE),
    std::pair(EasyOption::ISSUERCERT, CURLOPT_ISSUERCERT),
    std::pair(EasyOption::ADDRESS_SCOPE, CURLOPT_ADDRESS_SCOPE),
    std::pair(EasyOption::CERTINFO, CURLOPT_CERTINFO),
    std::pair(EasyOption::USERNAME, CURLOPT_USERNAME),
    std::pair(EasyOption::PASSWORD, CURLOPT_PASSWORD),
    std::pair(EasyOption::PROXYUSERNAME, CURLOPT_PROXYUSERNAME),
    std::pair(EasyOption::PROXYPASSWORD, CURLOPT_PROXYPASSWORD),
    std::pair(EasyOption::NOPROXY, CURLOPT_NOPROXY),
    std::pair(EasyOption::TFTP_BLKSIZE, CURLOPT_TFTP_BLKSIZE),
    std::pair(EasyOption::SOCKS5_GSSAPI_NEC, CURLOPT_SOCKS5_GSSAPI_NEC),
    std::pair(EasyOption::SSH_KNOWNHOSTS, CURLOPT_SSH_KNOWNHOSTS),
    std::pair(EasyOption::SSH_KEYFUNCTION, CURLOPT_SSH_KEYFUNCTION),
    std::pair(EasyOption::SSH_KEYDATA, CURLOPT_SSH_KEYDATA),
    std::pair(EasyOption::MAIL_FROM, CURLOPT_MAIL_FROM),
    std::pair(EasyOption::MAIL_RCPT, CURLOPT_MAIL_RCPT),
    std::pair(EasyOption::FTP_USE_PRET, CURLOPT_FTP_USE_PRET),
    std::pair(EasyOption::RTSP_REQUEST, CURLOPT_RTSP_REQUEST),
    std::pair(EasyOption::RTSP_SESSION_ID, CURLOPT_RTSP_SESSION_ID),
    std::pair(EasyOption::RTSP_STREAM_URI, CURLOPT_RTSP_STREAM_URI),
    std::pair(EasyOption::RTSP_TRANSPORT, CURLOPT_RTSP_TRANSPORT),
    std::pair(EasyOption::RTSP_CLIENT_CSEQ, CURLOPT_RTSP_CLIENT_CSEQ),
    std::pair(EasyOption::RTSP_SERVER_CSEQ, CURLOPT_RTSP_SERVER_CSEQ),
    std::pair(EasyOption::INTERLEAVEDATA, CURLOPT_INTERLEAVEDATA),
    std::pair(EasyOption::INTERLEAVEFUNCTION, CURLOPT_INTERLEAVEFUNCTION),
    std::pair(EasyOption::WILDCARDMATCH, CURLOPT_WILDCARDMATCH),
    std::pair(EasyOption::CHUNK_BGN_FUNCTION, CURLOPT_CHUNK_BGN_FUNCTION),
    std::pair(EasyOption::CHUNK_END_FUNCTION, CURLOPT_CHUNK_END_FUNCTION),
    std::pair(EasyOption::FNMATCH_FUNCTION, CURLOPT_FNMATCH_FUNCTION),
    std::pair(EasyOption::CHUNK_DATA, CURLOPT_CHUNK_DATA),
    std::pair(EasyOption::FNMATCH_DATA, CURLOPT_FNMATCH_DATA),
    std::pair(EasyOption::RESOLVE, CURLOPT_RESOLVE),
    std::pair(EasyOption::TLSAUTH_USERNAME, CURLOPT_TLSAUTH_USERNAME),
    std::pair(EasyOption::TLSAUTH_PASSWORD, CURLOPT_TLSAUTH_PASSWORD),
    std::pair(EasyOption::TLSAUTH_TYPE, CURLOPT_TLSAUTH_TYPE),
    std::pair(EasyOption::TRANSFER_ENCODING, CURLOPT_TRANSFER_ENCODING),
    std::pair(EasyOption::CLOSESOCKETFUNCTION, CURLOPT_CLOSESOCKETFUNCTION),
    std::pair(EasyOption::CLOSESOCKETDATA, CURLOPT_CLOSESOCKETDATA),
    std::pair(EasyOption::GSSAPI_DELEGATION, CURLOPT_GSSAPI_DELEGATION),
    std::pair(EasyOption::DNS_SERVERS, CURLOPT_DNS_SERVERS),
    std::pair(EasyOption::ACCEPTTIMEOUT_MS, CURLOPT_ACCEPTTIMEOUT_MS),
    std::pair(EasyOption::TCP_KEEPALIVE, CURLOPT_TCP_KEEPALIVE),
    std::pair(EasyOption::TCP_KEEPIDLE, CURLOPT_TCP_KEEPIDLE),
    std::pair(EasyOption::TCP_KEEPINTVL, CURLOPT_TCP_KEEPINTVL),
    std::pair(EasyOption::SSL_OPTIONS, CURLOPT_SSL_OPTIONS),
    std::pair(EasyOption::MAIL_AUTH, CURLOPT_MAIL_AUTH),
    std::pair(EasyOption::SASL_IR, CURLOPT_SASL_IR),
    std::pair(EasyOption::XFERINFOFUNCTION, CURLOPT_XFERINFOFUNCTION),
    std::pair(EasyOption::XOAUTH2_BEARER, CURLOPT_XOAUTH2_BEARER),
    std::pair(EasyOption::DNS_INTERFACE, CURLOPT_DNS_INTERFACE),
    std::pair(EasyOption::DNS_LOCAL_IP4, CURLOPT_DNS_LOCAL_IP4),
    std::pair(EasyOption::DNS_LOCAL_IP6, CURLOPT_DNS_LOCAL_IP6),
    std::pair(EasyOption::LOGIN_OPTIONS, CURLOPT_LOGIN_OPTIONS),
    std::pair(EasyOption::SSL_ENABLE_ALPN, CURLOPT_SSL_ENABLE_ALPN),
    std::pair(EasyOption::EXPECT_100_TIMEOUT_MS, CURLOPT_EXPECT_100_TIMEOUT_MS),
    std::pair(EasyOption::PROXYHEADER, CURLOPT_PROXYHEADER),
    std::pair(EasyOption::HEADEROPT, CURLOPT_HEADEROPT),
    std::pair(EasyOption::PINNEDPUBLICKEY, CURLOPT_PINNEDPUBLICKEY),
    std::pair(EasyOption::UNIX_SOCKET_PATH, CURLOPT_UNIX_SOCKET_PATH),
    std::pair(EasyOption::SSL_VERIFYSTATUS, CURLOPT_SSL_VERIFYSTATUS),
    std::pair(EasyOption::SSL_FALSESTART, CURLOPT_SSL_FALSESTART),
    std::pair(EasyOption::PATH_AS_IS, CURLOPT_PATH_AS_IS),
    std::pair(EasyOption::PROXY_SERVICE_NAME, CURLOPT_PROXY_SERVICE_NAME),
    std::pair(EasyOption::SERVICE_NAME, CURLOPT_SERVICE_NAME),
    std::pair(EasyOption::PIPEWAIT, CURLOPT_PIPEWAIT),
    std::pair(EasyOption::DEFAULT_PROTOCOL, CURLOPT_DEFAULT_PROTOCOL),
    std::pair(EasyOption::STREAM_WEIGHT, CURLOPT_STREAM_WEIGHT),
    std::pair(EasyOption::STREAM_DEPENDS, CURLOPT_STREAM_DEPENDS),
    std::pair(EasyOption::STREAM_DEPENDS_E, CURLOPT_STREAM_DEPENDS_E),
    std::pair(EasyOption::TFTP_NO_OPTIONS, CURLOPT_TFTP_NO_OPTIONS),
    std::pair(EasyOption::CONNECT_TO, CURLOPT_CONNECT_TO),
    std::pair(EasyOption::TCP_FASTOPEN, CURLOPT_TCP_FASTOPEN),
    std::pair(EasyOption::KEEP_SENDING_ON_ERROR, CURLOPT_KEEP_SENDING_ON_ERROR),
    std::pair(EasyOption::PROXY_CAINFO, CURLOPT_PROXY_CAINFO),
    std::pair(EasyOption::PROXY_CAPATH, CURLOPT_PROXY_CAPATH),
    std::pair(EasyOption::PROXY_SSL_VERIFYPEER, CURLOPT_PROXY_SSL_VERIFYPEER),
    std::pair(EasyOption::PROXY_SSL_VERIFYHOST, CURLOPT_PROXY_SSL_VERIFYHOST),
    std::pair(EasyOption::PROXY_SSLVERSION, CURLOPT_PROXY_SSLVERSION),
    std::pair(EasyOption::PROXY_TLSAUTH_USERNAME, CURLOPT_PROXY_TLSAUTH_USERNAME),
    std::pair(EasyOption::PROXY_TLSAUTH_PASSWORD, CURLOPT_PROXY_TLSAUTH_PASSWORD),
    std::pair(EasyOption::PROXY_TLSAUTH_TYPE, CURLOPT_PROXY_TLSAUTH_TYPE),
    std::pair(EasyOption::PROXY_SSLCERT, CURLOPT_PROXY_SSLCERT),
    std::pair(EasyOption::PROXY_SSLCERTTYPE, CURLOPT_PROXY_SSLCERTTYPE),
    std::pair(EasyOption::PROXY_SSLKEY, CURLOPT_PROXY_SSLKEY),
    std::pair(EasyOption::PROXY_SSLKEYTYPE, CURLOPT_PROXY_SSLKEYTYPE),
    std::pair(EasyOption::PROXY_KEYPASSWD, CURLOPT_PROXY_KEYPASSWD),
    std::pair(EasyOption::PROXY_SSL_CIPHER_LIST, CURLOPT_PROXY_SSL_CIPHER_LIST),
    std::pair(EasyOption::PROXY_CRLFILE, CURLOPT_PROXY_CRLFILE),
    std::pair(EasyOption::PROXY_SSL_OPTIONS, CURLOPT_PROXY_SSL_OPTIONS),
    std::pair(EasyOption::PRE_PROXY, CURLOPT_PRE_PROXY),
    std::pair(EasyOption::PROXY_PINNEDPUBLICKEY, CURLOPT_PROXY_PINNEDPUBLICKEY),
    std::pair(EasyOption::ABSTRACT_UNIX_SOCKET, CURLOPT_ABSTRACT_UNIX_SOCKET),
    std::pair(EasyOption::SUPPRESS_CONNECT_HEADERS, CURLOPT_SUPPRESS_CONNECT_HEADERS),
    std::pair(EasyOption::REQUEST_TARGET, CURLOPT_REQUEST_TARGET),
    std::pair(EasyOption::SOCKS5_AUTH, CURLOPT_SOCKS5_AUTH),
    std::pair(EasyOption::SSH_COMPRESSION, CURLOPT_SSH_COMPRESSION),
    std::pair(EasyOption::MIMEPOST, CURLOPT_MIMEPOST),
    std::pair(EasyOption::TIMEVALUE_LARGE, CURLOPT_TIMEVALUE_LARGE),
    std::pair(EasyOption::HAPPY_EYEBALLS_TIMEOUT_MS, CURLOPT_HAPPY_EYEBALLS_TIMEOUT_MS),
    std::pair(EasyOption::RESOLVER_START_FUNCTION, CURLOPT_RESOLVER_START_FUNCTION),
    std::pair(EasyOption::RESOLVER_START_DATA, CURLOPT_RESOLVER_START_DATA),
    std::pair(EasyOption::HAPROXYPROTOCOL, CURLOPT_HAPROXYPROTOCOL),
    std::pair(EasyOption::DNS_SHUFFLE_ADDRESSES, CURLOPT_DNS_SHUFFLE_ADDRESSES),
    std::pair(EasyOption::TLS13_CIPHERS, CURLOPT_TLS13_CIPHERS),
    std::pair(EasyOption::PROXY_TLS13_CIPHERS, CURLOPT_PROXY_TLS13_CIPHERS),
    std::pair(EasyOption::DISALLOW_USERNAME_IN_URL, CURLOPT_DISALLOW_USERNAME_IN_URL),
    std::pair(EasyOption::DOH_URL, CURLOPT_DOH_URL),
    std::pair(EasyOption::UPLOAD_BUFFERSIZE, CURLOPT_UPLOAD_BUFFERSIZE),
    std::pair(EasyOption::UPKEEP_INTERVAL_MS, CURLOPT_UPKEEP_INTERVAL_MS),
    std::pair(EasyOption::CURLU, CURLOPT_CURLU),
    std::pair(EasyOption::TRAILERFUNCTION, CURLOPT_TRAILERFUNCTION),
    std::pair(EasyOption::TRAILERDATA, CURLOPT_TRAILERDATA),
    std::pair(EasyOption::HTTP09_ALLOWED, CURLOPT_HTTP09_ALLOWED),
    std::pair(EasyOption::ALTSVC_CTRL, CURLOPT_ALTSVC_CTRL),
    std::pair(EasyOption::ALTSVC, CURLOPT_ALTSVC),
    std::pair(EasyOption::MAXAGE_CONN, CURLOPT_MAXAGE_CONN),
    std::pair(EasyOption::SASL_AUTHZID, CURLOPT_SASL_AUTHZID),
    std::pair(EasyOption::MAIL_RCPT_ALLOWFAILS, CURLOPT_MAIL_RCPT_ALLOWFAILS),
    std::pair(EasyOption::SSLCERT_BLOB, CURLOPT_SSLCERT_BLOB),
    std::pair(EasyOption::SSLKEY_BLOB, CURLOPT_SSLKEY_BLOB),
    std::pair(EasyOption::PROXY_SSLCERT_BLOB, CURLOPT_PROXY_SSLCERT_BLOB),
    std::pair(EasyOption::PROXY_SSLKEY_BLOB, CURLOPT_PROXY_SSLKEY_BLOB),
    std::pair(EasyOption::ISSUERCERT_BLOB, CURLOPT_ISSUERCERT_BLOB),
    std::pair(EasyOption::PROXY_ISSUERCERT, CURLOPT_PROXY_ISSUERCERT),
    std::pair(EasyOption::PROXY_ISSUERCERT_BLOB, CURLOPT_PROXY_ISSUERCERT_BLOB),
    std::pair(EasyOption::SSL_EC_CURVES, CURLOPT_SSL_EC_CURVES),
    std::pair(EasyOption::HSTS_CTRL, CURLOPT_HSTS_CTRL),
    std::pair(EasyOption::HSTS, CURLOPT_HSTS),
    std::pair(EasyOption::HSTSREADFUNCTION, CURLOPT_HSTSREADFUNCTION),
    std::pair(EasyOption::HSTSREADDATA, CURLOPT_HSTSREADDATA),
    std::pair(EasyOption::HSTSWRITEFUNCTION, CURLOPT_HSTSWRITEFUNCTION),
    std::pair(EasyOption::HSTSWRITEDATA, CURLOPT_HSTSWRITEDATA),
    std::pair(EasyOption::AWS_SIGV4, CURLOPT_AWS_SIGV4),
    std::pair(EasyOption::DOH_SSL_VERIFYPEER, CURLOPT_DOH_SSL_VERIFYPEER),
    std::pair(EasyOption::DOH_SSL_VERIFYHOST, CURLOPT_DOH_SSL_VERIFYHOST),
    std::pair(EasyOption::DOH_SSL_VERIFYSTATUS, CURLOPT_DOH_SSL_VERIFYSTATUS),
    std::pair(EasyOption::CAINFO_BLOB, CURLOPT_CAINFO_BLOB),
    std::pair(EasyOption::PROXY_CAINFO_BLOB, CURLOPT_PROXY_CAINFO_BLOB),
    std::pair(EasyOption::SSH_HOST_PUBLIC_KEY_SHA256, CURLOPT_SSH_HOST_PUBLIC_KEY_SHA256),
    std::pair(EasyOption::PREREQFUNCTION, CURLOPT_PREREQFUNCTION),
    std::pair(EasyOption::PREREQDATA, CURLOPT_PREREQDATA),
    std::pair(EasyOption::MAXLIFETIME_CONN, CURLOPT_MAXLIFETIME_CONN),
    std::pair(EasyOption::MIME_OPTIONS, CURLOPT_MIME_OPTIONS),
    std::pair(EasyOption::SSH_HOSTKEYFUNCTION, CURLOPT_SSH_HOSTKEYFUNCTION),
    std::pair(EasyOption::SSH_HOSTKEYDATA, CURLOPT_SSH_HOSTKEYDATA),
    std::pair(EasyOption::PROTOCOLS_STR, CURLOPT_PROTOCOLS_STR),
    std::pair(EasyOption::REDIR_PROTOCOLS_STR, CURLOPT_REDIR_PROTOCOLS_STR),
    std::pair(EasyOption::WS_OPTIONS, CURLOPT_WS_OPTIONS),
    std::pair(EasyOption::CA_CACHE_TIMEOUT, CURLOPT_CA_CACHE_TIMEOUT),
    std::pair(EasyOption::QUICK_EXIT, CURLOPT_QUICK_EXIT),
    std::pair(EasyOption::HAPROXY_CLIENT_IP, CURLOPT_HAPROXY_CLIENT_IP)
};

} // namespace EasyOptionsToCurl

constexpr CURLoption convertOptToCurl(const EasyOption src) 
{
    for (auto pair : EasyOptionsToCurl::s_conv_table)
    {
        if (std::get<0>(pair) == src)
        {
            return std::get<1>(pair);
        }
    }

    return CURLOPT_LASTENTRY;
}

} // namespace CurlWrapper
