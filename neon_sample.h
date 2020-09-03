#ifndef __ARM_NEON_SAMPLE__
#define __ARM_NEON_SAMPLE__

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <math.h>

#ifndef _INTEL_SIMU_
#	include <arm_neon.h>
#else
	// https://github.com/intel/ARM_NEON_2_x86_SSE
#	include "NEON_2_SSE.h"
#endif // _INTEL_SIMU_

#include "neon_sample_macro.h"

// -----------------------------------------------------------------------------
void NeonSample_Add_U8_U8_U8();
void NeonSample_Add_U16_U8_U8();
void NeonSample_Add_U16_U16_U16();
void NeonSample_Add_U32_U16_U16();
void NeonSample_Add_S8_S8_S8();
void NeonSample_Add_S16_S8_S8();
void NeonSample_Add_S16_S16_S16();
void NeonSample_Add_S32_S16_S16();
void NeonSample_Add_F32_F32_F32();
void NeonSample_Add_U8_U16_U16();
void NeonSample_Add_S8_S16_S16();
void NeonSample_Add_U16_U16_U8();
void NeonSample_Add_S16_S16_S8();

// -----------------------------------------------------------------------------
void NeonSample_Multiple_U8_U8_U8();
void NeonSample_Multiple_S8_S8_S8();
void NeonSample_Multiple_U8_U8_U8_U8();
void NeonSample_Multiple_S8_S8_S8_S8();
void NeonSample_Multiple_U16_U16_U8_U8();
void NeonSample_Multiple_S16_S16_S8_S8();
void NeonSample_Multiple_U16_U8_U8();
void NeonSample_Multiple_S16_S8_S8();
void NeonSample_Multiple_S16_S16_S16();
void NeonSample_Multiple_S32_S32_S16_S16();
void NeonSample_Multiple_S32_S16_S16();
void NeonSample_Multiple_S64_S32_S32();
void NeonSample_Multiple_F32_F32_F32();
void NeonSample_Multiple_F32_F32_F32_F32();
void NeonSample_Multiple_P16_P8_P8();

// -----------------------------------------------------------------------------
void NeonSample_Sub_U8_U8_U8();
void NeonSample_Sub_S8_S8_S8();
void NeonSample_Sub_F32_F32_F32();
void NeonSample_Sub_U16_U8_U8();
void NeonSample_Sub_S16_S8_S8();
void NeonSample_Sub_U16_U16_U8();
void NeonSample_Sub_S16_S16_S8();
void NeonSample_Sub_U8_U16_U16();
void NeonSample_Sub_S8_S16_S16();

// -----------------------------------------------------------------------------
void NeonSample_Compare_U8_U8_U8();
void NeonSample_Compare_U8_S8_S8();

// -----------------------------------------------------------------------------
void NeonSample_AbsDiff_U8_U8_U8();
void NeonSample_AbsDiff_S8_S8_S8();
void NeonSample_AbsDiff_U16_U8_U8();
void NeonSample_AbsDiff_S16_S8_S8();
void NeonSample_AbsDiff_F32_F32_F32();
void NeonSample_AbsDiff_U8_U8_U8_U8();
void NeonSample_AbsDiff_S8_S8_S8_S8();
void NeonSample_AbsDiff_U16_U16_U8_U8();
void NeonSample_AbsDiff_S16_S16_S8_S8();

// -----------------------------------------------------------------------------
void NeonSample_MaxMin_U8_U8_U8();
void NeonSample_MaxMin_S8_S8_S8();
void NeonSample_MaxMin_F32_F32_F32();

// -----------------------------------------------------------------------------
void NeonSample_PairwiseAdd_U8_U8_U8();
void NeonSample_PairwiseAdd_S8_S8_S8();
void NeonSample_PairwiseAdd_F32_F32_F32();
void NeonSample_PairwiseAdd_U16_U8();
void NeonSample_PairwiseAdd_S16_S8();
void NeonSample_PairwiseAdd_U16_U16_U8();
void NeonSample_PairwiseAdd_S16_S16_S8();

