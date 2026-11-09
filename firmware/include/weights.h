#ifndef WEIGHTS_H
#define WEIGHTS_H

#include <stdint.h>

#define L1_IN  3
#define L1_OUT 8
#define L2_IN  8
#define L2_OUT 4
#define L3_IN  4
#define L3_OUT 1

static const float X_MEAN[3] = {309.8950f, 1.0000f, 0.4926f};
static const float X_STD[3]  = {422.2253f, 0.0000f, 0.5000f};

static const int8_t W1[L1_OUT][L1_IN] = {
    {  87,  -44,   84},
    {  46,  -46,   53},
    { 107,  -50,  -77},
    {  45,   15,   87},
    {-112,  -41,  127},
    { 109,  -30,   44},
    { -50,   48,   55},
    {  -8,  -46,   16},
};
static const int8_t B1[L1_OUT] = {  36,   48, -127,   28,   72,   46,   31,  -50};

static const int8_t W2[L2_OUT][L2_IN] = {
    {  51,   54, -121,   52,  -32,   68,   -1,   20},
    {  16,   37,  127,   29,  103,  -46,   61,   -3},
    {   0,    9,  -17,   17,   -2,  -12,  -18,    0},
    {  11,  -12,   -8,    9,  -19,  -10,    2,    7},
};
static const int8_t B2[L2_OUT] = { -40,  -16, -127,  -64};

static const int8_t W3[L3_OUT][L3_IN] = {
    {-115,  127,   20,   25},
};
static const int8_t B3[L3_OUT] = {-127};

#endif // WEIGHTS_H
