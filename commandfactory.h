#ifndef COMMANDFACTORY_H
#define COMMANDFACTORY_H
#include <map>

#include "XMCommand.h"

enum XTCommands { SET_MODE_DIAGNOSTIC, SET_MODE_OPERATE, SET_ANGLE, GET_ANGLE, 
	SET_STROKE, GET_STROKE, SET_VELOCITY, GET_VELOCITY, ARM, FIRE, RETRACT, 
    GO_POSITIION, POST, SET_REGISTER_REGISTERNAME_REGISTERDATA, GET_REGISTER_REGISTERNAME,
    MOVE_NDD_DOWN, MOVE_NDD_UP, NUM_OF_ITEMS};

class CommandFactory {
private:
    map<int, XMCommand*> mNDDCommands;
		BaseConnection *pConn = NULL;
public:
	CommandFactory(BaseConnection *pConnObj){
		pConn = pConnObj;
	}
	bool initialize();

	XMCommand* getCommand(XTCommands cmd);
};

#endif // COMMANDFACTORY_H
