#include "top_function.hpp"

#include <cstdlib>

#define N 100


int main(int argc, char *argv[]) {

	input as[N], bs[N];
	output cs[N], cs_gold[N];

	input_pkt a_pkts[N], b_pkts[N];
	output_pkt c_pkts[N];

	input_s stream_a("STREAM A"), stream_b("STREAM B");
	output_s stream_c("STREAM C");



	// Random Initialization
	for (int i = 0; i < N; i++) {
		as[i] = rand();
		a_pkts[i].data = as[i];
		a_pkts[i].last = (i == (N - 1));
		a_pkts[i].keep = -1;
		a_pkts[i].strb = 0;

		bs[i] = rand();
		b_pkts[i].data = bs[i];
		b_pkts[i].last = (i == (N - 1));
		b_pkts[i].keep = -1;
		b_pkts[i].strb = 0;

		cs[i] = 0;
		cs_gold[i] = as[i] * bs[i];
	}

	// Load Streams
	for (int i = 0; i < N; i++) {
		stream_a << a_pkts[i];
		stream_b << b_pkts[i];
	}

	// Run IP
	for (int i = 0; i < N; i++) {
		multer(stream_a, stream_b, stream_c);
	}

	bool error = false;

	// Read Back Stream
	for (int i = 0; i < N; i++) {
		stream_c >> c_pkts[i];
		std::cout << "READ " << i << std::endl;
		if (c_pkts[i].keep != 0b1111) { //FIXME: hardcoded
			std::cerr << "KEEP should be all 1s, instead is " << c_pkts[i].keep << std::endl;
			error = true;
		}
		if (c_pkts[i].strb != 0) {
			std::cerr << "STRB should be all 0s, instead is " << c_pkts[i].strb << std::endl;
			error = true;
		}
		cs[i] = c_pkts[i].data;
		if (cs[i] != cs_gold[i]) {
			std::cerr << "DATA should be " << cs_gold[i] <<", instead is " << cs[i] << std::endl;
			error = true;
		}
		if (c_pkts[i].last) {
			break;
		}
	}

	return error ? 1 : 0;
}
