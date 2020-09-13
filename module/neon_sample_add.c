#include "neon_sample.h"

// https://developer.arm.com/documentation/dui0472/m/using-neon-support/neon-intrinsics-for-addition

// -----------------------------------------------------------------------------
void NeonSample_Add_U8_U8_U8()
{
	uint8_t		au8DataInA[8];
	uint8_t		au8DataInB[8];
	uint8_t		au8DataOut[8];
	uint8_t		au8DataOutHalf[8];
	uint8_t		au8DataOutRoundHalf[8];
	uint8_t		au8DataOutSaturate[8];

	uint8x8_t	vu8x8InputA;
	uint8x8_t	vu8x8InputB;
	uint8x8_t	vu8x8Output;

	uint32_t	u32Idx;

	// initial
	au8DataInA[0] = 1;		au8DataInB[0] = 1;
	au8DataInA[1] = 10;		au8DataInB[1] = 10;
	au8DataInA[2] = 100;	au8DataInB[2] = 101;
	au8DataInA[3] = 151;	au8DataInB[3] = 150;
	au8DataInA[4] = 100;	au8DataInB[4] = 150;
	au8DataInA[5] = 255;	au8DataInB[5] = 255;
	au8DataInA[6] = 100;	au8DataInB[6] = 200;
	au8DataInA[7] = 200;	au8DataInB[7] = 200;

	vu8x8InputA		= vld1_u8(au8DataInA);
	vu8x8InputB		= vld1_u8(au8DataInB);

	// uint8x8_t vadd_u8(uint8x8_t a, uint8x8_t b);								// VADD.I8 d0,d0,d0
	// (a + b)
	vu8x8Output		= vadd_u8(vu8x8InputA, vu8x8InputB);
	vst1_u8(au8DataOut, vu8x8Output);

	// uint8x8_t vhadd_u8(uint8x8_t a, uint8x8_t b);							// VHADD.U8 d0,d0,d0
	// (a + b) >> 1
	vu8x8Output		= vhadd_u8(vu8x8InputA, vu8x8InputB);
	vst1_u8(au8DataOutHalf, vu8x8Output);

	// uint8x8_t vrhadd_u8(uint8x8_t a, uint8x8_t b);							// VRHADD.U8 d0,d0,d0
	// (a + b + 1) >> 1
	vu8x8Output		= vrhadd_u8(vu8x8InputA, vu8x8InputB);
	vst1_u8(au8DataOutRoundHalf, vu8x8Output);

	// uint8x8_t vqadd_u8(uint8x8_t a, uint8x8_t b);							// VQADD.U8 d0,d0,d0
	// (a + b) > MAX ? MAX : (a + b)
	vu8x8Output		= vqadd_u8(vu8x8InputA, vu8x8InputB);
	vst1_u8(au8DataOutSaturate, vu8x8Output);

	printf("== Add u8 = u8 + u8 (vadd_u8 / vhadd_u8 / vrhadd_u8 / vqadd_u8) ==\n");
	printf("=> vadd_u8   : u8 = u8 + u8                                     ==\n");
	printf("=> vhadd_u8  : u8 = (u8 + u8) >> 1                              ==\n");
	printf("=> vrhadd_u8 : u8 = (u8 + u8 + 1) >> 1                          ==\n");
	printf("=> vqadd_u8  : u8 = SATURATE(u8 + u8)                           ==\n");
	for (u32Idx = 0; u32Idx < 8; ++u32Idx)
	{
		printf("%3d + %3d = %3d, %3d, %3d, %3d\n",
			au8DataInA[u32Idx], au8DataInB[u32Idx],
			au8DataOut[u32Idx],
			au8DataOutHalf[u32Idx],
			au8DataOutRoundHalf[u32Idx],
			au8DataOutSaturate[u32Idx]);
	}
	printf("========================================\n");
}

