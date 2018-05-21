#include "FireCmd.h"

void FireCmd::prepareCommand() {

	msCmdRequest = new string();

	if (msCmdRequest == NULL){
		//Logger
		//raise Exception
	}
	if (msCmdRequest) {
		msCmdRequest->append(msBaseCmdString);
		if (mbhasVariableCmdString) {
			msCmdRequest->append(*msVariableCmdString);
		}
	}
}

void FireCmd::execute() {
    //TODO : Refactor this function
    //may be move common code to base class
    if ( pConn == NULL){
        //Logger & Exception
    }

    QT_INT64 numOfBytesSend = pConn ->sendStream(msCmdRequest);
    //remove below function, this is just for testing, put it in a separate receive function

    //BaseConnection* precvConn = getRecvSerialPortConnection();
    pConn ->recvStream();

}

void FireCmd::commandExecStatus(){

}

void FireCmd::prepareCommandShort(){

}

void FireCmd::reset(){

}
