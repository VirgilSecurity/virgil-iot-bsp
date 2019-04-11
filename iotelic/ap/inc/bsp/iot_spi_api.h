/****************************************************************************

Copyright(c) 2016 by IoTelic Technologies. ALL RIGHTS RESERVED.

This Information is proprietary to IoTelic Technologies and MAY NOT
be copied by any method or incorporated into another program without
the express written consent of Iotelic. This Information or any portion
thereof remains the property of Iotelic. The Information contained herein
is believed to be accurate and Iotelic assumes no responsibility or
liability for its use in any way and conveys no license or title under
any patent or copyright and makes no representation or warranty that this
Information is free from patent or copyright infringement.

****************************************************************************/
#ifndef IOT_SPI_API_H
#define IOT_SPI_API_H

/** \defgroup SPI_APIs SPI APIs
  * @brief SPI APIs
  *
  *
  *
  */

/** @addtogroup SPI_APIs
  * @{
  */

#define INCLUDE_DW_APB_SSI

#ifdef INCLUDE_DW_APB_SSI

/**
  * @brief Poll mode Usage:

    xfer_buf spi_tx, spi_rx;

    iot_spi_module_init();

    iot_spi_dev_register(DEVICE_SPI0_MASTER, 1, 0, \
        isr_func, INT_RXFIFO_FULL|INT_TXFIFO_EMPTY);

    spi_tx.p_nt = &spi_rx; // Next buffer after this sent.
    spi_tx.txbuf = spi_tx_buf;
    spi_tx.rxbuf = NULL; // dummy data will be dropped.
    spi_tx.size = SPI_SENT_SIZE; //To send SPI_SENT_SIZE byte from spi_tx_buf.
    spi_rx.xfer_size =0;

    spi_rx.p_nt = NULL;
    spi_rx.rxbuf = spi_rx_buf;
    spi_rx.txbuf = tmp_buf; // dummy data will be sent to slaver.
    spi_rx.size = SPI_READ_SIZE; // To get SPI_READ_SIZE size of data.
    spi_rx.xfer_size =0;

    iot_spi_poll_transfer(DEVICE_SPI0_MASTER, &spi_tx);

    ...

  */

/**
  * @brief SPI timing.
  */
struct timing_config
{
    int scpol:1; /**< CLK stay in Low (0) or high (1) when idle */
    int scph:1; /**< 0 - Data transmited on falling edge of CS,
    captured on the 1ST edge of CLK
                   1 - Data transmited on the 1ST edge of CLK,
                   captured on the 2ND edge of CLK.    */
    int scph_tgl:1;
    int sste:1; /**< scph_tgl=0 & sste=1 , CS toggled between frames and
    CLK set default between frames .Else, CS stays LOW and CLK run
    continuously alwaays */
    int rev:28;
};

/**
  * @brief SPI dma config.
  */
struct spi_dma_config
{
    short rx_enable; /**< If to enable rx-DMA */
    short tx_enable; /**< If to enable tx-DMA */
    int rx_datalevel; /**< This bit field controls the level at which
        a DMA request is made by the receive logic.The watermark level
        = rx_datalevel+1 */
    int tx_datalevel; /**< This bit field controls the level at which
        a DMA request is made by the transmit logic.It is equal to the
        watermark level */
};

/**
  * @brief SPI device list.
  */
enum spi_device_list
{
    DEVICE_SPI0_MASTER,
    DEVICE_SPI1_MASTER,
    DEVICE_SPI0_SLAVER,

    DEVICE_SPI_INVALID
};

#define SPI_DFRAME_SIZE_8       8
#define SPI_DFRAME_SIZE_16      16
#define SPI_DFRAME_SIZE_32      32 /* NOT available for NOW */

#define DEVICE_SPI_CNT  DEVICE_SPI_INVALID
#define DEVICE_SPI_INT_MASK 0x3F
#define DEVICE_SPI_PORT_INVALID(d) ((d)>=DEVICE_SPI_CNT)

#define DEVICE_SPI_SYS_CLK  75*1000*1000 /* 75M */
#define DEVICE_SPI_DEFAULT_FREQUENCY  100*1000 /* 10M */
#define DEVICE_SPI_DEFAULT_RX_THRESHOULD    12
#define DEVICE_SPI_DEFAULT_TX_THRESHOULD    5

/* Mask */
#define INT_RXFIFO_FULL     BIT(4)
#define INT_RXFIFO_OVERFLOW BIT(3)
#define INT_RXFIFO_UNDERFLOW BIT(2)
#define INT_TXFIFO_EMPTY    BIT(1)
#define INT_TXFIFO_OVERFLOW BIT(0)
#else
#error "No SPI device included !"
#endif

#define SPI_MASTER  0
#define SPI_SLAVER  1

typedef void (*int_isr)(int);

/**
  * @brief SPI transerver mode.
  */
enum trans_mode
{
    TMOD_TRANCIEVER  = 0, /**< transmit and receive */
    TMOD_TRANSMITER  = 1, /**< transmit only */
    TMOD_RECIEVER    = 2, /**< receive only */
};

/**
  * @brief SPI frame mode.
  */
enum frame_format
{
    FRM_STD, /**< Only mode supported. */
    FRM_DUAL,
    FRM_QUAD,
    FRM_OCTAL
};

/**
  * @brief SPI config.
  */
typedef struct spi_config
{
    int dev_type:2;  /* Master or slaver */
    int trs_mode:2; /* trans_mode */
    int frm_fmt:2; /* frame_format */
    int dfrm_sz:5; /* Data frame size, SPI_DFRAME_SIZE_8 suggested. */
    int rev:21;

    int frq; /* Device frequency. Like DEVICE_SPI_DEFAULT_FREQUENCY  */

    int rx_thd; /**< Threshold for reviecing fifo. 0xF is max */
    int tx_thd; /**< Threshold for transmitting fifo. 0xF is max */
}spi_cfg;

