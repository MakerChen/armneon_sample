#include "neon_sample.h"

// https://developer.arm.com/documentation/dui0472/m/using-neon-support/neon-intrinsics-for-loading-an-n-element-structure

// -----------------------------------------------------------------------------
void NeonSample_LoadStoreElements_U82_U8()
{
	uint8_t			au8DataIn[16];
	uint8_t			au8DataInP1[8];
	uint8_t			au8DataInP2[8];
	uint8_t			au8DataOut[16];

	uint8x8x2_t		vu8x8x2Input;
	uint8x8_t		vu8x8InputP1;
	uint8x8_t		vu8x8InputP2;

	uint32_t		u32Idx;

	// initial
	au8DataIn[0] = 1;
	au8DataIn[1] = 2;
	au8DataIn[2] = 3;
	au8DataIn[3] = 4;
	au8DataIn[4] = 5;
	au8DataIn[5] = 6;
	au8DataIn[6] = 7;
	au8DataIn[7] = 8;
	au8DataIn[8] = 10;
	au8DataIn[9] = 20;
	au8DataIn[10] = 30;
	au8DataIn[11] = 40;
	au8DataIn[12] = 50;
	au8DataIn[13] = 60;
	au8DataIn[14] = 70;
	au8DataIn[15] = 80;

	// uint8x8x2_t vld2_u8(__transfersize(16) uint8_t const * ptr);				// VLD2.8 {d0, d1}, [r0]
	vu8x8x2Input	= vld2_u8(au8DataIn);
	vu8x8InputP1	= vu8x8x2Input.val[0];
	vu8x8InputP2	= vu8x8x2Input.val[1];

	vst1_u8(au8DataInP1, vu8x8InputP1);
	vst1_u8(au8DataInP2, vu8x8InputP2);

	// void vst2_u8(__transfersize(16) uint8_t * ptr, uint8x8x2_t val);			// VST2.8 {d0, d1}, [r0]
	vst2_u8(au8DataOut, vu8x8x2Input);

	printf("== Load/Store Elements u82 = u8 (vld2_u8 / vst2_u8) ==\n");
	printf("Input :\n");
	for (u32Idx = 0; u32Idx < 16; ++u32Idx)
	{
		printf("%3d ", au8DataIn[u32Idx]);
	}
	printf("\n");
	printf("Load Part (1) :\n");
	for (u32Idx = 0; u32Idx < 8; ++u32Idx)
	{
		printf("%3d ", au8DataInP1[u32Idx]);
	}
	printf("\n");
	printf("Load Part (2) :\n");
	for (u32Idx = 0; u32Idx < 8; ++u32Idx)
	{
		printf("%3d ", au8DataInP2[u32Idx]);
	}
	printf("\n");
	printf("Output :\n");
	for (u32Idx = 0; u32Idx < 16; ++u32Idx)
	{
		printf("%3d ", au8DataOut[u32Idx]);
	}
	printf("\n");
	printf("========================================\n");
}

