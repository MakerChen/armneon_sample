#include "neon_sample.h"

// https://developer.arm.com/documentation/dui0472/m/using-neon-support/neon-intrinsics-for-shifts-by-a-constant

// -----------------------------------------------------------------------------
void NeonSample_ShiftConstant_U8_U8_SU8()
{
	uint8_t		au8DataIn[8];
	uint8_t		au8DataOutRight[8];
	uint8_t		au8DataOutLeft[8];
	uint8_t		au8DataOutRightRound[8];
	uint8_t		au8DataOutLeftSaturate[8];

	uint8_t		u8CoefShiftRight;
	uint8_t		u8CoefShiftLeft;

	uint8x8_t	vu8x8InputA;
	uint8x8_t	vu8x8Output;

	uint32_t	u32Idx;

	// initial
	au8DataIn[0] = 0;
	au8DataIn[1] = 32;
	au8DataIn[2] = 35;
	au8DataIn[3] = 64;
	au8DataIn[4] = 65;
	au8DataIn[5] = 127;
	au8DataIn[6] = 128;
	au8DataIn[7] = 129;

	u8CoefShiftRight	= 4;
	u8CoefShiftLeft		= 2;

	vu8x8InputA		= vld1_u8(au8DataIn);

	// uint8x8_t vshr_n_u8(uint8x8_t a, __constrange(1,8) int b);				// VSHR.U8 d0,d0,#8
	// (a >> b), (1 ~ 8)
	vu8x8Output		= vshr_n_u8(vu8x8InputA, u8CoefShiftRight);
	vst1_u8(au8DataOutRight, vu8x8Output);

	// uint8x8_t vrshr_n_u8(uint8x8_t a, __constrange(1,8) int b);				// VRSHR.U8 d0,d0,#8
	// (a + 2^(b-1)) >> b), (1 ~ 8)
	vu8x8Output		= vrshr_n_u8(vu8x8InputA, u8CoefShiftRight);
	vst1_u8(au8DataOutRightRound, vu8x8Output);

	printf("== Shift u8 = u8 >> u8 (vshr_n_u8 / vrshr_n_u8) ==\n");
	printf("=> vshr_n_u8  : u8 = u8 >> u8                   ==\n");
	printf("=> vrshr_n_u8 : u8 = ROUND(u8 >> u8)            ==\n");
	for (u32Idx = 0; u32Idx < 8; ++u32Idx)
	{
		printf("%3d >> %1d = %3d, %3d\n",
			au8DataIn[u32Idx], u8CoefShiftRight,
			au8DataOutRight[u32Idx],
			au8DataOutRightRound[u32Idx]);
	}
	printf("========================================\n");

	// uint8x8_t vshl_n_u8(uint8x8_t a, __constrange(0,7) int b);				// VSHL.I8 d0,d0,#0
	// (a << b), (0 ~ 7)
	vu8x8Output		= vshl_n_u8(vu8x8InputA, u8CoefShiftLeft);
	vst1_u8(au8DataOutLeft, vu8x8Output);

	// uint8x8_t vqshl_n_u8(uint8x8_t a, __constrange(0,7) int b);				// VQSHL.U8 d0,d0,#0
	// SATURATE(a << b), (0 ~ 7)
	vu8x8Output		= vqshl_n_u8(vu8x8InputA, u8CoefShiftLeft);
	vst1_u8(au8DataOutLeftSaturate, vu8x8Output);

	printf("== Shift u8 = u8 << u8 (vshl_n_u8 / vqshl_n_u8) ==\n");
	printf("=> vshl_n_u8  : u8 = u8 << u8                   ==\n");
	printf("=> vqshl_n_u8 : u8 = SATURATE(u8 << u8)         ==\n");
	for (u32Idx = 0; u32Idx < 8; ++u32Idx)
	{
		printf("%3d << %1d = %3d, %3d\n",
			au8DataIn[u32Idx], u8CoefShiftLeft,
			au8DataOutLeft[u32Idx],
			au8DataOutLeftSaturate[u32Idx]);
	}
	printf("========================================\n");
}