// -----------------------------------------------------------------------------
void NeonSample_Add_U16_U8_U8()
{
	uint8_t		au8DataInA[8];
	uint8_t		au8DataInB[8];
	uint16_t	au16DataOutLong[8];

	uint8x8_t	vu8x8InputA;
	uint8x8_t	vu8x8InputB;
	uint16x8_t	vu16x8Output;

	uint32_t	u32Idx;

	// initial
	au8DataInA[0] = 1;		au8DataInB[0] = 1;
	au8DataInA[1] = 10;		au8DataInB[1] = 10;
	au8DataInA[2] = 100;	au8DataInB[2] = 100;
	au8DataInA[3] = 150;	au8DataInB[3] = 150;
	au8DataInA[4] = 100;	au8DataInB[4] = 150;
	au8DataInA[5] = 255;	au8DataInB[5] = 255;
	au8DataInA[6] = 100;	au8DataInB[6] = 200;
	au8DataInA[7] = 200;	au8DataInB[7] = 200;

	vu8x8InputA		= vld1_u8(au8DataInA);
	vu8x8InputB		= vld1_u8(au8DataInB);

	// uint16x8_t vaddl_u8(uint8x8_t a, uint8x8_t b);							// VADDL.U8 q0,d0,d0
	// (a + b)
	vu16x8Output		= vaddl_u8(vu8x8InputA, vu8x8InputB);
	vst1q_u16(au16DataOutLong, vu16x8Output);

	printf("== Add u16 = u8 + u8 (vaddl_u8) ==\n");
	for (u32Idx = 0; u32Idx < 8; ++u32Idx)
	{
		printf("%3d + %3d = %5d\n",
			au8DataInA[u32Idx], au8DataInB[u32Idx],
			au16DataOutLong[u32Idx]);
	}
	printf("========================================\n");
}

// -----------------------------------------------------------------------------
void NeonSample_Add_U16_U16_U16()
{
	uint16_t	au16DataInA[4];
	uint16_t	au16DataInB[4];
	uint16_t	au16DataOut[4];
	uint16_t	au16DataOutHalf[4];
	uint16_t	au16DataOutRoundHalf[4];
	uint16_t	au16DataOutSaturate[4];

	uint16x4_t	vu16x4InputA;
	uint16x4_t	vu16x4InputB;
	uint16x4_t	vu16x4Output;

	uint32_t	u32Idx;

	// initial
	au16DataInA[0] = 100;		au16DataInB[0] = 100;
	au16DataInA[1] = 300;		au16DataInB[1] = 500;
	au16DataInA[2] = 20000;		au16DataInB[2] = 40000;
	au16DataInA[3] = 40000;		au16DataInB[3] = 50000;

	vu16x4InputA	= vld1_u16(au16DataInA);
	vu16x4InputB	= vld1_u16(au16DataInB);

	// uint16x4_t vadd_u16(uint16x4_t a, uint16x4_t b);							// VADD.I16 d0,d0,d0
	// (a + b)
	vu16x4Output	= vadd_u16(vu16x4InputA, vu16x4InputB);
	vst1_u16(au16DataOut, vu16x4Output);

	// uint16x4_t vhadd_u16(uint16x4_t a, uint16x4_t b);						// VHADD.U16 d0,d0,d0
	// (a + b) >> 1
	vu16x4Output	= vhadd_u16(vu16x4InputA, vu16x4InputB);
	vst1_u16(au16DataOutHalf, vu16x4Output);

	// uint16x4_t vrhadd_u16(uint16x4_t a, uint16x4_t b);						// VRHADD.U16 d0,d0,d0
	// (a + b + 1) >> 1
	vu16x4Output	= vrhadd_u16(vu16x4InputA, vu16x4InputB);
	vst1_u16(au16DataOutRoundHalf, vu16x4Output);

	// uint16x4_t vqadd_u16(uint16x4_t a, uint16x4_t b);						// VQADD.U16 d0,d0,d0
	// (a + b) > MAX ? MAX : (a + b)
	vu16x4Output	= vqadd_u16(vu16x4InputA, vu16x4InputB);
	vst1_u16(au16DataOutSaturate, vu16x4Output);

	printf("== Add u16 = u16 + u16 (vadd_u16 / vhadd_u16 / vrhadd_u16 / vqadd_u16) ==\n");
	printf("=> vadd_u16   : u16 = u16 + u16                                        ==\n");
	printf("=> vhadd_u16  : u16 = (u16 + u16) >> 1                                 ==\n");
	printf("=> vrhadd_u16 : u16 = (u16 + u16 + 1) >> 1                             ==\n");
	printf("=> vqadd_u16  : u16 = SATURATE(u16 + u16)                              ==\n");
	for (u32Idx = 0; u32Idx < 4; ++u32Idx)
	{
		printf("%5d + %5d = %5d, %5d, %5d, %5d\n",
			au16DataInA[u32Idx], au16DataInB[u32Idx],
			au16DataOut[u32Idx],
			au16DataOutHalf[u32Idx],
			au16DataOutRoundHalf[u32Idx],
			au16DataOutSaturate[u32Idx]);
	}
	printf("========================================\n");
}