// -----------------------------------------------------------------------------
void NeonSample_LoadStoreElements_S82_S8()
{
	int8_t			as8DataIn[16];
	int8_t			as8DataInP1[8];
	int8_t			as8DataInP2[8];
	int8_t			as8DataOut[16];

	int8x8x2_t		vs8x8x2Input;
	int8x8_t		vs8x8InputP1;
	int8x8_t		vs8x8InputP2;

	uint32_t		u32Idx;

	// initial
	as8DataIn[0] = 1;
	as8DataIn[1] = 2;
	as8DataIn[2] = 3;
	as8DataIn[3] = 4;
	as8DataIn[4] = 5;
	as8DataIn[5] = 6;
	as8DataIn[6] = 7;
	as8DataIn[7] = 8;
	as8DataIn[8] = -10;
	as8DataIn[9] = -20;
	as8DataIn[10] = -30;
	as8DataIn[11] = -40;
	as8DataIn[12] = -50;
	as8DataIn[13] = -60;
	as8DataIn[14] = -70;
	as8DataIn[15] = -80;

	// int8x8x2_t vld2_s8(__transfersize(16) int8_t const * ptr);				// VLD2.8 {d0, d1}, [r0]
	vs8x8x2Input	= vld2_s8(as8DataIn);
	vs8x8InputP1	= vs8x8x2Input.val[0];
	vs8x8InputP2	= vs8x8x2Input.val[1];

	vst1_s8(as8DataInP1, vs8x8InputP1);
	vst1_s8(as8DataInP2, vs8x8InputP2);

	// void vst2_s8(__transfersize(16) int8_t * ptr, int8x8x2_t val);			// VST2.8 {d0, d1}, [r0]
	vst2_s8(as8DataOut, vs8x8x2Input);

	printf("== Load/Store Elements s82 = s8 (vld2_s8 / vst2_s8) ==\n");
	printf("Input :\n");
	for (u32Idx = 0; u32Idx < 16; ++u32Idx)
	{
		printf("%4d ", as8DataIn[u32Idx]);
	}
	printf("\n");
	printf("Load Part (1) :\n");
	for (u32Idx = 0; u32Idx < 8; ++u32Idx)
	{
		printf("%4d ", as8DataInP1[u32Idx]);
	}
	printf("\n");
	printf("Load Part (2) :\n");
	for (u32Idx = 0; u32Idx < 8; ++u32Idx)
	{
		printf("%4d ", as8DataInP2[u32Idx]);
	}
	printf("\n");
	printf("Output :\n");
	for (u32Idx = 0; u32Idx < 16; ++u32Idx)
	{
		printf("%4d ", as8DataOut[u32Idx]);
	}
	printf("\n");
	printf("========================================\n");
}

// -----------------------------------------------------------------------------
void NeonSample_LoadStoreElements_U82_U8_v2()
{
	uint8_t			au8DataIn[2];
	uint8_t			au8DataInP1[8];
	uint8_t			au8DataInP2[8];
	uint8_t			au8DataOut[16];

	uint8x8x2_t		vu8x8x2Input;
	uint8x8_t		vu8x8InputP1;
	uint8x8_t		vu8x8InputP2;

	uint32_t		u32Idx;

	// initial
	au8DataIn[0] = 100;
	au8DataIn[1] = 200;

	// uint8x8x2_t vld2_dup_u8(__transfersize(2) uint8_t const * ptr);			// VLD2.8 {d0[], d1[]}, [r0]
	vu8x8x2Input	= vld2_dup_u8(au8DataIn);
	vu8x8InputP1	= vu8x8x2Input.val[0];
	vu8x8InputP2	= vu8x8x2Input.val[1];

	vst1_u8(au8DataInP1, vu8x8InputP1);
	vst1_u8(au8DataInP2, vu8x8InputP2);

	// void vst2_u8(__transfersize(16) uint8_t * ptr, uint8x8x2_t val);			// VST2.8 {d0, d1}, [r0]
	vst2_u8(au8DataOut, vu8x8x2Input);

	printf("== Load/Store Elements u82 = u8[2] (vld2_dup_u8 / vst2_u8) ==\n");
	printf("Input :\n");
	for (u32Idx = 0; u32Idx < 2; ++u32Idx)
	{
		printf("%3d ", au8DataIn[u32Idx]);
	}
	printf("\n");
	printf("Load Part (1) :\n");
	for (u32Idx = 0; u32Idx < 8; ++u32Idx)
	{
		printf("%3d ", au8DataInP1[u32Idx]);
	}
	printf("\n");
	printf("Load Part (2) :\n");
	for (u32Idx = 0; u32Idx < 8; ++u32Idx)
	{
		printf("%3d ", au8DataInP2[u32Idx]);
	}
	printf("\n");
	printf("Output :\n");
	for (u32Idx = 0; u32Idx < 16; ++u32Idx)
	{
		printf("%3d ", au8DataOut[u32Idx]);
	}
	printf("\n");
	printf("========================================\n");
}

