#if 0
//
// Generated by Microsoft (R) HLSL Shader Compiler 9.29.952.3111
//
//
//   fxc /Zpc /Tps_4_0_level_9_3 /EPS /Fh
//    Shader/EffekseerRenderer.ModelRenderer.ShaderLighting_PS.h
//    Shader/model_renderer_lighting_PS.fx
//
//
// Buffer Definitions: 
//
// cbuffer $Globals
// {
//
//   float4 fLightDirection;            // Offset:    0 Size:    16 [unused]
//   float4 fLightColor;                // Offset:   16 Size:    16 [unused]
//   float4 fLightAmbient;              // Offset:   32 Size:    16
//
// }
//
//
// Resource Bindings:
//
// Name                                 Type  Format         Dim Slot Elements
// ------------------------------ ---------- ------- ----------- ---- --------
// $Globals                          cbuffer      NA          NA    0        1
//
//
//
// Input signature:
//
// Name                 Index   Mask Register SysValue Format   Used
// -------------------- ----- ------ -------- -------- ------ ------
// SV_POSITION              0   xyzw        0      POS  float       
// TEXCOORD                 0   xy          1     NONE  float       
// COLOR                    0   xyzw        2     NONE  float   xyzw
//
//
// Output signature:
//
// Name                 Index   Mask Register SysValue Format   Used
// -------------------- ----- ------ -------- -------- ------ ------
// SV_Target                0   xyzw        0   TARGET  float   xyzw
//
//
// Constant buffer to DX9 shader constant mappings:
//
// Target Reg Buffer  Start Reg # of Regs        Data Conversion
// ---------- ------- --------- --------- ----------------------
// c0         cb0             2         1  ( FLT, FLT, FLT, FLT)
//
//
// Level9 shader bytecode:
//
    ps_2_x
    def c1, -1, -0, 0, 0
    dcl t1
    mul r0.w, t1.w, t1.w
    cmp r0, -r0.w, c1.x, c1.y
    texkill r0
    mov r0.w, t1.w
    add r0.xyz, t1, c0
    mov oC0, r0

// approximately 6 instruction slots used
ps_4_0
dcl_constantbuffer cb0[3], immediateIndexed
dcl_input_ps linear v2.xyzw
dcl_output o0.xyzw
dcl_temps 1
eq r0.x, v2.w, l(0.000000)
discard r0.x
add o0.xyz, v2.xyzx, cb0[2].xyzx
mov o0.w, v2.w
ret 
// Approximately 5 instruction slots used
#endif

