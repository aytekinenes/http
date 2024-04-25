#include <iostream>
#include <curl/curl.h>

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

    if( result != CURLE_OK)
    {
        cout << "curl error" << endl;
    }
    curl_easy_cleanup(curl);



    return 0;
}