// -----------------------------------------------------------------------------
void NeonSample_Folding_U8_U8_U8();
void NeonSample_Folding_S8_S8_S8();
void NeonSample_Folding_F32_F32_F32();

// -----------------------------------------------------------------------------
void NeonSample_Reciprocal_F32_F32_F32();
void NeonSample_Reciprocal_F32_F32_F32_Example();
void NeonSample_Sqrt_F32_F32_F32();
void NeonSample_Sqrt_F32_F32_F32_Example();

// -----------------------------------------------------------------------------
void NeonSample_ShiftSigned_U8_U8_U8();
void NeonSample_ShiftSigned_S8_S8_S8();

// -----------------------------------------------------------------------------
void NeonSample_ShiftConstant_U8_U8_SU8();
void NeonSample_ShiftConstant_S8_S8_SU8();
void NeonSample_ShiftConstant_U8_S8_SU8();
void NeonSample_ShiftConstant_U8_U16_SU8();
void NeonSample_ShiftConstant_S8_S16_SU8();
void NeonSample_ShiftConstant_U8_S16_SU8();
void NeonSample_ShiftConstant_U16_U8_SU8();
void NeonSample_ShiftConstant_S16_S8_SU8();
void NeonSample_ShiftConstant_U8_U8_U8_SU8();
void NeonSample_ShiftConstant_S8_S8_S8_SU8();

// -----------------------------------------------------------------------------
void NeonSample_ShiftInsert_U8_U8_U8_SU8();
void NeonSample_ShiftInsert_S8_S8_S8_SU8();
void NeonSample_ShiftInsert_P8_P8_P8_SU8();

// -----------------------------------------------------------------------------
void NeonSample_LoadStore_U8_PU8();
void NeonSample_LoadStore_S8_PS8();
void NeonSample_LoadStore_F32_PF32();
void NeonSample_LoadStore_P8_PP8();
void NeonSample_LoadStore_U8_PU8_U8_SU8();
void NeonSample_LoadStore_S8_PS8_S8_SU8();
void NeonSample_LoadStore_F32_PF32_F32_SU8();
void NeonSample_LoadStore_P8_PP8_P8_SU8();
void NeonSample_LoadStore_U8_PSU8();
void NeonSample_LoadStore_S8_PSS8();
void NeonSample_LoadStore_F32_PSF32();
void NeonSample_LoadStore_P8_PSP8();

// -----------------------------------------------------------------------------
void NeonSample_LoadStoreElements_U82_U8();
void NeonSample_LoadStoreElements_S82_S8();
void NeonSample_LoadStoreElements_U82_U8_v2();
void NeonSample_LoadStoreElements_S82_S8_v2();
void NeonSample_LoadStoreElements_U82_U8_U82_SU8();
void NeonSample_LoadStoreElements_S82_S8_S82_SU8();
void NeonSample_LoadStoreElements_X_U8_U82_SU8();
void NeonSample_LoadStoreElements_X_S8_S82_SU8();

// -----------------------------------------------------------------------------
void NeonSample_ExtractLanes_U8_U8_SU8();
void NeonSample_ExtractLanes_S8_S8_SU8();
void NeonSample_ExtractLanes_F32_F32_SU8();
void NeonSample_ExtractLanes_P8_P8_SU8();

// -----------------------------------------------------------------------------
void NeonSample_LoadLaneFromLiteral_U8_SU8_U8_SU8();
void NeonSample_LoadLaneFromLiteral_S8_SS8_S8_SU8();
void NeonSample_LoadLaneFromLiteral_P8_SP8_P8_SU8();
void NeonSample_LoadLaneFromLiteral_F32_SF32_F32_SU8();

// -----------------------------------------------------------------------------
void NeonSample_InitialLiteral_U8_SU64();
void NeonSample_InitialLiteral_S8_SU64();
void NeonSample_InitialLiteral_F32_SU64();
void NeonSample_InitialLiteral_P8_SU64();

