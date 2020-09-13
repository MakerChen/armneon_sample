#include "neon_sample.h"

// https://developer.arm.com/documentation/dui0472/m/using-neon-support/neon-intrinsics-for-subtraction

// -----------------------------------------------------------------------------
void NeonSample_Sub_U8_U8_U8()
{
	uint8_t		au8DataInA[8];
	uint8_t		au8DataInB[8];
	uint8_t		au8DataOut[8];
	uint8_t		au8DataOutSaturate[8];
	uint8_t		au8DataOutHalf[8];

	uint8x8_t	vu8x8InputA;
	uint8x8_t	vu8x8InputB;
	uint8x8_t	vu8x8Output;

	uint32_t	u32Idx;

	// initial
	au8DataInA[0] = 100;	au8DataInB[0] = 10;
	au8DataInA[1] = 10;		au8DataInB[1] = 100;
	au8DataInA[2] = 100;	au8DataInB[2] = 101;
	au8DataInA[3] = 101;	au8DataInB[3] = 100;
	au8DataInA[4] = 100;	au8DataInB[4] = 199;
	au8DataInA[5] = 199;	au8DataInB[5] = 100;
	au8DataInA[6] = 100;	au8DataInB[6] = 200;
	au8DataInA[7] = 200;	au8DataInB[7] = 100;

	vu8x8InputA		= vld1_u8(au8DataInA);
	vu8x8InputB		= vld1_u8(au8DataInB);

	// uint8x8_t vsub_u8(uint8x8_t a, uint8x8_t b);								// VSUB.I8 d0,d0,d0
	// (a - b)
	vu8x8Output		= vsub_u8(vu8x8InputA, vu8x8InputB);
	vst1_u8(au8DataOut, vu8x8Output);

	// uint8x8_t vqsub_u8(uint8x8_t a, uint8x8_t b);							// VQSUB.U8 d0,d0,d0
	// SATURATE(a - b)
	vu8x8Output		= vqsub_u8(vu8x8InputA, vu8x8InputB);
	vst1_u8(au8DataOutSaturate, vu8x8Output);

	// uint8x8_t vhsub_u8(uint8x8_t a, uint8x8_t b);							// VHSUB.U8 d0,d0,d0
	// (a - b) >> 1
	vu8x8Output		= vhsub_u8(vu8x8InputA, vu8x8InputB);
	vst1_u8(au8DataOutHalf, vu8x8Output);

	printf("== Sub u8 = u8 - u8 (vsub_u8 / vqsub_u8 / vhsub_u8) ==\n");
	printf("=> vsub_u8  : u8 = u8 - u8                          ==\n");
	printf("=> vqsub_u8 : u8 = SATURATE(u8 - u8)                ==\n");
	printf("=> vhsub_u8 : u8 = (u8 - u8) >> 1                   ==\n");
	for (u32Idx = 0; u32Idx < 8; ++u32Idx)
	{
		printf("%3d - %3d = %3d, %3d, %3d\n",
			au8DataInA[u32Idx], au8DataInB[u32Idx],
			au8DataOut[u32Idx],
			au8DataOutSaturate[u32Idx],
			au8DataOutHalf[u32Idx]);
	}
	printf("========================================\n");
}

