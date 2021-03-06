/****************************************************************************
 * Included Files
 ****************************************************************************/
#include <silan_gpio.h>
#include "4052.h"
/****************************************************************************
 * Pre-processor Definitions
 ****************************************************************************/
#define sw1_4052 7
#define sw2_4052 8

/****************************************************************************
 * Public Types
 ****************************************************************************/

/****************************************************************************
 * Public Data
 ****************************************************************************/

/****************************************************************************
 * Public Function Prototypes
 ****************************************************************************/

/****************************************************************************
 * Public Functions
 ****************************************************************************/

/****************************************************************************
 * Name: switch_4052_function
 *
 * Description:
 *    通过IO口控制4052切换声音输出
 * 
 * Parameters:
 *    function  switch_4052类型，指定要切换到AUX1、AUX2还是蓝牙
 *
 * Returned Value:
 * 
 * Assumptions:
 *
 ****************************************************************************/
void switch_4052_function(int function)
{
    int sw1, sw2;

    switch (function)
    {
	case BT_4052:
        sw1 = 1;
        sw2 = 1;
        break;    
	case AUX_4052:
        sw1 = 0;
        sw2 = 1;
        break;    
    case RCA_4052:
        sw1 = 1;
        sw2 = 0;
        break;	
    default:
        sw1 = 0;
        sw2 = 0;
        break;
    }

    gpio_pull_mode(sw1_4052, PULLING_HIGH);

    gpio_direction_output(sw1_4052, sw1);

    zhuque_bsp_gpio_set_value(sw1_4052, sw1);

    gpio_pull_mode(sw2_4052, PULLING_HIGH);
	
    gpio_direction_output(sw2_4052, sw2);

    zhuque_bsp_gpio_set_value(sw2_4052, sw2);

}