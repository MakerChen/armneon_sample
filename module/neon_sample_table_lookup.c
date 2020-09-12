#include "neon_sample.h"

// https://developer.arm.com/documentation/dui0472/m/using-neon-support/neon-intrinsics-for-table-look-up
// https://developer.arm.com/documentation/dui0472/m/using-neon-support/neon-intrinsics-for-extended-table-look-up

// -----------------------------------------------------------------------------
void NeonSample_TableLookUp_U8_U8_U8()
{
	uint8_t		au8DataInA[8];
	uint8_t		au8DataInB[8];
	uint8_t		au8DataOut[8];

	uint8x8_t	vu8x8InputA;
	uint8x8_t	vu8x8InputB;
	uint8x8_t	vu8x8Output;

	uint32_t	u32Idx;

	// initial
	au8DataInA[0] = 100;	au8DataInB[0] = 10;
	au8DataInA[1] = 110;	au8DataInB[1] = 6;
	au8DataInA[2] = 120;	au8DataInB[2] = 5;
	au8DataInA[3] = 130;	au8DataInB[3] = 4;
	au8DataInA[4] = 140;	au8DataInB[4] = 3;
	au8DataInA[5] = 150;	au8DataInB[5] = 2;
	au8DataInA[6] = 160;	au8DataInB[6] = 1;
	au8DataInA[7] = 170;	au8DataInB[7] = 0;

	vu8x8InputA		= vld1_u8(au8DataInA);
	vu8x8InputB		= vld1_u8(au8DataInB);

	// uint8x8_t vtbl1_u8(uint8x8_t a, uint8x8_t b);							// VTBL.8 d0, {d0}, d0
	// output = a[b]
	vu8x8Output		= vtbl1_u8(vu8x8InputA, vu8x8InputB);
	vst1_u8(au8DataOut, vu8x8Output);

	printf("== Table LookUp u8 = u8, u8 (vtbl1_u8) ==\n");

	printf("Table :\n");
	for (u32Idx = 0; u32Idx < 8; ++u32Idx)
	{
		printf("[%1d] : %3d\n",
			u32Idx, au8DataInA[u32Idx]);
	}
	printf("\n");

	printf("Output :\n");
	for (u32Idx = 0; u32Idx < 8; ++u32Idx)
	{
		printf("[%1d], index: %3d, value : %3d\n",
			u32Idx, au8DataInB[u32Idx], au8DataOut[u32Idx]);
	}
	printf("\n");
	printf("========================================\n");
}

// -----------------------------------------------------------------------------
void NeonSample_TableLookUp_S8_S8_S8()
{
	int8_t		as8DataInA[8];
	int8_t		as8DataInB[8];
	int8_t		as8DataOut[8];

	int8x8_t	vs8x8InputA;
	int8x8_t	vs8x8InputB;
	int8x8_t	vs8x8Output;

	uint32_t	u32Idx;

	// initial
	as8DataInA[0] = 30;		as8DataInB[0] = 10;
	as8DataInA[1] = 60;		as8DataInB[1] = 6;
	as8DataInA[2] = 90;		as8DataInB[2] = 5;
	as8DataInA[3] = 120;	as8DataInB[3] = 4;
	as8DataInA[4] = -120;	as8DataInB[4] = 3;
	as8DataInA[5] = -90;	as8DataInB[5] = 2;
	as8DataInA[6] = -60;	as8DataInB[6] = 1;
	as8DataInA[7] = -30;	as8DataInB[7] = -1;

	vs8x8InputA		= vld1_s8(as8DataInA);
	vs8x8InputB		= vld1_s8(as8DataInB);

	// int8x8_t vtbl1_s8(int8x8_t a, int8x8_t b);								// VTBL.8 d0, {d0}, d0
	// output = a[b]
	vs8x8Output		= vtbl1_s8(vs8x8InputA, vs8x8InputB);
	vst1_s8(as8DataOut, vs8x8Output);

	printf("== Table LookUp s8 = s8, s8 (vtbl1_s8) ==\n");

	printf("Table :\n");
	for (u32Idx = 0; u32Idx < 8; ++u32Idx)
	{
		printf("[%1d] : %4d\n",
			u32Idx, as8DataInA[u32Idx]);
	}
	printf("\n");

	printf("Output :\n");
	for (u32Idx = 0; u32Idx < 8; ++u32Idx)
	{
		printf("[%1d], index: %4d, value : %4d\n",
			u32Idx, as8DataInB[u32Idx], as8DataOut[u32Idx]);
	}
	printf("\n");
	printf("========================================\n");
}

