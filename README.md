# Xilinx Dynamic Function Exchange + ZYNQ-MPSoC + PYNQ 2.7 example

_Based on Xilinx Vivado\Vitis\Vitis HLS 2021.2_

This repository contains all the sources and tools for creating a hardware design which allows to test Dynamic Function Exchange (DFX) on ZYNQ-MPSoCs through the PYNQ APIs.

## Steps

1. Creating the Variants for the Reconfigurable Module
    1. Create a Vitis HLS project for each of the three variants of the Reconfigurable Module under the `hw/hls` folder (namely: `adder`, `subber`, `multer`)
    2. Export the resulting IPs into the `hw/system/IPs` folder
2. Integrating the Reconfigurable Module variants into a system desing
    1. Extract the `DFX.xpr.zip` with Vivado with `hw/system` as working directory
    2. Replace the custom IP repository with `hw/system/IPs`
    3. Generate bitstream
    4. Copy `.bit` and `.hwh` files generated by Vivado into the `host` folder
3. Patching PYNQ
    1. Apply the `pdr_fix.patch` in the `PYNQ` folder on the `pynq` python package on the board
4. Run the Host IPython Notebook
    1. Load the `host` folder on the board
    2. Run `DFX Tester.ipynb`

For further details, read the `README.md`s under each of this example subfolders.