// -----------------------------------------------------------------------------
void NeonSample_ShiftConstant_S8_S8_SU8()
{
	int8_t		as8DataIn[8];
	int8_t		as8DataOutRight[8];
	int8_t		as8DataOutLeft[8];
	int8_t		as8DataOutRightRound[8];
	int8_t		as8DataOutLeftSaturate[8];

	uint8_t		u8CoefShiftRight;
	uint8_t		u8CoefShiftLeft;

	int8x8_t	vs8x8InputA;
	int8x8_t	vs8x8Output;

	uint32_t	u32Idx;

	// initial
	as8DataIn[0] = 0;
	as8DataIn[1] = 64;
	as8DataIn[2] = 65;
	as8DataIn[3] = 127;
	as8DataIn[4] = 128;
	as8DataIn[5] = -63;
	as8DataIn[6] = -64;
	as8DataIn[7] = -65;

	u8CoefShiftRight	= 4;
	u8CoefShiftLeft		= 2;

	vs8x8InputA		= vld1_s8(as8DataIn);

	// int8x8_t vshr_n_s8(int8x8_t a, __constrange(1,8) int b);					// VSHR.S8 d0,d0,#8
	// (a >> b), (1 ~ 8)
	vs8x8Output		= vshr_n_s8(vs8x8InputA, u8CoefShiftRight);
	vst1_s8(as8DataOutRight, vs8x8Output);

	// int8x8_t vrshr_n_s8(int8x8_t a, __constrange(1,8) int b);				// VRSHR.S8 d0,d0,#8
	// ROUND(a >> b), (1 ~ 8)
	vs8x8Output		= vrshr_n_s8(vs8x8InputA, u8CoefShiftRight);
	vst1_s8(as8DataOutRightRound, vs8x8Output);

	printf("== Shift s8 = s8 >> u8 (vshr_n_s8 / vrshr_n_s8) ==\n");
	printf("=> vshr_n_s8  : s8 = s8 >> u8                   ==\n");
	printf("=> vrshr_n_s8 : s8 = ROUND(s8 >> u8)            ==\n");
	for (u32Idx = 0; u32Idx < 8; ++u32Idx)
	{
		printf("%4d >> %1d = %4d, %4d\n",
			as8DataIn[u32Idx], u8CoefShiftRight,
			as8DataOutRight[u32Idx],
			as8DataOutRightRound[u32Idx]);
	}
	printf("========================================\n");

	// int8x8_t vshl_n_s8(int8x8_t a, __constrange(0,7) int b);					// VSHL.I8 d0,d0,#0
	// (a << b), (0 ~ 7)
	vs8x8Output		= vshl_n_s8(vs8x8InputA, u8CoefShiftLeft);
	vst1_s8(as8DataOutLeft, vs8x8Output);

	// int8x8_t vqshl_n_s8(int8x8_t a, __constrange(0,7) int b);				// VQSHL.S8 d0,d0,#0
	// SATURATE(a << b), (0 ~ 7)
	vs8x8Output		= vqshl_n_s8(vs8x8InputA, u8CoefShiftLeft);
	vst1_s8(as8DataOutLeftSaturate, vs8x8Output);

	printf("== Shift s8 = s8 << u8 (vshl_n_s8 / vqshl_n_s8) ==\n");
	printf("=> vshl_n_s8  : s8 = s8 << u8                   ==\n");
	printf("=> vqshl_n_s8 : s8 = SATURATE(s8 << u8)         ==\n");
	for (u32Idx = 0; u32Idx < 8; ++u32Idx)
	{
		printf("%4d << %1d = %4d, %4d\n",
			as8DataIn[u32Idx], u8CoefShiftLeft,
			as8DataOutLeft[u32Idx],
			as8DataOutLeftSaturate[u32Idx]);
	}
	printf("========================================\n");
}