// -----------------------------------------------------------------------------
void NeonSample_TableLookUp_P8_P8_U8()
{
	poly8_t		ap8DataInA[8];
	uint8_t		au8DataInB[8];
	poly8_t		ap8DataOut[8];

	poly8x8_t	vp8x8InputA;
	uint8x8_t	vu8x8InputB;
	poly8x8_t	vp8x8Output;

	uint32_t	u32Idx;

	// initial
	ap8DataInA[0] = 0b00000001;		au8DataInB[0] = 10;
	ap8DataInA[1] = 0b00000010;		au8DataInB[1] = 6;
	ap8DataInA[2] = 0b00000100;		au8DataInB[2] = 5;
	ap8DataInA[3] = 0b00001000;		au8DataInB[3] = 4;
	ap8DataInA[4] = 0b00010000;		au8DataInB[4] = 3;
	ap8DataInA[5] = 0b00100000;		au8DataInB[5] = 2;
	ap8DataInA[6] = 0b01000000;		au8DataInB[6] = 1;
	ap8DataInA[7] = 0b10000000;		au8DataInB[7] = 0;

	vp8x8InputA		= vld1_p8(ap8DataInA);
	vu8x8InputB		= vld1_u8(au8DataInB);

	// poly8x8_t vtbl1_p8(poly8x8_t a, uint8x8_t b);							// VTBL.8 d0, {d0}, d0
	// output = a[b]
	vp8x8Output		= vtbl1_p8(vp8x8InputA, vu8x8InputB);
	vst1_p8(ap8DataOut, vp8x8Output);

	printf("== Table LookUp p8 = p8, u8 (vtbl1_p8) ==\n");

	printf("Table :\n");
	for (u32Idx = 0; u32Idx < 8; ++u32Idx)
	{
		printf("[%1d] : "UINT8_TO_BIT_PATTERN"\n",
			u32Idx, UINT8_TO_BIT(ap8DataInA[u32Idx]));
	}
	printf("\n");

	printf("Output :\n");
	for (u32Idx = 0; u32Idx < 8; ++u32Idx)
	{
		printf("[%1d], index: %3d, value : "UINT8_TO_BIT_PATTERN"\n",
			u32Idx, au8DataInB[u32Idx], UINT8_TO_BIT(ap8DataOut[u32Idx]));
	}
	printf("\n");
	printf("========================================\n");
}

// -----------------------------------------------------------------------------
void NeonSample_TableLookUp_U8_U82_U8()
{
	uint8_t		au8DataInA[16];
	uint8_t		au8DataInB[8];
	uint8_t		au8DataOut[8];

	uint8x8x2_t	vu8x8x2InputA;
	uint8x8_t	vu8x8InputB;
	uint8x8_t	vu8x8Output;

	uint32_t	u32Idx, u32Idx2;

	// initial
	au8DataInA[0] = 100;	au8DataInA[1] = 10;
	au8DataInA[2] = 110;	au8DataInA[3] = 20;
	au8DataInA[4] = 120;	au8DataInA[5] = 30;
	au8DataInA[6] = 130;	au8DataInA[7] = 40;
	au8DataInA[8] = 140;	au8DataInA[9] = 50;
	au8DataInA[10] = 150;	au8DataInA[11] = 60;
	au8DataInA[12] = 160;	au8DataInA[13] = 70;
	au8DataInA[14] = 170;	au8DataInA[15] = 80;

	au8DataInB[0] = 14;
	au8DataInB[1] = 12;
	au8DataInB[2] = 10;
	au8DataInB[3] = 8;
	au8DataInB[4] = 6;
	au8DataInB[5] = 4;
	au8DataInB[6] = 2;
	au8DataInB[7] = 0;

	vu8x8x2InputA	= vld2_u8(au8DataInA);
	vu8x8InputB		= vld1_u8(au8DataInB);

	// uint8x8_t vtbl2_u8(uint8x8x2_t a, uint8x8_t b);							// VTBL.8 d0, {d0, d1}, d0
	// output = a[b]
	vu8x8Output		= vtbl2_u8(vu8x8x2InputA, vu8x8InputB);
	vst1_u8(au8DataOut, vu8x8Output);

	printf("== Table LookUp u8 = u82, u8 (vtbl2_u8) ==\n");

	printf("Table :\n");
	for (u32Idx = 0, u32Idx2 = 0; u32Idx < 8; ++u32Idx, u32Idx2 += 2)
	{
		printf("[%2d] : %3d\n",
			u32Idx, au8DataInA[u32Idx2]);
	}
	for (u32Idx = 0, u32Idx2 = 1; u32Idx < 8; ++u32Idx, u32Idx2 += 2)
	{
		printf("[%2d] : %3d\n",
			u32Idx + 8, au8DataInA[u32Idx2]);
	}
	printf("\n");

	printf("Output :\n");
	for (u32Idx = 0; u32Idx < 8; ++u32Idx)
	{
		printf("[%1d], index: %3d, value : %3d\n",
			u32Idx, au8DataInB[u32Idx], au8DataOut[u32Idx]);
	}
	printf("\n");
	printf("========================================\n");
}

