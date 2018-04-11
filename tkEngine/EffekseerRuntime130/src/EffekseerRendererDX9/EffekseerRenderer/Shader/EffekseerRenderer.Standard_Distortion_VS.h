#if 0
//
// Generated by Microsoft (R) HLSL Shader Compiler 9.29.952.3111
//
//   fxc /Zpc /Tvs_2_0 /EVS /Fh
//    Shader/EffekseerRenderer.Standard_Distortion_VS.h
//    Shader/standard_renderer_distortion_VS.fx
//
//
// Parameters:
//
//   float4x4 mCamera;
//   float4x4 mProj;
//
//
// Registers:
//
//   Name         Reg   Size
//   ------------ ----- ----
//   mCamera      c0       4
//   mProj        c4       4
//

    vs_2_0
    dcl_position v0
    dcl_normal v1
    dcl_texcoord v2
    dcl_normal1 v3
    dcl_normal2 v4
    mov r0.xyz, v0
    add r1.xyz, r0, v3
    mul r2, r1.y, c1
    mad r2, c0, r1.x, r2
    mad r1, c2, r1.z, r2
    add r1, r1, c3
    rcp r0.w, r1.w
    mul r2, v0.y, c1
    mad r2, c0, v0.x, r2
    mad r2, c2, v0.z, r2
    add r2, r2, c3
    rcp r1.w, r2.w
    mul r3.xyz, r1.w, r2
    mad r1.xyz, r1, r0.w, -r3
    nrm r4.xyz, r1
    mad r1.xyz, r2, r1.w, r4
    mul r4, r1.y, c5
    mad r4, c4, r1.x, r4
    mad r4, c6, r1.z, r4
    add r4, r4, c7
    rcp r0.w, r4.w
    mul oT3, r0.w, r4
    add r0.xyz, r0, v4
    mul r4, r0.y, c1
    mad r4, c0, r0.x, r4
    mad r0, c2, r0.z, r4
    add r0, r0, c3
    rcp r0.w, r0.w
    mad r0.xyz, r0, r0.w, -r3
    nrm r1.xyz, r0
    mad r0.xyz, r2, r1.w, r1
    mul r1, r0.y, c5
    mad r1, c4, r0.x, r1
    mad r0, c6, r0.z, r1
    add r0, r0, c7
    rcp r1.x, r0.w
    mul oT4, r0, r1.x
    mul r0, r3.y, c5
    mad r0, c4, r3.x, r0
    mad r0, c6, r3.z, r0
    add r0, r0, c7
    rcp r1.x, r0.w
    mul oT2, r0, r1.x
    mov oPos, r0
    mov oT0, v1
    mov oT1.xy, v2

// approximately 50 instruction slots used
#endif

