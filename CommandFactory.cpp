#include "commandfactory.h"
#include "ArmCmd.h"
#include "FireCmd.h"
#include "GetAngleCmd.h"
#include "GetRegRegNameDiagCmd.h"
#include "GetStrokeCmd.h"
#include "GetVelocityCmd.h"
#include "GoPositionaaxxDiagCmd.h"
#include "PostDiagCmd.h"
#include "RetractCmd.h"
#include "SetaaAngleCmd.h"
#include "SetDiagModeCmd.h"
#include "SetOperModeCmd.h"
#include "SetRegRegNameRegdataDiagCmd.h"
#include "SetvvVelocityCmd.h"
#include "SetxxStrokeCmd.h"
#include "MoveNDDDownCmd.h"
#include "MoveNDDUpCmd.h"

bool CommandFactory::initialize(){
	XMCommand* NDDcmd;
	for (int index = XTCommands::SET_MODE_DIAGNOSTIC ; index <= XTCommands::NUM_OF_ITEMS; index++){
		NDDcmd = NULL;
		switch (index){
		case  SET_MODE_DIAGNOSTIC:
			NDDcmd = new SetDiagModeCmd(pConn);
			break;
		case  SET_MODE_OPERATE:
            NDDcmd = new SetOperModeCmd(pConn);
			break;
		case  SET_ANGLE:
			NDDcmd = new SetaaAngleCmd(pConn);
			break;
		case  GET_ANGLE:
			NDDcmd = new GetAngleCmd(pConn);
			break;
		case  SET_STROKE:
			NDDcmd = new SetStrokeCmd(pConn);
			break;
		case  GET_STROKE:
			NDDcmd = new GetStrokeCmd(pConn);
			break;
		case  SET_VELOCITY:
			NDDcmd = new SetvvVelocityCmd(pConn);
			break;
		case  GET_VELOCITY:
			NDDcmd = new GetVelocityCmd(pConn);
			break;
		case  ARM:
			NDDcmd = new ArmCmd(pConn);
			break;
		case  FIRE:
			NDDcmd = new FireCmd(pConn);
			break;
		case  RETRACT:
			NDDcmd = new RetractCmd(pConn);
			break;
		case  GO_POSITIION:
			NDDcmd = new GoPositionaaxxDiagCmd(pConn);
			break;
		case  POST:
			NDDcmd = new PostDiagCmd(pConn);
			break;
		case  SET_REGISTER_REGISTERNAME_REGISTERDATA:
			NDDcmd = new SetRegRegNameRegDataDiagCmd(pConn);
			break;
		case  GET_REGISTER_REGISTERNAME:
			NDDcmd = new GetRegRegNameDiagCmd(pConn);
			break;
        case  MOVE_NDD_DOWN:
            NDDcmd = new MoveNDDDownCmd(pConn);
            break;
        case  MOVE_NDD_UP:
            NDDcmd = new MoveNDDUpCmd(pConn);
            break;
		default:
			break;
		}
		if (NDDcmd != NULL){
			mNDDCommands[index] = NDDcmd;
		}
		else{
			//Exception
            return false;
		}
    }

    return true;
}

XMCommand* CommandFactory::getCommand(XTCommands cmd){

	XMCommand* NDDcmd = mNDDCommands[cmd];
	//NDDcmd->reset();
	return NDDcmd;
}
