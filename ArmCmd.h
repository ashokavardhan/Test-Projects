#include "XMCommand.h"

;
class ArmCmd : public XMCommand {

public:
    ArmCmd(BaseConnection* mpConn) :XMCommand(mpConn) {
		//super(mpConn);a

        msBaseCmdString = "ARM";
	}

	~ArmCmd(){

	}

public:
	virtual void prepareCommand();
	virtual void prepareCommandShort();
	virtual void execute();
	virtual void commandExecStatus();
	virtual void reset();

};
