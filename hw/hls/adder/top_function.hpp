#include <ap_axi_sdata.h>
#include <ap_int.h>
#include <hls_stream.h>

typedef ap_int<32> input;
typedef hls::axis<input, 1, 1, 1> input_pkt;
typedef hls::stream<input_pkt> input_s;
typedef ap_int<32> output;
typedef hls::axis<output, 1, 1, 1> output_pkt;
typedef hls::stream<output_pkt> output_s;

void adder(input_s &stream_a, input_s &stream_b, output_s &stream_c);