// -----------------------------------------------------------------------------
void NeonSample_ShiftConstant_U8_S8_SU8()
{
	int8_t		as8DataIn[8];
	uint8_t		au8DataOut[8];

	uint8_t		u8CoefShift;

	int8x8_t	vs8x8InputA;
	uint8x8_t	vu8x8Output;

	uint32_t	u32Idx;

	// initial
	as8DataIn[0] = 2;
	as8DataIn[1] = 10;
	as8DataIn[2] = 20;
	as8DataIn[3] = 40;
	as8DataIn[4] = 50;
	as8DataIn[5] = -10;
	as8DataIn[6] = -20;
	as8DataIn[7] = -30;

	u8CoefShift		= 4;

	vs8x8InputA		= vld1_s8(as8DataIn);

	// uint8x8_t vqshlu_n_s8(int8x8_t a, __constrange(0,7) int b);				// VQSHLU.S8 d0,d0,#0
	// SATURATE(a << b), (0 ~ 7)
	vu8x8Output		= vqshlu_n_s8(vs8x8InputA, u8CoefShift);
	vst1_u8(au8DataOut, vu8x8Output);

	// Vector signed->unsigned saturating shift left by constant: vqshlu -> ri = ai << b;
	// left shifts each element in a vector of integers by an immediate value, places the
	// results in the destination vector, the sticky QC flag is set if saturation occurs,
	// and indicates that the results are unsigned even though the operands are signed

	printf("== Shift u8 = SATURATE(s8 << u8) (vqshlu_n_s8) ==\n");
	for (u32Idx = 0; u32Idx < 8; ++u32Idx)
	{
		printf("SATURATE(%4d << %1d) = %3d\n",
			as8DataIn[u32Idx], u8CoefShift,
			au8DataOut[u32Idx]);
	}
	printf("========================================\n");
}

// -----------------------------------------------------------------------------
void NeonSample_ShiftConstant_U8_U16_SU8()
{
	uint16_t	au16DataIn[8];
	uint8_t		au8DataOutNarrow[8];
	uint8_t		au8DataOutNarrowSaturate[8];
	uint8_t		au8DataOutRoundNarrow[8];
	uint8_t		au8DataOutRoundNarrowSaturate[8];

	uint8_t		u8CoefShift;

	uint16x8_t	vu16x8InputA;
	uint8x8_t	vu8x8Output;

	uint32_t	u32Idx;

	// initial
	au16DataIn[0] = 255;
	au16DataIn[1] = 256;
	au16DataIn[2] = 257;
	au16DataIn[3] = 260;
	au16DataIn[4] = 30000;
	au16DataIn[5] = 32768;
	au16DataIn[6] = 40000;
	au16DataIn[7] = 65535;

	u8CoefShift		= 3;

	vu16x8InputA	= vld1q_u16(au16DataIn);

	// uint8x8_t vshrn_n_u16(uint16x8_t a, __constrange(1,8) int b);			// VSHRN.I16 d0,q0,#8
	// NARROW(a >> b), (1 ~ 8)
	vu8x8Output		= vshrn_n_u16(vu16x8InputA, u8CoefShift);
	vst1_u8(au8DataOutNarrow, vu8x8Output);

	// int8x8_t vqshrn_n_u16(uint16x8_t a, __constrange(1,8) int b);			// VQSHRN.U16 d0,q0,#8
	// NARROW(SATURATE(a >> b)), (1 ~ 8)
	vu8x8Output		= vqshrn_n_u16(vu16x8InputA, u8CoefShift);
	vst1_u8(au8DataOutNarrowSaturate, vu8x8Output);

	// uint8x8_t vrshrn_n_u16(uint16x8_t a, __constrange(1,8) int b);			// VRSHRN.I16 d0,q0,#8
	// ROUND(NARROW(a >> b)), (1 ~ 8)
	vu8x8Output		= vrshrn_n_u16(vu16x8InputA, u8CoefShift);
	vst1_u8(au8DataOutRoundNarrow, vu8x8Output);

	// uint8x8_t vqrshrn_n_u16(uint16x8_t a, __constrange(1,8) int b);			// VQRSHRN.U16 d0,q0,#8
	// ROUND(NARROW(SATURATE(a >> b))), (1 ~ 8)
	vu8x8Output		= vqrshrn_n_u16(vu16x8InputA, u8CoefShift);
	vst1_u8(au8DataOutRoundNarrowSaturate, vu8x8Output);

	printf("== Shift u8 = u16 >> u8 (vshrn_n_u16 / vqshrn_n_u16 / vrshrn_n_u16 / vqrshrn_n_u16) ==\n");
	printf("=> vshrn_n_u16   : u8 = NARROW(u16 >> u8)                                           ==\n");
	printf("=> vqshrn_n_u16  : u8 = NARROW(SATURATE(u16 >> u8))                                 ==\n");
	printf("=> vrshrn_n_u16  : u8 = ROUND(NARROW(u16 >> u8))                                    ==\n");
	printf("=> vqrshrn_n_u16 : u8 = ROUND(NARROW(SATURATE(u16 >> u8)))                          ==\n");
	for (u32Idx = 0; u32Idx < 8; ++u32Idx)
	{
		printf("%5d >> %1d = %3d, %3d, %3d, %3d\n",
			au16DataIn[u32Idx], u8CoefShift,
			au8DataOutNarrow[u32Idx],
			au8DataOutNarrowSaturate[u32Idx],
			au8DataOutRoundNarrow[u32Idx],
			au8DataOutRoundNarrowSaturate[u32Idx]);
	}
	printf("========================================\n");
}

