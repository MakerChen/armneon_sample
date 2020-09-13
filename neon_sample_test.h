#ifndef _NEON_SAMPLE_TEST_
#define _NEON_SAMPLE_TEST_

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

#include "module/neon_sample.h"

// -----------------------------------------------------------------------------
void neon_sample_Add()
{
	NeonSample_Add_U8_U8_U8();
	NeonSample_Add_U16_U8_U8();
	NeonSample_Add_U16_U16_U16();
	NeonSample_Add_U32_U16_U16();
	NeonSample_Add_S8_S8_S8();
	NeonSample_Add_S16_S8_S8();
	NeonSample_Add_S16_S16_S16();
	NeonSample_Add_S32_S16_S16();
	NeonSample_Add_F32_F32_F32();
	NeonSample_Add_U8_U16_U16();
	NeonSample_Add_S8_S16_S16();
	NeonSample_Add_U16_U16_U8();
	NeonSample_Add_S16_S16_S8();
}

// -----------------------------------------------------------------------------
void neon_sample_AbsDiff()
{
	NeonSample_AbsDiff_U8_U8_U8();
	NeonSample_AbsDiff_S8_S8_S8();
	NeonSample_AbsDiff_U16_U8_U8();
	NeonSample_AbsDiff_S16_S8_S8();
	NeonSample_AbsDiff_F32_F32_F32();
	NeonSample_AbsDiff_U8_U8_U8_U8();
	NeonSample_AbsDiff_S8_S8_S8_S8();
	NeonSample_AbsDiff_U16_U16_U8_U8();
	NeonSample_AbsDiff_S16_S16_S8_S8();
}

// -----------------------------------------------------------------------------
void neon_sample_MaxMin()
{
	NeonSample_MaxMin_U8_U8_U8();
	NeonSample_MaxMin_S8_S8_S8();
	NeonSample_MaxMin_F32_F32_F32();
}

// -----------------------------------------------------------------------------
void neon_sample_Compare()
{
	NeonSample_Compare_U8_U8_U8();
	NeonSample_Compare_U8_S8_S8();
	NeonSample_Compare_U32_F32_F32();
}

// -----------------------------------------------------------------------------
void neon_sample_Bitwise()
{
	NeonSample_Bitwise_U8_U8();
	NeonSample_Bitwise_S8_S8();
	NeonSample_Bitwise_U8_U8_U8();
	NeonSample_Bitwise_S8_S8_S8();
	NeonSample_Bitwise_U8_U8_U8_U8();
	NeonSample_Bitwise_S8_S8_S8_S8();
	NeonSample_Bitwise_F32_U32_F32_F32();
	NeonSample_Bitwise_P8_U8_P8_P8();
}

// -----------------------------------------------------------------------------
void neon_sample_Sub()
{
	NeonSample_Sub_U8_U8_U8();
	NeonSample_Sub_S8_S8_S8();
	NeonSample_Sub_F32_F32_F32();
	NeonSample_Sub_U16_U8_U8();
	NeonSample_Sub_S16_S8_S8();
	NeonSample_Sub_U16_U16_U8();
	NeonSample_Sub_S16_S16_S8();
	NeonSample_Sub_U8_U16_U16();
	NeonSample_Sub_S8_S16_S16();
}

// -----------------------------------------------------------------------------
void neon_sample_ReciprocalSqrt()
{
	NeonSample_Reciprocal_F32_F32_F32();
	NeonSample_Reciprocal_F32_F32_F32_Example();
	NeonSample_Sqrt_F32_F32_F32();
	NeonSample_Sqrt_F32_F32_F32_Example();
}

// -----------------------------------------------------------------------------
void neon_sample_PairwiseAdd()
{
	NeonSample_PairwiseAdd_U8_U8_U8();
	NeonSample_PairwiseAdd_S8_S8_S8();
	NeonSample_PairwiseAdd_F32_F32_F32();
	NeonSample_PairwiseAdd_U16_U8();
	NeonSample_PairwiseAdd_S16_S8();
	NeonSample_PairwiseAdd_U16_U16_U8();
	NeonSample_PairwiseAdd_S16_S16_S8();
}

// -----------------------------------------------------------------------------
void neon_sample_Folding()
{
	NeonSample_Folding_U8_U8_U8();
	NeonSample_Folding_S8_S8_S8();
	NeonSample_Folding_F32_F32_F32();
}

