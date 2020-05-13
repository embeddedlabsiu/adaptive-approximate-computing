#include "Adder32ExactLibrary.h"

#include <stdint.h>

static int orFunction (int a, int b){return a | b; }
static int andFunction (int a, int b){return a & b; }
static int xorFunction (int a, int b){return a ^ b; }
static int notFunction (int a){return a ^ 1; }
static int bufFunction (int a){return a; }

void AND2_X1 ( int* A1, int* A2, int* ZN){
 *ZN=andFunction(  *A1, *A2);
}

void AND2_X2 ( int* A1, int* A2, int* ZN){
 *ZN=andFunction(  *A1, *A2);
}

void AND2_X4 ( int* A1, int* A2, int* ZN){
 *ZN=andFunction(  *A1, *A2);
}

void AND3_X1 ( int* A1, int* A2, int* A3, int* ZN){
 int i_4=andFunction(  *A1, *A2);
 *ZN=andFunction(  i_4, *A3);
}

void AND3_X2 ( int* A1, int* A2, int* A3, int* ZN){
 int i_4=andFunction(  *A1, *A2);
 *ZN=andFunction(  i_4, *A3);
}

void AND3_X4 ( int* A1, int* A2, int* A3, int* ZN){
 int i_4=andFunction(  *A1, *A2);
 *ZN=andFunction(  i_4, *A3);
}

void AND4_X1 ( int* A1, int* A2, int* A3, int* A4, int* ZN){
 int i_9=andFunction(  *A1, *A2);
 int i_8=andFunction(  i_9, *A3);
 *ZN=andFunction(  i_8, *A4);
}

void AND4_X2 ( int* A1, int* A2, int* A3, int* A4, int* ZN){
 int i_9=andFunction(  *A1, *A2);
 int i_8=andFunction(  i_9, *A3);
 *ZN=andFunction(  i_8, *A4);
}

void AND4_X4 ( int* A1, int* A2, int* A3, int* A4, int* ZN){
 int i_9=andFunction(  *A1, *A2);
 int i_8=andFunction(  i_9, *A3);
 *ZN=andFunction(  i_8, *A4);
}

void ANTENNA_X1 ( int* A){
}

void AOI211_X1 ( int* A, int* B, int* C1, int* C2, int* ZN){
 int i_14=andFunction(  *C1, *C2);
 int i_13=orFunction(  i_14, *B);
 int i_12=orFunction(  i_13, *A);
 *ZN=notFunction(  i_12);
}

void AOI211_X2 ( int* A, int* B, int* C1, int* C2, int* ZN){
 int i_14=andFunction(  *C1, *C2);
 int i_13=orFunction(  i_14, *B);
 int i_12=orFunction(  i_13, *A);
 *ZN=notFunction(  i_12);
}

void AOI211_X4 ( int* A, int* B, int* C1, int* C2, int* ZN){
 int i_24=andFunction(  *C1, *C2);
 int i_23=orFunction(  i_24, *B);
 int i_22=orFunction(  i_23, *A);
 int i_21=notFunction(  i_22);
 int i_20=notFunction(  i_21);
 *ZN=notFunction(  i_20);
}

void AOI21_X1 ( int* A, int* B1, int* B2, int* ZN){
 int i_9=andFunction(  *B1, *B2);
 int i_8=orFunction(  *A, i_9);
 *ZN=notFunction(  i_8);
}

void AOI21_X2 ( int* A, int* B1, int* B2, int* ZN){
 int i_9=andFunction(  *B1, *B2);
 int i_8=orFunction(  *A, i_9);
 *ZN=notFunction(  i_8);
}

void AOI21_X4 ( int* A, int* B1, int* B2, int* ZN){
 int i_9=andFunction(  *B1, *B2);
 int i_8=orFunction(  *A, i_9);
 *ZN=notFunction(  i_8);
}

void AOI221_X1 ( int* A, int* B1, int* B2, int* C1, int* C2, int* ZN){
 int i_18=andFunction(  *C1, *C2);
 int i_17=orFunction(  i_18, *A);
 int i_19=andFunction(  *B1, *B2);
 int i_16=orFunction(  i_17, i_19);
 *ZN=notFunction(  i_16);
}

