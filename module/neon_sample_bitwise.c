#include "neon_sample.h"

// https://developer.arm.com/documentation/dui0472/m/using-neon-support/neon-intrinsics-for-logical-operations

// -----------------------------------------------------------------------------
void NeonSample_Bitwise_U8_U8()
{
	uint8_t		au8DataIn[8];
	uint8_t		au8DataOut[8];

	uint8x8_t	vu8x8Input;
	uint8x8_t	vu8x8Output;

	uint32_t	u32Idx;

	// initial
	au8DataIn[0] = 0b11110000;
	au8DataIn[1] = 0b00001111;
	au8DataIn[2] = 0b10101010;
	au8DataIn[3] = 0b01010101;
	au8DataIn[4] = 0b11111111;
	au8DataIn[5] = 0b00000000;
	au8DataIn[6] = 0b11100111;
	au8DataIn[7] = 0b11001100;

	vu8x8Input		= vld1_u8(au8DataIn);

	// uint8x8_t vmvn_u8(uint8x8_t a);											// VMVN d0,d0
	// not(a)
	vu8x8Output		= vmvn_u8(vu8x8Input);
	vst1_u8(au8DataOut, vu8x8Output);

	printf("== Not u8 = !u8 (vmvn_u8) ==\n");
	for (u32Idx = 0; u32Idx < 8; ++u32Idx)
	{
		printf("("UINT8_TO_BIT_PATTERN") => ("UINT8_TO_BIT_PATTERN")\n",
			UINT8_TO_BIT(au8DataIn[u32Idx]),
			UINT8_TO_BIT(au8DataOut[u32Idx]));
	}
	printf("========================================\n");
}

// -----------------------------------------------------------------------------
void NeonSample_Bitwise_S8_S8()
{
	int8_t		as8DataIn[8];
	int8_t		as8DataOut[8];

	int8x8_t	vs8x8Input;
	int8x8_t	vs8x8Output;

	uint32_t	u32Idx;

	// initial
	as8DataIn[0] = 0b00000000;
	as8DataIn[1] = 0b10000000;
	as8DataIn[2] = 0b00001111;
	as8DataIn[3] = 0b10001111;
	as8DataIn[4] = 0b11111111;
	as8DataIn[5] = 0b10000011;
	as8DataIn[6] = 0b10001100;
	as8DataIn[7] = 0b10110011;

	vs8x8Input		= vld1_s8(as8DataIn);

	// int8x8_t vmvn_s8(int8x8_t a);											// VMVN d0,d0
	// not(a)
	vs8x8Output		= vmvn_s8(vs8x8Input);
	vst1_s8(as8DataOut, vs8x8Output);

	printf("== Not s8 = !s8 (vmvn_s8) ==\n");
	for (u32Idx = 0; u32Idx < 8; ++u32Idx)
	{
		printf("("UINT8_TO_BIT_PATTERN") => ("UINT8_TO_BIT_PATTERN")\n",
			UINT8_TO_BIT(as8DataIn[u32Idx]),
			UINT8_TO_BIT(as8DataOut[u32Idx]));
	}
	printf("========================================\n");
}

