#include "neon_sample.h"

// https://developer.arm.com/documentation/dui0472/m/using-neon-support/neon-intrinsics-for-comparison

// -----------------------------------------------------------------------------
void NeonSample_Compare_U8_U8_U8()
{
	uint8_t		au8DataInA[8];
	uint8_t		au8DataInB[8];
	uint8_t		au8DataOutEq[8];
	uint8_t		au8DataOutGtOrEq[8];
	uint8_t		au8DataOutLtOrEq[8];
	uint8_t		au8DataOutGt[8];
	uint8_t		au8DataOutLt[8];
	uint8_t		au8DataOutTest[8];

	uint8x8_t	vu8x8InputA;
	uint8x8_t	vu8x8InputB;
	uint8x8_t	vu8x8Output;

	uint32_t	u32Idx;

	// initial
	au8DataInA[0] = 0;		au8DataInB[0] = 0;
	au8DataInA[1] = 100;	au8DataInB[1] = 100;
	au8DataInA[2] = 200;	au8DataInB[2] = 100;
	au8DataInA[3] = 100;	au8DataInB[3] = 200;
	au8DataInA[4] = 0;		au8DataInB[4] = 100;
	au8DataInA[5] = 100;	au8DataInB[5] = 0;
	au8DataInA[6] = 0;		au8DataInB[6] = 0;
	au8DataInA[7] = 0;		au8DataInB[7] = 0;

	vu8x8InputA		= vld1_u8(au8DataInA);
	vu8x8InputB		= vld1_u8(au8DataInB);

	// uint8x8_t vceq_u8(uint8x8_t a, uint8x8_t b);								// VCEQ.I8 d0, d0, d0
	// (a == b)
	vu8x8Output		= vceq_u8(vu8x8InputA, vu8x8InputB);
	vst1_u8(au8DataOutEq, vu8x8Output);

	// uint8x8_t vcge_u8(uint8x8_t a, uint8x8_t b);								// VCGE.U8 d0, d0, d0
	// (a >= b)
	vu8x8Output		= vcge_u8(vu8x8InputA, vu8x8InputB);
	vst1_u8(au8DataOutGtOrEq, vu8x8Output);

	// uint8x8_t vcle_u8(uint8x8_t a, uint8x8_t b);								// VCGE.U8 d0, d0, d0
	// (a <= b)
	vu8x8Output		= vcle_u8(vu8x8InputA, vu8x8InputB);
	vst1_u8(au8DataOutLtOrEq, vu8x8Output);

	// uint8x8_t vcgt_u8(uint8x8_t a, uint8x8_t b);								// VCGT.U8 d0, d0, d0
	// (a > b)
	vu8x8Output		= vcgt_u8(vu8x8InputA, vu8x8InputB);
	vst1_u8(au8DataOutGt, vu8x8Output);

	// uint8x8_t vclt_u8(uint8x8_t a, uint8x8_t b);								// VCGT.U8 d0, d0, d0
	// (a < b)
	vu8x8Output		= vclt_u8(vu8x8InputA, vu8x8InputB);
	vst1_u8(au8DataOutLt, vu8x8Output);

	// uint8x8_t vtst_u8(uint8x8_t a, uint8x8_t b);								// VTST.8 d0, d0, d0
	// test(a, b)
	vu8x8Output		= vtst_u8(vu8x8InputA, vu8x8InputB);
	vst1_u8(au8DataOutTest, vu8x8Output);

	printf("== Compare u8 = u8, u8 (vceq_u8 / vcge_u8 / vcle_u8 / vcgt_u8 / vclt_u8 / vtst_u8) ==\n");
	printf("==                     (==      / >=      / <=      / >       / <       / test   ) ==\n");
	for (u32Idx = 0; u32Idx < 8; ++u32Idx)
	{
		printf("(%3d, %3d) => %3d, %3d, %3d, %3d, %3d, %3d\n",
			au8DataInA[u32Idx], au8DataInB[u32Idx],
			au8DataOutEq[u32Idx],
			au8DataOutGtOrEq[u32Idx],
			au8DataOutLtOrEq[u32Idx],
			au8DataOutGt[u32Idx],
			au8DataOutLt[u32Idx],
			au8DataOutTest[u32Idx]
			);
	}
	printf("========================================\n");
}

