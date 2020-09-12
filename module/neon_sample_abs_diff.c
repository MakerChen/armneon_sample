#include "neon_sample.h"

// https://developer.arm.com/documentation/dui0472/m/using-neon-support/neon-intrinsics-for-absolute-difference

// -----------------------------------------------------------------------------
void NeonSample_AbsDiff_U8_U8_U8()
{
	uint8_t		au8DataInA[8];
	uint8_t		au8DataInB[8];
	uint8_t		au8DataOut[8];

	uint8x8_t	vu8x8InputA;
	uint8x8_t	vu8x8InputB;
	uint8x8_t	vu8x8Output;

	uint32_t	u32Idx;

	// initial
	au8DataInA[0] = 10;		au8DataInB[0] = 10;
	au8DataInA[1] = 10;		au8DataInB[1] = 20;
	au8DataInA[2] = 20;		au8DataInB[2] = 10;
	au8DataInA[3] = 150;	au8DataInB[3] = 10;
	au8DataInA[4] = 10;		au8DataInB[4] = 150;
	au8DataInA[5] = 255;	au8DataInB[5] = 255;
	au8DataInA[6] = 100;	au8DataInB[6] = 200;
	au8DataInA[7] = 200;	au8DataInB[7] = 100;

	vu8x8InputA		= vld1_u8(au8DataInA);
	vu8x8InputB		= vld1_u8(au8DataInB);

	// uint8x8_t vabd_u8(uint8x8_t a, uint8x8_t b);								// VABD.U8 d0,d0,d0
	// | a - b |
	vu8x8Output		= vabd_u8(vu8x8InputA, vu8x8InputB);
	vst1_u8(au8DataOut, vu8x8Output);

	printf("== Abs diff u8 = | u8 - u8 | (vabd_u8) ==\n");
	for (u32Idx = 0; u32Idx < 8; ++u32Idx)
	{
		printf("| %3d - %3d | = %3d\n",
			au8DataInA[u32Idx], au8DataInB[u32Idx],
			au8DataOut[u32Idx]);
	}
	printf("========================================\n");
}

// -----------------------------------------------------------------------------
void NeonSample_AbsDiff_S8_S8_S8()
{
	int8_t		as8DataInA[8];
	int8_t		as8DataInB[8];
	int8_t		as8DataOut[8];

	int8x8_t	vs8x8InputA;
	int8x8_t	vs8x8InputB;
	int8x8_t	vs8x8Output;

	uint32_t	u32Idx;

	// initial
	as8DataInA[0] = -10;	as8DataInB[0] = -10;
	as8DataInA[1] = -10;	as8DataInB[1] = -20;
	as8DataInA[2] = -20;	as8DataInB[2] = -10;
	as8DataInA[3] = -50;	as8DataInB[3] = 50;
	as8DataInA[4] = 50;		as8DataInB[4] = -50;
	as8DataInA[5] = 100;	as8DataInB[5] = 120;
	as8DataInA[6] = 120;	as8DataInB[6] = 100;
	as8DataInA[7] = 110;	as8DataInB[7] = 110;

	vs8x8InputA		= vld1_s8(as8DataInA);
	vs8x8InputB		= vld1_s8(as8DataInB);

	// int8x8_t vabd_s8(int8x8_t a, int8x8_t b);								// VABD.S8 d0,d0,d0
	// | a - b |
	vs8x8Output		= vabd_s8(vs8x8InputA, vs8x8InputB);
	vst1_s8(as8DataOut, vs8x8Output);

	printf("== Abs diff s8 = | s8 - s8 | (vabd_s8) ==\n");
	for (u32Idx = 0; u32Idx < 8; ++u32Idx)
	{
		printf("| %4d - %4d | = %4d\n",
			as8DataInA[u32Idx], as8DataInB[u32Idx],
			as8DataOut[u32Idx]);
	}
	printf("========================================\n");
}