void AOI221_X2 ( int* A, int* B1, int* B2, int* C1, int* C2, int* ZN){
 int i_18=andFunction(  *C1, *C2);
 int i_17=orFunction(  i_18, *A);
 int i_19=andFunction(  *B1, *B2);
 int i_16=orFunction(  i_17, i_19);
 *ZN=notFunction(  i_16);
}

void AOI221_X4 ( int* A, int* B1, int* B2, int* C1, int* C2, int* ZN){
 int i_28=andFunction(  *C1, *C2);
 int i_27=orFunction(  i_28, *A);
 int i_29=andFunction(  *B1, *B2);
 int i_26=orFunction(  i_27, i_29);
 int i_25=notFunction(  i_26);
 int i_24=notFunction(  i_25);
 *ZN=notFunction(  i_24);
}

void AOI222_X1 ( int* A1, int* A2, int* B1, int* B2, int* C1, int* C2, int* ZN){
 int i_22=andFunction(  *A1, *A2);
 int i_23=andFunction(  *B1, *B2);
 int i_21=orFunction(  i_22, i_23);
 int i_24=andFunction(  *C1, *C2);
 int i_20=orFunction(  i_21, i_24);
 *ZN=notFunction(  i_20);
}

void AOI222_X2 ( int* A1, int* A2, int* B1, int* B2, int* C1, int* C2, int* ZN){
 int i_22=andFunction(  *A1, *A2);
 int i_23=andFunction(  *B1, *B2);
 int i_21=orFunction(  i_22, i_23);
 int i_24=andFunction(  *C1, *C2);
 int i_20=orFunction(  i_21, i_24);
 *ZN=notFunction(  i_20);
}

void AOI222_X4 ( int* A1, int* A2, int* B1, int* B2, int* C1, int* C2, int* ZN){
 int i_32=andFunction(  *A1, *A2);
 int i_33=andFunction(  *B1, *B2);
 int i_31=orFunction(  i_32, i_33);
 int i_34=andFunction(  *C1, *C2);
 int i_30=orFunction(  i_31, i_34);
 int i_29=notFunction(  i_30);
 int i_28=notFunction(  i_29);
 *ZN=notFunction(  i_28);
}

void AOI22_X1 ( int* A1, int* A2, int* B1, int* B2, int* ZN){
 int i_13=andFunction(  *A1, *A2);
 int i_14=andFunction(  *B1, *B2);
 int i_12=orFunction(  i_13, i_14);
 *ZN=notFunction(  i_12);
}

void AOI22_X2 ( int* A1, int* A2, int* B1, int* B2, int* ZN){
 int i_13=andFunction(  *A1, *A2);
 int i_14=andFunction(  *B1, *B2);
 int i_12=orFunction(  i_13, i_14);
 *ZN=notFunction(  i_12);
}

void AOI22_X4 ( int* A1, int* A2, int* B1, int* B2, int* ZN){
 int i_13=andFunction(  *A1, *A2);
 int i_14=andFunction(  *B1, *B2);
 int i_12=orFunction(  i_13, i_14);
 *ZN=notFunction(  i_12);
}

void BUF_X1 ( int* A, int* Z){
 *Z=bufFunction(  *A);
}

void BUF_X16 ( int* A, int* Z){
 *Z=bufFunction(  *A);
}

void BUF_X2 ( int* A, int* Z){
 *Z=bufFunction(  *A);
}

void BUF_X32 ( int* A, int* Z){
 *Z=bufFunction(  *A);
}

void BUF_X4 ( int* A, int* Z){
 *Z=bufFunction(  *A);
}

void BUF_X8 ( int* A, int* Z){
 *Z=bufFunction(  *A);
}

void CLKBUF_X1 ( int* A, int* Z){
 *Z=bufFunction(  *A);
}

void CLKBUF_X2 ( int* A, int* Z){
 *Z=bufFunction(  *A);
}

void CLKBUF_X3 ( int* A, int* Z){
 *Z=bufFunction(  *A);
}

void DFFRS_X1 ( int* D, int* RN, int* SN, int* CK, int* Q, int* QN){
 *Q=bufFunction(*D);
 *QN=notFunction(*D);
}

