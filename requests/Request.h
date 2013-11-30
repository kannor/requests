//
//  Request.h
//  requests
//
//  Created by kwaw on 30/11/2013.
//  Copyright (c) 2013 kwaw. All rights reserved.
//

#ifndef __requests__Request__
#define __requests__Request__

#include <iostream>

#endif /* defined(__requests__Request__) */


#include <curl/curl.h>


class Requests
{
public:
    Requests(const std::string& url);
    void send();
    void console_log(std::ostream& stream);
    void str_log(std::string& strem);
private:
    typedef void (*cleanup)(CURL*);
    typedef std::unique_ptr<CURL, cleanup> CurlHandle;
    
    CurlHandle curlHandle;
    std::string content_;
    
    static size_t handle(char * data, size_t size, size_t nmemb, void * p);
};