// -----------------------------------------------------------------------------
void NeonSample_AbsDiff_U16_U8_U8()
{
	uint8_t		au8DataInA[8];
	uint8_t		au8DataInB[8];
	uint16_t	au16DataOut[8];

	uint8x8_t	vu8x8InputA;
	uint8x8_t	vu8x8InputB;
	uint16x8_t	vu16x8Output;

	uint32_t	u32Idx;

	// initial
	au8DataInA[0] = 10;		au8DataInB[0] = 10;
	au8DataInA[1] = 10;		au8DataInB[1] = 20;
	au8DataInA[2] = 20;		au8DataInB[2] = 10;
	au8DataInA[3] = 150;	au8DataInB[3] = 10;
	au8DataInA[4] = 10;		au8DataInB[4] = 150;
	au8DataInA[5] = 255;	au8DataInB[5] = 255;
	au8DataInA[6] = 100;	au8DataInB[6] = 200;
	au8DataInA[7] = 200;	au8DataInB[7] = 100;

	vu8x8InputA		= vld1_u8(au8DataInA);
	vu8x8InputB		= vld1_u8(au8DataInB);

	// uint16x8_t vabdl_u8(uint8x8_t a, uint8x8_t b);							// VABDL.U8 q0,d0,d0
	// | a - b |
	vu16x8Output	= vabdl_u8(vu8x8InputA, vu8x8InputB);
	vst1q_u16(au16DataOut, vu16x8Output);

	printf("== Abs diff u16 = | u8 - u8 | (vabdl_u8) ==\n");
	for (u32Idx = 0; u32Idx < 8; ++u32Idx)
	{
		printf("| %3d - %3d | = %5d\n",
			au8DataInA[u32Idx], au8DataInB[u32Idx],
			au16DataOut[u32Idx]);
	}
	printf("========================================\n");
}

// -----------------------------------------------------------------------------
void NeonSample_AbsDiff_S16_S8_S8()
{
	int8_t		as8DataInA[8];
	int8_t		as8DataInB[8];
	int16_t		as16DataOut[8];

	int8x8_t	vs8x8InputA;
	int8x8_t	vs8x8InputB;
	int16x8_t	vs16x8Output;

	uint32_t	u32Idx;

	// initial
	as8DataInA[0] = -10;	as8DataInB[0] = -10;
	as8DataInA[1] = -10;	as8DataInB[1] = -20;
	as8DataInA[2] = -20;	as8DataInB[2] = -10;
	as8DataInA[3] = -50;	as8DataInB[3] = 50;
	as8DataInA[4] = 127;	as8DataInB[4] = -127;
	as8DataInA[5] = -127;	as8DataInB[5] = 127;
	as8DataInA[6] = 120;	as8DataInB[6] = -127;
	as8DataInA[7] = -127;	as8DataInB[7] = 120;

	vs8x8InputA		= vld1_s8(as8DataInA);
	vs8x8InputB		= vld1_s8(as8DataInB);

	// int16x8_t vabdl_s8(int8x8_t a, int8x8_t b);								// VABDL.S8 q0,d0,d0
	// | a - b |
	vs16x8Output	= vabdl_s8(vs8x8InputA, vs8x8InputB);
	vst1q_s16(as16DataOut, vs16x8Output);

	printf("== Abs diff s16 = | s8 - s8 | (vabdl_s8) ==\n");
	for (u32Idx = 0; u32Idx < 8; ++u32Idx)
	{
		printf("| %4d - %4d | = %6d\n",
			as8DataInA[u32Idx], as8DataInB[u32Idx],
			as16DataOut[u32Idx]);
	}
	printf("========================================\n");
}

// -----------------------------------------------------------------------------
void NeonSample_AbsDiff_F32_F32_F32()
{
	float			af32DataInA[2];
	float			af32DataInB[2];
	float			af32DataOut[2];

	float32x2_t		vf32x2InputA;
	float32x2_t		vf32x2InputB;
	float32x2_t		vf32x2Output;

	uint32_t		u32Idx;

	// initial
	af32DataInA[0] = -99.99;	af32DataInB[0] = 10.01;
	af32DataInA[1] = 120.01;	af32DataInB[1] = 220.99;

	vf32x2InputA	= vld1_f32(af32DataInA);
	vf32x2InputB	= vld1_f32(af32DataInB);

	// float32x2_t vabd_f32(float32x2_t a, float32x2_t b);						// VABD.F32 d0,d0,d0
	// | a - b |
	vf32x2Output	= vabd_f32(vf32x2InputA, vf32x2InputB);
	vst1_f32(af32DataOut, vf32x2Output);

	printf("== Abs diff f32 = | f32 - f32 | (vabd_f32) ==\n");
	for (u32Idx = 0; u32Idx < 2; ++u32Idx)
	{
		printf("| %9.4f - %9.4f | = %9.4f\n",
			af32DataInA[u32Idx], af32DataInB[u32Idx],
			af32DataOut[u32Idx]);
	}
	printf("========================================\n");
}

