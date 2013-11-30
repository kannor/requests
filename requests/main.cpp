//
//  main.cpp
//  requests
//
//  Created by kwaw on 30/11/2013.
//  Copyright (c) 2013 kwaw. All rights reserved.
//

#include <iostream>
#include "Request.h"

int main()
{
    std::string url = "https://www.googleapis.com/books/v1/volumes?q=flowers&projection=lite&key=AIzaSyBfFi4Yy5m9cH86C5Kzacnw-Dyi7WJsSCs";
    
    std::string content;
    
    
    Requests request(url);
    
    request.send();
    //request.console_log(std::cout);
    //request.str_log(content);
    
    content = request.response();
    
    std::cout << content;
}