void DFFRS_X2 ( int* D, int* RN, int* SN, int* CK, int* Q, int* QN){
 *Q=bufFunction(*D);
 *QN=notFunction(*D);
}

void DFFR_X1 ( int* D, int* RN, int* CK, int* Q, int* QN){
 *Q=bufFunction(*D);
 *QN=notFunction(*D);
}

void DFFR_X2 ( int* D, int* RN, int* CK, int* Q, int* QN){
 *Q=bufFunction(*D);
 *QN=notFunction(*D);
}

void DFFS_X1 ( int* D, int* SN, int* CK, int* Q, int* QN){
 *Q=bufFunction(*D);
 *QN=notFunction(*D);
}

void DFFS_X2 ( int* D, int* SN, int* CK, int* Q, int* QN){
 *Q=bufFunction(*D);
 *QN=notFunction(*D);
}

void DFF_X1 ( int* D, int* CK, int* Q, int* QN){
 *Q=bufFunction(*D);
 *QN=notFunction(*D);
}

void DFF_X2 ( int* D, int* CK, int* Q, int* QN){
 *Q=bufFunction(*D);
 *QN=notFunction(*D);
}

void FA_X1 ( int* A, int* B, int* CI, int* CO, int* S){
 int i_16=andFunction(  *A, *B);
 int i_18=orFunction(  *A, *B);
 int i_17=andFunction(  *CI, i_18);
 *CO=orFunction(  i_16, i_17);
 int i_22=xorFunction(  *A, *B);
 *S=xorFunction(  *CI, i_22);
}

void HA_X1 ( int* A, int* B, int* CO, int* S){
 *CO=andFunction(  *A, *B);
 *S=xorFunction(  *A, *B);
}

void INV_X1 ( int* A, int* ZN){
 *ZN=notFunction(  *A);
}

void INV_X16 ( int* A, int* ZN){
 *ZN=notFunction(  *A);
}

void INV_X2 ( int* A, int* ZN){
 *ZN=notFunction(  *A);
}

void INV_X32 ( int* A, int* ZN){
 *ZN=notFunction(  *A);
}

void INV_X4 ( int* A, int* ZN){
 *ZN=notFunction(  *A);
}

void INV_X8 ( int* A, int* ZN){
 *ZN=notFunction(  *A);
}

void LOGIC0_X1 ( int* Z){
}

//void LOGIC1_X1 ( int* Z){
//}

void MUX2_X1 ( int* A, int* B, int* S, int* Z){
 int i_12=andFunction(  *S, *B);
 int i_14=notFunction(  *S);
 int i_13=andFunction(  *A, i_14);
 *Z=orFunction(  i_12, i_13);
}

void MUX2_X2 ( int* A, int* B, int* S, int* Z){
 int i_12=andFunction(  *S, *B);
 int i_14=notFunction(  *S);
 int i_13=andFunction(  *A, i_14);
 *Z=orFunction(  i_12, i_13);
}

void NAND2_X1 ( int* A1, int* A2, int* ZN){
 int i_10=andFunction(  *A1, *A2);
 *ZN=notFunction(  i_10);
}

void NAND2_X2 ( int* A1, int* A2, int* ZN){
 int i_22=andFunction(  *A1, *A2);
 *ZN=notFunction(  i_22);
}

void NAND2_X4 ( int* A1, int* A2, int* ZN){
 int i_10=andFunction(  *A1, *A2);
 *ZN=notFunction(  i_10);
}

void NAND3_X1 ( int* A1, int* A2, int* A3, int* ZN){
 int i_9=andFunction(  *A1, *A2);
 int i_8=andFunction(  i_9, *A3);
 *ZN=notFunction(  i_8);
}

void NAND3_X2 ( int* A1, int* A2, int* A3, int* ZN){
 int i_9=andFunction(  *A1, *A2);
 int i_8=andFunction(  i_9, *A3);
 *ZN=notFunction(  i_8);
}

void NAND3_X4 ( int* A1, int* A2, int* A3, int* ZN){
 int i_9=andFunction(  *A1, *A2);
 int i_8=andFunction(  i_9, *A3);
 *ZN=notFunction(  i_8);
}