// -----------------------------------------------------------------------------
void NeonSample_TableLookUp_S8_S82_S8()
{
	int8_t		as8DataInA[16];
	int8_t		as8DataInB[8];
	int8_t		as8DataOut[8];

	int8x8x2_t	vs8x8x2InputA;
	int8x8_t	vs8x8InputB;
	int8x8_t	vs8x8Output;

	uint32_t	u32Idx, u32Idx2;

	// initial
	as8DataInA[0] = 50;		as8DataInA[1] = -100;
	as8DataInA[2] = 60;		as8DataInA[3] = -90;
	as8DataInA[4] = 70;		as8DataInA[5] = -80;
	as8DataInA[6] = 80;		as8DataInA[7] = -70;
	as8DataInA[8] = 90;		as8DataInA[9] = -60;
	as8DataInA[10] = 100;	as8DataInA[11] = -50;
	as8DataInA[12] = 110;	as8DataInA[13] = -40;
	as8DataInA[14] = 120;	as8DataInA[15] = -30;

	as8DataInB[0] = 1;
	as8DataInB[1] = 3;
	as8DataInB[2] = 5;
	as8DataInB[3] = 7;
	as8DataInB[4] = 9;
	as8DataInB[5] = 11;
	as8DataInB[6] = 13;
	as8DataInB[7] = 19;

	vs8x8x2InputA	= vld2_s8(as8DataInA);
	vs8x8InputB		= vld1_s8(as8DataInB);

	// int8x8_t vtbl2_s8(int8x8x2_t a, int8x8_t b);								// VTBL.8 d0, {d0, d1}, d0
	// output = a[b]
	vs8x8Output		= vtbl2_s8(vs8x8x2InputA, vs8x8InputB);
	vst1_s8(as8DataOut, vs8x8Output);

	printf("== Table LookUp s8 = s82, s8 (vtbl2_s8) ==\n");

	printf("Table :\n");
	for (u32Idx = 0, u32Idx2 = 0; u32Idx < 8; ++u32Idx, u32Idx2 += 2)
	{
		printf("[%2d] : %4d\n",
			u32Idx, as8DataInA[u32Idx2]);
	}
	for (u32Idx = 0, u32Idx2 = 1; u32Idx < 8; ++u32Idx, u32Idx2 += 2)
	{
		printf("[%2d] : %4d\n",
			u32Idx + 8, as8DataInA[u32Idx2]);
	}
	printf("\n");

	printf("Output :\n");
	for (u32Idx = 0; u32Idx < 8; ++u32Idx)
	{
		printf("[%1d], index: %3d, value : %4d\n",
			u32Idx, as8DataInB[u32Idx], as8DataOut[u32Idx]);
	}
	printf("\n");
	printf("========================================\n");
}

