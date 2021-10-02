/*
 * SevenSegment_interface.h
 *
 *  Created on: Oct 2, 2021
 *      Author: sa7er
 */

#ifndef SEVENSEGMENT_INTERFACE_H_
#define SEVENSEGMENT_INTERFACE_H_

ES_t SevenSegment_enuInit(SSG_t * SevenSegment_pAstrSSGConfig);

ES_t SevenSegment_enuDisplay(SSG_t * SevenSegment_pstrSSGInfo,u8 Copy_u8Number);

ES_t SevenSegment_enuEnableCommon(SSG_t * SevenSegment_pstrSSGInfo);

ES_t SevenSegment_enuDisableCommon(SSG_t * SevenSegment_pstrSSGInfo);

ES_t SevenSegment_enuEnableDot(SSG_t * SevenSegment_pstrSSGInfo);

ES_t SevenSegment_enuDisableDot(SSG_t * SevenSegment_pstrSSGInfo);

ES_t SevenSegment_enuStopDisplay(SSG_t * SevenSegment_pstrSSGInfo);

#endif /* SEVENSEGMENT_INTERFACE_H_ */