// -----------------------------------------------------------------------------
void NeonSample_LoadStoreElements_S82_S8_v2()
{
	int8_t			as8DataIn[2];
	int8_t			as8DataInP1[8];
	int8_t			as8DataInP2[8];
	int8_t			as8DataOut[16];

	int8x8x2_t		vs8x8x2Input;
	int8x8_t		vs8x8InputP1;
	int8x8_t		vs8x8InputP2;

	uint32_t		u32Idx;

	// initial
	as8DataIn[0] = 100;
	as8DataIn[1] = -100;

	// int8x8x2_t vld2_dup_s8(__transfersize(2) int8_t const * ptr);			// VLD2.8 {d0[], d1[]}, [r0]
	vs8x8x2Input	= vld2_dup_s8(as8DataIn);
	vs8x8InputP1	= vs8x8x2Input.val[0];
	vs8x8InputP2	= vs8x8x2Input.val[1];

	vst1_s8(as8DataInP1, vs8x8InputP1);
	vst1_s8(as8DataInP2, vs8x8InputP2);

	// void vst2_s8(__transfersize(16) int8_t * ptr, int8x8x2_t val);			// VST2.8 {d0, d1}, [r0]
	vst2_s8(as8DataOut, vs8x8x2Input);

	printf("== Load/Store Elements s82 = s8[2] (vld2_dup_s8 / vst2_s8) ==\n");
	printf("Input :\n");
	for (u32Idx = 0; u32Idx < 2; ++u32Idx)
	{
		printf("%4d ", as8DataIn[u32Idx]);
	}
	printf("\n");
	printf("Load Part (1) :\n");
	for (u32Idx = 0; u32Idx < 8; ++u32Idx)
	{
		printf("%4d ", as8DataInP1[u32Idx]);
	}
	printf("\n");
	printf("Load Part (2) :\n");
	for (u32Idx = 0; u32Idx < 8; ++u32Idx)
	{
		printf("%4d ", as8DataInP2[u32Idx]);
	}
	printf("\n");
	printf("Output :\n");
	for (u32Idx = 0; u32Idx < 16; ++u32Idx)
	{
		printf("%4d ", as8DataOut[u32Idx]);
	}
	printf("\n");
	printf("========================================\n");
}

