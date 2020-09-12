#include "neon_sample.h"

// https://developer.arm.com/documentation/dui0472/m/using-neon-support/neon-intrinsics-for-reversing-vector-elements--swap-endianness-

// -----------------------------------------------------------------------------
void NeonSample_ReverseVectorElements_U8_U8()
{
	uint8_t		au8DataIn[8];
	uint8_t		au8DataOut64[8];
	uint8_t		au8DataOut32[8];
	uint8_t		au8DataOut16[8];

	uint8x8_t	vu8x8Input;
	uint8x8_t	vu8x8Output;

	uint32_t	u32Idx;

	// initial
	au8DataIn[0] = 10;
	au8DataIn[1] = 20;
	au8DataIn[2] = 30;
	au8DataIn[3] = 40;
	au8DataIn[4] = 50;
	au8DataIn[5] = 60;
	au8DataIn[6] = 70;
	au8DataIn[7] = 80;

	vu8x8Input		= vld1_u8(au8DataIn);

	// uint8x8_t vrev64_u8(uint8x8_t vec);										// VREV64.8 d0,d0
	vu8x8Output		= vrev64_u8(vu8x8Input);
	vst1_u8(au8DataOut64, vu8x8Output);

	// uint8x8_t vrev32_u8(uint8x8_t vec);										// VREV32.8 d0,d0
	vu8x8Output		= vrev32_u8(vu8x8Input);
	vst1_u8(au8DataOut32, vu8x8Output);

	// uint8x8_t vrev16_u8(uint8x8_t vec);										// VREV16.8 d0,d0
	vu8x8Output		= vrev16_u8(vu8x8Input);
	vst1_u8(au8DataOut16, vu8x8Output);

	printf("== Reverse Vector u8 = u8 (vrev64_u8 / vrev32_u8 / vrev16_u8) ==\n");
	printf("=> vrev64_u8 : r[i] = a[7 - i]                                ==\n");
	printf("=> vrev32_u8 : r[i] = a[3 - i], i < 4                         ==\n");
	printf("             : r[i] = a[3 - i + 8], i >= 4                    ==\n");
	printf("=> vrev16_u8 : r[i] = a[1 - i], i < 2                         ==\n");
	printf("             : r[i] = a[1 - i + 4], 2 <= i < 4                ==\n");
	printf("             : r[i] = a[1 - i + 8], 4 <= i < 6                ==\n");
	printf("             : r[i] = a[1 - i + 12], 6 <= i < 8               ==\n");
	for (u32Idx = 0; u32Idx < 8; ++u32Idx)
	{
		printf("%3d => %3d, %3d, %3d\n",
			au8DataIn[u32Idx],
			au8DataOut64[u32Idx],
			au8DataOut32[u32Idx],
			au8DataOut16[u32Idx]);
	}
	printf("========================================\n");
}

// -----------------------------------------------------------------------------
void NeonSample_ReverseVectorElements_S8_S8()
{
	int8_t		as8DataIn[8];
	int8_t		as8DataOut64[8];
	int8_t		as8DataOut32[8];
	int8_t		as8DataOut16[8];

	int8x8_t	vs8x8Input;
	int8x8_t	vs8x8Output;

	uint32_t	u32Idx;

	// initial
	as8DataIn[0] = 10;
	as8DataIn[1] = 20;
	as8DataIn[2] = 30;
	as8DataIn[3] = 40;
	as8DataIn[4] = 50;
	as8DataIn[5] = 60;
	as8DataIn[6] = 70;
	as8DataIn[7] = 80;

	vs8x8Input		= vld1_s8(as8DataIn);

	// int8x8_t vrev64_s8(int8x8_t vec);										// VREV64.8 d0,d0
	vs8x8Output		= vrev64_s8(vs8x8Input);
	vst1_s8(as8DataOut64, vs8x8Output);

	// int8x8_t vrev32_s8(int8x8_t vec);										// VREV32.8 d0,d0
	vs8x8Output		= vrev32_s8(vs8x8Input);
	vst1_s8(as8DataOut32, vs8x8Output);

	// int8x8_t vrev16_s8(int8x8_t vec);										// VREV16.8 d0,d0
	vs8x8Output		= vrev16_u8(vs8x8Input);
	vst1_s8(as8DataOut16, vs8x8Output);

	printf("== Reverse Vector s8 = s8 (vrev64_s8 / vrev32_s8 / vrev16_s8) ==\n");
	printf("=> vrev64_s8 : r[i] = a[7 - i]                                ==\n");
	printf("=> vrev32_s8 : r[i] = a[3 - i], i < 4                         ==\n");
	printf("             : r[i] = a[3 - i + 8], i >= 4                    ==\n");
	printf("=> vrev16_s8 : r[i] = a[1 - i], i < 2                         ==\n");
	printf("             : r[i] = a[1 - i + 4], 2 <= i < 4                ==\n");
	printf("             : r[i] = a[1 - i + 8], 4 <= i < 6                ==\n");
	printf("             : r[i] = a[1 - i + 12], 6 <= i < 8               ==\n");
	for (u32Idx = 0; u32Idx < 8; ++u32Idx)
	{
		printf("%4d => %4d, %4d, %4d\n",
			as8DataIn[u32Idx],
			as8DataOut64[u32Idx],
			as8DataOut32[u32Idx],
			as8DataOut16[u32Idx]);
	}
	printf("========================================\n");
}

