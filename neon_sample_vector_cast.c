#include "neon_sample.h"

// https://developer.arm.com/documentation/dui0472/m/using-neon-support/neon-intrinsics-for-vector-cast-operations

// -----------------------------------------------------------------------------
void NeonSample_VectorCast_U8_S8()
{
	int8_t		as8DataIn[8];
	uint8_t		au8DataOut[8];

	int8x8_t	vs8x8Input;
	uint8x8_t	vu8x8Output;

	uint32_t	u32Idx;

	// initial
	as8DataIn[0] = -128;
	as8DataIn[1] = -100;
	as8DataIn[2] = -50;
	as8DataIn[3] = -30;
	as8DataIn[4] = 30;
	as8DataIn[5] = 50;
	as8DataIn[6] = 100;
	as8DataIn[7] = 127;

	vs8x8Input		= vld1_s8(as8DataIn);

	// uint8x8_t vreinterpret_u8_s8(int8x8_t __a);
	vu8x8Output		= vreinterpret_u8_s8(vs8x8Input);
	vst1_u8(au8DataOut, vu8x8Output);

	printf("== Vector Cast u8 = (UINT)s8 (vreinterpret_u8_s8) ==\n");
	for (u32Idx = 0; u32Idx < 8; ++u32Idx)
	{
		printf("%4d => %3d\n",
			as8DataIn[u32Idx],
			au8DataOut[u32Idx]);
		printf("\t"UINT8_TO_BIT_PATTERN" => "UINT8_TO_BIT_PATTERN"\n",
			UINT8_TO_BIT(as8DataIn[u32Idx]),
			UINT8_TO_BIT(au8DataOut[u32Idx]));
	}
	printf("========================================\n");
}

// -----------------------------------------------------------------------------
void NeonSample_VectorCast_U8_S16()
{
	int16_t		as16DataIn[4];
	uint8_t		au8DataOut[8];

	int16x4_t	vs16x4Input;
	uint8x8_t	vu8x8Output;

	uint32_t	u32Idx, u32Idx2;

	// initial
	as16DataIn[0] = 100 << 8 | 100;
	as16DataIn[1] = 200 << 8 | 200;
	as16DataIn[2] = 10 << 8 | 100;
	as16DataIn[3] = 20 << 8 | 200;

	vs16x4Input	= vld1_s16(as16DataIn);

	// uint8x8_t vreinterpret_u8_s16(int16x4_t __a);
	vu8x8Output		= vreinterpret_u8_s16(vs16x4Input);
	vst1_u8(au8DataOut, vu8x8Output);

	printf("== Vector Cast u8 = (UINT)s16 (vreinterpret_u8_s16) ==\n");
	for (u32Idx = 0, u32Idx2 = 0; u32Idx < 4; ++u32Idx, u32Idx2+=2)
	{
		printf("%6d => %3d, %3d\n",
			as16DataIn[u32Idx],
			au8DataOut[u32Idx2 + 1], au8DataOut[u32Idx2]);
		printf("\t"UINT16_TO_BIT_PATTERN" => "UINT8_TO_BIT_PATTERN", "UINT8_TO_BIT_PATTERN"\n",
			UINT16_TO_BIT(as16DataIn[u32Idx]),
			UINT8_TO_BIT(au8DataOut[u32Idx2 + 1]), UINT8_TO_BIT(au8DataOut[u32Idx2]));
	}
	printf("========================================\n");
}

// -----------------------------------------------------------------------------
void NeonSample_VectorCast_U8_U16()
{
	uint16_t	au16DataIn[4];
	uint8_t		au8DataOut[8];

	uint16x4_t	vu16x4Input;
	uint8x8_t	vu8x8Output;

	uint32_t	u32Idx, u32Idx2;

	// initial
	au16DataIn[0] = 100 << 8 | 100;
	au16DataIn[1] = 200 << 8 | 200;
	au16DataIn[2] = 10 << 8 | 100;
	au16DataIn[3] = 20 << 8 | 200;

	vu16x4Input		= vld1_u16(au16DataIn);

	// uint8x8_t vreinterpret_u8_u16(uint16x4_t __a);
	vu8x8Output		= vreinterpret_u8_u16(vu16x4Input);
	vst1_u8(au8DataOut, vu8x8Output);

	printf("== Vector Cast u8 = u16 (vreinterpret_u8_u16) ==\n");
	for (u32Idx = 0, u32Idx2 = 0; u32Idx < 4; ++u32Idx, u32Idx2+=2)
	{
		printf("%5d => %3d, %3d\n",
			au16DataIn[u32Idx],
			au8DataOut[u32Idx2 + 1], au8DataOut[u32Idx2]);
		printf("\t"UINT16_TO_BIT_PATTERN" => "UINT8_TO_BIT_PATTERN", "UINT8_TO_BIT_PATTERN"\n",
			UINT16_TO_BIT(au16DataIn[u32Idx]),
			UINT8_TO_BIT(au8DataOut[u32Idx2 + 1]), UINT8_TO_BIT(au8DataOut[u32Idx2]));
	}
	printf("========================================\n");
}

// -----------------------------------------------------------------------------
void NeonSample_VectorCast_U8_F32()
{
	// uint8x8_t vreinterpret_u8_f32(float32x2_t __a);
}

