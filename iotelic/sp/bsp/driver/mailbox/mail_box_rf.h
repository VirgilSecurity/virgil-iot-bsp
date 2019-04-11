
//-----------------------------------
#define CFG_MSG_RVER_ADDR 0x0000
#define MSG_RF_VER_OFFSET 0
#define MSG_RF_VER_MASK 0x000000FF

//-----------------------------------
#define CFG_MSG_STS_ADDR 0x0004
#define MSG_RX_FIFO_EMP_OFFSET 9
#define MSG_RX_FIFO_EMP_MASK 0x00000200
#define MSG_TX_FIFO_FULL_OFFSET 8
#define MSG_TX_FIFO_FULL_MASK 0x00000100
#define MSG_RX_FIFO_CNT_OFFSET 4
#define MSG_RX_FIFO_CNT_MASK 0x000000F0
#define MSG_TX_FIFO_CNT_OFFSET 0
#define MSG_TX_FIFO_CNT_MASK 0x0000000F

//-----------------------------------
#define CFG_MSG_RCTRL_ADDR 0x0008
#define MSG_RX_FIFO_RD_OFFSET 0
#define MSG_RX_FIFO_RD_MASK 0x00000001

//-----------------------------------
#define CFG_MSG_RDATA_ADDR 0x000c
#define MSG_RX_FIFO_RDATA_OFFSET 0
#define MSG_RX_FIFO_RDATA_MASK 0xFFFFFFFF

//-----------------------------------
#define CFG_MSG_WDATA_ADDR 0x0010
#define MSG_TX_FIFO_WDATA_OFFSET 0
#define MSG_TX_FIFO_WDATA_MASK 0xFFFFFFFF

//HW module read/write macro
#define MAIL_BOX_RF_READ_REG(addr) SOC_READ_REG(MAIL_BOX_RF_BASEADDR + addr)
#define MAIL_BOX_RF_WRITE_REG(addr,value) SOC_WRITE_REG(MAIL_BOX_RF_BASEADDR + addr,value)
#define MAIL_BOX_RF1_READ_REG(addr) SOC_READ_REG(MAIL_BOX_RF1_BASEADDR + addr)
#define MAIL_BOX_RF1_WRITE_REG(addr,value) SOC_WRITE_REG(MAIL_BOX_RF1_BASEADDR + addr,value)