// -----------------------------------------------------------------------------
void NeonSample_Sub_S8_S8_S8()
{
	int8_t		as8DataInA[8];
	int8_t		as8DataInB[8];
	int8_t		as8DataOut[8];
	int8_t		as8DataOutSaturate[8];
	int8_t		as8DataOutHalf[8];

	int8x8_t	vs8x8InputA;
	int8x8_t	vs8x8InputB;
	int8x8_t	vs8x8Output;

	uint32_t	u32Idx;

	// initial
	as8DataInA[0] = 1;		as8DataInB[0] = 127;
	as8DataInA[1] = -120;	as8DataInB[1] = 127;
	as8DataInA[2] = -120;	as8DataInB[2] = -127;
	as8DataInA[3] = -120;	as8DataInB[3] = 126;
	as8DataInA[4] = -120;	as8DataInB[4] = -126;
	as8DataInA[5] = 125;	as8DataInB[5] = -126;
	as8DataInA[6] = 0;		as8DataInB[6] = -100;
	as8DataInA[7] = 120;	as8DataInB[7] = 120;

	vs8x8InputA		= vld1_s8(as8DataInA);
	vs8x8InputB		= vld1_s8(as8DataInB);

	// int8x8_t vsub_s8(int8x8_t a, int8x8_t b);								// VSUB.I8 d0,d0,d0
	// (a - b)
	vs8x8Output		= vsub_s8(vs8x8InputA, vs8x8InputB);
	vst1_s8(as8DataOut, vs8x8Output);

	// int8x8_t vqsub_s8(int8x8_t a, int8x8_t b);								// VQSUB.S8 d0,d0,d0
	// SATURATE(a - b)
	vs8x8Output		= vqsub_s8(vs8x8InputA, vs8x8InputB);
	vst1_s8(as8DataOutSaturate, vs8x8Output);

	// int8x8_t vhsub_s8(int8x8_t a, int8x8_t b);								// VHSUB.S8 d0,d0,d0
	// (a - b) >> 1
	vs8x8Output		= vhsub_s8(vs8x8InputA, vs8x8InputB);
	vst1_s8(as8DataOutHalf, vs8x8Output);

	printf("== Sub s8 = s8 - s8 (vsub_s8 / vqsub_s8 / vhsub_s8) ==\n");
	printf("=> vsub_s8  : s8 = s8 - s8                          ==\n");
	printf("=> vqsub_s8 : s8 = SATURATE(s8 - s8)                ==\n");
	printf("=> vhsub_s8 : s8 = (s8 - s8) >> 1                   ==\n");
	for (u32Idx = 0; u32Idx < 8; ++u32Idx)
	{
		printf("%4d - %4d = %4d, %4d, %4d\n",
			as8DataInA[u32Idx], as8DataInB[u32Idx],
			as8DataOut[u32Idx],
			as8DataOutSaturate[u32Idx],
			as8DataOutHalf[u32Idx]);
	}
	printf("========================================\n");
}

// -----------------------------------------------------------------------------
void NeonSample_Sub_F32_F32_F32()
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

	// float32x2_t vsub_f32(float32x2_t a, float32x2_t b);						// VSUB.F32 d0,d0,d0
	// (a - b)
	vf32x2Output	= vsub_f32(vf32x2InputA, vf32x2InputB);
	vst1_f32(af32DataOut, vf32x2Output);

	printf("== Sub f32 = f32 - f32 (vsub_f32) ==\n");
	for (u32Idx = 0; u32Idx < 2; ++u32Idx)
	{
		printf("%9.4f - %9.4f = %9.4f\n",
			af32DataInA[u32Idx], af32DataInB[u32Idx],
			af32DataOut[u32Idx]);
	}
	printf("========================================\n");
}