// -----------------------------------------------------------------------------
void NeonSample_VectorCast_U8_P8()
{
	poly8_t		ap8DataIn[8];
	uint8_t		au8DataOut[8];

	poly8x8_t	vp8x8Input;
	uint8x8_t	vu8x8Output;

	uint32_t	u32Idx;

	// initial
	ap8DataIn[0] = 0b11110000;
	ap8DataIn[1] = 0b00001111;
	ap8DataIn[2] = 0b11001100;
	ap8DataIn[3] = 0b00110011;
	ap8DataIn[4] = 0b10101010;
	ap8DataIn[5] = 0b01010101;
	ap8DataIn[6] = 0b11111111;
	ap8DataIn[7] = 0b00000000;

	vp8x8Input		= vld1_p8(ap8DataIn);

	// uint8x8_t vreinterpret_u8_p8(poly8x8_t __a);
	vu8x8Output		= vreinterpret_u8_p8(vp8x8Input);
	vst1_u8(au8DataOut, vu8x8Output);

	printf("== Vector Cast u8 = p8 (vreinterpret_u8_p8) ==\n");
	for (u32Idx = 0; u32Idx < 8; ++u32Idx)
	{
		printf("%4d => %3d\n",
			ap8DataIn[u32Idx],
			au8DataOut[u32Idx]);
		printf("\t"UINT8_TO_BIT_PATTERN" => "UINT8_TO_BIT_PATTERN"\n",
			UINT8_TO_BIT(ap8DataIn[u32Idx]),
			UINT8_TO_BIT(au8DataOut[u32Idx]));
	}
	printf("========================================\n");
}

// -----------------------------------------------------------------------------
void NeonSample_VectorCast_U8_P16()
{
	poly16_t	ap16DataIn[4];
	uint8_t		au8DataOut[8];

	poly16x4_t	vp16x4Input;
	uint8x8_t	vu8x8Output;

	uint32_t	u32Idx, u32Idx2;

	// initial
	ap16DataIn[0] = 0b1111111100000000;
	ap16DataIn[1] = 0b1100110011001100;
	ap16DataIn[2] = 0b1010101001010101;
	ap16DataIn[3] = 0b1110001110001100;

	vp16x4Input		= vld1_p16(ap16DataIn);

	// uint8x8_t vreinterpret_u8_p16(poly16x4_t __a);
	vu8x8Output		= vreinterpret_u8_p16(vp16x4Input);
	vst1_u8(au8DataOut, vu8x8Output);

	printf("== Vector Cast u8 = p16 (vreinterpret_u8_p16) ==\n");
	for (u32Idx = 0, u32Idx2 = 0; u32Idx < 4; ++u32Idx, u32Idx2+=2)
	{
		printf("%5d => %3d, %3d\n",
			ap16DataIn[u32Idx],
			au8DataOut[u32Idx2 + 1], au8DataOut[u32Idx2]);
		printf("\t"UINT16_TO_BIT_PATTERN" => "UINT8_TO_BIT_PATTERN", "UINT8_TO_BIT_PATTERN"\n",
			UINT16_TO_BIT(ap16DataIn[u32Idx]),
			UINT8_TO_BIT(au8DataOut[u32Idx2 + 1]), UINT8_TO_BIT(au8DataOut[u32Idx2]));
	}
	printf("========================================\n");
}

// -----------------------------------------------------------------------------
void NeonSample_VectorCast_U16_S8()
{
	int8_t		as8DataIn[8];
	uint16_t	au16DataOut[4];

	int8x8_t	vs8x8Input;
	uint16x4_t	vu16x4Output;

	uint32_t	u32Idx, u32Idx2;

	// initial
	as8DataIn[0] = -128;
	as8DataIn[1] = -100;
	as8DataIn[2] = -50;
	as8DataIn[3] = -30;
	as8DataIn[4] = 30;
	as8DataIn[5] = 50;
	as8DataIn[6] = 100;
	as8DataIn[7] = 127;

	vs8x8Input		= vld1_s8(as8DataIn);

	// uint16x4_t vreinterpret_u16_s8(int8x8_t __a);
	vu16x4Output	= vreinterpret_u16_s8(vs8x8Input);
	vst1_u16(au16DataOut, vu16x4Output);

	printf("== Vector Cast u16 = (UINT)s8 (vreinterpret_u16_s8) ==\n");
	for (u32Idx = 0, u32Idx2 = 0; u32Idx < 4; ++u32Idx, u32Idx2+=2)
	{
		printf("%4d, %4d => %5d\n",
			as8DataIn[u32Idx2 + 1], as8DataIn[u32Idx2],
			au16DataOut[u32Idx]);
		printf("\t"UINT8_TO_BIT_PATTERN", "UINT8_TO_BIT_PATTERN" => "UINT16_TO_BIT_PATTERN"\n",
			UINT8_TO_BIT(as8DataIn[u32Idx2 + 1]), UINT8_TO_BIT(as8DataIn[u32Idx2]),
			UINT16_TO_BIT(au16DataOut[u32Idx]));
	}
	printf("========================================\n");
}

// -----------------------------------------------------------------------------
void NeonSample_VectorCast_U16_S16()
{
	int16_t		as16DataIn[4];
	uint16_t	au16DataOut[4];

	int16x4_t	vs16x4Input;
	uint16x4_t	vu16x4Output;

	uint32_t	u32Idx;

	// initial
	as16DataIn[0] = -100;
	as16DataIn[1] = -10000;
	as16DataIn[2] = 10000;
	as16DataIn[3] = 100;

	vs16x4Input		= vld1_s16(as16DataIn);

	// uint16x4_t vreinterpret_u16_s16(int16x4_t __a);
	vu16x4Output	= vreinterpret_u16_s16(vs16x4Input);
	vst1_u16(au16DataOut, vu16x4Output);

	printf("== Vector Cast u16 = (UINT)s16 (vreinterpret_u16_s16) ==\n");
	for (u32Idx = 0; u32Idx < 4; ++u32Idx)
	{
		printf("%6d => %5d\n",
			as16DataIn[u32Idx],
			au16DataOut[u32Idx]);
		printf("\t"UINT16_TO_BIT_PATTERN" => "UINT16_TO_BIT_PATTERN"\n",
			UINT16_TO_BIT(as16DataIn[u32Idx]),
			UINT16_TO_BIT(au16DataOut[u32Idx]));
	}
	printf("========================================\n");
}