// -----------------------------------------------------------------------------
void NeonSample_Bitwise_U8_U8_U8()
{
	uint8_t		au8DataIn1[8];
	uint8_t		au8DataIn2[8];
	uint8_t		au8DataOutAND[8];
	uint8_t		au8DataOutOR[8];
	uint8_t		au8DataOutXOR[8];
	uint8_t		au8DataOutClear[8];
	uint8_t		au8DataOutORComplement[8];

	uint8x8_t	vu8x8InputA;
	uint8x8_t	vu8x8InputB;
	uint8x8_t	vu8x8Output;

	uint32_t	u32Idx;

	// initial
	au8DataIn1[0] = 0b00000000;		au8DataIn2[0] = 0b00000000;
	au8DataIn1[1] = 0b00000000;		au8DataIn2[1] = 0b11111111;
	au8DataIn1[2] = 0b11110000;		au8DataIn2[2] = 0b00001111;
	au8DataIn1[3] = 0b10101010;		au8DataIn2[3] = 0b00001111;
	au8DataIn1[4] = 0b11111111;		au8DataIn2[4] = 0b11111111;
	au8DataIn1[5] = 0b11001100;		au8DataIn2[5] = 0b11110000;
	au8DataIn1[6] = 0b11001100;		au8DataIn2[6] = 0b00001111;
	au8DataIn1[7] = 0b11111111;		au8DataIn2[7] = 0b00001111;

	vu8x8InputA		= vld1_u8(au8DataIn1);
	vu8x8InputB		= vld1_u8(au8DataIn2);

	// uint8x8_t vand_u8(uint8x8_t a, uint8x8_t b);								// VAND d0,d0,d0
	// (a & b)
	vu8x8Output		= vand_u8(vu8x8InputA, vu8x8InputB);
	vst1_u8(au8DataOutAND, vu8x8Output);

	// uint8x8_t vorr_u8(uint8x8_t a, uint8x8_t b);								// VORR d0,d0,d0
	// (a | b)
	vu8x8Output		= vorr_u8(vu8x8InputA, vu8x8InputB);
	vst1_u8(au8DataOutOR, vu8x8Output);

	// uint8x8_t veor_u8(uint8x8_t a, uint8x8_t b);								// VEOR d0,d0,d0
	// (a ^ b)
	vu8x8Output		= veor_u8(vu8x8InputA, vu8x8InputB);
	vst1_u8(au8DataOutXOR, vu8x8Output);

	// uint8x8_t vbic_u8(uint8x8_t a, uint8x8_t b);								// VBIC d0,d0,d0
	// clear (a, b)
	vu8x8Output		= vbic_u8(vu8x8InputA, vu8x8InputB);
	vst1_u8(au8DataOutClear, vu8x8Output);

	// uint8x8_t vorn_u8(uint8x8_t a, uint8x8_t b);								// VORN d0,d0,d0
	// (a | !b)
	vu8x8Output		= vorn_u8(vu8x8InputA, vu8x8InputB);
	vst1_u8(au8DataOutORComplement, vu8x8Output);

	printf("== Bitwise u8 = u8, u8 ==\n");
	printf("Input A           : ");
	for (u32Idx = 0; u32Idx < 8; ++u32Idx)
	{
		printf(UINT8_TO_BIT_PATTERN"  ", UINT8_TO_BIT(au8DataIn1[u32Idx]));
	}
	printf("\n");
	printf("Input B           : ");
	for (u32Idx = 0; u32Idx < 8; ++u32Idx)
	{
		printf(UINT8_TO_BIT_PATTERN"  ", UINT8_TO_BIT(au8DataIn2[u32Idx]));
	}
	printf("\n");
	printf("\n");

	printf("AND (vand_u8)     : ");
	for (u32Idx = 0; u32Idx < 8; ++u32Idx)
	{
		printf(UINT8_TO_BIT_PATTERN"  ", UINT8_TO_BIT(au8DataOutAND[u32Idx]));
	}
	printf("\n");
	printf("OR (vorr_u8)      : ");
	for (u32Idx = 0; u32Idx < 8; ++u32Idx)
	{
		printf(UINT8_TO_BIT_PATTERN"  ", UINT8_TO_BIT(au8DataOutOR[u32Idx]));
	}
	printf("\n");
	printf("XOR (veor_u8)     : ");
	for (u32Idx = 0; u32Idx < 8; ++u32Idx)
	{
		printf(UINT8_TO_BIT_PATTERN"  ", UINT8_TO_BIT(au8DataOutXOR[u32Idx]));
	}
	printf("\n");
	printf("Clear (vbic_u8)   : ");
	for (u32Idx = 0; u32Idx < 8; ++u32Idx)
	{
		printf(UINT8_TO_BIT_PATTERN"  ", UINT8_TO_BIT(au8DataOutClear[u32Idx]));
	}
	printf("\n");
	printf("OR Comp (vorn_u8) : ");
	for (u32Idx = 0; u32Idx < 8; ++u32Idx)
	{
		printf(UINT8_TO_BIT_PATTERN"  ", UINT8_TO_BIT(au8DataOutORComplement[u32Idx]));
	}
	printf("\n");

	printf("========================================\n");
}

