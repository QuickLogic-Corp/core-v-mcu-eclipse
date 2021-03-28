//---------------------------------//
//
// Module: UDMA_CTRL
//
//---------------------------------//

typedef struct {
  union {
    __IO uint32_t REG_CG;     // Offset = 0x0000
    struct {
      __IO uint32_t  PERIPH_CLK_ENABLE : 32;
    } REG_CG_b;
  };
  union {
    __IO uint32_t REG_CFG_EVT;     // Offset = 0x0004
    struct {
      __IO uint32_t  CMP_EVENT[0] :  8;
      __IO uint32_t  CMP_EVENT[1] :  8;
      __IO uint32_t  CMP_EVENT[2] :  8;
      __IO uint32_t  CMP_EVENT[3] :  8;
    } REG_CFG_EVT_b;
  };
  union {
    __IO uint32_t REG_RST;     // Offset = 0x0008
    struct {
      __IO uint32_t  PERIPH_RESET : 32;
    } REG_RST_b;
  };
} UDMA_CTRL_t;


#define REG_REG_CG                     0x000
#define   REG_REG_CG_PERIPH_CLK_ENABLE_LSB         0
#define   REG_REG_CG_PERIPH_CLK_ENABLE_MASK        0xffffffff
#define REG_REG_CFG_EVT                0x004
#define   REG_REG_CFG_EVT_CMP_EVENT[3]_LSB         24
#define   REG_REG_CFG_EVT_CMP_EVENT[3]_MASK        0xff
#define   REG_REG_CFG_EVT_CMP_EVENT[2]_LSB         16
#define   REG_REG_CFG_EVT_CMP_EVENT[2]_MASK        0xff
#define   REG_REG_CFG_EVT_CMP_EVENT[1]_LSB         8
#define   REG_REG_CFG_EVT_CMP_EVENT[1]_MASK        0xff
#define   REG_REG_CFG_EVT_CMP_EVENT[0]_LSB         0
#define   REG_REG_CFG_EVT_CMP_EVENT[0]_MASK        0xff
#define REG_REG_RST                    0x008
#define   REG_REG_RST_PERIPH_RESET_LSB             0
#define   REG_REG_RST_PERIPH_RESET_MASK            0xffffffff

static inline uint32_t regfield_read(uint32_t reg, uint32_t mask, uint32_t lsb) {
  return (reg >> lsb) & mask;
}
static inline uint32_t regfield_write(uint32_t reg, uint32_t mask, uint32_t lsb, uint32_t value) {
  reg &= ~(mask << lsb);
  reg | = (value & mask) << lsb;
  return reg;
}
