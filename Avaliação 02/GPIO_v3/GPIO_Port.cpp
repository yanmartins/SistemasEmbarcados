/*
 * GPIO_Port.cpp
 *
 *  Created on: 22 de mar de 2017
 *      Author: aluno
 */
#include "GPIO_Port.h"
#include <avr/pgmspace.h>

namespace GPIO_PORT {

enum PORT_ADDR_BASE {
	AVR_PB = 0x0023,
	AVR_PE = 0x002C,
	AVR_PG = 0x0032,
	AVR_PH = 0x0100,
	AVR_PJ = 0x0103,
	AVR_PD = 0x0029,
	AVR_PA = 0x0020,
	AVR_PC = 0x0026,
	AVR_PF = 0x002F,
	AVR_PK = 0x0106
};

GPIO_Port * AllPorts[10] = {
		reinterpret_cast<GPIO_Port*>(AVR_PB),
		reinterpret_cast<GPIO_Port*>(AVR_PE),
		reinterpret_cast<GPIO_Port*>(AVR_PG),
		reinterpret_cast<GPIO_Port*>(AVR_PH),
		reinterpret_cast<GPIO_Port*>(AVR_PJ),
		reinterpret_cast<GPIO_Port*>(AVR_PD),
		reinterpret_cast<GPIO_Port*>(AVR_PA),
		reinterpret_cast<GPIO_Port*>(AVR_PC),
		reinterpret_cast<GPIO_Port*>(AVR_PF),
		reinterpret_cast<GPIO_Port*>(AVR_PK)
};


enum Ports_index {
	PB_i = 0,
	PE_i = 1,
	PG_i = 2,
	PH_i = 3
};

const uint8_t id_to_port[14] PROGMEM = {
	PE_i	,
	PE_i	,
	PE_i	,
	PE_i	,
	PG_i	,
	PE_i	,
	PH_i	,
	PH_i	,
	PH_i	,
	PH_i	,
	PB_i	,
	PB_i	,
	PB_i	,
	PB_i
};

const uint8_t id_to_bit[14] PROGMEM = {
	_BV( 0 )	,
	_BV( 1 )	,
	_BV( 4 )	,
	_BV( 5 )	,
	_BV( 5 )	,
	_BV( 3 )	,
	_BV( 3 )	,
	_BV( 4 )	,
	_BV( 5 )	,
	_BV( 6 )	,
	_BV( 4 )	,
	_BV( 5 )	,
	_BV( 6 )	,
	_BV( 7 )
};


void GPIO_Port::dir(uint8_t p, bool io) {
    if (io)
        ddr |= p;
    else
        ddr &= ~p;
}
void GPIO_Port::set(uint8_t p, bool val) {
    if (val)
        port |= p;
    else
        port &= ~p;
}
void GPIO_Port::clear(uint8_t p) {
    set(p,0);
}
bool GPIO_Port::get(uint8_t p) {
    return pin & p;
}

void GPIO_Port::toggle(uint8_t p) {
	pin = p;
}


} /* namespace GPIO_PORT */