// -----------------------------------------------------------------------------
void NeonSample_LoadStoreElements_U82_U8_U82_SU8()
{
	uint8_t			au8DataInA[2];
	uint8_t			au8DataInB[16];
	uint8_t			au8DataInBP1[8];
	uint8_t			au8DataInBP2[8];
	uint8_t			au8DataOut[16];
	uint8_t			au8DataOutP1[8];
	uint8_t			au8DataOutP2[8];

	uint8x8x2_t		vu8x8x2Input;
	uint8x8x2_t		vu8x8x2Output;

	uint8_t			u8CoefIndex;

	uint32_t		u32Idx;

	// initial
	au8DataInA[0] = 100;
	au8DataInA[1] = 200;

	au8DataInB[0] = 10;
	au8DataInB[1] = 20;
	au8DataInB[2] = 30;
	au8DataInB[3] = 40;
	au8DataInB[4] = 50;
	au8DataInB[5] = 60;
	au8DataInB[6] = 70;
	au8DataInB[7] = 80;
	au8DataInB[8] = 90;
	au8DataInB[9] = 100;
	au8DataInB[10] = 110;
	au8DataInB[11] = 120;
	au8DataInB[12] = 130;
	au8DataInB[13] = 140;
	au8DataInB[14] = 150;
	au8DataInB[15] = 160;

	u8CoefIndex = 3;

	vu8x8x2Input	= vld2_u8(au8DataInB);
	vst1_u8(au8DataInBP1, vu8x8x2Input.val[0]);
	vst1_u8(au8DataInBP2, vu8x8x2Input.val[1]);

	// uint8x8x2_t vld2_lane_u8(__transfersize(2) uint8_t const * ptr, uint8x8x2_t src, __constrange(0,7) int lane);	// VLD2.8 {d0[0], d1[0]}, [r0]
	vu8x8x2Output	= vld2_lane_u8(au8DataInA, vu8x8x2Input, u8CoefIndex);
	vst1_u8(au8DataOutP1, vu8x8x2Output.val[0]);
	vst1_u8(au8DataOutP2, vu8x8x2Output.val[1]);

	// void vst2_u8(__transfersize(16) uint8_t * ptr, uint8x8x2_t val);			// VST2.8 {d0, d1}, [r0]
	vst2_u8(au8DataOut, vu8x8x2Output);

	printf("== Load Elements u82 = u8[2], u82, su8 (vld2_lane_u8) ==\n");
	printf("=> r[*] = u82[*], (* != c)                            ==\n");
	printf("=> r[c] = u8[2]                                       ==\n");
	printf("Input (A):\n");
	for (u32Idx = 0; u32Idx < 2; ++u32Idx)
	{
		printf("%3d ", au8DataInA[u32Idx]);
	}
	printf("\n");
	printf("Input (B):\n");
	for (u32Idx = 0; u32Idx < 16; ++u32Idx)
	{
		printf("%3d ", au8DataInB[u32Idx]);
	}
	printf("\n");
	printf("Input (B) Part (1) :\n");
	for (u32Idx = 0; u32Idx < 8; ++u32Idx)
	{
		printf("%3d ", au8DataInBP1[u32Idx]);
	}
	printf("\n");
	printf("Input (B) Part (2) :\n");
	for (u32Idx = 0; u32Idx < 8; ++u32Idx)
	{
		printf("%3d ", au8DataInBP2[u32Idx]);
	}
	printf("\n");
	printf("Input (C): %1d\n", u8CoefIndex);

	printf("Output :\n");
	for (u32Idx = 0; u32Idx < 16; ++u32Idx)
	{
		printf("%3d ", au8DataOut[u32Idx]);
	}
	printf("\n");
	printf("Output Part (1) :\n");
	for (u32Idx = 0; u32Idx < 8; ++u32Idx)
	{
		printf("%3d ", au8DataOutP1[u32Idx]);
	}
	printf("\n");
	printf("Output Part (2) :\n");
	for (u32Idx = 0; u32Idx < 8; ++u32Idx)
	{
		printf("%3d ", au8DataOutP2[u32Idx]);
	}
	printf("\n");
	printf("========================================\n");
}

