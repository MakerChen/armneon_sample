#include "neon_sample.h"

// https://developer.arm.com/documentation/dui0472/m/using-neon-support/neon-intrinsics-for-transposition-operations

// -----------------------------------------------------------------------------
void NeonSample_Transposition_U82_U8_U8()
{
	uint8_t			au8DataInA[8];
	uint8_t			au8DataInB[8];
	uint8_t			au8DataOutTranspose[16];
	uint8_t			au8DataOutTranspose1[8];
	uint8_t			au8DataOutTranspose2[8];
	uint8_t			au8DataOutInterleave[16];
	uint8_t			au8DataOutInterleave1[8];
	uint8_t			au8DataOutInterleave2[8];
	uint8_t			au8DataOutDeInterleave[16];
	uint8_t			au8DataOutDeInterleave1[8];
	uint8_t			au8DataOutDeInterleave2[8];

	uint8x8_t		vu8x8InputA;
	uint8x8_t		vu8x8InputB;
	uint8x8x2_t		vu8x8x2Output;

	uint32_t		u32Idx;

	// initial
	au8DataInA[0] = 10;		au8DataInB[0] = 20;
	au8DataInA[1] = 30;		au8DataInB[1] = 40;
	au8DataInA[2] = 50;		au8DataInB[2] = 60;
	au8DataInA[3] = 70;		au8DataInB[3] = 80;
	au8DataInA[4] = 90;		au8DataInB[4] = 100;
	au8DataInA[5] = 110;	au8DataInB[5] = 120;
	au8DataInA[6] = 130;	au8DataInB[6] = 140;
	au8DataInA[7] = 150;	au8DataInB[7] = 160;

	vu8x8InputA		= vld1_u8(au8DataInA);
	vu8x8InputB		= vld1_u8(au8DataInB);

	// uint8x8x2_t vtrn_u8(uint8x8_t a, uint8x8_t b);							// VTRN.8 d0,d0
	vu8x8x2Output	= vtrn_u8(vu8x8InputA, vu8x8InputB);
	vst2_u8(au8DataOutTranspose, vu8x8x2Output);
	vst1_u8(au8DataOutTranspose1, vu8x8x2Output.val[0]);
	vst1_u8(au8DataOutTranspose2, vu8x8x2Output.val[1]);

	// uint8x8x2_t vzip_u8(uint8x8_t a, uint8x8_t b);							// VZIP.8 d0,d0
	vu8x8x2Output	= vzip_u8(vu8x8InputA, vu8x8InputB);
	vst2_u8(au8DataOutInterleave, vu8x8x2Output);
	vst1_u8(au8DataOutInterleave1, vu8x8x2Output.val[0]);
	vst1_u8(au8DataOutInterleave2, vu8x8x2Output.val[1]);

	// uint8x8x2_t vuzp_u8(uint8x8_t a, uint8x8_t b);							// VUZP.8 d0,d0
	vu8x8x2Output	= vuzp_u8(vu8x8InputA, vu8x8InputB);
	vst2_u8(au8DataOutDeInterleave, vu8x8x2Output);
	vst1_u8(au8DataOutDeInterleave1, vu8x8x2Output.val[0]);
	vst1_u8(au8DataOutDeInterleave2, vu8x8x2Output.val[1]);

	printf("== Transposition u82 = u8, u8 (vtrn_u8 / vzip_u8 / vuzp_u8)  ==\n");
	printf("=> vtrn_u8 : 2x2 with transpose elements, a[even] <-> b[odd] ==\n");
	printf("=> vzip_u8 : interleave                                      ==\n");
	printf("     a'[0~7] = a[0], b[0], a[1], b[1] ...                    ==\n");
	printf("     b'[0~7] = a[4], b[4], a[5], b[5] ...                    ==\n");
	printf("=> vuzp_u8 : de-interleave                                   ==\n");
	printf("     a'[0~3] = a[0], a[2], a[4], a[6]                        ==\n");
	printf("     b'[0~3] = a[1], a[3], a[5], a[7]                        ==\n");
	printf("     a'[4~7] = b[0], b[2], b[4], b[6]                        ==\n");
	printf("     b'[4~7] = b[1], b[3], b[5], b[7]                        ==\n");

	printf("Input A :         ");
	for (u32Idx = 0; u32Idx < 8; ++u32Idx)
	{
		printf("%3d ", au8DataInA[u32Idx]);
	}
	printf("\n");
	printf("Input B :         ");
	for (u32Idx = 0; u32Idx < 8; ++u32Idx)
	{
		printf("%3d ", au8DataInB[u32Idx]);
	}
	printf("\n");

	printf("Output (Transpose) :\n");
	printf("\t");
	for (u32Idx = 0; u32Idx < 16; ++u32Idx)
	{
		printf("%3d ", au8DataOutTranspose[u32Idx]);
	}
	printf("\n");
	printf("Output Part (1) : ");
	for (u32Idx = 0; u32Idx < 8; ++u32Idx)
	{
		printf("%3d ", au8DataOutTranspose1[u32Idx]);
	}
	printf("\n");
	printf("Output Part (2) : ");
	for (u32Idx = 0; u32Idx < 8; ++u32Idx)
	{
		printf("%3d ", au8DataOutTranspose2[u32Idx]);
	}
	printf("\n");

	printf("Output (Interleave) :\n");
	printf("\t");
	for (u32Idx = 0; u32Idx < 16; ++u32Idx)
	{
		printf("%3d ", au8DataOutInterleave[u32Idx]);
	}
	printf("\n");
	printf("Output Part (1) : ");
	for (u32Idx = 0; u32Idx < 8; ++u32Idx)
	{
		printf("%3d ", au8DataOutInterleave1[u32Idx]);
	}
	printf("\n");
	printf("Output Part (2) : ");
	for (u32Idx = 0; u32Idx < 8; ++u32Idx)
	{
		printf("%3d ", au8DataOutInterleave2[u32Idx]);
	}
	printf("\n");

	printf("Output (De-Interleave) :\n");
	printf("\t");
	for (u32Idx = 0; u32Idx < 16; ++u32Idx)
	{
		printf("%3d ", au8DataOutDeInterleave[u32Idx]);
	}
	printf("\n");
	printf("Output Part (1) : ");
	for (u32Idx = 0; u32Idx < 8; ++u32Idx)
	{
		printf("%3d ", au8DataOutDeInterleave1[u32Idx]);
	}
	printf("\n");
	printf("Output Part (2) : ");
	for (u32Idx = 0; u32Idx < 8; ++u32Idx)
	{
		printf("%3d ", au8DataOutDeInterleave2[u32Idx]);
	}
	printf("\n");
	printf("========================================\n");
}

