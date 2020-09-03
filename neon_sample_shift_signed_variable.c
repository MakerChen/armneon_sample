#include "neon_sample.h"

// https://developer.arm.com/documentation/dui0472/m/using-neon-support/neon-intrinsics-for-shifts-by-signed-variable

// -----------------------------------------------------------------------------
void NeonSample_ShiftSigned_U8_U8_U8()
{
	uint8_t		au8DataInA[8];
	uint8_t		au8DataInB[8];
	uint8_t		au8DataOut[8];
	uint8_t		au8DataOutSaturate[8];
	uint8_t		au8DataOutRound[8];
	uint8_t		au8DataOutSaturateRound[8];

	uint8x8_t	vu8x8InputA;
	uint8x8_t	vu8x8InputB;
	uint8x8_t	vu8x8Output;

	uint32_t	u32Idx;

	// initial
	au8DataInA[0] = 0;		au8DataInB[0] = 1;
	au8DataInA[1] = 30;		au8DataInB[1] = 2;
	au8DataInA[2] = 60;		au8DataInB[2] = 3;
	au8DataInA[3] = 90;		au8DataInB[3] = 4;
	au8DataInA[4] = 120;	au8DataInB[4] = 0;
	au8DataInA[5] = 150;	au8DataInB[5] = 1;
	au8DataInA[6] = 180;	au8DataInB[6] = 2;
	au8DataInA[7] = 210;	au8DataInB[7] = 3;

	vu8x8InputA		= vld1_u8(au8DataInA);
	vu8x8InputB		= vld1_u8(au8DataInB);

	// uint8x8_t vshl_u8(uint8x8_t a, int8x8_t b);								// VSHL.U8 d0,d0,d0
	// (a << b)
	vu8x8Output		= vshl_u8(vu8x8InputA, vu8x8InputB);
	vst1_u8(au8DataOut, vu8x8Output);

	// uint8x8_t vqshl_u8(uint8x8_t a, int8x8_t b);								// VQSHL.U8 d0,d0,d0
	// SATURATE(a << b)
	vu8x8Output		= vqshl_u8(vu8x8InputA, vu8x8InputB);
	vst1_u8(au8DataOutSaturate, vu8x8Output);

	// uint8x8_t vrshl_u8(uint8x8_t a, int8x8_t b);								// VRSHL.U8 d0,d0,d0
	// ROUND(a << b)
	vu8x8Output		= vrshl_u8(vu8x8InputA, vu8x8InputB);
	vst1_u8(au8DataOutRound, vu8x8Output);

	// uint8x8_t vqrshl_u8(uint8x8_t a, int8x8_t b);							// VQRSHL.U8 d0,d0,d0
	// SATURATE(ROUND(a << b))
	vu8x8Output		= vqrshl_u8(vu8x8InputA, vu8x8InputB);
	vst1_u8(au8DataOutSaturateRound, vu8x8Output);

	printf("== Shift u8 = u8 << u8 (vshl_u8 / vqshl_u8 / vrshl_u8 / vqrshl_u8) ==\n");
	printf("=> vshl_u8   : u8 = u8 << u8                                       ==\n");
	printf("=> vqshl_u8  : u8 = SATURATE(u8 << u8)                             ==\n");
	printf("=> vrshl_u8  : u8 = ROUND(u8 << u8)                                ==\n");
	printf("=> vqrshl_u8 : u8 = SATURATE(ROUND(u8 << u8))                      ==\n");
	for (u32Idx = 0; u32Idx < 8; ++u32Idx)
	{
		printf("%3d << %3d = %3d, %3d, %3d, %3d\n",
			au8DataInA[u32Idx], au8DataInB[u32Idx],
			au8DataOut[u32Idx],
			au8DataOutSaturate[u32Idx],
			au8DataOutRound[u32Idx],
			au8DataOutSaturateRound[u32Idx]);
	}
	printf("========================================\n");
}