// -----------------------------------------------------------------------------
void NeonSample_TableLookUp_P8_P82_U8()
{
	poly8_t		ap8DataInA[16];
	uint8_t		au8DataInB[8];
	poly8_t		ap8DataOut[8];

	poly8x8x2_t	vp8x8x2InputA;
	uint8x8_t	vu8x8InputB;
	poly8x8_t	vp8x8Output;

	uint32_t	u32Idx, u32Idx2;

	// initial
	ap8DataInA[0]	= 0b00000001;	ap8DataInA[1]	= 0b00010001;
	ap8DataInA[2]	= 0b00000010;	ap8DataInA[3]	= 0b00100010;
	ap8DataInA[4]	= 0b00000100;	ap8DataInA[5]	= 0b01000100;
	ap8DataInA[6]	= 0b00001000;	ap8DataInA[7]	= 0b10001000;
	ap8DataInA[8]	= 0b00010000;	ap8DataInA[9]	= 0b00011111;
	ap8DataInA[10]	= 0b00100000;	ap8DataInA[11]	= 0b00101111;
	ap8DataInA[12]	= 0b01000000;	ap8DataInA[13]	= 0b01001111;
	ap8DataInA[14]	= 0b10000000;	ap8DataInA[15]	= 0b10001111;

	au8DataInB[0] = 1;
	au8DataInB[1] = 3;
	au8DataInB[2] = 5;
	au8DataInB[3] = 7;
	au8DataInB[4] = 9;
	au8DataInB[5] = 11;
	au8DataInB[6] = 13;
	au8DataInB[7] = 19;

	vp8x8x2InputA	= vld2_p8(ap8DataInA);
	vu8x8InputB		= vld1_u8(au8DataInB);

	// poly8x8_t vtbl2_p8(poly8x8x2_t a, uint8x8_t b);							// VTBL.8 d0, {d0, d1}, d0
	// output = a[b]
	vp8x8Output		= vtbl2_p8(vp8x8x2InputA, vu8x8InputB);
	vst1_p8(ap8DataOut, vp8x8Output);

	printf("== Table LookUp p8 = p82, u8 (vtbl2_p8) ==\n");

	printf("Table :\n");
	for (u32Idx = 0, u32Idx2 = 0; u32Idx < 8; ++u32Idx, u32Idx2 += 2)
	{
		printf("[%2d] : "UINT8_TO_BIT_PATTERN"\n",
			u32Idx, UINT8_TO_BIT(ap8DataInA[u32Idx2]));
	}
	for (u32Idx = 0, u32Idx2 = 1; u32Idx < 8; ++u32Idx, u32Idx2 += 2)
	{
		printf("[%2d] : "UINT8_TO_BIT_PATTERN"\n",
			u32Idx + 8, UINT8_TO_BIT(ap8DataInA[u32Idx2]));
	}
	printf("\n");

	printf("Output :\n");
	for (u32Idx = 0; u32Idx < 8; ++u32Idx)
	{
		printf("[%1d], index: %3d, value : "UINT8_TO_BIT_PATTERN"\n",
			u32Idx, au8DataInB[u32Idx], UINT8_TO_BIT(ap8DataOut[u32Idx]));
	}
	printf("\n");
	printf("========================================\n");
}

// -----------------------------------------------------------------------------
void NeonSample_TableLookUp_U8_U8_U8_U8()
{
	uint8_t		au8DataInA[8];
	uint8_t		au8DataInB[8];
	uint8_t		au8DataInC[8];
	uint8_t		au8DataOut[8];

	uint8x8_t	vu8x8InputA;
	uint8x8_t	vu8x8InputB;
	uint8x8_t	vu8x8InputC;
	uint8x8_t	vu8x8Output;

	uint32_t	u32Idx;

	// initial
	au8DataInA[0] = 100;	au8DataInB[0] = 70;		au8DataInC[0] = 9;
	au8DataInA[1] = 110;	au8DataInB[1] = 60;		au8DataInC[1] = 1;
	au8DataInA[2] = 120;	au8DataInB[2] = 50;		au8DataInC[2] = 2;
	au8DataInA[3] = 130;	au8DataInB[3] = 40;		au8DataInC[3] = 3;
	au8DataInA[4] = 140;	au8DataInB[4] = 30;		au8DataInC[4] = 4;
	au8DataInA[5] = 150;	au8DataInB[5] = 20;		au8DataInC[5] = 5;
	au8DataInA[6] = 160;	au8DataInB[6] = 10;		au8DataInC[6] = 6;
	au8DataInA[7] = 170;	au8DataInB[7] = 0;		au8DataInC[7] = 70;

	vu8x8InputA		= vld1_u8(au8DataInA);
	vu8x8InputB		= vld1_u8(au8DataInB);
	vu8x8InputC		= vld1_u8(au8DataInC);

	// uint8x8_t vtbx1_u8(uint8x8_t a, uint8x8_t b, uint8x8_t c);				// VTBX.8 d0, {d0}, d0
	// output = b[c], c in 0 ~ 7
	// output = a[*], otherwise
	vu8x8Output		= vtbx1_u8(vu8x8InputA, vu8x8InputB, vu8x8InputC);
	vst1_u8(au8DataOut, vu8x8Output);

	printf("== Table LookUp u8 = u8, u8, u8 (vtbx1_u8) ==\n");

	printf("Ref. / Table :\n");
	for (u32Idx = 0; u32Idx < 8; ++u32Idx)
	{
		printf("[%1d] : %3d, %3d\n",
			u32Idx, au8DataInA[u32Idx], au8DataInB[u32Idx]);
	}
	printf("\n");

	printf("Output :\n");
	for (u32Idx = 0; u32Idx < 8; ++u32Idx)
	{
		printf("[%1d], index: %3d, value : %3d\n",
			u32Idx, au8DataInC[u32Idx], au8DataOut[u32Idx]);
	}
	printf("\n");
	printf("========================================\n");
}

