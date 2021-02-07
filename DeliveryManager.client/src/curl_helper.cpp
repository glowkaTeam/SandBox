#include "curl_helper.hpp"

#include <iostream>

class CurlGlobalStateGuard {
public:
    CurlGlobalStateGuard()
    {
        curl_global_init(CURL_GLOBAL_DEFAULT);
    }
    ~CurlGlobalStateGuard()
    {
        curl_global_cleanup();
    }
};
static CurlGlobalStateGuard handle_curl_state;

CurlURLDownloader::CurlURLDownloader(std::string url)
    : url_(url)
{
    curlHandler_ = curl_easy_init();

    if (curlHandler_) {
        curl_easy_setopt(curlHandler_, CURLOPT_URL, url_.c_str());
        setSSL();
    }
}

CurlURLDownloader::~CurlURLDownloader()
{
    curl_easy_cleanup(curlHandler_);
}

void CurlURLDownloader::setSSL()
{
    curl_easy_setopt(curlHandler_, CURLOPT_SSL_VERIFYPEER, 0L);
    curl_easy_setopt(curlHandler_, CURLOPT_SSL_VERIFYHOST, 0L);
}

std::string& CurlURLDownloader::downloadFile()
{
    fileContent_ = "";

    auto res = curl_easy_perform(curlHandler_);
    if (res != CURLE_OK) {
        std::cerr << "curl_easy_perform() failed:" << curl_easy_strerror(res) << std::endl;
    }
    return fileContent_;
}