// -----------------------------------------------------------------------------
void NeonSample_Add_U32_U16_U16()
{
	uint16_t	au16DataInA[4];
	uint16_t	au16DataInB[4];
	uint32_t	au32DataOutLong[4];

	uint16x4_t	vu16x4InputA;
	uint16x4_t	vu16x4InputB;
	uint32x4_t	vu32x4Output;

	uint32_t	u32Idx;

	// initial
	au16DataInA[0] = 100;		au16DataInB[0] = 100;
	au16DataInA[1] = 300;		au16DataInB[1] = 500;
	au16DataInA[2] = 20000;		au16DataInB[2] = 40000;
	au16DataInA[3] = 40000;		au16DataInB[3] = 50000;

	vu16x4InputA	= vld1_u16(au16DataInA);
	vu16x4InputB	= vld1_u16(au16DataInB);

	// uint32x4_t vaddl_u16(uint16x4_t a, uint16x4_t b);						// VADDL.U16 q0,d0,d0
	// (a + b)
	vu32x4Output	= vaddl_u16(vu16x4InputA, vu16x4InputB);
	vst1q_u32(au32DataOutLong, vu32x4Output);

	printf("== Add u32 = u16 + u16 (vaddl_u16) ==\n");
	for (u32Idx = 0; u32Idx < 4; ++u32Idx)
	{
		printf("%5d + %5d = %10d\n",
			au16DataInA[u32Idx], au16DataInB[u32Idx],
			au32DataOutLong[u32Idx]);
	}
	printf("========================================\n");
}

