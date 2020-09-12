#include "neon_sample.h"

// https://developer.arm.com/documentation/dui0472/m/using-neon-support/neon-intrinsics-for-initializing-a-vector-from-a-literal-bit-pattern

// -----------------------------------------------------------------------------
void NeonSample_InitialLiteral_U8_SU64()
{
	uint64_t	u64DataIn;
	uint8_t		au8DataOut[8];

	uint8x8_t	vu8x8Output;

	uint32_t	u32Idx;

	// initial
	u64DataIn = 10;
	u64DataIn = (u64DataIn << 8) + 20;
	u64DataIn = (u64DataIn << 8) + 30;
	u64DataIn = (u64DataIn << 8) + 40;
	u64DataIn = (u64DataIn << 8) + 50;
	u64DataIn = (u64DataIn << 8) + 60;
	u64DataIn = (u64DataIn << 8) + 70;
	u64DataIn = (u64DataIn << 8) + 80;

	// uint8x8_t vcreate_u8(uint64_t a);										// VMOV d0,r0,r0
	vu8x8Output		= vcreate_u8(u64DataIn);
	vst1_u8(au8DataOut, vu8x8Output);

	printf("== Initial From Literal u8 = su64 (vcreate_u8) ==\n");
	printf("Input : %ld\n", u64DataIn);
	printf("Input : "UINT64_TO_BYTE_PATTERN"\n", UINT64_TO_BYTE(u64DataIn));
	printf("Output :\n");
	for (u32Idx = 0; u32Idx < 8; ++u32Idx)
	{
		printf("%1d -> %3d\n",
			u32Idx,
			au8DataOut[u32Idx]);
	}
	printf("========================================\n");
}

// -----------------------------------------------------------------------------
void NeonSample_InitialLiteral_S8_SU64()
{
	uint64_t	u64DataIn;
	int8_t		as8DataOut[8];

	int8x8_t	vs8x8Output;

	uint32_t	u32Idx;

	// initial
	u64DataIn = 10;
	u64DataIn = (u64DataIn << 8) + 20;
	u64DataIn = (u64DataIn << 8) + 30;
	u64DataIn = (u64DataIn << 8) + 40;
	u64DataIn = (u64DataIn << 8) + 120;
	u64DataIn = (u64DataIn << 8) + (uint8_t)(-32);
	u64DataIn = (u64DataIn << 8) + (uint8_t)(-64);
	u64DataIn = (u64DataIn << 8) + (uint8_t)(-127);

	// int8x8_t vcreate_s8(uint64_t a);											// VMOV d0,r0,r0
	vs8x8Output		= vcreate_s8(u64DataIn);
	vst1_s8(as8DataOut, vs8x8Output);

	printf("== Initial From Literal s8 = su64 (vcreate_s8) ==\n");
	printf("Input : %ld\n", u64DataIn);
	printf("Input : "UINT64_TO_BYTE_PATTERN"\n", UINT64_TO_BYTE(u64DataIn));
	printf("Output :\n");
	for (u32Idx = 0; u32Idx < 8; ++u32Idx)
	{
		printf("%1d -> %4d\n",
			u32Idx,
			as8DataOut[u32Idx]);
	}
	printf("========================================\n");
}

// -----------------------------------------------------------------------------
void NeonSample_InitialLiteral_F32_SU64()
{
	float		*pf32Addr = NULL;
	uint64_t	u64DataIn = 0;
	float		af32DataOut[2];

	float32x2_t	vf32x2Output;

	uint32_t	u32Idx;

	// initial
	pf32Addr	= (float *)&u64DataIn;
	*(pf32Addr + 0)		= 10.99;
	*(pf32Addr + 1)		= 245.9976;

	// float32x2_t vcreate_f32(uint64_t a);										// VMOV d0,r0,r0
	vf32x2Output	= vcreate_f32(u64DataIn);
	vst1_f32(af32DataOut, vf32x2Output);

	printf("== Initial From Literal f32 = su64 (vcreate_f32) ==\n");
	printf("Input : %ld\n", u64DataIn);
	printf("Output :\n");
	for (u32Idx = 0; u32Idx < 2; ++u32Idx)
	{
		printf("%1d -> %9.4f\n",
			u32Idx,
			af32DataOut[u32Idx]);
	}
	printf("========================================\n");
}

// -----------------------------------------------------------------------------
void NeonSample_InitialLiteral_P8_SU64()
{
	uint64_t	u64DataIn;
	uint8_t		au8DataOut[8];

	poly8x8_t	vp8x8Output;

	uint32_t	u32Idx;

	// initial
	u64DataIn = 0b00000000;
	u64DataIn = (u64DataIn << 8) + 0b00001111;
	u64DataIn = (u64DataIn << 8) + 0b00111100;
	u64DataIn = (u64DataIn << 8) + 0b11110000;
	u64DataIn = (u64DataIn << 8) + 0b11000011;
	u64DataIn = (u64DataIn << 8) + 0b01010101;
	u64DataIn = (u64DataIn << 8) + 0b10101010;
	u64DataIn = (u64DataIn << 8) + 0b11111111;

	// poly8x8_t vcreate_p8(uint64_t a);										// VMOV d0,r0,r0
	vp8x8Output		= vcreate_p8(u64DataIn);
	vst1_p8(au8DataOut, vp8x8Output);

	printf("== Initial From Literal p8 = su64 (vcreate_p8) ==\n");
	printf("Input : %ld\n", u64DataIn);
	printf("Input : "UINT64_TO_BIT_PATTERN"\n", UINT64_TO_BIT(u64DataIn));
	printf("Output :\n");
	for (u32Idx = 0; u32Idx < 8; ++u32Idx)
	{
		printf("%1d -> "UINT8_TO_BIT_PATTERN"\n",
			u32Idx,
			UINT8_TO_BIT(au8DataOut[u32Idx]));
	}
	printf("========================================\n");
}

// -----------------------------------------------------------------------------