// -----------------------------------------------------------------------------
void NeonSample_AbsDiff_U8_U8_U8_U8()
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
	au8DataInA[0] = 100;	au8DataInB[0] = 10;		au8DataInC[0] = 10;
	au8DataInA[1] = 100;	au8DataInB[1] = 10;		au8DataInC[1] = 20;
	au8DataInA[2] = 100;	au8DataInB[2] = 20;		au8DataInC[2] = 10;
	au8DataInA[3] = 100;	au8DataInB[3] = 150;	au8DataInC[3] = 10;
	au8DataInA[4] = 220;	au8DataInB[4] = 10;		au8DataInC[4] = 150;
	au8DataInA[5] = 100;	au8DataInB[5] = 255;	au8DataInC[5] = 255;
	au8DataInA[6] = 100;	au8DataInB[6] = 100;	au8DataInC[6] = 200;
	au8DataInA[7] = 200;	au8DataInB[7] = 200;	au8DataInC[7] = 100;

	vu8x8InputA		= vld1_u8(au8DataInA);
	vu8x8InputB		= vld1_u8(au8DataInB);
	vu8x8InputC		= vld1_u8(au8DataInC);

	// uint8x8_t vaba_u8(uint8x8_t a, uint8x8_t b, uint8x8_t c);				// VABA.U8 d0,d0,d0
	// a + | b - c |
	vu8x8Output		= vaba_u8(vu8x8InputA, vu8x8InputB, vu8x8InputC);
	vst1_u8(au8DataOut, vu8x8Output);

	printf("== Abs diff u8 = u8 + | u8 - u8 | (vaba_u8) ==\n");
	for (u32Idx = 0; u32Idx < 8; ++u32Idx)
	{
		printf("%3d + | %3d - %3d | = %3d\n",
			au8DataInA[u32Idx], au8DataInB[u32Idx], au8DataInC[u32Idx],
			au8DataOut[u32Idx]);
	}
	printf("========================================\n");
}

// -----------------------------------------------------------------------------
void NeonSample_AbsDiff_S8_S8_S8_S8()
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
	as8DataInA[0] = 100;	as8DataInB[0] = -10;	as8DataInC[0] = -10;
	as8DataInA[1] = 100;	as8DataInB[1] = -10;	as8DataInC[1] = -20;
	as8DataInA[2] = 100;	as8DataInB[2] = -20;	as8DataInC[2] = -10;
	as8DataInA[3] = 10;		as8DataInB[3] = -50;	as8DataInC[3] = 50;
	as8DataInA[4] = 10;		as8DataInB[4] = 50;		as8DataInC[4] = -50;
	as8DataInA[5] = 100;	as8DataInB[5] = -50;	as8DataInC[5] = 50;
	as8DataInA[6] = 100;	as8DataInB[6] = 50;		as8DataInC[6] = -50;
	as8DataInA[7] = 110;	as8DataInB[7] = 110;	as8DataInC[7] = 110;

	vs8x8InputA		= vld1_s8(as8DataInA);
	vs8x8InputB		= vld1_s8(as8DataInB);
	vs8x8InputC		= vld1_s8(as8DataInC);

	// int8x8_t vaba_s8(int8x8_t a, int8x8_t b, int8x8_t c);					// VABA.S8 d0,d0,d0
	// a + | b - c |
	vs8x8Output		= vaba_s8(vs8x8InputA, vs8x8InputB, vs8x8InputC);
	vst1_s8(as8DataOut, vs8x8Output);

	printf("== Abs diff s8 = s8 + | s8 - s8 | (vaba_s8) ==\n");
	for (u32Idx = 0; u32Idx < 8; ++u32Idx)
	{
		printf("%4d + | %4d - %4d | = %4d\n",
			as8DataInA[u32Idx], as8DataInB[u32Idx], as8DataInC[u32Idx],
			as8DataOut[u32Idx]);
	}
	printf("========================================\n");
}