// -----------------------------------------------------------------------------
void NeonSample_LoadStoreElements_S82_S8_S82_SU8()
{
	int8_t			as8DataInA[2];
	int8_t			as8DataInB[16];
	int8_t			as8DataInBP1[8];
	int8_t			as8DataInBP2[8];
	int8_t			as8DataOut[16];
	int8_t			as8DataOutP1[8];
	int8_t			as8DataOutP2[8];

	int8x8x2_t		vs8x8x2Input;
	int8x8x2_t		vs8x8x2Output;

	uint8_t			u8CoefIndex;

	uint32_t		u32Idx;

	// initial
	as8DataInA[0] = 100;
	as8DataInA[1] = -100;

	as8DataInB[0] = 10;
	as8DataInB[1] = -10;
	as8DataInB[2] = 20;
	as8DataInB[3] = -20;
	as8DataInB[4] = 30;
	as8DataInB[5] = -30;
	as8DataInB[6] = 40;
	as8DataInB[7] = -40;
	as8DataInB[8] = 50;
	as8DataInB[9] = -50;
	as8DataInB[10] = 60;
	as8DataInB[11] = -60;
	as8DataInB[12] = 70;
	as8DataInB[13] = -70;
	as8DataInB[14] = 80;
	as8DataInB[15] = -80;

	u8CoefIndex = 3;

	vs8x8x2Input	= vld2_s8(as8DataInB);
	vst1_s8(as8DataInBP1, vs8x8x2Input.val[0]);
	vst1_s8(as8DataInBP2, vs8x8x2Input.val[1]);

	// int8x8x2_t vld2_lane_s8(__transfersize(2) int8_t const * ptr, int8x8x2_t src, __constrange(0,7) int lane);	// VLD2.8 {d0[0], d1[0]}, [r0]
	vs8x8x2Output	= vld2_lane_s8(as8DataInA, vs8x8x2Input, u8CoefIndex);
	vst1_s8(as8DataOutP1, vs8x8x2Output.val[0]);
	vst1_s8(as8DataOutP2, vs8x8x2Output.val[1]);

	// void vst2_s8(__transfersize(16) int8_t * ptr, int8x8x2_t val);			// VST2.8 {d0, d1}, [r0]
	vst2_s8(as8DataOut, vs8x8x2Output);

	printf("== Load Elements s82 = s8[2], s82, su8 (vld2_lane_s8) ==\n");
	printf("=> r[*] = s82[*], (* != c)                            ==\n");
	printf("=> r[c] = s8[2]                                       ==\n");
	printf("Input (A):\n");
	for (u32Idx = 0; u32Idx < 2; ++u32Idx)
	{
		printf("%4d ", as8DataInA[u32Idx]);
	}
	printf("\n");
	printf("Input (B):\n");
	for (u32Idx = 0; u32Idx < 16; ++u32Idx)
	{
		printf("%4d ", as8DataInB[u32Idx]);
	}
	printf("\n");
	printf("Input (B) Part (1) :\n");
	for (u32Idx = 0; u32Idx < 8; ++u32Idx)
	{
		printf("%4d ", as8DataInBP1[u32Idx]);
	}
	printf("\n");
	printf("Input (B) Part (2) :\n");
	for (u32Idx = 0; u32Idx < 8; ++u32Idx)
	{
		printf("%4d ", as8DataInBP2[u32Idx]);
	}
	printf("\n");
	printf("Input (C): %1d\n", u8CoefIndex);

	printf("Output :\n");
	for (u32Idx = 0; u32Idx < 16; ++u32Idx)
	{
		printf("%4d ", as8DataOut[u32Idx]);
	}
	printf("\n");
	printf("Output Part (1) :\n");
	for (u32Idx = 0; u32Idx < 8; ++u32Idx)
	{
		printf("%4d ", as8DataOutP1[u32Idx]);
	}
	printf("\n");
	printf("Output Part (2) :\n");
	for (u32Idx = 0; u32Idx < 8; ++u32Idx)
	{
		printf("%4d ", as8DataOutP2[u32Idx]);
	}
	printf("\n");
	printf("========================================\n");
}

// -----------------------------------------------------------------------------
void NeonSample_LoadStoreElements_X_U8_U82_SU8()
{
	uint8_t			au8DataIn[16];
	uint8_t			au8DataInP1[8];
	uint8_t			au8DataInP2[8];
	uint8_t			au8DataOut[2];

	uint8x8x2_t		vu8x8x2Input;

	uint8_t			u8CoefIndex;

	uint32_t		u32Idx;

	// initial
	au8DataIn[0] = 10;
	au8DataIn[1] = 20;
	au8DataIn[2] = 30;
	au8DataIn[3] = 40;
	au8DataIn[4] = 50;
	au8DataIn[5] = 60;
	au8DataIn[6] = 70;
	au8DataIn[7] = 80;
	au8DataIn[8] = 90;
	au8DataIn[9] = 100;
	au8DataIn[10] = 110;
	au8DataIn[11] = 120;
	au8DataIn[12] = 130;
	au8DataIn[13] = 140;
	au8DataIn[14] = 150;
	au8DataIn[15] = 160;

	u8CoefIndex = 4;

	vu8x8x2Input	= vld2_u8(au8DataIn);
	vst1_u8(au8DataInP1, vu8x8x2Input.val[0]);
	vst1_u8(au8DataInP2, vu8x8x2Input.val[1]);

	// void vst2_lane_u8(__transfersize(2) uint8_t * ptr, uint8x8x2_t val, __constrange(0,7) int lane);		// VST2.8 {d0[0], d1[0]}, [r0]
	vst2_lane_u8(au8DataOut, vu8x8x2Input, u8CoefIndex);

	printf("== Store Element u8[2] = u82, su8 (vst2_lane_u8) ==\n");
	printf("=> r[] = u82[u8]                                 ==\n");
	printf("Input (B):\n");
	for (u32Idx = 0; u32Idx < 16; ++u32Idx)
	{
		printf("%3d ", au8DataIn[u32Idx]);
	}
	printf("\n");
	printf("Input (B) Part (1) :\n");
	for (u32Idx = 0; u32Idx < 8; ++u32Idx)
	{
		printf("%3d ", au8DataInP1[u32Idx]);
	}
	printf("\n");
	printf("Input (B) Part (2) :\n");
	for (u32Idx = 0; u32Idx < 8; ++u32Idx)
	{
		printf("%3d ", au8DataInP2[u32Idx]);
	}
	printf("\n");
	printf("Input (C): %1d\n", u8CoefIndex);

	printf("Output :\n");
	for (u32Idx = 0; u32Idx < 2; ++u32Idx)
	{
		printf("%3d ", au8DataOut[u32Idx]);
	}
	printf("\n");
	printf("========================================\n");
}