// -----------------------------------------------------------------------------
void NeonSample_Add_S8_S8_S8()
{
	int8_t		as8DataInA[8];
	int8_t		as8DataInB[8];
	int8_t		as8DataOut[8];
	int8_t		as8DataOutHalf[8];
	int8_t		as8DataOutRoundHalf[8];
	int8_t		as8DataOutSaturate[8];

	int8x8_t	vs8x8InputA;
	int8x8_t	vs8x8InputB;
	int8x8_t	vs8x8Output;

	uint32_t	u32Idx;

	// initial
	as8DataInA[0] = 100;	as8DataInB[0] = 27;
	as8DataInA[1] = 127;	as8DataInB[1] = -126;
	as8DataInA[2] = 10;		as8DataInB[2] = -126;
	as8DataInA[3] = -100;	as8DataInB[3] = -100;
	as8DataInA[4] = -126;	as8DataInB[4] = 127;
	as8DataInA[5] = -100;	as8DataInB[5] = 15;
	as8DataInA[6] = -10;	as8DataInB[6] = -30;
	as8DataInA[7] = 100;	as8DataInB[7] = 100;

	vs8x8InputA		= vld1_s8(as8DataInA);
	vs8x8InputB		= vld1_s8(as8DataInB);

	// int8x8_t vadd_s8(int8x8_t a, int8x8_t b);								// VADD.I8 d0,d0,d0
	// (a + b)
	vs8x8Output		= vadd_s8(vs8x8InputA, vs8x8InputB);
	vst1_s8(as8DataOut, vs8x8Output);

	// int8x8_t vhadd_s8(int8x8_t a, int8x8_t b);								// VHADD.S8 d0,d0,d0
	// (a + b) >> 1
	vs8x8Output		= vhadd_s8(vs8x8InputA, vs8x8InputB);
	vst1_s8(as8DataOutHalf, vs8x8Output);

	// int8x8_t vrhadd_s8(int8x8_t a, int8x8_t b);								// VRHADD.S8 d0,d0,d0
	// (a + b + 1) >> 1
	vs8x8Output		= vrhadd_s8(vs8x8InputA, vs8x8InputB);
	vst1_s8(as8DataOutRoundHalf, vs8x8Output);

	// int8x8_t vqadd_s8(int8x8_t a, int8x8_t b);								// VQADD.S8 d0,d0,d0
	// (a + b) > MAX ? MAX : (a + b)
	vs8x8Output		= vqadd_s8(vs8x8InputA, vs8x8InputB);
	vst1_s8(as8DataOutSaturate, vs8x8Output);

	printf("== Add s8 = s8 + s8 (vadd_s8 / vhadd_s8 / vrhadd_s8 / vqadd_s8) ==\n");
	printf("=> vadd_s8   : s8 = s8 + s8                                     ==\n");
	printf("=> vhadd_s8  : s8 = (s8 + s8) >> 1                              ==\n");
	printf("=> vrhadd_s8 : s8 = (s8 + s8 + 1) >> 1                          ==\n");
	printf("=> vqadd_s8  : s8 = SATURATE(s8 + s8)                           ==\n");
	for (u32Idx = 0; u32Idx < 8; ++u32Idx)
	{
		printf("%4d + %4d = %4d, %4d, %4d, %4d\n",
			as8DataInA[u32Idx], as8DataInB[u32Idx],
			as8DataOut[u32Idx],
			as8DataOutHalf[u32Idx],
			as8DataOutRoundHalf[u32Idx],
			as8DataOutSaturate[u32Idx]);
	}
	printf("========================================\n");
}

// -----------------------------------------------------------------------------
void NeonSample_Add_S16_S8_S8()
{
	int8_t		as8DataInA[8];
	int8_t		as8DataInB[8];
	int16_t		as16DataOutLong[8];

	int8x8_t	vs8x8InputA;
	int8x8_t	vs8x8InputB;
	int16x8_t	vs16x8Output;

	uint32_t	u32Idx;

	// initial
	as8DataInA[0] = 100;	as8DataInB[0] = 27;
	as8DataInA[1] = 127;	as8DataInB[1] = -126;
	as8DataInA[2] = 10;		as8DataInB[2] = -126;
	as8DataInA[3] = -100;	as8DataInB[3] = -100;
	as8DataInA[4] = -126;	as8DataInB[4] = 127;
	as8DataInA[5] = -100;	as8DataInB[5] = 15;
	as8DataInA[6] = -10;	as8DataInB[6] = -30;
	as8DataInA[7] = 100;	as8DataInB[7] = 100;

	vs8x8InputA		= vld1_s8(as8DataInA);
	vs8x8InputB		= vld1_s8(as8DataInB);

	// int16x8_t vaddl_s8(int8x8_t a, int8x8_t b);								// VADDL.S8 q0,d0,d0
	// (a + b)
	vs16x8Output	= vaddl_s8(vs8x8InputA, vs8x8InputB);
	vst1q_s16(as16DataOutLong, vs16x8Output);

	printf("== Add s16 = s8 + s8 (vaddl_s8) ==\n");
	for (u32Idx = 0; u32Idx < 8; ++u32Idx)
	{
		printf("%4d + %4d = %6d\n",
			as8DataInA[u32Idx], as8DataInB[u32Idx],
			as16DataOutLong[u32Idx]);
	}
	printf("========================================\n");
}