// -----------------------------------------------------------------------------
void NeonSample_SetLanesToValue_U8_SU8();
void NeonSample_SetLanesToValue_S8_SS8();
void NeonSample_SetLanesToValue_P8_SP8();
void NeonSample_SetLanesToValue_F32_SF32();
void NeonSample_SetLanesToValue_U8_U8_SU8();
void NeonSample_SetLanesToValue_S8_S8_SU8();
void NeonSample_SetLanesToValue_P8_P8_SU8();
void NeonSample_SetLanesToValue_F32_F32_SU8();

// -----------------------------------------------------------------------------
void NeonSample_Combine_U8_U8_U8();
void NeonSample_Combine_S8_S8_S8();
void NeonSample_Combine_F32_F32_F32();
void NeonSample_Combine_P8_P8_P8();

// -----------------------------------------------------------------------------
void NeonSample_Split_U8_U8();
void NeonSample_Split_S8_S8();
void NeonSample_Split_F32_F32();
void NeonSample_Split_P8_P8();

// -----------------------------------------------------------------------------
void NeonSample_Convert_U32_F32();
void NeonSample_Convert_S32_F32();
void NeonSample_Convert_U32_F32_SU8();
void NeonSample_Convert_S32_F32_SU8();
void NeonSample_Convert_F32_U32();
void NeonSample_Convert_F32_S32();
void NeonSample_Convert_F32_U32_SU8();
void NeonSample_Convert_F32_S32_SU8();
void NeonSample_Convert_U16_U8();
void NeonSample_Convert_S16_S8();
void NeonSample_Convert_F16_F32();
void NeonSample_Convert_F32_F16();
void NeonSample_Convert_U8_S16();
void NeonSample_Convert_U8_U16();
void NeonSample_Convert_S8_S16();

// -----------------------------------------------------------------------------
void NeonSample_TableLookUp_U8_U8_U8();
void NeonSample_TableLookUp_S8_S8_S8();
void NeonSample_TableLookUp_P8_P8_U8();
void NeonSample_TableLookUp_U8_U82_U8();
void NeonSample_TableLookUp_S8_S82_S8();
void NeonSample_TableLookUp_P8_P82_U8();
void NeonSample_TableLookUp_U8_U8_U8_U8();
void NeonSample_TableLookUp_S8_S8_S8_S8();
void NeonSample_TableLookUp_P8_P8_P8_U8();
void NeonSample_TableLookUp_U8_U8_U82_U8();
void NeonSample_TableLookUp_S8_S8_S82_S8();
void NeonSample_TableLookUp_P8_P8_P82_U8();

// -----------------------------------------------------------------------------
void NeonSample_ScalarValue_U16_U16_U16_SU16_SU8();
void NeonSample_ScalarValue_S16_S16_S16_SS16_SU8();
void NeonSample_ScalarValue_F32_F32_F32_F32_SU8();
void NeonSample_ScalarValue_U32_U32_U16_U16_SU8();
void NeonSample_ScalarValue_S32_S32_S16_S16_SU8();
void NeonSample_ScalarValue_U16_U16_SU16();
void NeonSample_ScalarValue_S16_S16_SS16();
void NeonSample_ScalarValue_F32_F32_SF32();
void NeonSample_ScalarValue_U32_U16_SU16();
void NeonSample_ScalarValue_S32_S16_SS16();
void NeonSample_ScalarValue_U32_U16_U16_SU8();
void NeonSample_ScalarValue_S32_S16_S16_SU8();
void NeonSample_ScalarValue_S16_S16_S16_SU8();
void NeonSample_ScalarValue_U16_U16_U16_SU16();
void NeonSample_ScalarValue_S16_S16_S16_SS16();
void NeonSample_ScalarValue_F32_F32_F32_SF32();
void NeonSample_ScalarValue_U32_U32_U16_SU16();
void NeonSample_ScalarValue_S32_S32_S16_SS16();