// -----------------------------------------------------------------------------
void NeonSample_Compare_U8_S8_S8()
{
	int8_t		as8DataInA[8];
	int8_t		as8DataInB[8];
	uint8_t		au8DataOutEq[8];
	uint8_t		au8DataOutGtOrEq[8];
	uint8_t		au8DataOutLtOrEq[8];
	uint8_t		au8DataOutGt[8];
	uint8_t		au8DataOutLt[8];
	uint8_t		au8DataOutTest[8];

	int8x8_t	vs8x8InputA;
	int8x8_t	vs8x8InputB;
	uint8x8_t	vu8x8Output;

	uint32_t	u32Idx;

	// initial
	as8DataInA[0] = 0;		as8DataInB[0] = 0;
	as8DataInA[1] = 50;		as8DataInB[1] = 100;
	as8DataInA[2] = 100;	as8DataInB[2] = 100;
	as8DataInA[3] = -50;	as8DataInB[3] = -100;
	as8DataInA[4] = -50;	as8DataInB[4] = 100;
	as8DataInA[5] = -50;	as8DataInB[5] = -50;
	as8DataInA[6] = -50;	as8DataInB[6] = -20;
	as8DataInA[7] = -20;	as8DataInB[7] = -50;

	vs8x8InputA		= vld1_s8(as8DataInA);
	vs8x8InputB		= vld1_s8(as8DataInB);

	// uint8x8_t vceq_s8(int8x8_t a, int8x8_t b);								// VCEQ.I8 d0, d0, d0
	// (a == b)
	vu8x8Output		= vceq_s8(vs8x8InputA, vs8x8InputB);
	vst1_u8(au8DataOutEq, vu8x8Output);

	// uint8x8_t vcge_s8(int8x8_t a, int8x8_t b);								// VCGE.S8 d0, d0, d0
	// (a >= b)
	vu8x8Output		= vcge_s8(vs8x8InputA, vs8x8InputB);
	vst1_u8(au8DataOutGtOrEq, vu8x8Output);

	// uint8x8_t vcle_s8(int8x8_t a, int8x8_t b);								// VCGE.S8 d0, d0, d0
	// (a <= b)
	vu8x8Output		= vcle_s8(vs8x8InputA, vs8x8InputB);
	vst1_u8(au8DataOutLtOrEq, vu8x8Output);

	// uint8x8_t vcgt_s8(int8x8_t a, int8x8_t b);								// VCGT.S8 d0, d0, d0
	// (a > b)
	vu8x8Output		= vcgt_s8(vs8x8InputA, vs8x8InputB);
	vst1_u8(au8DataOutGt, vu8x8Output);

	// uint8x8_t vclt_s8(int8x8_t a, int8x8_t b);								// VCGT.S8 d0, d0, d0
	// (a < b)
	vu8x8Output		= vclt_s8(vs8x8InputA, vs8x8InputB);
	vst1_u8(au8DataOutLt, vu8x8Output);

	// uint8x8_t vtst_s8(int8x8_t a, int8x8_t b);								// VTST.8 d0, d0, d0
	// test(a, b)
	vu8x8Output		= vtst_s8(vs8x8InputA, vs8x8InputB);
	vst1_u8(au8DataOutTest, vu8x8Output);

	printf("== Compare u8 = s8, s8 (vceq_s8 / vcge_s8 / vcle_s8 / vcgt_s8 / vclt_s8 / vtst_s8) ==\n");
	printf("==                     (==      / >=      / <=      / >       / <       / test   ) ==\n");
	for (u32Idx = 0; u32Idx < 8; ++u32Idx)
	{
		printf("(%4d, %4d) => %3d, %3d, %3d, %3d, %3d, %3d\n",
			as8DataInA[u32Idx], as8DataInB[u32Idx],
			au8DataOutEq[u32Idx],
			au8DataOutGtOrEq[u32Idx],
			au8DataOutLtOrEq[u32Idx],
			au8DataOutGt[u32Idx],
			au8DataOutLt[u32Idx],
			au8DataOutTest[u32Idx]
			);
	}
	printf("========================================\n");
}

// -----------------------------------------------------------------------------