// -----------------------------------------------------------------------------
void NeonSample_ShiftSigned_S8_S8_S8()
{
	int8_t		as8DataInA[8];
	int8_t		as8DataInB_p[8];
	int8_t		as8DataInB_n[8];
	int8_t		as8DataOut_p[8];
	int8_t		as8DataOut_n[8];
	int8_t		as8DataOutSaturate_p[8];
	int8_t		as8DataOutSaturate_n[8];
	int8_t		as8DataOutRound_p[8];
	int8_t		as8DataOutRound_n[8];
	int8_t		as8DataOutSaturateRound_p[8];
	int8_t		as8DataOutSaturateRound_n[8];

	int8x8_t	vs8x8InputA;
	int8x8_t	vs8x8InputBp;
	int8x8_t	vs8x8InputBn;
	int8x8_t	vs8x8Output;

	uint32_t	u32Idx;

	// initial
	as8DataInA[0] = 0;		as8DataInB_p[0] = 1;	as8DataInB_n[0] = -1;
	as8DataInA[1] = 64;		as8DataInB_p[1] = 2;	as8DataInB_n[1] = -2;
	as8DataInA[2] = 81;		as8DataInB_p[2] = 2;	as8DataInB_n[2] = -2;
	as8DataInA[3] = 83;		as8DataInB_p[3] = 2;	as8DataInB_n[3] = -2;
	as8DataInA[4] = 128;	as8DataInB_p[4] = 0;	as8DataInB_n[4] = 0;
	as8DataInA[5] = -32;	as8DataInB_p[5] = 1;	as8DataInB_n[5] = -1;
	as8DataInA[6] = -64;	as8DataInB_p[6] = 2;	as8DataInB_n[6] = -2;
	as8DataInA[7] = -128;	as8DataInB_p[7] = 3;	as8DataInB_n[7] = -3;

	vs8x8InputA		= vld1_s8(as8DataInA);
	vs8x8InputBp	= vld1_s8(as8DataInB_p);
	vs8x8InputBn	= vld1_s8(as8DataInB_n);

	// int8x8_t vshl_s8(int8x8_t a, int8x8_t b);								// VSHL.S8 d0,d0,d0
	// (a << b)
	vs8x8Output		= vshl_s8(vs8x8InputA, vs8x8InputBp);
	vst1_s8(as8DataOut_p, vs8x8Output);

	// int8x8_t vqshl_s8(int8x8_t a, int8x8_t b);								// VQSHL.S8 d0,d0,d0
	// SATURATE(a << b)
	vs8x8Output		= vqshl_s8(vs8x8InputA, vs8x8InputBp);
	vst1_s8(as8DataOutSaturate_p, vs8x8Output);

	// int8x8_t vrshl_s8(int8x8_t a, int8x8_t b);								// VRSHL.S8 d0,d0,d0
	// ROUND(a << b)
	vs8x8Output		= vrshl_s8(vs8x8InputA, vs8x8InputBp);
	vst1_s8(as8DataOutRound_p, vs8x8Output);

	// int8x8_t vqrshl_s8(int8x8_t a, int8x8_t b);								// VQRSHL.S8 d0,d0,d0
	// SATURATE(ROUND(a << b))
	vs8x8Output		= vqrshl_s8(vs8x8InputA, vs8x8InputBp);
	vst1_s8(as8DataOutSaturateRound_p, vs8x8Output);

	printf("== Shift s8 = s8 << s8 (vshl_s8 / vqshl_s8 / vrshl_s8 / vqrshl_s8) ==\n");
	printf("=> vshl_s8   : s8 = s8 << s8                                       ==\n");
	printf("=> vqshl_s8  : s8 = SATURATE(s8 << s8)                             ==\n");
	printf("=> vrshl_s8  : s8 = ROUND(s8 << s8)                                ==\n");
	printf("=> vqrshl_s8 : s8 = SATURATE(ROUND(s8 << s8))                      ==\n");
	for (u32Idx = 0; u32Idx < 8; ++u32Idx)
	{
		printf("%4d << %4d = %4d, %4d, %4d, %4d\n",
			as8DataInA[u32Idx], as8DataInB_p[u32Idx],
			as8DataOut_p[u32Idx],
			as8DataOutSaturate_p[u32Idx],
			as8DataOutRound_p[u32Idx],
			as8DataOutSaturateRound_p[u32Idx]);
	}
	printf("========================================\n");

	// int8x8_t vshl_s8(int8x8_t a, int8x8_t b);								// VSHL.S8 d0,d0,d0
	// (a >> b), b <= 0
	vs8x8Output		= vshl_s8(vs8x8InputA, vs8x8InputBn);
	vst1_s8(as8DataOut_n, vs8x8Output);

	// int8x8_t vqshl_s8(int8x8_t a, int8x8_t b);								// VQSHL.S8 d0,d0,d0
	// SATURATE(a >> b), b <= 0
	vs8x8Output		= vqshl_s8(vs8x8InputA, vs8x8InputBn);
	vst1_s8(as8DataOutSaturate_n, vs8x8Output);

	// int8x8_t vrshl_s8(int8x8_t a, int8x8_t b);								// VRSHL.S8 d0,d0,d0
	// ROUND(a >> b), b <= 0
	vs8x8Output		= vrshl_s8(vs8x8InputA, vs8x8InputBn);
	vst1_s8(as8DataOutRound_n, vs8x8Output);

	// int8x8_t vqrshl_s8(int8x8_t a, int8x8_t b);								// VQRSHL.S8 d0,d0,d0
	// SATURATE(ROUND(a >> b)), b <= 0
	vs8x8Output		= vqrshl_s8(vs8x8InputA, vs8x8InputBn);
	vst1_s8(as8DataOutSaturateRound_n, vs8x8Output);

	printf("== Shift s8 = s8 >> s8, (b <= 0) (vshl_s8 / vqshl_s8 / vrshl_s8 / vqrshl_s8) ==\n");
	printf("=> vshl_s8   : s8 = s8 >> s8                                                 ==\n");
	printf("=> vqshl_s8  : s8 = SATURATE(s8 >> s8)                                       ==\n");
	printf("=> vrshl_s8  : s8 = ROUND(s8 >> s8)                                          ==\n");
	printf("=> vqrshl_s8 : s8 = SATURATE(ROUND(s8 >> s8))                                ==\n");
	for (u32Idx = 0; u32Idx < 8; ++u32Idx)
	{
		printf("%4d << %4d = %4d, %4d, %4d, %4d\n",
			as8DataInA[u32Idx], as8DataInB_n[u32Idx],
			as8DataOut_n[u32Idx],
			as8DataOutSaturate_n[u32Idx],
			as8DataOutRound_n[u32Idx],
			as8DataOutSaturateRound_n[u32Idx]);
	}
	printf("========================================\n");
}

// -----------------------------------------------------------------------------
