#include "curl_helper.hpp"
#include "dummy.hpp"

#include <iostream>

int main()
{
    CurlURLDownloader downloader("https://deliverymanager.azurewebsites.net/api/test");
    // CurlURLDownloader downloader("https://raw.githubusercontent.com/curl/curl/master/docs/examples/https.c");

    std::cout << downloader.getURL() << '\n';

    std::cout << "\n###########################################\n\n";
    std::cout << downloader.downloadFile();
    std::cout << "\n###########################################\n\n";
    return 0;
}
