// SOC options
#define N_IO                 48
#define N_SYSIO              3
#define N_GPIO               32
#define N_UART               2
#define N_QSPIM              1
#define N_I2CM               2
#define N_I2SC               0
#define N_CSI2               0
#define N_HYPER              0
#define N_SDIO               0
#define N_CAM                1
#define N_JTAG               0
#define N_MRAM               0
#define N_FILTER             1
#define N_FPGA               1
#define N_EXT_PER            0
#define N_EFPGA_TCDM_PORTS   4
#define N_FPGAIO             43
#define N_EFPGA_EVENTS       16

// UDMA configuration information
#define UDMA_START_ADDR 0x1A102000
// peripheral channel definitions
#define UDMA_CH_ADDR_CTRL       (0x1A102000)
#define UDMA_CH_ADDR_UART       (0x1A102000 + 1 * 0x80)
#define UDMA_CH_ADDR_UART0      (0x1A102000 + 1 * 0x80)
#define UDMA_CH_ADDR_UART1      (0x1A102000 + 2 * 0x80)
#define UDMA_CH_ADDR_I2CM       (0x1A102000 + 3 * 0x80)
#define UDMA_CH_ADDR_I2CM0      (0x1A102000 + 3 * 0x80)
#define UDMA_CH_ADDR_I2CM1      (0x1A102000 + 4 * 0x80)
#define UDMA_CH_ADDR_QSPIM      (0x1A102000 + 5 * 0x80)
#define UDMA_CH_ADDR_QSPIM0     (0x1A102000 + 5 * 0x80)
#define UDMA_CH_ADDR_I2SC       (0x1A102000 + 6 * 0x80)
#define UDMA_CH_ADDR_I2SC0      (0x1A102000 + 6 * 0x80)
#define UDMA_CH_ADDR_CSI2       (0x1A102000 + 6 * 0x80)
#define UDMA_CH_ADDR_CSI20      (0x1A102000 + 6 * 0x80)
#define UDMA_CH_ADDR_HYPER      (0x1A102000 + 6 * 0x80)
#define UDMA_CH_ADDR_HYPER0     (0x1A102000 + 6 * 0x80)
#define UDMA_CH_ADDR_SDIO       (0x1A102000 + 6 * 0x80)
#define UDMA_CH_ADDR_SDIO0      (0x1A102000 + 6 * 0x80)
#define UDMA_CH_ADDR_CAM        (0x1A102000 + 6 * 0x80)
#define UDMA_CH_ADDR_CAM0       (0x1A102000 + 6 * 0x80)
#define UDMA_CH_ADDR_JTAG       (0x1A102000 + 7 * 0x80)
#define UDMA_CH_ADDR_JTAG0      (0x1A102000 + 7 * 0x80)
#define UDMA_CH_ADDR_MRAM       (0x1A102000 + 7 * 0x80)
#define UDMA_CH_ADDR_MRAM0      (0x1A102000 + 7 * 0x80)
#define UDMA_CH_ADDR_FILTER     (0x1A102000 + 7 * 0x80)
#define UDMA_CH_ADDR_FILTER0    (0x1A102000 + 7 * 0x80)
#define UDMA_CH_ADDR_FPGA       (0x1A102000 + 8 * 0x80)
#define UDMA_CH_ADDR_FPGA0      (0x1A102000 + 8 * 0x80)
#define UDMA_CH_ADDR_EXT_PER    (0x1A102000 + 9 * 0x80)
#define UDMA_CH_ADDR_EXT_PER0   (0x1A102000 + 9 * 0x80)

// Peripheral clock enable masks
#define UDMA_CTRL_UART0_CLKEN      (1 << 0)
#define UDMA_CTRL_UART1_CLKEN      (1 << 1)
#define UDMA_CTRL_I2CM0_CLKEN      (1 << 2)
#define UDMA_CTRL_I2CM1_CLKEN      (1 << 3)
#define UDMA_CTRL_QSPIM0_CLKEN     (1 << 4)
#define UDMA_CTRL_I2SC0_CLKEN      (1 << 5)
#define UDMA_CTRL_CSI20_CLKEN      (1 << 5)
#define UDMA_CTRL_HYPER0_CLKEN     (1 << 5)
#define UDMA_CTRL_SDIO0_CLKEN      (1 << 5)
#define UDMA_CTRL_CAM0_CLKEN       (1 << 5)
#define UDMA_CTRL_JTAG0_CLKEN      (1 << 6)
#define UDMA_CTRL_MRAM0_CLKEN      (1 << 6)
#define UDMA_CTRL_FILTER0_CLKEN    (1 << 6)
#define UDMA_CTRL_FPGA0_CLKEN      (1 << 7)
#define UDMA_CTRL_EXT_PER0_CLKEN   (1 << 8)