// -----------------------------------------------------------------------------
void NeonSample_VectorCast_U16_U8()
{
	uint8_t		au8DataIn[8];
	uint16_t	au16DataOut[4];

	uint8x8_t	vu8x8Input;
	uint16x4_t	vu16x4Output;

	uint32_t	u32Idx, u32Idx2;

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

	// uint16x4_t vreinterpret_u16_u8(uint8x8_t __a);
	vu16x4Output	= vreinterpret_u16_u8(vu8x8Input);
	vst1_u16(au16DataOut, vu16x4Output);

	printf("== Vector Cast u16 = u8 (vreinterpret_u16_u8) ==\n");
	for (u32Idx = 0, u32Idx2 = 0; u32Idx < 4; ++u32Idx, u32Idx2+=2)
	{
		printf("%3d, %3d => %5d\n",
			au8DataIn[u32Idx2 + 1], au8DataIn[u32Idx2],
			au16DataOut[u32Idx]);
		printf("\t"UINT8_TO_BIT_PATTERN", "UINT8_TO_BIT_PATTERN" => "UINT16_TO_BIT_PATTERN"\n",
			UINT8_TO_BIT(au8DataIn[u32Idx2 + 1]), UINT8_TO_BIT(au8DataIn[u32Idx2]),
			UINT16_TO_BIT(au16DataOut[u32Idx]));
	}
	printf("========================================\n");
}

// -----------------------------------------------------------------------------
void NeonSample_VectorCast_U16_F32()
{
	// uint16x4_t vreinterpret_u16_f32(float32x2_t __a);
}

// -----------------------------------------------------------------------------
void NeonSample_VectorCast_U16_P8()
{
	poly8_t		ap8DataIn[8];
	uint16_t	au16DataOut[4];

	poly8x8_t	vp8x8Input;
	uint16x4_t	vu16x4Output;

	uint32_t	u32Idx, u32Idx2;

	// initial
	ap8DataIn[0] = 0b00000011;
	ap8DataIn[1] = 0b00001100;
	ap8DataIn[2] = 0b00110000;
	ap8DataIn[3] = 0b11000000;
	ap8DataIn[4] = 0b00001111;
	ap8DataIn[5] = 0b00111100;
	ap8DataIn[6] = 0b11110000;
	ap8DataIn[7] = 0b11111111;

	vp8x8Input		= vld1_p8(ap8DataIn);

	// uint16x4_t vreinterpret_u16_p8(poly8x8_t __a);
	vu16x4Output	= vreinterpret_u16_p8(vp8x8Input);
	vst1_u16(au16DataOut, vu16x4Output);

	printf("== Vector Cast u16 = p8 (vreinterpret_u16_p8) ==\n");
	for (u32Idx = 0, u32Idx2 = 0; u32Idx < 4; ++u32Idx, u32Idx2+=2)
	{
		printf("%4d, %4d => %5d\n",
			ap8DataIn[u32Idx2 + 1], ap8DataIn[u32Idx2],
			au16DataOut[u32Idx]);
		printf("\t"UINT8_TO_BIT_PATTERN", "UINT8_TO_BIT_PATTERN" => "UINT16_TO_BIT_PATTERN"\n",
			UINT8_TO_BIT(ap8DataIn[u32Idx2 + 1]), UINT8_TO_BIT(ap8DataIn[u32Idx2]),
			UINT16_TO_BIT(au16DataOut[u32Idx]));
	}
	printf("========================================\n");
}

// -----------------------------------------------------------------------------
void NeonSample_VectorCast_U16_P16()
{
	poly16_t	ap16DataIn[4];
	uint16_t	au16DataOut[4];

	poly16x4_t	vp16x4Input;
	uint16x4_t	vu16x4Output;

	uint32_t	u32Idx;

	// initial
	ap16DataIn[0] = 0b0000001111000000;
	ap16DataIn[1] = 0b0000110000110000;
	ap16DataIn[2] = 0b0011000000001100;
	ap16DataIn[3] = 0b1100000000000011;

	vp16x4Input		= vld1_p16(ap16DataIn);

	// uint16x4_t vreinterpret_u16_p16(poly16x4_t __a);
	vu16x4Output	= vreinterpret_u16_p16(vp16x4Input);
	vst1_u16(au16DataOut, vu16x4Output);

	printf("== Vector Cast u16 = p16 (vreinterpret_u16_p16) ==\n");
	for (u32Idx = 0; u32Idx < 4; ++u32Idx)
	{
		printf("%5d => %5d\n",
			ap16DataIn[u32Idx],
			au16DataOut[u32Idx]);
		printf("\t"UINT16_TO_BIT_PATTERN" => "UINT16_TO_BIT_PATTERN"\n",
			UINT16_TO_BIT(ap16DataIn[u32Idx]),
			UINT16_TO_BIT(au16DataOut[u32Idx]));
	}
	printf("========================================\n");
}

// -----------------------------------------------------------------------------
void NeonSample_VectorCast_S8_S16()
{
	int16_t		as16DataIn[4];
	int8_t		as8DataOut[8];

	int16x4_t	vs16x4Input;
	int8x8_t	vs8x8Output;

	uint32_t	u32Idx, u32Idx2;

	// initial
	as16DataIn[0] = 20000;
	as16DataIn[1] = 100;
	as16DataIn[2] = -100;
	as16DataIn[3] = -20000;

	vs16x4Input		= vld1_s16(as16DataIn);

	// int8x8_t vreinterpret_s8_s16(int16x4_t __a);
	vs8x8Output		= vreinterpret_s8_s16(vs16x4Input);
	vst1_s8(as8DataOut, vs8x8Output);

	printf("== Vector Cast s8 = s16 (vreinterpret_s8_s16) ==\n");
	for (u32Idx = 0, u32Idx2 = 0; u32Idx < 4; ++u32Idx, u32Idx2+=2)
	{
		printf("%11d => %4d, %4d\n",
			as16DataIn[u32Idx],
			as8DataOut[u32Idx2 + 1], as8DataOut[u32Idx2]);
		printf("\t"UINT16_TO_BIT_PATTERN" => "UINT8_TO_BIT_PATTERN", "UINT8_TO_BIT_PATTERN"\n",
			UINT16_TO_BIT(as16DataIn[u32Idx]),
			UINT8_TO_BIT(as8DataOut[u32Idx2 + 1]), UINT8_TO_BIT(as8DataOut[u32Idx2]));
	}
	printf("========================================\n");
}

