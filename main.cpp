#include <iostream>
#include <curl/curl.h>
#include <json.hpp>

using json = nlohmann::json;


size_t waitingForData(void *ptr, size_t size, size_t nmemb, std::string *result)
{
    size_t result_length = size * nmemb;
    result->append((char *)ptr, result_length); 
    return result_length;
}

int main()
{
    std::cout << "curl started" << std::endl;
    CURL *curl;
    CURLcode res;
    std::string result;

    curl = curl_easy_init();
    if (curl == NULL)
    {
        std::cout << "curl not found" << std::endl;
        return -1;
    }
    if (curl)
    {
        curl_easy_setopt(curl, CURLOPT_URL, "https://jsonplaceholder.typicode.com/posts");
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, waitingForData);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &result);
        res = curl_easy_perform(curl);

        if (res != CURLE_OK)
        {
            std::cerr << "curl_easy_perform() failed: " << curl_easy_strerror(res) << std::endl;
        }
        else
        {
            std::cout << "Getting data:\n" << result << std::endl;

            json data = json::parse(result);

            for (const auto &post : data)
            {
                std::cout << "User ID: " << post["userId"]<< std::endl;
                std::cout << "Id: " << post["id"]<< std::endl;
                std::cout << "Title: " << post["title"] << std::endl;
                std::cout << "Body: "<< post["body"]<< std::endl;
            }
        }

        curl_easy_cleanup(curl);
    }

    return 0;
}