
#include <stdio.h>
#include <stdint.h>
#define __int8 int8_t
#define __int16 int16_t

#define DSS_CBUF_SIZE 21

unsigned int word_3D1264;
unsigned int word_3D1266;
unsigned int flip;


void g_unc_byte_swap(__int8 *abuff_swap, __int8 **abuff_src, int dec_flag)
{
  uint8_t *abuff_tmp;
  int size; // si@1
  int i;

  word_3D1264 = 1;
  abuff_tmp = *abuff_src;
  size = DSS_CBUF_SIZE;
  if (flip)
  {
	  unsigned int tmp = abuff_tmp[0];
#if 0
    if (dec_flag & 2 && !(tmp & 0x80) )
    {
      size = 5;
      word_3D1264 = 0;
    }
#endif
    abuff_tmp++;

    for (i = 0; i < size - 1; i++)
    {
    	abuff_swap[0] = tmp;
    	abuff_swap[1] = abuff_tmp[0];
        tmp = abuff_tmp[1];
        abuff_tmp += 2;
        abuff_swap += 2;
    }

    word_3D1266 = tmp;
    abuff_swap[0] = 0;
    abuff_swap[1] = abuff_tmp[0];
    *abuff_src = abuff_tmp;
    flip ^= 1;
  } else {
#if 0
    if ( dec_flag & 2 && !(*(abuff_tmp - 1) & 0x80) )// Never executed
    {
      size = 5;
      word_3D1264 = 0;
    }
#endif
    abuff_swap[0] = abuff_tmp[2];
    abuff_swap[1] = word_3D1266;
    abuff_tmp++;
    abuff_swap += 2;

    for (i = 0; i < size - 2; i++) {
      abuff_swap[0] = abuff_tmp[3];
      abuff_swap[1] = abuff_tmp[0];
      abuff_swap += 2;
      abuff_tmp += 2;
    }

    abuff_swap[1] = abuff_tmp[0];
    *abuff_src = abuff_tmp + 2;
    flip ^= 1;
  }
}