// -----------------------------------------------------------------------------
void NeonSample_Bitwise_S8_S8_S8()
{
	int8_t		as8DataIn1[8];
	int8_t		as8DataIn2[8];
	int8_t		as8DataOutAND[8];
	int8_t		as8DataOutOR[8];
	int8_t		as8DataOutXOR[8];
	int8_t		as8DataOutClear[8];
	int8_t		as8DataOutORComplement[8];

	int8x8_t	vs8x8InputA;
	int8x8_t	vs8x8InputB;
	int8x8_t	vs8x8Output;

	uint32_t	u32Idx;

	// initial
	as8DataIn1[0] = 0b00000000;		as8DataIn2[0] = 0b00000000;
	as8DataIn1[1] = 0b00000000;		as8DataIn2[1] = 0b11111111;
	as8DataIn1[2] = 0b01110000;		as8DataIn2[2] = 0b00001111;
	as8DataIn1[3] = 0b00001111;		as8DataIn2[3] = 0b01111111;
	as8DataIn1[4] = 0b10000000;		as8DataIn2[4] = 0b00000000;
	as8DataIn1[5] = 0b11111111;		as8DataIn2[5] = 0b01111111;
	as8DataIn1[6] = 0b11010101;		as8DataIn2[6] = 0b10101010;
	as8DataIn1[7] = 0b10001111;		as8DataIn2[7] = 0b11110000;

	vs8x8InputA		= vld1_s8(as8DataIn1);
	vs8x8InputB		= vld1_s8(as8DataIn2);

	// int8x8_t vand_s8(int8x8_t a, int8x8_t b);								// VAND d0,d0,d0
	// (a & b)
	vs8x8Output		= vand_s8(vs8x8InputA, vs8x8InputB);
	vst1_s8(as8DataOutAND, vs8x8Output);

	// int8x8_t vorr_s8(int8x8_t a, int8x8_t b);								// VORR d0,d0,d0
	// (a | b)
	vs8x8Output		= vorr_s8(vs8x8InputA, vs8x8InputB);
	vst1_s8(as8DataOutOR, vs8x8Output);

	// int8x8_t veor_s8(int8x8_t a, int8x8_t b);								// VEOR d0,d0,d0
	// (a ^ b)
	vs8x8Output		= veor_s8(vs8x8InputA, vs8x8InputB);
	vst1_s8(as8DataOutXOR, vs8x8Output);

	// int8x8_t vbic_s8(int8x8_t a, int8x8_t b);								// VBIC d0,d0,d0
	// clear (a, b)
	vs8x8Output		= vbic_s8(vs8x8InputA, vs8x8InputB);
	vst1_s8(as8DataOutClear, vs8x8Output);

	// int8x8_t vorn_s8(int8x8_t a, int8x8_t b);								// VORN d0,d0,d0
	// (a | !b)
	vs8x8Output		= vorn_s8(vs8x8InputA, vs8x8InputB);
	vst1_s8(as8DataOutORComplement, vs8x8Output);

	printf("== Bitwise s8 = s8, s8 ==\n");
	printf("Input A           : ");
	for (u32Idx = 0; u32Idx < 8; ++u32Idx)
	{
		printf(UINT8_TO_BIT_PATTERN"  ", UINT8_TO_BIT(as8DataIn1[u32Idx]));
	}
	printf("\n");
	printf("Input B           : ");
	for (u32Idx = 0; u32Idx < 8; ++u32Idx)
	{
		printf(UINT8_TO_BIT_PATTERN"  ", UINT8_TO_BIT(as8DataIn2[u32Idx]));
	}
	printf("\n");
	printf("\n");

	printf("AND (vand_s8)     : ");
	for (u32Idx = 0; u32Idx < 8; ++u32Idx)
	{
		printf(UINT8_TO_BIT_PATTERN"  ", UINT8_TO_BIT(as8DataOutAND[u32Idx]));
	}
	printf("\n");
	printf("OR (vorr_s8)      : ");
	for (u32Idx = 0; u32Idx < 8; ++u32Idx)
	{
		printf(UINT8_TO_BIT_PATTERN"  ", UINT8_TO_BIT(as8DataOutOR[u32Idx]));
	}
	printf("\n");
	printf("XOR (veor_s8)     : ");
	for (u32Idx = 0; u32Idx < 8; ++u32Idx)
	{
		printf(UINT8_TO_BIT_PATTERN"  ", UINT8_TO_BIT(as8DataOutXOR[u32Idx]));
	}
	printf("\n");
	printf("Clear (vbic_s8)   : ");
	for (u32Idx = 0; u32Idx < 8; ++u32Idx)
	{
		printf(UINT8_TO_BIT_PATTERN"  ", UINT8_TO_BIT(as8DataOutClear[u32Idx]));
	}
	printf("\n");
	printf("OR Comp (vorn_s8) : ");
	for (u32Idx = 0; u32Idx < 8; ++u32Idx)
	{
		printf(UINT8_TO_BIT_PATTERN"  ", UINT8_TO_BIT(as8DataOutORComplement[u32Idx]));
	}
	printf("\n");

	printf("========================================\n");
}