// -----------------------------------------------------------------------------
void NeonSample_Sub_U16_U8_U8()
{
	uint8_t		au8DataInA[8];
	uint8_t		au8DataInB[8];
	uint16_t	au16DataOut[8];

	uint8x8_t	vu8x8InputA;
	uint8x8_t	vu8x8InputB;
	uint16x8_t	vu16x8Output;

	uint32_t	u32Idx;

	// initial
	au8DataInA[0] = 10;		au8DataInB[0] = 100;
	au8DataInA[1] = 10;		au8DataInB[1] = 255;
	au8DataInA[2] = 100;	au8DataInB[2] = 10;
	au8DataInA[3] = 255;	au8DataInB[3] = 10;
	au8DataInA[4] = 255;	au8DataInB[4] = 0;
	au8DataInA[5] = 0;		au8DataInB[5] = 255;
	au8DataInA[6] = 100;	au8DataInB[6] = 100;
	au8DataInA[7] = 200;	au8DataInB[7] = 200;

	vu8x8InputA		= vld1_u8(au8DataInA);
	vu8x8InputB		= vld1_u8(au8DataInB);

	// uint16x8_t vsubl_u8(uint8x8_t a, uint8x8_t b);							// VSUBL.U8 q0,d0,d0
	// (a - b)
	vu16x8Output	= vsubl_u8(vu8x8InputA, vu8x8InputB);
	vst1q_u16(au16DataOut, vu16x8Output);

	printf("== Sub u16 = u8 - u8 (vsubl_u8) ==\n");
	for (u32Idx = 0; u32Idx < 8; ++u32Idx)
	{
		printf("%3d - %3d = %5d\n",
			au8DataInA[u32Idx], au8DataInB[u32Idx],
			au16DataOut[u32Idx]);
	}
	printf("========================================\n");
}

// -----------------------------------------------------------------------------
void NeonSample_Sub_S16_S8_S8()
{
	int8_t		as8DataInA[8];
	int8_t		as8DataInB[8];
	int16_t		as16DataOut[8];

	int8x8_t	vs8x8InputA;
	int8x8_t	vs8x8InputB;
	int16x8_t	vs16x8Output;

	uint32_t	u32Idx;

	// initial
	as8DataInA[0] = 127;	as8DataInB[0] = -127;
	as8DataInA[1] = -127;	as8DataInB[1] = 127;
	as8DataInA[2] = 100;	as8DataInB[2] = 10;
	as8DataInA[3] = 10;		as8DataInB[3] = 100;
	as8DataInA[4] = 100;	as8DataInB[4] = 100;
	as8DataInA[5] = 0;		as8DataInB[5] = 0;
	as8DataInA[6] = 100;	as8DataInB[6] = -100;
	as8DataInA[7] = -100;	as8DataInB[7] = 100;

	vs8x8InputA		= vld1_s8(as8DataInA);
	vs8x8InputB		= vld1_s8(as8DataInB);

	// int16x8_t vsubl_s8(int8x8_t a, int8x8_t b);								// VSUBL.S8 q0,d0,d0
	// (a - b)
	vs16x8Output	= vsubl_s8(vs8x8InputA, vs8x8InputB);
	vst1q_s16(as16DataOut, vs16x8Output);

	printf("== Sub s16 = s8 - s8 (vsubl_s8) ==\n");
	for (u32Idx = 0; u32Idx < 8; ++u32Idx)
	{
		printf("%4d - %4d = \t%d\n",
			as8DataInA[u32Idx], as8DataInB[u32Idx],
			as16DataOut[u32Idx]);
	}
	printf("========================================\n");
}

// -----------------------------------------------------------------------------
void NeonSample_Sub_U16_U16_U8()
{
	uint16_t	au16DataInA[8];
	uint8_t		au8DataInB[8];
	uint16_t	au16DataOut[8];

	uint16x8_t	vu16x8InputA;
	uint8x8_t	vu8x8InputB;
	uint16x8_t	vu16x8Output;

	uint32_t	u32Idx;

	// initial
	au16DataInA[0] = 10;	au8DataInB[0] = 255;
	au16DataInA[1] = 65535;	au8DataInB[1] = 235;
	au16DataInA[2] = 0;		au8DataInB[2] = 100;
	au16DataInA[3] = 0;		au8DataInB[3] = 100;
	au16DataInA[4] = 0;		au8DataInB[4] = 100;
	au16DataInA[5] = 0;		au8DataInB[5] = 100;
	au16DataInA[6] = 0;		au8DataInB[6] = 100;
	au16DataInA[7] = 0;		au8DataInB[7] = 100;

	vu16x8InputA	= vld1q_u16(au16DataInA);
	vu8x8InputB		= vld1_u8(au8DataInB);

	// uint16x8_t vsubw_u8(uint16x8_t a, uint8x8_t b);							// VSUBW.U8 q0,q0,d0
	// (a - b)
	vu16x8Output	= vsubw_u8(vu16x8InputA, vu8x8InputB);
	vst1q_u16(au16DataOut, vu16x8Output);

	printf("== Sub u16 = u16 - u8 (vsubw_u8) ==\n");
	for (u32Idx = 0; u32Idx < 8; ++u32Idx)
	{
		printf("%5d - %3d = %5d\n",
			au16DataInA[u32Idx], au8DataInB[u32Idx],
			au16DataOut[u32Idx]);
	}
	printf("========================================\n");
}

