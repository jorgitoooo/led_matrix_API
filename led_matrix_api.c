#include "led_matrix_api.h"

// typedefs (uc, sc, us) found in 'defs.h'


// Aligns byte with MAX7219 LED driver
static void send_byte (uc data)
{
	for (uc i=8; i>0; i--)
	{
		CLK_LOW(); 
		if (data & 1 << (i - 1))
		{
			DATA_HIGH();
		}
		else
		{
			DATA_LOW();
		}
		CLK_HIGH();
	}
	CLK_LOW();
}

// Loads the 2 bytes that have been aligned by send word
void load_word()
{
	LOAD_LOW();
	LOAD_HIGH();
	LOAD_LOW();
}

// Aligns 2 bytes with MAX7219 LED driver
// - 1st byte: Register that data will be loaded into
// - 2st byte: Data to be loaded into register
void send_word(uc reg, uc data)
{
	send_byte(reg);
	send_byte(data);
}

// Clears all MAX7219 LED drivers
void clear_all(uc num_of_matrices)
{
	for (uc reg = 1; reg < 9; reg++)
	{
		for (uc matrix = 0; matrix < num_of_matrices; matrix++)
		{
			send_word(reg, 0x00);
		}
		load_word();
	}
}

// Sets the display brightness
void set_brightness(uc brightness, uc num_of_matrices)
{
	for (char i = 0; i < num_of_matrices; i++)
	{
		send_word(INTENSITY_REG_ADDR, brightness);
		load_word();
	}
}

// Clears all digit registers with the MAX7219 LED driver
void clear_digit_registers()
{
	for (uc reg = 1; reg <= 8; reg++)
	{
		send_word(reg, 0x00);
		load_word();
	}
}

// Initializes all MAX7219 LED drivers
void init_led_matrices(uc num_of_matrices)
{
	for (char i = 0; i < num_of_matrices; i++)
	{
		send_word(SCAN_LIMIT_REG_ADDR, 7);
		load_word();

		send_word(DECODE_MODE_REG_ADDR, 0x00);
		load_word();

		send_word(SHUTDOWN_REG_ADDR, 0x01);
		load_word();
	
		send_word(DISPLAY_TST_REG_ADDR, 0x00);
		load_word();

		clear_digit_registers();
	}
	set_brightness(0x07, 4);
}