// -----------------------------------------------------------------------------
void NeonSample_Add_S16_S16_S16()
{
	int16_t		as16DataInA[4];
	int16_t		as16DataInB[4];
	int16_t		as16DataOut[4];
	int16_t		as16DataOutHalf[4];
	int16_t		as16DataOutRoundHalf[4];
	int16_t		as16DataOutSaturate[4];

	int16x4_t	vs16x4InputA;
	int16x4_t	vs16x4InputB;
	int16x4_t	vs16x4Output;

	uint32_t	u32Idx;

	// initial
	as16DataInA[0] = 30000;		as16DataInB[0] = 30000;
	as16DataInA[1] = -30000;	as16DataInB[1] = -30000;
	as16DataInA[2] = 30000;		as16DataInB[2] = -20000;
	as16DataInA[3] = -30000;	as16DataInB[3] = 20000;

	vs16x4InputA	= vld1_s16(as16DataInA);
	vs16x4InputB	= vld1_s16(as16DataInB);

	// int16x4_t vadd_s16(int16x4_t a, int16x4_t b);							// VADD.I16 d0,d0,d0
	// (a + b)
	vs16x4Output	= vadd_s16(vs16x4InputA, vs16x4InputB);
	vst1_s16(as16DataOut, vs16x4Output);

	// int16x4_t vhadd_s16(int16x4_t a, int16x4_t b);							// VHADD.S16 d0,d0,d0
	// (a + b) >> 1
	vs16x4Output	= vhadd_s16(vs16x4InputA, vs16x4InputB);
	vst1_s16(as16DataOutHalf, vs16x4Output);

	// int16x4_t vrhadd_s16(int16x4_t a, int16x4_t b);							// VRHADD.S16 d0,d0,d0
	// (a + b + 1) >> 1
	vs16x4Output	= vrhadd_s16(vs16x4InputA, vs16x4InputB);
	vst1_s16(as16DataOutRoundHalf, vs16x4Output);

	// int16x4_t vqadd_s16(int16x4_t a, int16x4_t b);							// VQADD.S16 d0,d0,d0
	// (a + b) > MAX ? MAX : (a + b)
	vs16x4Output	= vqadd_s16(vs16x4InputA, vs16x4InputB);
	vst1_s16(as16DataOutSaturate, vs16x4Output);

	printf("== Add s16 = s16 + s16 (vadd_s16 / vhadd_s16 / vrhadd_s16 / vqadd_s16) ==\n");
	printf("=> vadd_s16   : s16 = s16 + s16                                        ==\n");
	printf("=> vhadd_s16  : s16 = (s16 + s16) >> 1                                 ==\n");
	printf("=> vrhadd_s16 : s16 = (s16 + s16 + 1) >> 1                             ==\n");
	printf("=> vqadd_s16  : s16 = SATURATE(s16 + s16)                              ==\n");
	for (u32Idx = 0; u32Idx < 4; ++u32Idx)
	{
		printf("%6d + %6d = %6d, %6d, %6d, %6d\n",
			as16DataInA[u32Idx], as16DataInB[u32Idx],
			as16DataOut[u32Idx],
			as16DataOutHalf[u32Idx],
			as16DataOutRoundHalf[u32Idx],
			as16DataOutSaturate[u32Idx]);
	}
	printf("========================================\n");
}

