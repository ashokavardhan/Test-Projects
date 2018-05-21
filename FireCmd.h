#include "XMCommand.h"

class FireCmd : public XMCommand {

public:
	FireCmd(BaseConnection* mpConn) :XMCommand(mpConn) {
		//super(mpConn);a

        msBaseCmdString = "FIRE";
	}

	~FireCmd(){

	}

public:
	virtual void prepareCommand();
	virtual void prepareCommandShort();
	virtual void execute();
	virtual void commandExecStatus();
	virtual void reset();

};