// -----------------------------------------------------------------------------
void NeonSample_VectorCast_S8_F32()
{
	// int8x8_t vreinterpret_s8_f32(float32x2_t __a);
}

// -----------------------------------------------------------------------------
void NeonSample_VectorCast_S8_U8()
{
	uint8_t		au8DataIn[8];
	int8_t		as8DataOut[8];

	uint8x8_t	vu8x8Input;
	int8x8_t	vs8x8Output;

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

	// int8x8_t vreinterpret_s8_u8(uint8x8_t __a);
	vs8x8Output		= vreinterpret_s8_u8(vu8x8Input);
	vst1_s8(as8DataOut, vs8x8Output);

	printf("== Vector Cast s8 = u8 (vreinterpret_s8_u8) ==\n");
	for (u32Idx = 0; u32Idx < 8; ++u32Idx)
	{
		printf("%3d => %4d\n",
			au8DataIn[u32Idx],
			as8DataOut[u32Idx]);
		printf("\t"UINT8_TO_BIT_PATTERN" => "UINT8_TO_BIT_PATTERN"\n",
			UINT8_TO_BIT(au8DataIn[u32Idx]),
			UINT8_TO_BIT(as8DataOut[u32Idx]));
	}
	printf("========================================\n");
}

// -----------------------------------------------------------------------------
void NeonSample_VectorCast_S8_U16()
{
	uint16_t	au16DataIn[4];
	int8_t		as8DataOut[8];

	uint16x4_t	vu16x4Input;
	int8x8_t	vs8x8Output;

	uint32_t	u32Idx, u32Idx2;

	// initial
	au16DataIn[0] = 1024;
	au16DataIn[1] = 32767;
	au16DataIn[2] = 32768;
	au16DataIn[3] = 65535;

	vu16x4Input		= vld1_u16(au16DataIn);

	// int8x8_t vreinterpret_s8_u16(uint16x4_t __a);
	vs8x8Output		= vreinterpret_s8_u16(vu16x4Input);
	vst1_s8(as8DataOut, vs8x8Output);

	printf("== Vector Cast s8 = u16 (vreinterpret_s8_u16) ==\n");
	for (u32Idx = 0, u32Idx2 = 0; u32Idx < 4; ++u32Idx, u32Idx2+=2)
	{
		printf("%5d => %4d, %4d\n",
			au16DataIn[u32Idx],
			as8DataOut[u32Idx2 + 1], as8DataOut[u32Idx2]);
		printf("\t"UINT16_TO_BIT_PATTERN" => "UINT8_TO_BIT_PATTERN", "UINT8_TO_BIT_PATTERN"\n",
			UINT16_TO_BIT(au16DataIn[u32Idx]),
			UINT8_TO_BIT(as8DataOut[u32Idx2 + 1]), UINT8_TO_BIT(as8DataOut[u32Idx2]));
	}
	printf("========================================\n");
}

// -----------------------------------------------------------------------------
void NeonSample_VectorCast_S8_P8()
{
	poly8_t		ap8DataIn[8];
	int8_t		as8DataOut[8];

	poly8x8_t	vp8x8Input;
	int8x8_t	vs8x8Output;

	uint32_t	u32Idx;

	// initial
	ap8DataIn[0] = 0b00000011;
	ap8DataIn[1] = 0b00001100;
	ap8DataIn[2] = 0b00110000;
	ap8DataIn[3] = 0b11000000;
	ap8DataIn[4] = 0b00001111;
	ap8DataIn[5] = 0b00111100;
	ap8DataIn[6] = 0b11110000;
	ap8DataIn[7] = 0b11111111;

	vp8x8Input		= vld1_p8(ap8DataIn);

	// int8x8_t vreinterpret_s8_p8(poly8x8_t __a);
	vs8x8Output		= vreinterpret_s8_p8(vp8x8Input);
	vst1_s8(as8DataOut, vs8x8Output);

	printf("== Vector Cast s8 = p8 (vreinterpret_s8_p8) ==\n");
	for (u32Idx = 0; u32Idx < 8; ++u32Idx)
	{
		printf("%3d => %4d\n",
			ap8DataIn[u32Idx],
			as8DataOut[u32Idx]);
		printf("\t"UINT8_TO_BIT_PATTERN" => "UINT8_TO_BIT_PATTERN"\n",
			UINT8_TO_BIT(ap8DataIn[u32Idx]),
			UINT8_TO_BIT(as8DataOut[u32Idx]));
	}
	printf("========================================\n");
}

// -----------------------------------------------------------------------------
void NeonSample_VectorCast_S8_P16()
{
	poly16_t	ap16DataIn[4];
	int8_t		as8DataOut[8];

	poly16x4_t	vp16x4Input;
	int8x8_t	vs8x8Output;

	uint32_t	u32Idx, u32Idx2;

	// initial
	ap16DataIn[0] = 0b1111111100000000;
	ap16DataIn[1] = 0b1100110011001100;
	ap16DataIn[2] = 0b1010101001010101;
	ap16DataIn[3] = 0b1110001110001100;

	vp16x4Input		= vld1_p16(ap16DataIn);

	// int8x8_t vreinterpret_s8_p16(poly16x4_t __a);
	vs8x8Output		= vreinterpret_s8_p16(vp16x4Input);
	vst1_s8(as8DataOut, vs8x8Output);

	printf("== Vector Cast s8 = p16 (vreinterpret_s8_p16) ==\n");
	for (u32Idx = 0, u32Idx2 = 0; u32Idx < 4; ++u32Idx, u32Idx2+=2)
	{
		printf("%5d => %4d, %4d\n",
			ap16DataIn[u32Idx],
			as8DataOut[u32Idx2 + 1], as8DataOut[u32Idx2]);
		printf("\t"UINT16_TO_BIT_PATTERN" => "UINT8_TO_BIT_PATTERN", "UINT8_TO_BIT_PATTERN"\n",
			UINT16_TO_BIT(ap16DataIn[u32Idx]),
			UINT8_TO_BIT(as8DataOut[u32Idx2 + 1]), UINT8_TO_BIT(as8DataOut[u32Idx2]));
	}
	printf("========================================\n");
}