// -----------------------------------------------------------------------------
void NeonSample_LoadStoreElements_X_S8_S82_SU8()
{
	int8_t			as8DataIn[16];
	int8_t			as8DataInP1[8];
	int8_t			as8DataInP2[8];
	int8_t			as8DataOut[2];

	int8x8x2_t		vs8x8x2Input;

	uint8_t			u8CoefIndex;

	uint32_t		u32Idx;

	// initial
	as8DataIn[0] = 10;
	as8DataIn[1] = -10;
	as8DataIn[2] = 20;
	as8DataIn[3] = -20;
	as8DataIn[4] = 30;
	as8DataIn[5] = -30;
	as8DataIn[6] = 40;
	as8DataIn[7] = -40;
	as8DataIn[8] = 50;
	as8DataIn[9] = -50;
	as8DataIn[10] = 60;
	as8DataIn[11] = -60;
	as8DataIn[12] = 70;
	as8DataIn[13] = -70;
	as8DataIn[14] = 80;
	as8DataIn[15] = -80;

	u8CoefIndex = 7;

	vs8x8x2Input	= vld2_s8(as8DataIn);
	vst1_s8(as8DataInP1, vs8x8x2Input.val[0]);
	vst1_s8(as8DataInP2, vs8x8x2Input.val[1]);

	// void vst2_lane_s8(__transfersize(2) int8_t * ptr, int8x8x2_t val, __constrange(0,7) int lane);	// VST2.8 {d0[0], d1[0]}, [r0]
	vst2_lane_s8(as8DataOut, vs8x8x2Input, u8CoefIndex);

	printf("== Store Element s8[2] = s82, su8 (vst2_lane_s8) ==\n");
	printf("=> r[] = s82[u8]                                 ==\n");
	printf("Input (B):\n");
	for (u32Idx = 0; u32Idx < 16; ++u32Idx)
	{
		printf("%4d ", as8DataIn[u32Idx]);
	}
	printf("\n");
	printf("Input (B) Part (1) :\n");
	for (u32Idx = 0; u32Idx < 8; ++u32Idx)
	{
		printf("%4d ", as8DataInP1[u32Idx]);
	}
	printf("\n");
	printf("Input (B) Part (2) :\n");
	for (u32Idx = 0; u32Idx < 8; ++u32Idx)
	{
		printf("%4d ", as8DataInP2[u32Idx]);
	}
	printf("\n");
	printf("Input (C): %1d\n", u8CoefIndex);

	printf("Output :\n");
	for (u32Idx = 0; u32Idx < 2; ++u32Idx)
	{
		printf("%4d ", as8DataOut[u32Idx]);
	}
	printf("\n");
	printf("========================================\n");
}

// -----------------------------------------------------------------------------