// -----------------------------------------------------------------------------
void NeonSample_Add_S32_S16_S16()
{
	int16_t		as16DataInA[4];
	int16_t		as16DataInB[4];
	int32_t		as32DataOutLong[4];

	int16x4_t	vs16x4InputA;
	int16x4_t	vs16x4InputB;
	int32x4_t	vs32x4Output;

	uint32_t	u32Idx;

	// initial
	as16DataInA[0] = 30000;		as16DataInB[0] = 30000;
	as16DataInA[1] = -30000;	as16DataInB[1] = -30000;
	as16DataInA[2] = 30000;		as16DataInB[2] = -20000;
	as16DataInA[3] = -30000;	as16DataInB[3] = 20000;

	vs16x4InputA	= vld1_s16(as16DataInA);
	vs16x4InputB	= vld1_s16(as16DataInB);

	// int32x4_t vaddl_s16(int16x4_t a, int16x4_t b);							// VADDL.S16 q0,d0,d0
	// (a + b)
	vs32x4Output	= vaddl_s16(vs16x4InputA, vs16x4InputB);
	vst1q_s32(as32DataOutLong, vs32x4Output);

	printf("== Add s32 = s16 + s16 (vaddl_s16) ==\n");
	for (u32Idx = 0; u32Idx < 4; ++u32Idx)
	{
		printf("%6d + %6d = %11d\n",
			as16DataInA[u32Idx], as16DataInB[u32Idx],
			as32DataOutLong[u32Idx]);
	}
	printf("========================================\n");
}

// -----------------------------------------------------------------------------
void NeonSample_Add_F32_F32_F32()
{
	float			af32DataInA[2];
	float			af32DataInB[2];
	float			af32DataOut[2];

	float32x2_t		vf32x2InputA;
	float32x2_t		vf32x2InputB;
	float32x2_t		vf32x2Output;

	uint32_t		u32Idx;

	// initial
	af32DataInA[0] = 99.99;		af32DataInB[0] = -10.5;
	af32DataInA[1] = 120.01;	af32DataInB[1] = 1.5;

	vf32x2InputA	= vld1_f32(af32DataInA);
	vf32x2InputB	= vld1_f32(af32DataInB);

	// float32x2_t vadd_f32(float32x2_t a, float32x2_t b);						// VADD.F32 d0,d0,d0
	// (a + b)
	vf32x2Output	= vadd_f32(vf32x2InputA, vf32x2InputB);
	vst1_f32(af32DataOut, vf32x2Output);

	printf("== Add f32 = f32 + f32 (vadd_f32) ==\n");
	for (u32Idx = 0; u32Idx < 2; ++u32Idx)
	{
		printf("%9.4f + %9.4f = %9.4f\n",
			af32DataInA[u32Idx], af32DataInB[u32Idx],
			af32DataOut[u32Idx]);
	}
	printf("========================================\n");
}

