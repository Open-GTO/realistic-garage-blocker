/*=========================================================*\
|--------------------------[How To]-------------------------|
|   	  Use BlockGarages(); to block the garages. 	  	|
|   	  Add a .text="" parameter to set the text.  	 	|
|   	Add a .type=int parameter to block one type.     	|
|	 Add a .block=bool parameter to set remove or block. 	|
|-----------------------------------------------------------|
\*=========================================================*/

/*
native BlockGarages(bool:block=true, GarageType:type=GARAGE_TYPE_ALL, text[]="");
*/

#if !defined _samp_included
	#error "Please include a_samp or a_npc before skinselect"
#endif

#if !defined _streamer_included
	#error "Please include streamer before garage_block"
#endif

#if defined _garage_block_included
	#endinput
#endif

#define _garage_block_included

enum (<< 1) {
	GARAGE_BLOCK_ALL = -1,
	GARAGE_BLOCK_DISABLED = 0,
	GARAGE_BLOCK_PAINT = 1,
	GARAGE_BLOCK_BOMB,
	GARAGE_BLOCK_MODSHOP,
};

enum E_GARAGE_BLOCKS {
	GarageType:E_GB_TYPE,
	E_GB_OBJECT,
	Float:E_GB_POS_X,
	Float:E_GB_POS_Y,
	Float:E_GB_POS_Z,
	Float:E_GB_POS_R,
};

static gGarageBlocks[][E_GARAGE_BLOCKS] = {
	{GARAGE_TYPE_PAINT, INVALID_OBJECT_ID, 1968.74219, 2162.49219, 12.09380, 0.0},
	{GARAGE_TYPE_BOMB, INVALID_OBJECT_ID, 2006.00000, 2303.72656, 11.31250, 90.0},
	{GARAGE_TYPE_BOMB, INVALID_OBJECT_ID, 2006.00000, 2317.60156, 11.31250, -90.0},
	{GARAGE_TYPE_PAINT, INVALID_OBJECT_ID, 720.01563, -462.52341, 16.85940, 90.0},
	{GARAGE_TYPE_PAINT, INVALID_OBJECT_ID, -100.00000, 1111.41406, 21.14060, 90.0},
	{GARAGE_TYPE_PAINT, INVALID_OBJECT_ID, -1420.52686, 2591.15747, 57.24220,-90.0},
	{GARAGE_TYPE_BOMB, INVALID_OBJECT_ID, 1843.36719, -1856.32031, 13.87500, 0.0},
	{GARAGE_TYPE_MODSHOP INVALID_OBJECT_ID, -2716.35156, 217.47659, 5.38280, 180.0},
	{GARAGE_TYPE_MODSHOP INVALID_OBJECT_ID, -1935.85938, 239.53130, 35.35160, 90.0},
	{GARAGE_TYPE_PAINT, INVALID_OBJECT_ID, -1904.53125, 277.89841, 42.45310, 90.0},
	{GARAGE_TYPE_PAINT, INVALID_OBJECT_ID, -1786.81250, 1209.42188, 25.83590, 90.0},
	{GARAGE_TYPE_ALL, INVALID_OBJECT_ID, 1798.68750, -2146.73438, 14.00000, 0.0},
	{GARAGE_TYPE_MODSHOP INVALID_OBJECT_ID, 2644.85938, -2039.23438, 14.03910, -90.0},
	{GARAGE_TYPE_PAINT, INVALID_OBJECT_ID, 2071.47656, -1831.42188, 14.56250, 180.0},
	{GARAGE_TYPE_PAINT, INVALID_OBJECT_ID, 488.28131, -1734.69531, 12.39060, -101.0},
	{GARAGE_TYPE_PAINT, INVALID_OBJECT_ID, -2425.72656, 1027.99219, 51.78130, -90.0},
	{GARAGE_TYPE_PAINT, INVALID_OBJECT_ID, 2393.76563, 1483.68750, 12.21090, 90.0},
	{GARAGE_TYPE_MODSHOP INVALID_OBJECT_ID, 2386.65625, 1043.60156, 11.59380, 90.0},
	{GARAGE_TYPE_PAINT, INVALID_OBJECT_ID, 1025.01672, -1029.21533, 33.11600, 90.0},
	{GARAGE_TYPE_MODSHOP, INVALID_OBJECT_ID, 1041.35254, -1025.90967, 32.67188, 90.0}
};

stock ToggleGaragesBlock(block = GARAGE_BLOCK_ALL, text[] = "")
{
	if (block == false) {
		for (new i; i < sizeof(gGarageBlocks); i++) {
			if (!(gGarageBlocks[i][E_GB_TYPE] & block)) {
				continue;
			}

			DestroyDynamicObject(gGarageBlocks[i][E_GB_OBJECT]);
		}
	} else {
		for (new i; i < sizeof(gGarageBlocks); i++) {
			if (!(gGarageBlocks[i][E_GB_TYPE] & block)) {
				continue;
			}

			DestroyDynamicObject(gGarageBlocks[i][E_GB_OBJECT]);
			
			gGarageBlocks[i][E_GB_OBJECT] = CreateDynamicObject(19325, gGarageBlocks[i][E_GB_POS_X], gGarageBlocks[i][E_GB_POS_Y], gGarageBlocks[i][E_GB_POS_Z], 0.00000, 0.00000, gGarageBlocks[i][E_GB_POS_R,]);
			
			if (strlen(text) != 0) {
				SetDynamicObjectMaterialText(gGarageBlocks[i][E_GB_OBJECT], 0, text, OBJECT_MATERIAL_SIZE_128x128, "Arial", 16, 0, 0xFFFF0000, 0x00000000, OBJECT_MATERIAL_TEXT_ALIGN_CENTER);
			} else {
				SetDynamicObjectMaterial(gGarageBlocks[i][E_GB_OBJECT], 0, 0, "none", "none", 0x00FFFFFF);
			}
		}
	}

	return 1;
}