// -----------------------------------------------------------------------------
void NeonSample_ShiftConstant_S8_S16_SU8()
{
	int16_t		as16DataIn[8];
	int8_t		as8DataOutNarrow[8];
	int8_t		as8DataOutNarrowSaturate[8];
	int8_t		as8DataOutRoundNarrow[8];
	int8_t		as8DataOutRoundNarrowSaturate[8];

	uint8_t		u8CoefShift;

	int16x8_t	vs16x8InputA;
	int8x8_t	vs8x8Output;

	uint32_t	u32Idx;

	// initial
	as16DataIn[0] = 512;
	as16DataIn[1] = -512;
	as16DataIn[2] = 16300;
	as16DataIn[3] = 16384;
	as16DataIn[4] = 16400;
	as16DataIn[5] = -16300;
	as16DataIn[6] = -16384;
	as16DataIn[7] = -16400;

	u8CoefShift		= 7;

	vs16x8InputA	= vld1q_s16(as16DataIn);

	// int8x8_t vshrn_n_s16(int16x8_t a, __constrange(1,8) int b);				// VSHRN.I16 d0,q0,#8
	// NARROW(a >> b), (1 ~ 8)
	vs8x8Output		= vshrn_n_s16(vs16x8InputA, u8CoefShift);
	vst1_s8(as8DataOutNarrow, vs8x8Output);

	// int8x8_t vqshrn_n_s16(int16x8_t a, __constrange(1,8) int b);				// VQSHRN.S16 d0,q0,#8
	// NARROW(SATURATE(a >> b)), (1 ~ 8)
	vs8x8Output		= vqshrn_n_s16(vs16x8InputA, u8CoefShift);
	vst1_s8(as8DataOutNarrowSaturate, vs8x8Output);

	// int8x8_t vrshrn_n_s16(int16x8_t a, __constrange(1,8) int b);				// VRSHRN.I16 d0,q0,#8
	// ROUND(NARROW(a >> b)), (1 ~ 8)
	vs8x8Output		= vrshrn_n_s16(vs16x8InputA, u8CoefShift);
	vst1_s8(as8DataOutRoundNarrow, vs8x8Output);

	// int8x8_t vqrshrn_n_s16(int16x8_t a, __constrange(1,8) int b);			// VQRSHRN.S16 d0,q0,#8
	// ROUND(NARROW(SATURATE(a >> b))), (1 ~ 8)
	vs8x8Output		= vqrshrn_n_s16(vs16x8InputA, u8CoefShift);
	vst1_s8(as8DataOutRoundNarrowSaturate, vs8x8Output);

	printf("== Shift s8 = s16 >> s8 (vshrn_n_s16 / vqshrn_n_s16 / vrshrn_n_s16 / vqrshrn_n_s16) ==\n");
	printf("=> vshrn_n_s16   : s8 = NARROW(s16 >> s8)                                           ==\n");
	printf("=> vqshrn_n_s16  : s8 = NARROW(SATURATE(s16 >> s8))                                 ==\n");
	printf("=> vrshrn_n_s16  : s8 = ROUND(NARROW(s16 >> s8))                                    ==\n");
	printf("=> vqrshrn_n_s16 : s8 = ROUND(NARROW(SATURATE(s16 >> s8)))                          ==\n");
	for (u32Idx = 0; u32Idx < 8; ++u32Idx)
	{
		printf("%6d >> %1d = %4d, %4d, %4d, %4d\n",
			as16DataIn[u32Idx], u8CoefShift,
			as8DataOutNarrow[u32Idx],
			as8DataOutNarrowSaturate[u32Idx],
			as8DataOutRoundNarrow[u32Idx],
			as8DataOutRoundNarrowSaturate[u32Idx]);
	}
	printf("========================================\n");
}