// -----------------------------------------------------------------------------
void NeonSample_VectorCast_S16_S8()
{
	int8_t		as8DataIn[8];
	int16_t		as16DataOut[4];

	int8x8_t	vs8x8Input;
	int16x4_t	vs16x4Output;

	uint32_t	u32Idx, u32Idx2;

	// initial
	as8DataIn[0] = -128;
	as8DataIn[1] = -127;
	as8DataIn[2] = -32;
	as8DataIn[3] = 0;
	as8DataIn[4] = 50;
	as8DataIn[5] = 100;
	as8DataIn[6] = 126;
	as8DataIn[7] = 127;

	vs8x8Input		= vld1_s8(as8DataIn);

	// int16x4_t vreinterpret_s16_s8(int8x8_t __a);
	vs16x4Output	= vreinterpret_s16_s8(vs8x8Input);
	vst1_s16(as16DataOut, vs16x4Output);

	printf("== Vector Cast s16 = s8 (vreinterpret_s16_s8) ==\n");
	for (u32Idx = 0, u32Idx2 = 0; u32Idx < 4; ++u32Idx, u32Idx2+=2)
	{
		printf("%4d, %4d => %6d\n",
			as8DataIn[u32Idx2 + 1], as8DataIn[u32Idx2],
			as16DataOut[u32Idx]);
		printf("\t"UINT8_TO_BIT_PATTERN", "UINT8_TO_BIT_PATTERN" => "UINT16_TO_BIT_PATTERN"\n",
			UINT8_TO_BIT(as8DataIn[u32Idx2 + 1]), UINT8_TO_BIT(as8DataIn[u32Idx2]),
			UINT16_TO_BIT(as16DataOut[u32Idx]));
	}
	printf("========================================\n");
}

// -----------------------------------------------------------------------------
void NeonSample_VectorCast_S16_F32()
{
	// int16x4_t vreinterpret_s16_f32(float32x2_t __a);
}

// -----------------------------------------------------------------------------
void NeonSample_VectorCast_S16_U8()
{
	uint8_t		au8DataIn[8];
	int16_t		as16DataOut[4];

	uint8x8_t	vu8x8Input;
	int16x4_t	vs16x4Output;

	uint32_t	u32Idx, u32Idx2;

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

	// int16x4_t vreinterpret_s16_u8(uint8x8_t __a);
	vs16x4Output	= vreinterpret_s16_u8(vu8x8Input);
	vst1_s16(as16DataOut, vs16x4Output);

	printf("== Vector Cast s16 = (INT)u8 (vreinterpret_s16_u8) ==\n");
	for (u32Idx = 0, u32Idx2 = 0; u32Idx < 4; ++u32Idx, u32Idx2+=2)
	{
		printf("%3d, %3d => %6d\n",
			au8DataIn[u32Idx2 + 1], au8DataIn[u32Idx2],
			as16DataOut[u32Idx]);
		printf("\t"UINT8_TO_BIT_PATTERN", "UINT8_TO_BIT_PATTERN" => "UINT16_TO_BIT_PATTERN"\n",
			UINT8_TO_BIT(au8DataIn[u32Idx2 + 1]), UINT8_TO_BIT(au8DataIn[u32Idx2]),
			UINT16_TO_BIT(as16DataOut[u32Idx]));
	}
	printf("========================================\n");
}

// -----------------------------------------------------------------------------
void NeonSample_VectorCast_S16_U16()
{
	uint16_t	au16DataIn[4];
	int16_t		as16DataOut[4];

	uint16x4_t	vu16x4Input;
	int16x4_t	vs16x4Output;

	uint32_t	u32Idx;

	// initial
	au16DataIn[0] = 512;
	au16DataIn[1] = 32767;
	au16DataIn[2] = 32768;
	au16DataIn[3] = 65535;

	vu16x4Input		= vld1_u16(au16DataIn);

	// int16x4_t vreinterpret_s16_u16(uint16x4_t __a);
	vs16x4Output	= vreinterpret_s16_u16(vu16x4Input);
	vst1_s16(as16DataOut, vs16x4Output);

	printf("== Vector Cast s16 = (INT)u16 (vreinterpret_s16_u16) ==\n");
	for (u32Idx = 0; u32Idx < 4; ++u32Idx)
	{
		printf("%5d => %6d\n",
			au16DataIn[u32Idx],
			as16DataOut[u32Idx]);
		printf("\t"UINT16_TO_BIT_PATTERN" => "UINT16_TO_BIT_PATTERN"\n",
			UINT16_TO_BIT(au16DataIn[u32Idx]),
			UINT16_TO_BIT(as16DataOut[u32Idx]));
	}
	printf("========================================\n");
}

// -----------------------------------------------------------------------------
void NeonSample_VectorCast_S16_P8()
{
	poly8_t		ap8DataIn[8];
	int16_t		as16DataOut[4];

	poly8x8_t	vp8x8Input;
	int16x4_t	vs16x4Output;

	uint32_t	u32Idx, u32Idx2;

	// initial
	ap8DataIn[0] = 0b00000011;
	ap8DataIn[1] = 0b00001100;
	ap8DataIn[2] = 0b00110000;
	ap8DataIn[3] = 0b11000000;
	ap8DataIn[4] = 0b00001111;
	ap8DataIn[5] = 0b00111100;
	ap8DataIn[6] = 0b11110000;
	ap8DataIn[7] = 0b11111111;

	vp8x8Input		= vld1_p8(ap8DataIn);

	// int16x4_t vreinterpret_s16_p8(poly8x8_t __a);
	vs16x4Output	= vreinterpret_s16_p8(vp8x8Input);
	vst1_s16(as16DataOut, vs16x4Output);

	printf("== Vector Cast s16 = p8 (vreinterpret_s16_p8) ==\n");
	for (u32Idx = 0, u32Idx2 = 0; u32Idx < 4; ++u32Idx, u32Idx2+=2)
	{
		printf("%3d, %3d => %6d\n",
			ap8DataIn[u32Idx2 + 1], ap8DataIn[u32Idx2],
			as16DataOut[u32Idx]);
		printf("\t"UINT8_TO_BIT_PATTERN", "UINT8_TO_BIT_PATTERN" => "UINT16_TO_BIT_PATTERN"\n",
			UINT8_TO_BIT(ap8DataIn[u32Idx2 + 1]), UINT8_TO_BIT(ap8DataIn[u32Idx2]),
			UINT16_TO_BIT(as16DataOut[u32Idx]));
	}
	printf("========================================\n");
}

