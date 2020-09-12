#include "neon_sample.h"

// https://developer.arm.com/documentation/dui0472/m/using-neon-support/neon-intrinsics-for-loading-a-single-lane-of-a-vector-from-a-literal

// -----------------------------------------------------------------------------
void NeonSample_LoadLaneFromLiteral_U8_SU8_U8_SU8()
{
	uint8_t		au8DataInB[8];
	uint8_t		au8DataOut[8];

	uint8x8_t	vu8x8InputB;
	uint8x8_t	vu8x8Output;

	uint8_t		u8CoefA;
	uint8_t		u8CoefC;

	uint32_t	u32Idx;

	// initial
	au8DataInB[0] = 1;
	au8DataInB[1] = 2;
	au8DataInB[2] = 3;
	au8DataInB[3] = 4;
	au8DataInB[4] = 5;
	au8DataInB[5] = 6;
	au8DataInB[6] = 7;
	au8DataInB[7] = 8;

	u8CoefA		= 100;
	u8CoefC		= 3;

	vu8x8InputB		= vld1_u8(au8DataInB);

	// uint8x8_t vset_lane_u8(uint8_t value, uint8x8_t vec, __constrange(0,7) int lane);	// VMOV.8 d0[0],r0
	// r[:] = b[:], r[c] = a
	vu8x8Output		= vset_lane_u8(u8CoefA, vu8x8InputB, u8CoefC);
	vst1_u8(au8DataOut, vu8x8Output);

	printf("== Load Lane From Literal u8 = su8, u8, su8 (vset_lane_u8) ==\n");
	printf("=> vset_lane_u8 : r[:] = b[:], r[c] = a                    ==\n");

	printf("Replace Index : %1d => %3d\n", u8CoefC, u8CoefA);
	for (u32Idx = 0; u32Idx < 8; ++u32Idx)
	{
		printf("[%1d] %3d => %3d\n",
			u32Idx,
			au8DataInB[u32Idx],
			au8DataOut[u32Idx]);
	}
	printf("========================================\n");
}

// -----------------------------------------------------------------------------
void NeonSample_LoadLaneFromLiteral_S8_SS8_S8_SU8()
{
	int8_t		as8DataInB[8];
	int8_t		as8DataOut[8];

	int8x8_t	vs8x8InputB;
	int8x8_t	vs8x8Output;

	int8_t		s8CoefA;
	uint8_t		u8CoefC;

	uint32_t	u32Idx;

	// initial
	as8DataInB[0] = 10;
	as8DataInB[1] = -10;
	as8DataInB[2] = 20;
	as8DataInB[3] = -20;
	as8DataInB[4] = 30;
	as8DataInB[5] = -30;
	as8DataInB[6] = 40;
	as8DataInB[7] = -40;

	s8CoefA		= -100;
	u8CoefC		= 4;

	vs8x8InputB		= vld1_s8(as8DataInB);

	// int8x8_t vset_lane_s8(int8_t value, int8x8_t vec, __constrange(0,7) int lane);	// VMOV.8 d0[0],r0
	// r[:] = b[:], r[c] = a
	vs8x8Output		= vset_lane_s8(s8CoefA, vs8x8InputB, u8CoefC);
	vst1_s8(as8DataOut, vs8x8Output);

	printf("== Load Lane From Literal s8 = ss8, s8, su8 (vset_lane_s8) ==\n");
	printf("=> vset_lane_s8 : r[:] = b[:], r[c] = a                    ==\n");

	printf("Replace Index : %1d => %4d\n", u8CoefC, s8CoefA);
	for (u32Idx = 0; u32Idx < 8; ++u32Idx)
	{
		printf("[%1d] %4d => %4d\n",
			u32Idx,
			as8DataInB[u32Idx],
			as8DataOut[u32Idx]);
	}
	printf("========================================\n");
}

// -----------------------------------------------------------------------------
void NeonSample_LoadLaneFromLiteral_P8_SP8_P8_SU8()
{
	poly8_t		ap8DataInB[8];
	poly8_t		ap8DataOut[8];

	poly8x8_t	vp8x8InputB;
	poly8x8_t	vp8x8Output;

	poly8_t		p8CoefA;
	uint8_t		u8CoefC;

	uint32_t	u32Idx;

	// initials
	ap8DataInB[0] = 0b00001111;
	ap8DataInB[1] = 0b00111100;
	ap8DataInB[2] = 0b11110000;
	ap8DataInB[3] = 0b11000011;
	ap8DataInB[4] = 0b10101010;
	ap8DataInB[5] = 0b01010101;
	ap8DataInB[6] = 0b00000000;
	ap8DataInB[7] = 0b11111111;

	vp8x8InputB		= vld1_p8(ap8DataInB);
	p8CoefA		= 0b11110000;
	u8CoefC		= 5;

	// poly8x8_t vset_lane_p8(poly8_t value, poly8x8_t vec, __constrange(0,7) int lane);	// VMOV.8 d0[0],r0
	// r[:] = b[:], r[c] = a
	vp8x8Output		= vset_lane_p8(p8CoefA, vp8x8InputB, u8CoefC);
	vst1_p8(ap8DataOut, vp8x8Output);

	printf("== Load Lane From Literal p8 = sp8, p8, su8 (vset_lane_p8) ==\n");
	printf("=> vset_lane_p8 : r[:] = b[:], r[c] = a                    ==\n");

	printf("Replace Index : %1d => "UINT8_TO_BIT_PATTERN"\n", u8CoefC, UINT8_TO_BIT(p8CoefA));
	for (u32Idx = 0; u32Idx < 8; ++u32Idx)
	{
		printf("[%1d] "UINT8_TO_BIT_PATTERN" => "UINT8_TO_BIT_PATTERN"\n",
			u32Idx,
			UINT8_TO_BIT(ap8DataInB[u32Idx]),
			UINT8_TO_BIT(ap8DataOut[u32Idx]));
	}
	printf("========================================\n");
}

// -----------------------------------------------------------------------------
void NeonSample_LoadLaneFromLiteral_F32_SF32_F32_SU8()
{
	float			af32DataInB[2];
	float			af32DataOut[2];

	float32x2_t		vf32x2InputB;
	float32x2_t		vf32x2Output;

	float			f32CoefA;
	uint8_t			u8CoefC;

	uint32_t		u32Idx;

	// initial
	af32DataInB[0] = 99.99;
	af32DataInB[1] = -34.27;

	f32CoefA	= -99.9999;
	u8CoefC		= 0;

	vf32x2InputB	= vld1_f32(af32DataInB);

	// float32x2_t vset_lane_f32(float32_t value, float32x2_t vec, __constrange(0,1) int lane);	// VMOV.32 d0[0],r0
	// r[:] = b[:], r[c] = a
	vf32x2Output	= vset_lane_f32(f32CoefA, vf32x2InputB, u8CoefC);
	vst1_f32(af32DataOut, vf32x2Output);

	printf("== Load Lane From Literal f32 = sf32, f32, su8 (vset_lane_f32) ==\n");
	printf("=> vset_lane_f32 : r[:] = b[:], r[c] = a                       ==\n");

	printf("Replace Index : %1d => %9.4f\n", u8CoefC, f32CoefA);
	for (u32Idx = 0; u32Idx < 2; ++u32Idx)
	{
		printf("[%1d] %9.4f => %9.4f\n",
			u32Idx,
			af32DataInB[u32Idx],
			af32DataOut[u32Idx]);
	}
	printf("========================================\n");
}

// -----------------------------------------------------------------------------