// -----------------------------------------------------------------------------
void NeonSample_ShiftConstant_U8_S16_SU8()
{
	int16_t		as16DataIn[8];
	uint8_t		au8DataOutNarrowSaturate[8];
	uint8_t		au8DataOutRoundNarrowSaturate[8];

	uint8_t		u8CoefShift;

	int16x8_t	vs16x8InputA;
	uint8x8_t	vu8x8Output;

	uint32_t	u32Idx;

	// initial
	as16DataIn[0] = 511;
	as16DataIn[1] = 512;
	as16DataIn[2] = 515;
	as16DataIn[3] = 516;
	as16DataIn[4] = -512;
	as16DataIn[5] = -16300;
	as16DataIn[6] = -16384;
	as16DataIn[7] = -16400;

	u8CoefShift		= 3;

	vs16x8InputA	= vld1q_s16(as16DataIn);

	// uint8x8_t vqshrun_n_s16(int16x8_t a, __constrange(1,8) int b);			// VQSHRUN.S16 d0,q0,#8
	// NARROW(SATURATE(a >> b)), (1 ~ 8)
	vu8x8Output		= vqshrun_n_s16(vs16x8InputA, u8CoefShift);
	vst1_u8(au8DataOutNarrowSaturate, vu8x8Output);

	// uint8x8_t vqrshrun_n_s16(int16x8_t a, __constrange(1,8) int b);			// VQRSHRUN.S16 d0,q0,#8
	// ROUND(NARROW(SATURATE(a >> b))), (1 ~ 8)
	vu8x8Output		= vqrshrun_n_s16(vs16x8InputA, u8CoefShift);
	vst1_u8(au8DataOutRoundNarrowSaturate, vu8x8Output);

	printf("== Shift u8 = s16 >> s8 (vqshrun_n_s16 / vqrshrun_n_s16)    ==\n");
	printf("=> vqshrun_n_s16  : u8 = NARROW(SATURATE(s16 >> s8))        ==\n");
	printf("=> vqrshrun_n_s16 : u8 = ROUND(NARROW(SATURATE(s16 >> s8))) ==\n");
	for (u32Idx = 0; u32Idx < 8; ++u32Idx)
	{
		printf("%6d >> %1d = %3d, %3d\n",
			as16DataIn[u32Idx], u8CoefShift,
			au8DataOutNarrowSaturate[u32Idx],
			au8DataOutRoundNarrowSaturate[u32Idx]);
	}
	printf("========================================\n");
}

