#pragma warning(disable:4996)
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include <curl/curl.h>
//
//#define URL_LENGTH 256
//
//size_t write_data(void* ptr, size_t size, size_t nmemb, FILE* stream) {
//    size_t written = fwrite(ptr, size, nmemb, stream);
//    return written;
//}
//
//int main(int argc, char** argv) {
//    if (argc != 2) { // 只接受一个命令行参数，即视频链接地址
//        fprintf(stderr, "Usage: %s <video-link>", argv[0]);
//        exit(EXIT_FAILURE);
//    }
//
//    char url[URL_LENGTH];
//    strncpy(url, "", URL_LENGTH);
//
//    CURL* curl_handle;
//    CURLcode res;
//
//    FILE* video_file;
//    video_file = fopen("D:\\video.mp4", "wb");
//    if (!video_file) {
//        fprintf(stderr, "Cannot create file");
//        exit(EXIT_FAILURE);
//    }
//
//    curl_handle = curl_easy_init();
//    curl_easy_setopt(curl_handle, CURLOPT_URL, url);
//    curl_easy_setopt(curl_handle, CURLOPT_FOLLOWLOCATION, 1L);
//    curl_easy_setopt(curl_handle, CURLOPT_WRITEFUNCTION, write_data);
//    curl_easy_setopt(curl_handle, CURLOPT_WRITEDATA, video_file);
//    res = curl_easy_perform(curl_handle);
//    if (res != CURLE_OK) {
//        fprintf(stderr, "curl_easy_perform() failed: %s", curl_easy_strerror(res));
//    }
//
//    curl_easy_cleanup(curl_handle);
//    fclose(video_file);
//
//    printf("Video downloaded successfully.");
//
//        return 0;
//}
#include <stdio.h>
#include <curl/curl.h>

#define false 0
#define true 1

int download_video(char* url) {
    CURL* curl_handle;
    CURLcode result;

    FILE* fp;
    fp = fopen("video.mp4", "wb");
    if (!fp) {
        fprintf(stderr, "Cannot create file.");
            return false;
    }

    curl_global_init(CURL_GLOBAL_ALL);
    curl_handle = curl_easy_init();
    curl_easy_setopt(curl_handle, CURLOPT_URL, url);
    curl_easy_setopt(curl_handle, CURLOPT_FOLLOWLOCATION, 1L);
    curl_easy_setopt(curl_handle, CURLOPT_WRITEFUNCTION, fwrite);
    curl_easy_setopt(curl_handle, CURLOPT_WRITEDATA, fp);
    result = curl_easy_perform(curl_handle);

    if (result != CURLE_OK) {
        fprintf(stderr, "curl_easy_perform() failed: %s ", curl_easy_strerror(result));
        return false;
    }

    curl_easy_cleanup(curl_handle);
    fclose(fp);
    return true;
}

int main(void)
{
    char* url = "https://fd.aigei.com/src/vdo/mp4/18/1802856622b7471483be2a5c06779501.mp4";  // 需要下载的视频链接
    int res = download_video(url);
    if (res == true) {
        printf("Video downloaded successfully! ");
    }
    else {
        printf("Video download failed. ");
    }
    return 0;
}