// -----------------------------------------------------------------------------
void NeonSample_TableLookUp_S8_S8_S8_S8()
{
	int8_t		as8DataInA[8];
	int8_t		as8DataInB[8];
	int8_t		as8DataInC[8];
	int8_t		as8DataOut[8];

	int8x8_t	vs8x8InputA;
	int8x8_t	vs8x8InputB;
	int8x8_t	vs8x8InputC;
	int8x8_t	vs8x8Output;

	uint32_t	u32Idx;

	// initial
	as8DataInA[0] = -10;	as8DataInB[0] = 10;		as8DataInC[0] = -1;
	as8DataInA[1] = -20;	as8DataInB[1] = 20;		as8DataInC[1] = 1;
	as8DataInA[2] = -30;	as8DataInB[2] = 30;		as8DataInC[2] = 2;
	as8DataInA[3] = -40;	as8DataInB[3] = 40;		as8DataInC[3] = 3;
	as8DataInA[4] = -50;	as8DataInB[4] = 50;		as8DataInC[4] = 4;
	as8DataInA[5] = -60;	as8DataInB[5] = 60;		as8DataInC[5] = 5;
	as8DataInA[6] = -70;	as8DataInB[6] = 70;		as8DataInC[6] = 6;
	as8DataInA[7] = -80;	as8DataInB[7] = 80;		as8DataInC[7] = 20;

	vs8x8InputA		= vld1_s8(as8DataInA);
	vs8x8InputB		= vld1_s8(as8DataInB);
	vs8x8InputC		= vld1_s8(as8DataInC);

	// int8x8_t vtbx1_s8(int8x8_t a, int8x8_t b, int8x8_t c);					// VTBX.8 d0, {d0}, d0
	// output = b[c], c in 0 ~ 7
	// output = a[*], otherwise
	vs8x8Output		= vtbx1_s8(vs8x8InputA, vs8x8InputB, vs8x8InputC);
	vst1_s8(as8DataOut, vs8x8Output);

	printf("== Table LookUp s8 = s8, s8, s8 (vtbx1_s8) ==\n");

	printf("Ref. / Table :\n");
	for (u32Idx = 0; u32Idx < 8; ++u32Idx)
	{
		printf("[%1d] : %4d, %4d\n",
			u32Idx, as8DataInA[u32Idx], as8DataInB[u32Idx]);
	}
	printf("\n");

	printf("Output :\n");
	for (u32Idx = 0; u32Idx < 8; ++u32Idx)
	{
		printf("[%1d], index: %3d, value : %4d\n",
			u32Idx, as8DataInC[u32Idx], as8DataOut[u32Idx]);
	}
	printf("\n");
	printf("========================================\n");
}