/**
  * @brief SPI xfer buffer.
  */
typedef struct spi_xfer_buf
{
    struct spi_xfer_buf *p_nt;
    int size; /* bytes for recieving or for transmiting. */
    int xfer_size; /* bytes recieved or transmited  */
    char *rxbuf;
    char *txbuf;
}xfer_buf;

typedef struct timing_config tm_cfg;
typedef struct spi_dma_config   sdma_cfg;

/**
 * @brief iot_spi_dev_register_detail() - Register a spi device.For detail using.
 * @param dev: See enum spi_device_list.
 * @param cfg: See spi_cfg, For spi config.
 * @param tm: See struct timing_config, For timming config.
 * @param dma_cfg: See sdma_cfg, For spi dma.
 * @param isr: See int_isr, ISR for interrupts.
 * @param int_mask: Interrupt mask. See #define INT_*.
 * @see ERR_FAIL
 * @see ERR_OK
 * @return ERR_FAIL -- Operation failed.
 * @return ERR_OK -- Operation Successful.
 */
int iot_spi_dev_register_detail
    (int dev, spi_cfg * cfg, tm_cfg *tm,
    sdma_cfg* dma_cfg, int_isr isr, int int_mask);

/**
 * @brief iot_spi_dev_register() - Register a spi device.
 * @param dev: See enum spi_device_list.
 * @param is_master: 0 for slaver, else master.
 * @param is_dma: 0 for none-dma, else dma..
 * @param isr: See int_isr, ISR for interrupts.
 * @param int_mask: Interrupt mask. See #define INT_*.
 * @see ERR_FAIL
 * @see ERR_OK
 * @return ERR_FAIL -- Operation failed.
 * @return ERR_OK -- Operation Successful.
 */
int iot_spi_dev_register
    (int dev, int is_master, int is_dma, int_isr isr, int int_mask);

/**
 * @brief iot_spi_clear_int_status() - Clear status of interrupts.
 * @param dev: See enum spi_device_list.
 * @see ERR_FAIL
 * @see ERR_OK
 * @return ERR_FAIL -- Operation failed.
 * @return ERR_OK -- Operation Successful.
 */
int iot_spi_clear_int_status(int dev);

/**
 * @brief iot_spi_set_int_enable() - Enable interrupts.
 * @param dev: See enum spi_device_list.
 * @param ena_msk: Interrupt mask. See #define INT_*.
 * @see ERR_FAIL
 * @see ERR_OK
 * @return ERR_FAIL -- Operation failed.
 * @return ERR_OK -- Operation Successful.
 */
int iot_spi_set_int_enable(int dev, int ena_msk);

/**
 * @brief iot_spi_set_int_enable() - Disable interrupts.
 * @param dev: See enum spi_device_list.
 * @param dis_msk: Interrupt mask. See #define INT_*.
 * @see ERR_FAIL
 * @see ERR_OK
 * @return ERR_FAIL -- Operation failed.
 * @return ERR_OK -- Operation Successful.
 */
int iot_spi_set_int_disable(int dev, int dis_msk);

/**
 * @brief iot_spi_get_rx_data_cnt() - Get recieved data counting..
 * @param dev: See enum spi_device_list.
 * @param *cnt: Pointer to return the counting.
 * @see ERR_FAIL
 * @see ERR_OK
 * @return ERR_FAIL -- Operation failed.
 * @return ERR_OK -- Operation Successful.
 */
int iot_spi_get_rx_data_cnt(int dev, int * cnt);

/**
 * @brief iot_spi_get_tx_data_space_cnt() - Get data counting we can
   still put into fifo.
 * @param dev: See enum spi_device_list.
 * @param *cnt: Pointer to return the counting.
 * @see ERR_FAIL
 * @see ERR_OK
 * @return ERR_FAIL -- Operation failed.
 * @return ERR_OK -- Operation Successful.
 */
int iot_spi_get_tx_data_space_cnt(int dev, int * cnt);

/**
 * @brief iot_spi_read_data() - Get the data recieved.
 * @param dev: See enum spi_device_list.
 * @param *buf: Buffer to store the data.
 * @param *rd_size: Size of data that wanna got.
 * @return  -- Size of data that got finally..
 */
int iot_spi_read_data(int dev, char *buf, int rd_size);

/**
 * @brief iot_spi_write_data() - Transmit data.
 * @param dev: See enum spi_device_list.
 * @param *buf: Buffer to store the data.
 * @param *wt_size: Size of data that wanna sent.
 * @return  -- Size of data that sent finally..
 */
int iot_spi_write_data(int dev, char *buf, int wt_size);

/**
 * @brief iot_spi_poll_transfer() - Transceive data.
 * @param dev: See enum spi_device_list.
 * @param *buf: Buffer to tramsmit and recieve.
 * @return ERR_FAIL -- Operation failed.
 * @return ERR_OK -- Operation Successful.
 */
int iot_spi_poll_transfer(int dev, xfer_buf *buf);

/**
 * @brief iot_spi_module_init() - Initialize the data of SPI module.
 * @return ERR_FAIL -- Operation failed.
 * @return ERR_OK -- Operation Successful.
 */
int iot_spi_module_init(void);

/**
 * @brief iot_spi_tx_fifo_empty_status() - check the tx fifo is empty or not.
 * @return 0 -- tx fifo is NOT empty.
 * @return 1 -- tx fifo is  empty.
 */
int iot_spi_tx_fifo_empty_status(int dev);

/**
  * @}
  */

#endif