// -----------------------------------------------------------------------------
void NeonSample_Bitwise_U8_U8_U8_U8()
{
	uint8_t		au8DataIn1[8];
	uint8_t		au8DataIn2[8];
	uint8_t		au8DataIn3[8];
	uint8_t		au8DataOut[8];

	uint8x8_t	vu8x8InputA;
	uint8x8_t	vu8x8InputB;
	uint8x8_t	vu8x8InputC;
	uint8x8_t	vu8x8Output;

	uint32_t	u32Idx;

	// initial
	au8DataIn1[0] = 0b10101010;		au8DataIn2[0] = 0b00000000;		au8DataIn3[0] = 0b11111111;
	au8DataIn1[1] = 0b10101010;		au8DataIn2[1] = 0b11111111;		au8DataIn3[1] = 0b00000000;
	au8DataIn1[2] = 0b10101010;		au8DataIn2[2] = 0b00001111;		au8DataIn3[2] = 0b11110000;
	au8DataIn1[3] = 0b00001111;		au8DataIn2[3] = 0b00001111;		au8DataIn3[3] = 0b11110000;
	au8DataIn1[4] = 0b00000000;		au8DataIn2[4] = 0b00001111;		au8DataIn3[4] = 0b11110000;
	au8DataIn1[5] = 0b11111111;		au8DataIn2[5] = 0b00001111;		au8DataIn3[5] = 0b11110000;
	au8DataIn1[6] = 0b11111111;		au8DataIn2[6] = 0b00001111;		au8DataIn3[6] = 0b00000000;
	au8DataIn1[7] = 0b11111111;		au8DataIn2[7] = 0b00000000;		au8DataIn3[7] = 0b11110000;

	vu8x8InputA		= vld1_u8(au8DataIn1);
	vu8x8InputB		= vld1_u8(au8DataIn2);
	vu8x8InputC		= vld1_u8(au8DataIn3);

	// uint8x8_t vbsl_u8(uint8x8_t a, uint8x8_t b, uint8x8_t c);				// VBSL d0,d0,d0
	// (a & b) | (!a & c)
	vu8x8Output		= vbsl_u8(vu8x8InputA, vu8x8InputB, vu8x8InputC);
	vst1_u8(au8DataOut, vu8x8Output);

	printf("== Bitwise u8 = u8, u8, u8 (vbsl_u8) ==\n");
	printf("(a & b) | (!a & c)\n");
	printf("Input A : ");
	for (u32Idx = 0; u32Idx < 8; ++u32Idx)
	{
		printf(UINT8_TO_BIT_PATTERN"  ", UINT8_TO_BIT(au8DataIn1[u32Idx]));
	}
	printf("\n");
	printf("Input B : ");
	for (u32Idx = 0; u32Idx < 8; ++u32Idx)
	{
		printf(UINT8_TO_BIT_PATTERN"  ", UINT8_TO_BIT(au8DataIn2[u32Idx]));
	}
	printf("\n");
	printf("Input C : ");
	for (u32Idx = 0; u32Idx < 8; ++u32Idx)
	{
		printf(UINT8_TO_BIT_PATTERN"  ", UINT8_TO_BIT(au8DataIn3[u32Idx]));
	}
	printf("\n");

	printf("Select  : ");
	for (u32Idx = 0; u32Idx < 8; ++u32Idx)
	{
		printf(UINT8_TO_BIT_PATTERN"  ", UINT8_TO_BIT(au8DataOut[u32Idx]));
	}
	printf("\n");
	printf("========================================\n");
}

