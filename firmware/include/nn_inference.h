#ifndef NN_INFERENCE_H
#define NN_INFERENCE_H

#include <stdint.h>
#include "weights.h"

// Runs baseline Pure-C INT8 Forward Pass Inference
int predict_can_intrusion(float inter_arrival_ms, float id_frequency, float hamming_distance);

#endif // NN_INFERENCE_H