// -----------------------------------------------------------------------------
void neon_sample_Multiple()
{
	NeonSample_Multiple_U8_U8_U8();
	NeonSample_Multiple_S8_S8_S8();
	NeonSample_Multiple_U8_U8_U8_U8();
	NeonSample_Multiple_S8_S8_S8_S8();
	NeonSample_Multiple_U16_U16_U8_U8();
	NeonSample_Multiple_S16_S16_S8_S8();
	NeonSample_Multiple_U16_U8_U8();
	NeonSample_Multiple_S16_S8_S8();
	NeonSample_Multiple_S16_S16_S16();
	NeonSample_Multiple_S32_S32_S16_S16();
	NeonSample_Multiple_S32_S16_S16();
	NeonSample_Multiple_S64_S32_S32();
	NeonSample_Multiple_F32_F32_F32();
	NeonSample_Multiple_F32_F32_F32_F32();
	NeonSample_Multiple_P16_P8_P8();
}

// -----------------------------------------------------------------------------
void neon_sample_ShiftSignedVariable()
{
	NeonSample_ShiftSigned_U8_U8_U8();
	NeonSample_ShiftSigned_S8_S8_S8();
}

// -----------------------------------------------------------------------------
void neon_sample_ShiftConstant()
{
	NeonSample_ShiftConstant_U8_U8_SU8();
	NeonSample_ShiftConstant_S8_S8_SU8();
	NeonSample_ShiftConstant_U8_S8_SU8();
	NeonSample_ShiftConstant_U8_U16_SU8();
	NeonSample_ShiftConstant_S8_S16_SU8();
	NeonSample_ShiftConstant_U8_S16_SU8();
	NeonSample_ShiftConstant_U16_U8_SU8();
	NeonSample_ShiftConstant_S16_S8_SU8();
	NeonSample_ShiftConstant_U8_U8_U8_SU8();
	NeonSample_ShiftConstant_S8_S8_S8_SU8();
}

// -----------------------------------------------------------------------------
void neon_sample_ShiftInsert()
{
	NeonSample_ShiftInsert_U8_U8_U8_SU8();
	NeonSample_ShiftInsert_S8_S8_S8_SU8();
	NeonSample_ShiftInsert_P8_P8_P8_SU8();
}

// -----------------------------------------------------------------------------
void neon_sample_Combine()
{
	NeonSample_Combine_U8_U8_U8();
	NeonSample_Combine_S8_S8_S8();
	NeonSample_Combine_F32_F32_F32();
	NeonSample_Combine_P8_P8_P8();
}

// -----------------------------------------------------------------------------
void neon_sample_Split()
{
	NeonSample_Split_U8_U8();
	NeonSample_Split_S8_S8();
	NeonSample_Split_F32_F32();
	NeonSample_Split_P8_P8();
}

// -----------------------------------------------------------------------------
void neon_sample_Convert()
{
	NeonSample_Convert_U32_F32();
	NeonSample_Convert_S32_F32();
	NeonSample_Convert_U32_F32_SU8();
	NeonSample_Convert_S32_F32_SU8();
	NeonSample_Convert_F32_U32();
	NeonSample_Convert_F32_S32();
	NeonSample_Convert_F32_U32_SU8();
	NeonSample_Convert_F32_S32_SU8();
	NeonSample_Convert_U16_U8();
	NeonSample_Convert_S16_S8();
	NeonSample_Convert_F16_F32();
	NeonSample_Convert_F32_F16();
	NeonSample_Convert_U8_S16();
	NeonSample_Convert_U8_U16();
	NeonSample_Convert_S8_S16();
}

// -----------------------------------------------------------------------------
void neon_sample_ExtractLanes()
{
	NeonSample_ExtractLanes_U8_U8_SU8();
	NeonSample_ExtractLanes_S8_S8_SU8();
	NeonSample_ExtractLanes_F32_F32_SU8();
	NeonSample_ExtractLanes_P8_P8_SU8();
}

// -----------------------------------------------------------------------------
void neon_sample_InitialLiteral()
{
	NeonSample_InitialLiteral_U8_SU64();
	NeonSample_InitialLiteral_S8_SU64();
	NeonSample_InitialLiteral_F32_SU64();
	NeonSample_InitialLiteral_P8_SU64();
}