// -----------------------------------------------------------------------------
void NeonSample_AbsDiff_U16_U16_U8_U8()
{
	uint16_t	au16DataInA[8];
	uint8_t		au8DataInB[8];
	uint8_t		au8DataInC[8];
	uint16_t	au16DataOut[8];

	uint16x8_t	vu16x8InputA;
	uint8x8_t	vu8x8InputB;
	uint8x8_t	vu8x8InputC;
	uint16x8_t	vu16x8Output;

	uint32_t	u32Idx;

	// initial
	au16DataInA[0] = 10000;		au8DataInB[0] = 10;		au8DataInC[0] = 10;
	au16DataInA[1] = 10000;		au8DataInB[1] = 10;		au8DataInC[1] = 20;
	au16DataInA[2] = 10000;		au8DataInB[2] = 20;		au8DataInC[2] = 10;
	au16DataInA[3] = 10000;		au8DataInB[3] = 150;	au8DataInC[3] = 10;
	au16DataInA[4] = 10000;		au8DataInB[4] = 10;		au8DataInC[4] = 150;
	au16DataInA[5] = 10000;		au8DataInB[5] = 255;	au8DataInC[5] = 255;
	au16DataInA[6] = 10000;		au8DataInB[6] = 100;	au8DataInC[6] = 200;
	au16DataInA[7] = 65535;		au8DataInB[7] = 200;	au8DataInC[7] = 100;

	vu16x8InputA	= vld1q_u16(au16DataInA);
	vu8x8InputB		= vld1_u8(au8DataInB);
	vu8x8InputC		= vld1_u8(au8DataInC);

	// uint16x8_t vabal_u8(uint16x8_t a, uint8x8_t b, uint8x8_t c);				// VABAL.U8 q0,d0,d0
	// a + | b - c |
	vu16x8Output	= vabal_u8(vu16x8InputA, vu8x8InputB, vu8x8InputC);
	vst1q_u16(au16DataOut, vu16x8Output);

	printf("== Abs diff u16 = u16 + | u8 - u8 | (vabal_u8) ==\n");
	for (u32Idx = 0; u32Idx < 8; ++u32Idx)
	{
		printf("%5d + | %3d - %3d | = %5d\n",
			au16DataInA[u32Idx], au8DataInB[u32Idx], au8DataInC[u32Idx],
			au16DataOut[u32Idx]);
	}
	printf("========================================\n");
}

// -----------------------------------------------------------------------------
void NeonSample_AbsDiff_S16_S16_S8_S8()
{
	int16_t		as16DataInA[8];
	int8_t		as8DataInB[8];
	int8_t		as8DataInC[8];
	int16_t		as16DataOut[8];

	int16x8_t	vs16x8InputA;
	int8x8_t	vs8x8InputB;
	int8x8_t	vs8x8InputC;
	int16x8_t	vs16x8Output;

	uint32_t	u32Idx;

	// initial
	as16DataInA[0] = 10000;		as8DataInB[0] = -10;	as8DataInC[0] = -10;
	as16DataInA[1] = 10000;		as8DataInB[1] = -10;	as8DataInC[1] = -20;
	as16DataInA[2] = 10000;		as8DataInB[2] = -20;	as8DataInC[2] = -10;
	as16DataInA[3] = 10000;		as8DataInB[3] = -50;	as8DataInC[3] = 50;
	as16DataInA[4] = 10000;		as8DataInB[4] = 50;		as8DataInC[4] = -50;
	as16DataInA[5] = 10000;		as8DataInB[5] = -50;	as8DataInC[5] = 50;
	as16DataInA[6] = 32767;		as8DataInB[6] = 50;		as8DataInC[6] = -50;
	as16DataInA[7] = 10000;		as8DataInB[7] = 110;	as8DataInC[7] = 110;

	vs16x8InputA	= vld1q_s16(as16DataInA);
	vs8x8InputB		= vld1_s8(as8DataInB);
	vs8x8InputC		= vld1_s8(as8DataInC);

	// int16x8_t vabal_s8(int16x8_t a, int8x8_t b, int8x8_t c);					// VABAL.S8 q0,d0,d0
	// a + | b - c |
	vs16x8Output	= vabal_s8(vs16x8InputA, vs8x8InputB, vs8x8InputC);
	vst1q_s16(as16DataOut, vs16x8Output);

	printf("== Abs diff s16 = s16 + | s8 - s8 | (vabal_s8) ==\n");
	for (u32Idx = 0; u32Idx < 8; ++u32Idx)
	{
		printf("%6d + | %4d - %4d | = %6d\n",
			as16DataInA[u32Idx], as8DataInB[u32Idx], as8DataInC[u32Idx],
			as16DataOut[u32Idx]);
	}
	printf("========================================\n");
}

// -----------------------------------------------------------------------------