// -----------------------------------------------------------------------------
void NeonSample_ShiftConstant_U16_U8_SU8()
{
	uint8_t		au8DataIn[8];
	uint16_t	au16DataOut[8];

	uint8_t		u8CoefShift;

	uint8x8_t	vu8x8InputA;
	uint16x8_t	vu16x8Output;

	uint32_t	u32Idx;

	// initial
	au8DataIn[0] = 0;
	au8DataIn[1] = 32;
	au8DataIn[2] = 35;
	au8DataIn[3] = 64;
	au8DataIn[4] = 65;
	au8DataIn[5] = 127;
	au8DataIn[6] = 128;
	au8DataIn[7] = 129;

	u8CoefShift		= 4;

	vu8x8InputA		= vld1_u8(au8DataIn);

	// uint16x8_t vshll_n_u8(uint8x8_t a, __constrange(0,8) int b);				// VSHLL.U8 q0,d0,#0
	// (a << b), (0 ~ 8)
	vu16x8Output	= vshll_n_u8(vu8x8InputA, u8CoefShift);
	vst1q_u16(au16DataOut, vu16x8Output);

	printf("== Shift u16 = u8 << u8 (vshll_n_u8) ==\n");
	for (u32Idx = 0; u32Idx < 8; ++u32Idx)
	{
		printf("%3d << %1d = %5d\n",
			au8DataIn[u32Idx], u8CoefShift,
			au16DataOut[u32Idx]);
	}
	printf("========================================\n");
}

// -----------------------------------------------------------------------------
void NeonSample_ShiftConstant_S16_S8_SU8()
{
	int8_t		as8DataIn[8];
	int16_t		as16DataOut[8];

	uint8_t		u8CoefShift;

	int8x8_t	vs8x8InputA;
	int16x8_t	vs16x8Output;

	uint32_t	u32Idx;

	// initial
	as8DataIn[0] = -1;
	as8DataIn[1] = 1;
	as8DataIn[2] = -64;
	as8DataIn[3] = 64;
	as8DataIn[4] = -127;
	as8DataIn[5] = 128;
	as8DataIn[6] = -5;
	as8DataIn[7] = 5;

	u8CoefShift		= 4;

	vs8x8InputA		= vld1_s8(as8DataIn);

	// int16x8_t vshll_n_s8(int8x8_t a, __constrange(0,8) int b);				// VSHLL.S8 q0,d0,#0
	// (a << b), (0 ~ 8)
	vs16x8Output	= vshll_n_s8(vs8x8InputA, u8CoefShift);
	vst1q_s16(as16DataOut, vs16x8Output);

	printf("== Shift s16 = s8 << u8 (vshll_n_s8) ==\n");
	for (u32Idx = 0; u32Idx < 8; ++u32Idx)
	{
		printf("%4d << %1d = %6d\n",
			as8DataIn[u32Idx], u8CoefShift,
			as16DataOut[u32Idx]);
	}
	printf("========================================\n");
}

// -----------------------------------------------------------------------------
void NeonSample_ShiftConstant_U8_U8_U8_SU8()
{
	uint8_t		au8DataInA[8];
	uint8_t		au8DataInB[8];
	uint8_t		au8DataOutAdd[8];
	uint8_t		au8DataOutRoundAdd[8];

	uint8_t		u8CoefShift;

	uint8x8_t	vu8x8InputA;
	uint8x8_t	vu8x8InputB;
	uint8x8_t	vu8x8Output;

	uint32_t	u32Idx;

	// initial
	au8DataInA[0] = 0;		au8DataInB[0] = 128;
	au8DataInA[1] = 128;	au8DataInB[1] = 0;
	au8DataInA[2] = 10;		au8DataInB[2] = 10;
	au8DataInA[3] = 50;		au8DataInB[3] = 50;
	au8DataInA[4] = 100;	au8DataInB[4] = 100;
	au8DataInA[5] = 128;	au8DataInB[5] = 128;
	au8DataInA[6] = 255;	au8DataInB[6] = 255;
	au8DataInA[7] = 128;	au8DataInB[7] = 255;

	u8CoefShift		= 3;

	vu8x8InputA		= vld1_u8(au8DataInA);
	vu8x8InputB		= vld1_u8(au8DataInB);

	// uint8x8_t vsra_n_u8(uint8x8_t a, uint8x8_t b, __constrange(1,8) int c);	// VSRA.U8 d0,d0,#8
	// a + (b >> c), (1 ~ 8)
	vu8x8Output		= vsra_n_u8(vu8x8InputA, vu8x8InputB, u8CoefShift);
	vst1_u8(au8DataOutAdd, vu8x8Output);

	// uint8x8_t vrsra_n_u8(uint8x8_t a, uint8x8_t b, __constrange(1,8) int c);	// VRSRA.U8 d0,d0,#8
	// a + ((b + 2^(c-1)) >> c), (1 ~ 8)
	vu8x8Output		= vrsra_n_u8(vu8x8InputA, vu8x8InputB, u8CoefShift);
	vst1_u8(au8DataOutRoundAdd, vu8x8Output);

	printf("== Shift u8 = u8 + (u8 >> u8) (vsra_n_u8 / vrsra_n_u8) ==\n");
	printf("=> vsra_n_u8  : u8 = u8 + (u8 >> u8)                   ==\n");
	printf("=> vrsra_n_u8 : u8 = u8 + ROUND(u8 >> u8)              ==\n");
	for (u32Idx = 0; u32Idx < 8; ++u32Idx)
	{
		printf("%3d + (%3d >> %1d) = %3d, %3d\n",
			au8DataInA[u32Idx],
			au8DataInB[u32Idx], u8CoefShift,
			au8DataOutAdd[u32Idx],
			au8DataOutRoundAdd[u32Idx]);
	}
	printf("========================================\n");
}