// -----------------------------------------------------------------------------
void NeonSample_ReverseVectorElements_P8_P8()
{
	uint8_t		au8DataIn[8];
	uint8_t		au8DataOut64[8];
	uint8_t		au8DataOut32[8];
	uint8_t		au8DataOut16[8];

	poly8x8_t	vp8x8Input;
	poly8x8_t	vp8x8Output;

	uint32_t	u32Idx;

	// initial
	au8DataIn[0] = 0b00000001;
	au8DataIn[1] = 0b00000010;
	au8DataIn[2] = 0b00000100;
	au8DataIn[3] = 0b00001000;
	au8DataIn[4] = 0b00010000;
	au8DataIn[5] = 0b00100000;
	au8DataIn[6] = 0b01000000;
	au8DataIn[7] = 0b10000000;

	vp8x8Input		= vld1_p8(au8DataIn);

	// poly8x8_t vrev64_p8(poly8x8_t vec);										// VREV64.8 d0,d0
	vp8x8Output		= vrev64_p8(vp8x8Input);
	vst1_u8(au8DataOut64, vp8x8Output);

	// poly8x8_t vrev32_p8(poly8x8_t vec);										// VREV32.8 d0,d0
	vp8x8Output		= vrev32_p8(vp8x8Input);
	vst1_u8(au8DataOut32, vp8x8Output);

	// poly8x8_t vrev16_p8(poly8x8_t vec);										// VREV16.8 d0,d0
	vp8x8Output		= vrev16_p8(vp8x8Input);
	vst1_u8(au8DataOut16, vp8x8Output);

	printf("== Reverse Vector p8 = p8 (vrev64_p8 / vrev32_p8 / vrev16_p8) ==\n");
	printf("=> vrev64_p8 : r[i] = a[7 - i]                                ==\n");
	printf("=> vrev32_p8 : r[i] = a[3 - i], i < 4                         ==\n");
	printf("             : r[i] = a[3 - i + 8], i >= 4                    ==\n");
	printf("=> vrev16_p8 : r[i] = a[1 - i], i < 2                         ==\n");
	printf("             : r[i] = a[1 - i + 4], 2 <= i < 4                ==\n");
	printf("             : r[i] = a[1 - i + 8], 4 <= i < 6                ==\n");
	printf("             : r[i] = a[1 - i + 12], 6 <= i < 8               ==\n");
	for (u32Idx = 0; u32Idx < 8; ++u32Idx)
	{
		printf(UINT8_TO_BIT_PATTERN" => "UINT8_TO_BIT_PATTERN" "UINT8_TO_BIT_PATTERN" "UINT8_TO_BIT_PATTERN"\n",
			UINT8_TO_BIT(au8DataIn[u32Idx]),
			UINT8_TO_BIT(au8DataOut64[u32Idx]),
			UINT8_TO_BIT(au8DataOut32[u32Idx]),
			UINT8_TO_BIT(au8DataOut16[u32Idx]));
	}
	printf("========================================\n");
}

// -----------------------------------------------------------------------------
void NeonSample_ReverseVectorElements_F32_F32()
{
	float		af32DataIn[2];
	float		af32DataOut[2];

	float32x2_t	vf32x2Input;
	float32x2_t	vf32x2Output;

	uint32_t	u32Idx;

	// initial
	af32DataIn[0] = 10.01;
	af32DataIn[1] = 991.199;

	vf32x2Input		= vld1_f32(af32DataIn);

	// float32x2_t vrev64_f32(float32x2_t vec);									// VREV64.32 d0,d0
	vf32x2Output	= vrev64_f32(vf32x2Input);
	vst1_f32(af32DataOut, vf32x2Output);

	printf("== Reverse Vector f32 = f32 (vrev64_f32) ==\n");
	printf("=> vrev64_f32 : r[i] = a[1 - i]          ==\n");
	for (u32Idx = 0; u32Idx < 2; ++u32Idx)
	{
		printf("%9.4f => %9.4f\n",
			af32DataIn[u32Idx],
			af32DataOut[u32Idx]);
	}
	printf("========================================\n");
}

// -----------------------------------------------------------------------------