const BYTE g_vs20_VS[] =
{
      0,   2, 254, 255, 254, 255, 
     40,   0,  67,  84,  65,  66, 
     28,   0,   0,   0, 105,   0, 
      0,   0,   0,   2, 254, 255, 
      2,   0,   0,   0,  28,   0, 
      0,   0,  16,   1,   0,   0, 
     98,   0,   0,   0,  68,   0, 
      0,   0,   2,   0,   0,   0, 
      4,   0,   2,   0,  76,   0, 
      0,   0,   0,   0,   0,   0, 
     92,   0,   0,   0,   2,   0, 
      4,   0,   4,   0,  18,   0, 
     76,   0,   0,   0,   0,   0, 
      0,   0, 109,  67,  97, 109, 
    101, 114,  97,   0,   3,   0, 
      3,   0,   4,   0,   4,   0, 
      1,   0,   0,   0,   0,   0, 
      0,   0, 109,  80, 114, 111, 
    106,   0, 118, 115,  95,  50, 
     95,  48,   0,  77, 105,  99, 
    114, 111, 115, 111, 102, 116, 
     32,  40,  82,  41,  32,  72, 
     76,  83,  76,  32,  83, 104, 
     97, 100, 101, 114,  32,  67, 
    111, 109, 112, 105, 108, 101, 
    114,  32,  57,  46,  50,  57, 
     46,  57,  53,  50,  46,  51, 
     49,  49,  49,   0, 171, 171, 
     31,   0,   0,   2,   0,   0, 
      0, 128,   0,   0,  15, 144, 
     31,   0,   0,   2,   3,   0, 
      0, 128,   1,   0,  15, 144, 
     31,   0,   0,   2,   5,   0, 
      0, 128,   2,   0,  15, 144, 
     31,   0,   0,   2,   3,   0, 
      1, 128,   3,   0,  15, 144, 
     31,   0,   0,   2,   3,   0, 
      2, 128,   4,   0,  15, 144, 
      1,   0,   0,   2,   0,   0, 
      7, 128,   0,   0, 228, 144, 
      2,   0,   0,   3,   1,   0, 
      7, 128,   0,   0, 228, 128, 
      3,   0, 228, 144,   5,   0, 
      0,   3,   2,   0,  15, 128, 
      1,   0,  85, 128,   1,   0, 
    228, 160,   4,   0,   0,   4, 
      2,   0,  15, 128,   0,   0, 
    228, 160,   1,   0,   0, 128, 
      2,   0, 228, 128,   4,   0, 
      0,   4,   1,   0,  15, 128, 
      2,   0, 228, 160,   1,   0, 
    170, 128,   2,   0, 228, 128, 
      2,   0,   0,   3,   1,   0, 
     15, 128,   1,   0, 228, 128, 
      3,   0, 228, 160,   6,   0, 
      0,   2,   0,   0,   8, 128, 
      1,   0, 255, 128,   5,   0, 
      0,   3,   2,   0,  15, 128, 
      0,   0,  85, 144,   1,   0, 
    228, 160,   4,   0,   0,   4, 
      2,   0,  15, 128,   0,   0, 
    228, 160,   0,   0,   0, 144, 
      2,   0, 228, 128,   4,   0, 
      0,   4,   2,   0,  15, 128, 
      2,   0, 228, 160,   0,   0, 
    170, 144,   2,   0, 228, 128, 
      2,   0,   0,   3,   2,   0, 
     15, 128,   2,   0, 228, 128, 
      3,   0, 228, 160,   6,   0, 
      0,   2,   1,   0,   8, 128, 
      2,   0, 255, 128,   5,   0, 
      0,   3,   3,   0,   7, 128, 
      1,   0, 255, 128,   2,   0, 
    228, 128,   4,   0,   0,   4, 
      1,   0,   7, 128,   1,   0, 
    228, 128,   0,   0, 255, 128, 
      3,   0, 228, 129,  36,   0, 
      0,   2,   4,   0,   7, 128, 
      1,   0, 228, 128,   4,   0, 
      0,   4,   1,   0,   7, 128, 
      2,   0, 228, 128,   1,   0, 
    255, 128,   4,   0, 228, 128, 
      5,   0,   0,   3,   4,   0, 
     15, 128,   1,   0,  85, 128, 
      5,   0, 228, 160,   4,   0, 
      0,   4,   4,   0,  15, 128, 
      4,   0, 228, 160,   1,   0, 
      0, 128,   4,   0, 228, 128, 
      4,   0,   0,   4,   4,   0, 
     15, 128,   6,   0, 228, 160, 
      1,   0, 170, 128,   4,   0, 
    228, 128,   2,   0,   0,   3, 
      4,   0,  15, 128,   4,   0, 
    228, 128,   7,   0, 228, 160, 
      6,   0,   0,   2,   0,   0, 
      8, 128,   4,   0, 255, 128, 
      5,   0,   0,   3,   3,   0, 
     15, 224,   0,   0, 255, 128, 
      4,   0, 228, 128,   2,   0, 
      0,   3,   0,   0,   7, 128, 
      0,   0, 228, 128,   4,   0, 
    228, 144,   5,   0,   0,   3, 
      4,   0,  15, 128,   0,   0, 
     85, 128,   1,   0, 228, 160, 
      4,   0,   0,   4,   4,   0, 
     15, 128,   0,   0, 228, 160, 
      0,   0,   0, 128,   4,   0, 
    228, 128,   4,   0,   0,   4, 
      0,   0,  15, 128,   2,   0, 
    228, 160,   0,   0, 170, 128, 
      4,   0, 228, 128,   2,   0, 
      0,   3,   0,   0,  15, 128, 
      0,   0, 228, 128,   3,   0, 
    228, 160,   6,   0,   0,   2, 
      0,   0,   8, 128,   0,   0, 
    255, 128,   4,   0,   0,   4, 
      0,   0,   7, 128,   0,   0, 
    228, 128,   0,   0, 255, 128, 
      3,   0, 228, 129,  36,   0, 
      0,   2,   1,   0,   7, 128, 
      0,   0, 228, 128,   4,   0, 
      0,   4,   0,   0,   7, 128, 
      2,   0, 228, 128,   1,   0, 
    255, 128,   1,   0, 228, 128, 
      5,   0,   0,   3,   1,   0, 
     15, 128,   0,   0,  85, 128, 
      5,   0, 228, 160,   4,   0, 
      0,   4,   1,   0,  15, 128, 
      4,   0, 228, 160,   0,   0, 
      0, 128,   1,   0, 228, 128, 
      4,   0,   0,   4,   0,   0, 
     15, 128,   6,   0, 228, 160, 
      0,   0, 170, 128,   1,   0, 
    228, 128,   2,   0,   0,   3, 
      0,   0,  15, 128,   0,   0, 
    228, 128,   7,   0, 228, 160, 
      6,   0,   0,   2,   1,   0, 
      1, 128,   0,   0, 255, 128, 
      5,   0,   0,   3,   4,   0, 
     15, 224,   0,   0, 228, 128, 
      1,   0,   0, 128,   5,   0, 
      0,   3,   0,   0,  15, 128, 
      3,   0,  85, 128,   5,   0, 
    228, 160,   4,   0,   0,   4, 
      0,   0,  15, 128,   4,   0, 
    228, 160,   3,   0,   0, 128, 
      0,   0, 228, 128,   4,   0, 
      0,   4,   0,   0,  15, 128, 
      6,   0, 228, 160,   3,   0, 
    170, 128,   0,   0, 228, 128, 
      2,   0,   0,   3,   0,   0, 
     15, 128,   0,   0, 228, 128, 
      7,   0, 228, 160,   6,   0, 
      0,   2,   1,   0,   1, 128, 
      0,   0, 255, 128,   5,   0, 
      0,   3,   2,   0,  15, 224, 
      0,   0, 228, 128,   1,   0, 
      0, 128,   1,   0,   0,   2, 
      0,   0,  15, 192,   0,   0, 
    228, 128,   1,   0,   0,   2, 
      0,   0,  15, 224,   1,   0, 
    228, 144,   1,   0,   0,   2, 
      1,   0,   3, 224,   2,   0, 
    228, 144, 255, 255,   0,   0
};