// -----------------------------------------------------------------------------
void NeonSample_VectorExtraction_U8_U8_U8_SU8();
void NeonSample_VectorExtraction_S8_S8_S8_SU8();
void NeonSample_VectorExtraction_P8_P8_P8_SU8();

// -----------------------------------------------------------------------------
void NeonSample_ReverseVectorElements_U8_U8();
void NeonSample_ReverseVectorElements_S8_S8();
void NeonSample_ReverseVectorElements_P8_P8();
void NeonSample_ReverseVectorElements_F32_F32();

// -----------------------------------------------------------------------------
void NeonSample_SingleOperandArithemetic_S8_S8();
void NeonSample_SingleOperandArithemetic_F32_F32();
void NeonSample_SingleOperandArithemetic_U8_U8_v2();
void NeonSample_SingleOperandArithemetic_S8_S8_v2();
void NeonSample_SingleOperandArithemetic_P8_P8_v2();
void NeonSample_SingleOperandArithemetic_U32_U32_v3();		//
void NeonSample_SingleOperandArithemetic_F32_F32_v3();

// -----------------------------------------------------------------------------
void NeonSample_Bitwise_U8_U8();
void NeonSample_Bitwise_S8_S8();
void NeonSample_Bitwise_U8_U8_U8();
void NeonSample_Bitwise_S8_S8_S8();
void NeonSample_Bitwise_U8_U8_U8_U8();
void NeonSample_Bitwise_S8_S8_S8_S8();
void NeonSample_Bitwise_F32_U32_F32_F32();
void NeonSample_Bitwise_P8_U8_P8_P8();

// -----------------------------------------------------------------------------
void NeonSample_Transposition_U82_U8_U8();
void NeonSample_Transposition_S82_S8_S8();

// -----------------------------------------------------------------------------
void NeonSample_VectorCast_U8_S8();
void NeonSample_VectorCast_U8_S16();
void NeonSample_VectorCast_U8_U16();
void NeonSample_VectorCast_U8_F32();		//
void NeonSample_VectorCast_U8_P8();
void NeonSample_VectorCast_U8_P16();

void NeonSample_VectorCast_U16_S8();
void NeonSample_VectorCast_U16_S16();
void NeonSample_VectorCast_U16_U8();
void NeonSample_VectorCast_U16_F32();		//
void NeonSample_VectorCast_U16_P8();
void NeonSample_VectorCast_U16_P16();

void NeonSample_VectorCast_S8_S16();
void NeonSample_VectorCast_S8_F32();		//
void NeonSample_VectorCast_S8_U8();
void NeonSample_VectorCast_S8_U16();
void NeonSample_VectorCast_S8_P8();
void NeonSample_VectorCast_S8_P16();

void NeonSample_VectorCast_S16_S8();
void NeonSample_VectorCast_S16_F32();		//
void NeonSample_VectorCast_S16_U8();
void NeonSample_VectorCast_S16_U16();
void NeonSample_VectorCast_S16_P8();
void NeonSample_VectorCast_S16_P16();

void NeonSample_VectorCast_F32_S8();		//
void NeonSample_VectorCast_F32_S16();		//
void NeonSample_VectorCast_F32_U8();		//
void NeonSample_VectorCast_F32_U16();		//
void NeonSample_VectorCast_F32_P8();		//
void NeonSample_VectorCast_F32_P16();		//

void NeonSample_VectorCast_P8_S8();
void NeonSample_VectorCast_P8_S16();
void NeonSample_VectorCast_P8_F32();		//
void NeonSample_VectorCast_P8_U8();
void NeonSample_VectorCast_P8_U16();
void NeonSample_VectorCast_P8_P16();

void NeonSample_VectorCast_P16_S8();
void NeonSample_VectorCast_P16_S16();
void NeonSample_VectorCast_P16_F32();		//
void NeonSample_VectorCast_P16_U8();
void NeonSample_VectorCast_P16_U16();
void NeonSample_VectorCast_P16_P8();

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // __ARM_NEON_SAMPLE__
