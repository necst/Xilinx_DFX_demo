#include "top_function.hpp"

void subber(input_s &stream_a, input_s &stream_b, output_s &stream_c) {
#pragma HLS INTERFACE mode=s_axilite port=return
#pragma HLS INTERFACE mode=axis register_mode=both port=stream_c register
#pragma HLS INTERFACE mode=axis register_mode=both port=stream_b register
#pragma HLS INTERFACE mode=axis register_mode=both port=stream_a register
#pragma HLS DATAFLOW
	input_pkt pkt_a, pkt_b;
	output_pkt pkt_c;

	input a, b;
	output c;

	stream_a >> pkt_a;
	stream_b >> pkt_b;

	a = pkt_a.data;
	b = pkt_b.data;
	c = a - b;

	pkt_c.data = c;
	pkt_c.last = pkt_a.last || pkt_b.last;
	pkt_c.keep = -1;
	pkt_c.strb = 0;

	stream_c << pkt_c;

	return;
}