// -----------------------------------------------------------------------------
void NeonSample_ShiftConstant_S8_S8_S8_SU8()
{
	int8_t		as8DataInA[8];
	int8_t		as8DataInB[8];
	int8_t		as8DataOutAdd[8];
	int8_t		as8DataOutRoundAdd[8];

	uint8_t		u8CoefShift;

	int8x8_t	vs8x8InputA;
	int8x8_t	vs8x8InputB;
	int8x8_t	vs8x8Output;

	uint32_t	u32Idx;

	// initial
	as8DataInA[0] = 0;		as8DataInB[0] = 128;
	as8DataInA[1] = 128;	as8DataInB[1] = 0;
	as8DataInA[2] = -127;	as8DataInB[2] = -127;
	as8DataInA[3] = -127;	as8DataInB[3] = 128;
	as8DataInA[4] = 100;	as8DataInB[4] = 100;
	as8DataInA[5] = 101;	as8DataInB[5] = -100;
	as8DataInA[6] = 100;	as8DataInB[6] = -101;
	as8DataInA[7] = 128;	as8DataInB[7] = 128;

	u8CoefShift		= 3;

	vs8x8InputA		= vld1_s8(as8DataInA);
	vs8x8InputB		= vld1_s8(as8DataInB);

	// int8x8_t vsra_n_s8(int8x8_t a, int8x8_t b, __constrange(1,8) int c);		// VSRA.S8 d0,d0,#8
	// a + (b >> c), (1 ~ 8)
	vs8x8Output		= vsra_n_s8(vs8x8InputA, vs8x8InputB, u8CoefShift);
	vst1_s8(as8DataOutAdd, vs8x8Output);

	// int8x8_t vrsra_n_s8(int8x8_t a, int8x8_t b, __constrange(1,8) int c);	// VRSRA.S8 d0,d0,#8
	// ROUND(a + (b >> c)), (1 ~ 8)
	vs8x8Output		= vrsra_n_s8(vs8x8InputA, vs8x8InputB, u8CoefShift);
	vst1_s8(as8DataOutRoundAdd, vs8x8Output);

	printf("== Shift s8 = s8 + (s8 >> u8) (vsra_n_s8 / vrsra_n_s8) ==\n");
	printf("=> vsra_n_s8  : s8 = s8 + (s8 >> u8)                   ==\n");
	printf("=> vrsra_n_s8 : s8 = ROUND(s8 + (s8 >> u8))            ==\n");
	for (u32Idx = 0; u32Idx < 8; ++u32Idx)
	{
		printf("%4d + (%4d >> %1d) = %4d, %4d\n",
			as8DataInA[u32Idx],
			as8DataInB[u32Idx], u8CoefShift,
			as8DataOutAdd[u32Idx],
			as8DataOutRoundAdd[u32Idx]);
	}
	printf("========================================\n");
}

// -----------------------------------------------------------------------------