// -----------------------------------------------------------------------------
void NeonSample_Bitwise_S8_S8_S8_S8()
{
	int8_t		as8DataIn1[8];
	int8_t		as8DataIn2[8];
	int8_t		as8DataIn3[8];
	int8_t		as8DataOut[8];

	int8x8_t	vs8x8InputA;
	int8x8_t	vs8x8InputB;
	int8x8_t	vs8x8InputC;
	int8x8_t	vs8x8Output;

	uint32_t	u32Idx;

	// initials
	as8DataIn1[0] = 0b10101010;		as8DataIn2[0] = 0b00000000;		as8DataIn3[0] = 0b11111111;
	as8DataIn1[1] = 0b10101010;		as8DataIn2[1] = 0b11111111;		as8DataIn3[1] = 0b00000000;
	as8DataIn1[2] = 0b10101010;		as8DataIn2[2] = 0b00001111;		as8DataIn3[2] = 0b11110000;
	as8DataIn1[3] = 0b00001111;		as8DataIn2[3] = 0b00001111;		as8DataIn3[3] = 0b11110000;
	as8DataIn1[4] = 0b00000000;		as8DataIn2[4] = 0b00001111;		as8DataIn3[4] = 0b11110000;
	as8DataIn1[5] = 0b11111111;		as8DataIn2[5] = 0b00001111;		as8DataIn3[5] = 0b11110000;
	as8DataIn1[6] = 0b11111111;		as8DataIn2[6] = 0b00001111;		as8DataIn3[6] = 0b00000000;
	as8DataIn1[7] = 0b11111111;		as8DataIn2[7] = 0b00000000;		as8DataIn3[7] = 0b11110000;

	vs8x8InputA		= vld1_s8(as8DataIn1);
	vs8x8InputB		= vld1_s8(as8DataIn2);
	vs8x8InputC		= vld1_s8(as8DataIn3);

	// int8x8_t vbsl_s8(uint8x8_t a, int8x8_t b, int8x8_t c);					// VBSL d0,d0,d0
	// (a & b) | (!a & c)
	vs8x8Output		= vbsl_s8(vs8x8InputA, vs8x8InputB, vs8x8InputC);
	vst1_s8(as8DataOut, vs8x8Output);

	printf("== Bitwise s8 = s8, s8, s8 (vbsl_s8) ==\n");
	printf("(a & b) | (!a & c)\n");
	printf("Input A : ");
	for (u32Idx = 0; u32Idx < 8; ++u32Idx)
	{
		printf(UINT8_TO_BIT_PATTERN"  ", UINT8_TO_BIT(as8DataIn1[u32Idx]));
	}
	printf("\n");
	printf("Input B : ");
	for (u32Idx = 0; u32Idx < 8; ++u32Idx)
	{
		printf(UINT8_TO_BIT_PATTERN"  ", UINT8_TO_BIT(as8DataIn2[u32Idx]));
	}
	printf("\n");
	printf("Input C : ");
	for (u32Idx = 0; u32Idx < 8; ++u32Idx)
	{
		printf(UINT8_TO_BIT_PATTERN"  ", UINT8_TO_BIT(as8DataIn3[u32Idx]));
	}
	printf("\n");

	printf("Select  : ");
	for (u32Idx = 0; u32Idx < 8; ++u32Idx)
	{
		printf(UINT8_TO_BIT_PATTERN"  ", UINT8_TO_BIT(as8DataOut[u32Idx]));
	}
	printf("\n");
	printf("========================================\n");
}

// -----------------------------------------------------------------------------
void NeonSample_Bitwise_F32_U32_F32_F32()
{
	uint32_t		au32DataIn1[2];
	float			af32DataIn2[2];
	float			af32DataIn3[2];
	float			af32DataOut[2];

	uint32x2_t		vs32x2InputA;
	float32x2_t		vf32x2InputB;
	float32x2_t		vf32x2InputC;
	float32x2_t		vf32x2Output;

	uint32_t	u32Idx;

	// initials
	au32DataIn1[0] = 0b10101010101010101010101010101010;
	af32DataIn2[0] = 0b00000000;
	af32DataIn3[0] = 0b11111111;

	au32DataIn1[1] = 0b10101010101010101010101010101010;
	af32DataIn2[1] = 0b11111111;
	af32DataIn3[1] = 0b00000000;

	vs32x2InputA	= vld1_u32(au32DataIn1);
	vf32x2InputB	= vld1_f32(af32DataIn2);
	vf32x2InputC	= vld1_f32(af32DataIn3);

	// float32x2_t vbsl_f32(uint32x2_t a, float32x2_t b, float32x2_t c);		// VBSL d0,d0,d0
	// (a & b) | (!a & c)
	vf32x2Output	= vbsl_f32(vs32x2InputA, vf32x2InputB, vf32x2InputC);
	vst1_f32(af32DataOut, vf32x2Output);

	printf("== Bitwise f32 = u32, f32, f32 (vbsl_f32) ==\n");
	printf("=> (a & b) | (!a & c)\n");
	for (u32Idx = 0; u32Idx < 2; ++u32Idx)
	{
		printf("Index : %d\n", u32Idx);
		printf("Input A   : "UINT32_TO_BIT_PATTERN"\n", UINT32_TO_BIT(au32DataIn1[u32Idx]));
		printf("Input B   : "UINT32_TO_BIT_PATTERN"\n", UINT32_TO_BIT((uint32_t)(af32DataIn2[u32Idx])));
		printf("Input C   : "UINT32_TO_BIT_PATTERN"\n", UINT32_TO_BIT((uint32_t)(af32DataIn3[u32Idx])));
		printf("=> Select : "UINT32_TO_BIT_PATTERN"\n", UINT32_TO_BIT((uint32_t)(af32DataOut[u32Idx])));
		printf("\n");
	}
	printf("========================================\n");
}

