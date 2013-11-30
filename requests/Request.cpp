//
//  Request.cpp
//  requests
//
//  Created by kwaw on 30/11/2013.
//  Copyright (c) 2013 kwaw. All rights reserved.
//

#include "Request.h"

Requests::Requests(const std::string& url)
: curlHandle(curl_easy_init(), &curl_easy_cleanup)
{
    curl_easy_setopt(curlHandle.get(), CURLOPT_URL, url.c_str());
    curl_easy_setopt(curlHandle.get(), CURLOPT_WRITEDATA, &content_);
    curl_easy_setopt(curlHandle.get(), CURLOPT_WRITEFUNCTION, &Requests::handle);
    curl_easy_setopt(curlHandle.get(), CURLOPT_FOLLOWLOCATION, 1L);
}

size_t Requests::handle(char * data, size_t size, size_t nmemb, void * p){
    std::string *stuff = static_cast<std::string*>(p);
    stuff->append(data, size * nmemb);
    return size * nmemb;
}

void Requests::send() {
    content_.clear();
    curl_easy_perform(curlHandle.get());
}

void Requests::console_log(std::ostream& stream){
    stream << content_;
}

void Requests::str_log(std::string& strem){
    strem = content_;
}