const BYTE g_PS[] =
{
     68,  88,  66,  67, 166, 151, 
    207, 195, 175, 228, 105,  69, 
    167, 115, 169,  55,  74,  94, 
      2, 252,   1,   0,   0,   0, 
    208,   3,   0,   0,   6,   0, 
      0,   0,  56,   0,   0,   0, 
    240,   0,   0,   0, 144,   1, 
      0,   0,  12,   2,   0,   0, 
     40,   3,   0,   0, 156,   3, 
      0,   0,  65, 111, 110,  57, 
    176,   0,   0,   0, 176,   0, 
      0,   0,   0,   2, 255, 255, 
    128,   0,   0,   0,  48,   0, 
      0,   0,   1,   0,  36,   0, 
      0,   0,  48,   0,   0,   0, 
     48,   0,   0,   0,  36,   0, 
      0,   0,  48,   0,   0,   0, 
      2,   0,   1,   0,   0,   0, 
      0,   0,   0,   0,   1,   2, 
    255, 255,  81,   0,   0,   5, 
      1,   0,  15, 160,   0,   0, 
    128, 191,   0,   0,   0, 128, 
      0,   0,   0,   0,   0,   0, 
      0,   0,  31,   0,   0,   2, 
      0,   0,   0, 128,   1,   0, 
     15, 176,   5,   0,   0,   3, 
      0,   0,   8, 128,   1,   0, 
    255, 176,   1,   0, 255, 176, 
     88,   0,   0,   4,   0,   0, 
     15, 128,   0,   0, 255, 129, 
      1,   0,   0, 160,   1,   0, 
     85, 160,  65,   0,   0,   1, 
      0,   0,  15, 128,   1,   0, 
      0,   2,   0,   0,   8, 128, 
      1,   0, 255, 176,   2,   0, 
      0,   3,   0,   0,   7, 128, 
      1,   0, 228, 176,   0,   0, 
    228, 160,   1,   0,   0,   2, 
      0,   8,  15, 128,   0,   0, 
    228, 128, 255, 255,   0,   0, 
     83,  72,  68,  82, 152,   0, 
      0,   0,  64,   0,   0,   0, 
     38,   0,   0,   0,  89,   0, 
      0,   4,  70, 142,  32,   0, 
      0,   0,   0,   0,   3,   0, 
      0,   0,  98,  16,   0,   3, 
    242,  16,  16,   0,   2,   0, 
      0,   0, 101,   0,   0,   3, 
    242,  32,  16,   0,   0,   0, 
      0,   0, 104,   0,   0,   2, 
      1,   0,   0,   0,  24,   0, 
      0,   7,  18,   0,  16,   0, 
      0,   0,   0,   0,  58,  16, 
     16,   0,   2,   0,   0,   0, 
      1,  64,   0,   0,   0,   0, 
      0,   0,  13,   0,   4,   3, 
     10,   0,  16,   0,   0,   0, 
      0,   0,   0,   0,   0,   8, 
    114,  32,  16,   0,   0,   0, 
      0,   0,  70,  18,  16,   0, 
      2,   0,   0,   0,  70, 130, 
     32,   0,   0,   0,   0,   0, 
      2,   0,   0,   0,  54,   0, 
      0,   5, 130,  32,  16,   0, 
      0,   0,   0,   0,  58,  16, 
     16,   0,   2,   0,   0,   0, 
     62,   0,   0,   1,  83,  84, 
     65,  84, 116,   0,   0,   0, 
      5,   0,   0,   0,   1,   0, 
      0,   0,   0,   0,   0,   0, 
      2,   0,   0,   0,   2,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   1,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   2,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,  82,  68,  69,  70, 
     20,   1,   0,   0,   1,   0, 
      0,   0,  72,   0,   0,   0, 
      1,   0,   0,   0,  28,   0, 
      0,   0,   0,   4, 255, 255, 
     16,   1,   0,   0, 226,   0, 
      0,   0,  60,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   1,   0,   0,   0, 
      0,   0,   0,   0,  36,  71, 
    108, 111,  98,  97, 108, 115, 
      0, 171, 171, 171,  60,   0, 
      0,   0,   3,   0,   0,   0, 
     96,   0,   0,   0,  48,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0, 168,   0, 
      0,   0,   0,   0,   0,   0, 
     16,   0,   0,   0,   0,   0, 
      0,   0, 184,   0,   0,   0, 
      0,   0,   0,   0, 200,   0, 
      0,   0,  16,   0,   0,   0, 
     16,   0,   0,   0,   0,   0, 
      0,   0, 184,   0,   0,   0, 
      0,   0,   0,   0, 212,   0, 
      0,   0,  32,   0,   0,   0, 
     16,   0,   0,   0,   2,   0, 
      0,   0, 184,   0,   0,   0, 
      0,   0,   0,   0, 102,  76, 
    105, 103, 104, 116,  68, 105, 
    114, 101,  99, 116, 105, 111, 
    110,   0,   1,   0,   3,   0, 
      1,   0,   4,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
    102,  76, 105, 103, 104, 116, 
     67, 111, 108, 111, 114,   0, 
    102,  76, 105, 103, 104, 116, 
     65, 109,  98, 105, 101, 110, 
    116,   0,  77, 105,  99, 114, 
    111, 115, 111, 102, 116,  32, 
     40,  82,  41,  32,  72,  76, 
     83,  76,  32,  83, 104,  97, 
    100, 101, 114,  32,  67, 111, 
    109, 112, 105, 108, 101, 114, 
     32,  57,  46,  50,  57,  46, 
     57,  53,  50,  46,  51,  49, 
     49,  49,   0, 171,  73,  83, 
     71,  78, 108,   0,   0,   0, 
      3,   0,   0,   0,   8,   0, 
      0,   0,  80,   0,   0,   0, 
      0,   0,   0,   0,   1,   0, 
      0,   0,   3,   0,   0,   0, 
      0,   0,   0,   0,  15,   0, 
      0,   0,  92,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   3,   0,   0,   0, 
      1,   0,   0,   0,   3,   0, 
      0,   0, 101,   0,   0,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   3,   0,   0,   0, 
      2,   0,   0,   0,  15,  15, 
      0,   0,  83,  86,  95,  80, 
     79,  83,  73,  84,  73,  79, 
     78,   0,  84,  69,  88,  67, 
     79,  79,  82,  68,   0,  67, 
     79,  76,  79,  82,   0, 171, 
     79,  83,  71,  78,  44,   0, 
      0,   0,   1,   0,   0,   0, 
      8,   0,   0,   0,  32,   0, 
      0,   0,   0,   0,   0,   0, 
      0,   0,   0,   0,   3,   0, 
      0,   0,   0,   0,   0,   0, 
     15,   0,   0,   0,  83,  86, 
     95,  84,  97, 114, 103, 101, 
    116,   0, 171, 171
};
