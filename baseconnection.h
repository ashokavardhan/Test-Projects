#ifndef BASECONNECTION_H
#define BASECONNECTION_H

#include "Util.h"

#ifdef _WIN32
typedef __int64 QT_INT64;
#else
typedef long long int QT_INT64;
#endif

class BaseConnection {
private:

public:
    BaseConnection(){


    }
    virtual QT_INT64 sendStream(string* mpStream){
        return -1;
    }
    virtual string* recvStream(){
        return NULL;
    }

};

#endif // BASECONNECTION_H
