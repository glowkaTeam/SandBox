#pragma once

#include <curl/curl.h>
#include <string>

class CurlURLDownloader {
public:
    CurlURLDownloader(std::string url = "");
    ~CurlURLDownloader();
    void configure();
    void download();
    void setURL(std::string url) { url_ = url; };
    const std::string& getURL() { return url_; };
    const std::string& getDownloadedFile() { return fileContent_; };

private:
    CURL* curlHandler_;
    std::string url_;
    std::string fileContent_;

    void setSSL();
};