void NAND4_X1 ( int* A1, int* A2, int* A3, int* A4, int* ZN){
 int i_14=andFunction(  *A1, *A2);
 int i_13=andFunction(  i_14, *A3);
 int i_12=andFunction(  i_13, *A4);
 *ZN=notFunction(  i_12);
}

void NAND4_X2 ( int* A1, int* A2, int* A3, int* A4, int* ZN){
 int i_14=andFunction(  *A1, *A2);
 int i_13=andFunction(  i_14, *A3);
 int i_12=andFunction(  i_13, *A4);
 *ZN=notFunction(  i_12);
}

void NAND4_X4 ( int* A1, int* A2, int* A3, int* A4, int* ZN){
 int i_14=andFunction(  *A1, *A2);
 int i_13=andFunction(  i_14, *A3);
 int i_12=andFunction(  i_13, *A4);
 *ZN=notFunction(  i_12);
}

void NOR2_X1 ( int* A1, int* A2, int* ZN){
 int i_10=orFunction(  *A1, *A2);
 *ZN=notFunction(  i_10);
}

void NOR2_X2 ( int* A1, int* A2, int* ZN){
 int i_10=orFunction(  *A1, *A2);
 *ZN=notFunction(  i_10);
}

void NOR2_X4 ( int* A1, int* A2, int* ZN){
 int i_16=orFunction(  *A1, *A2);
 *ZN=notFunction(  i_16);
}

void NOR3_X1 ( int* A1, int* A2, int* A3, int* ZN){
 int i_9=orFunction(  *A1, *A2);
 int i_8=orFunction(  i_9, *A3);
 *ZN=notFunction(  i_8);
}

void NOR3_X2 ( int* A1, int* A2, int* A3, int* ZN){
 int i_9=orFunction(  *A1, *A2);
 int i_8=orFunction(  i_9, *A3);
 *ZN=notFunction(  i_8);
}

void NOR3_X4 ( int* A1, int* A2, int* A3, int* ZN){
 int i_9=orFunction(  *A1, *A2);
 int i_8=orFunction(  i_9, *A3);
 *ZN=notFunction(  i_8);
}

void NOR4_X1 ( int* A1, int* A2, int* A3, int* A4, int* ZN){
 int i_14=orFunction(  *A1, *A2);
 int i_13=orFunction(  i_14, *A3);
 int i_12=orFunction(  i_13, *A4);
 *ZN=notFunction(  i_12);
}

void NOR4_X2 ( int* A1, int* A2, int* A3, int* A4, int* ZN){
 int i_14=orFunction(  *A1, *A2);
 int i_13=orFunction(  i_14, *A3);
 int i_12=orFunction(  i_13, *A4);
 *ZN=notFunction(  i_12);
}

void NOR4_X4 ( int* A1, int* A2, int* A3, int* A4, int* ZN){
 int i_14=orFunction(  *A1, *A2);
 int i_13=orFunction(  i_14, *A3);
 int i_12=orFunction(  i_13, *A4);
 *ZN=notFunction(  i_12);
}

void OAI211_X1 ( int* A, int* B, int* C1, int* C2, int* ZN){
 int i_14=orFunction(  *C1, *C2);
 int i_13=andFunction(  i_14, *A);
 int i_12=andFunction(  i_13, *B);
 *ZN=notFunction(  i_12);
}

void OAI211_X2 ( int* A, int* B, int* C1, int* C2, int* ZN){
 int i_14=orFunction(  *C1, *C2);
 int i_13=andFunction(  i_14, *A);
 int i_12=andFunction(  i_13, *B);
 *ZN=notFunction(  i_12);
}

void OAI211_X4 ( int* A, int* B, int* C1, int* C2, int* ZN){
 int i_14=orFunction(  *C1, *C2);
 int i_13=andFunction(  i_14, *A);
 int i_12=andFunction(  i_13, *B);
 *ZN=notFunction(  i_12);
}

void OAI21_X1 ( int* A, int* B1, int* B2, int* ZN){
 int i_9=orFunction(  *B1, *B2);
 int i_8=andFunction(  *A, i_9);
 *ZN=notFunction(  i_8);
}