// -----------------------------------------------------------------------------
void NeonSample_Sub_S16_S16_S8()
{
	int16_t		as16DataInA[8];
	int8_t		as8DataInB[8];
	int16_t		as16DataOut[8];

	int16x8_t	vs16x8InputA;
	int8x8_t	vs8x8InputB;
	int16x8_t	vs16x8Output;

	uint32_t	u32Idx;

	// initial
	as16DataInA[0] = -32767;	as8DataInB[0] = -127;
	as16DataInA[1] = -32767;	as8DataInB[1] = 127;
	as16DataInA[2] = 32767;		as8DataInB[2] = -127;
	as16DataInA[3] = 32767;		as8DataInB[3] = 127;
	as16DataInA[4] = 100;		as8DataInB[4] = 100;
	as16DataInA[5] = 0;			as8DataInB[5] = 0;
	as16DataInA[6] = 100;		as8DataInB[6] = -100;
	as16DataInA[7] = -100;		as8DataInB[7] = 100;

	vs16x8InputA	= vld1q_s16(as16DataInA);
	vs8x8InputB		= vld1_s8(as8DataInB);

	// int16x8_t vsubw_s8(int16x8_t a, int8x8_t b);								// VSUBW.S8 q0,q0,d0
	// (a - b)
	vs16x8Output	= vsubw_s8(vs16x8InputA, vs8x8InputB);
	vst1q_s16(as16DataOut, vs16x8Output);

	printf("== Sub s16 = s16 - s8 (vsubw_s8) ==\n");
	for (u32Idx = 0; u32Idx < 8; ++u32Idx)
	{
		printf("%6d - %4d = %6d\n",
			as16DataInA[u32Idx], as8DataInB[u32Idx],
			as16DataOut[u32Idx]);
	}
	printf("========================================\n");
}

// -----------------------------------------------------------------------------
void NeonSample_Sub_U8_U16_U16()
{
	uint16_t	au16DataInA[8];
	uint16_t	au16DataInB[8];
	uint8_t		au8DataOutSubHighHalf[8];
	uint8_t		au8DataOutRoundSubHighHalf[8];

	uint16x8_t	vu16x8InputA;
	uint16x8_t	vu16x8InputB;
	uint8x8_t	vu8x8Output;

	uint32_t	u32Idx;

	// initial
	au16DataInA[0] = 10000;	au16DataInB[0] = 5000;
	au16DataInA[1] = 10000;	au16DataInB[1] = 5001;
	au16DataInA[2] = 0;		au16DataInB[2] = 10000;
	au16DataInA[3] = 0;		au16DataInB[3] = 10001;
	au16DataInA[4] = 1000;	au16DataInB[4] = 900;
	au16DataInA[5] = 1000;	au16DataInB[5] = 901;
	au16DataInA[6] = 0;		au16DataInB[6] = 100;
	au16DataInA[7] = 0;		au16DataInB[7] = 101;

	vu16x8InputA	= vld1q_u16(au16DataInA);
	vu16x8InputB	= vld1q_u16(au16DataInB);

	// uint8x8_t vsubhn_u16(uint16x8_t a, uint16x8_t b);						// VSUBHN.I16 d0,q0,q0
	// (a - b) >> 8
	vu8x8Output		= vsubhn_u16(vu16x8InputA, vu16x8InputB);
	vst1_u8(au8DataOutSubHighHalf, vu8x8Output);

	// uint8x8_t vrsubhn_u16(uint16x8_t a, uint16x8_t b);						// VRSUBHN.I16 d0,q0,q0
	// ROUND((a - b) >> 8)
	vu8x8Output		= vrsubhn_u16(vu16x8InputA, vu16x8InputB);
	vst1_u8(au8DataOutRoundSubHighHalf, vu8x8Output);

	printf("== Sub u8 = u16 - u16 (vsubhn_u16 / vrsubhn_u16) ==\n");
	printf("=> vsubhn_u16  : u8 = (u16 - u16) >> 8           ==\n");
	printf("=> vrsubhn_u16 : u8 = ROUND((u16 - u16) >> 8)    ==\n");
	for (u32Idx = 0; u32Idx < 8; ++u32Idx)
	{
		printf("%5d - %5d = %3d, %3d\n",
			au16DataInA[u32Idx], au16DataInB[u32Idx],
			au8DataOutSubHighHalf[u32Idx],
			au8DataOutRoundSubHighHalf[u32Idx]);
	}
	printf("========================================\n");
}