// -----------------------------------------------------------------------------
void NeonSample_VectorCast_S16_P16()
{
	poly16_t	ap16DataIn[4];
	int16_t		as16DataOut[4];

	poly16x4_t	vp16x4Input;
	int16x4_t	vs16x4Output;

	uint32_t	u32Idx;

	// initial
	ap16DataIn[0] = 0b1111111100000000;
	ap16DataIn[1] = 0b1100110011001100;
	ap16DataIn[2] = 0b1010101001010101;
	ap16DataIn[3] = 0b1110001110001100;

	vp16x4Input		= vld1_p16(ap16DataIn);

	// int16x4_t vreinterpret_s16_p16(poly16x4_t __a);
	vs16x4Output	= vreinterpret_s16_p16(vp16x4Input);
	vst1_s16(as16DataOut, vs16x4Output);

	printf("== Vector Cast s16 = p16 (vreinterpret_s16_p16) ==\n");
	for (u32Idx = 0; u32Idx < 4; ++u32Idx)
	{
		printf("%5d => %6d\n",
			ap16DataIn[u32Idx],
			as16DataOut[u32Idx]);
		printf("\t"UINT16_TO_BIT_PATTERN" => "UINT16_TO_BIT_PATTERN"\n",
			UINT16_TO_BIT(ap16DataIn[u32Idx]),
			UINT16_TO_BIT(as16DataOut[u32Idx]));
	}
	printf("========================================\n");
}

// -----------------------------------------------------------------------------
void NeonSample_VectorCast_F32_S8()
{
	// float32x2_t vreinterpret_f32_s8(int8x8_t __a);
}

// -----------------------------------------------------------------------------
void NeonSample_VectorCast_F32_S16()
{
	// float32x2_t vreinterpret_f32_s16(int16x4_t __a);
}

// -----------------------------------------------------------------------------
void NeonSample_VectorCast_F32_U8()
{
	// float32x2_t vreinterpret_f32_u8(uint8x8_t __a);
}

// -----------------------------------------------------------------------------
void NeonSample_VectorCast_F32_U16()
{
	// float32x2_t vreinterpret_f32_u16(uint16x4_t __a);
}

// -----------------------------------------------------------------------------
void NeonSample_VectorCast_F32_P8()
{
	// float32x2_t vreinterpret_f32_p8(poly8x8_t __a);
}

// -----------------------------------------------------------------------------
void NeonSample_VectorCast_F32_P16()
{
	// float32x2_t vreinterpret_f32_p16(poly16x4_t __a);
}

// -----------------------------------------------------------------------------
void NeonSample_VectorCast_P8_S8()
{
	int8_t		as8DataIn[8];
	poly8_t		ap8DataOut[8];

	int8x8_t	vs8x8Input;
	poly8x8_t	vp8x8Output;

	uint32_t	u32Idx;

	// initial
	as8DataIn[0] = -128;
	as8DataIn[1] = -100;
	as8DataIn[2] = -50;
	as8DataIn[3] = -30;
	as8DataIn[4] = 30;
	as8DataIn[5] = 50;
	as8DataIn[6] = 100;
	as8DataIn[7] = 127;

	vs8x8Input		= vld1_s8(as8DataIn);

	// poly8x8_t vreinterpret_p8_s8(int8x8_t __a);
	vp8x8Output		= vreinterpret_p8_s8(vs8x8Input);
	vst1_p8(ap8DataOut, vp8x8Output);

	printf("== Vector Cast p8 = s8 (vreinterpret_p8_s8) ==\n");
	for (u32Idx = 0; u32Idx < 8; ++u32Idx)
	{
		printf("%4d, "UINT8_TO_BIT_PATTERN" => "UINT8_TO_BIT_PATTERN"\n",
			as8DataIn[u32Idx], UINT8_TO_BIT(as8DataIn[u32Idx]),
			UINT8_TO_BIT(ap8DataOut[u32Idx]));
	}
	printf("========================================\n");
}

// -----------------------------------------------------------------------------
void NeonSample_VectorCast_P8_S16()
{
	int16_t		as16DataIn[4];
	poly8_t		ap8DataOut[8];

	int16x4_t	vs16x4Input;
	poly8x8_t	vp8x8Output;

	uint32_t	u32Idx, u32Idx2;

	// initial
	as16DataIn[0] = 100 << 8 | 100;
	as16DataIn[1] = 200 << 8 | 200;
	as16DataIn[2] = 10 << 8 | 100;
	as16DataIn[3] = 20 << 8 | 200;

	vs16x4Input	= vld1_s16(as16DataIn);

	// poly8x8_t vreinterpret_p8_s16(int16x4_t __a);
	vp8x8Output		= vreinterpret_p8_s16(vs16x4Input);
	vst1_p8(ap8DataOut, vp8x8Output);

	printf("== Vector Cast p8 = s16 (vreinterpret_p8_s16) ==\n");
	for (u32Idx = 0, u32Idx2 = 0; u32Idx < 4; ++u32Idx, u32Idx2+=2)
	{
		printf("%6d, "UINT16_TO_BIT_PATTERN" => "UINT8_TO_BIT_PATTERN", "UINT8_TO_BIT_PATTERN"\n",
			as16DataIn[u32Idx], UINT16_TO_BIT(as16DataIn[u32Idx]),
			UINT8_TO_BIT(ap8DataOut[u32Idx2 + 1]), UINT8_TO_BIT(ap8DataOut[u32Idx2]));
	}
	printf("========================================\n");
}