void OAI21_X2 ( int* A, int* B1, int* B2, int* ZN){
 int i_9=orFunction(  *B1, *B2);
 int i_8=andFunction(  *A, i_9);
 *ZN=notFunction(  i_8);
}

void OAI21_X4 ( int* A, int* B1, int* B2, int* ZN){
 int i_9=orFunction(  *B1, *B2);
 int i_8=andFunction(  *A, i_9);
 *ZN=notFunction(  i_8);
}

void OAI221_X1 ( int* A, int* B1, int* B2, int* C1, int* C2, int* ZN){
 int i_18=orFunction(  *C1, *C2);
 int i_17=andFunction(  i_18, *A);
 int i_19=orFunction(  *B1, *B2);
 int i_16=andFunction(  i_17, i_19);
 *ZN=notFunction(  i_16);
}

void OAI221_X2 ( int* A, int* B1, int* B2, int* C1, int* C2, int* ZN){
 int i_18=orFunction(  *C1, *C2);
 int i_17=andFunction(  i_18, *A);
 int i_19=orFunction(  *B1, *B2);
 int i_16=andFunction(  i_17, i_19);
 *ZN=notFunction(  i_16);
}

void OAI221_X4 ( int* A, int* B1, int* B2, int* C1, int* C2, int* ZN){
 int i_28=orFunction(  *C1, *C2);
 int i_27=andFunction(  i_28, *A);
 int i_29=orFunction(  *B1, *B2);
 int i_26=andFunction(  i_27, i_29);
 int i_25=notFunction(  i_26);
 int i_24=notFunction(  i_25);
 *ZN=notFunction(  i_24);
}

void OAI222_X1 ( int* A1, int* A2, int* B1, int* B2, int* C1, int* C2, int* ZN){
 int i_22=orFunction(  *A1, *A2);
 int i_23=orFunction(  *B1, *B2);
 int i_21=andFunction(  i_22, i_23);
 int i_24=orFunction(  *C1, *C2);
 int i_20=andFunction(  i_21, i_24);
 *ZN=notFunction(  i_20);
}

void OAI222_X2 ( int* A1, int* A2, int* B1, int* B2, int* C1, int* C2, int* ZN){
 int i_22=orFunction(  *A1, *A2);
 int i_23=orFunction(  *B1, *B2);
 int i_21=andFunction(  i_22, i_23);
 int i_24=orFunction(  *C1, *C2);
 int i_20=andFunction(  i_21, i_24);
 *ZN=notFunction(  i_20);
}

void OAI222_X4 ( int* A1, int* A2, int* B1, int* B2, int* C1, int* C2, int* ZN){
 int i_32=orFunction(  *A1, *A2);
 int i_33=orFunction(  *B1, *B2);
 int i_31=andFunction(  i_32, i_33);
 int i_34=orFunction(  *C1, *C2);
 int i_30=andFunction(  i_31, i_34);
 int i_29=notFunction(  i_30);
 int i_28=notFunction(  i_29);
 *ZN=notFunction(  i_28);
}

void OAI22_X1 ( int* A1, int* A2, int* B1, int* B2, int* ZN){
 int i_13=orFunction(  *A1, *A2);
 int i_14=orFunction(  *B1, *B2);
 int i_12=andFunction(  i_13, i_14);
 *ZN=notFunction(  i_12);
}

void OAI22_X2 ( int* A1, int* A2, int* B1, int* B2, int* ZN){
 int i_13=orFunction(  *A1, *A2);
 int i_14=orFunction(  *B1, *B2);
 int i_12=andFunction(  i_13, i_14);
 *ZN=notFunction(  i_12);
}

void OAI22_X4 ( int* A1, int* A2, int* B1, int* B2, int* ZN){
 int i_13=orFunction(  *A1, *A2);
 int i_14=orFunction(  *B1, *B2);
 int i_12=andFunction(  i_13, i_14);
 *ZN=notFunction(  i_12);
}

