#include "xparameters.h"
#include "xil_io.h"
#include "shifter_v4.h"
 

//====================================================

int main (void) {

	int salida;
	int entrada = 20;
	int direccion = 1;
	int desplazamiento=2;
	
    xil_printf("-- BARREL SHIFTER V.3 --\r\n");
 
    SHIFTER_V4_mWriteReg(XPAR_SHIFTER_V4_S_AXI_BASEADDR, SHIFTER_V4_S_AXI_SLV_REG0_OFFSET, entrada);
    SHIFTER_V4_mWriteReg(XPAR_SHIFTER_V4_S_AXI_BASEADDR, SHIFTER_V4_S_AXI_SLV_REG1_OFFSET, desplazamiento);
	SHIFTER_V4_mWriteReg(XPAR_SHIFTER_V4_S_AXI_BASEADDR, SHIFTER_V4_S_AXI_SLV_REG2_OFFSET, direccion);
	
    salida = SHIFTER_V4_mReadReg(XPAR_SHIFTER_V4_S_AXI_BASEADDR, SHIFTER_V4_S_AXI_SLV_REG3_OFFSET);

    xil_printf("Entrada: %d \r\n", entrada);
	xil_printf("Desplazamiento: %d \r\n", desplazamiento);
    xil_printf("Direccion: %d \r\n", direccion);
    xil_printf("Salida: %d \r\n", salida);

 
}