// -----------------------------------------------------------------------------
void NeonSample_VectorCast_P8_F32()
{
	// poly8x8_t vreinterpret_p8_f32(float32x2_t __a);
}

// -----------------------------------------------------------------------------
void NeonSample_VectorCast_P8_U8()
{
	uint8_t		au8DataIn[8];
	poly8_t		ap8DataOut[8];

	uint8x8_t	vu8x8Input;
	poly8x8_t	vp8x8Output;

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

	// poly8x8_t vreinterpret_p8_u8(uint8x8_t __a);
	vp8x8Output		= vreinterpret_p8_u8(vu8x8Input);
	vst1_p8(ap8DataOut, vp8x8Output);

	printf("== Vector Cast p8 = u8 (vreinterpret_p8_u8) ==\n");
	for (u32Idx = 0; u32Idx < 8; ++u32Idx)
	{
		printf("%3d, "UINT8_TO_BIT_PATTERN" => "UINT8_TO_BIT_PATTERN"\n",
			au8DataIn[u32Idx], UINT8_TO_BIT(au8DataIn[u32Idx]),
			UINT8_TO_BIT(ap8DataOut[u32Idx]));
	}
	printf("========================================\n");
}

// -----------------------------------------------------------------------------
void NeonSample_VectorCast_P8_U16()
{
	uint16_t	au16DataIn[4];
	poly8_t		ap8DataOut[8];

	uint16x4_t	vu16x4Input;
	poly8x8_t	vp8x8Output;

	uint32_t	u32Idx, u32Idx2;

	// initial
	au16DataIn[0] = 1024;
	au16DataIn[1] = 4096;
	au16DataIn[2] = 32767;
	au16DataIn[3] = 65535;

	vu16x4Input	= vld1_u16(au16DataIn);

	// poly8x8_t vreinterpret_p8_u16(uint16x4_t __a);
	vp8x8Output		= vreinterpret_p8_u16(vu16x4Input);
	vst1_p8(ap8DataOut, vp8x8Output);

	printf("== Vector Cast p8 = u16 (vreinterpret_p8_u16) ==\n");
	for (u32Idx = 0, u32Idx2 = 0; u32Idx < 4; ++u32Idx, u32Idx2+=2)
	{
		printf("%5d, "UINT16_TO_BIT_PATTERN" => "UINT8_TO_BIT_PATTERN", "UINT8_TO_BIT_PATTERN"\n",
			au16DataIn[u32Idx], UINT16_TO_BIT(au16DataIn[u32Idx]),
			UINT8_TO_BIT(ap8DataOut[u32Idx2 + 1]), UINT8_TO_BIT(ap8DataOut[u32Idx2]));
	}
	printf("========================================\n");
}

// -----------------------------------------------------------------------------
void NeonSample_VectorCast_P8_P16()
{
	poly16_t	ap16DataIn[4];
	poly8_t		ap8DataOut[8];

	poly16x4_t	vp16x4Input;
	poly8x8_t	vp8x8Output;

	uint32_t	u32Idx, u32Idx2;

	// initial
	ap16DataIn[0] = 0b1111111100000000;
	ap16DataIn[1] = 0b1100110011001100;
	ap16DataIn[2] = 0b1010101001010101;
	ap16DataIn[3] = 0b1110001110001100;

	vp16x4Input	= vld1_p16(ap16DataIn);

	// poly8x8_t vreinterpret_p8_p16(poly16x4_t __a);
	vp8x8Output		= vreinterpret_p8_p16(vp16x4Input);
	vst1_p8(ap8DataOut, vp8x8Output);

	printf("== Vector Cast p8 = p16 (vreinterpret_p8_p16) ==\n");
	for (u32Idx = 0, u32Idx2 = 0; u32Idx < 4; ++u32Idx, u32Idx2+=2)
	{
		printf(UINT16_TO_BIT_PATTERN" => "UINT8_TO_BIT_PATTERN", "UINT8_TO_BIT_PATTERN"\n",
			UINT16_TO_BIT(ap16DataIn[u32Idx]),
			UINT8_TO_BIT(ap8DataOut[u32Idx2 + 1]), UINT8_TO_BIT(ap8DataOut[u32Idx2]));
	}
	printf("========================================\n");
}

// -----------------------------------------------------------------------------
void NeonSample_VectorCast_P16_S8()
{
	int8_t		as8DataIn[8];
	poly16_t	ap16DataOut[4];

	int8x8_t	vs8x8Input;
	poly16x4_t	vp16x4Output;

	uint32_t	u32Idx, u32Idx2;

	// initial
	as8DataIn[0] = -128;
	as8DataIn[1] = -100;
	as8DataIn[2] = -50;
	as8DataIn[3] = -30;
	as8DataIn[4] = 30;
	as8DataIn[5] = 50;
	as8DataIn[6] = 100;
	as8DataIn[7] = 127;

	vs8x8Input		= vld1_s8(as8DataIn);

	// poly16x4_t vreinterpret_p16_s8(int8x8_t __a);
	vp16x4Output	= vreinterpret_p16_s8(vs8x8Input);
	vst1_p16(ap16DataOut, vp16x4Output);

	printf("== Vector Cast p16 = s8 (vreinterpret_p16_s8) ==\n");
	for (u32Idx = 0, u32Idx2 = 0; u32Idx < 4; ++u32Idx, u32Idx2+=2)
	{
		printf("%4d, %4d, "UINT8_TO_BIT_PATTERN", "UINT8_TO_BIT_PATTERN" => "UINT16_TO_BIT_PATTERN"\n",
			as8DataIn[u32Idx2 + 1], as8DataIn[u32Idx2],
			UINT8_TO_BIT(as8DataIn[u32Idx2 + 1]), UINT8_TO_BIT(as8DataIn[u32Idx2]),
			UINT16_TO_BIT(ap16DataOut[u32Idx]));
	}
	printf("========================================\n");
}