// -----------------------------------------------------------------------------
void NeonSample_Add_U8_U16_U16()
{
	uint16_t	au16DataInA[8];
	uint16_t	au16DataInB[8];
	uint8_t		au8DataOutHighHalf[8];
	uint8_t		au8DataOutRoundHighHalf[8];

	uint16x8_t	vu16x8InputA;
	uint16x8_t	vu16x8InputB;
	uint8x8_t	vu8x8Output;

	uint32_t	u32Idx;

	// initial
	au16DataInA[0] = 100;		au16DataInB[0] = 100;
	au16DataInA[1] = 300;		au16DataInB[1] = 500;
	au16DataInA[2] = 20000;		au16DataInB[2] = 40000;
	au16DataInA[3] = 40000;		au16DataInB[3] = 50000;
	au16DataInA[4] = 200;		au16DataInB[4] = 0;
	au16DataInA[5] = 50000;		au16DataInB[5] = 9904;
	au16DataInA[6] = 10000;		au16DataInB[6] = 10000;
	au16DataInA[7] = 65535;		au16DataInB[7] = 65535;

	vu16x8InputA	= vld1q_u16(au16DataInA);
	vu16x8InputB	= vld1q_u16(au16DataInB);

	// uint8x8_t vaddhn_u16(uint16x8_t a, uint16x8_t b);						// VADDHN.I16 d0,q0,q0
	// (a + b) >> 8
	vu8x8Output	= vaddhn_u16(vu16x8InputA, vu16x8InputB);
	vst1_u8(au8DataOutHighHalf, vu8x8Output);

	// uint8x8_t vraddhn_u16(uint16x8_t a, uint16x8_t b);						// VRADDHN.I16 d0,q0,q0
	// ROUND((a + b) >> 8)
	vu8x8Output	= vraddhn_u16(vu16x8InputA, vu16x8InputB);
	vst1_u8(au8DataOutRoundHighHalf, vu8x8Output);

	printf("== Add u8 = u16 + u16 (vaddhn_u16 / vraddhn_u16) ==\n");
	printf("=> vaddhn_u16  : u8 = (u16 + u16) >> 8           ==\n");
	printf("=> vraddhn_u16 : u8 = ROUND((u16 + u16) >> 8)    ==\n");
	for (u32Idx = 0; u32Idx < 8; ++u32Idx)
	{
		printf("%5d + %5d = %3d, %3d\n",
			au16DataInA[u32Idx], au16DataInB[u32Idx],
			au8DataOutHighHalf[u32Idx],
			au8DataOutRoundHighHalf[u32Idx]);
	}
	printf("========================================\n");
}

// -----------------------------------------------------------------------------
void NeonSample_Add_S8_S16_S16()
{
	int16_t		as16DataInA[8];
	int16_t		as16DataInB[8];
	int8_t		as8DataOutHighHalf[8];
	int8_t		as8DataOutRoundHighHalf[8];

	int16x8_t	vs16x8InputA;
	int16x8_t	vs16x8InputB;
	int8x8_t	vs8x8Output;

	uint32_t	u32Idx;

	// initial
	as16DataInA[0] = 30000;		as16DataInB[0] = 30000;
	as16DataInA[1] = -30000;	as16DataInB[1] = -30000;
	as16DataInA[2] = 30000;		as16DataInB[2] = -20000;
	as16DataInA[3] = -30000;	as16DataInB[3] = 20000;
	as16DataInA[4] = 30000;		as16DataInB[4] = -20000;
	as16DataInA[5] = -30000;	as16DataInB[5] = 20000;
	as16DataInA[6] = 30000;		as16DataInB[6] = -20000;
	as16DataInA[7] = -30000;	as16DataInB[7] = 20000;

	vs16x8InputA	= vld1q_s16(as16DataInA);
	vs16x8InputB	= vld1q_s16(as16DataInB);

	// int8x8_t vaddhn_s16(int16x8_t a, int16x8_t b);							// VADDHN.I16 d0,q0,q0
	// (a + b) >> 8
	vs8x8Output	= vaddhn_s16(vs16x8InputA, vs16x8InputB);
	vst1_s8(as8DataOutHighHalf, vs8x8Output);

	// int8x8_t vraddhn_s16(int16x8_t a, int16x8_t b);							// VRADDHN.I16 d0,q0,q0
	// ROUND((a + b) >> 8)
	vs8x8Output	= vraddhn_s16(vs16x8InputA, vs16x8InputB);
	vst1_s8(as8DataOutRoundHighHalf, vs8x8Output);

	printf("== Add s8 = s16 + s16 (vaddhn_s16 / vraddhn_s16) ==\n");
	printf("=> vaddhn_s16  : s8 = (s16 + s16) >> 8           ==\n");
	printf("=> vraddhn_s16 : s8 = ROUND((s16 + s16) >> 8)    ==\n");
	for (u32Idx = 0; u32Idx < 8; ++u32Idx)
	{
		printf("%6d + %6d = %4d, %4d\n",
			as16DataInA[u32Idx], as16DataInB[u32Idx],
			as8DataOutHighHalf[u32Idx],
			as8DataOutRoundHighHalf[u32Idx]);
	}
	printf("========================================\n");
}

