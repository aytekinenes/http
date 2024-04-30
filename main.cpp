#include <iostream>
#include <curl/curl.h>
#include "json.hpp"

using json = nlohmann::json;
using namespace std;

int main()
{
    cout << "curl started"<< endl;
    CURL *curl;
    CURLcode result;

    curl = curl_easy_init();
    if(curl == NULL)
    {
        cout<< "curl not found"<< endl;
        return -1;
    }
    curl_easy_setopt(curl, CURLOPT_URL, "https://jsonplaceholder.typicode.com/posts");

    result = curl_easy_perform(curl);

        // JSON verilerini parse edelim
    if (result != CURLE_OK) 
    {
        cout << "curl error: " << curl_easy_strerror(result) << endl;
    } 
    else 
    {
        json responseData = json::parse(curl_easy_strerror(result));
        for (const auto& item : responseData) 
        {
            cout << "User ID: " << item["userId"] << ", ID: " << item["id"] << ", Title: " << item["title"] << endl;
        }
    }

    return 0;
}