// -----------------------------------------------------------------------------
void NeonSample_TableLookUp_P8_P8_P8_U8()
{
	poly8_t		ap8DataInA[8];
	poly8_t		ap8DataInB[8];
	uint8_t		au8DataInC[8];
	poly8_t		ap8DataOut[8];

	poly8x8_t	vp8x8InputA;
	poly8x8_t	vp8x8InputB;
	uint8x8_t	vu8x8InputC;
	poly8x8_t	vp8x8Output;

	uint32_t	u32Idx;

	// initial
	ap8DataInA[0] = 0b00000001;	ap8DataInB[0] = 0b10000001;		au8DataInC[0] = 9;
	ap8DataInA[1] = 0b00000010;	ap8DataInB[1] = 0b01000010;		au8DataInC[1] = 1;
	ap8DataInA[2] = 0b00000100;	ap8DataInB[2] = 0b00100100;		au8DataInC[2] = 2;
	ap8DataInA[3] = 0b00001000;	ap8DataInB[3] = 0b00011000;		au8DataInC[3] = 3;
	ap8DataInA[4] = 0b00010000;	ap8DataInB[4] = 0b11000011;		au8DataInC[4] = 4;
	ap8DataInA[5] = 0b00100000;	ap8DataInB[5] = 0b01100110;		au8DataInC[5] = 5;
	ap8DataInA[6] = 0b01000000;	ap8DataInB[6] = 0b00111100;		au8DataInC[6] = 6;
	ap8DataInA[7] = 0b10000000;	ap8DataInB[7] = 0b11111111;		au8DataInC[7] = 70;

	vp8x8InputA		= vld1_p8(ap8DataInA);
	vp8x8InputB		= vld1_p8(ap8DataInB);
	vu8x8InputC		= vld1_u8(au8DataInC);

	// poly8x8_t vtbx1_p8(poly8x8_t a, poly8x8_t b, uint8x8_t c);				// VTBX.8 d0, {d0}, d0
	// output = b[c], c in 0 ~ 7
	// output = a[*], otherwise
	vp8x8Output		= vtbx1_p8(vp8x8InputA, vp8x8InputB, vu8x8InputC);
	vst1_p8(ap8DataOut, vp8x8Output);

	printf("== Table LookUp p8 = p8, p8, u8 (vtbx1_p8) ==\n");

	printf("Ref. / Table :\n");
	for (u32Idx = 0; u32Idx < 8; ++u32Idx)
	{
		printf("[%1d] : "UINT8_TO_BIT_PATTERN", "UINT8_TO_BIT_PATTERN"\n",
			u32Idx, UINT8_TO_BIT(ap8DataInA[u32Idx]), UINT8_TO_BIT(ap8DataInB[u32Idx]));
	}
	printf("\n");

	printf("Output :\n");
	for (u32Idx = 0; u32Idx < 8; ++u32Idx)
	{
		printf("[%1d], index: %3d, value : "UINT8_TO_BIT_PATTERN"\n",
			u32Idx, au8DataInC[u32Idx], UINT8_TO_BIT(ap8DataOut[u32Idx]));
	}
	printf("\n");
	printf("========================================\n");
}

// -----------------------------------------------------------------------------
void NeonSample_TableLookUp_U8_U8_U82_U8()
{
	uint8_t		au8DataInA[8];
	uint8_t		au8DataInB[16];
	uint8_t		au8DataInC[8];
	uint8_t		au8DataOut[8];

	uint8x8_t	vu8x8InputA;
	uint8x8x2_t	vu8x8x2InputB;
	uint8x8_t	vu8x8InputC;
	uint8x8_t	vu8x8Output;

	uint32_t	u32Idx, u32Idx2;

	// initial
	au8DataInA[0] = 1;
	au8DataInA[1] = 2;
	au8DataInA[2] = 3;
	au8DataInA[3] = 4;
	au8DataInA[4] = 5;
	au8DataInA[5] = 6;
	au8DataInA[6] = 7;
	au8DataInA[7] = 8;

	au8DataInB[0] = 100;	au8DataInB[1] = 10;
	au8DataInB[2] = 110;	au8DataInB[3] = 20;
	au8DataInB[4] = 120;	au8DataInB[5] = 30;
	au8DataInB[6] = 130;	au8DataInB[7] = 40;
	au8DataInB[8] = 140;	au8DataInB[9] = 50;
	au8DataInB[10] = 150;	au8DataInB[11] = 60;
	au8DataInB[12] = 160;	au8DataInB[13] = 70;
	au8DataInB[14] = 170;	au8DataInB[15] = 80;

	au8DataInC[0] = 0;
	au8DataInC[1] = 3;
	au8DataInC[2] = 6;
	au8DataInC[3] = 9;
	au8DataInC[4] = 12;
	au8DataInC[5] = 15;
	au8DataInC[6] = 16;
	au8DataInC[7] = 100;

	vu8x8InputA		= vld1_u8(au8DataInA);
	vu8x8x2InputB	= vld2_u8(au8DataInB);
	vu8x8InputC		= vld1_u8(au8DataInC);

	// uint8x8_t vtbx2_u8(uint8x8_t a, uint8x8x2_t b, uint8x8_t c);				// VTBX.8 d0, {d0, d1}, d0
	// output = b[c], c in 0 ~ 15
	// output = a[*], otherwise
	vu8x8Output		= vtbx2_u8(vu8x8InputA, vu8x8x2InputB, vu8x8InputC);
	vst1_u8(au8DataOut, vu8x8Output);

	printf("== Table LookUp u8 = u8, u82, u8 (vtbx2_u8) ==\n");
	printf("Ref. :\n");
	for (u32Idx = 0; u32Idx < 8; ++u32Idx)
	{
		printf("[%1d] : %3d\n",
			u32Idx, au8DataInA[u32Idx]);
	}
	printf("\n");

	printf("Table :\n");
	for (u32Idx = 0, u32Idx2 = 0; u32Idx < 8; ++u32Idx, u32Idx2 += 2)
	{
		printf("[%2d] : %3d\n",
			u32Idx, au8DataInB[u32Idx2]);
	}
	for (u32Idx = 0, u32Idx2 = 1; u32Idx < 8; ++u32Idx, u32Idx2 += 2)
	{
		printf("[%2d] : %3d\n",
			u32Idx + 8, au8DataInB[u32Idx2]);
	}
	printf("\n");

	printf("Output :\n");
	for (u32Idx = 0; u32Idx < 8; ++u32Idx)
	{
		printf("[%1d], index: %3d, value : %3d\n",
			u32Idx, au8DataInC[u32Idx], au8DataOut[u32Idx]);
	}
	printf("\n");
	printf("========================================\n");
}