void OAI33_X1 ( int* A1, int* A2, int* A3, int* B1, int* B2, int* B3, int* ZN){
 int i_22=orFunction(  *A1, *A2);
 int i_21=orFunction(  i_22, *A3);
 int i_24=orFunction(  *B1, *B2);
 int i_23=orFunction(  i_24, *B3);
 int i_20=andFunction(  i_21, i_23);
 *ZN=notFunction(  i_20);
}

void OR2_X1 ( int* A1, int* A2, int* ZN){
 *ZN=orFunction(  *A1, *A2);
}

void OR2_X2 ( int* A1, int* A2, int* ZN){
 *ZN=orFunction(  *A1, *A2);
}

void OR2_X4 ( int* A1, int* A2, int* ZN){
 *ZN=orFunction(  *A1, *A2);
}

void OR3_X1 ( int* A1, int* A2, int* A3, int* ZN){
 int i_4=orFunction(  *A1, *A2);
 *ZN=orFunction(  i_4, *A3);
}

void OR3_X2 ( int* A1, int* A2, int* A3, int* ZN){
 int i_4=orFunction(  *A1, *A2);
 *ZN=orFunction(  i_4, *A3);
}

void OR3_X4 ( int* A1, int* A2, int* A3, int* ZN){
 int i_4=orFunction(  *A1, *A2);
 *ZN=orFunction(  i_4, *A3);
}

void OR4_X1 ( int* A1, int* A2, int* A3, int* A4, int* ZN){
 int i_9=orFunction(  *A1, *A2);
 int i_8=orFunction(  i_9, *A3);
 *ZN=orFunction(  i_8, *A4);
}

void OR4_X2 ( int* A1, int* A2, int* A3, int* A4, int* ZN){
 int i_9=orFunction(  *A1, *A2);
 int i_8=orFunction(  i_9, *A3);
 *ZN=orFunction(  i_8, *A4);
}

void OR4_X4 ( int* A1, int* A2, int* A3, int* A4, int* ZN){
 int i_9=orFunction(  *A1, *A2);
 int i_8=orFunction(  i_9, *A3);
 *ZN=orFunction(  i_8, *A4);
}

void SDFFRS_X1 ( int* D, int* RN, int* SE, int* SI, int* SN, int* CK, int* Q, int* QN){
 *Q=bufFunction(*D);
 *QN=notFunction(*D);
}

void SDFFRS_X2 ( int* D, int* RN, int* SE, int* SI, int* SN, int* CK, int* Q, int* QN){
 *Q=bufFunction(*D);
 *QN=notFunction(*D);
}

void SDFFR_X1 ( int* D, int* RN, int* SE, int* SI, int* CK, int* Q, int* QN){
 *Q=bufFunction(*D);
 *QN=notFunction(*D);
}

void SDFFR_X2 ( int* D, int* RN, int* SE, int* SI, int* CK, int* Q, int* QN){
 *Q=bufFunction(*D);
 *QN=notFunction(*D);
}

void SDFFS_X1 ( int* D, int* SE, int* SI, int* SN, int* CK, int* Q, int* QN){
 *Q=bufFunction(*D);
 *QN=notFunction(*D);
}

void SDFFS_X2 ( int* D, int* SE, int* SI, int* SN, int* CK, int* Q, int* QN){
 *Q=bufFunction(*D);
 *QN=notFunction(*D);
}

void SDFF_X1 ( int* D, int* SE, int* SI, int* CK, int* Q, int* QN){
 *Q=bufFunction(*D);
 *QN=notFunction(*D);
}

void SDFF_X2 ( int* D, int* SE, int* SI, int* CK, int* Q, int* QN){
 *Q=bufFunction(*D);
 *QN=notFunction(*D);
}

void XNOR2_X1 ( int* A, int* B, int* ZN){
 int i_4=xorFunction(  *A, *B);
 *ZN=notFunction(  i_4);
}

void XNOR2_X2 ( int* A, int* B, int* ZN){
 int i_4=xorFunction(  *A, *B);
 *ZN=notFunction(  i_4);
}

void XOR2_X1 ( int* A, int* B, int* Z){
 *Z=xorFunction(  *A, *B);
}

void XOR2_X2 ( int* A, int* B, int* Z){
 *Z=xorFunction(  *A, *B);
}