// -----------------------------------------------------------------------------
void NeonSample_Transposition_S82_S8_S8()
{
	int8_t			as8DataInA[8];
	int8_t			as8DataInB[8];
	int8_t			as8DataOutTranspose[16];
	int8_t			as8DataOutTranspose1[8];
	int8_t			as8DataOutTranspose2[8];
	int8_t			as8DataOutInterleave[16];
	int8_t			as8DataOutInterleave1[8];
	int8_t			as8DataOutInterleave2[8];
	int8_t			as8DataOutDeInterleave[16];
	int8_t			as8DataOutDeInterleave1[8];
	int8_t			as8DataOutDeInterleave2[8];

	int8x8_t		vs8x8InputA;
	int8x8_t		vs8x8InputB;
	int8x8x2_t		vs8x8x2Output;

	uint32_t		u32Idx;

	// initial
	as8DataInA[0] = 10;		as8DataInB[0] = -10;
	as8DataInA[1] = 30;		as8DataInB[1] = -30;
	as8DataInA[2] = 50;		as8DataInB[2] = -50;
	as8DataInA[3] = 70;		as8DataInB[3] = -70;
	as8DataInA[4] = 90;		as8DataInB[4] = -90;
	as8DataInA[5] = 100;	as8DataInB[5] = -100;
	as8DataInA[6] = 110;	as8DataInB[6] = -110;
	as8DataInA[7] = 120;	as8DataInB[7] = -120;

	vs8x8InputA		= vld1_s8(as8DataInA);
	vs8x8InputB		= vld1_s8(as8DataInB);

	// int8x8x2_t vtrn_s8(int8x8_t a, int8x8_t b);								// VTRN.8 d0,d0
	vs8x8x2Output	= vtrn_s8(vs8x8InputA, vs8x8InputB);
	vst2_s8(as8DataOutTranspose, vs8x8x2Output);
	vst1_s8(as8DataOutTranspose1, vs8x8x2Output.val[0]);
	vst1_s8(as8DataOutTranspose2, vs8x8x2Output.val[1]);

	// int8x8x2_t vzip_s8(int8x8_t a, int8x8_t b);								// VZIP.8 d0,d0
	vs8x8x2Output	= vzip_s8(vs8x8InputA, vs8x8InputB);
	vst2_s8(as8DataOutInterleave, vs8x8x2Output);
	vst1_s8(as8DataOutInterleave1, vs8x8x2Output.val[0]);
	vst1_s8(as8DataOutInterleave2, vs8x8x2Output.val[1]);

	// int8x8x2_t vuzp_s8(int8x8_t a, int8x8_t b);								// VUZP.8 d0,d0
	vs8x8x2Output	= vuzp_s8(vs8x8InputA, vs8x8InputB);
	vst2_s8(as8DataOutDeInterleave, vs8x8x2Output);
	vst1_s8(as8DataOutDeInterleave1, vs8x8x2Output.val[0]);
	vst1_s8(as8DataOutDeInterleave2, vs8x8x2Output.val[1]);

	printf("== Transposition s82 = s8, s8 (vtrn_s8 / vzip_s8 / vuzp_s8)  ==\n");
	printf("=> vtrn_s8 : 2x2 with transpose elements, a[even] <-> b[odd] ==\n");
	printf("=> vzip_s8 : interleave                                      ==\n");
	printf("     a'[0~7] = a[0], b[0], a[1], b[1] ...                    ==\n");
	printf("     b'[0~7] = a[4], b[4], a[5], b[5] ...                    ==\n");
	printf("=> vuzp_s8 : de-interleave                                   ==\n");
	printf("     a'[0~3] = a[0], a[2], a[4], a[6]                        ==\n");
	printf("     b'[0~3] = a[1], a[3], a[5], a[7]                        ==\n");
	printf("     a'[4~7] = b[0], b[2], b[4], b[6]                        ==\n");
	printf("     b'[4~7] = b[1], b[3], b[5], b[7]                        ==\n");

	printf("Input A :         ");
	for (u32Idx = 0; u32Idx < 8; ++u32Idx)
	{
		printf("%4d ", as8DataInA[u32Idx]);
	}
	printf("\n");
	printf("Input B :         ");
	for (u32Idx = 0; u32Idx < 8; ++u32Idx)
	{
		printf("%4d ", as8DataInB[u32Idx]);
	}
	printf("\n");

	printf("Output (Transpose) :\n");
	printf("\t");
	for (u32Idx = 0; u32Idx < 16; ++u32Idx)
	{
		printf("%4d ", as8DataOutTranspose[u32Idx]);
	}
	printf("\n");
	printf("Output Part (1) : ");
	for (u32Idx = 0; u32Idx < 8; ++u32Idx)
	{
		printf("%4d ", as8DataOutTranspose1[u32Idx]);
	}
	printf("\n");
	printf("Output Part (2) : ");
	for (u32Idx = 0; u32Idx < 8; ++u32Idx)
	{
		printf("%4d ", as8DataOutTranspose2[u32Idx]);
	}
	printf("\n");

	printf("Output (Interleave) :\n");
	printf("\t");
	for (u32Idx = 0; u32Idx < 16; ++u32Idx)
	{
		printf("%4d ", as8DataOutInterleave[u32Idx]);
	}
	printf("\n");
	printf("Output Part (1) : ");
	for (u32Idx = 0; u32Idx < 8; ++u32Idx)
	{
		printf("%4d ", as8DataOutInterleave1[u32Idx]);
	}
	printf("\n");
	printf("Output Part (2) : ");
	for (u32Idx = 0; u32Idx < 8; ++u32Idx)
	{
		printf("%4d ", as8DataOutInterleave2[u32Idx]);
	}
	printf("\n");

	printf("Output (De-Interleave) :\n");
	printf("\t");
	for (u32Idx = 0; u32Idx < 16; ++u32Idx)
	{
		printf("%4d ", as8DataOutDeInterleave[u32Idx]);
	}
	printf("\n");
	printf("Output Part (1) : ");
	for (u32Idx = 0; u32Idx < 8; ++u32Idx)
	{
		printf("%4d ", as8DataOutDeInterleave1[u32Idx]);
	}
	printf("\n");
	printf("Output Part (2) : ");
	for (u32Idx = 0; u32Idx < 8; ++u32Idx)
	{
		printf("%4d ", as8DataOutDeInterleave2[u32Idx]);
	}
	printf("\n");

	printf("========================================\n");
}

// -----------------------------------------------------------------------------