// -----------------------------------------------------------------------------
void neon_sample_ScalarValue()
{
	NeonSample_ScalarValue_U16_U16_U16_SU16_SU8();
	NeonSample_ScalarValue_S16_S16_S16_SS16_SU8();
	NeonSample_ScalarValue_F32_F32_F32_F32_SU8();
	NeonSample_ScalarValue_U32_U32_U16_U16_SU8();
	NeonSample_ScalarValue_S32_S32_S16_S16_SU8();
	NeonSample_ScalarValue_U16_U16_SU16();
	NeonSample_ScalarValue_S16_S16_SS16();
	NeonSample_ScalarValue_F32_F32_SF32();
	NeonSample_ScalarValue_U32_U16_SU16();
	NeonSample_ScalarValue_S32_S16_SS16();
	NeonSample_ScalarValue_U32_U16_U16_SU8();
	NeonSample_ScalarValue_S32_S16_S16_SU8();
	NeonSample_ScalarValue_S16_S16_S16_SU8();
	NeonSample_ScalarValue_U16_U16_U16_SU16();
	NeonSample_ScalarValue_S16_S16_S16_SS16();
	NeonSample_ScalarValue_F32_F32_F32_SF32();
	NeonSample_ScalarValue_U32_U32_U16_SU16();
	NeonSample_ScalarValue_S32_S32_S16_SS16();
}

// -----------------------------------------------------------------------------
void neon_sample_LoadLaneFromLiteral()
{
	NeonSample_LoadLaneFromLiteral_U8_SU8_U8_SU8();
	NeonSample_LoadLaneFromLiteral_S8_SS8_S8_SU8();
	NeonSample_LoadLaneFromLiteral_P8_SP8_P8_SU8();
	NeonSample_LoadLaneFromLiteral_F32_SF32_F32_SU8();
}

// -----------------------------------------------------------------------------
void neon_sample_VectorExtraction()
{
	NeonSample_VectorExtraction_U8_U8_U8_SU8();
	NeonSample_VectorExtraction_S8_S8_S8_SU8();
	NeonSample_VectorExtraction_P8_P8_P8_SU8();
}

// -----------------------------------------------------------------------------
void neon_sample_SetLanesToValue()
{
	NeonSample_SetLanesToValue_U8_SU8();
	NeonSample_SetLanesToValue_S8_SS8();
	NeonSample_SetLanesToValue_P8_SP8();
	NeonSample_SetLanesToValue_F32_SF32();
	NeonSample_SetLanesToValue_U8_U8_SU8();
	NeonSample_SetLanesToValue_S8_S8_SU8();
	NeonSample_SetLanesToValue_P8_P8_SU8();
	NeonSample_SetLanesToValue_F32_F32_SU8();
}

// -----------------------------------------------------------------------------
void neon_sample_ReverseVectorElements()
{
	NeonSample_ReverseVectorElements_U8_U8();
	NeonSample_ReverseVectorElements_S8_S8();
	NeonSample_ReverseVectorElements_P8_P8();
	NeonSample_ReverseVectorElements_F32_F32();
}

// -----------------------------------------------------------------------------
void neon_sample_SingleOperandArithemetic()
{
	NeonSample_SingleOperandArithemetic_S8_S8();
	NeonSample_SingleOperandArithemetic_F32_F32();
	NeonSample_SingleOperandArithemetic_U8_U8_v2();
	NeonSample_SingleOperandArithemetic_S8_S8_v2();
	NeonSample_SingleOperandArithemetic_P8_P8_v2();
	NeonSample_SingleOperandArithemetic_U32_U32_v3();	// need verify
	NeonSample_SingleOperandArithemetic_F32_F32_v3();
}

// -----------------------------------------------------------------------------
void neon_sample_Transposition()
{
	NeonSample_Transposition_U82_U8_U8();
	NeonSample_Transposition_S82_S8_S8();
}

