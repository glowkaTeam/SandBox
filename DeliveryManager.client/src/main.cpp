#include "curl_helper.hpp"
#include "json_helper.hpp"

#include <iostream>

int main()
{
    CurlURLDownloader downloader("https://deliverymanager.azurewebsites.net/api/test");
    // CurlURLDownloader downloader("https://raw.githubusercontent.com/curl/curl/master/docs/examples/https.c");

    downloader.configure();
    downloader.download();

    std::cout << "\n###########################################\n\n";
    std::cout << downloader.getDownloadedFile();
    std::cout << "\n###########################################\n\n";

    downloader.setURL("https://raw.githubusercontent.com/curl/curl/master/docs/examples/https.c");
    downloader.configure();
    downloader.download();

    std::cout << "\n###########################################\n\n";
    std::cout << downloader.getDownloadedFile();
    std::cout << "\n###########################################\n\n";
    return 0;
}