void g_unc_sub_3B9120(uint16_t *reconstr_abuff, int16_t *abuff_swap_a2)
{
  __int16 v2; // bp@1
  __int16 *abuff_swap_ptr_v3; // eax@2
  __int16 *reconstr_abuff_v4; // esi@2
  int v5; // ecx@2
  int v6; // edx@2
  signed int v7; // edx@2
  signed int v8; // edx@2
  int v9; // ecx@2
  int v10; // edx@2
  signed int v11; // ecx@2
  int v12; // edx@2
  int v13; // edx@3
  signed int v14; // edx@3
  signed int v15; // edx@3
  int v16; // ecx@3
  int v17; // edx@3
  signed int v18; // ecx@7
  signed int v19; // edx@7
  int v20; // ecx@7
  signed int v21; // ecx@7
  signed int v22; // ecx@7
  int v23; // edx@7
  signed int v24; // edx@7
  signed int v25; // edx@7
  signed int v26; // edx@7
  int v27; // ecx@7
  signed int v28; // ecx@7
  signed int v29; // ecx@7
  int v30; // edx@7
  signed int v31; // edi@9
  int *v32; // ebx@12
  signed int v33; // ecx@12
  int *v34; // edx@16
  int v35; // ebx@16
  unsigned int v36; // edx@22
  signed int v37; // ebx@22
  signed int v38; // ecx@22
  signed int v39; // edi@22
  int v40; // ebp@25
  int v41; // ebp@25
  bool v42; // zf@26
  int v43; // edx@27
  __int16 *v44; // ebx@27
  signed int v45; // ebp@27
  int v46; // ecx@27
  __int16 v47; // di@28
  __int16 v48; // si@29
  __int8 *v49; // eax@29
  signed int v50; // edx@29
  int v51; // ecx@31
  int v52; // [sp+8h] [bp-30h]@7
  __int16 *v53; // [sp+Ch] [bp-2Ch]@7
  int *v54; // [sp+10h] [bp-28h]@12
  signed int v55; // [sp+14h] [bp-24h]@7
  int v56; // [sp+18h] [bp-20h]@9
  int v57; // [sp+1Ch] [bp-1Ch]@9
  int v58; // [sp+20h] [bp-18h]@9
  int v59; // [sp+24h] [bp-14h]@9
  int v60; // [sp+28h] [bp-10h]@9
  int v61; // [sp+2Ch] [bp-Ch]@9
  int v62; // [sp+30h] [bp-8h]@9
  int v63; // [sp+34h] [bp-4h]@9
  __int16 *reconstr_abuffa; // [sp+3Ch] [bp+4h]@0
  __int16 *reconstr_abuffb; // [sp+3Ch] [bp+4h]@7
  __int16 *abuff_swap_ptr; // [sp+40h] [bp+8h]@0
  __int16 *abuff_swap_ptra; // [sp+40h] [bp+8h]@12
  __int8 *abuff_swap_ptrb; // [sp+40h] [bp+8h]@22
  __int8 *abuff_swap_ptrc; // [sp+40h] [bp+8h]@27

  v2 = 0;
  if ( word_3D041C )
  {
    abuff_swap_ptr_v3 = abuff_swap_ptr;
    reconstr_abuff_v4 = reconstr_abuffa;
    reconstr_abuff = abuff_swap_ptr[0];
    v5 = (reconstr_abuff >> 15) & 1;
    reconstr_abuffa[0] = v5;
    word_3D1264 = v5;
    reconstr_abuffa[1] = ((signed int)(unsigned __int16)*abuff_swap_ptr >> 10) & 0x1F;
    LOWORD(abuff_swap_a2) = *abuff_swap_ptr;
    v6 = ((signed int)abuff_swap_a2 >> 5) & 0x1F;
    reconstr_abuffa[2] = v6;
    reconstr_abuffa[3] = (*(_BYTE *)abuff_swap_ptr >> 1) & 0xF;
    LOWORD(v6) = abuff_swap_ptr[1];
    v7 = ((v6 >> 13) & 7) + 8 * (*(_BYTE *)abuff_swap_ptr & 1);
    reconstr_abuffa[4] = v7;
    reconstr_abuffa[5] = ((signed int)(unsigned __int16)abuff_swap_ptr[1] >> 9) & 0xF;
    LOWORD(v7) = abuff_swap_ptr[1];
    reconstr_abuffa[6] = (v7 >> 5) & 0xF;
    reconstr_abuffa[7] = (*((_BYTE *)abuff_swap_ptr + 2) >> 1) & 0xF;
    v8 = (((signed int)(unsigned __int16)abuff_swap_ptr_v3[2] >> 13) & 7) + 8 * (*((_BYTE *)abuff_swap_ptr_v3 + 2) & 1);
    reconstr_abuffa[8] = v8;
    reconstr_abuffa[9] = ((signed int)(unsigned __int16)abuff_swap_ptr[2] >> 10) & 7;
    LOWORD(v8) = abuff_swap_ptr[2];
    reconstr_abuffa[10] = (v8 >> 7) & 7;
    v9 = (*((_BYTE *)abuff_swap_ptr + 4) >> 4) & 7;
    reconstr_abuffa[11] = v9;
    reconstr_abuffa[12] = (*((_BYTE *)abuff_swap_ptr + 4) >> 1) & 7;
    LOWORD(v9) = abuff_swap_ptr[3];
    v10 = *((_BYTE *)abuff_swap_ptr + 4) & 1;
    v11 = ((v9 >> 14) & 3) + 4 * v10;
    reconstr_abuffa[13] = v11;
    LOWORD(v10) = abuff_swap_ptr[3];
    v12 = (v10 >> 12) & 3;
  }
  else
  {
    abuff_swap_ptr_v3 = abuff_swap_ptr;
    reconstr_abuff_v4 = reconstr_abuffa;
    word_3D1264 = 1;

    reconstr_abuffa[1] = (abuff_swap_ptr[0] >> 11) & 0x1F;
    reconstr_abuffa[2] = (abuff_swap_ptr[0] >> 6) & 0x1F;
    reconstr_abuffa[3] = ((abuff_swap_ptr[0] & 0xf) >> 2) & 0xF;
    reconstr_abuffa[4] = ((abuff_swap_ptr[1] >> 14) & 3)
    		+ 4 * (abuff_swap_ptr[0] & 3);

    reconstr_abuffa[5] = (abuff_swap_ptr[1] >> 10) & 0xF;
    reconstr_abuffa[6] = (abuff_swap_ptr[1] >> 6) & 0xF;
    reconstr_abuffa[7] = ((abuff_swap_ptr[1] & 0xf) >> 2) & 0xF;
    reconstr_abuffa[8] = ((abuff_swap_ptr[2] >> 14) & 3)
    		+ 4 * (abuff_swap_ptr[1] & 3);

    reconstr_abuffa[9] = (abuff_swap_ptr[2] >> 11) & 7;
    reconstr_abuffa[10] = (abuff_swap_ptr[2] >> 8) & 7;
    reconstr_abuffa[11] = ((abuff_swap_ptr[2] & 0xf) >> 5) & 7;
    reconstr_abuffa[12] = ((abuff_swap_ptr[2] & 0xf) >> 2) & 7;
    reconstr_abuffa[13] = ((abuff_swap_ptr[3] >> 15) & 1)
    		+ 2 * ((abuff_swap_ptr[2] & 0xf) & 3);

    v12 = (abuff_swap_ptr[3] >> 12) & 7;
  }
  reconstr_abuff_v4[14] = v12;
  if ( word_3D041C && !word_3D1264 )
  {
    LOWORD(v11) = abuff_swap_ptr_v3[3];
    reconstr_abuff_v4[19] = (v11 >> 7) & 0x1F;
    reconstr_abuff_v4[20] = (*((_BYTE *)abuff_swap_ptr_v3 + 6) >> 2) & 0x1F;
    reconstr_abuff_v4[21] = ((signed int)(unsigned __int16)abuff_swap_ptr_v3[4] >> 13) & 7;
    reconstr_abuff_v4[22] = ((signed int)(unsigned __int16)abuff_swap_ptr_v3[4] >> 8) & 0x1F;
    return;
  }
  LOWORD(v11) = abuff_swap_ptr_v3[3];
  reconstr_abuff_v4[19] = (v11 >> 7) & 0x1F;
  *((_DWORD *)reconstr_abuff_v4 + 13) = *((_BYTE *)abuff_swap_ptr_v3 + 11)
                                      + (((unsigned __int16)abuff_swap_ptr_v3[4]
                                        + ((*((_BYTE *)abuff_swap_ptr_v3 + 6) & 0x7F) << 16)) << 8);
  reconstr_abuff_v4[24] = (*((_BYTE *)abuff_swap_ptr_v3 + 10) >> 2) & 0x3F;
  v18 = (((signed int)(unsigned __int16)abuff_swap_ptr_v3[6] >> 15) & 1) + 2 * (*((_BYTE *)abuff_swap_ptr_v3 + 10) & 3);
  reconstr_abuff_v4[35] = v18;
  reconstr_abuff_v4[36] = ((signed int)(unsigned __int16)abuff_swap_ptr_v3[6] >> 12) & 7;
  LOWORD(v18) = abuff_swap_ptr_v3[6];
  reconstr_abuff_v4[37] = (v18 >> 9) & 7;
  reconstr_abuff_v4[38] = ((signed int)(unsigned __int16)abuff_swap_ptr_v3[6] >> 6) & 7;
  reconstr_abuff_v4[39] = (*((_BYTE *)abuff_swap_ptr_v3 + 12) >> 3) & 7;
  reconstr_abuff_v4[40] = *((_BYTE *)abuff_swap_ptr_v3 + 12) & 7;
  reconstr_abuff_v4[41] = ((signed int)(unsigned __int16)abuff_swap_ptr_v3[7] >> 13) & 7;
  reconstr_abuff_v4[20] = ((signed int)(unsigned __int16)abuff_swap_ptr_v3[7] >> 8) & 0x1F;
  v19 = (unsigned __int16)abuff_swap_ptr_v3[8];
  v20 = v19 + (*((_BYTE *)abuff_swap_ptr_v3 + 14) << 16);
  LOWORD(v19) = abuff_swap_ptr_v3[9];
  v21 = ((v19 >> 9) & 0x7F) + (v20 << 7);
  *((_DWORD *)reconstr_abuff_v4 + 22) = v21;
  LOWORD(v21) = abuff_swap_ptr_v3[9];
  reconstr_abuff_v4[42] = (v21 >> 3) & 0x3F;
  reconstr_abuff_v4[53] = *((_BYTE *)abuff_swap_ptr_v3 + 18) & 7;
  reconstr_abuff_v4[54] = ((signed int)(unsigned __int16)abuff_swap_ptr_v3[10] >> 13) & 7;
  reconstr_abuff_v4[55] = ((signed int)(unsigned __int16)abuff_swap_ptr_v3[10] >> 10) & 7;
  reconstr_abuff_v4[56] = ((signed int)(unsigned __int16)abuff_swap_ptr_v3[10] >> 7) & 7;
  reconstr_abuff_v4[57] = (*((_BYTE *)abuff_swap_ptr_v3 + 20) >> 4) & 7;
  reconstr_abuff_v4[58] = (*((_BYTE *)abuff_swap_ptr_v3 + 20) >> 1) & 7;
  reconstr_abuff_v4[59] = (((signed int)(unsigned __int16)abuff_swap_ptr_v3[11] >> 14) & 3)
                        + 4 * (*((_BYTE *)abuff_swap_ptr_v3 + 20) & 1);
  reconstr_abuff_v4[21] = ((signed int)(unsigned __int16)abuff_swap_ptr_v3[11] >> 9) & 0x1F;
  v22 = (unsigned __int16)abuff_swap_ptr_v3[12];
  v23 = v22 + ((abuff_swap_ptr_v3[11] & 0x1FF) << 16);
  LOWORD(v22) = abuff_swap_ptr_v3[13];
  v24 = ((v22 >> 10) & 0x3F) + (v23 << 6);
  *((_DWORD *)reconstr_abuff_v4 + 31) = v24;
  LOWORD(v24) = abuff_swap_ptr_v3[13];
  reconstr_abuff_v4[60] = (v24 >> 4) & 0x3F;
  reconstr_abuff_v4[71] = (*((_BYTE *)abuff_swap_ptr_v3 + 26) >> 1) & 7;
  v25 = (((signed int)(unsigned __int16)abuff_swap_ptr_v3[14] >> 14) & 3) + 4 * (*((_BYTE *)abuff_swap_ptr_v3 + 26) & 1);
  reconstr_abuff_v4[72] = v25;
  reconstr_abuff_v4[73] = ((signed int)(unsigned __int16)abuff_swap_ptr_v3[14] >> 11) & 7;
  LOWORD(v25) = abuff_swap_ptr_v3[14];
  reconstr_abuff_v4[74] = (v25 >> 8) & 7;
  reconstr_abuff_v4[75] = (*((_BYTE *)abuff_swap_ptr_v3 + 28) >> 5) & 7;
  reconstr_abuff_v4[76] = (*((_BYTE *)abuff_swap_ptr_v3 + 28) >> 2) & 7;
  reconstr_abuff_v4[77] = (((signed int)(unsigned __int16)abuff_swap_ptr_v3[15] >> 15) & 1)
                        + 2 * (*((_BYTE *)abuff_swap_ptr_v3 + 28) & 3);
  reconstr_abuff_v4[22] = ((signed int)(unsigned __int16)abuff_swap_ptr_v3[15] >> 10) & 0x1F;
  reconstr_abuffb = 0;
  v26 = (unsigned __int16)abuff_swap_ptr_v3[16];
  v52 = 0;
  v27 = v26 + ((abuff_swap_ptr_v3[15] & 0x3FF) << 16);
  LOWORD(v26) = abuff_swap_ptr_v3[17];
  v55 = 4;
  v28 = ((v26 >> 11) & 0x1F) + 32 * v27;
  *((_DWORD *)reconstr_abuff_v4 + 40) = v28;
  LOWORD(v28) = abuff_swap_ptr_v3[17];
  reconstr_abuff_v4[78] = (v28 >> 5) & 0x3F;
  reconstr_abuff_v4[89] = (*((_BYTE *)abuff_swap_ptr_v3 + 34) >> 2) & 7;
  v29 = (((signed int)(unsigned __int16)abuff_swap_ptr_v3[18] >> 15) & 1) + 2 * (*((_BYTE *)abuff_swap_ptr_v3 + 34) & 3);
  reconstr_abuff_v4[90] = v29;
  reconstr_abuff_v4[91] = ((signed int)(unsigned __int16)abuff_swap_ptr_v3[18] >> 12) & 7;
  LOWORD(v29) = abuff_swap_ptr_v3[18];
  reconstr_abuff_v4[92] = (v29 >> 9) & 7;
  reconstr_abuff_v4[93] = ((signed int)(unsigned __int16)abuff_swap_ptr_v3[18] >> 6) & 7;
  reconstr_abuff_v4[94] = (*((_BYTE *)abuff_swap_ptr_v3 + 36) >> 3) & 7;
  reconstr_abuff_v4[95] = *((_BYTE *)abuff_swap_ptr_v3 + 36) & 7;
  v30 = (int)(reconstr_abuff_v4 + 26);
  v53 = reconstr_abuff_v4 + 26;
  while ( 1 )
  {
    v31 = *(_DWORD *)v30;
    v56 = 72;
    v57 = 2556;
    v58 = 59640;
    v59 = 1028790;
    v60 = 13991544;
    v61 = 156238908;
    v62 = 1473109704;
    v63 = -915885543;
    if ( v31 <= 1473109703 )
    {
      if ( word_3D0C26 != v2 )
        goto LABEL_22;
    }
    else
    {
      word_3D0C26 = v2;
    }
    v32 = &v63;
    v33 = 7;
    *(_WORD *)(v30 + 16) = v2;
    abuff_swap_ptra = (__int16 *)71;
    v54 = &v63;
    do
    {
      if ( *(v32 - 1) <= v31 )
      {
        --v33;
        v32 = &v56 + (signed __int16)v33;
        v31 -= *(&v56 + (signed __int16)v33);
        v54 = &v56 + (signed __int16)v33;
        reconstr_abuff_v4[v52 - (signed __int16)v33 + 34] = (signed __int16)abuff_swap_ptra;
        if ( !(_WORD)v33 )
          break;
      }
      --v56;
      if ( (signed __int16)v33 > 1 )
      {
        v34 = &v57;
        v35 = (signed __int16)v33 - 1;
        do
        {
          *v34 -= *(v34 - 1);
          ++v34;
          --v35;
        }
        while ( v35 );
        v32 = v54;
      }
      abuff_swap_ptra = (__int16 *)((char *)abuff_swap_ptra - 1);
    }
    while ( (signed __int16)abuff_swap_ptra >= 0 );
    if ( word_3D0C26 )
    {
      v30 = (int)v53;
LABEL_22:
      v36 = *(_DWORD *)v30;
      v37 = 7;
      v38 = 71;
      v39 = 504;
      abuff_swap_ptrb = (__int8 *)7;
      do
      {
        for ( ; v36 < g_unc_array_3C8978[v39 + (signed __int16)v38]; --v38 )
          ;
        v40 = v39 + (signed __int16)v38;
        v39 -= 72;
        v36 -= g_unc_array_3C8978[v40];
        v41 = 18 * (_DWORD)reconstr_abuffb - v37--;
        reconstr_abuff_v4[v41 + 35] = v38;
        --abuff_swap_ptrb;
      }
      while ( abuff_swap_ptrb );
    }
    v30 = (int)(v53 + 18);
    v42 = v55 == 1;
    reconstr_abuffb = (__int16 *)((char *)reconstr_abuffb + 1);
    v52 += 18;
    v53 += 18;
    --v55;
    if ( v42 )
      break;
    v2 = 0;
  }
  v43 = (unsigned __int16)abuff_swap_ptr_v3[19];
  v44 = reconstr_abuff_v4 + 16;
  abuff_swap_ptrc = (__int8 *)(reconstr_abuff_v4 + 16);
  v45 = 3;
  v46 = ((v43 << 8) + *((_BYTE *)abuff_swap_ptr_v3 + 41)) / 151;
  reconstr_abuff_v4[15] = ((v43 << 8) + *((_BYTE *)abuff_swap_ptr_v3 + 41)) % 151 + 36;
  do
  {
    v47 = v46;
    ++v44;
    v46 /= 48;
    --v45;
    *(v44 - 1) = v47 - 48 * v46;
  }
  while ( v45 );
  v48 = reconstr_abuff_v4[15];
  v49 = abuff_swap_ptrc;
  v50 = 3;
  do
  {
    if ( v48 > 162 )
    {
      *(_WORD *)v49 += 139;
    }
    else
    {
      v51 = v48 - 23;
      if ( v51 < 36 )
        LOWORD(v51) = 36;
      *(_WORD *)v49 += v51;
    }
    v48 = *(_WORD *)v49;
    v49 += 2;
    --v50;
  }
  while ( v50 );
}