// -----------------------------------------------------------------------------
void NeonSample_Bitwise_P8_U8_P8_P8()
{
	uint8_t			au8DataIn1[8];
	uint8_t			au8DataIn2[8];
	uint8_t			au8DataIn3[8];
	uint8_t			au8DataOut[8];

	uint8x8_t		vu8x8InputA;
	poly8x8_t		vp8x8InputB;
	poly8x8_t		vp8x8InputC;
	poly8x8_t		vp8x8Output;

	uint32_t	u32Idx;

	// initials
	au8DataIn1[0] = 0b10101010;		au8DataIn2[0] = 0b11111111;		au8DataIn3[0] = 0b00000000;
	au8DataIn1[1] = 0b10101010;		au8DataIn2[1] = 0b11110000;		au8DataIn3[0] = 0b11110000;
	au8DataIn1[2] = 0b10101010;		au8DataIn2[2] = 0b11110000;		au8DataIn3[0] = 0b00001111;
	au8DataIn1[3] = 0b11110101;		au8DataIn2[3] = 0b11110000;		au8DataIn3[0] = 0b00001010;
	au8DataIn1[4] = 0b10101010;		au8DataIn2[4] = 0b11110000;		au8DataIn3[0] = 0b00000101;
	au8DataIn1[5] = 0b01010101;		au8DataIn2[5] = 0b00001111;		au8DataIn3[0] = 0b10101010;
	au8DataIn1[6] = 0b10100000;		au8DataIn2[6] = 0b00001111;		au8DataIn3[0] = 0b01010101;
	au8DataIn1[7] = 0b10101010;		au8DataIn2[7] = 0b10101010;		au8DataIn3[0] = 0b01010101;

	vu8x8InputA		= vld1_u8(au8DataIn1);
	vp8x8InputB		= vld1_p8(au8DataIn2);
	vp8x8InputC		= vld1_p8(au8DataIn3);

	// poly8x8_t vbsl_p8(uint8x8_t a, poly8x8_t b, poly8x8_t c);				// VBSL d0,d0,d0
	// (a & b) | (!a & c)
	vp8x8Output		= vbsl_p8(vu8x8InputA, vp8x8InputB, vp8x8InputC);
	vst1_p8(au8DataOut, vp8x8Output);

	printf("== Bitwise p8 = u8, p8, p8 (vbsl_p8) ==\n");
	printf("=> (a & b) | (!a & c)\n");
	for (u32Idx = 0; u32Idx < 8; ++u32Idx)
	{
		printf("Index : %d\n", u32Idx);
		printf("Input A /Inv A : "UINT8_TO_BIT_PATTERN" "UINT8_TO_BIT_PATTERN"\n", UINT8_TO_BIT(au8DataIn1[u32Idx]), UINT8_TO_BIT(~au8DataIn1[u32Idx]));
		printf("Input B        : "UINT8_TO_BIT_PATTERN"\n", UINT8_TO_BIT(au8DataIn2[u32Idx]));
		printf("Input C        :          "UINT8_TO_BIT_PATTERN"\n", UINT8_TO_BIT(au8DataIn3[u32Idx]));
		printf("=> Select      : "UINT8_TO_BIT_PATTERN"\n", UINT8_TO_BIT(au8DataOut[u32Idx]));
		printf("\n");
	}
	printf("========================================\n");
}

// -----------------------------------------------------------------------------