// -----------------------------------------------------------------------------
void NeonSample_Add_U16_U16_U8()
{
	uint16_t	au16DataInA[8];
	uint8_t		au8DataInB[8];
	uint16_t	au16DataOut[8];

	uint16x8_t	vu16x8InputA;
	uint8x8_t	vu8x8InputB;
	uint16x8_t	vu16x8Output;

	uint32_t	u32Idx;

	// initial
	au16DataInA[0] = 10000;		au8DataInB[0] = 100;
	au16DataInA[1] = 10000;		au8DataInB[1] = 255;
	au16DataInA[2] = 20000;		au8DataInB[2] = 255;
	au16DataInA[3] = 30000;		au8DataInB[3] = 255;
	au16DataInA[4] = 40000;		au8DataInB[4] = 255;
	au16DataInA[5] = 50000;		au8DataInB[5] = 255;
	au16DataInA[6] = 60000;		au8DataInB[6] = 255;
	au16DataInA[7] = 65530;		au8DataInB[7] = 255;

	vu16x8InputA	= vld1q_u16(au16DataInA);
	vu8x8InputB		= vld1_u8(au8DataInB);

	// uint16x8_t vaddw_u8(uint16x8_t a, uint8x8_t b);							// VADDW.U8 q0,q0,d0
	// (a + b)
	vu16x8Output	= vaddw_u8(vu16x8InputA, vu8x8InputB);
	vst1q_u16(au16DataOut, vu16x8Output);

	printf("== Add u16 = u16 + u8 (vaddw_u8) ==\n");
	for (u32Idx = 0; u32Idx < 8; ++u32Idx)
	{
		printf("%5d + %3d = %5d\n",
			au16DataInA[u32Idx], au8DataInB[u32Idx],
			au16DataOut[u32Idx]);
	}
	printf("========================================\n");
}

// -----------------------------------------------------------------------------
void NeonSample_Add_S16_S16_S8()
{
	int16_t		as16DataInA[8];
	int8_t		as8DataInB[8];
	int16_t		as16DataOut[8];

	int16x8_t	vs16x8InputA;
	int8x8_t	vs8x8InputB;
	int16x8_t	vs16x8Output;

	uint32_t	u32Idx;

	// initial
	as16DataInA[0] = 32767;		as8DataInB[0] = 128;
	as16DataInA[1] = 32767;		as8DataInB[1] = -128;
	as16DataInA[2] = 32767;		as8DataInB[2] = 1;
	as16DataInA[3] = 32767;		as8DataInB[3] = 0;
	as16DataInA[4] = -32767;	as8DataInB[4] = 128;
	as16DataInA[5] = -32767;	as8DataInB[5] = -128;
	as16DataInA[6] = -32767;	as8DataInB[6] = -1;
	as16DataInA[7] = -32767;	as8DataInB[7] = 0;

	vs16x8InputA	= vld1q_s16(as16DataInA);
	vs8x8InputB		= vld1_s8(as8DataInB);

	// int16x8_t vaddw_s8(int16x8_t a, int8x8_t b);								// VADDW.S8 q0,q0,d0
	// (a + b)
	vs16x8Output	= vaddw_s8(vs16x8InputA, vs8x8InputB);
	vst1q_s16(as16DataOut, vs16x8Output);

	printf("== Add s16 = s16 + s8 (vaddw_s8) ==\n");
	for (u32Idx = 0; u32Idx < 8; ++u32Idx)
	{
		printf("%6d + %4d = %6d\n",
			as16DataInA[u32Idx], as8DataInB[u32Idx],
			as16DataOut[u32Idx]);
	}
	printf("========================================\n");
}

// -----------------------------------------------------------------------------