// -----------------------------------------------------------------------------
void NeonSample_TableLookUp_S8_S8_S82_S8()
{
	int8_t		as8DataInA[8];
	int8_t		as8DataInB[16];
	int8_t		as8DataInC[8];
	int8_t		as8DataOut[8];

	int8x8_t	vs8x8InputA;
	int8x8x2_t	vs8x8x2InputB;
	int8x8_t	vs8x8InputC;
	int8x8_t	vs8x8Output;

	uint32_t	u32Idx, u32Idx2;

	// initial
	as8DataInA[0] = 1;
	as8DataInA[1] = 2;
	as8DataInA[2] = 3;
	as8DataInA[3] = 4;
	as8DataInA[4] = 5;
	as8DataInA[5] = 6;
	as8DataInA[6] = 7;
	as8DataInA[7] = 8;

	as8DataInB[0] = 100;	as8DataInB[1] = 10;
	as8DataInB[2] = 110;	as8DataInB[3] = 20;
	as8DataInB[4] = 120;	as8DataInB[5] = 30;
	as8DataInB[6] = 130;	as8DataInB[7] = 40;
	as8DataInB[8] = 140;	as8DataInB[9] = 50;
	as8DataInB[10] = 150;	as8DataInB[11] = 60;
	as8DataInB[12] = 160;	as8DataInB[13] = 70;
	as8DataInB[14] = 170;	as8DataInB[15] = 80;

	as8DataInC[0] = 0;
	as8DataInC[1] = 3;
	as8DataInC[2] = 6;
	as8DataInC[3] = 9;
	as8DataInC[4] = 12;
	as8DataInC[5] = 15;
	as8DataInC[6] = 16;
	as8DataInC[7] = 100;

	vs8x8InputA		= vld1_s8(as8DataInA);
	vs8x8x2InputB	= vld2_s8(as8DataInB);
	vs8x8InputC		= vld1_s8(as8DataInC);

	// int8x8_t vtbx2_s8(int8x8_t a, int8x8x2_t b, int8x8_t c);					// VTBX.8 d0, {d0, d1}, d0
	// output = b[c], c in 0 ~ 15
	// output = a[*], otherwise
	vs8x8Output		= vtbx2_s8(vs8x8InputA, vs8x8x2InputB, vs8x8InputC);
	vst1_s8(as8DataOut, vs8x8Output);

	printf("== Table LookUp s8 = s8, s82, s8 (vtbx2_s8) ==\n");
	printf("Ref. :\n");
	for (u32Idx = 0; u32Idx < 8; ++u32Idx)
	{
		printf("[%1d] : %4d\n",
			u32Idx, as8DataInA[u32Idx]);
	}
	printf("\n");

	printf("Table :\n");
	for (u32Idx = 0, u32Idx2 = 0; u32Idx < 8; ++u32Idx, u32Idx2 += 2)
	{
		printf("[%2d] : %4d\n",
			u32Idx, as8DataInB[u32Idx2]);
	}
	for (u32Idx = 0, u32Idx2 = 1; u32Idx < 8; ++u32Idx, u32Idx2 += 2)
	{
		printf("[%2d] : %4d\n",
			u32Idx + 8, as8DataInB[u32Idx2]);
	}
	printf("\n");

	printf("Output :\n");
	for (u32Idx = 0; u32Idx < 8; ++u32Idx)
	{
		printf("[%1d], index: %3d, value : %4d\n",
			u32Idx, as8DataInC[u32Idx], as8DataOut[u32Idx]);
	}
	printf("\n");
	printf("========================================\n");
}