// -----------------------------------------------------------------------------
void NeonSample_VectorCast_P16_S16()
{
	int16_t		as16DataIn[4];
	poly16_t	ap16DataOut[4];

	int16x4_t	vs16x4Input;
	poly16x4_t	vp16x4Output;

	uint32_t	u32Idx;

	// initial
	as16DataIn[0] = -100;
	as16DataIn[1] = -10000;
	as16DataIn[2] = 10000;
	as16DataIn[3] = 100;

	vs16x4Input		= vld1_s16(as16DataIn);

	// poly16x4_t vreinterpret_p16_s16(int16x4_t __a);
	vp16x4Output	= vreinterpret_p16_s16(vs16x4Input);
	vst1_p16(ap16DataOut, vp16x4Output);

	printf("== Vector Cast p16 = s16 (vreinterpret_p16_s16) ==\n");
	for (u32Idx = 0; u32Idx < 4; ++u32Idx)
	{
		printf("%6d, "UINT16_TO_BIT_PATTERN" => "UINT16_TO_BIT_PATTERN"\n",
			as16DataIn[u32Idx], UINT16_TO_BIT(as16DataIn[u32Idx]),
			UINT16_TO_BIT(ap16DataOut[u32Idx]));
	}
	printf("========================================\n");
}

// -----------------------------------------------------------------------------
void NeonSample_VectorCast_P16_F32()
{
	// poly16x4_t vreinterpret_p16_f32(float32x2_t __a);
}

// -----------------------------------------------------------------------------
void NeonSample_VectorCast_P16_U8()
{
	uint8_t		au8DataIn[8];
	poly16_t	ap16DataOut[4];

	uint8x8_t	vu8x8Input;
	poly16x4_t	vp16x4Output;

	uint32_t	u32Idx, u32Idx2;

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

	// poly16x4_t vreinterpret_p16_u8(uint8x8_t __a);
	vp16x4Output	= vreinterpret_p16_u8(vu8x8Input);
	vst1_p16(ap16DataOut, vp16x4Output);

	printf("== Vector Cast p16 = u8 (vreinterpret_p16_u8) ==\n");
	for (u32Idx = 0, u32Idx2 = 0; u32Idx < 4; ++u32Idx, u32Idx2+=2)
	{
		printf("%4d, %4d, "UINT8_TO_BIT_PATTERN", "UINT8_TO_BIT_PATTERN" => "UINT16_TO_BIT_PATTERN"\n",
			au8DataIn[u32Idx2 + 1], au8DataIn[u32Idx2],
			UINT8_TO_BIT(au8DataIn[u32Idx2 + 1]), UINT8_TO_BIT(au8DataIn[u32Idx2]),
			UINT16_TO_BIT(ap16DataOut[u32Idx]));
	}
	printf("========================================\n");
}

// -----------------------------------------------------------------------------
void NeonSample_VectorCast_P16_U16()
{
	uint16_t	au16DataIn[4];
	poly16_t	ap16DataOut[4];

	uint16x4_t	vu16x4Input;
	poly16x4_t	vp16x4Output;

	uint32_t	u32Idx;

	// initial
	au16DataIn[0] = 512;
	au16DataIn[1] = 32767;
	au16DataIn[2] = 32768;
	au16DataIn[3] = 65535;

	vu16x4Input		= vld1_u16(au16DataIn);

	// poly16x4_t vreinterpret_p16_u16(uint16x4_t __a);
	vp16x4Output	= vreinterpret_p16_u16(vu16x4Input);
	vst1_p16(ap16DataOut, vp16x4Output);

	printf("== Vector Cast p16 = u16 (vreinterpret_p16_u16) ==\n");
	for (u32Idx = 0; u32Idx < 4; ++u32Idx)
	{
		printf("%5d, "UINT16_TO_BIT_PATTERN" => "UINT16_TO_BIT_PATTERN"\n",
			au16DataIn[u32Idx], UINT16_TO_BIT(au16DataIn[u32Idx]),
			UINT16_TO_BIT(ap16DataOut[u32Idx]));
	}
	printf("========================================\n");
}

// -----------------------------------------------------------------------------
void NeonSample_VectorCast_P16_P8()
{
	poly8_t		ap8DataIn[8];
	poly16_t	ap16DataOut[4];

	poly8x8_t	vp8x8Input;
	poly16x4_t	vp16x4Output;

	uint32_t	u32Idx, u32Idx2;

	// initial
	ap8DataIn[0] = 0b00000011;
	ap8DataIn[1] = 0b00001100;
	ap8DataIn[2] = 0b00110000;
	ap8DataIn[3] = 0b11000000;
	ap8DataIn[4] = 0b00001111;
	ap8DataIn[5] = 0b00111100;
	ap8DataIn[6] = 0b11110000;
	ap8DataIn[7] = 0b11111111;

	vp8x8Input		= vld1_p8(ap8DataIn);

	// poly16x4_t vreinterpret_p16_p8(poly8x8_t __a);
	vp16x4Output	= vreinterpret_p16_p8(vp8x8Input);
	vst1_p16(ap16DataOut, vp16x4Output);

	printf("== Vector Cast p16 = p8 (vreinterpret_p16_p8) ==\n");
	for (u32Idx = 0, u32Idx2 = 0; u32Idx < 4; ++u32Idx, u32Idx2+=2)
	{
		printf(UINT8_TO_BIT_PATTERN", "UINT8_TO_BIT_PATTERN" => "UINT16_TO_BIT_PATTERN"\n",
			UINT8_TO_BIT(ap8DataIn[u32Idx2 + 1]), UINT8_TO_BIT(ap8DataIn[u32Idx2]),
			UINT16_TO_BIT(ap16DataOut[u32Idx]));
	}
	printf("========================================\n");
}

// -----------------------------------------------------------------------------
