#pragma once


//All thanks to jazzisparis for the code, since it's way faster than tanf.

inline float tan_p(float angle)
{
	angle *= kDbl4dPI;
	double ang2 = angle * angle;
	return angle * (211.849369664121 - 12.5288887278448 * ang2) / (269.7350131214121 + ang2 * (ang2 - 71.4145309347748));
}


 
 __forceinline float dTan(float angle) {
	 {
		 while (angle > kDblPIx2)
			 angle -= kDblPIx2;

		 int octant = int(angle * kDbl4dPI);
		 switch (octant)
		 {
		 case 0:
			 return tan_p(angle);
		 case 1:
			 return 1.0 / tan_p(kDblPId2 - angle);
		 case 2:
			 return -1.0 / tan_p(angle - kDblPId2);
		 case 3:
			 return -tan_p(kDblPI - angle);
		 case 4:
			 return tan_p(angle - kDblPI);
		 case 5:
			 return 1.0 / tan_p(kDblPIx3d2 - angle);
		 case 6:
			 return -1.0 / tan_p(angle - kDblPIx3d2);
		 default:
			 return -tan_p(kDblPIx2 - angle);
		 }
	 }
 }

float fastDTan(float value) {
	bool sign = (value < 0);
	if (sign) value = -value;
	float tempRes = dTan(value * kDblPId180);
	return (sign ? -tempRes : tempRes);
}


//As defined in NVSE.


#define PASS_VARARGS  scriptObj, eventList
#define VARARGS Script *scriptObj, ScriptEventList *eventList



void setVarByName(VARARGS, const char *var_name, float value)
{
	ListNode<VariableInfo>* traverse = scriptObj->varList.Head();
	VariableInfo *varInfo;
	do
	{
		varInfo = traverse->data;
		if (!strcmp(((char*)varInfo->name.CStr()), var_name))
		{
			eventList->GetVariable(varInfo->idx)->data = value;
			break;
		}
	} while (traverse = traverse->next);

}

class LevelUpMenu : public Menu {
public:
	LevelUpMenu();
	~LevelUpMenu();
	UInt32 isPerkMenu;
	TileText *tile2C;
	TileImage *tile30;
	TileImage *tile34;
	TileImage *tile38;
	TileText *tile3C;
	TileText *tile40;
	TileImage *tile44;
	TileImage *tile48;
	TileImage *tile4C;
	TileImage *tile50;
	UInt32 unk54;
	UInt32 unk58;
	UInt32 unk5C;
	UInt32 unk60;
	UInt32 listBoxActorValue[12];
	UInt32 listBoxPerk[12];
	UInt32 unkC4[2];
};



