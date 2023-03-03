#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <stdbool.h>
#include "ascii.h"

/**
 *
 *
 */
int main(int argc, char** argv)
{
    bool hex_output = check_flag(argv, HEX_FLAG);

    // more characters than we need but that's okay.
    char row_buffer[0x100] = {0};
    char str_buffer[0x10] = {0};
    char* buf_ptr = row_buffer;
    static int col_count = 8;
    int x = 0;
    int y = 0;

    for (uint8_t c = 0; c <= 127; c++)
    {
        char next = y + (x * col_count);

        memset(str_buffer, 0, sizeof(str_buffer));

        char_str(next, str_buffer);

        if (hex_output)
        {
            sprintf(buf_ptr, "%02x\t%s\t", next, str_buffer);
        }
        else
        {
            sprintf(buf_ptr, "%d\t%s\t", next, str_buffer);
        }

        // seek next NUL character.
        while (*buf_ptr)
        {
            buf_ptr++;
        }

        if (x == col_count - 1)
        {
            y++;
            x = 0;
            buf_ptr = row_buffer;

            printf("%s\n", buf_ptr);

            // Wipe buffer
            memset(buf_ptr, 0, sizeof(row_buffer));
        }
        else
        {
            x++;
        }
    }

    return 0;
}

// return 1 if present, 0 if not.
bool check_flag(char** args, char* flag)
{
    bool present = 0;

    while (*args && !present)
    {
        present = strcmp(*args, flag) == 0;

        args++;
    }

    return present;
}

int char_str(char c, char* buf)
{
    int size;

    if (c < 0x20 || c == 0x7F)
    {
        size = ctrl_char_str(c, buf);
    }
    else
    {
        size = print_char_str(c, buf);
    }

    return size;
}

int print_char_str(char c, char* buf)
{
    *buf = c;

    return 1;
}

// Returns size of string.
int ctrl_char_str(char c, char* buf)
{
    int str_size;

    if (c < 0x20)
    {
        switch (c)
        {
            case 0x0:
                MEMCPY_CONST(buf, NUL_STR);
                str_size = sizeof(NUL_STR);
                break;
            case 0x1:
                MEMCPY_CONST(buf, SOH_STR);
                str_size = sizeof(SOH_STR);
                break;
            case 0x2:
                MEMCPY_CONST(buf, STX_STR);
                str_size = sizeof(STX_STR);
                break;
            case 0x3:
                MEMCPY_CONST(buf, ETX_STR);
                str_size = sizeof(ETX_STR);
                break;
            case 0x4:
                MEMCPY_CONST(buf, EOT_STR);
                str_size = sizeof(EOT_STR);
                break;
            case 0x5:
                MEMCPY_CONST(buf, ENQ_STR);
                str_size = sizeof(ENQ_STR);
                break;
            case 0x6:
                MEMCPY_CONST(buf, ACK_STR);
                str_size = sizeof(ACK_STR);
                break;
            case 0x7:
                MEMCPY_CONST(buf, BEL_STR);
                str_size = sizeof(BEL_STR);
                break;
            case 0x8:
                MEMCPY_CONST(buf, BS_STR);
                str_size = sizeof(BS_STR);
                break;
            case 0x9:
                MEMCPY_CONST(buf, HT_STR);
                str_size = sizeof(HT_STR);
                break;
            case 0xA:
                MEMCPY_CONST(buf, LF_STR);
                str_size = sizeof(LF_STR);
                break;
            case 0xB:
                MEMCPY_CONST(buf, VT_STR);
                str_size = sizeof(VT_STR);
                break;
            case 0xC:
                MEMCPY_CONST(buf, FF_STR);
                str_size = sizeof(FF_STR);
                break;
            case 0xD:
                MEMCPY_CONST(buf, CR_STR);
                str_size = sizeof(CR_STR);
                break;
            case 0xE:
                MEMCPY_CONST(buf, SO_STR);
                str_size = sizeof(SO_STR);
                break;
            case 0xF:
                MEMCPY_CONST(buf, SI_STR);
                str_size = sizeof(SI_STR);
                break;
            case 0x10:
                MEMCPY_CONST(buf, DLE_STR);
                str_size = sizeof(DLE_STR);
                break;
            case 0x11:
                MEMCPY_CONST(buf, DC1_STR);
                str_size = sizeof(DC1_STR);
                break;
            case 0x12:
                MEMCPY_CONST(buf, DC2_STR);
                str_size = sizeof(DC2_STR);
                break;
            case 0x13:
                MEMCPY_CONST(buf, DC3_STR);
                str_size = sizeof(DC3_STR);
                break;
            case 0x14:
                MEMCPY_CONST(buf, DC4_STR);
                str_size = sizeof(DC4_STR);
                break;
            case 0x15:
                MEMCPY_CONST(buf, NAK_STR);
                str_size = sizeof(NAK_STR);
                break;
            case 0x16:
                MEMCPY_CONST(buf, SYN_STR);
                str_size = sizeof(SYN_STR);
                break;
            case 0x17:
                MEMCPY_CONST(buf, ETB_STR);
                str_size = sizeof(ETB_STR);
                break;
            case 0x18:
                MEMCPY_CONST(buf, CAN_STR);
                str_size = sizeof(CAN_STR);
                break;
            case 0x19:
                MEMCPY_CONST(buf, EM_STR);
                str_size = sizeof(EM_STR);
                break;
            case 0x1A:
                MEMCPY_CONST(buf, SUB_STR);
                str_size = sizeof(SUB_STR);
                break;
            case 0x1B:
                MEMCPY_CONST(buf, ESC_STR);
                str_size = sizeof(ESC_STR);
                break;
            case 0x1C:
                MEMCPY_CONST(buf, FS_STR);
                str_size = sizeof(FS_STR);
                break;
            case 0x1D:
                MEMCPY_CONST(buf, GS_STR);
                str_size = sizeof(GS_STR);
                break;
            case 0x1E:
                MEMCPY_CONST(buf, RS_STR);
                str_size = sizeof(RS_STR);
                break;
            case 0x1F:
                MEMCPY_CONST(buf, US_STR);
                str_size = sizeof(US_STR);
                break;
            default:
                break;
        }
    }
    else if (c == 0x7F)
    {
        MEMCPY_CONST(buf, DEL_STR);
        str_size = sizeof(DEL_STR);
    }

    return str_size;
}