// -----------------------------------------------------------------------------
void neon_sample_LoadStore()
{
	NeonSample_LoadStore_U8_PU8();
	NeonSample_LoadStore_S8_PS8();
	NeonSample_LoadStore_F32_PF32();
	NeonSample_LoadStore_P8_PP8();
	NeonSample_LoadStore_U8_PU8_U8_SU8();
	NeonSample_LoadStore_S8_PS8_S8_SU8();
	NeonSample_LoadStore_F32_PF32_F32_SU8();
	NeonSample_LoadStore_P8_PP8_P8_SU8();
	NeonSample_LoadStore_U8_PSU8();
	NeonSample_LoadStore_S8_PSS8();
	NeonSample_LoadStore_F32_PSF32();
	NeonSample_LoadStore_P8_PSP8();
}

// -----------------------------------------------------------------------------
void neon_sample_LoadStoreElements()
{
	NeonSample_LoadStoreElements_U82_U8();
	NeonSample_LoadStoreElements_S82_S8();
	NeonSample_LoadStoreElements_U82_U8_v2();
	NeonSample_LoadStoreElements_S82_S8_v2();
	NeonSample_LoadStoreElements_U82_U8_U82_SU8();
	NeonSample_LoadStoreElements_S82_S8_S82_SU8();
	NeonSample_LoadStoreElements_X_U8_U82_SU8();
	NeonSample_LoadStoreElements_X_S8_S82_SU8();
}

// -----------------------------------------------------------------------------
void neon_sample_TableLookUp()
{
	NeonSample_TableLookUp_U8_U8_U8();
	NeonSample_TableLookUp_S8_S8_S8();
	NeonSample_TableLookUp_P8_P8_U8();
	NeonSample_TableLookUp_U8_U82_U8();
	NeonSample_TableLookUp_S8_S82_S8();
	NeonSample_TableLookUp_P8_P82_U8();
	NeonSample_TableLookUp_U8_U8_U8_U8();
	NeonSample_TableLookUp_S8_S8_S8_S8();
	NeonSample_TableLookUp_P8_P8_P8_U8();
	NeonSample_TableLookUp_U8_U8_U82_U8();
	NeonSample_TableLookUp_S8_S8_S82_S8();
	NeonSample_TableLookUp_P8_P8_P82_U8();
}

// -----------------------------------------------------------------------------
void neon_sample_VectorCast()
{
	NeonSample_VectorCast_U8_S8();
	NeonSample_VectorCast_U8_S16();
	NeonSample_VectorCast_U8_U16();
	NeonSample_VectorCast_U8_F32();
	NeonSample_VectorCast_U8_P8();
	NeonSample_VectorCast_U8_P16();

	NeonSample_VectorCast_U16_S8();
	NeonSample_VectorCast_U16_S16();
	NeonSample_VectorCast_U16_U8();	
	NeonSample_VectorCast_U16_F32();
	NeonSample_VectorCast_U16_P8();
	NeonSample_VectorCast_U16_P16();

	NeonSample_VectorCast_S8_S16();
	NeonSample_VectorCast_S8_F32();
	NeonSample_VectorCast_S8_U8();
	NeonSample_VectorCast_S8_U16();
	NeonSample_VectorCast_S8_P8();
	NeonSample_VectorCast_S8_P16();

	NeonSample_VectorCast_S16_S8();
	NeonSample_VectorCast_S16_F32();
	NeonSample_VectorCast_S16_U8();
	NeonSample_VectorCast_S16_U16();
	NeonSample_VectorCast_S16_P8();
	NeonSample_VectorCast_S16_P16();

	NeonSample_VectorCast_F32_S8();
	NeonSample_VectorCast_F32_S16();
	NeonSample_VectorCast_F32_U8();
	NeonSample_VectorCast_F32_U16();
	NeonSample_VectorCast_F32_P8();
	NeonSample_VectorCast_F32_P16();

	NeonSample_VectorCast_P8_S8();
	NeonSample_VectorCast_P8_S16();
	NeonSample_VectorCast_P8_F32();
	NeonSample_VectorCast_P8_U8();
	NeonSample_VectorCast_P8_U16();
	NeonSample_VectorCast_P8_P16();

	NeonSample_VectorCast_P16_S8();
	NeonSample_VectorCast_P16_S16();
	NeonSample_VectorCast_P16_F32();
	NeonSample_VectorCast_P16_U8();
	NeonSample_VectorCast_P16_U16();
	NeonSample_VectorCast_P16_P8();
}

// -----------------------------------------------------------------------------

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // _NEON_SAMPLE_TEST_