// -----------------------------------------------------------------------------
void NeonSample_TableLookUp_P8_P8_P82_U8()
{
	poly8_t		ap8DataInA[8];
	poly8_t		ap8DataInB[16];
	uint8_t		au8DataInC[8];
	poly8_t		ap8DataOut[8];

	poly8x8_t	vp8x8InputA;
	poly8x8x2_t	vp8x8x2InputB;
	uint8x8_t	vu8x8InputC;
	poly8x8_t	vp8x8Output;

	uint32_t	u32Idx, u32Idx2;

	// initial
	ap8DataInA[0] = 0b00000001;
	ap8DataInA[1] = 0b00000011;
	ap8DataInA[2] = 0b00000111;
	ap8DataInA[3] = 0b00001111;
	ap8DataInA[4] = 0b00011111;
	ap8DataInA[5] = 0b00111111;
	ap8DataInA[6] = 0b01111111;
	ap8DataInA[7] = 0b11111111;

	ap8DataInB[0]	= 0b11111111;	ap8DataInB[1]	= 0b11111111;
	ap8DataInB[2]	= 0b10000000;	ap8DataInB[3]	= 0b11111110;
	ap8DataInB[4]	= 0b11000000;	ap8DataInB[5]	= 0b11111100;
	ap8DataInB[6]	= 0b11100000;	ap8DataInB[7]	= 0b11111000;
	ap8DataInB[8]	= 0b11110000;	ap8DataInB[9]	= 0b11110000;
	ap8DataInB[10]	= 0b11111000;	ap8DataInB[11]	= 0b11100000;
	ap8DataInB[12]	= 0b11111100;	ap8DataInB[13]	= 0b11000000;
	ap8DataInB[14]	= 0b11111110;	ap8DataInB[15] 	= 0b11111111;

	au8DataInC[0] = 0;
	au8DataInC[1] = 3;
	au8DataInC[2] = 6;
	au8DataInC[3] = 9;
	au8DataInC[4] = 12;
	au8DataInC[5] = 15;
	au8DataInC[6] = 16;
	au8DataInC[7] = 100;

	vp8x8InputA		= vld1_p8(ap8DataInA);
	vp8x8x2InputB	= vld2_p8(ap8DataInB);
	vu8x8InputC		= vld1_u8(au8DataInC);

	// poly8x8_t vtbx2_p8(poly8x8_t a, poly8x8x2_t b, uint8x8_t c);				// VTBX.8 d0, {d0, d1}, d0
	// output = b[c], c in 0 ~ 15
	// output = a[*], otherwise
	vp8x8Output		= vtbx2_p8(vp8x8InputA, vp8x8x2InputB, vu8x8InputC);
	vst1_p8(ap8DataOut, vp8x8Output);

	printf("== Table LookUp p8 = p8, p82, u8 (vtbx2_p8) ==\n");
	printf("Ref. :\n");
	for (u32Idx = 0; u32Idx < 8; ++u32Idx)
	{
		printf("[%1d] : "UINT8_TO_BIT_PATTERN"\n",
			u32Idx, UINT8_TO_BIT(ap8DataInA[u32Idx]));
	}
	printf("\n");

	printf("Table :\n");
	for (u32Idx = 0, u32Idx2 = 0; u32Idx < 8; ++u32Idx, u32Idx2 += 2)
	{
		printf("[%2d] : "UINT8_TO_BIT_PATTERN"\n",
			u32Idx, UINT8_TO_BIT(ap8DataInB[u32Idx2]));
	}
	for (u32Idx = 0, u32Idx2 = 1; u32Idx < 8; ++u32Idx, u32Idx2 += 2)
	{
		printf("[%2d] : "UINT8_TO_BIT_PATTERN"\n",
			u32Idx + 8, UINT8_TO_BIT(ap8DataInB[u32Idx2]));
	}
	printf("\n");

	printf("Output :\n");
	for (u32Idx = 0; u32Idx < 8; ++u32Idx)
	{
		printf("[%1d], index: %3d, value : "UINT8_TO_BIT_PATTERN"\n",
			u32Idx, au8DataInC[u32Idx], UINT8_TO_BIT(ap8DataOut[u32Idx]));
	}
	printf("\n");
	printf("========================================\n");
}

// -----------------------------------------------------------------------------
