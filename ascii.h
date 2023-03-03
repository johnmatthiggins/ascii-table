#ifndef ASCII_H
#define ASCII_H
#include <stdlib.h>
#include <string.h>

#define HEX_FLAG "-x"
#define COL_FLAG "-c"

#define MEMCPY_CONST(destination, source) memcpy((void*)destination, (void*)source, sizeof(source) * sizeof(char))

#define NUL_STR ("NUL")
#define SOH_STR ("SOH")
#define STX_STR ("STX")
#define ETX_STR ("ETX")
#define EOT_STR ("EOT")
#define ENQ_STR ("ENQ")
#define ACK_STR ("ACK")
#define BEL_STR ("BEL")
#define BS_STR  ("BS")
#define HT_STR  ("HT")
#define LF_STR  ("LF")
#define VT_STR  ("VT")
#define FF_STR  ("FF")
#define CR_STR  ("CR")
#define SO_STR  ("SO")
#define SI_STR  ("SI")
#define DLE_STR ("DLE")
#define DC1_STR ("DC1")
#define DC2_STR ("DC2")
#define DC3_STR ("DC3")
#define DC4_STR ("DC4")
#define NAK_STR ("NAK")
#define SYN_STR ("SYN")
#define ETB_STR ("ETB")
#define CAN_STR ("CAN")
#define EM_STR  ("EM")
#define SUB_STR ("SUB")
#define ESC_STR ("ESC")
#define FS_STR  ("FS")
#define GS_STR  ("GS")
#define RS_STR  ("RS")
#define US_STR  ("US")
#define DEL_STR ("DEL")

int char_str(char c, char* buf);
int print_char_str(char c, char* buf);
int ctrl_char_str(char c, char* buf);
bool check_flag(char** args, char* flag);
int read_column_flag(char** args, int argc);

#endif