// -----------------------------------------------------------------------------
void NeonSample_Sub_S8_S16_S16()
{
	int16_t		as16DataInA[8];
	int16_t		as16DataInB[8];
	int8_t		as8DataOutSubHighHalf[8];
	int8_t		as8DataOutRoundSubHighHalf[8];

	int16x8_t	vs16x8InputA;
	int16x8_t	vs16x8InputB;
	int8x8_t	vs8x8Output;

	uint32_t	u32Idx;

	// initial
	as16DataInA[0] = 10000;		as16DataInB[0] = 5000;
	as16DataInA[1] = 10000;		as16DataInB[1] = 5001;
	as16DataInA[2] = 0;			as16DataInB[2] = 10000;
	as16DataInA[3] = 0;			as16DataInB[3] = 10001;
	as16DataInA[4] = 1000;		as16DataInB[4] = 900;
	as16DataInA[5] = 1000;		as16DataInB[5] = 901;
	as16DataInA[6] = 0;			as16DataInB[6] = 100;
	as16DataInA[7] = 0;			as16DataInB[7] = 101;

	vs16x8InputA	= vld1q_s16(as16DataInA);
	vs16x8InputB	= vld1q_s16(as16DataInB);

	// int8x8_t vsubhn_s16(int16x8_t a, int16x8_t b);							// VSUBHN.I16 d0,q0,q0
	// (a - b) >> 8
	vs8x8Output		= vsubhn_s16(vs16x8InputA, vs16x8InputB);
	vst1_s8(as8DataOutSubHighHalf, vs8x8Output);

	// int8x8_t vrsubhn_s16(int16x8_t a, int16x8_t b);							// VRSUBHN.I16 d0,q0,q0
	// ROUND((a - b) >> 8)
	vs8x8Output		= vrsubhn_s16(vs16x8InputA, vs16x8InputB);
	vst1_s8(as8DataOutRoundSubHighHalf, vs8x8Output);

	printf("== Sub s8 = s16 - s16 (vsubhn_s16 / vrsubhn_s16) ==\n");
	printf("=> vsubhn_s16  : s8 = (s16 - s16) >> 8           ==\n");
	printf("=> vrsubhn_s16 : s8 = ROUND((s16 - s16) >> 8)    ==\n");
	for (u32Idx = 0; u32Idx < 8; ++u32Idx)
	{
		printf("%6d - %6d = %4d, %4d\n",
			as16DataInA[u32Idx], as16DataInB[u32Idx],
			as8DataOutSubHighHalf[u32Idx],
			as8DataOutRoundSubHighHalf[u32Idx]);
	}
	printf("========================================\n");
}

// -----------------------------------------------------------------------------
