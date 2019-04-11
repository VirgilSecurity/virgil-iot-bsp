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

#ifndef IOT_IRQ_H
#define IOT_IRQ_H

#define HAL_VECTOR_COUNT 64

/*
* interrupt vector table
*/
typedef enum {
    HAL_VECTOR_GPTMR = 0,      // GP Timer
    HAL_VECTOR_GPIO,           // GPIO
    HAL_VECTOR_UART0,          // UART0
    HAL_VECTOR_UART1,          // UART1
    HAL_VECTOR_MAC_0,          // MAC_0
    HAL_VECTOR_MAC_1,          // MAC_1
    HAL_VECTOR_MAC_2,          // MAC_2
    HAL_VECTOR_MAC_3,          // MAC_3
    HAL_VECTOR_UART2,          // UART2
    HAL_VECTOR_GPTMR1,         // GP Timer1
    HAL_VECTOR_PHY_0,          // PHY_0
    HAL_VECTOR_PHY_1,          // PHY_1
    HAL_VECTOR_PHY_2,          // PHY_2
    HAL_VECTOR_PHY_3,          // PHY_3
    HAL_VECTOR_WDG_TO,         // WDG Timeout
    HAL_VECTOR_SPI_M0,         // SPI master0
    HAL_VECTOR_SPI_M1,         // SPI master1
    HAL_VECTOR_SPI_S0,         // SPI slave0
    HAL_VECTOR_STMR0,          // STMR0
    HAL_VECTOR_SW_DMA,         // SW DMA
    HAL_VECTOR_WDG,            // WDG Feeddog
    HAL_VECTOR_CAN,            // CAN
    HAL_VECTOR_UART3,          // UART3
    HAL_VECTOR_GMAC,           // GMAC
    HAL_VECTOR_DMA0,           // DMA0
    HAL_VECTOR_PWM0,           // PWM0
    HAL_VECTOR_MOD_MUL,        // MOD Multiply
    HAL_VECTOR_HASH,           // HASH
    HAL_VECTOR_SM4,            // SM4
    HAL_VECTOR_RNG,            // RANDOM
    HAL_VECTOR_IIS,            // IIS
    HAL_VECTOR_CONV,           // CONV
    HAL_VECTOR_STMR1,          // STMR1
    HAL_VECTOR_SADC,           // SADC
    HAL_VECTOR_DMA2,           // DMA2
    HAL_VECTOR_DMA3,           // DMA3
    HAL_VECTOR_DMA4,           // DMA4
    HAL_VECTOR_DMA5,           // DMA5
    HAL_VECTOR_PWM1,           // PWM1
    HAL_VECTOR_PWM2,           // PWM2
    HAL_VECTOR_MTX_MST_ERR,    // MTX_MST_ERR
    HAL_VECTOR_SNAP_SHOT,      // SNAP_SHOT
    HAL_VECTOR_MBOX0,          // MBOX0
    HAL_VECTOR_MBOX1,          // MBOX1
    HAL_VECTOR_WDG1_TO,        // WDG1 Timeout
    HAL_VECTOR_WDG1,           // WDG1 Feeddog
    HAL_VECTOR_SW_DMA1,        // SW DMA1
    HAL_VECTOR_DMA1,           // DMA1
    HAL_VECTOR_SFC_ERR_EMC,    // SFC_WR_ERR_INT
    HAL_VECTOR_SFC_ERR_DCACHE, // SFC_WR_ERR_DCACHE
    HAL_VECTOR_SFC_ERR_ICACHE, // SFC_WR_ERR_ICACHE
    
    HAL_VECTOR_MAX
}IOT_INTR_VECTOR;

/*
* interrupt priority
*/

typedef enum {
    HAL_INTR_PRI_0  = 0,
    HAL_INTR_PRI_1,
    HAL_INTR_PRI_2,
    HAL_INTR_PRI_3,
    HAL_INTR_PRI_4,
    HAL_INTR_PRI_5,
    HAL_INTR_PRI_6,
    HAL_INTR_PRI_7,
    
    HAL_INTR_PRI_MAX
}IOT_INTR_PRIORITY;

/*
 * interrupt's cpu core
*/
typedef enum{
    HAL_INTR_CPU_0 = 0,
    HAL_INTR_CPU_1,

    HAL_INTR_CPU_MAX
}IOT_INTR_CPU;

typedef uint32_t iot_addrword_t;
typedef uint32_t iot_addr_t;
typedef iot_addrword_t iot_irq_t;

/*
* interrupt service routine prototype.
*/
typedef uint32_t iot_isr_t( uint32_t vector, iot_addrword_t data);

/*
 * iot_interrupt_create() - create an interrupt for vector
 * vector - interrupt vector
 * priority - interrupt priority
 * data - isr's data
 * isr  - isr function
 * return: 
 *      NULL or interrupt handle
 */
iot_irq_t iot_interrupt_create(uint32_t vector,
                                uint32_t priority, 
                                iot_addrword_t data,
                                iot_isr_t *isr);

/*
 * iot_interrupt_delete() - delete an interrupt for vector
 * interrupt - interrupt handle
 * return:
 *      void
 */
void iot_interrupt_delete( iot_irq_t interrupt );

/*
 * iot_interrupt_attach() - attach this interrupt. It attached isr into table.
 * interrupt - interrupt handle
 * return:
 *      void
 */
void iot_interrupt_attach( iot_irq_t interrupt );

/*
 * iot_interrupt_detach() - deatach this interrupt. It detach isr form table.
 * interrupt - interrupt handle
 * return:
 *      void
 */
void iot_interrupt_detach( iot_irq_t interrupt );

/*
 * iot_interrupt_mask() - mask this interrupt.
 * interrupt - interrupt handle
 * return:
 *      void
 */
void iot_interrupt_mask( iot_irq_t interrupt );

/*
 * iot_interrupt_unmask() - unmask this interrupt.
 * interrupt - interrupt handle
 * return:
 *      void
 */
void iot_interrupt_unmask( iot_irq_t interrupt);

/*
 * iot_interrupt_acknowldege() - acknowledge this interrupt.
 * interrupt - interrupt handle
 * return:
 *      void
 */
void iot_interrupt_acknowledge( iot_irq_t interrupt);

/*
 * iot_interrupt_configure() - configure this interrupt.
 * interrupt - interrupt handle
 * level  -- level trigger
 * up   -- edge trigger
 * return:
 *      void
 */
void iot_interrupt_configure( iot_irq_t interrupt, uint32_t level, uint32_t up);

/*
 * iot_interrupt_priority() - set this interrupt's priority.
 * interrupt - interrupt handle
 * return:
 *      void
 */
void iot_interrupt_priority( iot_irq_t interrupt, uint32_t priority);

/*
 * iot_interrupt_set_cpu() - set cpu's id for this interrupt.
 * interrupt - interrupt handle
 * return:
 *      void
 */
void iot_interrupt_set_cpu( iot_irq_t interrupt, uint32_t cpu);

/*
 * iot_interrupt_get_cpu() - get cpu's id for this interrupt.
 * interrupt - interrupt handle
 * return:
 *      cpu id
 */
uint32_t iot_interrupt_get_cpu( iot_irq_t interrupt );

/*
 * iot_interrupt_init() - init interrupt controller and install default isr.
 * return:
 *      0 -- OK
 */ 
uint32_t iot_interrupt_init();

#endif /* IOT_IRQ_H */
